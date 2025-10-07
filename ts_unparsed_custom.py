#!/usr/bin/env python3
import argparse, json, os, sys, importlib
from typing import List, Tuple, Set
from tree_sitter import Language, Parser

# If your grammar exports 'statement' as a supertype, list it here.
PREFERRED_SUPERTYPES = {"statement"}

# Heuristic fallback when no 'statement' supertype exists.
LIKELY_STATEMENT_TYPES = {
    "expression_statement","declaration","function_declaration","method_declaration",
    "class_declaration","if_statement","for_statement","while_statement","switch_statement",
    "return_statement","block","compound_statement","let_declaration","short_var_declaration",
    "var_declaration","const_declaration","local_variable_declaration","field_declaration",
    "try_statement","with_statement"
}
HINT_SUBSTRS = (
    "statement","declaration","definition","specifier",
    "clause","item","rule","assignment","directive"
)

def looks_like_statement(node_type: str, have_supertype: bool) -> bool:
    if have_supertype and node_type == "statement":
        return True
    if node_type in LIKELY_STATEMENT_TYPES:
        return True
    for s in HINT_SUBSTRS:
        if s in node_type:
            return True
    return False

def iter_named(node):
    stack = [node]
    while stack:
        cur = stack.pop()
        yield cur
        for i in range(cur.named_child_count - 1, -1, -1):
            stack.append(cur.named_child(i))

def gather_errors_explicit(root) -> List:
    out = []
    for n in iter_named(root):
        is_err = getattr(n, "is_error", False)
        is_mis = getattr(n, "is_missing", False)
        if is_err or is_mis:
            out.append(n)
    return out

def gather_errors_subtree(root) -> List:
    # Pick smallest nodes whose subtree has_error == True and whose parent does not.
    out = []
    for n in iter_named(root):
        if not n.has_error:
            continue
        p = n.parent
        if p is None or not getattr(p, "has_error", False):
            out.append(n)
    return out

def nearest_statement(err_node, have_supertype: bool):
    # climb to nearest statement-ish ancestor; otherwise smallest named ancestor
    a = err_node
    hops = 0
    while a is not None and hops < 512:
        if looks_like_statement(a.type, have_supertype):
            return a
        a = a.parent
        hops += 1
    a = err_node.parent
    while a is not None and not a.is_named:
        a = a.parent
    return a or err_node

def unique_by_span(nodes: List) -> List:
    seen: Set[Tuple[int,int,str]] = set()
    uniq = []
    for n in nodes:
        key = (n.start_byte, n.end_byte, n.type)
        if key not in seen:
            seen.add(key)
            uniq.append(n)
    return uniq

def width_for_linecount(n):
    return max(1, len(str(n)))

def render_lines(src_text: str, a_row: int, b_row: int) -> List[str]:
    lines = src_text.splitlines()
    a = max(0, a_row); b = min(len(lines)-1, b_row)
    pad = width_for_linecount(b+1)
    block = []
    for i in range(a, b+1):
        block.append(f"{str(i+1).rjust(pad)}| {lines[i]}")
    return block

def main():
    ap = argparse.ArgumentParser(description="Report statements containing Tree-sitter parse errors for a custom grammar.")
    ap.add_argument("path", help="source file to analyze")
    ap.add_argument("--lib", required=True, help="path to your compiled language shared library (.so/.dylib/.dll)")
    ap.add_argument("--lang", required=True, help="language name as exported by the shared library")
    ap.add_argument("--json", action="store_true", help="emit JSON")
    ap.add_argument("--mode", choices=["explicit","subtree"], default="explicit",
                    help="explicit: ERROR/MISSING nodes only; subtree: minimal has_error subtrees")
    args = ap.parse_args()

    try:
        src_bytes = open(args.path, "rb").read()
    except Exception as e:
        sys.stderr.write(f"read error: {e}\n"); sys.exit(2)
    src_text = src_bytes.decode("utf8", errors="replace")

    # Try multiple loading strategies to support both old and new Python APIs:
    # 1) Preferred for tree-sitter >= 0.25: import the generated Python package
    #    (e.g. tree_sitter_magma) and build Language from its language() capsule.
    # 2) Fallback for older APIs: load from shared library path (args.lib).
    lang = None
    load_errors = []

    # Strategy 1: module-based (tree-sitter >= 0.25)
    module_name = args.lang if "." in args.lang else f"tree_sitter_{args.lang}"
    try:
        mod = importlib.import_module(module_name)
        if hasattr(mod, "language"):
            lang = Language(mod.language())
        else:
            load_errors.append(
                f"module {module_name} has no language() function"
            )
    except Exception as e:
        load_errors.append(f"module load failed: {module_name}: {e}")

    # Strategy 2: legacy shared-library loading
    if lang is None:
        try:
            # Old signature: Language(path, symbol_name)
            lang = Language(args.lib, args.lang)
        except TypeError as e:
            load_errors.append(f"Language(path, name) unsupported: {e}")
            try:
                # Some releases provided Language.load(path)
                if hasattr(Language, "load"):
                    lang = Language.load(args.lib)
                else:
                    # Some builds accept Language(path) where the lib exposes a single language
                    lang = Language(args.lib)
            except Exception as e2:
                load_errors.append(f"Language.load/path failed: {e2}")
        except Exception as e:
            load_errors.append(f"Language(path, name) raised: {e}")

    if lang is None:
        sys.stderr.write(
            "could not load language; tried module '" + module_name +
            "' and shared library methods. Errors: " + "; ".join(load_errors) +
            "\n"
        )
        sys.exit(2)

    parser = Parser(language=lang)
    tree = parser.parse(src_bytes)
    root = tree.root_node

    # Detect whether grammar exposes a 'statement' supertype.
    # Tree-sitter bindings do not expose supertypes list, so we infer by name usage.
    have_supertype = True  # optimistic: many grammars define a 'statement' rule
    # If that assumption is wrong for your grammar, set to False or rename the rule.

    if args.mode == "explicit":
        err_like = gather_errors_explicit(root)
    else:
        err_like = gather_errors_subtree(root)

    if not err_like:
        if args.json:
            print(json.dumps({
                "file": os.path.abspath(args.path),
                "language": args.lang,
                "count": 0,
                "unparsed_statements": []
            }, indent=2))
        else:
            print("No unparseable regions found.")
        return

    # Map each error-ish node to its enclosing statement-ish node.
    stmts = [nearest_statement(n, have_supertype) for n in err_like]
    stmts = unique_by_span(stmts)

    if args.json:
        items = []
        for s in stmts:
            items.append({
                "type": s.type,
                "line_start": s.start_point.row + 1,
                "line_end":   s.end_point.row + 1,
                "byte_start": s.start_byte,
                "byte_end":   s.end_byte
            })
        print(json.dumps({
            "file": os.path.abspath(args.path),
            "language": args.lang,
            "mode": args.mode,
            "count": len(items),
            "unparsed_statements": items
        }, indent=2))
        return

    print(f"File: {os.path.abspath(args.path)}")
    print(f"Language: {args.lang}  Mode: {args.mode}")
    print(f"Unparseable statements: {len(stmts)}\n")

    for i, s in enumerate(stmts, 1):
        a_row, b_row = s.start_point.row, s.end_point.row
        a_col, b_col = s.start_point.column, s.end_point.column
        print(f"[{i}] type={s.type} lines={a_row+1}-{b_row+1} cols={a_col+1}-{b_col+1} bytes={s.start_byte}-{s.end_byte}")

        inner = []
        for n in iter_named(s):
            if getattr(n, "is_error", False):
                inner.append("ERROR")
            elif getattr(n, "is_missing", False):
                inner.append(f"MISSING<{n.type}>")
        if inner:
            print(f"    inner: {', '.join(inner)}")
        print()
        for line in render_lines(src_text, a_row, b_row):
            print("    " + line)
        print()

if __name__ == "__main__":
    main()
