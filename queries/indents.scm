;; Indentation queries for Magma (nvim-treesitter format)

;; Definitions — indent body
(function_definition
  "function" @indent.begin
  "end" @indent.end)

(procedure_definition
  "procedure" @indent.begin
  "end" @indent.end)

(intrinsic_definition
  "intrinsic" @indent.begin
  "end" @indent.end)

;; Control flow — indent after keyword, dedent at end
(if_statement
  "then" @indent.begin
  "end" @indent.end)

;; elif/else are both dedent and re-indent
(elif_clause
  "elif" @indent.branch)

(else_clause
  "else" @indent.branch)

(for_statement
  "do" @indent.begin
  "end" @indent.end)

(while_statement
  "do" @indent.begin
  "end" @indent.end)

(repeat_statement
  "repeat" @indent.begin
  "until" @indent.end)

(case_statement
  "case" @indent.begin
  "end" @indent.end)

(when_clause
  "when" @indent.branch)

(try_catch_statement
  "try" @indent.begin
  "catch" @indent.branch
  "end" @indent.end)

;; Constructors — indent between < >
;; Scoped to constructor nodes to avoid matching comparison operators
(constructor
  "<" @indent.begin
  ">" @indent.end)

(recformat_constructor
  "<" @indent.begin
  ">" @indent.end)

(case_constructor
  "<" @indent.begin
  ">" @indent.end)

;; Continuation lines: multi-line expressions wrapped in parentheses
(parenthesized_expression
  "(" @indent.begin
  ")" @indent.end)

;; Multi-line argument lists
(argument_list
  "(" @indent.begin
  ")" @indent.end)

;; Multi-line parameter lists
(parameters
  "(" @indent.begin
  ")" @indent.end)
