#!/usr/bin/env bash
# Parse all Magma package files and report error statistics
#
# Usage: ./scripts/parse_packages.sh [PACKAGE_DIR]
# Default PACKAGE_DIR: /opt/magma/current/package
#
# Baseline (before grammar hardening): ~32.5% error rate (estimated from 200-file sample)
# After grammar hardening: 21/3465 files (0.6%), 99.39% success rate
#
# Remaining 21 failures:
#   6 files - MATLAB/R code, not Magma (benchmark.m, stab.m, conj_matlab.m, prospect.m)
#   4 files - backslash continuation inside identifiers (DOrelations.m, Interpolations.m, g3twists*.m)
#   4 files - missing semicolons after 'end case' (db.m, q_expansions.m, torsion_subgroups.m, prime_proof.m)
#   6 files - misc edge cases (empty when body, when without case, ambiguous syntax, etc.)

set -euo pipefail

PACKAGE_DIR="${1:-/opt/magma/current/package}"
SCRIPT_DIR="$(cd "$(dirname "$0")/.." && pwd)"
TOTAL=0
ERRORS=0
ERROR_LOG=$(mktemp)

if [ ! -d "$PACKAGE_DIR" ]; then
    echo "Error: Directory $PACKAGE_DIR does not exist" >&2
    exit 1
fi

trap "rm -f $ERROR_LOG" EXIT

while IFS= read -r -d '' file; do
    TOTAL=$((TOTAL + 1))
    output=$(cd "$SCRIPT_DIR" && npx tree-sitter parse "$file" 2>&1) || true
    if echo "$output" | grep -q "ERROR"; then
        ERRORS=$((ERRORS + 1))
        echo "FAIL: $file"
        # Extract ERROR context lines and write to temp file
        echo "$output" | grep "ERROR" | head -5 | tee -a "$ERROR_LOG"
        echo "---"
    fi
    if (( TOTAL % 200 == 0 )); then
        echo "[progress] $TOTAL files processed, $ERRORS errors so far..." >&2
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
sed 's/^[[:space:]]*//' "$ERROR_LOG" | grep -oP '\(ERROR[^)]*\)|\(MISSING[^)]*\)' | sort | uniq -c | sort -rn | head -20
