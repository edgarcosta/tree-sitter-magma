package tree_sitter_magma_test

import (
	"testing"

	tree_sitter "github.com/tree-sitter/go-tree-sitter"
	tree_sitter_magma "github.com/tree-sitter/tree-sitter-magma/bindings/go"
)

func TestCanLoadGrammar(t *testing.T) {
	language := tree_sitter.NewLanguage(tree_sitter_magma.Language())
	if language == nil {
		t.Errorf("Error loading Magma grammar")
	}
}
