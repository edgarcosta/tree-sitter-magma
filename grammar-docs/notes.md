# Implementation Notes

This file contains observations and notes about the Magma parser implementation and considerations for tree-sitter development.

## Parser Characteristics

### Shift/Reduce Conflicts
The original parser has **1 expected shift/reduce conflict** related to the ambiguity between:
- Commutator syntax: `(a, b, c)`  
- Function call syntax: `func(a, b, c)`

This is noted in the parser header: "Expect 1 shift/reduce conflict. [commutator/function call]"

### Grammar Complexity
- The grammar is quite large with **240+ production rules**
- Heavy use of **left-recursive rules** for lists (common in yacc/bison)
- Multiple **precedence levels** (32 levels) for expression parsing
- Extensive use of **semantic actions** in C code (which we'll ignore for tree-sitter)

## Notable Grammar Features

### Multi-Character Operators
Magma has many multi-character operators that need special lexical handling:
- `:=` (assignment)
- `::` (type annotation) 
- `..` (range)
- `...` (variadic)
- `->` (arrow/map)
- `|->` (map rule)
- `^^` (double power)
- `!!` (double bang)
- `@@` (double at)
- `&+`, `&*`, `&and`, etc. (reduction operators)

### Special Bracket Combinations
- `{@` and `@}` for indexed sets
- `{*` and `*}` for multisets  
- `{!` and `!}` for function sets
- `[*` and `*]` for starred sequences

### Context-Sensitive Elements
Some parsing decisions depend on context:
- **Mutation operators** like `+=`, `*=` are lexed as single tokens
- **Cycles vs. function calls** create the shift/reduce conflict
- **Range syntax** `a..b` vs sequence indexing
- **Where clauses** can appear in multiple contexts

### Dynamic Features
- **Eval expressions** allow dynamic code evaluation
- **Variable argument lists** with `...`  
- **Optional parameters** in function definitions
- **Multiple return values** from functions

## Lexical Considerations

### Reserved Words
The language has **100+ reserved keywords** including:
- Control flow: `if`, `then`, `else`, `while`, `for`, `do`, `end`
- Mathematical structures: `algebra`, `group`, `field`, `ideal`
- I/O operations: `print`, `read`, `load`, `save`
- Type constructors: `rec`, `map`, `set`, `sequence`

### Identifiers
- Standard identifiers: `/[a-zA-Z_][a-zA-Z0-9_]*/`
- Case-sensitive language
- Underscore `_` is both an identifier character and a special "wildcard" token

### Literals
- **Integer literals**: Standard decimal, also hex (`0x...`) and binary (`0b...`)
- **Real literals**: Decimal with optional exponent
- **String literals**: Quoted strings with escape sequences
- **Sequence literals**: Pre-computed sequences like `[1,2,3]`
- **Cycle literals**: Permutation cycles

### Comments
The grammar doesn't show comment syntax explicitly, but likely supports:
- Line comments (probably `//`)
- Block comments (possibly `/* ... */`)

## Semantic Complexity

### Type System
Magma has a rich type system that the parser needs to handle:
- Primitive types: integers, rationals, reals, booleans, strings
- Container types: sequences, sets, tuples, records
- Mathematical types: groups, rings, fields, algebras, codes
- Function and procedure types
- Generic/parametric types

### Scoping Rules
- **Local variables** declared with `local`
- **Function parameters** with optional reference (`~`) modifier
- **Nested scopes** in functions, procedures, and blocks
- **Global context** with `$` and `$$` references

### Constructor Disambiguation
The parser must distinguish between:
- Set constructors: `{1, 2, 3}` vs `{x : x in S | P(x)}`
- Sequence constructors: `[1, 2, 3]` vs `[x : x in S | P(x)]`  
- Tuple constructors: `<1, 2>` vs `<x : x in S | P(x)>`
- Map constructors: various forms with `map<...>`

## Tree-Sitter Considerations

### Precedence Handling
Tree-sitter handles precedence differently than yacc/bison:
- Convert `%left`/`%right`/`%nonassoc` declarations to tree-sitter precedence rules
- May need to restructure some grammar rules for tree-sitter's precedence system
- Pay attention to **non-associative operators** which tree-sitter handles differently

### Left Recursion
Tree-sitter prefers **right recursion** for performance:
- Convert left-recursive list rules to right-recursive
- Example: `list: list ',' item` → `list: item (',' item)*`
- This affects many grammar rules for identifier lists, expression lists, etc.

### Conflict Resolution
- The commutator/function call conflict may need **GLR parsing** or **dynamic precedence**
- Tree-sitter's conflict resolution is different from yacc/bison
- May need to restructure grammar to avoid conflicts

### Performance Considerations
- Tree-sitter parsers should be **fast and incremental**
- Complex mathematical structure constructors might need optimization
- Consider factoring out common patterns into subrules

### Error Recovery
- Tree-sitter has built-in **error recovery** mechanisms
- The grammar should be designed to handle **partial/incomplete** input gracefully
- Mathematical expressions are particularly important for good error recovery

## Recommended Approach

### Phase 1: Core Grammar
Start with basic language constructs:
1. Literals and identifiers
2. Basic expressions with operators
3. Simple statements (assignment, control flow)
4. Function/procedure definitions

### Phase 2: Mathematical Constructs  
Add Magma-specific features:
1. Set/sequence/tuple constructors
2. Mathematical structure constructors
3. Map and record syntax
4. Quantifiers and comprehensions

### Phase 3: Advanced Features
Complete the grammar:
1. Intrinsic definitions
2. Package system
3. Advanced expression forms (where, case, eval)
4. Error handling constructs

### Testing Strategy
- Create **test corpus** with examples of each construct
- Focus on **expression parsing** which is most complex
- Test **conflict resolution** especially for commutators
- Validate **precedence handling** with complex expressions

## Known Challenges

### Ambiguous Constructs
1. **Commutators vs. function calls**: `(a, b, c)`
2. **Range vs. indexing**: `a[1..n]` 
3. **Type vs. constructor**: `Group` vs `group<...>`

### Complex Nesting
1. **Nested comprehensions**: `{f(x) : x in {y : y in S | P(y)} | Q(x)}`
2. **Complex constructor arguments**: Mathematical structures with many parameters
3. **Mixed bracket types**: `{[<a, b> : a in S] : b in T}`

### Context Sensitivity
1. **Keyword overloading**: Some keywords may be identifiers in certain contexts
2. **Operator precedence**: Complex precedence with many levels
3. **Type-dependent parsing**: Some constructs depend on semantic type information

This analysis provides a foundation for developing a tree-sitter grammar that captures the full complexity of the Magma language while working within tree-sitter's parsing model. 