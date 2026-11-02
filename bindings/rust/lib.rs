//! This crate provides Magma language support for the [tree-sitter][] parsing library.
//!
//! Typically, you will use the [language][language func] function to add this language to a
//! tree-sitter [Parser][], and then use the parser to parse some code:
//!
//! ```
//! let code = r#"
//! "#;
//! let mut parser = tree_sitter::Parser::new();
//! let language = tree_sitter_magma::LANGUAGE;
//! parser
//!     .set_language(&language.into())
//!     .expect("Error loading Magma parser");
//! let tree = parser.parse(code, None).unwrap();
//! assert!(!tree.root_node().has_error());
//! ```
//!
//! [Language]: https://docs.rs/tree-sitter/*/tree_sitter/struct.Language.html
//! [language func]: fn.language.html
//! [Parser]: https://docs.rs/tree-sitter/*/tree_sitter/struct.Parser.html
//! [tree-sitter]: https://tree-sitter.github.io/

use tree_sitter_language::LanguageFn;

extern "C" {
    fn tree_sitter_magma() -> *const ();
}

/// The tree-sitter [`LanguageFn`] for this grammar.
pub const LANGUAGE: LanguageFn = unsafe { LanguageFn::from_raw(tree_sitter_magma) };

/// The content of the [`node-types.json`][] file for this grammar.
///
/// [`node-types.json`]: https://tree-sitter.github.io/tree-sitter/using-parsers#static-node-types
pub const NODE_TYPES: &str = include_str!("../../src/node-types.json");

// NOTE: uncomment these to include any queries that this grammar contains:

// pub const HIGHLIGHTS_QUERY: &str = include_str!("../../queries/highlights.scm");
// pub const INJECTIONS_QUERY: &str = include_str!("../../queries/injections.scm");
// pub const LOCALS_QUERY: &str = include_str!("../../queries/locals.scm");
/// Symbol definitions and call references for code navigation.
pub const TAGS_QUERY: &str = include_str!("../../queries/tags.scm");

#[cfg(test)]
mod tests {
    use tree_sitter::StreamingIterator;

    #[test]
    fn test_can_load_grammar() {
        let mut parser = tree_sitter::Parser::new();
        parser
            .set_language(&super::LANGUAGE.into())
            .expect("Error loading Magma parser");
        let tree = parser
            .parse("R<x> := PolynomialRing(Rationals());\ny := 0.5;\n", None)
            .expect("Error parsing Magma");
        assert!(!tree.root_node().has_error());
        assert!(tree.root_node().to_sexp().contains("(real)"));
    }

    #[test]
    fn test_tags_select_names_without_false_definitions() {
        let source = r#"
declare type Widget: Parent;
declare type GrpPSL2[GrpPSL2Elt]: Parent;
declare attributes Widget: first, second, third;
format := recformat<typed: RngIntElt, bare, other: MonStgElt>;
inline := func<x | x>;
action := proc<~x | Change(~x)>;
closure := function(x) return x; end function;
change := procedure(~x) x := 1; end procedure;
object`child`action(1);
forward Pending;
import "other.m": Imported;
ordinary := 1;
alias := inline;
record := rec<format | bare := 1>;
mapping := map<domain -> codomain | x :-> x>;
fake := functional<x | x>;
left, right := func<x | x>, 1;
single := func<x | x>, 1;
handlers[1](2);
"#;
        let language = super::LANGUAGE.into();
        let query = tree_sitter::Query::new(&language, super::TAGS_QUERY).unwrap();
        let mut parser = tree_sitter::Parser::new();
        parser.set_language(&language).unwrap();
        let tree = parser.parse(source, None).unwrap();
        assert!(!tree.root_node().has_error());
        let mut cursor = tree_sitter::QueryCursor::new();
        let mut matches = cursor.matches(&query, tree.root_node(), source.as_bytes());
        let mut symbols = Vec::new();
        while let Some(matched) = matches.next() {
            let name = matched
                .captures
                .iter()
                .find(|capture| query.capture_names()[capture.index as usize] == "name")
                .unwrap();
            let role = matched
                .captures
                .iter()
                .map(|capture| query.capture_names()[capture.index as usize])
                .find(|role| role.starts_with("definition.") || role.starts_with("reference."))
                .unwrap();
            symbols.push((name.node.utf8_text(source.as_bytes()).unwrap(), role));
        }
        assert_eq!(
            symbols,
            vec![
                ("Widget", "definition.type"),
                ("GrpPSL2", "definition.type"),
                ("first", "definition.field"),
                ("second", "definition.field"),
                ("third", "definition.field"),
                ("typed", "definition.field"),
                ("bare", "definition.field"),
                ("other", "definition.field"),
                ("inline", "definition.function"),
                ("action", "definition.function"),
                ("Change", "reference.call"),
                ("closure", "definition.function"),
                ("change", "definition.function"),
                ("action", "reference.call"),
            ]
        );
    }
}
