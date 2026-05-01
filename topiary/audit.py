#!/usr/bin/env python3
"""Audit topiary formatting across a directory of Magma files.

Classifies each file as:
  ok              - topiary succeeds, formatted output parses the same as input
  topiary_error   - topiary exited non-zero (includes idempotence failures)
  parse_regression- formatted output has tree-sitter ERROR nodes input didn't
  token_diff      - non-whitespace token sequence changed between input and output
  input_broken    - input itself has ERROR nodes; we skip (not topiary's fault)

Writes per-file detail to <out>/files/<sanitized>.log and a summary to
<out>/summary.md. Prints one-line progress per file.
"""

import argparse
import concurrent.futures
import os
import re
import subprocess
import sys
from pathlib import Path

REPO_ROOT = Path(__file__).resolve().parent.parent
TREE_SITTER = REPO_ROOT / "node_modules" / ".bin" / "tree-sitter"
BUILD_SH = REPO_ROOT / "topiary" / "build.sh"


def parse_args():
    p = argparse.ArgumentParser()
    p.add_argument("input_dir", type=Path, help="Directory to scan for .m files")
    p.add_argument("--out", type=Path, default=REPO_ROOT / "topiary" / "audit-out")
    p.add_argument("-j", "--jobs", type=int, default=os.cpu_count() or 4)
    p.add_argument("--limit", type=int, default=None, help="Process only N files (for smoke-test)")
    return p.parse_args()


def discover_files(root: Path):
    return sorted(p for p in root.rglob("*.m") if p.is_file())


def run_topiary(file: Path) -> tuple[int, bytes, bytes]:
    """Run topiary on `file` via the build.sh wrapper. Returns (exit, stdout, stderr)."""
    proc = subprocess.run(
        [str(BUILD_SH), "format", str(file.resolve())],
        capture_output=True,
        timeout=120,
    )
    return proc.returncode, proc.stdout, proc.stderr


ERROR_RE = re.compile(rb"\(ERROR\b|\bMISSING\b|\(UNEXPECTED")


def parse_tree(source: bytes) -> tuple[bytes, int]:
    """Parse `source` via tree-sitter CLI. Returns (sexp_bytes, error_count).

    Calls `tree-sitter parse -` (stdin mode is not supported in 0.20.8, so we
    write to a tempfile).
    """
    import tempfile
    with tempfile.NamedTemporaryFile(suffix=".m", delete=False) as tf:
        tf.write(source)
        tmp = tf.name
    try:
        proc = subprocess.run(
            [str(TREE_SITTER), "parse", tmp],
            capture_output=True,
            cwd=REPO_ROOT,
            timeout=60,
        )
    finally:
        os.unlink(tmp)
    sexp = proc.stdout
    error_count = len(ERROR_RE.findall(sexp))
    return sexp, error_count


# Matches leaf tokens in the tree-sitter parse output:
#   (node_type [row, col] - [row, col])
# We want the node_type of every leaf. Leaves are any node with no children —
# in the s-expression, they have no following newline+indent line that starts
# with a field or nested '('. We take a simpler approach: extract all
# (identifier-like tokens) *that don't contain children*. tree-sitter's -x
# (XML) or --dot outputs aren't obviously easier, so we parse the s-exp.
TOKEN_RE = re.compile(rb"\(([a-zA-Z_][a-zA-Z0-9_]*)\s+\[")


def token_seq(sexp: bytes) -> list[str]:
    """Return the ordered list of node-type names from a tree-sitter s-expression.

    This includes both leaves and interior nodes, which is fine for our purposes:
    if two trees have the same sequence of node types, they are structurally
    identical (modulo whitespace, which tree-sitter elides).
    """
    return [m.decode() for m in TOKEN_RE.findall(sexp)]


from dataclasses import dataclass


@dataclass
class Result:
    path: Path
    category: str  # ok | topiary_error | parse_regression | token_diff | input_broken | runner_error
    detail: str    # short one-line detail for the summary
    topiary_stderr: bytes = b""
    input_errors: int = 0
    output_errors: int = 0


def classify(file: Path) -> Result:
    try:
        return _classify(file)
    except subprocess.TimeoutExpired as e:
        return Result(file, "runner_error", f"timeout in {Path(e.cmd[0]).name}")
    except Exception as e:
        return Result(file, "runner_error", f"{type(e).__name__}: {e}"[:200])


def _classify(file: Path) -> Result:
    src = file.read_bytes()
    in_sexp, in_err = parse_tree(src)
    if in_err > 0:
        return Result(file, "input_broken", f"input has {in_err} parse errors")

    code, out, err = run_topiary(file)
    if code != 0:
        # Collapse stderr to a single summary line for clustering.
        first = err.splitlines()[0].decode(errors="replace") if err else f"exit {code}"
        return Result(file, "topiary_error", first, topiary_stderr=err)

    out_sexp, out_err = parse_tree(out)
    if out_err > in_err:
        return Result(
            file,
            "parse_regression",
            f"output has {out_err} parse errors (input had {in_err})",
            input_errors=in_err,
            output_errors=out_err,
        )

    t_in = token_seq(in_sexp)
    t_out = token_seq(out_sexp)
    if t_in != t_out:
        # Find first divergence for detail.
        for i, (a, b) in enumerate(zip(t_in, t_out)):
            if a != b:
                return Result(
                    file,
                    "token_diff",
                    f"divergence at token {i}: in={a!r} out={b!r}",
                )
        return Result(
            file,
            "token_diff",
            f"length differs: in={len(t_in)} out={len(t_out)}",
        )

    return Result(file, "ok", "clean")


from collections import Counter, defaultdict


def write_summary(results: list[Result], out_dir: Path) -> Path:
    by_cat: dict[str, list[Result]] = defaultdict(list)
    for r in results:
        by_cat[r.category].append(r)

    lines = ["# Topiary audit summary", ""]
    lines.append(f"Total files: {len(results)}")
    counts = Counter(r.category for r in results)
    for cat in ("ok", "input_broken", "topiary_error", "parse_regression", "token_diff", "runner_error"):
        lines.append(f"- **{cat}**: {counts.get(cat, 0)}")
    lines.append("")

    for cat in ("topiary_error", "parse_regression", "token_diff", "runner_error"):
        if not by_cat[cat]:
            continue
        lines.append(f"## {cat} ({len(by_cat[cat])})")
        lines.append("")
        detail_counts = Counter(r.detail for r in by_cat[cat])
        lines.append("Top details:")
        for detail, n in detail_counts.most_common(10):
            lines.append(f"- `{detail}` — {n} file(s)")
        lines.append("")
        lines.append("Example files (first 20):")
        for r in by_cat[cat][:20]:
            lines.append(f"- `{r.path}` — {r.detail}")
        lines.append("")

    summary_path = out_dir / "summary.md"
    summary_path.write_text("\n".join(lines) + "\n")

    # Per-file logs for topiary_error so stderr can be inspected later.
    for r in by_cat["topiary_error"]:
        safe = str(r.path).replace("/", "_")
        (out_dir / "files" / f"{safe}.stderr").write_bytes(r.topiary_stderr)
    return summary_path


def main():
    args = parse_args()
    args.out.mkdir(parents=True, exist_ok=True)
    (args.out / "files").mkdir(exist_ok=True)
    files = discover_files(args.input_dir)
    if args.limit:
        files = files[: args.limit]
    print(f"Discovered {len(files)} files")
    results = []
    with concurrent.futures.ProcessPoolExecutor(max_workers=args.jobs) as ex:
        for i, r in enumerate(ex.map(classify, files, chunksize=4), 1):
            results.append(r)
            if i % 50 == 0 or i == len(files):
                print(f"  {i}/{len(files)} processed", file=sys.stderr)

    summary_path = write_summary(results, args.out)
    print(f"\nSummary written to {summary_path}")


if __name__ == "__main__":
    main()
