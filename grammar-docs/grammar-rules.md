# Magma Grammar Rules

This file provides a more detailed overview of Magma's grammar rules, focusing on constructors, quantifiers, and special statements.

## Program Structure
A Magma program is a sequence of statements, declarations, or directives.
```yacc
program:
    /* empty */
|   statement
|   directive
|   intrinsic
|   declaration
;
```

## Directives
Directives control the Magma environment.
- `load "filename";`
- `iload "filename";`
- `save "filename";`
- `restore "filename";`
- `freeze;`
- `clear;`

## Statements

### Assignment
```yacc
lval_list TOK_BECOMES expr_list TOK_SEMI
```
- **lval**: Can be an identifier, an indexed element (`X[i]`), a record field (`R`f`), or `_` (the "bit bucket").
- **Multiple assignment**: `a, b := f(x);` is supported.

### Control Flow
- **`if` statement**: `if bool_expr then ... elif bool_expr then ... else ... end if;`
- **`while` loop**: `while bool_expr do ... end while;`
- **`repeat` loop**: `repeat ... until bool_expr;`
- **`for` loop**: `for var := start to finish by step do ... end for;`
- **`for-each` loop**: `for var in sequence do ... end for;`
- **`for-random` loop**: `for random var in sequence do ... end for;`
- **`case` statement**: `case expr: when val1: ... when val2, val3: ... else: ... end case;`

### Loop Control
- `break;`: Exits the current loop. Can optionally be followed by a label.
- `continue;`: Proceeds to the next iteration of the current loop. Can optionally be followed by a label.

### Procedure and Function Calls
Procedure calls are statements. Function calls are expressions.
```yacc
// Procedure call
expr(expr_list) TOK_SEMI

// Function call (as part of an expression)
expr(expr_list)
```
- Parameters passed by reference are prefixed with `~`.

### I/O and System
- `print expr_list;`
- `printf format, expr_list;`
- `fprintf file, format, expr_list;`
- `load "filename";`
- `save "filename";`
- `restore "filename";`
- `clear;`
- `quit;` or `quit code;`: Exits Magma, optionally with an integer exit code.

### Timing Statements
- `time <statement>`: Measures and prints the execution time of a statement.
- `vtime <flag>, <level> : <statement>`: Verbose timing, conditional on a verbose flag.

## Constructors

### Set and Sequence Constructors
These constructors create sets and sequences, including comprehensions.

**Set Constructors** (`{ ... }`)
- `{ 1, 2, 3 }` (finite set)
- `{ 1..100 by 2 }` (arithmetic progression)
- `{ x^2 : x in S | IsPrime(x) }` (comprehension)

**Sequence Constructors** (`[ ... ]`)
- `[ 1, 2, 3 ]` (finite sequence)
- `[ 1..100 by 2 ]` (arithmetic progression)
- `[ x^2 : x in S | IsPrime(x) ]` (comprehension)

**Indexed Sets** (`{@ ... @}`) and **Multisets** (`{* ... *}`) follow similar syntax.

### Tuple Constructor (`< ... >`)
- `< 1, "hello", true >`

### Special Sequence Constructors
- `[* ... *]`: Starred sequence constructor.

### Map and Homomorphism Constructors
- `map< D -> C | x :-> f(x) >`
- `hom< G -> H | g :-> h >`

### Record Constructor (`rec< ... >`)
- `recformat< name: Type, age: Type >`
- `rec< MyFormat | name := "John", age := 30 >`

### Algebraic Structure Constructors
Magma has a rich syntax for creating algebraic structures.
- **Groups**: `PermutationGroup< ... >`, `MatrixGroup< ... >`, `FPGroup< ... >`, `AbelianGroup< ... >`
- **Rings and Fields**: `PolynomialRing(R, n)`, `quo< R | I >`, `ext< F | f >`
- **Special Ring Constructors**: `frac<R|I>`, `loc<R|I>`, `comp<R|I>`
- **Algebras**: `MatrixAlgebra(F, n)`, `GroupAlgebra(G, F)`, `LieAlgebra(...)`

## Quantifiers
Quantifiers are expressions that return a boolean value or a witness.

- `exists{ var in S | condition }`
  - Returns `true` and a witness `var` if one exists, otherwise `false`.
- `forall{ var in S | condition }`
  - Returns `true` if the condition holds for all elements, otherwise `false` and a counterexample.
- `rep{ S }`
  - Returns a representative element from the set `S`.
- `random(S)`
  - Returns a random element from the set `S`.

## Special Expressions

### `where` Clause
A `where` clause allows for local definitions within an expression. It supports multiple assignments and can use `is` or `:=`.
```magma
f(x) where f is func< y | y^2 >
(a+b)^2 where a := 1, b := 2
```
This is equivalent to `(func<y|y^2>)(x)`.

### `eval` Expression
- `eval "1+2"`: Evaluates the string as a Magma expression.

### Context Variables
- `$`: The "default" object in the current context. Useful in constructors like `quo< R | $1^2-2 >`.
- `$$`: The enclosing context (e.g., the parent structure).
- `$1, $2, ...`: The previous results in the interactive session.

### Ternary Conditional
- `condition select expr1 else expr2`

### Case Expression
A `case` expression provides a way to select a value based on matching patterns, similar to a `case` statement but usable within an expression.
```magma
result := case< my_var | 1: "one", 2: "two", default: "other" >;
```

### Back-quote for Record Field Access
- `R`f`: Access field `f` of record `R`.
- `R``"f"`: Access field whose name is given by a string.

### Error Handling
- `try ... catch e ... end try;`
- `error "message";`: Throws a runtime error.
- `error if condition, "message";`: Throws a runtime error conditionally.
- `assert condition;`: Halts execution if the condition is false.
- `require condition;`: Used in intrinsics to check preconditions.

## Intrinsics and Declarations
Magma allows users to define new types and functions with performance comparable to built-in ones.

### `intrinsic`
```magma
intrinsic MyIntrinsic(x::Type1, ~y::Type2) -> RetType
{This is a documentation comment.}
    // implementation
end intrinsic;
```

### `declare`
- `declare type T;`: Declares a new object type.
- `declare attributes T: attr1, attr2;`: Adds attributes to a type.
- `declare verbose MyVerbose, 3;`: Declares a verbose flag with a maximum level.

### `forward`
- `forward MyFunc, MyProc;`: Forward-declares functions and procedures. 