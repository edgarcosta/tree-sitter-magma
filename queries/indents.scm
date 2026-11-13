;; Indentation queries for Magma (nvim-treesitter format).
;; @indent.begin must capture whole multi-line nodes; a keyword token that
;; starts and ends on one line never indents anything.

[
  (function_definition)
  (procedure_definition)
  (intrinsic_definition)
  (if_statement)
  (for_statement)
  (while_statement)
  (repeat_statement)
  (case_statement)
  (try_catch_statement)
  (constructor)
  (recformat_constructor)
  (case_constructor)
  (parenthesized_expression)
  (argument_list)
  (parameters)
  (assignment)
] @indent.begin

[
  "end"
  "until"
  ")"
  ">"
] @indent.end

[
  "end"
  "until"
  ")"
  ">"
  "catch"
  (elif_clause)
  (else_clause)
  (when_clause)
] @indent.branch

;; `when` and `else:` sit level with `case`, as in the Magma package library.
(case_statement "else" @indent.branch)

;; Docstrings sit level with `intrinsic`; their continuation lines are text.
(doc_string) @indent.branch
[(doc_string) (comment) (string)] @indent.auto
