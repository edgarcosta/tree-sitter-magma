# Topiary formatter for Magma

This directory contains the Topiary formatting queries
(`magma.scm`), a build/test wrapper (`build.sh`), and a fixture
suite (`test/`).

## Running the formatter

```bash
./build.sh build           # compile the grammar shared library
./build.sh format <file>   # format a Magma source file
./build.sh test            # run the fixture suite
```

The build assumes a `topiary` binary is on `PATH`. For local dev
without a system install, drop a binary at
`tools/topiary-cli-<triple>/topiary` and prepend it:

```bash
PATH="$PWD/tools/topiary-cli-x86_64-unknown-linux-gnu:$PATH" ./build.sh test
```

## Known limitations

### No automatic line-length wrapping

Topiary's softline model is *input-driven*: a softline expands to
a line break iff the parent CST node is multi-line in the source.
There is no concept of column budget or maximum line width.

Concretely:

- If you write a 200-character single-line function call, topiary
  will not wrap it. The line stays at 200 characters.
- If you wrap the call yourself across multiple lines, topiary
  will preserve and clean up your line breaks (consistent comma
  alignment, etc.).

This is a deliberate trade-off: the user decides where to break,
and topiary makes the result clean. Width-driven wrapping (à la
`gofmt`, `prettier`, `black`) would require a Wadler-style
pretty-printer back-end in topiary itself; see upstream issue
discussion at <https://github.com/tweag/topiary/issues>.

### Continuation-line indent for wrapped argument lists

When a function call or function-definition parameter list is
broken across multiple lines, topiary preserves the user's line
breaks but does *not* automatically indent the continuation lines.
Each continuation line stays at column 0 (or wherever the user
placed it). For example:

```magma
result := DoStuff(arg1,
arg2,
arg3);
```

Adding a conditional `@append_indent_start` (gated on
`#multi_line_only!`) breaks idempotence: a multi-line input
acquires a new indent level on the first pass, but the output is
still multi-line, so the predicate fires again on the next pass
and the indent compounds. A robust fix needs the same
width-aware pretty-printer back-end mentioned above.

### One-line if/for/while preservation

The current rules force `if`/`for`/`while` bodies onto multiple
lines, even for trivial constructs that `style.md` permits as
one-liners (`if cond then x; end if;`). Fixing this needs the
same input-softline machinery and is left for a follow-up.
