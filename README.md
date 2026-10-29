# tree-sitter-magma

A tree-sitter parser for the Magma computational algebra language.

## Playground

Try the grammar and the Topiary formatter in your browser:
<https://edgarcosta.github.io/tree-sitter-magma/>

## Build and test with the CLI

Install the [Tree-sitter CLI](https://github.com/tree-sitter/tree-sitter/releases)
(version 0.25.10 is used for this repository's checks) and a C compiler.
For example, with Rust's Cargo:

```bash
cargo install tree-sitter-cli --version 0.25.10 --locked
```

From this checkout:

```bash
tree-sitter generate          # generate src/ from grammar.js
tree-sitter build             # compile the native parser
tree-sitter test              # parser corpus, highlight and tag assertions
tree-sitter parse examples/highlighting.m
```

`tree-sitter parse` and `tree-sitter test` also compile the parser when needed.
The grammar's JavaScript file needs a JavaScript runtime for generation; Node.js
is the CLI's default. npm is not required for this workflow.

Alternatively, npm can install the CLI (`npm install -g tree-sitter-cli@0.25.10`).
If you already ran `npm ci` in this checkout, use `npx tree-sitter` in place of
`tree-sitter` to select the locally installed CLI.

## Language bindings

Bindings for C, Go, Node.js, Python, Rust, and Swift live in `bindings/`.
Their build tools and Tree-sitter runtime dependencies are separate from the
CLI workflow above. For the tested Node.js, Rust, and Python bindings:

```bash
npm ci && npm test                         # Node.js binding and runtime
cargo test                                # Rust binding and documentation
python3 -m pip install '.[core]'           # Python binding and runtime
python3 -m unittest discover bindings/python/tests
```

The generated parser uses ABI 15. Node.js and Python runtime requirements
start at Tree-sitter 0.25; the Rust tests use 0.25.10. `npm ci` installs the
Node.js runtime for development, while it remains an optional peer dependency
for package consumers. These binding tests are separate from `tree-sitter test`.

## Reviewing highlighting

Generate a local comparison of the committed and working highlight queries:

```bash
python3 scripts/highlight_preview.py
```

Open `build/highlighting.html` in a browser. The default example is
`examples/highlighting.m`. To inspect your own files or the intrinsic fixtures:

```bash
python3 scripts/highlight_preview.py /path/to/example.m test/highlight/definitions.m
```

The preview compares `highlights.scm` and the locals configuration against `HEAD`,
using the working parser for both sides. Use `--baseline REV` to select another
commit, or `--output /path/to/preview.html` to change the destination.
It parses the examples without executing them.

The script uses the installed npm Tree-sitter CLI, falling back to `tree-sitter`
on `PATH`. Preview colors distinguish the capture roles; editor themes may
render them differently.

Capture names follow the upstream tree-sitter convention (`@constant.builtin`
for booleans, `@property` for record fields). The consuming highlighter selects
the colors. Parameter declarations are distinct; ordinary references use
`@variable`, and calls use `@function`. `queries/locals.scm` intentionally has
no captures: source-order propagation cannot reliably handle Magma's forward
bindings in comprehensions and `where` clauses. The same syntactic coloring
works when a consumer loads only `highlights.scm`.

GitHub's supported capture configuration still needs confirmation from its
highlighting team.

Run parser and highlight regression tests with:

```bash
tree-sitter test
```

To benchmark parsing, highlight/locals queries, and HTML rendering (Python 3,
the CLI, and macOS or Linux; no Python binding needed):

```bash
python3 scripts/benchmark_highlighting.py
python3 scripts/benchmark_highlighting.py --spec "$MAGMA_ROOT/package/spec"
```

The optional spec adds a sample spread across file sizes, including the largest.
The script also exercises malformed and stress inputs, enforces a 30-second
limit per file, and writes timings and peak memory to
`build/highlight-benchmark.json`. Use `--cli /path/to/tree-sitter` to select a
CLI explicitly. Package sources are not copied into the report.

For a parse-only sweep of every real Magma file, install the Python
`tree-sitter` runtime and build this grammar's Python binding first:

```bash
python3 -m pip install "tree-sitter>=0.25,<0.26" setuptools
python3 setup.py build_ext --inplace
python3 scripts/parse_corpus.py --spec "$MAGMA_ROOT/package/spec"
```

Results and GitHub integration notes are in [docs/github-highlighting.md](docs/github-highlighting.md).

## Reviewing code navigation

`queries/tags.scm` extracts routine definitions and named calls, declared types,
and attribute and record field definitions. Intrinsic tags include their
documentation. The Rust binding exposes the query as `TAGS_QUERY`.

Inspect the extracted symbols without executing the Magma source:

```bash
tree-sitter tags test/tags/navigation.m
tree-sitter tags examples/highlighting.m
tree-sitter test
cargo test
```

This first draft recognizes named routines and single-target assignments of
anonymous functions, procedures, and `func`/`proc` expressions.
It omits forward declarations, imports, aliases, multiple assignments, and
dynamically selected callees such as `handlers[1](x)`. Parenthesized definitions
and callees are not yet covered. Record formats contribute field definitions;
their assigned names are not classified as types.
Calls through attributes use the final field name. These are syntactic tags:
they do not resolve overloads or associate fields with a particular record type.

## Contributing

This parser is generated from the existing yacc grammar for Magma. Contributions are welcome!

## License

MIT
