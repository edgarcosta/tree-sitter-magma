#!/usr/bin/env python3
"""Extract Magma source code from tree-sitter corpus test files.

Corpus format:
    ===...===
    Test Name
    ===...===

    source code here;

    ---

    (expected tree)

Outputs each test as a separate file in the output directory,
named <corpus_file>__<test_name>.m
"""

import argparse
import os
import re
import sys


def extract_tests(corpus_file):
    """Yield (test_name, source_code) pairs from a corpus file."""
    with open(corpus_file) as f:
        content = f.read()

    # Split on === separator lines
    parts = re.split(r'^={3,}\s*$', content, flags=re.MULTILINE)

    # parts alternates: [preamble, name, body, name, body, ...]
    # After the first split, odd indices are names, even indices are bodies
    i = 1  # skip preamble
    while i + 1 < len(parts):
        name = parts[i].strip()
        body = parts[i + 1]

        # Split body on --- separator to get source code and expected tree
        sections = re.split(r'^-{3,}\s*$', body, flags=re.MULTILINE)
        if sections:
            source = sections[0].strip()
            if source:
                yield name, source

        i += 2


def sanitize_filename(name):
    """Convert test name to a safe filename."""
    return re.sub(r'[^a-zA-Z0-9_-]', '_', name).strip('_')[:80]


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('corpus_dir', help='Directory containing corpus .txt files')
    parser.add_argument('output_dir', help='Directory to write extracted .m files')
    parser.add_argument('--skip', nargs='*', default=['invalid'],
                        help='Corpus files to skip (default: invalid)')
    parser.add_argument('--list', action='store_true',
                        help='Just list test names, do not write files')
    args = parser.parse_args()

    os.makedirs(args.output_dir, exist_ok=True)

    total = 0
    for fname in sorted(os.listdir(args.corpus_dir)):
        if not fname.endswith('.txt'):
            continue
        base = fname[:-4]
        if base in (args.skip or []):
            continue

        corpus_path = os.path.join(args.corpus_dir, fname)
        for name, source in extract_tests(corpus_path):
            total += 1
            safe_name = sanitize_filename(name)
            out_name = f"{base}__{safe_name}.m"

            if args.list:
                print(f"{out_name}: {name}")
            else:
                out_path = os.path.join(args.output_dir, out_name)
                with open(out_path, 'w') as f:
                    f.write(source + '\n')

    if not args.list:
        print(f"Extracted {total} test snippets to {args.output_dir}")


if __name__ == '__main__':
    main()
