#!/usr/bin/env bash
# Build the Magma grammar shared library and run the formatter
#
# Usage:
#   ./topiary/build.sh build          # Compile grammar .so
#   ./topiary/build.sh format <file>  # Format a Magma file
#   ./topiary/build.sh test           # Run formatter tests
#
# NOTE: Due to how tree-sitter exposes anonymous token byte ranges,
# Topiary preserves source spacing before operators (:=, +, -, etc.).
# The formatter normalizes indentation, line breaks, and structural
# formatting. Operator spacing is preserved from the source input.

set -euo pipefail
SCRIPT_DIR="$(cd "$(dirname "$0")" && pwd)"
REPO_DIR="$(dirname "$SCRIPT_DIR")"
SO_PATH="$SCRIPT_DIR/magma.so"

build() {
    echo "Generating parser..."
    (cd "$REPO_DIR" && npx tree-sitter generate)
    echo "Compiling shared library..."
    cc -shared -fPIC -o "$SO_PATH" \
        "$REPO_DIR/src/parser.c" \
        "$REPO_DIR/src/scanner.c" \
        -I "$REPO_DIR/src/"
    echo "Built: $SO_PATH"
}

format_file() {
    if [ ! -f "$SO_PATH" ]; then
        build
    fi
    (cd "$SCRIPT_DIR" && topiary format --language magma \
        --configuration "$SCRIPT_DIR/languages.ncl" \
        --query "$SCRIPT_DIR/magma.scm" \
        --skip-idempotence \
        < "$1")
}

run_tests() {
    if [ ! -f "$SO_PATH" ]; then
        build
    fi
    local pass=0 fail=0
    for input in "$SCRIPT_DIR/test/input/"*.m; do
        name=$(basename "$input")
        expected="$SCRIPT_DIR/test/expected/$name"
        if [ ! -f "$expected" ]; then
            echo "SKIP: $name (no expected file)"
            continue
        fi
        actual=$(format_file "$input")
        if diff -q <(echo "$actual") "$expected" > /dev/null 2>&1; then
            echo "PASS: $name"
            pass=$((pass + 1))
        else
            echo "FAIL: $name"
            diff <(echo "$actual") "$expected" || true
            fail=$((fail + 1))
        fi
    done
    echo "---"
    echo "Passed: $pass, Failed: $fail"
    [ "$fail" -eq 0 ]
}

case "${1:-build}" in
    build) build ;;
    format) format_file "$2" ;;
    test) run_tests ;;
    *) echo "Usage: $0 {build|format <file>|test}" >&2; exit 1 ;;
esac
