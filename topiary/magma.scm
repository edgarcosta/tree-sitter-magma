;; Topiary formatting queries for Magma
;;
;; NOTE: In this grammar, anonymous token byte ranges may include
;; surrounding whitespace from the source text. Topiary uses source
;; byte ranges for token content, so whitespace before operators gets
;; embedded in the content. Therefore, we use @append_space on operator
;; tokens (for trailing space) but avoid @prepend_space on anonymous
;; tokens (which would add a duplicate leading space). Spacing BEFORE
;; operators is preserved from the source.

;; ============================================================
;; Leaves: content that should not be reformatted
;; ============================================================

[
  (comment)
  (string)
  (doc_string)
] @leaf

;; ============================================================
;; Allow blank lines between top-level constructs
;; ============================================================

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

;; ============================================================
;; Semicolons: always followed by a newline, no space before
;; ============================================================

(block
  ";" @append_hardline
)

(program
  ";" @append_hardline
)

";" @prepend_antispace

;; ============================================================
;; Function/procedure/intrinsic definitions
;; ============================================================

;; Space after opening keyword (anchored as first child)
(function_definition
  .
  "function" @append_space
)

(procedure_definition
  .
  "procedure" @append_space
)

(intrinsic_definition
  .
  "intrinsic" @append_space
)

;; Newline after parameters, indent body block
(function_definition
  parameters: (parameters) @append_hardline
  body: (block) @prepend_indent_start @append_indent_end
)

(function_definition
  "end" @prepend_hardline @append_space
)

(procedure_definition
  parameters: (parameters) @append_hardline
  body: (block) @prepend_indent_start @append_indent_end
)

(procedure_definition
  "end" @prepend_hardline @append_space
)

(intrinsic_definition
  (doc_string) @append_hardline
  body: (block) @prepend_indent_start @append_indent_end
)

(intrinsic_definition
  "end" @prepend_hardline @append_space
)

;; ============================================================
;; Control flow: if/elif/else
;; ============================================================

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

;; ============================================================
;; Control flow: for
;; ============================================================

(for_statement
  "for" @append_space
  "do" @append_hardline
  body: (block) @prepend_indent_start @append_indent_end
  "end" @prepend_hardline @append_space
)

;; Spacing in for_quantifier (use @append_space only)
(for_quantifier
  ":=" @append_space
)

(for_quantifier
  "to" @append_space
)

(for_quantifier
  "by" @append_space
)

;; ============================================================
;; Control flow: while
;; ============================================================

(while_statement
  "while" @append_space
  "do" @append_hardline
  body: (block) @prepend_indent_start @append_indent_end
  "end" @prepend_hardline @append_space
)

;; ============================================================
;; Control flow: repeat/until
;; ============================================================

(repeat_statement
  "repeat" @append_hardline
  body: (block) @prepend_indent_start @append_indent_end
  "until" @prepend_hardline @append_space
)

;; ============================================================
;; Control flow: case
;; ============================================================

(case_statement
  "case" @append_space
)

(case_statement
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

;; ============================================================
;; Control flow: try/catch
;; ============================================================

;; Opening "try" gets hardline after (anchored as first child)
(try_catch_statement
  .
  "try" @append_hardline
)

;; Indent both blocks in try/catch
(try_catch_statement
  (block) @prepend_indent_start @append_indent_end
)

(try_catch_statement
  "catch" @prepend_hardline @append_space
)

(try_catch_statement
  error: (_) @append_hardline
)

(try_catch_statement
  "end" @prepend_hardline @append_space
)

;; ============================================================
;; Binary operators: @append_space only (preserves source spacing before)
;; ============================================================

(binary_operator
  operator: "+" @append_space
)

(binary_operator
  operator: "-" @append_space
)

(binary_operator
  operator: "*" @append_space
)

(binary_operator
  operator: "/" @append_space
)

(binary_operator
  operator: "^" @append_space
)

(binary_operator
  operator: "^^" @append_space
)

(binary_operator
  operator: "~" @append_space
)

;; Dot, bang, at operators: no extra spaces (member access, indexing)
;; e.g. G.1, x!, x!!, f@x, f@@x — source spacing preserved

;; ============================================================
;; Assignment operator: @append_space only
;; ============================================================

(assignment
  ":=" @append_space
)

;; ============================================================
;; Commas: space after, no space before
;; ============================================================

"," @append_space
"," @prepend_antispace

;; ============================================================
;; Parentheses: no space inside
;; ============================================================

(parameters
  "(" @append_antispace
  ")" @prepend_antispace
)

(argument_list
  "(" @append_antispace
  ")" @prepend_antispace
)

(parenthesized_expression
  "(" @append_antispace
  ")" @prepend_antispace
)

;; ============================================================
;; Constructors — angle brackets: no space inside
;; ============================================================

(constructor
  "<" @append_antispace
  ">" @prepend_antispace
)

(recformat_constructor
  "<" @append_antispace
  ">" @prepend_antispace
)

(tuple
  "<" @append_antispace
  ">" @prepend_antispace
)

;; field_definition: "name : Type"
(field_definition
  ":" @prepend_space @append_space
)

;; ============================================================
;; Aggregates — no space inside brackets
;; ============================================================

(seqenum
  "[" @append_antispace
  "]" @prepend_antispace
)

(set
  "{" @append_antispace
  "}" @prepend_antispace
)

;; ============================================================
;; Where clauses
;; ============================================================

(where_expression
  "where" @append_space
)

(where_expression
  ":=" @prepend_space @append_space
)

;; ============================================================
;; Statement keywords: space after
;; ============================================================

(return_statement
  "return" @append_space
)

(print_statement
  "print" @append_space
)

(error_statement
  "error" @append_space
)

(assert_statement
  "assert" @append_space
)

(require_statement
  "require" @append_space
)

(require_statement
  ":" @append_space
)

(local_statement
  "local" @append_space
)

(delete
  "delete" @append_space
)

;; ============================================================
;; Import directives
;; ============================================================

(import_directive
  "import" @append_space
)

(import_directive
  ":" @append_space
)

;; ============================================================
;; Optional parameter (name := value)
;; ============================================================

(optional_parameter
  ":=" @append_space
)

;; ============================================================
;; Typed identifier (x :: Type)
;; ============================================================

(typed_identifier
  "::" @append_space
)

;; ============================================================
;; Ternary operator (cond select x else y)
;; ============================================================

(ternary_operator
  "select" @append_space
)

(ternary_operator
  "else" @append_space
)

;; ============================================================
;; Arrow operator in intrinsic definitions
;; ============================================================

(intrinsic_definition
  "->" @append_space
)

;; ============================================================
;; Ref identifier (~x): no space after tilde
;; ============================================================

(ref_identifier
  "~" @append_antispace
)

;; ============================================================
;; Unary operators
;; ============================================================

(unary_operator
  operator: "not" @append_space
)

(unary_operator
  operator: "-" @append_antispace
)

(unary_operator
  operator: "+" @append_antispace
)

(unary_operator
  operator: "#" @append_antispace
)

(unary_operator
  operator: "~" @append_antispace
)

;; ============================================================
;; Comments
;; ============================================================

(comment) @prepend_input_softline
(comment) @append_hardline

;; ============================================================
;; Intrinsic definition extras
;; ============================================================

(intrinsic_definition
  (doc_string) @prepend_hardline
)
