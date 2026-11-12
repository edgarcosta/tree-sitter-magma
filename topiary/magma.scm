;; Topiary formatting queries for Magma
;;
;; ============================================================
;; Leaves: content that should not be reformatted
;; ============================================================

;; Comments are already single tokens. An explicit @leaf capture prevents
;; Topiary 0.7.3 from discarding a leading space before adjusting their indent.
[
  (string)
  (doc_string)
] @leaf

;; ============================================================
;; Statement boundaries
;; ============================================================

;; Break before each statement, leaving a same-line trailing comment beside
;; its semicolon. Block terminators already carry their own hardlines.
(program
  [
    (expression_statement)
    (assignment)
    (augmented_assignment)
    (return_statement)
    (break_statement)
    (continue_statement)
    (print_statement)
    (vprint_statement)
    (read_statement)
    (time_statement)
    (vtime_statement)
    (assert_statement)
    (require_statement)
    (local_statement)
    (error_statement)
    (clear)
    (freeze)
    (forward)
    (delete)
    (exit_directive)
    (load_directive)
    (save_directive)
    (import_directive)
    (declare_statement)
    (if_statement)
    (for_statement)
    (while_statement)
    (repeat_statement)
    (case_statement)
    (try_catch_statement)
  ] @prepend_hardline @allow_blank_line_before
)
(block
  [
    (expression_statement)
    (assignment)
    (augmented_assignment)
    (return_statement)
    (break_statement)
    (continue_statement)
    (print_statement)
    (vprint_statement)
    (read_statement)
    (time_statement)
    (vtime_statement)
    (assert_statement)
    (require_statement)
    (local_statement)
    (error_statement)
    (clear)
    (freeze)
    (forward)
    (delete)
    (exit_directive)
    (load_directive)
    (save_directive)
    (import_directive)
    (declare_statement)
    (if_statement)
    (for_statement)
    (while_statement)
    (repeat_statement)
    (case_statement)
    (try_catch_statement)
  ] @prepend_hardline @allow_blank_line_before
)

";" @prepend_antispace @append_input_softline
(program (comment) @append_hardline)
(block (comment) @append_hardline)

;; ============================================================
;; Function/procedure/intrinsic definitions
;; ============================================================

;; Named function definition: hardline before, space after `function`
(function_definition
  .
  "function" @append_space
  .
  name: (identifier)
) @prepend_hardline

;; Anonymous function (used as expression): no hardline, strip
;; whitespace after `function` so it abuts the parameter list.
(function_definition
  .
  "function" @append_antispace
  .
  parameters: (parameters)
)

;; Named procedure: space after `procedure`.
(procedure_definition
  .
  "procedure" @append_space
  .
  name: (identifier)
)

;; Anonymous procedure: strip whitespace after `procedure`.
(procedure_definition
  .
  "procedure" @append_antispace
  .
  parameters: (parameters)
)

(intrinsic_definition
  .
  "intrinsic" @append_space
)

;; Indent from the opening syntax to the closing keyword. Comments are
;; extras and may fall outside the body block, including in empty bodies.
(function_definition
  parameters: (parameters) @append_hardline @append_indent_start
  "end" @prepend_indent_end @prepend_hardline @append_space
)

(procedure_definition
  parameters: (parameters) @append_hardline @append_indent_start
  "end" @prepend_indent_end @prepend_hardline @append_space
)

(intrinsic_definition
  (doc_string) @prepend_hardline @append_hardline @append_indent_start
  "end" @prepend_indent_end @prepend_hardline @append_space
)

;; ============================================================
;; Control flow: if/elif/else
;; ============================================================

;; Each clause closes the preceding body's indentation before opening its
;; own. The final `end` closes whichever branch came last.
(if_statement
  "if" @append_space
  "then" @prepend_input_softline @append_hardline @append_indent_start
  "end" @prepend_indent_end @prepend_hardline @append_space
)

(elif_clause
  "elif" @prepend_indent_end @prepend_hardline @append_space
  "then" @prepend_input_softline @append_hardline @append_indent_start
)

(else_clause
  "else" @prepend_indent_end @prepend_hardline @append_hardline
)
(else_clause "else" @append_indent_start)

;; ============================================================
;; Control flow: for
;; ============================================================

(for_statement
  "for" @append_space
  "do" @prepend_input_softline @append_hardline @append_indent_start
  "end" @prepend_indent_end @prepend_hardline @append_space
)

(for_quantifier
  "random" @append_space
  "in" @prepend_space @append_space
)

(for_quantifier
  ":=" @prepend_input_softline @append_input_softline
)

(for_quantifier
  "to" @prepend_input_softline @append_input_softline
)

(for_quantifier
  "by" @prepend_input_softline @append_input_softline
)

;; range expression `a..b by c` (used inside aggregates: `[1..n by -1]`).
;; The grammar's range rule has bare 'by' (no surrounding spaces in literal),
;; so without this rule `[1..n by -1]` collapses to `[1..nby-1]`.
(range
  "by" @prepend_input_softline @append_input_softline
)

;; ============================================================
;; Control flow: while
;; ============================================================

(while_statement
  "while" @append_space
  "do" @prepend_input_softline @append_hardline @append_indent_start
  "end" @prepend_indent_end @prepend_hardline @append_space
)

;; ============================================================
;; Control flow: repeat/until
;; ============================================================

(repeat_statement
  "repeat" @append_hardline @append_indent_start
  "until" @prepend_indent_end @prepend_hardline @append_space
)

;; ============================================================
;; Control flow: case
;; ============================================================

(case_statement
  "case" @append_space
  ":" @append_hardline @append_indent_start
  (when_clause)
  "end" @prepend_indent_end @prepend_hardline @append_space
)

;; Start each body at its colon, but finish it at the next clause/end.
;; This includes comments outside the when_clause/block node ranges.
(when_clause
  "when" @prepend_hardline @append_space
  ":" @append_hardline @append_indent_start
)
(case_statement
  (when_clause)
  . (comment)* .
  (when_clause "when" @prepend_indent_end)
)
(case_statement
  "else" @prepend_indent_end @prepend_hardline
)
(case_statement
  "else"
  . [(comment) (block)] @prepend_hardline
)
(case_statement "else" @append_indent_start)
(case_statement
  "end" @prepend_indent_end
)

;; ============================================================
;; Control flow: try/catch
;; ============================================================

(try_catch_statement
  .
  "try" @append_hardline @append_indent_start
  "catch" @prepend_indent_end @prepend_hardline @append_space
  error: (_) @append_hardline @append_indent_start
  "end" @prepend_indent_end @prepend_hardline @append_space
)

;; Commas retain user-chosen row grouping in every comma-separated form.
"," @prepend_antispace @append_input_softline

;; ============================================================
;; Delimited expressions and signatures
;; ============================================================

;; Antispace suppresses the space variant of an input softline, but leaves
;; existing newlines intact. Balanced indentation also works for empty
;; and comment-only lists. Closing delimiters align with the enclosing code.
(parameters
  "(" @append_antispace @append_input_softline @append_indent_start
  ")" @prepend_antispace @prepend_input_softline @prepend_indent_end
)

(argument_list
  "(" @append_antispace @append_input_softline @append_indent_start
  ")" @prepend_antispace @prepend_input_softline @prepend_indent_end
)

(parenthesized_expression
  "(" @append_antispace @append_input_softline @append_indent_start
  ")" @prepend_antispace @prepend_input_softline @prepend_indent_end
)

(intrinsic_definition
  "(" @append_antispace @append_input_softline @append_indent_start
  ")" @prepend_antispace @prepend_input_softline @prepend_indent_end
)

(constructor
  "<" @append_antispace @append_input_softline @append_indent_start
  ">" @prepend_antispace @prepend_input_softline @prepend_indent_end
)

(recformat_constructor
  "<" @append_antispace @append_input_softline @append_indent_start
  ">" @prepend_antispace @prepend_input_softline @prepend_indent_end
)

(case_constructor
  "<" @append_antispace @append_input_softline @append_indent_start
  ">" @prepend_antispace @prepend_input_softline @prepend_indent_end
)

(anonymous_constructor
  "<" @append_antispace @append_input_softline @append_indent_start
  ">" @prepend_antispace @prepend_input_softline @prepend_indent_end
)

(tuple
  "<" @append_antispace @append_input_softline @append_indent_start
  ">" @prepend_antispace @prepend_input_softline @prepend_indent_end
)

(seqenum
  "[" @append_antispace @append_input_softline @append_indent_start
  "]" @prepend_antispace @prepend_input_softline @prepend_indent_end
)

(literal_sequence
  "\\[" @append_antispace @append_input_softline @append_indent_start
  "]" @prepend_antispace @prepend_input_softline @prepend_indent_end
)

(list
  "[*" @append_antispace @append_input_softline @append_indent_start
  "*]" @prepend_antispace @prepend_input_softline @prepend_indent_end
)

(set
  "{" @append_antispace @append_input_softline @append_indent_start
  "}" @prepend_antispace @prepend_input_softline @prepend_indent_end
)

(indexed_set
  "{@" @append_antispace @append_input_softline @append_indent_start
  "@}" @prepend_antispace @prepend_input_softline @prepend_indent_end
)

(formal_set
  "{!" @append_antispace @append_input_softline @append_indent_start
  "!}" @prepend_antispace @prepend_input_softline @prepend_indent_end
)

(multiset
  "{*" @append_antispace @append_input_softline @append_indent_start
  "*}" @prepend_antispace @prepend_input_softline @prepend_indent_end
)

(cycle_or_commutator
  "(" @append_antispace @append_input_softline @append_indent_start
  ")" @prepend_antispace @prepend_input_softline @prepend_indent_end
)

(case_constructor
  ["|" ":" "default"] @prepend_input_softline @append_input_softline
)

;; Constructor `|` separates options/parameters from elements:
;;   quo<F | r1, r2>  or  quo<GrpFP : F1, F2 | R : opt := val>
(constructor_elements
  "|" @prepend_input_softline @append_input_softline
) @prepend_input_softline

;; Map constructor `:->` separates domain element from image:
;;   map< X -> Y | x :-> x^2 >
(map_constructor
  ":->" @prepend_input_softline @append_input_softline
)

;; two_tuple `->` (e.g., the `X -> Y` in `map<X -> Y | ...>`):
;; mirrors the `intrinsic_definition` `->` rule so the arrow has
;; consistent spacing wherever it appears as a structural separator.
(two_tuple
  "->" @prepend_input_softline @append_input_softline
)

;; constructor_options `:` separates the options block (e.g., the
;; `: F1, F2` in `quo<GrpFP : F1, F2 | ...>` and the trailing
;; `: opt := val`).
(constructor_options
  ":" @append_input_softline
) @prepend_input_softline

;; simple_assignment `name := value` appears inside constructor
;; options/elements (e.g., `R : opt := val`). Space around `:=`
;; mirrors the global assignment rule.
(simple_assignment
  ":=" @prepend_input_softline @append_input_softline
)

;; field_definition: "name : Type"
(field_definition
 ":" @prepend_input_softline @append_input_softline
 )

;; Comprehension separators ":" and "|" inside aggregates
;; (one explicit rule per aggregate node — bracket-list-of-parents matched
;;  ":" globally including in require_statement, so we list each parent).
(seqenum     ":" @prepend_input_softline @append_input_softline)
(list        ":" @prepend_input_softline @append_input_softline)
(set         ":" @prepend_input_softline @append_input_softline)
(indexed_set ":" @prepend_input_softline @append_input_softline)
(formal_set  ":" @prepend_input_softline @append_input_softline)
(multiset    ":" @prepend_input_softline @append_input_softline)
(tuple       ":" @prepend_input_softline @append_input_softline)

(seqenum     "|" @prepend_input_softline @append_input_softline)
(list        "|" @prepend_input_softline @append_input_softline)
(set         "|" @prepend_input_softline @append_input_softline)
(indexed_set "|" @prepend_input_softline @append_input_softline)
(formal_set  "|" @prepend_input_softline @append_input_softline)
(multiset    "|" @prepend_input_softline @append_input_softline)
(tuple       "|" @prepend_input_softline @append_input_softline)

(iter_var
  "in" @prepend_input_softline @append_input_softline
)
(iter_var
  "->" @prepend_input_softline @append_input_softline
)

(quantified_set ["exists" "forall"] @append_space)
(quantified_set "(" @prepend_antispace @append_antispace
                ")" @prepend_antispace @append_space)
(random_element_of_set "random" @append_space)
(representative_of_set (identifier) @append_space)

;; ============================================================
;; Where clauses
;; ============================================================

(where_expression
 "where" @prepend_input_softline @append_input_softline
 operator: [":=" "is"] @prepend_input_softline @append_input_softline
 )

;; ============================================================
;; Statement keywords: space after
;; ============================================================

(return_statement
  "return" @append_input_softline
)

(print_level_statement ":" @prepend_antispace @append_space)

(print_statement
  ["print" "printf" "fprintf"] @append_input_softline
)

(vprint_statement
  ["vprint" "vprintf"] @append_space
  ":" @append_space
)

(eval_expression
  "eval" @append_input_softline
)

;; break / continue can take an optional label identifier:
;;   break u;  break 2;  continue u;
;; The keyword needs a trailing space when followed by an identifier.
;; The existing program-level ";" @prepend_antispace rule strips the
;; space when the statement is bare (`break;`).
(break_statement
  "break" @append_space
)
(continue_statement
  "continue" @append_space
)

(error_statement
  "error" @append_input_softline
)

;; error if cond, msg — the conditional form: `error if NOT separable, "..."`
(error_statement
  "if" @prepend_input_softline @append_input_softline
)

(assert_statement
  ["assert" "assert2" "assert3"] @append_input_softline
)

(require_statement
  "require" @append_input_softline
)

(require_statement
  ":" @append_space
)

(require_statement
  "requirege" @append_space
)

(require_statement
  "requirerange" @append_space
)

(local_statement
  "local" @append_input_softline
)

(delete
  "delete" @append_input_softline
)

(forward
  "forward" @append_input_softline
)

(read_statement
  ["read" "readi"] @append_input_softline
)

(exit_directive
  ["quit" "exit"] @append_space
)

(time_statement
  "time" @append_space
)

(vtime_statement
  "vtime" @append_space
  ":" @append_space
)

;; ============================================================
;; Declare statements
;; ============================================================

(declare_statement
  "declare" @append_space
)
(verbosity_declaration
  "verbose" @append_space
)
(attribute_declaration
  "attributes" @append_space
  ":" @prepend_antispace @append_space
)
(type_declaration
  "type" @append_space
)
(type_declaration
  ":" @prepend_antispace @append_space
)

;; ============================================================
;; Load, save, and import directives
;; ============================================================

(load_directive
  ["load" "iload"] @append_space
)

(save_directive
  ["save" "restore"] @append_space
)

(import_directive
  "import" @append_space
)

(import_directive
  ":" @append_space
)

;; ============================================================
;; Optional parameter (name := value)
;; ============================================================

(parameters ":" @prepend_input_softline @append_input_softline)
(intrinsic_definition ":" @prepend_input_softline @append_input_softline)

(optional_parameter
  ":=" @prepend_input_softline @append_input_softline
)

;; ============================================================
;; Optional argument at call sites: f(req, req : opt := val, ...)
;; ============================================================

(argument_list
  ":" @prepend_input_softline @append_input_softline
)

(optional_argument
  ":=" @prepend_input_softline @append_input_softline
)

;; ============================================================
;; Typed identifier (x :: Type)
;; ============================================================

(typed_identifier
  "::" @prepend_antispace @append_antispace
)
(ref_typed_identifier
  "~" @append_antispace
  "::" @prepend_antispace @append_antispace
)
(backtick_identifier "`" @append_antispace)

;; ============================================================
;; Ternary operator (cond select x else y)
;; ============================================================

(ternary_operator
  ["select" "else"] @prepend_input_softline @append_input_softline
)

;; ============================================================
;; Return types in intrinsic definitions
;; ============================================================

(intrinsic_definition
  ")" @append_indent_start
  "->" @prepend_input_softline @append_input_softline
  (doc_string) @prepend_indent_end
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
  operator: ["not" "assigned"] @append_input_softline
)

(unary_operator
  operator: ["-" "+" "#" "~"] @append_antispace @append_input_softline
)

;; ============================================================
;; Binary operators
;; ============================================================

;; Keep multiplication, powers, coercion, application, and field access tight:
;; 3*x^2 + a. Input softlines still preserve breaks beside these operators.
(binary_operator
  operator: ["*" "/" "^" "!" "!!" "@" "."] @prepend_antispace @append_antispace
)

(binary_operator
  operator: ["*" "/" "^" "!" "!!" "@" "."] @prepend_input_softline @append_input_softline
)

;; Low/mid precedence, word operators, and inverse application (@@) — spaced.
;; ^^ (group conjugation) is precedence 7 in grammar.js, lower than
;; or/and/comparisons, so it stays spaced.
;; mod/div/cat and the rest are word operators; the lexer requires
;; whitespace so they must stay spaced.
(binary_operator
  operator: ["+" "-" "^^" "@@"
             "mod" "div" "cat"
             "join" "meet" "diff" "sdiff"
             "adj" "notadj" "subset" "notsubset"
             "in" "notin"
             "gt" "lt" "ge" "le" "eq" "ne" "cmpeq" "cmpne"] @prepend_input_softline @append_input_softline
)

(group_relation
  "=" @prepend_input_softline @append_input_softline
)

(boolean_operator
 operator: ["or" "xor" "and"] @prepend_input_softline @append_input_softline)

(reduct_operator
 operator: ["&+" "&-" "&*" "&and" "&or" "&meet" "&join" "&cat"] @prepend_input_softline @append_input_softline)

;; ============================================================
;; Assignment
;; ============================================================

(assignment
 ":=" @prepend_input_softline @append_input_softline
 )

(augmented_assignment
 ["join:="  "meet:="  "diff:="  "sdiff:="  "cat:="  "*:="  "+:="  "-:="  "/:="  "^:="  "div:="  "mod:="  "and:="  "or:="  "xor:="] @prepend_input_softline @append_input_softline
 )

;; ============================================================
;; Expression continuations
;; ============================================================

;; Indent undelimited expressions at statement roots, never recursively at
;; every binary/boolean operator. Lists and calls own their delimiter scopes.
;; Keeping these alternatives explicit avoids indenting a function body or
;; adding a second hanging level to a directly assigned list/call.
(assignment
  right: [
    (identifier) (anonymous_identifier) (integer) (real) (string) (true) (false)
    (binary_operator) (boolean_operator) (unary_operator) (reduct_operator)
    (ternary_operator) (where_expression) (eval_expression) (group_relation)
    (two_tuple) (attribute) (dollar) (double_dollar)
  ] @prepend_indent_start @append_indent_end
)

(augmented_assignment
  right: [
    (identifier) (anonymous_identifier) (integer) (real) (string) (true) (false)
    (binary_operator) (boolean_operator) (unary_operator) (reduct_operator)
    (ternary_operator) (where_expression) (eval_expression) (group_relation)
    (two_tuple) (attribute) (dollar) (double_dollar)
  ] @prepend_indent_start @append_indent_end
)

(return_statement
  [
    (identifier) (anonymous_identifier) (integer) (real) (string) (true) (false)
    (binary_operator) (boolean_operator) (unary_operator) (reduct_operator)
    (ternary_operator) (where_expression) (eval_expression) (group_relation)
    (two_tuple) (attribute) (dollar) (double_dollar)
  ] @prepend_indent_start @append_indent_end
)

(assert_statement
  [
    (identifier) (anonymous_identifier) (integer) (real) (string) (true) (false)
    (binary_operator) (boolean_operator) (unary_operator) (reduct_operator)
    (ternary_operator) (where_expression) (eval_expression) (group_relation)
    (two_tuple) (attribute) (dollar) (double_dollar)
  ] @prepend_indent_start @append_indent_end
)

(require_statement
  [
    (identifier) (anonymous_identifier) (integer) (real) (string) (true) (false)
    (binary_operator) (boolean_operator) (unary_operator) (reduct_operator)
    (ternary_operator) (where_expression) (eval_expression) (group_relation)
    (two_tuple) (attribute) (dollar) (double_dollar)
  ] @prepend_indent_start @append_indent_end
)

(if_statement
  condition: (_) @prepend_indent_start @append_indent_end
)

(elif_clause
  condition: (_) @prepend_indent_start @append_indent_end
)

(while_statement
  condition: (_) @prepend_indent_start @append_indent_end
)

(repeat_statement
  condition: (_) @prepend_indent_start @append_indent_end
)

(case_statement
  matchee: (_) @prepend_indent_start @append_indent_end
)

(when_clause
  match: (_) @prepend_indent_start @append_indent_end
)

(for_statement
  quantifier: (_) @prepend_indent_start @append_indent_end
)

(print_statement
  ["print" "printf" "fprintf"] @append_indent_start
) @append_indent_end

(vprint_statement
  ":" @append_indent_start
) @append_indent_end

(read_statement
  ["read" "readi"] @append_indent_start
) @append_indent_end

(local_statement
  "local" @append_indent_start
) @append_indent_end

(delete
  "delete" @append_indent_start
) @append_indent_end

(forward
  "forward" @append_indent_start
) @append_indent_end

(error_statement
  "error" @append_indent_start
) @append_indent_end

;; A delimited RHS normally supplies its own continuation indentation. If
;; it starts below :=, indent the whole RHS as well. Measure only that gap,
;; so a multiline list starting beside := does not acquire an extra level.
((assignment
   ":=" @prepend_begin_scope @append_begin_measuring_scope
   . (comment)* . right: [(call) (parenthesized_expression) (aggregate) (constructor)
          (recformat_constructor) (case_constructor) (seq_slice)
          (quantified_set) (random_element_of_set) (representative_of_set)
          (cycle_or_commutator_product)] @prepend_end_measuring_scope
   .) @append_end_scope
  (#scope_id! "assignment-rhs"))

((assignment
   ":=" @append_indent_start
   . (comment)* . right: [(call) (parenthesized_expression) (aggregate) (constructor)
          (recformat_constructor) (case_constructor) (seq_slice)
          (quantified_set) (random_element_of_set) (representative_of_set)
          (cycle_or_commutator_product)]
   .) @append_indent_end
  (#multi_line_scope_only! "assignment-rhs"))

;; The same gap measurement applies to a returned call or collection.
((return_statement
   "return" @prepend_begin_scope @append_begin_measuring_scope
   . (comment)* . [(call) (parenthesized_expression) (aggregate) (constructor)
          (recformat_constructor) (case_constructor) (seq_slice)
          (quantified_set) (random_element_of_set) (representative_of_set)
          (cycle_or_commutator_product)] @prepend_end_measuring_scope
   .) @append_end_scope
  (#scope_id! "return-value"))

((return_statement
   "return" @append_indent_start
   . (comment)* . [(call) (parenthesized_expression) (aggregate) (constructor)
          (recformat_constructor) (case_constructor) (seq_slice)
          (quantified_set) (random_element_of_set) (representative_of_set)
          (cycle_or_commutator_product)]
   .) @append_indent_end
  (#multi_line_scope_only! "return-value"))

;; ============================================================
;; Comments
;; ============================================================

;; Line comments must terminate the line; block comments may stay inline.
(comment) @prepend_input_softline @multi_line_indent_all @allow_blank_line_before
((comment) @append_hardline
  (#match? @append_hardline "^//"))
((comment) @append_input_softline
  (#match? @append_input_softline "^/\\*"))
