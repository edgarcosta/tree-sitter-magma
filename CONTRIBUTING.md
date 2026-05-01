# Contributing to tree-sitter-magma

Thanks for helping. Most PRs here are grammar changes plus corpus tests; this
file collects the conventions that have come out of past reviews so new
contributors don't have to rediscover them.

## Setup

Tree-sitter CLI pin: `^0.25.0` (see `devDependencies` in `package.json`,
alongside the runtime peer dep `tree-sitter: ^0.20.0`). Stick to the pinned
CLI — running `tree-sitter generate` from a different version will produce
a different `src/parser.c` and may not match the committed
`src/tree_sitter/parser.h`. Bump intentionally, in its own commit.

```bash
npm install
npx tree-sitter generate    # regenerate src/parser.c
npx tree-sitter test         # run all corpus tests
npx tree-sitter test -f "name"   # run a single test
npx tree-sitter test -u      # update expected trees from current parser output
```

## Workflow for grammar changes

1. Edit `grammar.js` (or `src/scanner.c` for token-level work).
2. Run `tree-sitter generate`.
3. Run `tree-sitter test` and fix any regressions.
4. Add or update corpus tests for the construct you touched.
5. Verify with `make validate-corpus` (see below).
6. Run `make parse-spec SPEC=/path/to/magma/package/spec` against a real
   Magma installation to confirm no regressions on actually-loaded code.
   Use `make parse-packages PACKAGE_DIR=...` if you also want to sweep
   unloaded files in the tree, but expect a noisier result — official
   Magma releases ship dead/experimental code that doesn't go through the
   parser and contains real syntax errors.

## Writing corpus tests

Test format (`test/corpus/*.txt`):

```
================================================================================
Test name
================================================================================

source code here;

---

(program
  (expression_statement ...))
```

### Keep each test minimal

A corpus test exists to exercise *one* grammar feature. Strip the example
down to the smallest snippet that still triggers the construct you're
testing. A few rules of thumb:

- One test, one feature. If you find yourself writing a 20-line example to
  cover a single new rule, split it into separate tests, each focused on
  the construct in its name.
- Don't paste real package code verbatim. Real Magma is full of incidental
  detail — function calls, attribute lookups, named arguments — that
  bloats the expected tree without testing anything new. Reduce it to the
  shape you actually care about.
- The expected tree should make the feature being tested obvious at a
  glance. If a reviewer has to scroll past 30 lines of setup to find the
  construct named in the test header, the test is too big.

### Tests must be runnable in the Magma REPL

A passing tree-sitter test only means the snippet *parses*. It doesn't mean
it's valid Magma. The `make validate-corpus` target extracts each snippet
into a standalone `.m` file and feeds it to `magma -b`, flagging any parser
errors. **Run it before you push** — and ideally also paste the snippet
into a fresh `magma` session and confirm there are no runtime errors
either.

Practical implications:

- Don't use undeclared identifiers (`a + b * c - d` with no preceding
  declarations is wrong). Either declare them (`a := 1; b := 2; ...`) or
  use literals (`1 + 2 * 3 - 4`).
- Prefer self-contained, single-statement examples. If a construct needs a
  group, ring, or map, build it inline (`Rationals()`, `Integers()`,
  `SymmetricGroup(3)`, `Coercion(Integers(), Rationals())`) instead of
  introducing a prelude variable that pads the expected tree without
  testing anything new.
- When a prelude is unavoidable, keep it as short as possible and prefer
  Magma builtins that produce the right type with one call.
- `@@`, coercion, ideal/quotient constructors, `hom<...>`, etc. each have
  semantic preconditions. Verify in a fresh REPL session — runtime errors
  like *"Bad modifier category name"* or *"There is no rule for calculating
  the preimage"* mean your example is wrong even if it parses.

`validate-corpus` is a coarse safety net, not a full runtime check:

- The Makefile invokes `extract_corpus_code.py … --skip invalid types`, so
  only `test/corpus/invalid.txt` (intentionally bad syntax) and
  `test/corpus/types.txt` (`declare type` is package-only and is rejected
  before reaching the parser) are excluded from extraction. Keep the
  skip list short and document the reason in the Makefile when you add to
  it.
- Every other corpus snippet is fed to `magma -b`, but the failure filter
  only flags `bad syntax` errors. Runtime errors — *"Illegal declaration"*
  for intrinsic definitions, *"Could not open file"* for `load`/`save`/
  `restore`, *"has not been declared"* for stray identifiers — are
  silently tolerated. That's by design (so package-only constructs and
  filesystem directives don't constantly red-flag the target), but it
  means a green `validate-corpus` doesn't guarantee your snippet runs.
  Paste it into a fresh REPL yourself before pushing.

### Reducing a real-world parse failure to a test

When `make parse-spec` flags an `ERROR` in real Magma source, the fix
workflow is:

1. Open the offending file, find the smallest expression around the ERROR
   that still fails to parse.
2. Strip every identifier and call that isn't load-bearing for the parse;
   replace with constants where possible.
3. Confirm the reduced snippet still triggers the same error.
4. Add it to `test/corpus/invalid.txt` if the parser should reject it, or
   to a positive-test file with the appropriate expected tree if the
   grammar should accept it.
5. Then fix `grammar.js` and verify the test goes from failing to passing.

### Negative tests

Put grammar tests for intentionally invalid syntax in `test/corpus/invalid.txt`.
Magma rejection at runtime ≠ tree-sitter rejection — only put a test in
`invalid.txt` if the *parser* should produce an `ERROR` or `MISSING` node.

## Grammar conventions

### Definitions vs compound statements

`function_definition`, `procedure_definition`, and `intrinsic_definition` all
live in the `_definition` supertype (under `primary_expression`). At top
level they parse as `(expression_statement (function_definition …))`. New
definition-like constructs go there, not into `_compound_statement`.

`_compound_statement` is for control-flow constructs (`if`, `for`, `while`,
`repeat`, `try`, `case`).

### Required terminators

Every statement needs a trailing `;` (handled by `_statement: seq(…, ';')`).
Don't add `optional(';')` inside compound statements as glue for stray
semicolons — use the empty-statement model instead: `block` and `program`
accept bare `;` between real statements, so `if x then ; body; end if;` and
`1;;;` parse without per-rule special cases.

### Field labels

Use `field('name', …)` to expose semantic structure that downstream tooling
(highlighters, formatters, locals queries) needs. For paired constructs like
record-field assignments, expose the pair as a named node with `name:` /
`value:` fields, not as flat children of the parent. See `simple_assignment`
and `field_definition` for examples.

### Soft keywords

Magma has identifiers like `rep` that are reserved only in specific
syntactic positions. Use the `repIdentifier` / `identifierOrRep` helpers at
the bottom of `grammar.js` — `alias('rep', $.identifier)` placed at every
position where the keyword could appear as an ordinary name. Tree-sitter's
keyword-extraction (`word: $ => $.identifier`) handles the rest.

### Word operators

Word operators (`div`, `mod`, `in`, `eq`, `subset`, `cat`, etc.) are bare
identifiers in `binary_operator`'s precedence table; spaces are handled by
the `extras` rule. Don't bake whitespace into the operator literal.

## Style

- **Read and exercise every regex or rule before shipping it.** Tree-sitter
  doesn't always loudly reject a wrong rule — the parser still produces
  *some* tree for any input — so a plausible-looking rule can be quietly
  wrong on edge cases. Paste tricky inputs into a Magma REPL and confirm
  the parse tree matches what Magma itself does. The `string` rule still
  has scars from fragments merged on faith.
- **Track upstream Magma.** When a Magma release tightens or relaxes syntax
  (e.g., the upcoming requirement for `;` after `end intrinsic`), update
  the grammar to match the new behavior; don't keep accepting the
  no-longer-valid form for "compatibility".
- **Comments only when WHY is non-obvious.** No need to narrate WHAT a rule
  does — the rule itself is the documentation. A comment earns its keep
  when it captures a hidden constraint, a prior bug, or a design decision
  the code can't express.
- **Conventional commits.** Use `<type>(<scope>): <description>`, e.g.
  `fix(grammar): remove ~ from binary_operator`,
  `test: add positive binary tests for word operators`,
  `refactor(grammar): expose simple_assignment with name/value fields`.

## PR checklist

- [ ] `npx tree-sitter generate` produces no errors.
- [ ] `npx tree-sitter test` is green.
- [ ] `make validate-corpus` is green (or explicitly notes which tests are
      skip-listed and why).
- [ ] New grammar features are covered by both a positive corpus test and,
      where applicable, a negative test in `invalid.txt`.
- [ ] No `optional(';')` band-aids inside compound statements.
- [ ] No commented-out code or stale `// TODO`s in the diff.
