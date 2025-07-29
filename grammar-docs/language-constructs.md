# Magma Language Constructs

This file documents the high-level language features and constructs found in Magma.

## Overview

Magma is a computational algebra system with a rich type system designed for mathematical computation. The language supports both procedural and functional programming paradigms with emphasis on mathematical structures and operations.

## Core Language Features

### Variables and Assignment
- Standard assignment with `:=` operator.
- Multiple assignment: `a, b, c := 1, 2, 3;`
- Mutation operators: `+:=`, `*:=`, etc.
- Underscore `_` for anonymous/ignored values in assignments.

### Data Types

#### Primitive Types
- **Integers** - Arbitrary precision integers, with `0x` and `0b` prefixes for hexadecimal and binary.
- **Rationals** - Fractions of integers.
- **Reals** - Floating-point numbers with optional precision (e.g., `1.23p50`).
- **Booleans** - `true` and `false`.
- **Strings** - Text literals in double quotes (`"..."`). Single-quoted text (`'...'`) is a literal identifier.

#### Collection Types
- **Sequences** - Ordered collections `[1, 2, 3]`.
- **Sets** - Unordered collections of distinct elements `{1, 2, 3}`.
- **Indexed Sets** - Sets that maintain insertion order `{@1, 2, 3@}`.
- **Multisets** - Sets that allow duplicate elements `{*1, 2, 2, 3*}`.
- **Tuples** - Fixed-size, ordered, heterogeneous collections `<1, "hello", true>`.
- **Lists** - A special sequence type with different performance characteristics `[* 1, 2, 3 *]`.

### Comments
- **Line comments**: `// ...` to the end of the line.
- **Block comments**: `/* ... */`, can span multiple lines.
- **Signature comments**: `{...}` inside intrinsic definitions for documentation.

Magma supports three types of comments:

- **Single-line comments**: Start with `//`. All text from `//` to the end of the line is ignored.
- **Block comments**: Start with `/*` and end with `*/`. They can span multiple lines and cannot be nested.
- **Signature comments**: Used specifically for documenting `intrinsic` functions. They are enclosed in braces `{ ... }` immediately following the intrinsic's signature. This comment is stored with the intrinsic and can be accessed programmatically.

### Forward Declarations
Function and procedure declarations can be forwarded using the `forward` keyword, allowing you to declare them before they are fully defined.

```magma
forward MyFunction, MyProcedure;
```

### Line Continuation
- A backslash `\\` at the end of a line continues the statement on the next line.

### Functions and Procedures

#### Definitions
Functions are defined with the `function` keyword and must return a value. Procedures are defined with `procedure` and may modify their arguments. Shorter forms `func` and `proc` are also available.

```magma
// Function
function MyFunction(x, y)
    return x + y;
end function;

// Procedure
procedure MyProcedure(~arr, index, value)
    arr[index] := value;
end procedure;
```

#### Lambda Expressions
- Anonymous functions: `func<x, y | x^2 + y^2>`
- Anonymous procedures: `proc<x | print x>`

#### Parameter Passing
- **By value** (`param`): The default, a copy is passed.
- **By reference** (`~param`): The original variable can be modified.
- **Variable arguments**: `...` can be used in definitions to accept a variable number of arguments.

### Control Flow

#### Conditional Statements
```magma
if condition then
    ...
elif other_condition then
    ...
else
    ...
end if;
```
A ternary conditional expression is also available: `condition select value_if_true else value_if_false`.

#### Loops
```magma
// For loop
for i := 1 to 10 by 2 do
    ...
end for;

// For-each loop
for item in my_sequence do
    ...
end for;

// For-random loop
for random i := 1 to 10 do
    ...
end for;

// While loop
while condition do
    ...
end while;

// Repeat-until loop
repeat
    ...
until condition;
```

#### Loop Control
- `break`: Exits the innermost loop. Can optionally take a loop label.
- `continue`: Skips to the next iteration of the innermost loop. Can optionally take a loop label.

#### Exception Handling
```magma
try
    ...
catch e
    // e contains the error object
    ...
end try;
```
The `error` statement can also be made conditional:
```magma
error if condition, "message";
```

### Context and Previous Results
- `$` - Represents the default or current object in a given context (e.g., the universe in a constructor).
- `$$` - Refers to the enclosing context.
- `$1`, `$2`, etc. - Access previous results from the history.

### Mathematical Structures

Magma provides extensive support for mathematical structures:

#### Groups
- `FP_GROUP<generators | relations>` - Finitely presented groups
- `PERMUTATION_GROUP<generators>` - Permutation groups
- `MATRIX_GROUP<field, generators>` - Matrix groups
- `ABELIAN_GROUP<relations>` - Abelian groups
- `POLYCYCLIC_GROUP<relations>` - Polycyclic groups

#### Rings and Fields  
- `EXTENSION_FIELD<base, polynomial>` - Field extensions
- Integer rings, polynomial rings, etc.
- Ideals: `IDEAL<ring, generators>`
- Special ring constructors: `frac<...>`, `loc<...>`, `comp<...>` for rings of fractions, localizations, and completions. Note that `frac<>` may be deprecated as the parser contains a hardcoded error for it.

#### Algebras
- `ALGEBRA<field, generators>` - General algebras
- `LIE_ALGEBRA<field, generators>` - Lie algebras
- `QUATERNION_ALGEBRA<field, parameters>` - Quaternion algebras
- `CLIFFORD_ALGEBRA<field, form>` - Clifford algebras

#### Codes
- `LINEAR_CODE<field, generators>` - Linear error-correcting codes
- `ADDITIVE_CODE<ring, generators>` - Additive codes

#### Geometric Objects
- `GRAPH<vertices, edges>` - Graphs
- `DIGRAPH<vertices, edges>` - Directed graphs
- `PROJECTIVE_PLANE<parameters>` - Projective planes
- `AFFINE_PLANE<parameters>` - Affine planes

### Set and Sequence Operations

#### Set Construction
- Explicit: `{1, 2, 3}`
- Range: `{1..10}`  
- Comprehension: `{x : x in S | condition}`

#### Sequence Construction
- Explicit: `[1, 2, 3]`
- Range: `[1..10]`
- Comprehension: `[f(x) : x in S | condition]`

#### Operations
- Union, intersection, difference: `meet`, `join`, `diff`
- Membership: `in`, `notin`
- Subset: `subset`, `notsubset`
- Cardinality: `#S`

### Map Construction

#### Map Types
- `map<domain -> codomain | mappings>`
- `partial_map<domain -> codomain | mappings>`  
- `hom<domain -> codomain | mappings>` - Homomorphisms
- `iso<domain -> codomain | mappings>` - Isomorphisms

#### Map Rules
- Direct mappings: `x |-> f(x)`
- Conditional mappings with conditions

### Quantifiers and Constructors

#### Existential and Universal Quantifiers
- `exists(result) {condition : variables in sets | predicate}`
- `forall(result) {condition : variables in sets | predicate}`

#### Special Constructors
- `random {expression : variables in sets | condition}` - Random selection
- `rep {expression : variables in sets | condition}` - Representative selection

### Records

#### Record Construction
```
rec<format | field1 := value1, field2 := value2, ...>
```

#### Record Format Definition
```
recformat<field1, field2 : type, ...>
```

#### Field Access
- Static: `record`field`
- Dynamic: `record``expression``

### Intrinsic Functions

Magma allows definition of built-in functions:

```
intrinsic FunctionName(param1 :: Type1, param2 :: Type2, ...) -> ReturnType
{
    Documentation string
}
    local variables;
    // implementation
end intrinsic;
```

#### Type Specifications
- Basic types: integers, rationals, etc.
- Collection types: `[Type]`, `{Type}`, `{@Type@}`, `{*Type*}`
- Any type: `.`
- Tuple types: `<>`

### Operators

#### Arithmetic
- Basic: `+`, `-`, `*`, `/`, `div`, `mod`
- Power: `^`, `^^` (double power)
- Unary: `+expr`, `-expr`

#### Logical
- Boolean: `and`, `or`, `xor`, `not`
- Reduction: `&+`, `&*`, `&and`, `&or`, `&meet`, `&join`, `&cat`

#### Comparison  
- Equality: `eq`, `ne`, `cmpeq`, `cmpne`
- Ordering: `lt`, `le`, `gt`, `ge`
- Set relations: `subset`, `notsubset`

#### Special
- Coercion: `!` (convert between types)
- Function composition: `@`
- Concatenation: `cat`
- Assignment test: `assigned`

### I/O and System Operations

#### Output
- `print` - Basic printing
- `printf` - Formatted printing  
- `fprintf` - File output
- `vprint`, `vprintf` - Verbose printing

#### Input
- `read` - Read input
- `readi` - Read integer

#### File Operations
- `load`, `save`, `restore` - Workspace operations
- `iload` - An alternative to `load`.
- `freeze` - Freeze the current workspace state.
- `import`, `export` - Package operations
- The `import` statement has a variant to load all symbols from a package: `import @"filename";`

### System Commands
- `quit`: Exits the Magma session. Can optionally take an exit code (e.g., `quit 1;`).

### Debugging and Verification

#### Assertions
- `assert condition;` - Basic assertion.
- `assert2 condition;` - Level 2 assertion.
- `assert3 condition;` - Level 3 assertion.

#### Requirements (for intrinsics)
- `require condition : message` - General requirement
- `requirerange variable, min, max` - Range requirement
- `requirege variable, minimum` - Minimum requirement

#### Timing
- `time statement` - Time execution
- `vtime name, level : statement` - Verbose timing

### Special Features

#### Pattern Matching

- Case statements: `case expr: when pattern1: ... end case;`
- Case expressions: `case<expr | pattern1 : result1, pattern2 : result2, ...>`
- Default cases supported

#### Where Clauses
- Local bindings: `expression where variable is value`
- Multiple bindings and `:=` are supported: `expression where x is 1, y := 2`

#### Evaluation
- `eval expression` - Dynamic evaluation

### Memory Management

#### Garbage Collection
- `mark_sweep` - Force garbage collection
- Automatic memory management for most objects

#### Object Lifecycle
- `delete object` - Explicit deletion
- Reference counting for some objects

## Literals

### Integer Literals
Integer literals can be specified in decimal, hexadecimal, or binary format.
- **Decimal**: A sequence of digits `0-9`. Example: `12345`
- **Hexadecimal**: `0x` followed by a sequence of hex digits `0-9`, `a-f`, `A-F`. Example: `0xFF`
- **Binary**: `0b` followed by a sequence of binary digits `0` or `1`. Example: `0b1011`

### Real Literals
Real literals follow standard floating-point notation.
- **Decimal notation**: `123.45`
- **Scientific notation**: `1.23e-4`
- **Precision specifier**: A real literal can have its precision specified with `p`. Example: `0.123456789p30` creates a real number with 30 decimal digits of precision.

### String Literals
- **Double quotes**: `"..."`. Can contain newlines and escaped characters (e.g., `\n`, `\t`, `\"`).
- **Single quotes**: `'...'`. Interpreted as a literal identifier. Cannot contain newlines.

### Sequence and Cycle Literals
- **Literal Sequence**: `\\[ 1, 2, 3 ]`. A sequence of integers.
- **Literal Cycle**: `\\(1 2 3)(4 5)`. Permutation cycles.

## Whitespace and Line Continuations

- **Whitespace**: Spaces, tabs, and newlines are generally ignored between tokens.
- **Line Continuation**: A backslash `\\` at the end of a line indicates that the statement continues on the next line. Whitespace between the backslash and the newline is skipped.