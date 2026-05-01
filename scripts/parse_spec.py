#!/usr/bin/env python3
"""Walk a Magma spec file and emit absolute paths of every .m file it loads.

A spec file is a tree of directory blocks:

    name { entries }      -> descend into subdirectory `name`
    +relpath              -> include another spec at `relpath` (relative to
                             the current spec's directory)
    file.m                -> a Magma source file in the current directory

Top-level can either start with `{ ... }` or with bare entries.

Usage:
    parse_spec.py <spec_file>            # one .m path per line, on stdout
    parse_spec.py <spec_file> --check    # also `tree-sitter parse` each file
                                          # and report ERROR/MISSING nodes
"""

import argparse
import os
import re
import subprocess
import sys


_TOKEN_RE = re.compile(r"[{}]|\S+")


def tokenize(text):
    # Spec files use `#` for end-of-line comments. Strip those before
    # tokenizing so `# Use new code` and trailing `... # ModAbVar` are
    # both ignored.
    text = re.sub(r"#.*", "", text)
    return _TOKEN_RE.findall(text)


def walk(spec_path, _seen=None):
    if _seen is None:
        _seen = set()
    spec_path = os.path.abspath(spec_path)
    if spec_path in _seen:
        return
    _seen.add(spec_path)

    base = os.path.dirname(spec_path)
    with open(spec_path) as f:
        tokens = tokenize(f.read())

    pos = [0]

    def peek():
        return tokens[pos[0]] if pos[0] < len(tokens) else None

    def consume():
        tok = tokens[pos[0]]
        pos[0] += 1
        return tok

    def body(dir_):
        while peek() not in (None, "}"):
            tok = consume()
            if tok.startswith("+"):
                included = os.path.join(dir_, tok[1:])
                yield from walk(included, _seen)
            elif peek() == "{":
                consume()
                yield from body(os.path.join(dir_, tok))
                if peek() == "}":
                    consume()
            else:
                yield os.path.join(dir_, tok)

    if peek() == "{":
        consume()
        yield from body(base)
        if peek() == "}":
            consume()
    else:
        yield from body(base)


def check(files):
    total = 0
    errors = 0
    for path in files:
        total += 1
        try:
            result = subprocess.run(
                ["npx", "tree-sitter", "parse", path, "--quiet"],
                capture_output=True,
                text=True,
                timeout=30,
            )
        except subprocess.TimeoutExpired:
            errors += 1
            print(f"TIMEOUT: {path}")
            continue
        out = result.stdout + result.stderr
        if "ERROR" in out or "MISSING" in out:
            errors += 1
            print(f"FAIL: {path}")
            for line in out.splitlines():
                if "ERROR" in line or "MISSING" in line:
                    print(f"  {line.strip()}")
            print("---")
        if total % 200 == 0:
            print(f"[progress] {total} files, {errors} errors", file=sys.stderr)
    print()
    if total:
        rate = (total - errors) * 100 / total
        print(f"Spec: {total} files, {errors} errors, {rate:.2f}% success")
    else:
        print("Spec: 0 files")
    return 1 if errors else 0


def main():
    p = argparse.ArgumentParser(description=__doc__,
                                formatter_class=argparse.RawDescriptionHelpFormatter)
    p.add_argument("spec_file", help="Path to a Magma spec file")
    p.add_argument("--check", action="store_true",
                   help="Run tree-sitter parse on each file and report errors")
    args = p.parse_args()

    files = list(walk(args.spec_file))
    if args.check:
        sys.exit(check(files))
    for f in files:
        print(f)


if __name__ == "__main__":
    try:
        main()
    except BrokenPipeError:
        # Allow `parse_spec.py … | head` etc. to exit cleanly.
        try:
            sys.stdout.close()
        except Exception:
            pass
        sys.exit(0)
