#!/usr/bin/env bash
# Build the Magma grammar shared library and run the formatter
#
# Usage:
#   ./topiary/build.sh build          # Compile grammar .so
#   ./topiary/build.sh format <file>  # Format a Magma file
#   ./topiary/build.sh test           # Run formatter tests

set -euo pipefail
SCRIPT_DIR="$(cd "$(dirname "$0")" && pwd)"
REPO_DIR="$(dirname "$SCRIPT_DIR")"
SO_PATH="$SCRIPT_DIR/magma.so"
if [ -z "${TREE_SITTER:-}" ]; then
    if [ -x "$REPO_DIR/node_modules/.bin/tree-sitter" ]; then
        TREE_SITTER="$REPO_DIR/node_modules/.bin/tree-sitter"
    else
        TREE_SITTER="tree-sitter"
    fi
fi
export TREE_SITTER

build() {
    echo "Generating parser..." >&2
    (cd "$REPO_DIR" && "$TREE_SITTER" generate) >&2
    echo "Compiling shared library..." >&2
    cc -shared -fPIC -o "$SO_PATH" \
        "$REPO_DIR/src/parser.c" \
        "$REPO_DIR/src/scanner.c" \
        -I "$REPO_DIR/src/"
    echo "Built: $SO_PATH" >&2
}

ensure_built() {
    if [ ! -f "$SO_PATH" ] ||
       [ "$REPO_DIR/grammar.js" -nt "$SO_PATH" ] ||
       [ "$REPO_DIR/src/parser.c" -nt "$SO_PATH" ] ||
       [ "$REPO_DIR/src/scanner.c" -nt "$SO_PATH" ]; then
        build
    fi
}

format_file() {
    ensure_built
    local input
    input="$(realpath "$1")"
    (cd "$SCRIPT_DIR" && topiary format --language magma \
        --configuration "$SCRIPT_DIR/languages.ncl" \
        --query "$SCRIPT_DIR/magma.scm" \
        < "$input")
}

run_tests() {
    ensure_built
    python3 "$SCRIPT_DIR/test_checks.py"
    python3 "$SCRIPT_DIR/test.py"
}

case "${1:-build}" in
    build) build ;;
    format) format_file "$2" ;;
    test) run_tests ;;
    *) echo "Usage: $0 {build|format <file>|test}" >&2; exit 1 ;;
esac
