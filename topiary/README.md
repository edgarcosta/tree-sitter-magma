# Topiary formatter for Magma

The formatter preserves deliberate line breaks and normalizes spacing and
indentation. It uses four spaces per level, configured in `languages.ncl`.

## Running the formatter

Install Tree-sitter CLI 0.25.10, Topiary 0.7.3, Python 3.10 or later, and a C
compiler. Run these commands from the repository root:

```bash
npm ci
cargo install topiary-cli --version 0.7.3 --locked
./topiary/build.sh build
./topiary/build.sh format path/to/file.m > /tmp/formatted.m
./topiary/build.sh test
```

`format` writes to standard output. The wrapper rebuilds the shared grammar
when its source changes. Set `TREE_SITTER` to select a different CLI binary;
otherwise the wrapper prefers the repository's installed CLI over `PATH`.

## Formatting rules

- Existing breaks at commas, expression operators, comprehension separators,
  and collection/call delimiters survive formatting. Grouped rows stay grouped.
- Delimited contents receive one indentation level. A closing delimiter on
  its own line aligns with the enclosing code.
- Arithmetic and boolean continuations in assignments, returns, and conditions
  receive a hanging indent. Operator chains do not accumulate indentation.
- An assigned or returned call/collection that starts on the following line
  receives an outer indent as well as indentation for its contents.
- Body indentation starts at the opening syntax and ends at the closing
  keyword. It includes leading, trailing, and comment-only bodies.
- Trailing comments stay beside their statements. Inline block comments stay
  inline; multiline comments move with the surrounding indentation.
- Optional parameter separators and inverse application use spaces:
  `F(W : Context := false)` and `x @@ f`. Multiplication, powers, coercion,
  and forward application remain tight: `a*b`, `x^2`, `R!x`, and `x@f`.
- Existing blank lines between statements are retained, with at most one
  empty line. Function and control-flow bodies expand onto separate lines.

For example:

```magma
function Compute(W : Context := false)
    // Explain the computation.
    values := [1, 2,
        3, 4];
    result := Transform(W,
        Context);
    return result @@ W;
end function;
```

## Limits

Topiary 0.7.3 has no column budget. It preserves breaks at the boundaries
covered by these queries but does not wrap an existing long single line to
120 columns. Strings and intrinsic documentation remain unchanged internally.
Preserving compact one-line blocks is not currently supported.

Continuation indentation for attribute declarations and imports is not yet
handled, and the first item may join the line containing the colon. Trailing
comments are not aligned into columns. Inputs must be UTF-8; large generated
tables can be slow to format or overflow Topiary's stack.

## Validation

`build.sh test` checks every input against its expected output byte for byte,
including the final newline. Missing fixture partners are failures. Topiary's
idempotence check remains enabled.

The suite also compares the complete parse hierarchy, field names, anonymous
tokens, and named terminal contents before and after formatting. Only leading
whitespace within comment lines is excluded from the content comparison.
Separate checks exercise this validator against changed identifiers, literals,
operators, nesting, and the random-loop token-joining regression.

CI runs this suite with the versions listed above. Package-corpus analysis is
a separate validation step; passing the fixture suite does not establish
coverage of all Magma code in use.
