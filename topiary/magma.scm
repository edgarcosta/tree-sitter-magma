;; Topiary formatting queries for Magma.
;;
;; Operator spacing note: the byte range of an anonymous token in this
;; grammar spans the whitespace between its named siblings, so the
;; token's source text already includes any leading space. Using
;; @prepend_space on an operator therefore double-spaces well-formatted
;; input (e.g. "y := 2" becomes "y  := 2"). We only @append_space on
;; operators and trust the source for spacing before them.

;; Leaves: don't reformat
[
  (comment)
  (string)
  (doc_string)
] @leaf

;; Allow blank lines between top-level constructs
[
  (expression_statement)
  (assignment)
  (comment)
  (freeze)
  (import_directive)
  (if_statement)
  (for_statement)
  (while_statement)
  (repeat_statement)
  (case_statement)
  (try_catch_statement)
] @allow_blank_line_before

;; Semicolons: hardline after, no space before
(block ";" @append_hardline)
(program ";" @append_hardline)
";" @prepend_antispace

;; Function/procedure/intrinsic definitions
(function_definition
  .
  "function" @append_space
)
(function_definition
  parameters: (parameters) @append_hardline
  body: (block) @prepend_indent_start @append_indent_end
)
(function_definition
  "end" @prepend_hardline @append_space
)

(procedure_definition
  .
  "procedure" @append_space
)
(procedure_definition
  parameters: (parameters) @append_hardline
  body: (block) @prepend_indent_start @append_indent_end
)
(procedure_definition
  "end" @prepend_hardline @append_space
)

(intrinsic_definition
  .
  "intrinsic" @append_space
)
(intrinsic_definition
  (doc_string) @prepend_hardline @append_hardline
  body: (block) @prepend_indent_start @append_indent_end
)
(intrinsic_definition
  "end" @prepend_hardline @append_space
)
(intrinsic_definition
  "->" @append_space
)

;; if / elif / else
(if_statement
  "if" @append_space
  "then" @append_hardline
  consequence: (block) @prepend_indent_start @append_indent_end
  "end" @prepend_hardline @append_space
)
(elif_clause
  "elif" @prepend_hardline @append_space
  "then" @append_hardline
  consequence: (block) @prepend_indent_start @append_indent_end
)
(else_clause
  "else" @prepend_hardline @append_hardline
  consequence: (block) @prepend_indent_start @append_indent_end
)

;; for
(for_statement
  "for" @append_space
  "do" @append_hardline
  body: (block) @prepend_indent_start @append_indent_end
  "end" @prepend_hardline @append_space
)
(for_quantifier
  [":=" "to" "by"] @append_space
)

;; while
(while_statement
  "while" @append_space
  "do" @append_hardline
  body: (block) @prepend_indent_start @append_indent_end
  "end" @prepend_hardline @append_space
)

;; repeat / until
(repeat_statement
  "repeat" @append_hardline
  body: (block) @prepend_indent_start @append_indent_end
  "until" @prepend_hardline @append_space
)

;; case / when / else
(case_statement
  "case" @append_space
  ":" @append_hardline @append_indent_start
)
(when_clause
  "when" @prepend_hardline @append_space
  ":" @append_hardline
  consequence: (block) @prepend_indent_start @append_indent_end
)
(case_statement
  "else" @prepend_hardline @append_hardline
  else: (block) @prepend_indent_start @append_indent_end
)
(case_statement
  "end" @prepend_hardline @prepend_indent_end @append_space
)

;; try / catch
(try_catch_statement
  .
  "try" @append_hardline
)
(try_catch_statement
  (block) @prepend_indent_start @append_indent_end
)
(try_catch_statement
  "catch" @prepend_hardline @append_space
  error: (_) @append_hardline
  "end" @prepend_hardline @append_space
)

;; Binary and unary operators (see header note: @append_space only)
(binary_operator
  operator: ["+" "-" "*" "/" "^" "^^"] @append_space
)
(unary_operator
  operator: "not" @append_space
)
(unary_operator
  operator: ["-" "+" "#" "~"] @append_antispace
)

;; Assignment
(assignment ":=" @append_space)

;; Commas: space after, no space before
"," @append_space @prepend_antispace

;; Brackets: no space inside
[
  (parameters)
  (argument_list)
  (parenthesized_expression)
] (
  "(" @append_antispace
  ")" @prepend_antispace
)

[
  (constructor)
  (recformat_constructor)
  (tuple)
] (
  "<" @append_antispace
  ">" @prepend_antispace
)

(seqenum
  "[" @append_antispace
  "]" @prepend_antispace
)
(set
  "{" @append_antispace
  "}" @prepend_antispace
)

;; field_definition: "name : Type"
(field_definition
  ":" @prepend_space @append_space
)

;; where clauses
(where_expression
  "where" @append_space
  ":=" @prepend_space @append_space
)

;; Statement-leading keywords: space after
(return_statement "return" @append_space)
(print_statement "print" @append_space)
(error_statement "error" @append_space)
(assert_statement "assert" @append_space)
(local_statement "local" @append_space)
(delete "delete" @append_space)
(require_statement
  "require" @append_space
  ":" @append_space
)
(import_directive
  "import" @append_space
  ":" @append_space
)

;; Optional / typed parameters
(optional_parameter ":=" @append_space)
(typed_identifier "::" @append_space)

;; Ternary: cond select x else y
(ternary_operator
  ["select" "else"] @append_space
)

;; Ref identifier (~x): no space after tilde
(ref_identifier "~" @append_antispace)

;; Comments: preserve input softline before, hardline after
(comment) @prepend_input_softline @append_hardline
