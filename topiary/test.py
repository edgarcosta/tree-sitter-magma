#!/usr/bin/env python3
"""Check exact fixture output, idempotence, and syntax preservation."""

import difflib
from pathlib import Path
import subprocess
import sys

from checks import syntax_signature


ROOT = Path(__file__).resolve().parent


def format_source(source):
    # Topiary's default idempotence check stays enabled.
    result = subprocess.run(
        ["topiary", "format", "--language", "magma", "--configuration",
         str(ROOT / "languages.ncl"), "--query", str(ROOT / "magma.scm")],
        cwd=ROOT,
        input=source,
        capture_output=True,
        timeout=60,
    )
    if result.returncode:
        raise ValueError(result.stderr.decode(errors="replace"))
    return result.stdout


def main():
    inputs = {path.name: path for path in (ROOT / "test/input").glob("*.m")}
    expected = {path.name: path for path in (ROOT / "test/expected").glob("*.m")}
    failures = 0
    for name in sorted(inputs.keys() | expected.keys()):
        try:
            if name not in inputs or name not in expected:
                raise ValueError("fixture needs both an input and an expected file")
            source = inputs[name].read_bytes()
            wanted = expected[name].read_bytes()
            actual = format_source(source)
            if syntax_signature(source) != syntax_signature(actual):
                raise ValueError("formatting changed the syntax tree or token contents")
            if actual != wanted:
                difference = "".join(difflib.unified_diff(
                    wanted.decode().splitlines(keepends=True),
                    actual.decode().splitlines(keepends=True),
                    fromfile=f"expected/{name}", tofile=f"actual/{name}",
                ))
                raise ValueError(difference)
        except (ValueError, OSError, subprocess.SubprocessError) as error:
            failures += 1
            print(f"FAIL: {name}\n{error}")
        else:
            print(f"PASS: {name}")
    if not inputs:
        print("FAIL: no formatter fixtures found")
        return 1
    print(f"Fixtures: {len(inputs)}, failures: {failures}")
    return int(failures != 0)


if __name__ == "__main__":
    sys.exit(main())
