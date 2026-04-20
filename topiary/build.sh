#!/usr/bin/env bash
# Build the Magma grammar shared library and run the formatter.
#
# Usage:
#   ./topiary/build.sh build          # Compile grammar .so (incremental)
#   ./topiary/build.sh format <file>  # Format a Magma file
#   ./topiary/build.sh test           # Run formatter tests

set -euo pipefail
SCRIPT_DIR="$(cd "$(dirname "$0")" && pwd)"
REPO_DIR="$(dirname "$SCRIPT_DIR")"
PARSER_C="$REPO_DIR/src/parser.c"
SCANNER_C="$REPO_DIR/src/scanner.c"
SO_PATH="$SCRIPT_DIR/magma.so"

build() {
    if [ ! -f "$PARSER_C" ] || [ "$REPO_DIR/grammar.js" -nt "$PARSER_C" ]; then
        echo "Generating parser..."
        (cd "$REPO_DIR" && npx tree-sitter generate)
    fi
    if [ ! -f "$SO_PATH" ] || [ "$PARSER_C" -nt "$SO_PATH" ] || [ "$SCANNER_C" -nt "$SO_PATH" ]; then
        echo "Compiling shared library..."
        cc -shared -fPIC -o "$SO_PATH" "$PARSER_C" "$SCANNER_C" -I "$REPO_DIR/src/"
        echo "Built: $SO_PATH"
    fi
}

format_file() {
    build
    (cd "$SCRIPT_DIR" && topiary format --language magma \
        --configuration "$SCRIPT_DIR/languages.ncl" \
        --query "$SCRIPT_DIR/magma.scm" \
        < "$1")
}

run_tests() {
    build
    local pass=0 fail=0
    for input in "$SCRIPT_DIR/test/input/"*.m; do
        name=$(basename "$input")
        expected="$SCRIPT_DIR/test/expected/$name"
        if [ ! -f "$expected" ]; then
            echo "SKIP: $name (no expected file)"
            continue
        fi
        actual=$(format_file "$input")
        if diff <(printf '%s\n' "$actual") "$expected" > /dev/null 2>&1; then
            echo "PASS: $name"
            pass=$((pass + 1))
        else
            echo "FAIL: $name"
            diff <(printf '%s\n' "$actual") "$expected" || true
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
