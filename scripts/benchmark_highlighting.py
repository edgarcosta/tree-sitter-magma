#!/usr/bin/env python3
"""Benchmark CLI parsing, highlight/locals queries, and HTML rendering.

Requires Python 3 and the Tree-sitter CLI on macOS or Linux. No Python binding
is needed. Package sources remain local; the JSON report contains metrics and
file names, not source text. Timings include CLI startup and HTML rendering.
"""

import argparse
import hashlib
import json
import os
from pathlib import Path
import platform
import re
import shutil
import signal
import subprocess
import sys
import tempfile
import time


ROOT = Path(__file__).resolve().parents[1]


def measure(command, timeout, cwd):
    """Use a fresh time process for each case so peak RSS is per invocation."""
    flag = "-l" if sys.platform == "darwin" else "-v"
    started = time.perf_counter()
    process = subprocess.Popen(
        ["/usr/bin/time", flag, *command], cwd=cwd,
        stdout=subprocess.DEVNULL, stderr=subprocess.PIPE,
        text=True, start_new_session=True,
    )
    timed_out = False
    try:
        _, stderr = process.communicate(timeout=timeout)
    except subprocess.TimeoutExpired:
        timed_out = True
        os.killpg(process.pid, signal.SIGKILL)
        _, stderr = process.communicate()
    elapsed = time.perf_counter() - started
    if sys.platform == "darwin":
        match = re.search(r"(\d+)\s+maximum resident set size", stderr)
        divisor = 1_000_000
    else:
        match = re.search(r"Maximum resident set size \(kbytes\):\s*(\d+)", stderr)
        divisor = 1000
    result = {
        "status": "timeout" if timed_out else "ok" if process.returncode == 0 else "failed",
        "exit_code": process.returncode,
        "wall_seconds": round(elapsed, 4),
        "peak_rss_mb": round(int(match[1]) / divisor, 2) if match else None,
    }
    if result["status"] != "ok":
        result["stderr"] = stderr[-4000:]
    return result


def main():
    ap = argparse.ArgumentParser(description=__doc__)
    ap.add_argument("--spec", type=Path, help="Sample files loaded by this Magma spec")
    ap.add_argument("--sample", type=int, default=12, help="Size-spaced package sample, including largest (default: 12)")
    ap.add_argument("--timeout", type=float, default=30, help="Seconds allowed per file (default: 30)")
    ap.add_argument("--cli", type=Path, help="Explicit Tree-sitter executable")
    ap.add_argument("--output", type=Path, default=ROOT / "build/highlight-benchmark.json")
    args = ap.parse_args()
    if args.sample < 2 or args.timeout <= 0:
        ap.error("--sample must be at least 2 and --timeout must be positive")
    if sys.platform not in ("darwin", "linux"):
        ap.error("peak RSS measurement currently supports macOS and Linux")
    cli = args.cli or ROOT / "node_modules/.bin/tree-sitter"
    if not cli.exists():
        if args.cli:
            ap.error(f"CLI does not exist: {cli}")
        executable = shutil.which("tree-sitter")
        if not executable:
            ap.error("Install the Tree-sitter CLI first")
        cli = Path(executable)
    cli = cli.resolve()
    version = subprocess.check_output([str(cli), "--version"], text=True).strip()
    report = {
        "cli": version, "platform": platform.platform(),
        "method": "One warmed CLI invocation per file, parsing + highlight/locals queries + HTML rendering to /dev/null; wall time includes process startup",
        "timeout_seconds": args.timeout,
        "sha256": {name: hashlib.sha256((ROOT / name).read_bytes()).hexdigest()
                   for name in ("src/parser.c", "src/scanner.c", "queries/highlights.scm", "queries/locals.scm")},
        "cases": [],
    }
    cases = [(str(path.relative_to(ROOT)), path) for path in
             [ROOT / "examples/highlighting.m", *sorted((ROOT / "test/highlight").glob("*.m"))]]
    if args.spec:
        from parse_spec import walk
        package_files = sorted(set(map(Path, walk(str(args.spec)))), key=lambda p: (p.stat().st_size, str(p)))
        if not package_files:
            ap.error("spec contains no source files")
        count = min(args.sample, len(package_files))
        indices = {round(i * (len(package_files) - 1) / (count - 1)) for i in range(count)} if count > 1 else {0}
        cases.extend((str(package_files[i].relative_to(args.spec.resolve().parent)), package_files[i]) for i in sorted(indices))
        report["package_population"] = len(package_files)
        report["package_selection"] = "Evenly spaced ranks after sorting by byte size, then path; includes smallest and largest"

    with tempfile.TemporaryDirectory(prefix="magma-benchmark-") as directory:
        scratch = Path(directory)
        grammar = scratch / "tree-sitter-magma"
        grammar.mkdir()
        for name in ("src", "queries", "grammar.js"):
            (grammar / name).symlink_to(ROOT / name, target_is_directory=(ROOT / name).is_dir())
        metadata = json.loads((ROOT / "tree-sitter.json").read_text())
        metadata["grammars"][0]["locals"] = "queries/locals.scm"
        (grammar / "tree-sitter.json").write_text(json.dumps(metadata))
        captures = set(re.findall(r"@([\w.]+)", (ROOT / "queries/highlights.scm").read_text()))
        config = scratch / "config.json"
        config.write_text(json.dumps({"parser-directories": [str(scratch)],
                                     "theme": {name: "#24292f" for name in captures if not name.startswith("_")}}))
        command = [str(cli), "highlight", "--html", "--scope", "source.magma", "--config-path", str(config)]
        # Compile/load the parser before measuring individual files.
        subprocess.run([*command, str(ROOT / "examples/highlighting.m")], cwd=grammar,
                       stdout=subprocess.DEVNULL, check=True, timeout=args.timeout)
        adversarial = {
            "long-expression.m": "x := " + "+".join(["1"] * 20_000) + ";\n",
            "long-boolean-expression.m": "x := " + " and ".join(["true"] * 20_000) + ";\n",
            "nested-parentheses.m": "x := " + "(" * 5000 + "1" + ")" * 5000 + ";\n",
            "unclosed-brackets.m": "x := " + "[" * 140 + "1;\n",
            "many-functions.m": "function f(x) return x; end function;\n" * 50_000,
            "unterminated-string.m": 'x := "' + "a" * 100_000,
            "unterminated-comment.m": "/*" + " comment\n" * 20_000,
            "keyword-soup.m": "rep func proc where end if := | < > ;\n" * 2000,
        }
        for name, source in adversarial.items():
            path = scratch / name
            path.write_text(source)
            cases.append(("synthetic/" + name, path))
        for label, path in cases:
            result = {"file": label, "bytes": path.stat().st_size,
                      **measure([*command, str(path)], args.timeout, grammar)}
            report["cases"].append(result)
            print(f"{result['status']:7} {result['wall_seconds']:7.3f}s {str(result['peak_rss_mb']):>8} MB  {label}", flush=True)

    args.output.parent.mkdir(parents=True, exist_ok=True)
    args.output.write_text(json.dumps(report, indent=2) + "\n")
    print(args.output.resolve())
    return int(any(case["status"] != "ok" for case in report["cases"]))


if __name__ == "__main__":
    sys.exit(main())
