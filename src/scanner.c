#include "tree_sitter/array.h"
#include "tree_sitter/parser.h"

#include <assert.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <wctype.h>

enum TokenType {
  REAL
};

static inline void advance(TSLexer *lexer) { lexer->advance(lexer, false); }
static inline void skip(TSLexer *lexer) { lexer->advance(lexer, true); }

static inline bool process_real_literal(TSLexer *lexer) {
    lexer->result_symbol = REAL;

    while (iswdigit(lexer->lookahead)) {
        advance(lexer);
    }

    bool has_fraction = false, has_exponent = false, has_prec = false;

    if (lexer->lookahead == '.') {
      has_fraction = true;
      advance(lexer);

      if (lexer->lookahead == '.') {
	return false;		/* in this case we have a range! */
      }

      while (iswdigit(lexer->lookahead)) {
	advance(lexer);
      }
    }
    lexer->mark_end(lexer);
    
    if (lexer->lookahead == 'e' || lexer->lookahead == 'E') {
      has_exponent = true;
      advance(lexer);

      if (lexer->lookahead == '+' || lexer->lookahead == '-') {
	advance(lexer);
      }
      
      if (!iswdigit(lexer->lookahead)) {
	return false;
      }
      
      while (iswdigit(lexer->lookahead)) {
	advance(lexer);
      }
      lexer->mark_end(lexer);
    }
    
    if (lexer->lookahead == 'p' || lexer->lookahead == 'P') {
      has_prec = true;
      advance(lexer);
      if (!iswdigit(lexer->lookahead)) {
	return false;
      }
      while (iswdigit(lexer->lookahead)) {
	advance(lexer);
      }
      lexer->mark_end(lexer);
    }
    
    if (!has_exponent && !has_fraction && !has_prec) {
        return false;
    }
    
    while (iswdigit(lexer->lookahead)) {
      advance(lexer);
    }

    lexer->mark_end(lexer);
    return true;
}

void * tree_sitter_magma_external_scanner_create() {return NULL;}
void tree_sitter_magma_external_scanner_destroy(void *payload) {}

unsigned tree_sitter_magma_external_scanner_serialize(void *payload, char *buffer) {
  return 0;
}
void tree_sitter_magma_external_scanner_deserialize(void *payload, char *buffer) {
  /* return NULL; */
}
  

bool tree_sitter_magma_external_scanner_scan(void *payload,
					     TSLexer *lexer,
					     const bool *valid_symbols) {
  /* ignore whitespace */
  while (iswspace(lexer->lookahead)) {
        skip(lexer);
  }

  if (valid_symbols[REAL] && iswdigit(lexer->lookahead)) {
    return process_real_literal(lexer);
  }
  return false;
}


