;; Code folding queries for Magma

;; Definitions
(function_definition) @fold
(procedure_definition) @fold
(intrinsic_definition) @fold

;; Control flow
(if_statement) @fold
(for_statement) @fold
(while_statement) @fold
(repeat_statement) @fold
(case_statement) @fold
(try_catch_statement) @fold

;; Constructors (multi-line)
(constructor) @fold
(recformat_constructor) @fold
(case_constructor) @fold

;; Block comments
(comment) @fold
