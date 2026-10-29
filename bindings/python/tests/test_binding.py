from unittest import TestCase

import tree_sitter
import tree_sitter_magma


class TestLanguage(TestCase):
    def test_can_parse_with_external_scanner(self):
        language = tree_sitter.Language(tree_sitter_magma.language())
        parser = tree_sitter.Parser(language)
        tree = parser.parse(b"R<x> := PolynomialRing(Rationals());\ny := 0.5;\n")
        self.assertFalse(tree.root_node.has_error)
        self.assertIn("(real)", str(tree.root_node))
