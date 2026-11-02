;; Named routines, including nested definitions. Procedures use the standard
;; function category; no separate procedure category is needed by consumers.
(function_definition name: (identifier) @name) @definition.function
(procedure_definition name: (identifier) @name) @definition.function

((intrinsic_definition
  name: (identifier) @name
  docstring: (doc_string) @doc) @definition.function
 (#strip! @doc "^\\{\\s*|\\s*\\};?$"))

;; Require exactly one target and one value. Multiple assignment does not
;; establish which target receives a callable. Unnamed literals have no tag.
(assignment
  . left: (identifier) @name
  . right: [(function_definition !name) (procedure_definition !name)] .)
  @definition.function

;; Match the constructor's prefix: the tags engine accepts only its standard
;; capture names, so a private helper capture for the constructor is not used.
((assignment
   . left: (identifier) @name
   . right: (constructor) @definition.function .)
 (#match? @definition.function "^(func|proc)\\b"))

;; Only the declared type is a definition, not its supertypes or annotations.
(type_declaration (type . (identifier) @name)) @definition.type

;; The repeated `attribute` field query selects only its first element on
;; CLI 0.25.10. Matching identifiers after the colon includes every attribute.
(attribute_declaration ":" (identifier) @name @definition.field)
(recformat_constructor
  (field_definition name: (identifier) @name) @definition.field)
(recformat_constructor (identifier) @name @definition.field)

;; References are syntactic call sites, not resolved bindings. For record
;; attributes, use the final field name, not the object or earlier fields.
(call function: (identifier) @name) @reference.call
(call function: (attribute "`" . (identifier) @name .)) @reference.call

;; Forward declarations, imports, ordinary assignments, and dynamically
;; selected callees are deliberately omitted. These queries do not infer
;; aliases, resolve overloads, or assign qualified names to record fields.
