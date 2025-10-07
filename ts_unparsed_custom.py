#!/usr/bin/env python3
import argparse, json, os, sys, importlib
from typing import List, Tuple, Set
from tree_sitter import Language, Parser
from pathlib import Path

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

def get_files_recursively(path: str, extensions: Set[str] = None) -> List[str]:
    """Get all files recursively from a path, optionally filtered by extensions."""
    path_obj = Path(path)
    files = []
    
    if path_obj.is_file():
        return [str(path_obj)]
    elif path_obj.is_dir():
        for file_path in path_obj.rglob("*"):
            if file_path.is_file():
                # If extensions are specified, filter by them
                if extensions is None or file_path.suffix.lower() in extensions:
                    files.append(str(file_path))
    else:
        raise FileNotFoundError(f"Path does not exist: {path}")
    
    return sorted(files)

def process_single_file(file_path: str, parser: Parser, have_supertype: bool, mode: str) -> dict:
    """Process a single file and return results."""
    try:
        src_bytes = open(file_path, "rb").read()
    except Exception as e:
        return {
            "file": os.path.abspath(file_path),
            "error": f"read error: {e}",
            "count": 0,
            "unparsed_statements": []
        }
    
    src_text = src_bytes.decode("utf8", errors="replace")
    tree = parser.parse(src_bytes)
    root = tree.root_node

    if mode == "explicit":
        err_like = gather_errors_explicit(root)
    else:
        err_like = gather_errors_subtree(root)

    if not err_like:
        return {
            "file": os.path.abspath(file_path),
            "count": 0,
            "unparsed_statements": []
        }

    # Map each error-ish node to its enclosing statement-ish node.
    stmts = [nearest_statement(n, have_supertype) for n in err_like]
    stmts = unique_by_span(stmts)

    items = []
    for s in stmts:
        items.append({
            "type": s.type,
            "line_start": s.start_point.row + 1,
            "line_end": s.end_point.row + 1,
            "byte_start": s.start_byte,
            "byte_end": s.end_byte
        })
    
    return {
        "file": os.path.abspath(file_path),
        "count": len(items),
        "unparsed_statements": items
    }

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
    ap.add_argument("path", help="source file or directory to analyze")
    ap.add_argument("--lib", required=True, help="path to your compiled language shared library (.so/.dylib/.dll)")
    ap.add_argument("--lang", required=True, help="language name as exported by the shared library")
    ap.add_argument("--json", action="store_true", help="emit JSON")
    ap.add_argument("--mode", choices=["explicit","subtree"], default="explicit",
                    help="explicit: ERROR/MISSING nodes only; subtree: minimal has_error subtrees")
    ap.add_argument("--ext", nargs="*", help="file extensions to include when scanning directories (e.g., .m .magma)")
    args = ap.parse_args()

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

    # Detect whether grammar exposes a 'statement' supertype.
    # Tree-sitter bindings do not expose supertypes list, so we infer by name usage.
    have_supertype = True  # optimistic: many grammars define a 'statement' rule
    # If that assumption is wrong for your grammar, set to False or rename the rule.

    # Get files to process
    try:
        extensions = set(args.ext) if args.ext else None
        files = get_files_recursively(args.path, extensions)
    except FileNotFoundError as e:
        sys.stderr.write(f"{e}\n")
        sys.exit(2)

    if not files:
        if args.json:
            print(json.dumps({
                "language": args.lang,
                "mode": args.mode,
                "total_files": 0,
                "files_with_errors": 0,
                "total_errors": 0,
                "results": []
            }, indent=2))
        else:
            print("No files found to analyze.")
        return

    # Process all files
    results = []
    total_errors = 0
    files_with_errors = 0

    for file_path in files:
        result = process_single_file(file_path, parser, have_supertype, args.mode)
        results.append(result)
        
        if "error" in result:
            continue
            
        if result["count"] > 0:
            files_with_errors += 1
            total_errors += result["count"]

    if args.json:
        print(json.dumps({
            "language": args.lang,
            "mode": args.mode,
            "total_files": len(files),
            "files_with_errors": files_with_errors,
            "total_errors": total_errors,
            "results": results
        }, indent=2))
        return

    # Text output
    print(f"Language: {args.lang}  Mode: {args.mode}")
    print(f"Total files: {len(files)}")
    print(f"Files with errors: {files_with_errors}")
    print(f"Total unparseable statements: {total_errors}\n")

    for result in results:
        if "error" in result:
            print(f"ERROR processing {result['file']}: {result['error']}")
            continue
            
        if result["count"] == 0:
            continue

        print(f"File: {result['file']}")
        print(f"Unparseable statements: {result['count']}\n")

        # For text output, we need to re-read the file to show the actual content
        try:
            with open(result['file'], 'rb') as f:
                src_bytes = f.read()
            src_text = src_bytes.decode("utf8", errors="replace")
        except Exception as e:
            print(f"    Could not read file for display: {e}\n")
            continue

        for i, stmt in enumerate(result['unparsed_statements'], 1):
            a_row, b_row = stmt['line_start'] - 1, stmt['line_end'] - 1
            a_col, b_col = 0, 0  # We don't have column info in JSON
            print(f"[{i}] type={stmt['type']} lines={stmt['line_start']}-{stmt['line_end']} bytes={stmt['byte_start']}-{stmt['byte_end']}")
            print()
            for line in render_lines(src_text, a_row, b_row):
                print("    " + line)
            print()

if __name__ == "__main__":
    main()
