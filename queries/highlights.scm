;; Capture names follow the upstream tree-sitter convention. Consumers choose
;; which names and dotted prefixes their themes recognize.
;; Generic captures precede the more specific identifier roles below.
(identifier) @variable
(anonymous_identifier) @variable.builtin
(dollar) @variable.builtin
(double_dollar) @function.builtin

(comment) @comment
(string) @string
(doc_string) @string.documentation
(integer) @number
(real) @number.float
[(true) (false)] @constant.builtin

[";" "," ":"] @punctuation.delimiter
[".." "|" "..."] @punctuation.special
[
  "(" ")" "[" "]" "{" "}" "<" ">"
  "[*" "*]" "{@" "@}" "{!" "!}" "{*" "*}" "{[" "]}"
  "\\[" "\\("
] @punctuation.bracket

;; Match operator tokens directly. Parent/field patterns on left-nested binary
;; expressions make highlighting long polynomial expressions much slower.
[
  ":=" "::" ":->" "->" "=" "~" "`" "``" "[~]"
  "+" "-" "*" "/" "^" "^^" "@" "@@" "!" "!!" "." "#"
] @operator
[
  "div" "mod" "join" "diff" "sdiff" "meet" "cat"
  "in" "notin" "adj" "notadj" "subset" "notsubset"
  "gt" "ge" "lt" "le" "eq" "ne" "cmpeq" "cmpne"
  "and" "or" "xor" "not" "assigned"
] @keyword.operator
(reduct_operator operator: _ @operator)
(augmented_assignment operator: _ @operator)

["function" "procedure" "intrinsic" "end"] @keyword.function
"return" @keyword.return
["if" "then" "elif" "else" "case" "when" "select" "default"] @keyword.conditional
["for" "to" "by" "do" "while" "repeat" "until" "break" "continue"] @keyword.repeat
["try" "catch" "error"] @keyword.exception
["where" "is" "eval"] @keyword
["exists" "forall" "random" "in"] @keyword.operator

;; `end` takes its role from the enclosing construct.
(if_statement "end" @keyword.conditional)
(case_statement "end" @keyword.conditional)
(for_statement "end" @keyword.repeat)
(while_statement "end" @keyword.repeat)
(try_catch_statement "end" @keyword.exception)

;; After a comma, the current parser represents `default` as a match identifier.
((case_constructor match: (identifier) @keyword.conditional)
 (#eq? @keyword.conditional "default"))

;; `rep` is an ordinary identifier except when extracting a representative.
(representative_of_set . (identifier) @keyword.operator)

;; Capture keywords, not whole statements: operands retain their own colors.
(clear) @keyword.directive
(freeze) @keyword.directive
[
  "forward" "delete" "quit" "exit" "load" "iload" "save" "restore" "import"
  "declare" "attributes" "type" "verbose" "local"
  "print" "printf" "fprintf" "vprint" "vprintf" "read" "readi"
  "assert" "assert2" "assert3" "require" "requirege" "requirerange"
  "time" "vtime"
] @keyword.directive
["Default" "Maximal" "Minimal" "Magma" "Hex" "Latex"] @constant.builtin

(call function: (identifier) @function)
(function_definition name: (identifier) @function)
(procedure_definition name: (identifier) @function)
(intrinsic_definition name: (identifier) @function)
(forward (identifier) @function)
(assignment
  . left: (identifier) @function
  . (comment)* . ":=" . (comment)*
  . right: [(function_definition) (procedure_definition)] .)

(parameters (identifier) @variable.parameter)
(typed_identifier (identifier) @variable.parameter)
(ref_identifier (identifier) @variable.parameter)
(ref_typed_identifier (identifier) @variable.parameter)
(backtick_identifier (identifier) @variable.parameter)
(optional_parameter name: (identifier) @variable.parameter)
(optional_argument argument: (identifier) @variable.parameter)
;; Match the inlined parameter list without including the intrinsic's name.
(intrinsic_definition "(" (identifier) @variable.parameter)
(intrinsic_definition ":" (identifier) @variable.parameter)

(type (identifier) @type)
(type (string) @type)
(type "." @type)
(attribute_declaration category: (identifier) @type)
(type_declaration supertype: (identifier) @type)

(attribute "`" . (identifier) @property)
(attribute_declaration ":" (identifier) @property)
(field_definition name: (identifier) @property)
(recformat_constructor (identifier) @property)
(field_definition type: (identifier) @type)
(simple_assignment name: (identifier) @property)
(constructor_options (simple_assignment name: (identifier) @variable.parameter))

(constructor name: (identifier) @function.builtin)
;; Generator declarations share the constructor node, but declare a variable.
(assignment left: (constructor name: (identifier) @variable))
((constructor
  name: (identifier) @function.builtin
  (identifier) @variable.parameter)
 (#any-of? @function.builtin "func" "proc"))
((constructor
  name: (identifier) @function.builtin
  (constructor_elements
    (constructor_options (identifier) @variable.parameter)))
 (#any-of? @function.builtin "func" "proc"))
((constructor
  name: (identifier) @function.builtin
  (unary_operator operator: "~" right: (identifier) @variable.parameter))
 (#eq? @function.builtin "proc"))
(map_constructor domain_element: (identifier) @variable.parameter)
"recformat" @function.builtin
