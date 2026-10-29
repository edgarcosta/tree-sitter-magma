#!/usr/bin/env python3
"""Parse real Magma files and report errors, speed, and peak memory.

Needs the Python binding built in place: python3 setup.py build_ext --inplace

    scripts/parse_corpus.py --spec /path/to/package/spec   # files Magma loads
    scripts/parse_corpus.py DIR_OR_FILE ...                 # *.m, *.mag, *.magma
"""

import argparse
import os
import resource
import sys
import time

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
sys.path[:0] = [os.path.join(ROOT, "scripts"), os.path.join(ROOT, "bindings", "python")]


def iter_files(args):
    if args.spec:
        from parse_spec import walk
        yield from walk(args.spec)
    for path in args.paths:
        if os.path.isfile(path):
            yield path
        for dirpath, _, names in sorted(os.walk(path)):
            yield from (os.path.join(dirpath, n) for n in sorted(names)
                        if n.endswith((".m", ".mag", ".magma")))


def first_error(node):
    stack = [node]
    while stack:
        node = stack.pop()
        if node.type == "ERROR" or node.is_missing:
            return node
        stack.extend(c for c in reversed(node.children) if c.has_error)


def main():
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("paths", nargs="*")
    ap.add_argument("--spec", help="Magma spec file; parse only the files it loads")
    args = ap.parse_args()
    if not (args.paths or args.spec):
        ap.error("give --spec or at least one path")
    try:
        import tree_sitter
        import tree_sitter_magma
    except ImportError as exc:
        sys.exit(f"{exc}\nBuild the binding first: python3 setup.py build_ext --inplace")
    language = tree_sitter.Language(tree_sitter_magma.language())
    parser = tree_sitter.Parser(language)

    files = failures = total = 0
    slowest = (0, "")
    started = time.perf_counter()
    for path in iter_files(args):
        with open(path, "rb") as handle:
            data = handle.read()
        t0 = time.perf_counter()
        tree = parser.parse(data)
        elapsed = time.perf_counter() - t0
        files += 1
        total += len(data)
        slowest = max(slowest, (elapsed, path))
        if tree.root_node.has_error:
            failures += 1
            err = first_error(tree.root_node)
            print(f"FAIL {path}: {err.type} at {err.start_point}: {err.text[:60]!r}")
    wall = time.perf_counter() - started
    rss = resource.getrusage(resource.RUSAGE_SELF).ru_maxrss / (1e6 if sys.platform == "darwin" else 1e3)
    print(f"files: {files}  with errors: {failures}  bytes: {total}  abi: {language.abi_version}")
    print(f"wall: {wall:.1f}s  throughput: {total / wall / 1e6:.1f} MB/s  peak RSS: {rss:.0f} MB")
    print(f"slowest: {slowest[1]} ({slowest[0] * 1000:.0f} ms)")
    return 1 if failures else 0


if __name__ == "__main__":
    sys.exit(main())
