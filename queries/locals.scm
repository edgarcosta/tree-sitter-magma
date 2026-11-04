;; Keep this file free of captures. Magma comprehensions and `where` clauses
;; use names before their bindings, which tree-sitter-highlight's source-order
;; resolver cannot reliably resolve; an empty query makes automatic discovery
;; match consumers that load only highlights.scm.
