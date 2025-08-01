# Operator Precedence and Associativity

This document outlines the precedence and associativity of operators in the Magma language, from lowest to highest precedence. This information is extracted from the `interp/parser.y` file.

| Associativity | Operators                                                               | Description                      |
| :------------ | :---------------------------------------------------------------------- | :------------------------------- |
| `left`        | `TOK_EVAL` (`eval`)                                                     | Evaluation                       |
| `left`        | `TOK_WHERE`, `TOK_IS`, `TOK_BECOMES` (`where`, `is`, `:=`)              | `where` clause and assignment    |
| `left`        | `TOK_EQUALITY` (`=`)                                                    | Equality test                    |
| `left`        | `TOK_ARROW` (`->`)                                                      | Map/function arrow               |
| `right`       | `TOK_QUESTION`, `TOK_SELECT`, `TOK_ELSE` (`?`, `select`, `else`)        | Ternary conditional              |
| `nonassoc`    | `TOK_HAT_HAT` (`^^`)                                                    | Double exponentiation            |
| `left`        | `TOK_OR`, `TOK_XOR` (`or`, `xor`)                                       | Logical OR/XOR                   |
| `left`        | `TOK_AND` (`and`)                                                       | Logical AND                      |
| `right`       | `TOK_NOT` (`not`)                                                       | Logical NOT                      |
| `left`        | `TOK_EQ`, `TOK_CMPEQ`, `TOK_CMPNE`, `TOK_NE`, `TOK_GT`, `TOK_GE`, `TOK_LT`, `TOK_LE` | Comparison operators           |
| `nonassoc`    | `TOK_IN`, `TOK_NOTIN`, `TOK_ADJ`, `TOK_NOTADJ`, `TOK_SUBSET`, `TOK_NOTSUBSET` | Membership and relation tests    |
| `left`        | `TOK_JOIN` (`join`)                                                     | Set/sequence join                |
| `left`        | `TOK_DIFF` (`diff`)                                                     | Set difference                   |
| `left`        | `TOK_SDIFF` (`sdiff`)                                                   | Symmetric difference             |
| `left`        | `TOK_MEET` (`meet`)                                                     | Set intersection                 |
| `left`        | `TOK_PLUS`, `TOK_MINUS` (`+`, `-`)                                      | Addition and subtraction         |
| `left`        | `TOK_DIV`, `TOK_MOD`, `TOK_STAR`, `TOK_SLASH` (`div`, `mod`, `*`, `/`)  | Multiplication and division      |
| `left`        | `TOK_TILDE` (`~`)                                                       | Tilde                            |
| `left`        | `TOK_CAT` (`cat`)                                                       | Concatenation                    |
| `right`       | `TOK_UMINUS`                                                            | Unary minus                      |
| `right`       | `TOK_HAT` (`^`)                                                         | Exponentiation                   |
| `right`       | `TOK_BANG`, `TOK_BANG_BANG` (`!`, `!!`)                                 | Coercion                         |
| `left`        | `TOK_AT`, `TOK_ATAT` (`@`, `@@`)                                        | Map application                  |
| `left`        | `TOK_DOT` (`.`)                                                         | Record/attribute access          |
| `nonassoc`    | `TOK_DOLLAR`, `TOK_DOLLAR_DOLLAR` (`$`, `$$`)                           | Previous value                   |
| `nonassoc`    | `TOK_REDUCT_PLUS`, `TOK_REDUCT_MULT`, `TOK_REDUCT_AND`, ...               | Reduction operators              |
| `nonassoc`    | `TOK_HASH` (`#`)                                                        | Cardinality                      |
| `nonassoc`    | `TOK_UTILDE`                                                            | Unary tilde (internal)           |
| `right`       | `TOK_ASSIGNED` (`assigned`)                                             | `assigned` operator              |
| `left`        | `TOK_LEFTSQUARE` (`[`)                                                  | Indexing                         |
| `left`        | `TOK_LEFTROUND` (`(`)                                                   | Function call / grouping         |
| `left`        | `TOK_BACKQUOTE`, `TOK_BACKQUOTE_BACKQUOTE` (`` ` ``, ``` `` ```) | Backtick/record field access     | 