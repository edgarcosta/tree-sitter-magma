"""Compare formatter output using the complete tree and terminal contents."""

import os
from pathlib import Path
import shutil
import subprocess
import tempfile
import xml.etree.ElementTree as ET


REPO_ROOT = Path(__file__).resolve().parent.parent
# Named terminals in grammar.js (including the external real-number token).
TERMINALS = {
    "identifier", "anonymous_identifier", "integer", "real", "string",
    "comment", "doc_string", "true", "false",
}


def tree_sitter_binary():
    configured = os.environ.get("TREE_SITTER")
    local = REPO_ROOT / "node_modules" / ".bin" / "tree-sitter"
    binary = configured or (str(local) if local.is_file() else shutil.which("tree-sitter"))
    if not binary:
        raise RuntimeError("tree-sitter is required; run npm ci or set TREE_SITTER")
    return binary


def syntax_signature(source: bytes):
    """Retain hierarchy, fields, anonymous tokens, and exact named leaf text.

    XML supplies hierarchy and anonymous tokens. Read named leaves from the
    original bytes using the parser's positions, so whitespace inside strings
    and numeric literals remains significant. Only comment indentation may
    change: Topiary shifts multiline comments with their enclosing block.
    """
    with tempfile.TemporaryDirectory(prefix="magma-format-check-") as directory:
        path = Path(directory) / "source.m"
        path.write_bytes(source)
        result = subprocess.run(
            [tree_sitter_binary(), "parse", "--xml", str(path)],
            cwd=REPO_ROOT,
            capture_output=True,
            timeout=60,
        )
    if result.returncode:
        raise ValueError(
            "tree-sitter failed:\n"
            + result.stderr.decode(errors="replace")
            + result.stdout.decode(errors="replace")
        )
    try:
        root = ET.fromstring(result.stdout)
    except ET.ParseError as error:
        raise ValueError("tree-sitter did not return a valid XML tree") from error
    offsets = [0]
    for line in source.split(b"\n")[:-1]:
        offsets.append(offsets[-1] + len(line) + 1)

    def signature(node):
        if node.tag in {"ERROR", "MISSING"}:
            raise ValueError(f"invalid syntax: {node.tag}")
        identity = (node.tag, node.get("field"))
        if node.tag in TERMINALS:
            start = offsets[int(node.attrib["srow"])] + int(node.attrib["scol"])
            end = offsets[int(node.attrib["erow"])] + int(node.attrib["ecol"])
            text = source[start:end]
            if node.tag == "comment":
                text = b"\n".join(line.lstrip(b" \t") for line in text.split(b"\n"))
            return (*identity, text)
        # XML prints each anonymous token on its own line. Preserve their
        # boundaries, including punctuation that a named-node-only walk loses.
        contents = [tuple((node.text or "").split())]
        for child in node:
            contents.append(signature(child))
            contents.append(tuple((child.tail or "").split()))
        return (*identity, tuple(contents))

    return signature(root)
