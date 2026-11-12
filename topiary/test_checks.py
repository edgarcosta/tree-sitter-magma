"""Regression checks for the syntax-preservation check itself."""

import unittest

from checks import syntax_signature


class SyntaxSignatureTests(unittest.TestCase):
    def test_formatting_preserves_signature(self):
        self.assertEqual(
            syntax_signature(b'x:=f("a b",1);'),
            syntax_signature(b'x := f(\n    "a b",\n    1\n);\n'),
        )
        self.assertEqual(syntax_signature(b"f(  );"), syntax_signature(b"f();\n"))
        self.assertEqual(syntax_signature(b" \n"), syntax_signature(b""))

    def test_changed_contents_are_detected(self):
        for before, after in [
            (b"x := a;", b"x := b;"),
            (b"x := 1;", b"x := 2;"),
            (b'x := "a b";', b'x := "ab";'),
            (b"x := a + b;", b"x := a - b;"),
            (b"// hello\nx := 1;", b"// goodbye\nx := 1;"),
        ]:
            with self.subTest(before=before):
                self.assertNotEqual(syntax_signature(before), syntax_signature(after))

    def test_tree_hierarchy_is_significant(self):
        # Same depth-first sequence of named node kinds, different grouping.
        self.assertNotEqual(
            syntax_signature(b"x := f(g(a), b);"),
            syntax_signature(b"x := f(g(a, b));"),
        )

    def test_random_loop_regression_is_detected(self):
        self.assertNotEqual(
            syntax_signature(b"for random i in S do print i; end for;"),
            syntax_signature(b"for randomiinS do print i; end for;"),
        )

    def test_comment_indentation_can_change(self):
        self.assertEqual(
            syntax_signature(b"function F()\n/* A\n   B\n*/\nreturn 1;\nend function;"),
            syntax_signature(b"function F()\n    /* A\n       B\n    */\n    return 1;\nend function;"),
        )

    def test_invalid_input_is_rejected(self):
        with self.assertRaises(ValueError):
            syntax_signature(b"x := ;")


if __name__ == "__main__":
    unittest.main()
