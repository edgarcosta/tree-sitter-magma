const assert = require("node:assert");
const { test } = require("node:test");

const Parser = require("tree-sitter");

test("can parse Magma with the packaged grammar and scanner", () => {
  const parser = new Parser();
  parser.setLanguage(require("."));
  const tree = parser.parse("R<x> := PolynomialRing(Rationals());\ny := 0.5;\n");
  assert.equal(tree.rootNode.hasError, false);
  assert.match(tree.rootNode.toString(), /\(real\)/);
});
