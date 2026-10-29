;; Highlighting deliberately uses syntactic roles, without local-reference
;; propagation. Parameter declarations are @variable.parameter; expressions
;; are @variable and callees are @function, regardless of an outer binding.
;;
;; Magma comprehensions and `where` introduce names after their uses. The
;; source-order resolver in tree-sitter-highlight cannot resolve these reliably.
;; Keep this file empty of captures so automatic discovery has the same behavior
;; as consumers loading only highlights.scm. Semantic name resolution belongs
;; in language tooling, not this highlighting query.
