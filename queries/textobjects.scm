;; Text object queries for Magma (nvim-treesitter-textobjects format)

;; Functions — outer includes keywords, inner is just the body
(function_definition) @function.outer
(function_definition
  body: (block) @function.inner)

(procedure_definition) @function.outer
(procedure_definition
  body: (block) @function.inner)

(intrinsic_definition) @function.outer
(intrinsic_definition
  body: (block) @function.inner)

;; Parameters
(parameters) @parameter.outer
(parameter) @parameter.inner

;; Arguments
(argument_list) @parameter.outer
(argument_list
  argument: (_) @parameter.inner)

;; Control flow blocks
(if_statement) @block.outer
(if_statement
  consequence: (block) @block.inner)

(for_statement) @block.outer
(for_statement
  body: (block) @block.inner)

(while_statement) @block.outer
(while_statement
  body: (block) @block.inner)

(repeat_statement) @block.outer
(repeat_statement
  body: (block) @block.inner)

(case_statement) @block.outer

;; Comments
(comment) @comment.outer
