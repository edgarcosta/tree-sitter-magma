#!/usr/bin/env python3
"""Compare committed and working highlight/locals queries on Magma examples."""

import argparse
import html
import json
from pathlib import Path
import re
import shutil
import subprocess
import tempfile


ROOT = Path(__file__).resolve().parents[1]
QUERY_FILES = ("highlights.scm", "locals.scm")
COLORS = {
    "comment": "#6e7781",
    "string": "#0a3069",
    "number": "#0550ae",
    "boolean": "#0550ae",
    "constant": "#0550ae",
    "keyword": "#cf222e",
    "operator": "#cf222e",
    "function": "#8250df",
    "type": "#953800",
    "attribute": "#0550ae",
    "property": "#0550ae",
    "variable": "#24292f",
    "variable.parameter": "#953800",
    "variable.member": "#0550ae",
    "punctuation": "#57606a",
    "delimiter": "#57606a",
}


def run(*args, cwd=ROOT):
    return subprocess.check_output(args, cwd=cwd, text=True)


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("files", nargs="*", type=Path)
    parser.add_argument("--baseline", default="HEAD", help="Git revision to compare")
    parser.add_argument("--output", type=Path, default=ROOT / "build/highlighting.html")
    args = parser.parse_args()
    files = [p.resolve(strict=True) for p in args.files] or [ROOT / "examples/highlighting.m"]
    cli = ROOT / "node_modules/.bin/tree-sitter"
    if not cli.exists():
        executable = shutil.which("tree-sitter")
        if not executable:
            parser.error("Install the Tree-sitter CLI before generating a preview")
        cli = Path(executable)

    before = {
        name: run("git", "show", f"{args.baseline}:queries/{name}")
        for name in QUERY_FILES
    }
    after = {name: (ROOT / "queries" / name).read_text() for name in QUERY_FILES}
    captures = set(re.findall(r"@([\w.]+)", before["highlights.scm"] + after["highlights.scm"]))
    theme = {}
    for capture in captures:
        base = capture.split(".")[0]
        theme[capture] = COLORS.get(capture, COLORS.get(base, "#24292f"))

    sections = []
    with tempfile.TemporaryDirectory(prefix="magma-highlight-") as scratch:
        scratch = Path(scratch)
        grammars = []
        for label, queries in ((args.baseline, before), ("Working queries", after)):
            grammar = scratch / str(len(grammars)) / "tree-sitter-magma"
            (grammar / "queries").mkdir(parents=True)
            (grammar.parent / "config.json").write_text(json.dumps({
                "parser-directories": [str(grammar.parent)], "theme": theme,
            }))
            # Both sides use the working parser: this comparison isolates queries.
            (grammar / "src").symlink_to(ROOT / "src", target_is_directory=True)
            (grammar / "grammar.js").symlink_to(ROOT / "grammar.js")
            metadata = json.loads((ROOT / "tree-sitter.json").read_text())
            metadata["grammars"][0]["locals"] = "queries/locals.scm"
            (grammar / "tree-sitter.json").write_text(json.dumps(metadata))
            for name, query in queries.items():
                (grammar / "queries" / name).write_text(query)
            grammars.append((label, grammar))

        for source in files:
            panels = []
            for label, grammar in grammars:
                document = run(
                    str(cli), "highlight", "--html", "--scope", "source.magma",
                    "--config-path", str(grammar.parent / "config.json"), str(source), cwd=grammar,
                )
                table = re.search(r"<table\b.*?</table>", document, re.DOTALL)
                if table is None:
                    raise RuntimeError(f"Tree-sitter produced no HTML table for {source}")
                panels.append(f"<section><h3>{html.escape(label)}</h3>{table[0]}</section>")
            sections.append(
                f"<h2>{html.escape(str(source))}</h2><div class='comparison'>"
                + "".join(panels) + "</div>"
            )

    document = """<!doctype html>
<html lang="en"><meta charset="utf-8">
<meta name="viewport" content="width=device-width,initial-scale=1">
<title>Magma highlighting comparison</title>
<style>
body { margin: 24px; color: #24292f; background: #fff; font: 14px system-ui; }
h2 { font-size: 16px; overflow-wrap: anywhere; }
h3 { margin: 0; padding: 12px; background: #f6f8fa; border-bottom: 1px solid #d0d7de; }
.comparison { display: grid; grid-template-columns: 1fr 1fr; gap: 16px; }
section { min-width: 0; overflow: auto; border: 1px solid #d0d7de; border-radius: 6px; }
table { font: 13px/1.6 ui-monospace, monospace; border-collapse: collapse; }
.line { white-space: pre; padding-right: 12px; }
.line-number { user-select: none; text-align: right; color: #6e7781; padding: 0 12px; }
@media(max-width: 900px) { .comparison { grid-template-columns: 1fr; } }
</style>
<h1>Magma highlighting comparison</h1>
<p>Committed and working highlight/locals queries, using the same parser and preview theme.
These colors illustrate capture roles; editor and GitHub themes may differ.</p>
""" + "".join(sections) + "</html>\n"
    args.output.parent.mkdir(parents=True, exist_ok=True)
    args.output.write_text(document)
    print(args.output.resolve())


if __name__ == "__main__":
    main()
