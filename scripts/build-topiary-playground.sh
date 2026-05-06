#!/usr/bin/env bash
# build-topiary-playground.sh
#
# Build a deployable magma-aware Topiary playground.
#
# Usage:
#   scripts/build-topiary-playground.sh
#
# Environment variables:
#   OUT_DIR   — where to write the final dist/ tree (default: <repo-root>/playground-dist)
#
# Required tools (not installed by this script):
#   git, patch, python3
#   tree-sitter (CLI >=0.25)
#   cargo, rustup, wasm-pack, wasm-bindgen (=0.2.91)
#   node, npm
#   docker OR podman OR emcc  (for tree-sitter build --wasm)

set -euo pipefail

# ---------------------------------------------------------------------------
# Paths
# ---------------------------------------------------------------------------
SCRIPT_DIR="$(cd "$(dirname "$0")" && pwd)"
REPO_ROOT="$(cd "${SCRIPT_DIR}/.." && pwd)"

PLAYGROUND_SHA="39cdd5dfa9146e5dc43d84e7d1d17195adbf13dd"
PLAYGROUND_REPO="https://github.com/topiary/playground"
TOPIARY_REPO="https://github.com/tweag/topiary"

PATCH_FILE="${REPO_ROOT}/topiary/playground.patch"
QUERY_FILE="${REPO_ROOT}/topiary/magma.scm"
SAMPLE_FILE="${REPO_ROOT}/topiary/sample.m"

OUT_DIR="${OUT_DIR:-${REPO_ROOT}/playground-dist}"

# ---------------------------------------------------------------------------
# Work dir — cleaned up on exit
# ---------------------------------------------------------------------------
WORK_DIR="$(mktemp -d)"
trap 'rm -rf "$WORK_DIR"' EXIT

PLAYGROUND_DIR="${WORK_DIR}/topiary-playground"
TOPIARY_DIR="${WORK_DIR}/topiary"

# ---------------------------------------------------------------------------
# Phase 1: Clone topiary/playground at the pinned SHA
# ---------------------------------------------------------------------------
echo "==> [1/9] Cloning topiary-playground at ${PLAYGROUND_SHA}"
git clone "${PLAYGROUND_REPO}" "${PLAYGROUND_DIR}"
git -C "${PLAYGROUND_DIR}" checkout "${PLAYGROUND_SHA}"

# ---------------------------------------------------------------------------
# Phase 2: Clone tweag/topiary (latest) for bin/build-languages-export.sh
# ---------------------------------------------------------------------------
echo "==> [2/9] Cloning tweag/topiary (latest)"
git clone --depth=1 "${TOPIARY_REPO}" "${TOPIARY_DIR}"

# ---------------------------------------------------------------------------
# Phase 3: Apply the magma patch to the playground checkout
# ---------------------------------------------------------------------------
echo "==> [3/9] Applying topiary/playground.patch"
patch -p1 -d "${PLAYGROUND_DIR}" < "${PATCH_FILE}"

# ---------------------------------------------------------------------------
# Phase 4: Build tree-sitter-magma.wasm and copy into the playground
# ---------------------------------------------------------------------------
echo "==> [4/9] Generating and building tree-sitter-magma.wasm"
(
  cd "${REPO_ROOT}"
  tree-sitter generate
  tree-sitter build --wasm
)
WASM_DEST="${PLAYGROUND_DIR}/web-playground/public/scripts"
mkdir -p "${WASM_DEST}"
cp "${REPO_ROOT}/tree-sitter-magma.wasm" "${WASM_DEST}/"

# ---------------------------------------------------------------------------
# Phase 5: Build the topiary-playground crate to WASM
# ---------------------------------------------------------------------------
# Build inside the upstream flake's devShell so we get the exact rust +
# wasm-pack + wasm-bindgen + WASI sysroot the topiary playground was
# tested with. Avoids the wasm32-unknown-unknown / WASI subdir mismatch
# we hit when trying to bridge cc-rs to wasi-sdk manually.
echo "==> [5/9] Building topiary-playground crate with wasm-pack (inside nix develop)"
(
  cd "${PLAYGROUND_DIR}"
  nix develop --command wasm-pack build --target web --out-dir web-playground/src/wasm-app
)

# ---------------------------------------------------------------------------
# Phase 6: Generate languages_export.ts via upstream script
# ---------------------------------------------------------------------------
# Upstream's bin/build-languages-export.sh takes a single positional argument
# (the tweag/topiary checkout) and writes ./languages_export.ts in cwd.
echo "==> [6/9] Generating languages_export.ts"
LANGUAGES_EXPORT_TS="${PLAYGROUND_DIR}/web-playground/src/samples/languages_export.ts"
(cd "${PLAYGROUND_DIR}" && bash bin/build-languages-export.sh "${TOPIARY_DIR}")
mv "${PLAYGROUND_DIR}/languages_export.ts" "${LANGUAGES_EXPORT_TS}"

# ---------------------------------------------------------------------------
# Phase 7: Append magma entry to languages_export.ts
# ---------------------------------------------------------------------------
echo "==> [7/9] Appending magma entry to languages_export.ts"
export LANGUAGES_EXPORT_TS QUERY_FILE SAMPLE_FILE
python3 - <<'EOF'
import pathlib, os

ts_path  = pathlib.Path(os.environ["LANGUAGES_EXPORT_TS"])
query    = pathlib.Path(os.environ["QUERY_FILE"]).read_text()
sample   = pathlib.Path(os.environ["SAMPLE_FILE"]).read_text()
ts       = ts_path.read_text()

def js(s):
    return s.replace("\\", "\\\\").replace("`", "\\`").replace("${", "\\${")

entry    = '  "magma": {\n    "query": `' + js(query) + '`,\n    "input": `' + js(sample) + '`,\n  },\n'
sentinel = "};\n\nexport default languages;"

if "magma" in ts:
    raise SystemExit("languages_export.ts already has a magma entry; bug in the script")

ts_path.write_text(ts.replace(sentinel, entry + sentinel))
EOF

# ---------------------------------------------------------------------------
# Phase 8: Build the Vite frontend
# ---------------------------------------------------------------------------
echo "==> [8/9] Building Vite frontend"
(
  cd "${PLAYGROUND_DIR}/web-playground"
  npm install
  npm run build
)

# ---------------------------------------------------------------------------
# Phase 9: Copy dist/ to $OUT_DIR
# ---------------------------------------------------------------------------
echo "==> [9/9] Copying dist to ${OUT_DIR}"
rm -rf "${OUT_DIR}"
mkdir -p "$(dirname "${OUT_DIR}")"
cp -r "${PLAYGROUND_DIR}/web-playground/dist" "${OUT_DIR}"

echo ""
echo "Build complete. Playground written to: ${OUT_DIR}"
