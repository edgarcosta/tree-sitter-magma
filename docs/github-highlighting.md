# GitHub highlighting: integration notes and evidence

This file collects what we learned about getting tree-sitter-magma used for
syntax highlighting on github.com, and the verification results to attach to
that request. Update the numbers when re-running the commands.

## How GitHub integrates tree-sitter grammars

- GitHub's highlighter uses tree-sitter grammars for about twenty languages
  (C, C#, Go, Java, JavaScript, Python, Ruby, Rust, Swift, Gleam, Nix,
  TLA+, ...). Linguist's `vendor/README.md` marks these with a snail and
  notes they are updated on the highlighting team's own schedule.
- Linguist does **not** accept tree-sitter grammars. Its maintainers say there
  is no public process: "this isn't handled by Linguist ... handled internally
  by another team that controls the syntax highlighting service". They suggest
  a GitHub Community discussion or a support ticket via "Contact GitHub".
  Source: <https://github.com/github-linguist/linguist/discussions/6073>.
- Language detection is Linguist's job, and Magma is not currently registered
  in `languages.yml`. Registration and detection of the shared `.m` extension
  need coordination with GitHub. The sources above do **not** establish a
  TextMate grammar as a prerequisite for direct Tree-sitter adoption.
- A fresh REST code search for `"end intrinsic" extension:m` returned 4888
  indexed results with `incomplete_results: false` on 2026-10-29. The first
  100 results included 13 public repositories. This is evidence of use, not
  proof of a popularity threshold, recent activity, or unique code ownership.
  See the reproducible query and independently maintained projects below.
- GitHub's deployed Tree-sitter runtime, ABI, and capture configuration have
  not been confirmed. Earlier local checks passed at ABI 14 and 15; confirm
  which artifact the highlighting team wants.

### Suggested route

Contact GitHub Support or Community to request direct adoption of
`edgarcosta/tree-sitter-magma`, linking a tested revision and the evidence below.
Ask how the highlighting team wants to coordinate Magma registration and `.m`
detection with Linguist. The staff discussion describes no public community
submission process; it does not guarantee acceptance.

Sources:
<https://github.com/github-linguist/linguist/discussions/6073> and
<https://github.com/github-linguist/linguist/discussions/5572>.

## Deliverable

- Repository: <https://github.com/edgarcosta/tree-sitter-magma>, MIT license.
- Generated sources are committed (`src/parser.c`, `src/grammar.json`,
  `src/node-types.json`) with an external scanner (`src/scanner.c`, real
  literals only). CLI 0.25.10 now reproduces all generated files byte-for-byte,
  including `src/tree_sitter/array.h`. All workflows and the npm development
  dependency pin that generator; CI checks the entire `src/` diff.
- Submit `queries/highlights.scm`. `queries/locals.scm` is deliberately
  capture-free: parameter declarations retain their role, while references
  use syntactic variable/function captures. This avoids source-order binding
  errors without requiring a custom highlighting engine. `folds.scm`,
  `indents.scm`, and `textobjects.scm` are editor extras.
  Highlight predicates used are `#eq?` and `#any-of?` only.
- Node.js, Rust, and Python binding tests parse a generator declaration and
  a real literal, exercising the external scanner. Verified locally with
  Node 26.8.2 / runtime 0.25.1, Rust runtime 0.25.10, and Python 3.12 /
  runtime 0.25.2 on macOS arm64. CI adds Linux/macOS coverage for these
  bindings; the hosted run is pending publication of the changes.
- Node's language type tag now matches the runtime, and macOS C flags no
  longer apply C99 to C++ sources. The Node and Python dependency ranges
  exclude runtimes older than 0.25, which cannot consume this ABI 15 parser.
  The Rust crate declares its missing test dependency.
- Earlier checks built the C/Make and CMake bindings. Swift and Go remain
  outside this validation pass; their release compatibility is not claimed.
- Language reference: the Magma Handbook, chapter "The Magma Language"
  (<https://magma.maths.usyd.edu.au/magma/handbook/>). Grammar notes live in
  `grammar-docs/`.

## Verification results (revision 75b31f4 plus the changes in this branch)

Final toolchain: Tree-sitter CLI 0.25.10, parser ABI 15, macOS arm64.
The Python binding was rebuilt from the same `src/`.

### Parser and highlight tests

```
tree-sitter test
```

- 281 corpus tests across 32 files pass, including 7 malformed-input cases
  in `test/corpus/malformed.txt`.
- 8 highlight fixtures in `test/highlight/` with 320 assertions pass. They
  cover keywords, operators, constructors, directives, definitions, bindings,
  and context-sensitive cases (`rep`, quoted identifiers, fields and
  parameters sharing names), including negative cases. `scopes.m` contains 52 assertions for
  comprehension binders, leading expressions and filters, map and
  inline-procedure parameters, nested functions, shadowing, and `where`
  self-reference. Declarations retain their special color; references use
  their syntactic role regardless of the surrounding bindings. It also runs in Magma V2.30-1.
- Every file in `queries/` compiles against the parser (`tree-sitter query`).

### Real-world corpus

```
python3 scripts/parse_corpus.py --spec "$MAGMA/package/spec"
python3 scripts/parse_corpus.py "$MAGMA/package"
```

Magma V2.30-1 package library (`Magma-V2.30-1.app/Contents/Resources/magma/share/package`):

| Set | Files | Bytes | Files with errors | Wall time | Throughput | Peak RSS |
|---|---|---|---|---|---|---|
| Files loaded through `spec` | 2781 | 118.9 MB | 0 | 5.9 s | 20 MB/s | 610 MB |
| Entire package tree | 3470 | 142.1 MB | 1 | 7.6 s | 19 MB/s | 537 MB |

The single failure is `.../prospector/R/prospect.m`, an R script with `%`
comments that ships in the tree but is not Magma. The slowest file in that parse run was
`Group/GrpFin/SimpleAutGp/authn.m`, parsed in 0.72 s. The largest spec-loaded
file is `Geometry/CrvG3/reconstruction/Interpolations.m` (22.6 MB).
These are parse-only measurements from the earlier pass; see the end-to-end
benchmark below for highlighting cost.

Note: the package sources are proprietary and must not be attached to a
public request. Use `examples/highlighting.m` and `test/highlight/*.m` as
shareable samples.

### End-to-end highlighting benchmark

```bash
python3 scripts/benchmark_highlighting.py --spec "$MAGMA/package/spec"
```

The script times parsing, highlight/locals queries, and HTML rendering to
`/dev/null`. Each file gets a fresh CLI invocation and a 30-second timeout;
parser compilation is warmed up first. Timings include CLI startup. The local
npm-installed CLI 0.25.10 was used on macOS arm64. This measures the CLI,
not GitHub's private highlighting service.

The package sample selects 12 evenly spaced ranks by file size from the 2781
spec-loaded files, including the smallest and largest. It also checks the
shareable example, all eight highlight fixtures, and eight generated stress
inputs. No package source text is written to the report.

The initial run exposed slow operator field queries: a 20,000-term sum took
4.4 seconds and the largest package file exceeded 30 seconds. Matching the
operator tokens directly reduced these to about 0.06 seconds and 1.8 seconds,
respectively, without changing their capture roles.

Final run (2026-10-29): all 29 cases completed within the timeout. The largest
file took 1.79 seconds and peaked at 662 MB RSS. The 20,000-term arithmetic
and boolean expressions took 0.056 and 0.054 seconds. The unterminated block
comment took 1.50 seconds; the other synthetic cases completed under 0.4 seconds.

The final per-file results, hashes of the parser and queries, CLI version,
status, wall time, and peak RSS are in local `build/highlight-benchmark.json`.
The initial results are retained in `build/highlight-benchmark-before.json`.
A timeout reports no peak RSS because the measuring process is terminated.
These local build artifacts are ignored by Git; regenerate them for the
revision submitted to GitHub.

### Highlight coverage

The fixtures check capture roles and nearby operands. A passing suite does
not establish semantic name resolution: these queries deliberately provide
syntax highlighting only.

### Known limitations

- `rep` is a soft keyword: it is `@keyword.operator` only directly before a
  set literal, and an identifier elsewhere.
- Intrinsic parameter lists are inlined in the grammar, so their captures are
  matched positionally rather than through a `parameters` node.
- `declare verbose`, `print ... : Hex` and similar directive tails highlight
  the keyword and the operand, not the directive as a unit.
- No `injections.scm` (Magma embeds no other languages) and no `tags.scm`
  (code navigation is out of scope for this request).
- The queries do not perform semantic name resolution. Parameter declarations
  are `@variable.parameter`; ordinary identifiers are `@variable`, and calls
  are `@function`. Forward bindings and shadowing use the same rules as every
  other expression, so their colors do not depend on capture traversal order.

## Reproducible usage evidence

```bash
gh api --method GET search/code -f q='"end intrinsic" extension:m' \
  -f per_page=100 \
  --jq '{total_count, incomplete_results, repositories: ([.items[].repository | select(.private == false) | .full_name] | unique)}'
```

Observed on 2026-10-29: 4888 results, complete result count, 13 public
repositories among the first 100 hits. Repository metadata separately
confirmed the following projects are public and are not forks:

| Project | Magma use |
|---|---|
| [Hilbert modular forms](https://github.com/edgarcosta/hilbertmodularforms) | Hilbert modular form computations |
| [RiemannSurfaces](https://github.com/christianneurohr/RiemannSurfaces) | High-precision computations on Riemann surfaces |
| [TensorSpace](https://github.com/thetensor-space/TensorSpace) | Multilinear algebra |

The search count includes indexed matches without a recency filter. It does
not establish a count of independent repositories or files added within the
last year. GitHub's highlighting team must confirm what usage evidence it
requires for direct Tree-sitter adoption.

## Before requesting adoption

- [x] Exercise the parser corpus and compile every shipped query.
- [x] Add capture assertions and a shareable visual preview.
- [x] Measure the actual highlighting path, including large and malformed input.
- [x] Document a CLI-first build without requiring npm.
- [x] Use syntactic coloring and test forward bindings and shadowing.
- [x] Align generated headers and verify byte-for-byte reproduction locally.
- [ ] Verify the final selected revision on CI and rerun its benchmark.
- [x] Test Node.js, Rust, and Python runtime compatibility separately from the CLI.
- [x] Collect a reproducible usage search and verify representative public repositories.
- [ ] Send the reviewed request and obtain confirmation of intake, runtime/ABI,
      capture names, performance limits, and Magma/`.m` registration.
- [ ] Attach a fixed revision, license, public examples, and verified measurements.
