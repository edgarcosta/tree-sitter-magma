# Token Definitions

This file contains the token definitions extracted from the Magma parser.

## Operators

### Comparison Operators
- `TOK_EQ` - Equality (`eq`)
- `TOK_NE` - Not equal (`ne`)
- `TOK_GT` - Greater than (`gt`)
- `TOK_GE` - Greater than or equal (`ge`)
- `TOK_LT` - Less than (`lt`)
- `TOK_LE` - Less than or equal (`le`)
- `TOK_CMPEQ` - Compare equal (`cmpeq`)
- `TOK_CMPNE` - Compare not equal (`cmpne`)

### Adjacency/Membership Operators
- `TOK_ADJ` - Adjacent (`adj`)
- `TOK_NOTADJ` - Not adjacent (`notadj`)
- `TOK_IN` - In (`in`)
- `TOK_NOTIN` - Not in (`notin`)
- `TOK_SUBSET` - Subset (`subset`)
- `TOK_NOTSUBSET` - Not subset (`notsubset`)

### Logical Operators
- `TOK_NOT` - Logical not (`not`)
- `TOK_OR` - Logical or (`or`)
- `TOK_AND` - Logical and (`and`)
- `TOK_XOR` - Exclusive or (`xor`)

### Arithmetic Operators
- `TOK_PLUS` - Addition (`+`)
- `TOK_MINUS` - Subtraction (`-`)
- `TOK_STAR` - Multiplication (`*`)
- `TOK_DIV` - Integer division (`div`)
- `TOK_SLASH` - Division (`/`)
- `TOK_MOD` - Modulo (`mod`)
- `TOK_HAT` - Power (`^`)
- `TOK_HAT_HAT` - Double power (`^^`)
- `TOK_UMINUS` - Unary minus (pseudo-token)

### Set, Sequence, and Collection Operators
- `TOK_DIFF` - Set difference (`diff`)
- `TOK_SDIFF` - Symmetric difference (`sdiff`)
- `TOK_HASH` - Cardinality (`#`)
- `TOK_CAT` - Concatenation (`cat`)
- `TOK_MEET` - Meet (`meet`)
- `TOK_JOIN` - Join (`join`)

### Reduction Operators
- `TOK_REDUCT_PLUS` - Reduction plus (`&+`)
- `TOK_REDUCT_MULT` - Reduction multiply (`&*`)
- `TOK_REDUCT_AND` - Reduction and (`&and`)
- `TOK_REDUCT_OR` - Reduction or (`&or`)
- `TOK_REDUCT_MEET` - Reduction meet (`&meet`)
- `TOK_REDUCT_JOIN` - Reduction join (`&join`)
- `TOK_REDUCT_CAT` - Reduction concatenation (`&cat`)

## Delimiters and Special Symbols

### Brackets
- `TOK_LEFTANGLE` / `TOK_RIGHTANGLE` - Angle brackets (`<`, `>`)
- `TOK_LEFTBRACE` / `TOK_RIGHTBRACE` - Braces (`{`, `}`)
- `TOK_LEFTSQUARE` / `TOK_RIGHTSQUARE` - Square brackets (`[`, `]`)
- `TOK_LEFTROUND` / `TOK_RIGHTROUND` - Parentheses (`(`, `)`)

### Paired Delimiters
- `TOK_LEFTBRACE_AT` / `TOK_AT_RIGHTBRACE` - At-braces (`{@`, `@}`)
- `TOK_LEFTBRACE_BANG` / `TOK_BANG_RIGHTBRACE` - Bang-braces (`{!`, `!}`)
- `TOK_LEFTBRACE_STAR` / `TOK_STAR_RIGHTBRACE` - Star-braces (`{*`, `*}`)
- `TOK_LEFTSQUARE_STAR` / `TOK_STAR_RIGHTSQUARE` - Star-squares (`[*`, `*]`)

### Other Special Symbols
- `TOK_UNDERSCORE` - Underscore (`_`)
- `TOK_TILDE` - Tilde (`~`)
- `TOK_ARROW` - Arrow (`->`)
- `TOK_AT` - At symbol (`@`)
- `TOK_ATAT` - Double at symbol (`@@`)
- `TOK_BAR` - Vertical bar (`|`)
- `TOK_BAR_ARROW` - Bar arrow (`|->`)
- `TOK_BECOMES` - Assignment (`:=`)
- `TOK_BANG` - Exclamation (`!`)
- `TOK_BANG_BANG` - Double exclamation (`!!`)
- `TOK_COLON` - Colon (`:`)
- `TOK_COLON_COLON` - Double colon (`::`)
- `TOK_COMMA` - Comma (`,`)
- `TOK_DOLLAR` - Dollar (`$`)
- `TOK_DOLLAR_DOLLAR` - Double dollar (`$$`)
- `TOK_DOT` - Dot (`.`)
- `TOK_DOTDOT` - Double dot (`..`)
- `TOK_DOTDOTDOT` - Triple dot (`...`)
- `TOK_SEMI` - Semicolon (`;`)
- `TOK_EQUALITY` - Equality symbol (`=`)
- `TOK_STAR_STAR` - Double star (`**`)
- `TOK_BACKQUOTE` - Backtick (`` ` ``)
- `TOK_BACKQUOTE_BACKQUOTE` - Double backtick (``` `` ```)
- `TOK_QUESTION` - Question mark (`?`)

## Keywords

### Reserved Words
These words are always treated as keywords.

- `assert`, `assert2`, `assert3`
- `assigned`
- `break`
- `by`
- `case`
- `cat`
- `catch`
- `clear`
- `cmpeq`, `cmpne`
- `continue`
- `declare`
- `default`
- `delete`
- `diff`
- `div`
- `do`
- `elif`, `else`
- `end`
- `eq`, `ne`, `gt`, `ge`, `lt`, `le`
- `error`
- `eval`
- `exists`
- `exit` (alias for `quit`)
- `false`, `true`
- `for`
- `forall`
- `forward`
- `fprintf`
- `freeze`
- `function`
- `if`
- `iload`
- `import`
- `in`, `notin`
- `intrinsic`
- `is`
- `join`
- `load`
- `local`
- `mark_sweep`
- `meet`
- `mod`
- `not`
- `notadj`
- `notsubset`
- `or`, `and`, `xor`
- `print`, `printf`
- `procedure`
- `quit`
- `random`
- `read`, `readi`
- `repeat`
- `require`, `requirege`, `requirerange`
- `restore`
- `return`
- `save`
- `sdiff`
- `select`
- `subset`
- `then`
- `time`
- `to`
- `try`
- `until`
- `vprint`, `vprintf`
- `vtime`
- `when`
- `where`
- `while`

### Semi-reserved Words
These words are treated as keywords only in specific contexts (usually followed by `<...>`), otherwise they can be used as identifiers.

- `AbelianGroup`
- `AdditiveCode`
- `AffineAlgebra`
- `AffinePlane` (`FiniteAffinePlane`)
- `Algebra`
- `AssociativeAlgebra`
- `car`
- `CayleyGroup`
- `Character`
- `CliffordAlgebra`
- `comp`
- `cop`
- `Cycle`
- `Design`
- `Digraph`
- `elt`
- `ext`
- `ExtensionField`
- `FPAlgebra`
- `FPGroup` (`Group`)
- `FPMonoid` (`Monoid`)
- `FPSemigroup` (`Semigroup`)
- `frac`
- `func`
- `Graph`
- `GroupAlgebra`
- `hom`
- `ideal`
- `IncidenceStructure`
- `iso`
- `lideal`
- `LieAlgebra`
- `LinearCode`
- `LinearSpace`
- `loc`
- `map`
- `MatrixAlgebra` (`MatrixRing`)
- `MatrixGroup`
- `MultiDigraph`
- `MultiGraph`
- `ncl`
- `NearLinearSpace`
- `Network`
- `NilpotentGroup`
- `PartialMap` (`pmap`)
- `PermutationGroup`
- `PolycyclicGroup`
- `proc`
- `ProjectivePlane` (`FiniteProjectivePlane`)
- `quo`
- `QuaternionAlgebra`
- `rec`, `recformat`
- `rep`
- `rideal`
- `sub`
- `UnipotentMatrixGroup`
- `ZModule`

## Literals and Identifiers
- `TOK_INTCONST` - Integer constants (e.g., `123`, `0xAF`, `0b101`).
- `TOK_REALCONST` - Real number constants (e.g., `3.14`, `1.2e-5`).
- `TOK_BOOLCONST` - Boolean constants (`true`, `false`).
- `TOK_STRINGCONST` - String constants (e.g., `"hello"`).
- `TOK_IDENTIFIER` - Identifiers (e.g., `my_var`, `'any text'`).
- `TOK_SEQCONST` - Literal sequence constructor (`\\[ ... ]`).
- `TOK_CYCLECONST` - Literal cycle constructor (`\\( ... )`).
- `TOK_UNDEFCONST` - The undefined value.

## Special Tokens
- `TOK_PREV` - Previous result reference (`$1`, `$2`, etc.).
- `TOK_SYM_POLY` - A symbolic polynomial expression (handled specially by the lexer).
- `TOK_MUTATION_OP` - Mutation operators (`+:=`, `*:=`, etc.). 