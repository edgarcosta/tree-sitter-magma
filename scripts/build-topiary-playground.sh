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

# ---------------------------------------------------------------------------
# Phase 1: Clone topiary/playground at the pinned SHA
# ---------------------------------------------------------------------------
echo "==> [1/8] Cloning topiary-playground at ${PLAYGROUND_SHA}"
git clone "${PLAYGROUND_REPO}" "${PLAYGROUND_DIR}"
git -C "${PLAYGROUND_DIR}" checkout "${PLAYGROUND_SHA}"

# ---------------------------------------------------------------------------
# Phase 2: Apply the magma patch to the playground checkout
# ---------------------------------------------------------------------------
echo "==> [2/8] Applying topiary/playground.patch"
patch -p1 -d "${PLAYGROUND_DIR}" < "${PATCH_FILE}"

# ---------------------------------------------------------------------------
# Phase 3: Build tree-sitter-magma.wasm and copy into the playground
# ---------------------------------------------------------------------------
echo "==> [3/8] Generating and building tree-sitter-magma.wasm"
(
  cd "${REPO_ROOT}"
  tree-sitter generate
  tree-sitter build --wasm
)
WASM_DEST="${PLAYGROUND_DIR}/web-playground/public/scripts"
mkdir -p "${WASM_DEST}"
cp "${REPO_ROOT}/tree-sitter-magma.wasm" "${WASM_DEST}/"

# ---------------------------------------------------------------------------
# Phase 4: Build the topiary-playground crate to WASM
# ---------------------------------------------------------------------------
# Build inside the upstream flake's devShell so we get the exact rust +
# wasm-bindgen + WASI sysroot the topiary playground was tested with.
# wasm-pack itself is provided by 'nix profile install nixpkgs#wasm-pack'
# in the workflow because the upstream devShell doesn't include it.
echo "==> [4/8] Building topiary-playground crate with wasm-pack (inside nix develop)"
(
  cd "${PLAYGROUND_DIR}"
  nix develop --command wasm-pack build --target web --out-dir web-playground/src/wasm-app
)

# ---------------------------------------------------------------------------
# Phase 5: Write a magma-only languages_export.ts
# ---------------------------------------------------------------------------
# We don't use the upstream bin/build-languages-export.sh: it walks tweag/
# topiary's queries dir, whose layout has drifted from what the pinned
# playground expects, and we only want magma in this fork's playground
# anyway.
echo "==> [5/8] Writing magma-only languages_export.ts"
LANGUAGES_EXPORT_TS="${PLAYGROUND_DIR}/web-playground/src/samples/languages_export.ts"
mkdir -p "$(dirname "${LANGUAGES_EXPORT_TS}")"
export LANGUAGES_EXPORT_TS QUERY_FILE SAMPLE_FILE
python3 - <<'EOF'
import pathlib, os

ts_path = pathlib.Path(os.environ["LANGUAGES_EXPORT_TS"])
query   = pathlib.Path(os.environ["QUERY_FILE"]).read_text()
sample  = pathlib.Path(os.environ["SAMPLE_FILE"]).read_text()

def js(s):
    return s.replace("\\", "\\\\").replace("`", "\\`").replace("${", "\\${")

ts_path.write_text(
    "const languages: {[index: string]: any} = {\n"
    f'  "magma": {{\n'
    f'    "query": `{js(query)}`,\n'
    f'    "input": `{js(sample)}`,\n'
    f'  }},\n'
    "};\n\n"
    "export default languages;\n"
)
EOF

# ---------------------------------------------------------------------------
# Phase 6: Install Vite frontend deps
# ---------------------------------------------------------------------------
echo "==> [6/8] Installing Vite frontend deps"
(cd "${PLAYGROUND_DIR}/web-playground" && npm install)

# ---------------------------------------------------------------------------
# Phase 7: Build the Vite frontend
# ---------------------------------------------------------------------------
echo "==> [7/8] Building Vite frontend"
(cd "${PLAYGROUND_DIR}/web-playground" && npm run build)

# ---------------------------------------------------------------------------
# Phase 8: Copy dist/ to $OUT_DIR
# ---------------------------------------------------------------------------
echo "==> [8/8] Copying dist to ${OUT_DIR}"
rm -rf "${OUT_DIR}"
mkdir -p "$(dirname "${OUT_DIR}")"
cp -r "${PLAYGROUND_DIR}/web-playground/dist" "${OUT_DIR}"

echo ""
echo "Build complete. Playground written to: ${OUT_DIR}"
