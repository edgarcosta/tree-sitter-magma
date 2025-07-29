# Magma Grammar Documentation

This folder contains extracted grammar and structural information from the Magma parser for use in developing a tree-sitter grammar.

## Files

- `tokens.md` - Token definitions and lexical elements
- `grammar-rules.md` - Production rules and syntax structure  
- `precedence.md` - Operator precedence and associativity
- `language-constructs.md` - High-level language features
- `examples.md` - Sample code patterns and constructs
- `notes.md` - Implementation notes and observations

## Usage

This documentation is extracted from `parser.y` and related files, with C implementation details removed to focus on the pure grammar structure needed for tree-sitter.

## Grammar Overview

Magma appears to be a mathematical computation language with:
- Rich type system including algebraic structures
- Multiple constructor syntaxes (sets, sequences, tuples, maps)
- Function and procedure definitions
- Control flow constructs (if/then/else, for, while, etc.)
- Mathematical operators and operations
- Intrinsic function definitions
- Package/module system

## Parser Note

The original parser file notes: "Expect 1 shift/reduce conflict. [commutator/function call]" 