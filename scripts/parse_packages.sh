#!/usr/bin/env bash
# Parse all Magma package files and report error statistics
#
# Usage: ./scripts/parse_packages.sh [PACKAGE_DIR]
# Default PACKAGE_DIR: /opt/magma/current/package

set -euo pipefail

PACKAGE_DIR="${1:-/opt/magma/current/package}"
SCRIPT_DIR="$(cd "$(dirname "$0")/.." && pwd)"
TOTAL=0
ERRORS=0
ERROR_CONTEXTS=""

if [ ! -d "$PACKAGE_DIR" ]; then
    echo "Error: Directory $PACKAGE_DIR does not exist" >&2
    exit 1
fi

while IFS= read -r -d '' file; do
    TOTAL=$((TOTAL + 1))
    output=$(cd "$SCRIPT_DIR" && npx tree-sitter parse "$file" 2>&1) || true
    if echo "$output" | grep -q "ERROR"; then
        ERRORS=$((ERRORS + 1))
        echo "FAIL: $file"
        # Extract ERROR context lines for later analysis
        error_lines=$(echo "$output" | grep "ERROR" | head -5)
        echo "$error_lines"
        ERROR_CONTEXTS="${ERROR_CONTEXTS}${error_lines}"$'\n'
        echo "---"
    fi
done < <(find "$PACKAGE_DIR" -name "*.m" -type f -print0 | sort -z)

echo ""
echo "========================================="
echo "Parse Report"
echo "========================================="
echo "Total files:  $TOTAL"
echo "With errors:  $ERRORS"
if [ "$TOTAL" -gt 0 ]; then
    RATE=$(echo "scale=1; $ERRORS * 100 / $TOTAL" | bc)
    echo "Error rate:   ${RATE}%"
fi
echo "========================================="
echo ""
echo "Most common ERROR contexts:"
echo "$ERROR_CONTEXTS" | sed 's/^[[:space:]]*//' | grep -oP '\(ERROR[^)]*\)|\(MISSING[^)]*\)' | sort | uniq -c | sort -rn | head -20
