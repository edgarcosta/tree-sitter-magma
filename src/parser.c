#include <tree_sitter/parser.h>

#if defined(__GNUC__) || defined(__clang__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wmissing-field-initializers"
#endif

#ifdef _MSC_VER
#pragma optimize("", off)
#elif defined(__clang__)
#pragma clang optimize off
#elif defined(__GNUC__)
#pragma GCC optimize ("O0")
#endif

#define LANGUAGE_VERSION 14
#define STATE_COUNT 228
#define LARGE_STATE_COUNT 2
#define SYMBOL_COUNT 131
#define ALIAS_COUNT 0
#define TOKEN_COUNT 86
#define EXTERNAL_TOKEN_COUNT 0
#define FIELD_COUNT 17
#define MAX_ALIAS_SEQUENCE_LENGTH 10
#define PRODUCTION_ID_COUNT 24

enum {
  anon_sym_SLASH_SLASH = 1,
  aux_sym_comment_token1 = 2,
  anon_sym_SLASH_STAR = 3,
  aux_sym_comment_token2 = 4,
  anon_sym_SLASH = 5,
  anon_sym_SEMI = 6,
  anon_sym_COMMA = 7,
  anon_sym_return = 8,
  anon_sym_break = 9,
  anon_sym_continue = 10,
  anon_sym_eval = 11,
  anon_sym_print = 12,
  anon_sym_not = 13,
  anon_sym_DASH = 14,
  anon_sym_TILDE = 15,
  anon_sym_PLUS = 16,
  anon_sym_STAR = 17,
  anon_sym_CARET = 18,
  anon_sym_div = 19,
  anon_sym_mod = 20,
  anon_sym_CARET_CARET = 21,
  anon_sym_join = 22,
  anon_sym_diff = 23,
  anon_sym_sdiff = 24,
  anon_sym_meet = 25,
  anon_sym_cat = 26,
  anon_sym_select = 27,
  anon_sym_else = 28,
  anon_sym_gt = 29,
  anon_sym_ge = 30,
  anon_sym_lt = 31,
  anon_sym_le = 32,
  anon_sym_eq = 33,
  anon_sym_ne = 34,
  anon_sym_cmpeq = 35,
  anon_sym_cmpne = 36,
  anon_sym_or = 37,
  anon_sym_xor = 38,
  anon_sym_and = 39,
  anon_sym_LPAREN = 40,
  anon_sym_RPAREN = 41,
  sym_true = 42,
  sym_false = 43,
  sym_expression_list = 44,
  anon_sym_function = 45,
  anon_sym_endfunction = 46,
  anon_sym_procedure = 47,
  anon_sym_endprocedure = 48,
  anon_sym_intrinsic = 49,
  anon_sym_DASH_GT = 50,
  anon_sym_LBRACE = 51,
  aux_sym_intrinsic_definition_token1 = 52,
  anon_sym_RBRACE = 53,
  anon_sym_endintrinsic = 54,
  anon_sym_COLON_EQ = 55,
  anon_sym_PLUS_COLON_EQ = 56,
  anon_sym_DASH_COLON_EQ = 57,
  anon_sym_STAR_COLON_EQ = 58,
  anon_sym_SLASH_COLON_EQ = 59,
  anon_sym_and_COLON_EQ = 60,
  anon_sym_or_COLON_EQ = 61,
  anon_sym_div_COLON_EQ = 62,
  anon_sym__ = 63,
  anon_sym_LT = 64,
  anon_sym_GT = 65,
  anon_sym_DOT = 66,
  anon_sym_COLON_COLON = 67,
  anon_sym_if = 68,
  anon_sym_then = 69,
  anon_sym_endif = 70,
  anon_sym_elif = 71,
  sym_for_statement = 72,
  anon_sym_while = 73,
  anon_sym_do = 74,
  anon_sym_endwhile = 75,
  anon_sym_repeat = 76,
  anon_sym_until = 77,
  anon_sym_case = 78,
  anon_sym_COLON = 79,
  anon_sym_endcase = 80,
  anon_sym_when = 81,
  sym_identifier = 82,
  sym_string = 83,
  sym_integer = 84,
  sym_real = 85,
  sym_program = 86,
  sym_comment = 87,
  sym__statement = 88,
  sym_expression_statement = 89,
  sym_return_statement = 90,
  sym_break_statement = 91,
  sym_continue_statement = 92,
  sym_eval_statement = 93,
  sym_print_statement = 94,
  sym_unary_operator = 95,
  sym_binary_operator = 96,
  sym_ternary_operator = 97,
  sym_comparison_operator = 98,
  sym_boolean_operator = 99,
  sym_expression = 100,
  sym_parenthesized_expression = 101,
  sym_primary_expression = 102,
  sym__definition = 103,
  sym_function_definition = 104,
  sym_procedure_definition = 105,
  sym_intrinsic_definition = 106,
  sym_call = 107,
  sym_argument_list = 108,
  sym__assignment = 109,
  sym_assignment = 110,
  sym_augmented_assignment = 111,
  sym__right_hand_side = 112,
  sym_gen_expression = 113,
  sym_type = 114,
  sym_if_statement = 115,
  sym_elif_clause = 116,
  sym_else_clause = 117,
  sym_while_statement = 118,
  sym_repeat_statement = 119,
  sym_case_statement = 120,
  sym_when_clause = 121,
  sym_block = 122,
  aux_sym_program_repeat1 = 123,
  aux_sym_expression_statement_repeat1 = 124,
  aux_sym_print_statement_repeat1 = 125,
  aux_sym__left_hand_side_repeat1 = 126,
  aux_sym_gen_expression_repeat1 = 127,
  aux_sym_if_statement_repeat1 = 128,
  aux_sym_case_statement_repeat1 = 129,
  aux_sym_block_repeat1 = 130,
};

static const char * const ts_symbol_names[] = {
  [ts_builtin_sym_end] = "end",
  [anon_sym_SLASH_SLASH] = "//",
  [aux_sym_comment_token1] = "comment_token1",
  [anon_sym_SLASH_STAR] = "/*",
  [aux_sym_comment_token2] = "comment_token2",
  [anon_sym_SLASH] = "/",
  [anon_sym_SEMI] = ";",
  [anon_sym_COMMA] = ",",
  [anon_sym_return] = "return",
  [anon_sym_break] = "break",
  [anon_sym_continue] = "continue",
  [anon_sym_eval] = "eval",
  [anon_sym_print] = "print",
  [anon_sym_not] = "not",
  [anon_sym_DASH] = "-",
  [anon_sym_TILDE] = "~",
  [anon_sym_PLUS] = "+",
  [anon_sym_STAR] = "*",
  [anon_sym_CARET] = "^",
  [anon_sym_div] = "div",
  [anon_sym_mod] = "mod",
  [anon_sym_CARET_CARET] = "^^",
  [anon_sym_join] = "join",
  [anon_sym_diff] = "diff",
  [anon_sym_sdiff] = "sdiff",
  [anon_sym_meet] = "meet",
  [anon_sym_cat] = "cat",
  [anon_sym_select] = "select",
  [anon_sym_else] = "else",
  [anon_sym_gt] = "gt",
  [anon_sym_ge] = "ge",
  [anon_sym_lt] = "lt",
  [anon_sym_le] = "le",
  [anon_sym_eq] = "eq",
  [anon_sym_ne] = "ne",
  [anon_sym_cmpeq] = "cmpeq",
  [anon_sym_cmpne] = "cmpne",
  [anon_sym_or] = "or",
  [anon_sym_xor] = "xor",
  [anon_sym_and] = "and",
  [anon_sym_LPAREN] = "(",
  [anon_sym_RPAREN] = ")",
  [sym_true] = "true",
  [sym_false] = "false",
  [sym_expression_list] = "expression_list",
  [anon_sym_function] = "function",
  [anon_sym_endfunction] = "end function",
  [anon_sym_procedure] = "procedure",
  [anon_sym_endprocedure] = "end procedure",
  [anon_sym_intrinsic] = "intrinsic",
  [anon_sym_DASH_GT] = "->",
  [anon_sym_LBRACE] = "{",
  [aux_sym_intrinsic_definition_token1] = "intrinsic_definition_token1",
  [anon_sym_RBRACE] = "}",
  [anon_sym_endintrinsic] = "end intrinsic",
  [anon_sym_COLON_EQ] = ":=",
  [anon_sym_PLUS_COLON_EQ] = "+:=",
  [anon_sym_DASH_COLON_EQ] = "-:=",
  [anon_sym_STAR_COLON_EQ] = "*:=",
  [anon_sym_SLASH_COLON_EQ] = "/:=",
  [anon_sym_and_COLON_EQ] = "and:=",
  [anon_sym_or_COLON_EQ] = "or:=",
  [anon_sym_div_COLON_EQ] = "div:=",
  [anon_sym__] = "_",
  [anon_sym_LT] = "<",
  [anon_sym_GT] = ">",
  [anon_sym_DOT] = ".",
  [anon_sym_COLON_COLON] = "::",
  [anon_sym_if] = "if",
  [anon_sym_then] = "then",
  [anon_sym_endif] = "end if",
  [anon_sym_elif] = "elif",
  [sym_for_statement] = "for_statement",
  [anon_sym_while] = "while",
  [anon_sym_do] = "do",
  [anon_sym_endwhile] = "end while",
  [anon_sym_repeat] = "repeat",
  [anon_sym_until] = "until",
  [anon_sym_case] = "case",
  [anon_sym_COLON] = ":",
  [anon_sym_endcase] = "end case",
  [anon_sym_when] = "when",
  [sym_identifier] = "identifier",
  [sym_string] = "string",
  [sym_integer] = "integer",
  [sym_real] = "real",
  [sym_program] = "program",
  [sym_comment] = "comment",
  [sym__statement] = "_statement",
  [sym_expression_statement] = "expression_statement",
  [sym_return_statement] = "return_statement",
  [sym_break_statement] = "break_statement",
  [sym_continue_statement] = "continue_statement",
  [sym_eval_statement] = "eval_statement",
  [sym_print_statement] = "print_statement",
  [sym_unary_operator] = "unary_operator",
  [sym_binary_operator] = "binary_operator",
  [sym_ternary_operator] = "ternary_operator",
  [sym_comparison_operator] = "comparison_operator",
  [sym_boolean_operator] = "boolean_operator",
  [sym_expression] = "expression",
  [sym_parenthesized_expression] = "parenthesized_expression",
  [sym_primary_expression] = "primary_expression",
  [sym__definition] = "_definition",
  [sym_function_definition] = "function_definition",
  [sym_procedure_definition] = "procedure_definition",
  [sym_intrinsic_definition] = "intrinsic_definition",
  [sym_call] = "call",
  [sym_argument_list] = "argument_list",
  [sym__assignment] = "_assignment",
  [sym_assignment] = "assignment",
  [sym_augmented_assignment] = "augmented_assignment",
  [sym__right_hand_side] = "_right_hand_side",
  [sym_gen_expression] = "gen_expression",
  [sym_type] = "type",
  [sym_if_statement] = "if_statement",
  [sym_elif_clause] = "elif_clause",
  [sym_else_clause] = "else_clause",
  [sym_while_statement] = "while_statement",
  [sym_repeat_statement] = "repeat_statement",
  [sym_case_statement] = "case_statement",
  [sym_when_clause] = "when_clause",
  [sym_block] = "block",
  [aux_sym_program_repeat1] = "program_repeat1",
  [aux_sym_expression_statement_repeat1] = "expression_statement_repeat1",
  [aux_sym_print_statement_repeat1] = "print_statement_repeat1",
  [aux_sym__left_hand_side_repeat1] = "_left_hand_side_repeat1",
  [aux_sym_gen_expression_repeat1] = "gen_expression_repeat1",
  [aux_sym_if_statement_repeat1] = "if_statement_repeat1",
  [aux_sym_case_statement_repeat1] = "case_statement_repeat1",
  [aux_sym_block_repeat1] = "block_repeat1",
};

static const TSSymbol ts_symbol_map[] = {
  [ts_builtin_sym_end] = ts_builtin_sym_end,
  [anon_sym_SLASH_SLASH] = anon_sym_SLASH_SLASH,
  [aux_sym_comment_token1] = aux_sym_comment_token1,
  [anon_sym_SLASH_STAR] = anon_sym_SLASH_STAR,
  [aux_sym_comment_token2] = aux_sym_comment_token2,
  [anon_sym_SLASH] = anon_sym_SLASH,
  [anon_sym_SEMI] = anon_sym_SEMI,
  [anon_sym_COMMA] = anon_sym_COMMA,
  [anon_sym_return] = anon_sym_return,
  [anon_sym_break] = anon_sym_break,
  [anon_sym_continue] = anon_sym_continue,
  [anon_sym_eval] = anon_sym_eval,
  [anon_sym_print] = anon_sym_print,
  [anon_sym_not] = anon_sym_not,
  [anon_sym_DASH] = anon_sym_DASH,
  [anon_sym_TILDE] = anon_sym_TILDE,
  [anon_sym_PLUS] = anon_sym_PLUS,
  [anon_sym_STAR] = anon_sym_STAR,
  [anon_sym_CARET] = anon_sym_CARET,
  [anon_sym_div] = anon_sym_div,
  [anon_sym_mod] = anon_sym_mod,
  [anon_sym_CARET_CARET] = anon_sym_CARET_CARET,
  [anon_sym_join] = anon_sym_join,
  [anon_sym_diff] = anon_sym_diff,
  [anon_sym_sdiff] = anon_sym_sdiff,
  [anon_sym_meet] = anon_sym_meet,
  [anon_sym_cat] = anon_sym_cat,
  [anon_sym_select] = anon_sym_select,
  [anon_sym_else] = anon_sym_else,
  [anon_sym_gt] = anon_sym_gt,
  [anon_sym_ge] = anon_sym_ge,
  [anon_sym_lt] = anon_sym_lt,
  [anon_sym_le] = anon_sym_le,
  [anon_sym_eq] = anon_sym_eq,
  [anon_sym_ne] = anon_sym_ne,
  [anon_sym_cmpeq] = anon_sym_cmpeq,
  [anon_sym_cmpne] = anon_sym_cmpne,
  [anon_sym_or] = anon_sym_or,
  [anon_sym_xor] = anon_sym_xor,
  [anon_sym_and] = anon_sym_and,
  [anon_sym_LPAREN] = anon_sym_LPAREN,
  [anon_sym_RPAREN] = anon_sym_RPAREN,
  [sym_true] = sym_true,
  [sym_false] = sym_false,
  [sym_expression_list] = sym_expression_list,
  [anon_sym_function] = anon_sym_function,
  [anon_sym_endfunction] = anon_sym_endfunction,
  [anon_sym_procedure] = anon_sym_procedure,
  [anon_sym_endprocedure] = anon_sym_endprocedure,
  [anon_sym_intrinsic] = anon_sym_intrinsic,
  [anon_sym_DASH_GT] = anon_sym_DASH_GT,
  [anon_sym_LBRACE] = anon_sym_LBRACE,
  [aux_sym_intrinsic_definition_token1] = aux_sym_intrinsic_definition_token1,
  [anon_sym_RBRACE] = anon_sym_RBRACE,
  [anon_sym_endintrinsic] = anon_sym_endintrinsic,
  [anon_sym_COLON_EQ] = anon_sym_COLON_EQ,
  [anon_sym_PLUS_COLON_EQ] = anon_sym_PLUS_COLON_EQ,
  [anon_sym_DASH_COLON_EQ] = anon_sym_DASH_COLON_EQ,
  [anon_sym_STAR_COLON_EQ] = anon_sym_STAR_COLON_EQ,
  [anon_sym_SLASH_COLON_EQ] = anon_sym_SLASH_COLON_EQ,
  [anon_sym_and_COLON_EQ] = anon_sym_and_COLON_EQ,
  [anon_sym_or_COLON_EQ] = anon_sym_or_COLON_EQ,
  [anon_sym_div_COLON_EQ] = anon_sym_div_COLON_EQ,
  [anon_sym__] = anon_sym__,
  [anon_sym_LT] = anon_sym_LT,
  [anon_sym_GT] = anon_sym_GT,
  [anon_sym_DOT] = anon_sym_DOT,
  [anon_sym_COLON_COLON] = anon_sym_COLON_COLON,
  [anon_sym_if] = anon_sym_if,
  [anon_sym_then] = anon_sym_then,
  [anon_sym_endif] = anon_sym_endif,
  [anon_sym_elif] = anon_sym_elif,
  [sym_for_statement] = sym_for_statement,
  [anon_sym_while] = anon_sym_while,
  [anon_sym_do] = anon_sym_do,
  [anon_sym_endwhile] = anon_sym_endwhile,
  [anon_sym_repeat] = anon_sym_repeat,
  [anon_sym_until] = anon_sym_until,
  [anon_sym_case] = anon_sym_case,
  [anon_sym_COLON] = anon_sym_COLON,
  [anon_sym_endcase] = anon_sym_endcase,
  [anon_sym_when] = anon_sym_when,
  [sym_identifier] = sym_identifier,
  [sym_string] = sym_string,
  [sym_integer] = sym_integer,
  [sym_real] = sym_real,
  [sym_program] = sym_program,
  [sym_comment] = sym_comment,
  [sym__statement] = sym__statement,
  [sym_expression_statement] = sym_expression_statement,
  [sym_return_statement] = sym_return_statement,
  [sym_break_statement] = sym_break_statement,
  [sym_continue_statement] = sym_continue_statement,
  [sym_eval_statement] = sym_eval_statement,
  [sym_print_statement] = sym_print_statement,
  [sym_unary_operator] = sym_unary_operator,
  [sym_binary_operator] = sym_binary_operator,
  [sym_ternary_operator] = sym_ternary_operator,
  [sym_comparison_operator] = sym_comparison_operator,
  [sym_boolean_operator] = sym_boolean_operator,
  [sym_expression] = sym_expression,
  [sym_parenthesized_expression] = sym_parenthesized_expression,
  [sym_primary_expression] = sym_primary_expression,
  [sym__definition] = sym__definition,
  [sym_function_definition] = sym_function_definition,
  [sym_procedure_definition] = sym_procedure_definition,
  [sym_intrinsic_definition] = sym_intrinsic_definition,
  [sym_call] = sym_call,
  [sym_argument_list] = sym_argument_list,
  [sym__assignment] = sym__assignment,
  [sym_assignment] = sym_assignment,
  [sym_augmented_assignment] = sym_augmented_assignment,
  [sym__right_hand_side] = sym__right_hand_side,
  [sym_gen_expression] = sym_gen_expression,
  [sym_type] = sym_type,
  [sym_if_statement] = sym_if_statement,
  [sym_elif_clause] = sym_elif_clause,
  [sym_else_clause] = sym_else_clause,
  [sym_while_statement] = sym_while_statement,
  [sym_repeat_statement] = sym_repeat_statement,
  [sym_case_statement] = sym_case_statement,
  [sym_when_clause] = sym_when_clause,
  [sym_block] = sym_block,
  [aux_sym_program_repeat1] = aux_sym_program_repeat1,
  [aux_sym_expression_statement_repeat1] = aux_sym_expression_statement_repeat1,
  [aux_sym_print_statement_repeat1] = aux_sym_print_statement_repeat1,
  [aux_sym__left_hand_side_repeat1] = aux_sym__left_hand_side_repeat1,
  [aux_sym_gen_expression_repeat1] = aux_sym_gen_expression_repeat1,
  [aux_sym_if_statement_repeat1] = aux_sym_if_statement_repeat1,
  [aux_sym_case_statement_repeat1] = aux_sym_case_statement_repeat1,
  [aux_sym_block_repeat1] = aux_sym_block_repeat1,
};

static const TSSymbolMetadata ts_symbol_metadata[] = {
  [ts_builtin_sym_end] = {
    .visible = false,
    .named = true,
  },
  [anon_sym_SLASH_SLASH] = {
    .visible = true,
    .named = false,
  },
  [aux_sym_comment_token1] = {
    .visible = false,
    .named = false,
  },
  [anon_sym_SLASH_STAR] = {
    .visible = true,
    .named = false,
  },
  [aux_sym_comment_token2] = {
    .visible = false,
    .named = false,
  },
  [anon_sym_SLASH] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_SEMI] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_COMMA] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_return] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_break] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_continue] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_eval] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_print] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_not] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_DASH] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_TILDE] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_PLUS] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_STAR] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_CARET] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_div] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_mod] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_CARET_CARET] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_join] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_diff] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_sdiff] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_meet] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_cat] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_select] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_else] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_gt] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_ge] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_lt] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_le] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_eq] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_ne] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_cmpeq] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_cmpne] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_or] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_xor] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_and] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_LPAREN] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_RPAREN] = {
    .visible = true,
    .named = false,
  },
  [sym_true] = {
    .visible = true,
    .named = true,
  },
  [sym_false] = {
    .visible = true,
    .named = true,
  },
  [sym_expression_list] = {
    .visible = true,
    .named = true,
  },
  [anon_sym_function] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_endfunction] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_procedure] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_endprocedure] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_intrinsic] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_DASH_GT] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_LBRACE] = {
    .visible = true,
    .named = false,
  },
  [aux_sym_intrinsic_definition_token1] = {
    .visible = false,
    .named = false,
  },
  [anon_sym_RBRACE] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_endintrinsic] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_COLON_EQ] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_PLUS_COLON_EQ] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_DASH_COLON_EQ] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_STAR_COLON_EQ] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_SLASH_COLON_EQ] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_and_COLON_EQ] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_or_COLON_EQ] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_div_COLON_EQ] = {
    .visible = true,
    .named = false,
  },
  [anon_sym__] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_LT] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_GT] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_DOT] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_COLON_COLON] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_if] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_then] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_endif] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_elif] = {
    .visible = true,
    .named = false,
  },
  [sym_for_statement] = {
    .visible = true,
    .named = true,
  },
  [anon_sym_while] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_do] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_endwhile] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_repeat] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_until] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_case] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_COLON] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_endcase] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_when] = {
    .visible = true,
    .named = false,
  },
  [sym_identifier] = {
    .visible = true,
    .named = true,
  },
  [sym_string] = {
    .visible = true,
    .named = true,
  },
  [sym_integer] = {
    .visible = true,
    .named = true,
  },
  [sym_real] = {
    .visible = true,
    .named = true,
  },
  [sym_program] = {
    .visible = true,
    .named = true,
  },
  [sym_comment] = {
    .visible = true,
    .named = true,
  },
  [sym__statement] = {
    .visible = false,
    .named = true,
  },
  [sym_expression_statement] = {
    .visible = true,
    .named = true,
  },
  [sym_return_statement] = {
    .visible = true,
    .named = true,
  },
  [sym_break_statement] = {
    .visible = true,
    .named = true,
  },
  [sym_continue_statement] = {
    .visible = true,
    .named = true,
  },
  [sym_eval_statement] = {
    .visible = true,
    .named = true,
  },
  [sym_print_statement] = {
    .visible = true,
    .named = true,
  },
  [sym_unary_operator] = {
    .visible = true,
    .named = true,
  },
  [sym_binary_operator] = {
    .visible = true,
    .named = true,
  },
  [sym_ternary_operator] = {
    .visible = true,
    .named = true,
  },
  [sym_comparison_operator] = {
    .visible = true,
    .named = true,
  },
  [sym_boolean_operator] = {
    .visible = true,
    .named = true,
  },
  [sym_expression] = {
    .visible = false,
    .named = true,
    .supertype = true,
  },
  [sym_parenthesized_expression] = {
    .visible = true,
    .named = true,
  },
  [sym_primary_expression] = {
    .visible = false,
    .named = true,
    .supertype = true,
  },
  [sym__definition] = {
    .visible = false,
    .named = true,
  },
  [sym_function_definition] = {
    .visible = true,
    .named = true,
  },
  [sym_procedure_definition] = {
    .visible = true,
    .named = true,
  },
  [sym_intrinsic_definition] = {
    .visible = true,
    .named = true,
  },
  [sym_call] = {
    .visible = true,
    .named = true,
  },
  [sym_argument_list] = {
    .visible = true,
    .named = true,
  },
  [sym__assignment] = {
    .visible = false,
    .named = true,
  },
  [sym_assignment] = {
    .visible = true,
    .named = true,
  },
  [sym_augmented_assignment] = {
    .visible = true,
    .named = true,
  },
  [sym__right_hand_side] = {
    .visible = false,
    .named = true,
  },
  [sym_gen_expression] = {
    .visible = true,
    .named = true,
  },
  [sym_type] = {
    .visible = true,
    .named = true,
  },
  [sym_if_statement] = {
    .visible = true,
    .named = true,
  },
  [sym_elif_clause] = {
    .visible = true,
    .named = true,
  },
  [sym_else_clause] = {
    .visible = true,
    .named = true,
  },
  [sym_while_statement] = {
    .visible = true,
    .named = true,
  },
  [sym_repeat_statement] = {
    .visible = true,
    .named = true,
  },
  [sym_case_statement] = {
    .visible = true,
    .named = true,
  },
  [sym_when_clause] = {
    .visible = true,
    .named = true,
  },
  [sym_block] = {
    .visible = true,
    .named = true,
  },
  [aux_sym_program_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_expression_statement_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_print_statement_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym__left_hand_side_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_gen_expression_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_if_statement_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_case_statement_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_block_repeat1] = {
    .visible = false,
    .named = false,
  },
};

enum {
  field_alternative = 1,
  field_arguments = 2,
  field_body = 3,
  field_condition = 4,
  field_conditional = 5,
  field_consequence = 6,
  field_docstring = 7,
  field_else = 8,
  field_function = 9,
  field_left = 10,
  field_match = 11,
  field_matchee = 12,
  field_name = 13,
  field_operator = 14,
  field_return_type = 15,
  field_right = 16,
  field_then = 17,
};

static const char * const ts_field_names[] = {
  [0] = NULL,
  [field_alternative] = "alternative",
  [field_arguments] = "arguments",
  [field_body] = "body",
  [field_condition] = "condition",
  [field_conditional] = "conditional",
  [field_consequence] = "consequence",
  [field_docstring] = "docstring",
  [field_else] = "else",
  [field_function] = "function",
  [field_left] = "left",
  [field_match] = "match",
  [field_matchee] = "matchee",
  [field_name] = "name",
  [field_operator] = "operator",
  [field_return_type] = "return_type",
  [field_right] = "right",
  [field_then] = "then",
};

static const TSFieldMapSlice ts_field_map_slices[PRODUCTION_ID_COUNT] = {
  [1] = {.index = 0, .length = 2},
  [2] = {.index = 2, .length = 2},
  [3] = {.index = 4, .length = 2},
  [4] = {.index = 6, .length = 3},
  [5] = {.index = 9, .length = 2},
  [6] = {.index = 11, .length = 3},
  [7] = {.index = 14, .length = 2},
  [8] = {.index = 16, .length = 3},
  [9] = {.index = 19, .length = 2},
  [10] = {.index = 21, .length = 1},
  [11] = {.index = 22, .length = 2},
  [12] = {.index = 24, .length = 1},
  [13] = {.index = 25, .length = 3},
  [14] = {.index = 28, .length = 1},
  [15] = {.index = 29, .length = 3},
  [16] = {.index = 32, .length = 3},
  [17] = {.index = 35, .length = 2},
  [18] = {.index = 37, .length = 4},
  [19] = {.index = 41, .length = 2},
  [20] = {.index = 43, .length = 5},
  [21] = {.index = 48, .length = 6},
  [22] = {.index = 54, .length = 6},
  [23] = {.index = 60, .length = 7},
};

static const TSFieldMapEntry ts_field_map_entries[] = {
  [0] =
    {field_operator, 0},
    {field_right, 1},
  [2] =
    {field_arguments, 1},
    {field_function, 0},
  [4] =
    {field_left, 0},
    {field_right, 2},
  [6] =
    {field_left, 0},
    {field_operator, 1},
    {field_right, 2},
  [9] =
    {field_arguments, 2},
    {field_name, 1},
  [11] =
    {field_left, 0},
    {field_left, 1},
    {field_right, 3},
  [14] =
    {field_body, 1},
    {field_condition, 3},
  [16] =
    {field_arguments, 2},
    {field_body, 3},
    {field_name, 1},
  [19] =
    {field_condition, 1},
    {field_consequence, 3},
  [21] =
    {field_alternative, 0},
  [22] =
    {field_body, 3},
    {field_condition, 1},
  [24] =
    {field_matchee, 1},
  [25] =
    {field_conditional, 0},
    {field_else, 4},
    {field_then, 2},
  [28] =
    {field_consequence, 1},
  [29] =
    {field_alternative, 4},
    {field_condition, 1},
    {field_consequence, 3},
  [32] =
    {field_alternative, 4, .inherited = true},
    {field_condition, 1},
    {field_consequence, 3},
  [35] =
    {field_alternative, 0, .inherited = true},
    {field_alternative, 1, .inherited = true},
  [37] =
    {field_alternative, 4, .inherited = true},
    {field_alternative, 5},
    {field_condition, 1},
    {field_consequence, 3},
  [41] =
    {field_consequence, 3},
    {field_match, 1},
  [43] =
    {field_arguments, 2},
    {field_docstring, 4},
    {field_docstring, 5},
    {field_docstring, 6},
    {field_name, 1},
  [48] =
    {field_arguments, 2},
    {field_body, 7},
    {field_docstring, 4},
    {field_docstring, 5},
    {field_docstring, 6},
    {field_name, 1},
  [54] =
    {field_arguments, 2},
    {field_docstring, 5},
    {field_docstring, 6},
    {field_docstring, 7},
    {field_name, 1},
    {field_return_type, 4},
  [60] =
    {field_arguments, 2},
    {field_body, 8},
    {field_docstring, 5},
    {field_docstring, 6},
    {field_docstring, 7},
    {field_name, 1},
    {field_return_type, 4},
};

static const TSSymbol ts_alias_sequences[PRODUCTION_ID_COUNT][MAX_ALIAS_SEQUENCE_LENGTH] = {
  [0] = {0},
};

static const uint16_t ts_non_terminal_alias_map[] = {
  0,
};

static const TSStateId ts_primary_state_ids[STATE_COUNT] = {
  [0] = 0,
  [1] = 1,
  [2] = 2,
  [3] = 3,
  [4] = 4,
  [5] = 5,
  [6] = 6,
  [7] = 2,
  [8] = 3,
  [9] = 3,
  [10] = 2,
  [11] = 3,
  [12] = 2,
  [13] = 2,
  [14] = 14,
  [15] = 15,
  [16] = 16,
  [17] = 17,
  [18] = 3,
  [19] = 2,
  [20] = 3,
  [21] = 21,
  [22] = 2,
  [23] = 23,
  [24] = 3,
  [25] = 3,
  [26] = 26,
  [27] = 27,
  [28] = 28,
  [29] = 2,
  [30] = 30,
  [31] = 31,
  [32] = 32,
  [33] = 33,
  [34] = 34,
  [35] = 35,
  [36] = 36,
  [37] = 37,
  [38] = 38,
  [39] = 39,
  [40] = 40,
  [41] = 41,
  [42] = 42,
  [43] = 43,
  [44] = 44,
  [45] = 45,
  [46] = 46,
  [47] = 47,
  [48] = 48,
  [49] = 49,
  [50] = 50,
  [51] = 51,
  [52] = 52,
  [53] = 53,
  [54] = 54,
  [55] = 55,
  [56] = 56,
  [57] = 57,
  [58] = 58,
  [59] = 59,
  [60] = 60,
  [61] = 61,
  [62] = 62,
  [63] = 63,
  [64] = 64,
  [65] = 65,
  [66] = 62,
  [67] = 62,
  [68] = 68,
  [69] = 69,
  [70] = 64,
  [71] = 68,
  [72] = 72,
  [73] = 68,
  [74] = 74,
  [75] = 68,
  [76] = 64,
  [77] = 77,
  [78] = 68,
  [79] = 79,
  [80] = 64,
  [81] = 68,
  [82] = 82,
  [83] = 64,
  [84] = 68,
  [85] = 64,
  [86] = 86,
  [87] = 87,
  [88] = 68,
  [89] = 89,
  [90] = 32,
  [91] = 68,
  [92] = 64,
  [93] = 64,
  [94] = 33,
  [95] = 30,
  [96] = 32,
  [97] = 30,
  [98] = 33,
  [99] = 99,
  [100] = 100,
  [101] = 101,
  [102] = 102,
  [103] = 103,
  [104] = 103,
  [105] = 103,
  [106] = 106,
  [107] = 107,
  [108] = 108,
  [109] = 109,
  [110] = 110,
  [111] = 111,
  [112] = 112,
  [113] = 113,
  [114] = 114,
  [115] = 115,
  [116] = 116,
  [117] = 117,
  [118] = 118,
  [119] = 119,
  [120] = 120,
  [121] = 121,
  [122] = 122,
  [123] = 123,
  [124] = 124,
  [125] = 125,
  [126] = 126,
  [127] = 127,
  [128] = 128,
  [129] = 129,
  [130] = 130,
  [131] = 131,
  [132] = 132,
  [133] = 133,
  [134] = 134,
  [135] = 135,
  [136] = 136,
  [137] = 137,
  [138] = 138,
  [139] = 139,
  [140] = 140,
  [141] = 141,
  [142] = 142,
  [143] = 143,
  [144] = 144,
  [145] = 145,
  [146] = 146,
  [147] = 147,
  [148] = 148,
  [149] = 146,
  [150] = 150,
  [151] = 151,
  [152] = 146,
  [153] = 153,
  [154] = 154,
  [155] = 155,
  [156] = 156,
  [157] = 157,
  [158] = 158,
  [159] = 159,
  [160] = 160,
  [161] = 161,
  [162] = 162,
  [163] = 163,
  [164] = 164,
  [165] = 165,
  [166] = 166,
  [167] = 167,
  [168] = 168,
  [169] = 169,
  [170] = 170,
  [171] = 171,
  [172] = 172,
  [173] = 173,
  [174] = 174,
  [175] = 175,
  [176] = 176,
  [177] = 177,
  [178] = 178,
  [179] = 179,
  [180] = 180,
  [181] = 181,
  [182] = 182,
  [183] = 183,
  [184] = 184,
  [185] = 185,
  [186] = 186,
  [187] = 187,
  [188] = 188,
  [189] = 189,
  [190] = 190,
  [191] = 191,
  [192] = 192,
  [193] = 193,
  [194] = 194,
  [195] = 195,
  [196] = 196,
  [197] = 197,
  [198] = 198,
  [199] = 199,
  [200] = 200,
  [201] = 201,
  [202] = 202,
  [203] = 203,
  [204] = 204,
  [205] = 205,
  [206] = 206,
  [207] = 207,
  [208] = 208,
  [209] = 209,
  [210] = 194,
  [211] = 211,
  [212] = 212,
  [213] = 194,
  [214] = 194,
  [215] = 215,
  [216] = 216,
  [217] = 217,
  [218] = 194,
  [219] = 219,
  [220] = 220,
  [221] = 221,
  [222] = 194,
  [223] = 194,
  [224] = 194,
  [225] = 194,
  [226] = 226,
  [227] = 227,
};

static bool ts_lex(TSLexer *lexer, TSStateId state) {
  START_LEXER();
  eof = lexer->eof(lexer);
  switch (state) {
    case 0:
      if (eof) ADVANCE(229);
      if (lookahead == '"') ADVANCE(15);
      if (lookahead == '(') ADVANCE(292);
      if (lookahead == ')') ADVANCE(293);
      if (lookahead == '*') ADVANCE(265);
      if (lookahead == '+') ADVANCE(263);
      if (lookahead == ',') ADVANCE(245);
      if (lookahead == '-') ADVANCE(260);
      if (lookahead == '.') ADVANCE(326);
      if (lookahead == '/') ADVANCE(243);
      if (lookahead == ':') ADVANCE(346);
      if (lookahead == ';') ADVANCE(244);
      if (lookahead == '<') ADVANCE(324);
      if (lookahead == '>') ADVANCE(325);
      if (lookahead == 'T') ADVANCE(36);
      if (lookahead == '^') ADVANCE(266);
      if (lookahead == '_') ADVANCE(322);
      if (lookahead == 'a') ADVANCE(149);
      if (lookahead == 'b') ADVANCE(188);
      if (lookahead == 'c') ADVANCE(40);
      if (lookahead == 'd') ADVANCE(114);
      if (lookahead == 'e') ADVANCE(134);
      if (lookahead == 'f') ADVANCE(41);
      if (lookahead == 'g') ADVANCE(66);
      if (lookahead == 'i') ADVANCE(97);
      if (lookahead == 'j') ADVANCE(167);
      if (lookahead == 'l') ADVANCE(67);
      if (lookahead == 'm') ADVANCE(85);
      if (lookahead == 'n') ADVANCE(69);
      if (lookahead == 'o') ADVANCE(184);
      if (lookahead == 'p') ADVANCE(138);
      if (lookahead == 'r') ADVANCE(70);
      if (lookahead == 's') ADVANCE(62);
      if (lookahead == 't') ADVANCE(110);
      if (lookahead == 'u') ADVANCE(158);
      if (lookahead == 'w') ADVANCE(108);
      if (lookahead == 'x') ADVANCE(168);
      if (lookahead == '{') ADVANCE(308);
      if (lookahead == '}') ADVANCE(312);
      if (lookahead == '~') ADVANCE(261);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(0)
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(448);
      END_STATE();
    case 1:
      if (lookahead == ' ') ADVANCE(51);
      END_STATE();
    case 2:
      if (lookahead == ' ') ADVANCE(115);
      END_STATE();
    case 3:
      if (lookahead == ' ') ADVANCE(107);
      END_STATE();
    case 4:
      if (lookahead == ' ') ADVANCE(140);
      END_STATE();
    case 5:
      if (lookahead == '"') ADVANCE(15);
      if (lookahead == '(') ADVANCE(292);
      if (lookahead == ')') ADVANCE(293);
      if (lookahead == '-') ADVANCE(258);
      if (lookahead == '/') ADVANCE(20);
      if (lookahead == ';') ADVANCE(244);
      if (lookahead == 'f') ADVANCE(363);
      if (lookahead == 'n') ADVANCE(422);
      if (lookahead == 't') ADVANCE(426);
      if (lookahead == '~') ADVANCE(261);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(5)
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(448);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(446);
      END_STATE();
    case 6:
      if (lookahead == '"') ADVANCE(15);
      if (lookahead == '(') ADVANCE(292);
      if (lookahead == '-') ADVANCE(258);
      if (lookahead == '/') ADVANCE(20);
      if (lookahead == 'T') ADVANCE(359);
      if (lookahead == '_') ADVANCE(323);
      if (lookahead == 'b') ADVANCE(427);
      if (lookahead == 'c') ADVANCE(361);
      if (lookahead == 'e') ADVANCE(445);
      if (lookahead == 'f') ADVANCE(362);
      if (lookahead == 'i') ADVANCE(389);
      if (lookahead == 'n') ADVANCE(422);
      if (lookahead == 'p') ADVANCE(425);
      if (lookahead == 'r') ADVANCE(377);
      if (lookahead == 't') ADVANCE(426);
      if (lookahead == 'u') ADVANCE(419);
      if (lookahead == 'w') ADVANCE(391);
      if (lookahead == '~') ADVANCE(261);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(6)
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(448);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(446);
      END_STATE();
    case 7:
      if (lookahead == '"') ADVANCE(15);
      if (lookahead == '(') ADVANCE(292);
      if (lookahead == '-') ADVANCE(258);
      if (lookahead == '/') ADVANCE(20);
      if (lookahead == 'T') ADVANCE(359);
      if (lookahead == '_') ADVANCE(323);
      if (lookahead == 'b') ADVANCE(427);
      if (lookahead == 'c') ADVANCE(361);
      if (lookahead == 'e') ADVANCE(403);
      if (lookahead == 'f') ADVANCE(362);
      if (lookahead == 'i') ADVANCE(389);
      if (lookahead == 'n') ADVANCE(422);
      if (lookahead == 'p') ADVANCE(425);
      if (lookahead == 'r') ADVANCE(377);
      if (lookahead == 't') ADVANCE(426);
      if (lookahead == 'w') ADVANCE(391);
      if (lookahead == '~') ADVANCE(261);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(7)
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(448);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(446);
      END_STATE();
    case 8:
      if (lookahead == '"') ADVANCE(15);
      if (lookahead == '(') ADVANCE(292);
      if (lookahead == '-') ADVANCE(258);
      if (lookahead == '/') ADVANCE(20);
      if (lookahead == 'T') ADVANCE(359);
      if (lookahead == '_') ADVANCE(323);
      if (lookahead == 'b') ADVANCE(427);
      if (lookahead == 'c') ADVANCE(361);
      if (lookahead == 'e') ADVANCE(414);
      if (lookahead == 'f') ADVANCE(362);
      if (lookahead == 'i') ADVANCE(389);
      if (lookahead == 'n') ADVANCE(422);
      if (lookahead == 'p') ADVANCE(425);
      if (lookahead == 'r') ADVANCE(377);
      if (lookahead == 't') ADVANCE(426);
      if (lookahead == 'w') ADVANCE(391);
      if (lookahead == '~') ADVANCE(261);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(8)
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(448);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(446);
      END_STATE();
    case 9:
      if (lookahead == '"') ADVANCE(15);
      if (lookahead == '(') ADVANCE(292);
      if (lookahead == '-') ADVANCE(258);
      if (lookahead == '/') ADVANCE(20);
      if (lookahead == 'T') ADVANCE(359);
      if (lookahead == '_') ADVANCE(323);
      if (lookahead == 'b') ADVANCE(427);
      if (lookahead == 'c') ADVANCE(361);
      if (lookahead == 'e') ADVANCE(415);
      if (lookahead == 'f') ADVANCE(362);
      if (lookahead == 'i') ADVANCE(389);
      if (lookahead == 'n') ADVANCE(422);
      if (lookahead == 'p') ADVANCE(425);
      if (lookahead == 'r') ADVANCE(377);
      if (lookahead == 't') ADVANCE(426);
      if (lookahead == 'w') ADVANCE(391);
      if (lookahead == '~') ADVANCE(261);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(9)
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(448);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(446);
      END_STATE();
    case 10:
      if (lookahead == '"') ADVANCE(15);
      if (lookahead == '(') ADVANCE(292);
      if (lookahead == '-') ADVANCE(258);
      if (lookahead == '/') ADVANCE(20);
      if (lookahead == 'T') ADVANCE(359);
      if (lookahead == '_') ADVANCE(323);
      if (lookahead == 'b') ADVANCE(427);
      if (lookahead == 'c') ADVANCE(361);
      if (lookahead == 'e') ADVANCE(417);
      if (lookahead == 'f') ADVANCE(362);
      if (lookahead == 'i') ADVANCE(389);
      if (lookahead == 'n') ADVANCE(422);
      if (lookahead == 'p') ADVANCE(425);
      if (lookahead == 'r') ADVANCE(377);
      if (lookahead == 't') ADVANCE(426);
      if (lookahead == 'w') ADVANCE(392);
      if (lookahead == '~') ADVANCE(261);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(10)
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(448);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(446);
      END_STATE();
    case 11:
      if (lookahead == '"') ADVANCE(15);
      if (lookahead == '(') ADVANCE(292);
      if (lookahead == '-') ADVANCE(258);
      if (lookahead == '/') ADVANCE(20);
      if (lookahead == 'T') ADVANCE(359);
      if (lookahead == '_') ADVANCE(323);
      if (lookahead == 'b') ADVANCE(427);
      if (lookahead == 'c') ADVANCE(361);
      if (lookahead == 'e') ADVANCE(418);
      if (lookahead == 'f') ADVANCE(362);
      if (lookahead == 'i') ADVANCE(389);
      if (lookahead == 'n') ADVANCE(422);
      if (lookahead == 'p') ADVANCE(425);
      if (lookahead == 'r') ADVANCE(377);
      if (lookahead == 't') ADVANCE(426);
      if (lookahead == 'w') ADVANCE(391);
      if (lookahead == '~') ADVANCE(261);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(11)
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(448);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(446);
      END_STATE();
    case 12:
      if (lookahead == '"') ADVANCE(15);
      if (lookahead == '(') ADVANCE(292);
      if (lookahead == '-') ADVANCE(258);
      if (lookahead == '/') ADVANCE(20);
      if (lookahead == 'T') ADVANCE(359);
      if (lookahead == '_') ADVANCE(323);
      if (lookahead == 'b') ADVANCE(427);
      if (lookahead == 'c') ADVANCE(361);
      if (lookahead == 'e') ADVANCE(412);
      if (lookahead == 'f') ADVANCE(362);
      if (lookahead == 'i') ADVANCE(389);
      if (lookahead == 'n') ADVANCE(422);
      if (lookahead == 'p') ADVANCE(425);
      if (lookahead == 'r') ADVANCE(377);
      if (lookahead == 't') ADVANCE(426);
      if (lookahead == 'w') ADVANCE(391);
      if (lookahead == '~') ADVANCE(261);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(12)
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(448);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(446);
      END_STATE();
    case 13:
      if (lookahead == '"') ADVANCE(15);
      if (lookahead == '(') ADVANCE(292);
      if (lookahead == '-') ADVANCE(258);
      if (lookahead == '/') ADVANCE(20);
      if (lookahead == 'T') ADVANCE(359);
      if (lookahead == '_') ADVANCE(323);
      if (lookahead == 'b') ADVANCE(427);
      if (lookahead == 'c') ADVANCE(361);
      if (lookahead == 'e') ADVANCE(420);
      if (lookahead == 'f') ADVANCE(362);
      if (lookahead == 'i') ADVANCE(389);
      if (lookahead == 'n') ADVANCE(422);
      if (lookahead == 'p') ADVANCE(425);
      if (lookahead == 'r') ADVANCE(377);
      if (lookahead == 't') ADVANCE(426);
      if (lookahead == 'w') ADVANCE(391);
      if (lookahead == '~') ADVANCE(261);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(13)
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(448);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(446);
      END_STATE();
    case 14:
      if (lookahead == '"') ADVANCE(15);
      if (lookahead == '(') ADVANCE(292);
      if (lookahead == '-') ADVANCE(258);
      if (lookahead == '/') ADVANCE(20);
      if (lookahead == '_') ADVANCE(323);
      if (lookahead == 'f') ADVANCE(363);
      if (lookahead == 'n') ADVANCE(422);
      if (lookahead == 't') ADVANCE(426);
      if (lookahead == '~') ADVANCE(261);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(14)
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(448);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(446);
      END_STATE();
    case 15:
      if (lookahead == '"') ADVANCE(447);
      if (lookahead == '\\') ADVANCE(227);
      if (lookahead != 0) ADVANCE(15);
      END_STATE();
    case 16:
      if (lookahead == '(') ADVANCE(292);
      if (lookahead == ')') ADVANCE(293);
      if (lookahead == '*') ADVANCE(265);
      if (lookahead == '+') ADVANCE(263);
      if (lookahead == ',') ADVANCE(245);
      if (lookahead == '-') ADVANCE(260);
      if (lookahead == '/') ADVANCE(243);
      if (lookahead == ':') ADVANCE(347);
      if (lookahead == ';') ADVANCE(244);
      if (lookahead == '^') ADVANCE(266);
      if (lookahead == 'a') ADVANCE(149);
      if (lookahead == 'c') ADVANCE(46);
      if (lookahead == 'd') ADVANCE(114);
      if (lookahead == 'e') ADVANCE(146);
      if (lookahead == 'g') ADVANCE(66);
      if (lookahead == 'j') ADVANCE(167);
      if (lookahead == 'l') ADVANCE(67);
      if (lookahead == 'm') ADVANCE(85);
      if (lookahead == 'n') ADVANCE(68);
      if (lookahead == 'o') ADVANCE(184);
      if (lookahead == 's') ADVANCE(62);
      if (lookahead == 't') ADVANCE(109);
      if (lookahead == 'x') ADVANCE(168);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(16)
      END_STATE();
    case 17:
      if (lookahead == '(') ADVANCE(292);
      if (lookahead == ')') ADVANCE(293);
      if (lookahead == '*') ADVANCE(265);
      if (lookahead == '+') ADVANCE(263);
      if (lookahead == ',') ADVANCE(245);
      if (lookahead == '-') ADVANCE(259);
      if (lookahead == '/') ADVANCE(243);
      if (lookahead == ':') ADVANCE(347);
      if (lookahead == ';') ADVANCE(244);
      if (lookahead == '^') ADVANCE(266);
      if (lookahead == 'a') ADVANCE(149);
      if (lookahead == 'c') ADVANCE(46);
      if (lookahead == 'd') ADVANCE(114);
      if (lookahead == 'e') ADVANCE(146);
      if (lookahead == 'g') ADVANCE(66);
      if (lookahead == 'j') ADVANCE(167);
      if (lookahead == 'l') ADVANCE(67);
      if (lookahead == 'm') ADVANCE(85);
      if (lookahead == 'n') ADVANCE(68);
      if (lookahead == 'o') ADVANCE(184);
      if (lookahead == 's') ADVANCE(62);
      if (lookahead == 't') ADVANCE(109);
      if (lookahead == 'x') ADVANCE(168);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(17)
      END_STATE();
    case 18:
      if (lookahead == '(') ADVANCE(292);
      if (lookahead == '*') ADVANCE(265);
      if (lookahead == '+') ADVANCE(263);
      if (lookahead == ',') ADVANCE(245);
      if (lookahead == '-') ADVANCE(259);
      if (lookahead == '/') ADVANCE(243);
      if (lookahead == ':') ADVANCE(26);
      if (lookahead == ';') ADVANCE(244);
      if (lookahead == '<') ADVANCE(324);
      if (lookahead == '^') ADVANCE(266);
      if (lookahead == 'a') ADVANCE(149);
      if (lookahead == 'c') ADVANCE(46);
      if (lookahead == 'd') ADVANCE(113);
      if (lookahead == 'e') ADVANCE(182);
      if (lookahead == 'g') ADVANCE(66);
      if (lookahead == 'j') ADVANCE(167);
      if (lookahead == 'l') ADVANCE(67);
      if (lookahead == 'm') ADVANCE(85);
      if (lookahead == 'n') ADVANCE(68);
      if (lookahead == 'o') ADVANCE(184);
      if (lookahead == 's') ADVANCE(62);
      if (lookahead == 'x') ADVANCE(168);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(18)
      END_STATE();
    case 19:
      if (lookahead == '(') ADVANCE(292);
      if (lookahead == '*') ADVANCE(264);
      if (lookahead == '+') ADVANCE(262);
      if (lookahead == '-') ADVANCE(258);
      if (lookahead == '/') ADVANCE(242);
      if (lookahead == ':') ADVANCE(345);
      if (lookahead == '^') ADVANCE(266);
      if (lookahead == 'a') ADVANCE(160);
      if (lookahead == 'c') ADVANCE(46);
      if (lookahead == 'd') ADVANCE(116);
      if (lookahead == 'e') ADVANCE(182);
      if (lookahead == 'g') ADVANCE(66);
      if (lookahead == 'j') ADVANCE(167);
      if (lookahead == 'l') ADVANCE(67);
      if (lookahead == 'm') ADVANCE(85);
      if (lookahead == 'n') ADVANCE(68);
      if (lookahead == 'o') ADVANCE(187);
      if (lookahead == 's') ADVANCE(62);
      if (lookahead == 'x') ADVANCE(168);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(19)
      END_STATE();
    case 20:
      if (lookahead == '*') ADVANCE(237);
      if (lookahead == '/') ADVANCE(230);
      END_STATE();
    case 21:
      if (lookahead == '*') ADVANCE(241);
      if (lookahead == '/') ADVANCE(23);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(21);
      if (lookahead != 0) ADVANCE(22);
      END_STATE();
    case 22:
      if (lookahead == '*') ADVANCE(241);
      if (lookahead != 0) ADVANCE(22);
      END_STATE();
    case 23:
      if (lookahead == '*') ADVANCE(238);
      if (lookahead == '/') ADVANCE(231);
      if (lookahead != 0) ADVANCE(22);
      END_STATE();
    case 24:
      if (lookahead == '-') ADVANCE(34);
      if (lookahead == '.') ADVANCE(326);
      if (lookahead == '/') ADVANCE(20);
      if (lookahead == ';') ADVANCE(244);
      if (lookahead == '{') ADVANCE(308);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(24)
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(446);
      END_STATE();
    case 25:
      if (lookahead == ':') ADVANCE(2);
      END_STATE();
    case 26:
      if (lookahead == '=') ADVANCE(314);
      END_STATE();
    case 27:
      if (lookahead == '=') ADVANCE(317);
      END_STATE();
    case 28:
      if (lookahead == '=') ADVANCE(315);
      END_STATE();
    case 29:
      if (lookahead == '=') ADVANCE(316);
      END_STATE();
    case 30:
      if (lookahead == '=') ADVANCE(318);
      END_STATE();
    case 31:
      if (lookahead == '=') ADVANCE(320);
      END_STATE();
    case 32:
      if (lookahead == '=') ADVANCE(319);
      END_STATE();
    case 33:
      if (lookahead == '=') ADVANCE(321);
      END_STATE();
    case 34:
      if (lookahead == '>') ADVANCE(307);
      END_STATE();
    case 35:
      if (lookahead == 'D') ADVANCE(37);
      END_STATE();
    case 36:
      if (lookahead == 'O') ADVANCE(35);
      END_STATE();
    case 37:
      if (lookahead == 'O') ADVANCE(25);
      END_STATE();
    case 38:
      if (lookahead == '_') ADVANCE(142);
      END_STATE();
    case 39:
      if (lookahead == '_') ADVANCE(83);
      END_STATE();
    case 40:
      if (lookahead == 'a') ADVANCE(197);
      if (lookahead == 'm') ADVANCE(176);
      if (lookahead == 'o') ADVANCE(159);
      END_STATE();
    case 41:
      if (lookahead == 'a') ADVANCE(135);
      if (lookahead == 'u') ADVANCE(150);
      END_STATE();
    case 42:
      if (lookahead == 'a') ADVANCE(133);
      END_STATE();
    case 43:
      if (lookahead == 'a') ADVANCE(53);
      END_STATE();
    case 44:
      if (lookahead == 'a') ADVANCE(136);
      END_STATE();
    case 45:
      if (lookahead == 'a') ADVANCE(208);
      END_STATE();
    case 46:
      if (lookahead == 'a') ADVANCE(204);
      if (lookahead == 'm') ADVANCE(176);
      END_STATE();
    case 47:
      if (lookahead == 'a') ADVANCE(203);
      END_STATE();
    case 48:
      if (lookahead == 'c') ADVANCE(305);
      END_STATE();
    case 49:
      if (lookahead == 'c') ADVANCE(313);
      END_STATE();
    case 50:
      if (lookahead == 'c') ADVANCE(47);
      END_STATE();
    case 51:
      if (lookahead == 'c') ADVANCE(47);
      if (lookahead == 'f') ADVANCE(223);
      if (lookahead == 'i') ADVANCE(104);
      if (lookahead == 'p') ADVANCE(190);
      if (lookahead == 'w') ADVANCE(112);
      END_STATE();
    case 52:
      if (lookahead == 'c') ADVANCE(209);
      END_STATE();
    case 53:
      if (lookahead == 'c') ADVANCE(86);
      END_STATE();
    case 54:
      if (lookahead == 'c') ADVANCE(88);
      END_STATE();
    case 55:
      if (lookahead == 'c') ADVANCE(214);
      END_STATE();
    case 56:
      if (lookahead == 'c') ADVANCE(216);
      END_STATE();
    case 57:
      if (lookahead == 'c') ADVANCE(96);
      END_STATE();
    case 58:
      if (lookahead == 'd') ADVANCE(291);
      END_STATE();
    case 59:
      if (lookahead == 'd') ADVANCE(1);
      END_STATE();
    case 60:
      if (lookahead == 'd') ADVANCE(269);
      END_STATE();
    case 61:
      if (lookahead == 'd') ADVANCE(290);
      END_STATE();
    case 62:
      if (lookahead == 'd') ADVANCE(118);
      if (lookahead == 'e') ADVANCE(141);
      END_STATE();
    case 63:
      if (lookahead == 'd') ADVANCE(221);
      END_STATE();
    case 64:
      if (lookahead == 'd') ADVANCE(93);
      END_STATE();
    case 65:
      if (lookahead == 'd') ADVANCE(222);
      END_STATE();
    case 66:
      if (lookahead == 'e') ADVANCE(280);
      if (lookahead == 't') ADVANCE(279);
      END_STATE();
    case 67:
      if (lookahead == 'e') ADVANCE(282);
      if (lookahead == 't') ADVANCE(281);
      END_STATE();
    case 68:
      if (lookahead == 'e') ADVANCE(284);
      END_STATE();
    case 69:
      if (lookahead == 'e') ADVANCE(284);
      if (lookahead == 'o') ADVANCE(205);
      END_STATE();
    case 70:
      if (lookahead == 'e') ADVANCE(180);
      END_STATE();
    case 71:
      if (lookahead == 'e') ADVANCE(343);
      END_STATE();
    case 72:
      if (lookahead == 'e') ADVANCE(183);
      if (lookahead == 'n') ADVANCE(75);
      END_STATE();
    case 73:
      if (lookahead == 'e') ADVANCE(277);
      END_STATE();
    case 74:
      if (lookahead == 'e') ADVANCE(294);
      END_STATE();
    case 75:
      if (lookahead == 'e') ADVANCE(286);
      END_STATE();
    case 76:
      if (lookahead == 'e') ADVANCE(296);
      END_STATE();
    case 77:
      if (lookahead == 'e') ADVANCE(335);
      END_STATE();
    case 78:
      if (lookahead == 'e') ADVANCE(250);
      END_STATE();
    case 79:
      if (lookahead == 'e') ADVANCE(348);
      END_STATE();
    case 80:
      if (lookahead == 'e') ADVANCE(338);
      END_STATE();
    case 81:
      if (lookahead == 'e') ADVANCE(302);
      END_STATE();
    case 82:
      if (lookahead == 'e') ADVANCE(304);
      END_STATE();
    case 83:
      if (lookahead == 'e') ADVANCE(225);
      END_STATE();
    case 84:
      if (lookahead == 'e') ADVANCE(148);
      END_STATE();
    case 85:
      if (lookahead == 'e') ADVANCE(91);
      if (lookahead == 'o') ADVANCE(60);
      END_STATE();
    case 86:
      if (lookahead == 'e') ADVANCE(111);
      END_STATE();
    case 87:
      if (lookahead == 'e') ADVANCE(42);
      END_STATE();
    case 88:
      if (lookahead == 'e') ADVANCE(63);
      END_STATE();
    case 89:
      if (lookahead == 'e') ADVANCE(45);
      END_STATE();
    case 90:
      if (lookahead == 'e') ADVANCE(152);
      END_STATE();
    case 91:
      if (lookahead == 'e') ADVANCE(206);
      END_STATE();
    case 92:
      if (lookahead == 'e') ADVANCE(153);
      if (lookahead == 'i') ADVANCE(143);
      END_STATE();
    case 93:
      if (lookahead == 'e') ADVANCE(186);
      END_STATE();
    case 94:
      if (lookahead == 'e') ADVANCE(52);
      END_STATE();
    case 95:
      if (lookahead == 'e') ADVANCE(162);
      END_STATE();
    case 96:
      if (lookahead == 'e') ADVANCE(65);
      END_STATE();
    case 97:
      if (lookahead == 'f') ADVANCE(328);
      if (lookahead == 'n') ADVANCE(213);
      END_STATE();
    case 98:
      if (lookahead == 'f') ADVANCE(100);
      if (lookahead == 'v') ADVANCE(268);
      END_STATE();
    case 99:
      if (lookahead == 'f') ADVANCE(100);
      if (lookahead == 'v') ADVANCE(267);
      END_STATE();
    case 100:
      if (lookahead == 'f') ADVANCE(272);
      END_STATE();
    case 101:
      if (lookahead == 'f') ADVANCE(332);
      END_STATE();
    case 102:
      if (lookahead == 'f') ADVANCE(273);
      END_STATE();
    case 103:
      if (lookahead == 'f') ADVANCE(331);
      END_STATE();
    case 104:
      if (lookahead == 'f') ADVANCE(331);
      if (lookahead == 'n') ADVANCE(217);
      END_STATE();
    case 105:
      if (lookahead == 'f') ADVANCE(223);
      END_STATE();
    case 106:
      if (lookahead == 'f') ADVANCE(102);
      END_STATE();
    case 107:
      if (lookahead == 'f') ADVANCE(172);
      END_STATE();
    case 108:
      if (lookahead == 'h') ADVANCE(92);
      END_STATE();
    case 109:
      if (lookahead == 'h') ADVANCE(90);
      END_STATE();
    case 110:
      if (lookahead == 'h') ADVANCE(90);
      if (lookahead == 'r') ADVANCE(219);
      END_STATE();
    case 111:
      if (lookahead == 'h') ADVANCE(170);
      END_STATE();
    case 112:
      if (lookahead == 'h') ADVANCE(132);
      END_STATE();
    case 113:
      if (lookahead == 'i') ADVANCE(98);
      END_STATE();
    case 114:
      if (lookahead == 'i') ADVANCE(98);
      if (lookahead == 'o') ADVANCE(337);
      END_STATE();
    case 115:
      if (lookahead == 'i') ADVANCE(147);
      END_STATE();
    case 116:
      if (lookahead == 'i') ADVANCE(99);
      END_STATE();
    case 117:
      if (lookahead == 'i') ADVANCE(101);
      if (lookahead == 's') ADVANCE(73);
      END_STATE();
    case 118:
      if (lookahead == 'i') ADVANCE(106);
      END_STATE();
    case 119:
      if (lookahead == 'i') ADVANCE(202);
      END_STATE();
    case 120:
      if (lookahead == 'i') ADVANCE(48);
      END_STATE();
    case 121:
      if (lookahead == 'i') ADVANCE(151);
      END_STATE();
    case 122:
      if (lookahead == 'i') ADVANCE(173);
      END_STATE();
    case 123:
      if (lookahead == 'i') ADVANCE(137);
      END_STATE();
    case 124:
      if (lookahead == 'i') ADVANCE(49);
      END_STATE();
    case 125:
      if (lookahead == 'i') ADVANCE(103);
      END_STATE();
    case 126:
      if (lookahead == 'i') ADVANCE(163);
      END_STATE();
    case 127:
      if (lookahead == 'i') ADVANCE(157);
      END_STATE();
    case 128:
      if (lookahead == 'i') ADVANCE(166);
      END_STATE();
    case 129:
      if (lookahead == 'i') ADVANCE(174);
      END_STATE();
    case 130:
      if (lookahead == 'i') ADVANCE(164);
      END_STATE();
    case 131:
      if (lookahead == 'i') ADVANCE(161);
      if (lookahead == 'o') ADVANCE(54);
      END_STATE();
    case 132:
      if (lookahead == 'i') ADVANCE(144);
      END_STATE();
    case 133:
      if (lookahead == 'k') ADVANCE(248);
      END_STATE();
    case 134:
      if (lookahead == 'l') ADVANCE(117);
      if (lookahead == 'n') ADVANCE(59);
      if (lookahead == 'q') ADVANCE(283);
      if (lookahead == 'v') ADVANCE(44);
      END_STATE();
    case 135:
      if (lookahead == 'l') ADVANCE(201);
      END_STATE();
    case 136:
      if (lookahead == 'l') ADVANCE(252);
      END_STATE();
    case 137:
      if (lookahead == 'l') ADVANCE(341);
      END_STATE();
    case 138:
      if (lookahead == 'l') ADVANCE(43);
      if (lookahead == 'r') ADVANCE(131);
      END_STATE();
    case 139:
      if (lookahead == 'l') ADVANCE(64);
      END_STATE();
    case 140:
      if (lookahead == 'l') ADVANCE(171);
      END_STATE();
    case 141:
      if (lookahead == 'l') ADVANCE(94);
      END_STATE();
    case 142:
      if (lookahead == 'l') ADVANCE(119);
      END_STATE();
    case 143:
      if (lookahead == 'l') ADVANCE(77);
      END_STATE();
    case 144:
      if (lookahead == 'l') ADVANCE(80);
      END_STATE();
    case 145:
      if (lookahead == 'l') ADVANCE(84);
      END_STATE();
    case 146:
      if (lookahead == 'l') ADVANCE(198);
      if (lookahead == 'q') ADVANCE(283);
      END_STATE();
    case 147:
      if (lookahead == 'm') ADVANCE(181);
      END_STATE();
    case 148:
      if (lookahead == 'm') ADVANCE(95);
      END_STATE();
    case 149:
      if (lookahead == 'n') ADVANCE(58);
      END_STATE();
    case 150:
      if (lookahead == 'n') ADVANCE(55);
      END_STATE();
    case 151:
      if (lookahead == 'n') ADVANCE(271);
      END_STATE();
    case 152:
      if (lookahead == 'n') ADVANCE(330);
      END_STATE();
    case 153:
      if (lookahead == 'n') ADVANCE(349);
      END_STATE();
    case 154:
      if (lookahead == 'n') ADVANCE(246);
      END_STATE();
    case 155:
      if (lookahead == 'n') ADVANCE(299);
      END_STATE();
    case 156:
      if (lookahead == 'n') ADVANCE(301);
      END_STATE();
    case 157:
      if (lookahead == 'n') ADVANCE(199);
      END_STATE();
    case 158:
      if (lookahead == 'n') ADVANCE(211);
      END_STATE();
    case 159:
      if (lookahead == 'n') ADVANCE(215);
      END_STATE();
    case 160:
      if (lookahead == 'n') ADVANCE(61);
      END_STATE();
    case 161:
      if (lookahead == 'n') ADVANCE(207);
      END_STATE();
    case 162:
      if (lookahead == 'n') ADVANCE(212);
      END_STATE();
    case 163:
      if (lookahead == 'n') ADVANCE(220);
      END_STATE();
    case 164:
      if (lookahead == 'n') ADVANCE(200);
      END_STATE();
    case 165:
      if (lookahead == 'n') ADVANCE(56);
      END_STATE();
    case 166:
      if (lookahead == 'n') ADVANCE(217);
      END_STATE();
    case 167:
      if (lookahead == 'o') ADVANCE(121);
      END_STATE();
    case 168:
      if (lookahead == 'o') ADVANCE(185);
      END_STATE();
    case 169:
      if (lookahead == 'o') ADVANCE(177);
      END_STATE();
    case 170:
      if (lookahead == 'o') ADVANCE(139);
      END_STATE();
    case 171:
      if (lookahead == 'o') ADVANCE(169);
      END_STATE();
    case 172:
      if (lookahead == 'o') ADVANCE(191);
      END_STATE();
    case 173:
      if (lookahead == 'o') ADVANCE(155);
      END_STATE();
    case 174:
      if (lookahead == 'o') ADVANCE(156);
      END_STATE();
    case 175:
      if (lookahead == 'o') ADVANCE(57);
      END_STATE();
    case 176:
      if (lookahead == 'p') ADVANCE(72);
      END_STATE();
    case 177:
      if (lookahead == 'p') ADVANCE(334);
      END_STATE();
    case 178:
      if (lookahead == 'p') ADVANCE(190);
      END_STATE();
    case 179:
      if (lookahead == 'p') ADVANCE(189);
      END_STATE();
    case 180:
      if (lookahead == 'p') ADVANCE(89);
      if (lookahead == 't') ADVANCE(218);
      END_STATE();
    case 181:
      if (lookahead == 'p') ADVANCE(145);
      END_STATE();
    case 182:
      if (lookahead == 'q') ADVANCE(283);
      END_STATE();
    case 183:
      if (lookahead == 'q') ADVANCE(285);
      END_STATE();
    case 184:
      if (lookahead == 'r') ADVANCE(288);
      END_STATE();
    case 185:
      if (lookahead == 'r') ADVANCE(289);
      END_STATE();
    case 186:
      if (lookahead == 'r') ADVANCE(39);
      END_STATE();
    case 187:
      if (lookahead == 'r') ADVANCE(287);
      END_STATE();
    case 188:
      if (lookahead == 'r') ADVANCE(87);
      END_STATE();
    case 189:
      if (lookahead == 'r') ADVANCE(38);
      END_STATE();
    case 190:
      if (lookahead == 'r') ADVANCE(175);
      END_STATE();
    case 191:
      if (lookahead == 'r') ADVANCE(4);
      END_STATE();
    case 192:
      if (lookahead == 'r') ADVANCE(154);
      END_STATE();
    case 193:
      if (lookahead == 'r') ADVANCE(81);
      END_STATE();
    case 194:
      if (lookahead == 'r') ADVANCE(82);
      END_STATE();
    case 195:
      if (lookahead == 'r') ADVANCE(127);
      END_STATE();
    case 196:
      if (lookahead == 'r') ADVANCE(130);
      END_STATE();
    case 197:
      if (lookahead == 's') ADVANCE(71);
      if (lookahead == 't') ADVANCE(275);
      END_STATE();
    case 198:
      if (lookahead == 's') ADVANCE(73);
      END_STATE();
    case 199:
      if (lookahead == 's') ADVANCE(120);
      END_STATE();
    case 200:
      if (lookahead == 's') ADVANCE(124);
      END_STATE();
    case 201:
      if (lookahead == 's') ADVANCE(76);
      END_STATE();
    case 202:
      if (lookahead == 's') ADVANCE(210);
      END_STATE();
    case 203:
      if (lookahead == 's') ADVANCE(79);
      END_STATE();
    case 204:
      if (lookahead == 't') ADVANCE(275);
      END_STATE();
    case 205:
      if (lookahead == 't') ADVANCE(256);
      END_STATE();
    case 206:
      if (lookahead == 't') ADVANCE(274);
      END_STATE();
    case 207:
      if (lookahead == 't') ADVANCE(254);
      END_STATE();
    case 208:
      if (lookahead == 't') ADVANCE(339);
      END_STATE();
    case 209:
      if (lookahead == 't') ADVANCE(276);
      END_STATE();
    case 210:
      if (lookahead == 't') ADVANCE(298);
      END_STATE();
    case 211:
      if (lookahead == 't') ADVANCE(123);
      END_STATE();
    case 212:
      if (lookahead == 't') ADVANCE(3);
      END_STATE();
    case 213:
      if (lookahead == 't') ADVANCE(195);
      END_STATE();
    case 214:
      if (lookahead == 't') ADVANCE(122);
      END_STATE();
    case 215:
      if (lookahead == 't') ADVANCE(126);
      END_STATE();
    case 216:
      if (lookahead == 't') ADVANCE(129);
      END_STATE();
    case 217:
      if (lookahead == 't') ADVANCE(196);
      END_STATE();
    case 218:
      if (lookahead == 'u') ADVANCE(192);
      END_STATE();
    case 219:
      if (lookahead == 'u') ADVANCE(74);
      END_STATE();
    case 220:
      if (lookahead == 'u') ADVANCE(78);
      END_STATE();
    case 221:
      if (lookahead == 'u') ADVANCE(193);
      END_STATE();
    case 222:
      if (lookahead == 'u') ADVANCE(194);
      END_STATE();
    case 223:
      if (lookahead == 'u') ADVANCE(165);
      END_STATE();
    case 224:
      if (lookahead == 'w') ADVANCE(112);
      END_STATE();
    case 225:
      if (lookahead == 'x') ADVANCE(179);
      END_STATE();
    case 226:
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(449);
      END_STATE();
    case 227:
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(15);
      END_STATE();
    case 228:
      if (eof) ADVANCE(229);
      if (lookahead == '"') ADVANCE(15);
      if (lookahead == '(') ADVANCE(292);
      if (lookahead == ',') ADVANCE(245);
      if (lookahead == '-') ADVANCE(258);
      if (lookahead == '/') ADVANCE(20);
      if (lookahead == ':') ADVANCE(26);
      if (lookahead == '<') ADVANCE(324);
      if (lookahead == 'T') ADVANCE(359);
      if (lookahead == '_') ADVANCE(323);
      if (lookahead == 'b') ADVANCE(427);
      if (lookahead == 'c') ADVANCE(361);
      if (lookahead == 'e') ADVANCE(445);
      if (lookahead == 'f') ADVANCE(362);
      if (lookahead == 'i') ADVANCE(389);
      if (lookahead == 'n') ADVANCE(422);
      if (lookahead == 'p') ADVANCE(425);
      if (lookahead == 'r') ADVANCE(377);
      if (lookahead == 't') ADVANCE(426);
      if (lookahead == 'w') ADVANCE(391);
      if (lookahead == '~') ADVANCE(261);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(228)
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(448);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(446);
      END_STATE();
    case 229:
      ACCEPT_TOKEN(ts_builtin_sym_end);
      END_STATE();
    case 230:
      ACCEPT_TOKEN(anon_sym_SLASH_SLASH);
      END_STATE();
    case 231:
      ACCEPT_TOKEN(anon_sym_SLASH_SLASH);
      if (lookahead == '*') ADVANCE(241);
      if (lookahead != 0) ADVANCE(22);
      END_STATE();
    case 232:
      ACCEPT_TOKEN(anon_sym_SLASH_SLASH);
      if (lookahead != 0 &&
          lookahead != '{' &&
          lookahead != '}') ADVANCE(311);
      END_STATE();
    case 233:
      ACCEPT_TOKEN(anon_sym_SLASH_SLASH);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(236);
      END_STATE();
    case 234:
      ACCEPT_TOKEN(aux_sym_comment_token1);
      if (lookahead == '*') ADVANCE(240);
      if (lookahead == '/') ADVANCE(233);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(236);
      END_STATE();
    case 235:
      ACCEPT_TOKEN(aux_sym_comment_token1);
      if (lookahead == '/') ADVANCE(234);
      if (lookahead == '\t' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(235);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(236);
      END_STATE();
    case 236:
      ACCEPT_TOKEN(aux_sym_comment_token1);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(236);
      END_STATE();
    case 237:
      ACCEPT_TOKEN(anon_sym_SLASH_STAR);
      END_STATE();
    case 238:
      ACCEPT_TOKEN(anon_sym_SLASH_STAR);
      if (lookahead == '*') ADVANCE(241);
      if (lookahead != 0 &&
          lookahead != '/') ADVANCE(22);
      END_STATE();
    case 239:
      ACCEPT_TOKEN(anon_sym_SLASH_STAR);
      if (lookahead != 0 &&
          lookahead != '{' &&
          lookahead != '}') ADVANCE(311);
      END_STATE();
    case 240:
      ACCEPT_TOKEN(anon_sym_SLASH_STAR);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(236);
      END_STATE();
    case 241:
      ACCEPT_TOKEN(aux_sym_comment_token2);
      if (lookahead == '*') ADVANCE(241);
      if (lookahead != 0 &&
          lookahead != '/') ADVANCE(22);
      END_STATE();
    case 242:
      ACCEPT_TOKEN(anon_sym_SLASH);
      if (lookahead == '*') ADVANCE(237);
      if (lookahead == '/') ADVANCE(230);
      END_STATE();
    case 243:
      ACCEPT_TOKEN(anon_sym_SLASH);
      if (lookahead == '*') ADVANCE(237);
      if (lookahead == '/') ADVANCE(230);
      if (lookahead == ':') ADVANCE(30);
      END_STATE();
    case 244:
      ACCEPT_TOKEN(anon_sym_SEMI);
      END_STATE();
    case 245:
      ACCEPT_TOKEN(anon_sym_COMMA);
      END_STATE();
    case 246:
      ACCEPT_TOKEN(anon_sym_return);
      END_STATE();
    case 247:
      ACCEPT_TOKEN(anon_sym_return);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(446);
      END_STATE();
    case 248:
      ACCEPT_TOKEN(anon_sym_break);
      END_STATE();
    case 249:
      ACCEPT_TOKEN(anon_sym_break);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(446);
      END_STATE();
    case 250:
      ACCEPT_TOKEN(anon_sym_continue);
      END_STATE();
    case 251:
      ACCEPT_TOKEN(anon_sym_continue);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(446);
      END_STATE();
    case 252:
      ACCEPT_TOKEN(anon_sym_eval);
      END_STATE();
    case 253:
      ACCEPT_TOKEN(anon_sym_eval);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(446);
      END_STATE();
    case 254:
      ACCEPT_TOKEN(anon_sym_print);
      END_STATE();
    case 255:
      ACCEPT_TOKEN(anon_sym_print);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(446);
      END_STATE();
    case 256:
      ACCEPT_TOKEN(anon_sym_not);
      END_STATE();
    case 257:
      ACCEPT_TOKEN(anon_sym_not);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(446);
      END_STATE();
    case 258:
      ACCEPT_TOKEN(anon_sym_DASH);
      END_STATE();
    case 259:
      ACCEPT_TOKEN(anon_sym_DASH);
      if (lookahead == ':') ADVANCE(29);
      END_STATE();
    case 260:
      ACCEPT_TOKEN(anon_sym_DASH);
      if (lookahead == ':') ADVANCE(29);
      if (lookahead == '>') ADVANCE(307);
      END_STATE();
    case 261:
      ACCEPT_TOKEN(anon_sym_TILDE);
      END_STATE();
    case 262:
      ACCEPT_TOKEN(anon_sym_PLUS);
      END_STATE();
    case 263:
      ACCEPT_TOKEN(anon_sym_PLUS);
      if (lookahead == ':') ADVANCE(28);
      END_STATE();
    case 264:
      ACCEPT_TOKEN(anon_sym_STAR);
      END_STATE();
    case 265:
      ACCEPT_TOKEN(anon_sym_STAR);
      if (lookahead == ':') ADVANCE(27);
      END_STATE();
    case 266:
      ACCEPT_TOKEN(anon_sym_CARET);
      if (lookahead == '^') ADVANCE(270);
      END_STATE();
    case 267:
      ACCEPT_TOKEN(anon_sym_div);
      END_STATE();
    case 268:
      ACCEPT_TOKEN(anon_sym_div);
      if (lookahead == ':') ADVANCE(33);
      END_STATE();
    case 269:
      ACCEPT_TOKEN(anon_sym_mod);
      END_STATE();
    case 270:
      ACCEPT_TOKEN(anon_sym_CARET_CARET);
      END_STATE();
    case 271:
      ACCEPT_TOKEN(anon_sym_join);
      END_STATE();
    case 272:
      ACCEPT_TOKEN(anon_sym_diff);
      END_STATE();
    case 273:
      ACCEPT_TOKEN(anon_sym_sdiff);
      END_STATE();
    case 274:
      ACCEPT_TOKEN(anon_sym_meet);
      END_STATE();
    case 275:
      ACCEPT_TOKEN(anon_sym_cat);
      END_STATE();
    case 276:
      ACCEPT_TOKEN(anon_sym_select);
      END_STATE();
    case 277:
      ACCEPT_TOKEN(anon_sym_else);
      END_STATE();
    case 278:
      ACCEPT_TOKEN(anon_sym_else);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(446);
      END_STATE();
    case 279:
      ACCEPT_TOKEN(anon_sym_gt);
      END_STATE();
    case 280:
      ACCEPT_TOKEN(anon_sym_ge);
      END_STATE();
    case 281:
      ACCEPT_TOKEN(anon_sym_lt);
      END_STATE();
    case 282:
      ACCEPT_TOKEN(anon_sym_le);
      END_STATE();
    case 283:
      ACCEPT_TOKEN(anon_sym_eq);
      END_STATE();
    case 284:
      ACCEPT_TOKEN(anon_sym_ne);
      END_STATE();
    case 285:
      ACCEPT_TOKEN(anon_sym_cmpeq);
      END_STATE();
    case 286:
      ACCEPT_TOKEN(anon_sym_cmpne);
      END_STATE();
    case 287:
      ACCEPT_TOKEN(anon_sym_or);
      END_STATE();
    case 288:
      ACCEPT_TOKEN(anon_sym_or);
      if (lookahead == ':') ADVANCE(31);
      END_STATE();
    case 289:
      ACCEPT_TOKEN(anon_sym_xor);
      END_STATE();
    case 290:
      ACCEPT_TOKEN(anon_sym_and);
      END_STATE();
    case 291:
      ACCEPT_TOKEN(anon_sym_and);
      if (lookahead == ':') ADVANCE(32);
      END_STATE();
    case 292:
      ACCEPT_TOKEN(anon_sym_LPAREN);
      END_STATE();
    case 293:
      ACCEPT_TOKEN(anon_sym_RPAREN);
      END_STATE();
    case 294:
      ACCEPT_TOKEN(sym_true);
      END_STATE();
    case 295:
      ACCEPT_TOKEN(sym_true);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(446);
      END_STATE();
    case 296:
      ACCEPT_TOKEN(sym_false);
      END_STATE();
    case 297:
      ACCEPT_TOKEN(sym_false);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(446);
      END_STATE();
    case 298:
      ACCEPT_TOKEN(sym_expression_list);
      END_STATE();
    case 299:
      ACCEPT_TOKEN(anon_sym_function);
      END_STATE();
    case 300:
      ACCEPT_TOKEN(anon_sym_function);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(446);
      END_STATE();
    case 301:
      ACCEPT_TOKEN(anon_sym_endfunction);
      END_STATE();
    case 302:
      ACCEPT_TOKEN(anon_sym_procedure);
      END_STATE();
    case 303:
      ACCEPT_TOKEN(anon_sym_procedure);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(446);
      END_STATE();
    case 304:
      ACCEPT_TOKEN(anon_sym_endprocedure);
      END_STATE();
    case 305:
      ACCEPT_TOKEN(anon_sym_intrinsic);
      END_STATE();
    case 306:
      ACCEPT_TOKEN(anon_sym_intrinsic);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(446);
      END_STATE();
    case 307:
      ACCEPT_TOKEN(anon_sym_DASH_GT);
      END_STATE();
    case 308:
      ACCEPT_TOKEN(anon_sym_LBRACE);
      END_STATE();
    case 309:
      ACCEPT_TOKEN(aux_sym_intrinsic_definition_token1);
      if (lookahead == '*') ADVANCE(239);
      if (lookahead == '/') ADVANCE(232);
      if (lookahead != 0 &&
          lookahead != '{' &&
          lookahead != '}') ADVANCE(311);
      END_STATE();
    case 310:
      ACCEPT_TOKEN(aux_sym_intrinsic_definition_token1);
      if (lookahead == '/') ADVANCE(309);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(310);
      if (lookahead != 0 &&
          lookahead != '{' &&
          lookahead != '}') ADVANCE(311);
      END_STATE();
    case 311:
      ACCEPT_TOKEN(aux_sym_intrinsic_definition_token1);
      if (lookahead != 0 &&
          lookahead != '{' &&
          lookahead != '}') ADVANCE(311);
      END_STATE();
    case 312:
      ACCEPT_TOKEN(anon_sym_RBRACE);
      END_STATE();
    case 313:
      ACCEPT_TOKEN(anon_sym_endintrinsic);
      END_STATE();
    case 314:
      ACCEPT_TOKEN(anon_sym_COLON_EQ);
      END_STATE();
    case 315:
      ACCEPT_TOKEN(anon_sym_PLUS_COLON_EQ);
      END_STATE();
    case 316:
      ACCEPT_TOKEN(anon_sym_DASH_COLON_EQ);
      END_STATE();
    case 317:
      ACCEPT_TOKEN(anon_sym_STAR_COLON_EQ);
      END_STATE();
    case 318:
      ACCEPT_TOKEN(anon_sym_SLASH_COLON_EQ);
      END_STATE();
    case 319:
      ACCEPT_TOKEN(anon_sym_and_COLON_EQ);
      END_STATE();
    case 320:
      ACCEPT_TOKEN(anon_sym_or_COLON_EQ);
      END_STATE();
    case 321:
      ACCEPT_TOKEN(anon_sym_div_COLON_EQ);
      END_STATE();
    case 322:
      ACCEPT_TOKEN(anon_sym__);
      END_STATE();
    case 323:
      ACCEPT_TOKEN(anon_sym__);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(446);
      END_STATE();
    case 324:
      ACCEPT_TOKEN(anon_sym_LT);
      END_STATE();
    case 325:
      ACCEPT_TOKEN(anon_sym_GT);
      END_STATE();
    case 326:
      ACCEPT_TOKEN(anon_sym_DOT);
      END_STATE();
    case 327:
      ACCEPT_TOKEN(anon_sym_COLON_COLON);
      END_STATE();
    case 328:
      ACCEPT_TOKEN(anon_sym_if);
      END_STATE();
    case 329:
      ACCEPT_TOKEN(anon_sym_if);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(446);
      END_STATE();
    case 330:
      ACCEPT_TOKEN(anon_sym_then);
      END_STATE();
    case 331:
      ACCEPT_TOKEN(anon_sym_endif);
      END_STATE();
    case 332:
      ACCEPT_TOKEN(anon_sym_elif);
      END_STATE();
    case 333:
      ACCEPT_TOKEN(anon_sym_elif);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(446);
      END_STATE();
    case 334:
      ACCEPT_TOKEN(sym_for_statement);
      END_STATE();
    case 335:
      ACCEPT_TOKEN(anon_sym_while);
      END_STATE();
    case 336:
      ACCEPT_TOKEN(anon_sym_while);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(446);
      END_STATE();
    case 337:
      ACCEPT_TOKEN(anon_sym_do);
      END_STATE();
    case 338:
      ACCEPT_TOKEN(anon_sym_endwhile);
      END_STATE();
    case 339:
      ACCEPT_TOKEN(anon_sym_repeat);
      END_STATE();
    case 340:
      ACCEPT_TOKEN(anon_sym_repeat);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(446);
      END_STATE();
    case 341:
      ACCEPT_TOKEN(anon_sym_until);
      END_STATE();
    case 342:
      ACCEPT_TOKEN(anon_sym_until);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(446);
      END_STATE();
    case 343:
      ACCEPT_TOKEN(anon_sym_case);
      END_STATE();
    case 344:
      ACCEPT_TOKEN(anon_sym_case);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(446);
      END_STATE();
    case 345:
      ACCEPT_TOKEN(anon_sym_COLON);
      END_STATE();
    case 346:
      ACCEPT_TOKEN(anon_sym_COLON);
      if (lookahead == ':') ADVANCE(327);
      if (lookahead == '=') ADVANCE(314);
      END_STATE();
    case 347:
      ACCEPT_TOKEN(anon_sym_COLON);
      if (lookahead == '=') ADVANCE(314);
      END_STATE();
    case 348:
      ACCEPT_TOKEN(anon_sym_endcase);
      END_STATE();
    case 349:
      ACCEPT_TOKEN(anon_sym_when);
      END_STATE();
    case 350:
      ACCEPT_TOKEN(anon_sym_when);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(446);
      END_STATE();
    case 351:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == ' ') ADVANCE(224);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(446);
      END_STATE();
    case 352:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == ' ') ADVANCE(50);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(446);
      END_STATE();
    case 353:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == ' ') ADVANCE(105);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(446);
      END_STATE();
    case 354:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == ' ') ADVANCE(125);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(446);
      END_STATE();
    case 355:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == ' ') ADVANCE(178);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(446);
      END_STATE();
    case 356:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == ' ') ADVANCE(128);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(446);
      END_STATE();
    case 357:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == ':') ADVANCE(2);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(446);
      END_STATE();
    case 358:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'D') ADVANCE(360);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(446);
      END_STATE();
    case 359:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'O') ADVANCE(358);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(446);
      END_STATE();
    case 360:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'O') ADVANCE(357);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(446);
      END_STATE();
    case 361:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'a') ADVANCE(431);
      if (lookahead == 'o') ADVANCE(413);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(446);
      END_STATE();
    case 362:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'a') ADVANCE(406);
      if (lookahead == 'u') ADVANCE(407);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(446);
      END_STATE();
    case 363:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'a') ADVANCE(406);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(446);
      END_STATE();
    case 364:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'a') ADVANCE(401);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(446);
      END_STATE();
    case 365:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'a') ADVANCE(402);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(446);
      END_STATE();
    case 366:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'a') ADVANCE(436);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(446);
      END_STATE();
    case 367:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'c') ADVANCE(306);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(446);
      END_STATE();
    case 368:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'c') ADVANCE(438);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(446);
      END_STATE();
    case 369:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'c') ADVANCE(381);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(446);
      END_STATE();
    case 370:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'd') ADVANCE(354);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(446);
      END_STATE();
    case 371:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'd') ADVANCE(355);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(446);
      END_STATE();
    case 372:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'd') ADVANCE(444);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(446);
      END_STATE();
    case 373:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'd') ADVANCE(356);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(446);
      END_STATE();
    case 374:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'd') ADVANCE(352);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(446);
      END_STATE();
    case 375:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'd') ADVANCE(351);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(446);
      END_STATE();
    case 376:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'd') ADVANCE(353);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(446);
      END_STATE();
    case 377:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'e') ADVANCE(424);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(446);
      END_STATE();
    case 378:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'e') ADVANCE(344);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(446);
      END_STATE();
    case 379:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'e') ADVANCE(295);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(446);
      END_STATE();
    case 380:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'e') ADVANCE(297);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(446);
      END_STATE();
    case 381:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'e') ADVANCE(372);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(446);
      END_STATE();
    case 382:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'e') ADVANCE(336);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(446);
      END_STATE();
    case 383:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'e') ADVANCE(251);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(446);
      END_STATE();
    case 384:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'e') ADVANCE(303);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(446);
      END_STATE();
    case 385:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'e') ADVANCE(278);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(446);
      END_STATE();
    case 386:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'e') ADVANCE(364);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(446);
      END_STATE();
    case 387:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'e') ADVANCE(366);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(446);
      END_STATE();
    case 388:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'e') ADVANCE(410);
      if (lookahead == 'i') ADVANCE(405);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(446);
      END_STATE();
    case 389:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'f') ADVANCE(329);
      if (lookahead == 'n') ADVANCE(439);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(446);
      END_STATE();
    case 390:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'f') ADVANCE(333);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(446);
      END_STATE();
    case 391:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'h') ADVANCE(396);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(446);
      END_STATE();
    case 392:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'h') ADVANCE(388);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(446);
      END_STATE();
    case 393:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'i') ADVANCE(390);
      if (lookahead == 's') ADVANCE(385);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(446);
      END_STATE();
    case 394:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'i') ADVANCE(423);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(446);
      END_STATE();
    case 395:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'i') ADVANCE(421);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(446);
      END_STATE();
    case 396:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'i') ADVANCE(405);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(446);
      END_STATE();
    case 397:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'i') ADVANCE(367);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(446);
      END_STATE();
    case 398:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'i') ADVANCE(411);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(446);
      END_STATE();
    case 399:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'i') ADVANCE(404);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(446);
      END_STATE();
    case 400:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'i') ADVANCE(416);
      if (lookahead == 'o') ADVANCE(369);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(446);
      END_STATE();
    case 401:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'k') ADVANCE(249);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(446);
      END_STATE();
    case 402:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'l') ADVANCE(253);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(446);
      END_STATE();
    case 403:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'l') ADVANCE(393);
      if (lookahead == 'n') ADVANCE(370);
      if (lookahead == 'v') ADVANCE(365);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(446);
      END_STATE();
    case 404:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'l') ADVANCE(342);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(446);
      END_STATE();
    case 405:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'l') ADVANCE(382);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(446);
      END_STATE();
    case 406:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'l') ADVANCE(433);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(446);
      END_STATE();
    case 407:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'n') ADVANCE(368);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(446);
      END_STATE();
    case 408:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'n') ADVANCE(247);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(446);
      END_STATE();
    case 409:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'n') ADVANCE(300);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(446);
      END_STATE();
    case 410:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'n') ADVANCE(350);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(446);
      END_STATE();
    case 411:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'n') ADVANCE(432);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(446);
      END_STATE();
    case 412:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'n') ADVANCE(370);
      if (lookahead == 'v') ADVANCE(365);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(446);
      END_STATE();
    case 413:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'n') ADVANCE(437);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(446);
      END_STATE();
    case 414:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'n') ADVANCE(371);
      if (lookahead == 'v') ADVANCE(365);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(446);
      END_STATE();
    case 415:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'n') ADVANCE(373);
      if (lookahead == 'v') ADVANCE(365);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(446);
      END_STATE();
    case 416:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'n') ADVANCE(435);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(446);
      END_STATE();
    case 417:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'n') ADVANCE(374);
      if (lookahead == 'v') ADVANCE(365);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(446);
      END_STATE();
    case 418:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'n') ADVANCE(375);
      if (lookahead == 'v') ADVANCE(365);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(446);
      END_STATE();
    case 419:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'n') ADVANCE(440);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(446);
      END_STATE();
    case 420:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'n') ADVANCE(376);
      if (lookahead == 'v') ADVANCE(365);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(446);
      END_STATE();
    case 421:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'n') ADVANCE(443);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(446);
      END_STATE();
    case 422:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'o') ADVANCE(434);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(446);
      END_STATE();
    case 423:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'o') ADVANCE(409);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(446);
      END_STATE();
    case 424:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'p') ADVANCE(387);
      if (lookahead == 't') ADVANCE(442);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(446);
      END_STATE();
    case 425:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'r') ADVANCE(400);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(446);
      END_STATE();
    case 426:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'r') ADVANCE(441);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(446);
      END_STATE();
    case 427:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'r') ADVANCE(386);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(446);
      END_STATE();
    case 428:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'r') ADVANCE(408);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(446);
      END_STATE();
    case 429:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'r') ADVANCE(384);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(446);
      END_STATE();
    case 430:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'r') ADVANCE(398);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(446);
      END_STATE();
    case 431:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 's') ADVANCE(378);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(446);
      END_STATE();
    case 432:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 's') ADVANCE(397);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(446);
      END_STATE();
    case 433:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 's') ADVANCE(380);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(446);
      END_STATE();
    case 434:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 't') ADVANCE(257);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(446);
      END_STATE();
    case 435:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 't') ADVANCE(255);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(446);
      END_STATE();
    case 436:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 't') ADVANCE(340);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(446);
      END_STATE();
    case 437:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 't') ADVANCE(395);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(446);
      END_STATE();
    case 438:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 't') ADVANCE(394);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(446);
      END_STATE();
    case 439:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 't') ADVANCE(430);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(446);
      END_STATE();
    case 440:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 't') ADVANCE(399);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(446);
      END_STATE();
    case 441:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'u') ADVANCE(379);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(446);
      END_STATE();
    case 442:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'u') ADVANCE(428);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(446);
      END_STATE();
    case 443:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'u') ADVANCE(383);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(446);
      END_STATE();
    case 444:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'u') ADVANCE(429);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(446);
      END_STATE();
    case 445:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'v') ADVANCE(365);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(446);
      END_STATE();
    case 446:
      ACCEPT_TOKEN(sym_identifier);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(446);
      END_STATE();
    case 447:
      ACCEPT_TOKEN(sym_string);
      END_STATE();
    case 448:
      ACCEPT_TOKEN(sym_integer);
      if (lookahead == '.') ADVANCE(226);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(448);
      END_STATE();
    case 449:
      ACCEPT_TOKEN(sym_real);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(449);
      END_STATE();
    default:
      return false;
  }
}

static const TSLexMode ts_lex_modes[STATE_COUNT] = {
  [0] = {.lex_state = 0},
  [1] = {.lex_state = 228},
  [2] = {.lex_state = 7},
  [3] = {.lex_state = 7},
  [4] = {.lex_state = 8},
  [5] = {.lex_state = 9},
  [6] = {.lex_state = 9},
  [7] = {.lex_state = 10},
  [8] = {.lex_state = 10},
  [9] = {.lex_state = 11},
  [10] = {.lex_state = 12},
  [11] = {.lex_state = 12},
  [12] = {.lex_state = 11},
  [13] = {.lex_state = 6},
  [14] = {.lex_state = 228},
  [15] = {.lex_state = 228},
  [16] = {.lex_state = 228},
  [17] = {.lex_state = 228},
  [18] = {.lex_state = 6},
  [19] = {.lex_state = 8},
  [20] = {.lex_state = 8},
  [21] = {.lex_state = 228},
  [22] = {.lex_state = 13},
  [23] = {.lex_state = 228},
  [24] = {.lex_state = 13},
  [25] = {.lex_state = 9},
  [26] = {.lex_state = 228},
  [27] = {.lex_state = 228},
  [28] = {.lex_state = 228},
  [29] = {.lex_state = 9},
  [30] = {.lex_state = 16},
  [31] = {.lex_state = 17},
  [32] = {.lex_state = 16},
  [33] = {.lex_state = 16},
  [34] = {.lex_state = 17},
  [35] = {.lex_state = 17},
  [36] = {.lex_state = 17},
  [37] = {.lex_state = 17},
  [38] = {.lex_state = 17},
  [39] = {.lex_state = 17},
  [40] = {.lex_state = 17},
  [41] = {.lex_state = 17},
  [42] = {.lex_state = 17},
  [43] = {.lex_state = 17},
  [44] = {.lex_state = 17},
  [45] = {.lex_state = 17},
  [46] = {.lex_state = 17},
  [47] = {.lex_state = 17},
  [48] = {.lex_state = 17},
  [49] = {.lex_state = 17},
  [50] = {.lex_state = 17},
  [51] = {.lex_state = 17},
  [52] = {.lex_state = 17},
  [53] = {.lex_state = 18},
  [54] = {.lex_state = 18},
  [55] = {.lex_state = 18},
  [56] = {.lex_state = 17},
  [57] = {.lex_state = 18},
  [58] = {.lex_state = 17},
  [59] = {.lex_state = 17},
  [60] = {.lex_state = 19},
  [61] = {.lex_state = 19},
  [62] = {.lex_state = 17},
  [63] = {.lex_state = 17},
  [64] = {.lex_state = 7},
  [65] = {.lex_state = 17},
  [66] = {.lex_state = 17},
  [67] = {.lex_state = 17},
  [68] = {.lex_state = 7},
  [69] = {.lex_state = 17},
  [70] = {.lex_state = 10},
  [71] = {.lex_state = 10},
  [72] = {.lex_state = 17},
  [73] = {.lex_state = 9},
  [74] = {.lex_state = 17},
  [75] = {.lex_state = 12},
  [76] = {.lex_state = 12},
  [77] = {.lex_state = 17},
  [78] = {.lex_state = 228},
  [79] = {.lex_state = 17},
  [80] = {.lex_state = 6},
  [81] = {.lex_state = 11},
  [82] = {.lex_state = 17},
  [83] = {.lex_state = 11},
  [84] = {.lex_state = 6},
  [85] = {.lex_state = 13},
  [86] = {.lex_state = 228},
  [87] = {.lex_state = 17},
  [88] = {.lex_state = 8},
  [89] = {.lex_state = 17},
  [90] = {.lex_state = 8},
  [91] = {.lex_state = 13},
  [92] = {.lex_state = 8},
  [93] = {.lex_state = 9},
  [94] = {.lex_state = 8},
  [95] = {.lex_state = 8},
  [96] = {.lex_state = 228},
  [97] = {.lex_state = 228},
  [98] = {.lex_state = 228},
  [99] = {.lex_state = 17},
  [100] = {.lex_state = 14},
  [101] = {.lex_state = 14},
  [102] = {.lex_state = 5},
  [103] = {.lex_state = 5},
  [104] = {.lex_state = 5},
  [105] = {.lex_state = 5},
  [106] = {.lex_state = 5},
  [107] = {.lex_state = 5},
  [108] = {.lex_state = 5},
  [109] = {.lex_state = 5},
  [110] = {.lex_state = 5},
  [111] = {.lex_state = 5},
  [112] = {.lex_state = 5},
  [113] = {.lex_state = 5},
  [114] = {.lex_state = 5},
  [115] = {.lex_state = 5},
  [116] = {.lex_state = 5},
  [117] = {.lex_state = 5},
  [118] = {.lex_state = 5},
  [119] = {.lex_state = 5},
  [120] = {.lex_state = 5},
  [121] = {.lex_state = 5},
  [122] = {.lex_state = 5},
  [123] = {.lex_state = 5},
  [124] = {.lex_state = 5},
  [125] = {.lex_state = 5},
  [126] = {.lex_state = 5},
  [127] = {.lex_state = 5},
  [128] = {.lex_state = 5},
  [129] = {.lex_state = 5},
  [130] = {.lex_state = 5},
  [131] = {.lex_state = 5},
  [132] = {.lex_state = 5},
  [133] = {.lex_state = 5},
  [134] = {.lex_state = 5},
  [135] = {.lex_state = 5},
  [136] = {.lex_state = 0},
  [137] = {.lex_state = 0},
  [138] = {.lex_state = 0},
  [139] = {.lex_state = 0},
  [140] = {.lex_state = 24},
  [141] = {.lex_state = 0},
  [142] = {.lex_state = 228},
  [143] = {.lex_state = 0},
  [144] = {.lex_state = 0},
  [145] = {.lex_state = 0},
  [146] = {.lex_state = 0},
  [147] = {.lex_state = 228},
  [148] = {.lex_state = 0},
  [149] = {.lex_state = 0},
  [150] = {.lex_state = 0},
  [151] = {.lex_state = 0},
  [152] = {.lex_state = 0},
  [153] = {.lex_state = 0},
  [154] = {.lex_state = 0},
  [155] = {.lex_state = 0},
  [156] = {.lex_state = 228},
  [157] = {.lex_state = 228},
  [158] = {.lex_state = 0},
  [159] = {.lex_state = 228},
  [160] = {.lex_state = 0},
  [161] = {.lex_state = 0},
  [162] = {.lex_state = 0},
  [163] = {.lex_state = 0},
  [164] = {.lex_state = 0},
  [165] = {.lex_state = 228},
  [166] = {.lex_state = 228},
  [167] = {.lex_state = 228},
  [168] = {.lex_state = 24},
  [169] = {.lex_state = 0},
  [170] = {.lex_state = 0},
  [171] = {.lex_state = 24},
  [172] = {.lex_state = 0},
  [173] = {.lex_state = 24},
  [174] = {.lex_state = 0},
  [175] = {.lex_state = 0},
  [176] = {.lex_state = 0},
  [177] = {.lex_state = 0},
  [178] = {.lex_state = 0},
  [179] = {.lex_state = 0},
  [180] = {.lex_state = 310},
  [181] = {.lex_state = 0},
  [182] = {.lex_state = 0},
  [183] = {.lex_state = 0},
  [184] = {.lex_state = 0},
  [185] = {.lex_state = 0},
  [186] = {.lex_state = 0},
  [187] = {.lex_state = 0},
  [188] = {.lex_state = 0},
  [189] = {.lex_state = 0},
  [190] = {.lex_state = 24},
  [191] = {.lex_state = 0},
  [192] = {.lex_state = 0},
  [193] = {.lex_state = 0},
  [194] = {.lex_state = 0},
  [195] = {.lex_state = 0},
  [196] = {.lex_state = 0},
  [197] = {.lex_state = 24},
  [198] = {.lex_state = 0},
  [199] = {.lex_state = 0},
  [200] = {.lex_state = 24},
  [201] = {.lex_state = 0},
  [202] = {.lex_state = 0},
  [203] = {.lex_state = 235},
  [204] = {.lex_state = 0},
  [205] = {.lex_state = 0},
  [206] = {.lex_state = 0},
  [207] = {.lex_state = 310},
  [208] = {.lex_state = 0},
  [209] = {.lex_state = 24},
  [210] = {.lex_state = 0},
  [211] = {.lex_state = 0},
  [212] = {.lex_state = 0},
  [213] = {.lex_state = 0},
  [214] = {.lex_state = 0},
  [215] = {.lex_state = 0},
  [216] = {.lex_state = 0},
  [217] = {.lex_state = 0},
  [218] = {.lex_state = 0},
  [219] = {.lex_state = 0},
  [220] = {.lex_state = 21},
  [221] = {.lex_state = 24},
  [222] = {.lex_state = 0},
  [223] = {.lex_state = 0},
  [224] = {.lex_state = 0},
  [225] = {.lex_state = 0},
  [226] = {(TSStateId)(-1)},
  [227] = {(TSStateId)(-1)},
};

static const uint16_t ts_parse_table[LARGE_STATE_COUNT][SYMBOL_COUNT] = {
  [0] = {
    [sym_comment] = STATE(0),
    [ts_builtin_sym_end] = ACTIONS(1),
    [anon_sym_SLASH_SLASH] = ACTIONS(3),
    [anon_sym_SLASH_STAR] = ACTIONS(5),
    [anon_sym_SLASH] = ACTIONS(1),
    [anon_sym_SEMI] = ACTIONS(1),
    [anon_sym_COMMA] = ACTIONS(1),
    [anon_sym_return] = ACTIONS(1),
    [anon_sym_break] = ACTIONS(1),
    [anon_sym_continue] = ACTIONS(1),
    [anon_sym_eval] = ACTIONS(1),
    [anon_sym_print] = ACTIONS(1),
    [anon_sym_not] = ACTIONS(1),
    [anon_sym_DASH] = ACTIONS(1),
    [anon_sym_TILDE] = ACTIONS(1),
    [anon_sym_PLUS] = ACTIONS(1),
    [anon_sym_STAR] = ACTIONS(1),
    [anon_sym_CARET] = ACTIONS(1),
    [anon_sym_div] = ACTIONS(1),
    [anon_sym_mod] = ACTIONS(1),
    [anon_sym_CARET_CARET] = ACTIONS(1),
    [anon_sym_join] = ACTIONS(1),
    [anon_sym_diff] = ACTIONS(1),
    [anon_sym_sdiff] = ACTIONS(1),
    [anon_sym_meet] = ACTIONS(1),
    [anon_sym_cat] = ACTIONS(1),
    [anon_sym_select] = ACTIONS(1),
    [anon_sym_else] = ACTIONS(1),
    [anon_sym_gt] = ACTIONS(1),
    [anon_sym_ge] = ACTIONS(1),
    [anon_sym_lt] = ACTIONS(1),
    [anon_sym_le] = ACTIONS(1),
    [anon_sym_eq] = ACTIONS(1),
    [anon_sym_ne] = ACTIONS(1),
    [anon_sym_cmpeq] = ACTIONS(1),
    [anon_sym_cmpne] = ACTIONS(1),
    [anon_sym_or] = ACTIONS(1),
    [anon_sym_xor] = ACTIONS(1),
    [anon_sym_and] = ACTIONS(1),
    [anon_sym_LPAREN] = ACTIONS(1),
    [anon_sym_RPAREN] = ACTIONS(1),
    [sym_true] = ACTIONS(1),
    [sym_false] = ACTIONS(1),
    [sym_expression_list] = ACTIONS(1),
    [anon_sym_function] = ACTIONS(1),
    [anon_sym_endfunction] = ACTIONS(1),
    [anon_sym_procedure] = ACTIONS(1),
    [anon_sym_endprocedure] = ACTIONS(1),
    [anon_sym_intrinsic] = ACTIONS(1),
    [anon_sym_DASH_GT] = ACTIONS(1),
    [anon_sym_LBRACE] = ACTIONS(1),
    [anon_sym_RBRACE] = ACTIONS(1),
    [anon_sym_endintrinsic] = ACTIONS(1),
    [anon_sym_COLON_EQ] = ACTIONS(1),
    [anon_sym_PLUS_COLON_EQ] = ACTIONS(1),
    [anon_sym_DASH_COLON_EQ] = ACTIONS(1),
    [anon_sym_STAR_COLON_EQ] = ACTIONS(1),
    [anon_sym_SLASH_COLON_EQ] = ACTIONS(1),
    [anon_sym_and_COLON_EQ] = ACTIONS(1),
    [anon_sym_or_COLON_EQ] = ACTIONS(1),
    [anon_sym_div_COLON_EQ] = ACTIONS(1),
    [anon_sym__] = ACTIONS(1),
    [anon_sym_LT] = ACTIONS(1),
    [anon_sym_GT] = ACTIONS(1),
    [anon_sym_DOT] = ACTIONS(1),
    [anon_sym_COLON_COLON] = ACTIONS(1),
    [anon_sym_if] = ACTIONS(1),
    [anon_sym_then] = ACTIONS(1),
    [anon_sym_endif] = ACTIONS(1),
    [anon_sym_elif] = ACTIONS(1),
    [sym_for_statement] = ACTIONS(1),
    [anon_sym_while] = ACTIONS(1),
    [anon_sym_do] = ACTIONS(1),
    [anon_sym_endwhile] = ACTIONS(1),
    [anon_sym_repeat] = ACTIONS(1),
    [anon_sym_until] = ACTIONS(1),
    [anon_sym_case] = ACTIONS(1),
    [anon_sym_COLON] = ACTIONS(1),
    [anon_sym_endcase] = ACTIONS(1),
    [anon_sym_when] = ACTIONS(1),
    [sym_string] = ACTIONS(1),
    [sym_integer] = ACTIONS(1),
    [sym_real] = ACTIONS(1),
  },
  [1] = {
    [sym_program] = STATE(183),
    [sym_comment] = STATE(1),
    [sym__statement] = STATE(86),
    [sym_expression_statement] = STATE(194),
    [sym_return_statement] = STATE(194),
    [sym_break_statement] = STATE(194),
    [sym_continue_statement] = STATE(194),
    [sym_eval_statement] = STATE(194),
    [sym_print_statement] = STATE(194),
    [sym_unary_operator] = STATE(36),
    [sym_binary_operator] = STATE(36),
    [sym_ternary_operator] = STATE(36),
    [sym_comparison_operator] = STATE(38),
    [sym_boolean_operator] = STATE(38),
    [sym_expression] = STATE(99),
    [sym_parenthesized_expression] = STATE(36),
    [sym_primary_expression] = STATE(53),
    [sym__definition] = STATE(194),
    [sym_function_definition] = STATE(189),
    [sym_procedure_definition] = STATE(189),
    [sym_intrinsic_definition] = STATE(189),
    [sym_call] = STATE(36),
    [sym__assignment] = STATE(194),
    [sym_assignment] = STATE(196),
    [sym_augmented_assignment] = STATE(196),
    [sym_gen_expression] = STATE(157),
    [sym_if_statement] = STATE(194),
    [sym_while_statement] = STATE(194),
    [sym_repeat_statement] = STATE(194),
    [sym_case_statement] = STATE(194),
    [aux_sym_program_repeat1] = STATE(28),
    [ts_builtin_sym_end] = ACTIONS(7),
    [anon_sym_SLASH_SLASH] = ACTIONS(3),
    [anon_sym_SLASH_STAR] = ACTIONS(5),
    [anon_sym_return] = ACTIONS(9),
    [anon_sym_break] = ACTIONS(11),
    [anon_sym_continue] = ACTIONS(13),
    [anon_sym_eval] = ACTIONS(15),
    [anon_sym_print] = ACTIONS(17),
    [anon_sym_not] = ACTIONS(19),
    [anon_sym_DASH] = ACTIONS(21),
    [anon_sym_TILDE] = ACTIONS(23),
    [anon_sym_LPAREN] = ACTIONS(25),
    [sym_true] = ACTIONS(27),
    [sym_false] = ACTIONS(27),
    [anon_sym_function] = ACTIONS(29),
    [anon_sym_procedure] = ACTIONS(31),
    [anon_sym_intrinsic] = ACTIONS(33),
    [anon_sym__] = ACTIONS(35),
    [anon_sym_if] = ACTIONS(37),
    [sym_for_statement] = ACTIONS(39),
    [anon_sym_while] = ACTIONS(41),
    [anon_sym_repeat] = ACTIONS(43),
    [anon_sym_case] = ACTIONS(45),
    [sym_identifier] = ACTIONS(47),
    [sym_string] = ACTIONS(49),
    [sym_integer] = ACTIONS(27),
    [sym_real] = ACTIONS(49),
  },
};

static const uint16_t ts_small_parse_table[] = {
  [0] = 35,
    ACTIONS(3), 1,
      anon_sym_SLASH_SLASH,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(51), 1,
      anon_sym_return,
    ACTIONS(54), 1,
      anon_sym_break,
    ACTIONS(57), 1,
      anon_sym_continue,
    ACTIONS(60), 1,
      anon_sym_eval,
    ACTIONS(63), 1,
      anon_sym_print,
    ACTIONS(66), 1,
      anon_sym_not,
    ACTIONS(69), 1,
      anon_sym_DASH,
    ACTIONS(72), 1,
      anon_sym_TILDE,
    ACTIONS(77), 1,
      anon_sym_LPAREN,
    ACTIONS(83), 1,
      anon_sym_function,
    ACTIONS(86), 1,
      anon_sym_procedure,
    ACTIONS(89), 1,
      anon_sym_intrinsic,
    ACTIONS(92), 1,
      anon_sym__,
    ACTIONS(95), 1,
      anon_sym_if,
    ACTIONS(98), 1,
      anon_sym_endif,
    ACTIONS(100), 1,
      sym_for_statement,
    ACTIONS(103), 1,
      anon_sym_while,
    ACTIONS(106), 1,
      anon_sym_repeat,
    ACTIONS(109), 1,
      anon_sym_case,
    ACTIONS(112), 1,
      sym_identifier,
    STATE(53), 1,
      sym_primary_expression,
    STATE(64), 1,
      sym__statement,
    STATE(99), 1,
      sym_expression,
    STATE(157), 1,
      sym_gen_expression,
    ACTIONS(75), 2,
      anon_sym_else,
      anon_sym_elif,
    ACTIONS(115), 2,
      sym_string,
      sym_real,
    STATE(2), 2,
      sym_comment,
      aux_sym_block_repeat1,
    STATE(38), 2,
      sym_comparison_operator,
      sym_boolean_operator,
    STATE(196), 2,
      sym_assignment,
      sym_augmented_assignment,
    ACTIONS(80), 3,
      sym_true,
      sym_false,
      sym_integer,
    STATE(189), 3,
      sym_function_definition,
      sym_procedure_definition,
      sym_intrinsic_definition,
    STATE(36), 5,
      sym_unary_operator,
      sym_binary_operator,
      sym_ternary_operator,
      sym_parenthesized_expression,
      sym_call,
    STATE(223), 12,
      sym_expression_statement,
      sym_return_statement,
      sym_break_statement,
      sym_continue_statement,
      sym_eval_statement,
      sym_print_statement,
      sym__definition,
      sym__assignment,
      sym_if_statement,
      sym_while_statement,
      sym_repeat_statement,
      sym_case_statement,
  [130] = 36,
    ACTIONS(3), 1,
      anon_sym_SLASH_SLASH,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(9), 1,
      anon_sym_return,
    ACTIONS(11), 1,
      anon_sym_break,
    ACTIONS(13), 1,
      anon_sym_continue,
    ACTIONS(15), 1,
      anon_sym_eval,
    ACTIONS(17), 1,
      anon_sym_print,
    ACTIONS(19), 1,
      anon_sym_not,
    ACTIONS(21), 1,
      anon_sym_DASH,
    ACTIONS(23), 1,
      anon_sym_TILDE,
    ACTIONS(25), 1,
      anon_sym_LPAREN,
    ACTIONS(29), 1,
      anon_sym_function,
    ACTIONS(31), 1,
      anon_sym_procedure,
    ACTIONS(33), 1,
      anon_sym_intrinsic,
    ACTIONS(35), 1,
      anon_sym__,
    ACTIONS(37), 1,
      anon_sym_if,
    ACTIONS(41), 1,
      anon_sym_while,
    ACTIONS(43), 1,
      anon_sym_repeat,
    ACTIONS(45), 1,
      anon_sym_case,
    ACTIONS(47), 1,
      sym_identifier,
    ACTIONS(120), 1,
      anon_sym_endif,
    ACTIONS(122), 1,
      sym_for_statement,
    STATE(2), 1,
      aux_sym_block_repeat1,
    STATE(3), 1,
      sym_comment,
    STATE(53), 1,
      sym_primary_expression,
    STATE(64), 1,
      sym__statement,
    STATE(99), 1,
      sym_expression,
    STATE(157), 1,
      sym_gen_expression,
    ACTIONS(49), 2,
      sym_string,
      sym_real,
    ACTIONS(118), 2,
      anon_sym_else,
      anon_sym_elif,
    STATE(38), 2,
      sym_comparison_operator,
      sym_boolean_operator,
    STATE(196), 2,
      sym_assignment,
      sym_augmented_assignment,
    ACTIONS(27), 3,
      sym_true,
      sym_false,
      sym_integer,
    STATE(189), 3,
      sym_function_definition,
      sym_procedure_definition,
      sym_intrinsic_definition,
    STATE(36), 5,
      sym_unary_operator,
      sym_binary_operator,
      sym_ternary_operator,
      sym_parenthesized_expression,
      sym_call,
    STATE(223), 12,
      sym_expression_statement,
      sym_return_statement,
      sym_break_statement,
      sym_continue_statement,
      sym_eval_statement,
      sym_print_statement,
      sym__definition,
      sym__assignment,
      sym_if_statement,
      sym_while_statement,
      sym_repeat_statement,
      sym_case_statement,
  [262] = 36,
    ACTIONS(3), 1,
      anon_sym_SLASH_SLASH,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(9), 1,
      anon_sym_return,
    ACTIONS(11), 1,
      anon_sym_break,
    ACTIONS(13), 1,
      anon_sym_continue,
    ACTIONS(15), 1,
      anon_sym_eval,
    ACTIONS(17), 1,
      anon_sym_print,
    ACTIONS(19), 1,
      anon_sym_not,
    ACTIONS(21), 1,
      anon_sym_DASH,
    ACTIONS(23), 1,
      anon_sym_TILDE,
    ACTIONS(25), 1,
      anon_sym_LPAREN,
    ACTIONS(29), 1,
      anon_sym_function,
    ACTIONS(31), 1,
      anon_sym_procedure,
    ACTIONS(33), 1,
      anon_sym_intrinsic,
    ACTIONS(35), 1,
      anon_sym__,
    ACTIONS(37), 1,
      anon_sym_if,
    ACTIONS(41), 1,
      anon_sym_while,
    ACTIONS(43), 1,
      anon_sym_repeat,
    ACTIONS(45), 1,
      anon_sym_case,
    ACTIONS(47), 1,
      sym_identifier,
    ACTIONS(124), 1,
      anon_sym_endprocedure,
    ACTIONS(126), 1,
      sym_for_statement,
    STATE(4), 1,
      sym_comment,
    STATE(20), 1,
      aux_sym_block_repeat1,
    STATE(53), 1,
      sym_primary_expression,
    STATE(92), 1,
      sym__statement,
    STATE(99), 1,
      sym_expression,
    STATE(157), 1,
      sym_gen_expression,
    STATE(192), 1,
      sym_block,
    ACTIONS(49), 2,
      sym_string,
      sym_real,
    STATE(38), 2,
      sym_comparison_operator,
      sym_boolean_operator,
    STATE(196), 2,
      sym_assignment,
      sym_augmented_assignment,
    ACTIONS(27), 3,
      sym_true,
      sym_false,
      sym_integer,
    STATE(189), 3,
      sym_function_definition,
      sym_procedure_definition,
      sym_intrinsic_definition,
    STATE(36), 5,
      sym_unary_operator,
      sym_binary_operator,
      sym_ternary_operator,
      sym_parenthesized_expression,
      sym_call,
    STATE(222), 12,
      sym_expression_statement,
      sym_return_statement,
      sym_break_statement,
      sym_continue_statement,
      sym_eval_statement,
      sym_print_statement,
      sym__definition,
      sym__assignment,
      sym_if_statement,
      sym_while_statement,
      sym_repeat_statement,
      sym_case_statement,
  [393] = 36,
    ACTIONS(3), 1,
      anon_sym_SLASH_SLASH,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(9), 1,
      anon_sym_return,
    ACTIONS(11), 1,
      anon_sym_break,
    ACTIONS(13), 1,
      anon_sym_continue,
    ACTIONS(15), 1,
      anon_sym_eval,
    ACTIONS(17), 1,
      anon_sym_print,
    ACTIONS(19), 1,
      anon_sym_not,
    ACTIONS(21), 1,
      anon_sym_DASH,
    ACTIONS(23), 1,
      anon_sym_TILDE,
    ACTIONS(25), 1,
      anon_sym_LPAREN,
    ACTIONS(29), 1,
      anon_sym_function,
    ACTIONS(31), 1,
      anon_sym_procedure,
    ACTIONS(33), 1,
      anon_sym_intrinsic,
    ACTIONS(35), 1,
      anon_sym__,
    ACTIONS(37), 1,
      anon_sym_if,
    ACTIONS(41), 1,
      anon_sym_while,
    ACTIONS(43), 1,
      anon_sym_repeat,
    ACTIONS(45), 1,
      anon_sym_case,
    ACTIONS(47), 1,
      sym_identifier,
    ACTIONS(128), 1,
      anon_sym_endintrinsic,
    ACTIONS(130), 1,
      sym_for_statement,
    STATE(5), 1,
      sym_comment,
    STATE(25), 1,
      aux_sym_block_repeat1,
    STATE(53), 1,
      sym_primary_expression,
    STATE(93), 1,
      sym__statement,
    STATE(99), 1,
      sym_expression,
    STATE(157), 1,
      sym_gen_expression,
    STATE(174), 1,
      sym_block,
    ACTIONS(49), 2,
      sym_string,
      sym_real,
    STATE(38), 2,
      sym_comparison_operator,
      sym_boolean_operator,
    STATE(196), 2,
      sym_assignment,
      sym_augmented_assignment,
    ACTIONS(27), 3,
      sym_true,
      sym_false,
      sym_integer,
    STATE(189), 3,
      sym_function_definition,
      sym_procedure_definition,
      sym_intrinsic_definition,
    STATE(36), 5,
      sym_unary_operator,
      sym_binary_operator,
      sym_ternary_operator,
      sym_parenthesized_expression,
      sym_call,
    STATE(210), 12,
      sym_expression_statement,
      sym_return_statement,
      sym_break_statement,
      sym_continue_statement,
      sym_eval_statement,
      sym_print_statement,
      sym__definition,
      sym__assignment,
      sym_if_statement,
      sym_while_statement,
      sym_repeat_statement,
      sym_case_statement,
  [524] = 36,
    ACTIONS(3), 1,
      anon_sym_SLASH_SLASH,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(9), 1,
      anon_sym_return,
    ACTIONS(11), 1,
      anon_sym_break,
    ACTIONS(13), 1,
      anon_sym_continue,
    ACTIONS(15), 1,
      anon_sym_eval,
    ACTIONS(17), 1,
      anon_sym_print,
    ACTIONS(19), 1,
      anon_sym_not,
    ACTIONS(21), 1,
      anon_sym_DASH,
    ACTIONS(23), 1,
      anon_sym_TILDE,
    ACTIONS(25), 1,
      anon_sym_LPAREN,
    ACTIONS(29), 1,
      anon_sym_function,
    ACTIONS(31), 1,
      anon_sym_procedure,
    ACTIONS(33), 1,
      anon_sym_intrinsic,
    ACTIONS(35), 1,
      anon_sym__,
    ACTIONS(37), 1,
      anon_sym_if,
    ACTIONS(41), 1,
      anon_sym_while,
    ACTIONS(43), 1,
      anon_sym_repeat,
    ACTIONS(45), 1,
      anon_sym_case,
    ACTIONS(47), 1,
      sym_identifier,
    ACTIONS(130), 1,
      sym_for_statement,
    ACTIONS(132), 1,
      anon_sym_endintrinsic,
    STATE(6), 1,
      sym_comment,
    STATE(25), 1,
      aux_sym_block_repeat1,
    STATE(53), 1,
      sym_primary_expression,
    STATE(93), 1,
      sym__statement,
    STATE(99), 1,
      sym_expression,
    STATE(157), 1,
      sym_gen_expression,
    STATE(178), 1,
      sym_block,
    ACTIONS(49), 2,
      sym_string,
      sym_real,
    STATE(38), 2,
      sym_comparison_operator,
      sym_boolean_operator,
    STATE(196), 2,
      sym_assignment,
      sym_augmented_assignment,
    ACTIONS(27), 3,
      sym_true,
      sym_false,
      sym_integer,
    STATE(189), 3,
      sym_function_definition,
      sym_procedure_definition,
      sym_intrinsic_definition,
    STATE(36), 5,
      sym_unary_operator,
      sym_binary_operator,
      sym_ternary_operator,
      sym_parenthesized_expression,
      sym_call,
    STATE(210), 12,
      sym_expression_statement,
      sym_return_statement,
      sym_break_statement,
      sym_continue_statement,
      sym_eval_statement,
      sym_print_statement,
      sym__definition,
      sym__assignment,
      sym_if_statement,
      sym_while_statement,
      sym_repeat_statement,
      sym_case_statement,
  [655] = 35,
    ACTIONS(3), 1,
      anon_sym_SLASH_SLASH,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(51), 1,
      anon_sym_return,
    ACTIONS(54), 1,
      anon_sym_break,
    ACTIONS(57), 1,
      anon_sym_continue,
    ACTIONS(60), 1,
      anon_sym_eval,
    ACTIONS(63), 1,
      anon_sym_print,
    ACTIONS(66), 1,
      anon_sym_not,
    ACTIONS(69), 1,
      anon_sym_DASH,
    ACTIONS(72), 1,
      anon_sym_TILDE,
    ACTIONS(75), 1,
      anon_sym_when,
    ACTIONS(77), 1,
      anon_sym_LPAREN,
    ACTIONS(83), 1,
      anon_sym_function,
    ACTIONS(86), 1,
      anon_sym_procedure,
    ACTIONS(89), 1,
      anon_sym_intrinsic,
    ACTIONS(92), 1,
      anon_sym__,
    ACTIONS(95), 1,
      anon_sym_if,
    ACTIONS(98), 1,
      anon_sym_endcase,
    ACTIONS(103), 1,
      anon_sym_while,
    ACTIONS(106), 1,
      anon_sym_repeat,
    ACTIONS(109), 1,
      anon_sym_case,
    ACTIONS(112), 1,
      sym_identifier,
    ACTIONS(134), 1,
      sym_for_statement,
    STATE(53), 1,
      sym_primary_expression,
    STATE(70), 1,
      sym__statement,
    STATE(99), 1,
      sym_expression,
    STATE(157), 1,
      sym_gen_expression,
    ACTIONS(115), 2,
      sym_string,
      sym_real,
    STATE(7), 2,
      sym_comment,
      aux_sym_block_repeat1,
    STATE(38), 2,
      sym_comparison_operator,
      sym_boolean_operator,
    STATE(196), 2,
      sym_assignment,
      sym_augmented_assignment,
    ACTIONS(80), 3,
      sym_true,
      sym_false,
      sym_integer,
    STATE(189), 3,
      sym_function_definition,
      sym_procedure_definition,
      sym_intrinsic_definition,
    STATE(36), 5,
      sym_unary_operator,
      sym_binary_operator,
      sym_ternary_operator,
      sym_parenthesized_expression,
      sym_call,
    STATE(213), 12,
      sym_expression_statement,
      sym_return_statement,
      sym_break_statement,
      sym_continue_statement,
      sym_eval_statement,
      sym_print_statement,
      sym__definition,
      sym__assignment,
      sym_if_statement,
      sym_while_statement,
      sym_repeat_statement,
      sym_case_statement,
  [784] = 36,
    ACTIONS(3), 1,
      anon_sym_SLASH_SLASH,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(9), 1,
      anon_sym_return,
    ACTIONS(11), 1,
      anon_sym_break,
    ACTIONS(13), 1,
      anon_sym_continue,
    ACTIONS(15), 1,
      anon_sym_eval,
    ACTIONS(17), 1,
      anon_sym_print,
    ACTIONS(19), 1,
      anon_sym_not,
    ACTIONS(21), 1,
      anon_sym_DASH,
    ACTIONS(23), 1,
      anon_sym_TILDE,
    ACTIONS(25), 1,
      anon_sym_LPAREN,
    ACTIONS(29), 1,
      anon_sym_function,
    ACTIONS(31), 1,
      anon_sym_procedure,
    ACTIONS(33), 1,
      anon_sym_intrinsic,
    ACTIONS(35), 1,
      anon_sym__,
    ACTIONS(37), 1,
      anon_sym_if,
    ACTIONS(41), 1,
      anon_sym_while,
    ACTIONS(43), 1,
      anon_sym_repeat,
    ACTIONS(45), 1,
      anon_sym_case,
    ACTIONS(47), 1,
      sym_identifier,
    ACTIONS(118), 1,
      anon_sym_when,
    ACTIONS(120), 1,
      anon_sym_endcase,
    ACTIONS(137), 1,
      sym_for_statement,
    STATE(7), 1,
      aux_sym_block_repeat1,
    STATE(8), 1,
      sym_comment,
    STATE(53), 1,
      sym_primary_expression,
    STATE(70), 1,
      sym__statement,
    STATE(99), 1,
      sym_expression,
    STATE(157), 1,
      sym_gen_expression,
    ACTIONS(49), 2,
      sym_string,
      sym_real,
    STATE(38), 2,
      sym_comparison_operator,
      sym_boolean_operator,
    STATE(196), 2,
      sym_assignment,
      sym_augmented_assignment,
    ACTIONS(27), 3,
      sym_true,
      sym_false,
      sym_integer,
    STATE(189), 3,
      sym_function_definition,
      sym_procedure_definition,
      sym_intrinsic_definition,
    STATE(36), 5,
      sym_unary_operator,
      sym_binary_operator,
      sym_ternary_operator,
      sym_parenthesized_expression,
      sym_call,
    STATE(213), 12,
      sym_expression_statement,
      sym_return_statement,
      sym_break_statement,
      sym_continue_statement,
      sym_eval_statement,
      sym_print_statement,
      sym__definition,
      sym__assignment,
      sym_if_statement,
      sym_while_statement,
      sym_repeat_statement,
      sym_case_statement,
  [915] = 35,
    ACTIONS(3), 1,
      anon_sym_SLASH_SLASH,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(9), 1,
      anon_sym_return,
    ACTIONS(11), 1,
      anon_sym_break,
    ACTIONS(13), 1,
      anon_sym_continue,
    ACTIONS(15), 1,
      anon_sym_eval,
    ACTIONS(17), 1,
      anon_sym_print,
    ACTIONS(19), 1,
      anon_sym_not,
    ACTIONS(21), 1,
      anon_sym_DASH,
    ACTIONS(23), 1,
      anon_sym_TILDE,
    ACTIONS(25), 1,
      anon_sym_LPAREN,
    ACTIONS(29), 1,
      anon_sym_function,
    ACTIONS(31), 1,
      anon_sym_procedure,
    ACTIONS(33), 1,
      anon_sym_intrinsic,
    ACTIONS(35), 1,
      anon_sym__,
    ACTIONS(37), 1,
      anon_sym_if,
    ACTIONS(41), 1,
      anon_sym_while,
    ACTIONS(43), 1,
      anon_sym_repeat,
    ACTIONS(45), 1,
      anon_sym_case,
    ACTIONS(47), 1,
      sym_identifier,
    ACTIONS(120), 1,
      anon_sym_endwhile,
    ACTIONS(139), 1,
      sym_for_statement,
    STATE(9), 1,
      sym_comment,
    STATE(12), 1,
      aux_sym_block_repeat1,
    STATE(53), 1,
      sym_primary_expression,
    STATE(83), 1,
      sym__statement,
    STATE(99), 1,
      sym_expression,
    STATE(157), 1,
      sym_gen_expression,
    ACTIONS(49), 2,
      sym_string,
      sym_real,
    STATE(38), 2,
      sym_comparison_operator,
      sym_boolean_operator,
    STATE(196), 2,
      sym_assignment,
      sym_augmented_assignment,
    ACTIONS(27), 3,
      sym_true,
      sym_false,
      sym_integer,
    STATE(189), 3,
      sym_function_definition,
      sym_procedure_definition,
      sym_intrinsic_definition,
    STATE(36), 5,
      sym_unary_operator,
      sym_binary_operator,
      sym_ternary_operator,
      sym_parenthesized_expression,
      sym_call,
    STATE(224), 12,
      sym_expression_statement,
      sym_return_statement,
      sym_break_statement,
      sym_continue_statement,
      sym_eval_statement,
      sym_print_statement,
      sym__definition,
      sym__assignment,
      sym_if_statement,
      sym_while_statement,
      sym_repeat_statement,
      sym_case_statement,
  [1043] = 34,
    ACTIONS(3), 1,
      anon_sym_SLASH_SLASH,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(51), 1,
      anon_sym_return,
    ACTIONS(54), 1,
      anon_sym_break,
    ACTIONS(57), 1,
      anon_sym_continue,
    ACTIONS(60), 1,
      anon_sym_eval,
    ACTIONS(63), 1,
      anon_sym_print,
    ACTIONS(66), 1,
      anon_sym_not,
    ACTIONS(69), 1,
      anon_sym_DASH,
    ACTIONS(72), 1,
      anon_sym_TILDE,
    ACTIONS(77), 1,
      anon_sym_LPAREN,
    ACTIONS(83), 1,
      anon_sym_function,
    ACTIONS(86), 1,
      anon_sym_procedure,
    ACTIONS(89), 1,
      anon_sym_intrinsic,
    ACTIONS(92), 1,
      anon_sym__,
    ACTIONS(95), 1,
      anon_sym_if,
    ACTIONS(98), 1,
      anon_sym_endif,
    ACTIONS(103), 1,
      anon_sym_while,
    ACTIONS(106), 1,
      anon_sym_repeat,
    ACTIONS(109), 1,
      anon_sym_case,
    ACTIONS(112), 1,
      sym_identifier,
    ACTIONS(141), 1,
      sym_for_statement,
    STATE(53), 1,
      sym_primary_expression,
    STATE(76), 1,
      sym__statement,
    STATE(99), 1,
      sym_expression,
    STATE(157), 1,
      sym_gen_expression,
    ACTIONS(115), 2,
      sym_string,
      sym_real,
    STATE(10), 2,
      sym_comment,
      aux_sym_block_repeat1,
    STATE(38), 2,
      sym_comparison_operator,
      sym_boolean_operator,
    STATE(196), 2,
      sym_assignment,
      sym_augmented_assignment,
    ACTIONS(80), 3,
      sym_true,
      sym_false,
      sym_integer,
    STATE(189), 3,
      sym_function_definition,
      sym_procedure_definition,
      sym_intrinsic_definition,
    STATE(36), 5,
      sym_unary_operator,
      sym_binary_operator,
      sym_ternary_operator,
      sym_parenthesized_expression,
      sym_call,
    STATE(225), 12,
      sym_expression_statement,
      sym_return_statement,
      sym_break_statement,
      sym_continue_statement,
      sym_eval_statement,
      sym_print_statement,
      sym__definition,
      sym__assignment,
      sym_if_statement,
      sym_while_statement,
      sym_repeat_statement,
      sym_case_statement,
  [1169] = 35,
    ACTIONS(3), 1,
      anon_sym_SLASH_SLASH,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(9), 1,
      anon_sym_return,
    ACTIONS(11), 1,
      anon_sym_break,
    ACTIONS(13), 1,
      anon_sym_continue,
    ACTIONS(15), 1,
      anon_sym_eval,
    ACTIONS(17), 1,
      anon_sym_print,
    ACTIONS(19), 1,
      anon_sym_not,
    ACTIONS(21), 1,
      anon_sym_DASH,
    ACTIONS(23), 1,
      anon_sym_TILDE,
    ACTIONS(25), 1,
      anon_sym_LPAREN,
    ACTIONS(29), 1,
      anon_sym_function,
    ACTIONS(31), 1,
      anon_sym_procedure,
    ACTIONS(33), 1,
      anon_sym_intrinsic,
    ACTIONS(35), 1,
      anon_sym__,
    ACTIONS(37), 1,
      anon_sym_if,
    ACTIONS(41), 1,
      anon_sym_while,
    ACTIONS(43), 1,
      anon_sym_repeat,
    ACTIONS(45), 1,
      anon_sym_case,
    ACTIONS(47), 1,
      sym_identifier,
    ACTIONS(120), 1,
      anon_sym_endif,
    ACTIONS(144), 1,
      sym_for_statement,
    STATE(10), 1,
      aux_sym_block_repeat1,
    STATE(11), 1,
      sym_comment,
    STATE(53), 1,
      sym_primary_expression,
    STATE(76), 1,
      sym__statement,
    STATE(99), 1,
      sym_expression,
    STATE(157), 1,
      sym_gen_expression,
    ACTIONS(49), 2,
      sym_string,
      sym_real,
    STATE(38), 2,
      sym_comparison_operator,
      sym_boolean_operator,
    STATE(196), 2,
      sym_assignment,
      sym_augmented_assignment,
    ACTIONS(27), 3,
      sym_true,
      sym_false,
      sym_integer,
    STATE(189), 3,
      sym_function_definition,
      sym_procedure_definition,
      sym_intrinsic_definition,
    STATE(36), 5,
      sym_unary_operator,
      sym_binary_operator,
      sym_ternary_operator,
      sym_parenthesized_expression,
      sym_call,
    STATE(225), 12,
      sym_expression_statement,
      sym_return_statement,
      sym_break_statement,
      sym_continue_statement,
      sym_eval_statement,
      sym_print_statement,
      sym__definition,
      sym__assignment,
      sym_if_statement,
      sym_while_statement,
      sym_repeat_statement,
      sym_case_statement,
  [1297] = 34,
    ACTIONS(3), 1,
      anon_sym_SLASH_SLASH,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(51), 1,
      anon_sym_return,
    ACTIONS(54), 1,
      anon_sym_break,
    ACTIONS(57), 1,
      anon_sym_continue,
    ACTIONS(60), 1,
      anon_sym_eval,
    ACTIONS(63), 1,
      anon_sym_print,
    ACTIONS(66), 1,
      anon_sym_not,
    ACTIONS(69), 1,
      anon_sym_DASH,
    ACTIONS(72), 1,
      anon_sym_TILDE,
    ACTIONS(77), 1,
      anon_sym_LPAREN,
    ACTIONS(83), 1,
      anon_sym_function,
    ACTIONS(86), 1,
      anon_sym_procedure,
    ACTIONS(89), 1,
      anon_sym_intrinsic,
    ACTIONS(92), 1,
      anon_sym__,
    ACTIONS(95), 1,
      anon_sym_if,
    ACTIONS(98), 1,
      anon_sym_endwhile,
    ACTIONS(103), 1,
      anon_sym_while,
    ACTIONS(106), 1,
      anon_sym_repeat,
    ACTIONS(109), 1,
      anon_sym_case,
    ACTIONS(112), 1,
      sym_identifier,
    ACTIONS(146), 1,
      sym_for_statement,
    STATE(53), 1,
      sym_primary_expression,
    STATE(83), 1,
      sym__statement,
    STATE(99), 1,
      sym_expression,
    STATE(157), 1,
      sym_gen_expression,
    ACTIONS(115), 2,
      sym_string,
      sym_real,
    STATE(12), 2,
      sym_comment,
      aux_sym_block_repeat1,
    STATE(38), 2,
      sym_comparison_operator,
      sym_boolean_operator,
    STATE(196), 2,
      sym_assignment,
      sym_augmented_assignment,
    ACTIONS(80), 3,
      sym_true,
      sym_false,
      sym_integer,
    STATE(189), 3,
      sym_function_definition,
      sym_procedure_definition,
      sym_intrinsic_definition,
    STATE(36), 5,
      sym_unary_operator,
      sym_binary_operator,
      sym_ternary_operator,
      sym_parenthesized_expression,
      sym_call,
    STATE(224), 12,
      sym_expression_statement,
      sym_return_statement,
      sym_break_statement,
      sym_continue_statement,
      sym_eval_statement,
      sym_print_statement,
      sym__definition,
      sym__assignment,
      sym_if_statement,
      sym_while_statement,
      sym_repeat_statement,
      sym_case_statement,
  [1423] = 34,
    ACTIONS(3), 1,
      anon_sym_SLASH_SLASH,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(51), 1,
      anon_sym_return,
    ACTIONS(54), 1,
      anon_sym_break,
    ACTIONS(57), 1,
      anon_sym_continue,
    ACTIONS(60), 1,
      anon_sym_eval,
    ACTIONS(63), 1,
      anon_sym_print,
    ACTIONS(66), 1,
      anon_sym_not,
    ACTIONS(69), 1,
      anon_sym_DASH,
    ACTIONS(72), 1,
      anon_sym_TILDE,
    ACTIONS(75), 1,
      anon_sym_until,
    ACTIONS(77), 1,
      anon_sym_LPAREN,
    ACTIONS(83), 1,
      anon_sym_function,
    ACTIONS(86), 1,
      anon_sym_procedure,
    ACTIONS(89), 1,
      anon_sym_intrinsic,
    ACTIONS(92), 1,
      anon_sym__,
    ACTIONS(95), 1,
      anon_sym_if,
    ACTIONS(103), 1,
      anon_sym_while,
    ACTIONS(106), 1,
      anon_sym_repeat,
    ACTIONS(109), 1,
      anon_sym_case,
    ACTIONS(112), 1,
      sym_identifier,
    ACTIONS(149), 1,
      sym_for_statement,
    STATE(53), 1,
      sym_primary_expression,
    STATE(80), 1,
      sym__statement,
    STATE(99), 1,
      sym_expression,
    STATE(157), 1,
      sym_gen_expression,
    ACTIONS(115), 2,
      sym_string,
      sym_real,
    STATE(13), 2,
      sym_comment,
      aux_sym_block_repeat1,
    STATE(38), 2,
      sym_comparison_operator,
      sym_boolean_operator,
    STATE(196), 2,
      sym_assignment,
      sym_augmented_assignment,
    ACTIONS(80), 3,
      sym_true,
      sym_false,
      sym_integer,
    STATE(189), 3,
      sym_function_definition,
      sym_procedure_definition,
      sym_intrinsic_definition,
    STATE(36), 5,
      sym_unary_operator,
      sym_binary_operator,
      sym_ternary_operator,
      sym_parenthesized_expression,
      sym_call,
    STATE(214), 12,
      sym_expression_statement,
      sym_return_statement,
      sym_break_statement,
      sym_continue_statement,
      sym_eval_statement,
      sym_print_statement,
      sym__definition,
      sym__assignment,
      sym_if_statement,
      sym_while_statement,
      sym_repeat_statement,
      sym_case_statement,
  [1549] = 35,
    ACTIONS(3), 1,
      anon_sym_SLASH_SLASH,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(9), 1,
      anon_sym_return,
    ACTIONS(11), 1,
      anon_sym_break,
    ACTIONS(13), 1,
      anon_sym_continue,
    ACTIONS(15), 1,
      anon_sym_eval,
    ACTIONS(17), 1,
      anon_sym_print,
    ACTIONS(19), 1,
      anon_sym_not,
    ACTIONS(21), 1,
      anon_sym_DASH,
    ACTIONS(23), 1,
      anon_sym_TILDE,
    ACTIONS(25), 1,
      anon_sym_LPAREN,
    ACTIONS(29), 1,
      anon_sym_function,
    ACTIONS(31), 1,
      anon_sym_procedure,
    ACTIONS(33), 1,
      anon_sym_intrinsic,
    ACTIONS(35), 1,
      anon_sym__,
    ACTIONS(37), 1,
      anon_sym_if,
    ACTIONS(41), 1,
      anon_sym_while,
    ACTIONS(43), 1,
      anon_sym_repeat,
    ACTIONS(45), 1,
      anon_sym_case,
    ACTIONS(47), 1,
      sym_identifier,
    ACTIONS(137), 1,
      sym_for_statement,
    STATE(8), 1,
      aux_sym_block_repeat1,
    STATE(14), 1,
      sym_comment,
    STATE(53), 1,
      sym_primary_expression,
    STATE(70), 1,
      sym__statement,
    STATE(99), 1,
      sym_expression,
    STATE(157), 1,
      sym_gen_expression,
    STATE(170), 1,
      sym_block,
    ACTIONS(49), 2,
      sym_string,
      sym_real,
    STATE(38), 2,
      sym_comparison_operator,
      sym_boolean_operator,
    STATE(196), 2,
      sym_assignment,
      sym_augmented_assignment,
    ACTIONS(27), 3,
      sym_true,
      sym_false,
      sym_integer,
    STATE(189), 3,
      sym_function_definition,
      sym_procedure_definition,
      sym_intrinsic_definition,
    STATE(36), 5,
      sym_unary_operator,
      sym_binary_operator,
      sym_ternary_operator,
      sym_parenthesized_expression,
      sym_call,
    STATE(213), 12,
      sym_expression_statement,
      sym_return_statement,
      sym_break_statement,
      sym_continue_statement,
      sym_eval_statement,
      sym_print_statement,
      sym__definition,
      sym__assignment,
      sym_if_statement,
      sym_while_statement,
      sym_repeat_statement,
      sym_case_statement,
  [1677] = 35,
    ACTIONS(3), 1,
      anon_sym_SLASH_SLASH,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(9), 1,
      anon_sym_return,
    ACTIONS(11), 1,
      anon_sym_break,
    ACTIONS(13), 1,
      anon_sym_continue,
    ACTIONS(15), 1,
      anon_sym_eval,
    ACTIONS(17), 1,
      anon_sym_print,
    ACTIONS(19), 1,
      anon_sym_not,
    ACTIONS(21), 1,
      anon_sym_DASH,
    ACTIONS(23), 1,
      anon_sym_TILDE,
    ACTIONS(25), 1,
      anon_sym_LPAREN,
    ACTIONS(29), 1,
      anon_sym_function,
    ACTIONS(31), 1,
      anon_sym_procedure,
    ACTIONS(33), 1,
      anon_sym_intrinsic,
    ACTIONS(35), 1,
      anon_sym__,
    ACTIONS(37), 1,
      anon_sym_if,
    ACTIONS(41), 1,
      anon_sym_while,
    ACTIONS(43), 1,
      anon_sym_repeat,
    ACTIONS(45), 1,
      anon_sym_case,
    ACTIONS(47), 1,
      sym_identifier,
    ACTIONS(139), 1,
      sym_for_statement,
    STATE(9), 1,
      aux_sym_block_repeat1,
    STATE(15), 1,
      sym_comment,
    STATE(53), 1,
      sym_primary_expression,
    STATE(83), 1,
      sym__statement,
    STATE(99), 1,
      sym_expression,
    STATE(157), 1,
      sym_gen_expression,
    STATE(186), 1,
      sym_block,
    ACTIONS(49), 2,
      sym_string,
      sym_real,
    STATE(38), 2,
      sym_comparison_operator,
      sym_boolean_operator,
    STATE(196), 2,
      sym_assignment,
      sym_augmented_assignment,
    ACTIONS(27), 3,
      sym_true,
      sym_false,
      sym_integer,
    STATE(189), 3,
      sym_function_definition,
      sym_procedure_definition,
      sym_intrinsic_definition,
    STATE(36), 5,
      sym_unary_operator,
      sym_binary_operator,
      sym_ternary_operator,
      sym_parenthesized_expression,
      sym_call,
    STATE(224), 12,
      sym_expression_statement,
      sym_return_statement,
      sym_break_statement,
      sym_continue_statement,
      sym_eval_statement,
      sym_print_statement,
      sym__definition,
      sym__assignment,
      sym_if_statement,
      sym_while_statement,
      sym_repeat_statement,
      sym_case_statement,
  [1805] = 35,
    ACTIONS(3), 1,
      anon_sym_SLASH_SLASH,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(9), 1,
      anon_sym_return,
    ACTIONS(11), 1,
      anon_sym_break,
    ACTIONS(13), 1,
      anon_sym_continue,
    ACTIONS(15), 1,
      anon_sym_eval,
    ACTIONS(17), 1,
      anon_sym_print,
    ACTIONS(19), 1,
      anon_sym_not,
    ACTIONS(21), 1,
      anon_sym_DASH,
    ACTIONS(23), 1,
      anon_sym_TILDE,
    ACTIONS(25), 1,
      anon_sym_LPAREN,
    ACTIONS(29), 1,
      anon_sym_function,
    ACTIONS(31), 1,
      anon_sym_procedure,
    ACTIONS(33), 1,
      anon_sym_intrinsic,
    ACTIONS(35), 1,
      anon_sym__,
    ACTIONS(37), 1,
      anon_sym_if,
    ACTIONS(41), 1,
      anon_sym_while,
    ACTIONS(43), 1,
      anon_sym_repeat,
    ACTIONS(45), 1,
      anon_sym_case,
    ACTIONS(47), 1,
      sym_identifier,
    ACTIONS(152), 1,
      sym_for_statement,
    STATE(16), 1,
      sym_comment,
    STATE(24), 1,
      aux_sym_block_repeat1,
    STATE(53), 1,
      sym_primary_expression,
    STATE(85), 1,
      sym__statement,
    STATE(99), 1,
      sym_expression,
    STATE(157), 1,
      sym_gen_expression,
    STATE(195), 1,
      sym_block,
    ACTIONS(49), 2,
      sym_string,
      sym_real,
    STATE(38), 2,
      sym_comparison_operator,
      sym_boolean_operator,
    STATE(196), 2,
      sym_assignment,
      sym_augmented_assignment,
    ACTIONS(27), 3,
      sym_true,
      sym_false,
      sym_integer,
    STATE(189), 3,
      sym_function_definition,
      sym_procedure_definition,
      sym_intrinsic_definition,
    STATE(36), 5,
      sym_unary_operator,
      sym_binary_operator,
      sym_ternary_operator,
      sym_parenthesized_expression,
      sym_call,
    STATE(218), 12,
      sym_expression_statement,
      sym_return_statement,
      sym_break_statement,
      sym_continue_statement,
      sym_eval_statement,
      sym_print_statement,
      sym__definition,
      sym__assignment,
      sym_if_statement,
      sym_while_statement,
      sym_repeat_statement,
      sym_case_statement,
  [1933] = 34,
    ACTIONS(3), 1,
      anon_sym_SLASH_SLASH,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(154), 1,
      ts_builtin_sym_end,
    ACTIONS(156), 1,
      anon_sym_return,
    ACTIONS(159), 1,
      anon_sym_break,
    ACTIONS(162), 1,
      anon_sym_continue,
    ACTIONS(165), 1,
      anon_sym_eval,
    ACTIONS(168), 1,
      anon_sym_print,
    ACTIONS(171), 1,
      anon_sym_not,
    ACTIONS(174), 1,
      anon_sym_DASH,
    ACTIONS(177), 1,
      anon_sym_TILDE,
    ACTIONS(180), 1,
      anon_sym_LPAREN,
    ACTIONS(186), 1,
      anon_sym_function,
    ACTIONS(189), 1,
      anon_sym_procedure,
    ACTIONS(192), 1,
      anon_sym_intrinsic,
    ACTIONS(195), 1,
      anon_sym__,
    ACTIONS(198), 1,
      anon_sym_if,
    ACTIONS(201), 1,
      sym_for_statement,
    ACTIONS(204), 1,
      anon_sym_while,
    ACTIONS(207), 1,
      anon_sym_repeat,
    ACTIONS(210), 1,
      anon_sym_case,
    ACTIONS(213), 1,
      sym_identifier,
    STATE(53), 1,
      sym_primary_expression,
    STATE(86), 1,
      sym__statement,
    STATE(99), 1,
      sym_expression,
    STATE(157), 1,
      sym_gen_expression,
    ACTIONS(216), 2,
      sym_string,
      sym_real,
    STATE(17), 2,
      sym_comment,
      aux_sym_program_repeat1,
    STATE(38), 2,
      sym_comparison_operator,
      sym_boolean_operator,
    STATE(196), 2,
      sym_assignment,
      sym_augmented_assignment,
    ACTIONS(183), 3,
      sym_true,
      sym_false,
      sym_integer,
    STATE(189), 3,
      sym_function_definition,
      sym_procedure_definition,
      sym_intrinsic_definition,
    STATE(36), 5,
      sym_unary_operator,
      sym_binary_operator,
      sym_ternary_operator,
      sym_parenthesized_expression,
      sym_call,
    STATE(194), 12,
      sym_expression_statement,
      sym_return_statement,
      sym_break_statement,
      sym_continue_statement,
      sym_eval_statement,
      sym_print_statement,
      sym__definition,
      sym__assignment,
      sym_if_statement,
      sym_while_statement,
      sym_repeat_statement,
      sym_case_statement,
  [2059] = 35,
    ACTIONS(3), 1,
      anon_sym_SLASH_SLASH,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(9), 1,
      anon_sym_return,
    ACTIONS(11), 1,
      anon_sym_break,
    ACTIONS(13), 1,
      anon_sym_continue,
    ACTIONS(15), 1,
      anon_sym_eval,
    ACTIONS(17), 1,
      anon_sym_print,
    ACTIONS(19), 1,
      anon_sym_not,
    ACTIONS(21), 1,
      anon_sym_DASH,
    ACTIONS(23), 1,
      anon_sym_TILDE,
    ACTIONS(25), 1,
      anon_sym_LPAREN,
    ACTIONS(29), 1,
      anon_sym_function,
    ACTIONS(31), 1,
      anon_sym_procedure,
    ACTIONS(33), 1,
      anon_sym_intrinsic,
    ACTIONS(35), 1,
      anon_sym__,
    ACTIONS(37), 1,
      anon_sym_if,
    ACTIONS(41), 1,
      anon_sym_while,
    ACTIONS(43), 1,
      anon_sym_repeat,
    ACTIONS(45), 1,
      anon_sym_case,
    ACTIONS(47), 1,
      sym_identifier,
    ACTIONS(118), 1,
      anon_sym_until,
    ACTIONS(219), 1,
      sym_for_statement,
    STATE(13), 1,
      aux_sym_block_repeat1,
    STATE(18), 1,
      sym_comment,
    STATE(53), 1,
      sym_primary_expression,
    STATE(80), 1,
      sym__statement,
    STATE(99), 1,
      sym_expression,
    STATE(157), 1,
      sym_gen_expression,
    ACTIONS(49), 2,
      sym_string,
      sym_real,
    STATE(38), 2,
      sym_comparison_operator,
      sym_boolean_operator,
    STATE(196), 2,
      sym_assignment,
      sym_augmented_assignment,
    ACTIONS(27), 3,
      sym_true,
      sym_false,
      sym_integer,
    STATE(189), 3,
      sym_function_definition,
      sym_procedure_definition,
      sym_intrinsic_definition,
    STATE(36), 5,
      sym_unary_operator,
      sym_binary_operator,
      sym_ternary_operator,
      sym_parenthesized_expression,
      sym_call,
    STATE(214), 12,
      sym_expression_statement,
      sym_return_statement,
      sym_break_statement,
      sym_continue_statement,
      sym_eval_statement,
      sym_print_statement,
      sym__definition,
      sym__assignment,
      sym_if_statement,
      sym_while_statement,
      sym_repeat_statement,
      sym_case_statement,
  [2187] = 34,
    ACTIONS(3), 1,
      anon_sym_SLASH_SLASH,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(51), 1,
      anon_sym_return,
    ACTIONS(54), 1,
      anon_sym_break,
    ACTIONS(57), 1,
      anon_sym_continue,
    ACTIONS(60), 1,
      anon_sym_eval,
    ACTIONS(63), 1,
      anon_sym_print,
    ACTIONS(66), 1,
      anon_sym_not,
    ACTIONS(69), 1,
      anon_sym_DASH,
    ACTIONS(72), 1,
      anon_sym_TILDE,
    ACTIONS(77), 1,
      anon_sym_LPAREN,
    ACTIONS(83), 1,
      anon_sym_function,
    ACTIONS(86), 1,
      anon_sym_procedure,
    ACTIONS(89), 1,
      anon_sym_intrinsic,
    ACTIONS(92), 1,
      anon_sym__,
    ACTIONS(95), 1,
      anon_sym_if,
    ACTIONS(98), 1,
      anon_sym_endprocedure,
    ACTIONS(103), 1,
      anon_sym_while,
    ACTIONS(106), 1,
      anon_sym_repeat,
    ACTIONS(109), 1,
      anon_sym_case,
    ACTIONS(112), 1,
      sym_identifier,
    ACTIONS(221), 1,
      sym_for_statement,
    STATE(53), 1,
      sym_primary_expression,
    STATE(92), 1,
      sym__statement,
    STATE(99), 1,
      sym_expression,
    STATE(157), 1,
      sym_gen_expression,
    ACTIONS(115), 2,
      sym_string,
      sym_real,
    STATE(19), 2,
      sym_comment,
      aux_sym_block_repeat1,
    STATE(38), 2,
      sym_comparison_operator,
      sym_boolean_operator,
    STATE(196), 2,
      sym_assignment,
      sym_augmented_assignment,
    ACTIONS(80), 3,
      sym_true,
      sym_false,
      sym_integer,
    STATE(189), 3,
      sym_function_definition,
      sym_procedure_definition,
      sym_intrinsic_definition,
    STATE(36), 5,
      sym_unary_operator,
      sym_binary_operator,
      sym_ternary_operator,
      sym_parenthesized_expression,
      sym_call,
    STATE(222), 12,
      sym_expression_statement,
      sym_return_statement,
      sym_break_statement,
      sym_continue_statement,
      sym_eval_statement,
      sym_print_statement,
      sym__definition,
      sym__assignment,
      sym_if_statement,
      sym_while_statement,
      sym_repeat_statement,
      sym_case_statement,
  [2313] = 35,
    ACTIONS(3), 1,
      anon_sym_SLASH_SLASH,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(9), 1,
      anon_sym_return,
    ACTIONS(11), 1,
      anon_sym_break,
    ACTIONS(13), 1,
      anon_sym_continue,
    ACTIONS(15), 1,
      anon_sym_eval,
    ACTIONS(17), 1,
      anon_sym_print,
    ACTIONS(19), 1,
      anon_sym_not,
    ACTIONS(21), 1,
      anon_sym_DASH,
    ACTIONS(23), 1,
      anon_sym_TILDE,
    ACTIONS(25), 1,
      anon_sym_LPAREN,
    ACTIONS(29), 1,
      anon_sym_function,
    ACTIONS(31), 1,
      anon_sym_procedure,
    ACTIONS(33), 1,
      anon_sym_intrinsic,
    ACTIONS(35), 1,
      anon_sym__,
    ACTIONS(37), 1,
      anon_sym_if,
    ACTIONS(41), 1,
      anon_sym_while,
    ACTIONS(43), 1,
      anon_sym_repeat,
    ACTIONS(45), 1,
      anon_sym_case,
    ACTIONS(47), 1,
      sym_identifier,
    ACTIONS(120), 1,
      anon_sym_endprocedure,
    ACTIONS(126), 1,
      sym_for_statement,
    STATE(19), 1,
      aux_sym_block_repeat1,
    STATE(20), 1,
      sym_comment,
    STATE(53), 1,
      sym_primary_expression,
    STATE(92), 1,
      sym__statement,
    STATE(99), 1,
      sym_expression,
    STATE(157), 1,
      sym_gen_expression,
    ACTIONS(49), 2,
      sym_string,
      sym_real,
    STATE(38), 2,
      sym_comparison_operator,
      sym_boolean_operator,
    STATE(196), 2,
      sym_assignment,
      sym_augmented_assignment,
    ACTIONS(27), 3,
      sym_true,
      sym_false,
      sym_integer,
    STATE(189), 3,
      sym_function_definition,
      sym_procedure_definition,
      sym_intrinsic_definition,
    STATE(36), 5,
      sym_unary_operator,
      sym_binary_operator,
      sym_ternary_operator,
      sym_parenthesized_expression,
      sym_call,
    STATE(222), 12,
      sym_expression_statement,
      sym_return_statement,
      sym_break_statement,
      sym_continue_statement,
      sym_eval_statement,
      sym_print_statement,
      sym__definition,
      sym__assignment,
      sym_if_statement,
      sym_while_statement,
      sym_repeat_statement,
      sym_case_statement,
  [2441] = 35,
    ACTIONS(3), 1,
      anon_sym_SLASH_SLASH,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(9), 1,
      anon_sym_return,
    ACTIONS(11), 1,
      anon_sym_break,
    ACTIONS(13), 1,
      anon_sym_continue,
    ACTIONS(15), 1,
      anon_sym_eval,
    ACTIONS(17), 1,
      anon_sym_print,
    ACTIONS(19), 1,
      anon_sym_not,
    ACTIONS(21), 1,
      anon_sym_DASH,
    ACTIONS(23), 1,
      anon_sym_TILDE,
    ACTIONS(25), 1,
      anon_sym_LPAREN,
    ACTIONS(29), 1,
      anon_sym_function,
    ACTIONS(31), 1,
      anon_sym_procedure,
    ACTIONS(33), 1,
      anon_sym_intrinsic,
    ACTIONS(35), 1,
      anon_sym__,
    ACTIONS(37), 1,
      anon_sym_if,
    ACTIONS(41), 1,
      anon_sym_while,
    ACTIONS(43), 1,
      anon_sym_repeat,
    ACTIONS(45), 1,
      anon_sym_case,
    ACTIONS(47), 1,
      sym_identifier,
    ACTIONS(219), 1,
      sym_for_statement,
    STATE(18), 1,
      aux_sym_block_repeat1,
    STATE(21), 1,
      sym_comment,
    STATE(53), 1,
      sym_primary_expression,
    STATE(80), 1,
      sym__statement,
    STATE(99), 1,
      sym_expression,
    STATE(157), 1,
      sym_gen_expression,
    STATE(216), 1,
      sym_block,
    ACTIONS(49), 2,
      sym_string,
      sym_real,
    STATE(38), 2,
      sym_comparison_operator,
      sym_boolean_operator,
    STATE(196), 2,
      sym_assignment,
      sym_augmented_assignment,
    ACTIONS(27), 3,
      sym_true,
      sym_false,
      sym_integer,
    STATE(189), 3,
      sym_function_definition,
      sym_procedure_definition,
      sym_intrinsic_definition,
    STATE(36), 5,
      sym_unary_operator,
      sym_binary_operator,
      sym_ternary_operator,
      sym_parenthesized_expression,
      sym_call,
    STATE(214), 12,
      sym_expression_statement,
      sym_return_statement,
      sym_break_statement,
      sym_continue_statement,
      sym_eval_statement,
      sym_print_statement,
      sym__definition,
      sym__assignment,
      sym_if_statement,
      sym_while_statement,
      sym_repeat_statement,
      sym_case_statement,
  [2569] = 34,
    ACTIONS(3), 1,
      anon_sym_SLASH_SLASH,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(51), 1,
      anon_sym_return,
    ACTIONS(54), 1,
      anon_sym_break,
    ACTIONS(57), 1,
      anon_sym_continue,
    ACTIONS(60), 1,
      anon_sym_eval,
    ACTIONS(63), 1,
      anon_sym_print,
    ACTIONS(66), 1,
      anon_sym_not,
    ACTIONS(69), 1,
      anon_sym_DASH,
    ACTIONS(72), 1,
      anon_sym_TILDE,
    ACTIONS(77), 1,
      anon_sym_LPAREN,
    ACTIONS(83), 1,
      anon_sym_function,
    ACTIONS(86), 1,
      anon_sym_procedure,
    ACTIONS(89), 1,
      anon_sym_intrinsic,
    ACTIONS(92), 1,
      anon_sym__,
    ACTIONS(95), 1,
      anon_sym_if,
    ACTIONS(98), 1,
      anon_sym_endfunction,
    ACTIONS(103), 1,
      anon_sym_while,
    ACTIONS(106), 1,
      anon_sym_repeat,
    ACTIONS(109), 1,
      anon_sym_case,
    ACTIONS(112), 1,
      sym_identifier,
    ACTIONS(224), 1,
      sym_for_statement,
    STATE(53), 1,
      sym_primary_expression,
    STATE(85), 1,
      sym__statement,
    STATE(99), 1,
      sym_expression,
    STATE(157), 1,
      sym_gen_expression,
    ACTIONS(115), 2,
      sym_string,
      sym_real,
    STATE(22), 2,
      sym_comment,
      aux_sym_block_repeat1,
    STATE(38), 2,
      sym_comparison_operator,
      sym_boolean_operator,
    STATE(196), 2,
      sym_assignment,
      sym_augmented_assignment,
    ACTIONS(80), 3,
      sym_true,
      sym_false,
      sym_integer,
    STATE(189), 3,
      sym_function_definition,
      sym_procedure_definition,
      sym_intrinsic_definition,
    STATE(36), 5,
      sym_unary_operator,
      sym_binary_operator,
      sym_ternary_operator,
      sym_parenthesized_expression,
      sym_call,
    STATE(218), 12,
      sym_expression_statement,
      sym_return_statement,
      sym_break_statement,
      sym_continue_statement,
      sym_eval_statement,
      sym_print_statement,
      sym__definition,
      sym__assignment,
      sym_if_statement,
      sym_while_statement,
      sym_repeat_statement,
      sym_case_statement,
  [2695] = 35,
    ACTIONS(3), 1,
      anon_sym_SLASH_SLASH,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(9), 1,
      anon_sym_return,
    ACTIONS(11), 1,
      anon_sym_break,
    ACTIONS(13), 1,
      anon_sym_continue,
    ACTIONS(15), 1,
      anon_sym_eval,
    ACTIONS(17), 1,
      anon_sym_print,
    ACTIONS(19), 1,
      anon_sym_not,
    ACTIONS(21), 1,
      anon_sym_DASH,
    ACTIONS(23), 1,
      anon_sym_TILDE,
    ACTIONS(25), 1,
      anon_sym_LPAREN,
    ACTIONS(29), 1,
      anon_sym_function,
    ACTIONS(31), 1,
      anon_sym_procedure,
    ACTIONS(33), 1,
      anon_sym_intrinsic,
    ACTIONS(35), 1,
      anon_sym__,
    ACTIONS(37), 1,
      anon_sym_if,
    ACTIONS(41), 1,
      anon_sym_while,
    ACTIONS(43), 1,
      anon_sym_repeat,
    ACTIONS(45), 1,
      anon_sym_case,
    ACTIONS(47), 1,
      sym_identifier,
    ACTIONS(122), 1,
      sym_for_statement,
    STATE(3), 1,
      aux_sym_block_repeat1,
    STATE(23), 1,
      sym_comment,
    STATE(53), 1,
      sym_primary_expression,
    STATE(64), 1,
      sym__statement,
    STATE(99), 1,
      sym_expression,
    STATE(136), 1,
      sym_block,
    STATE(157), 1,
      sym_gen_expression,
    ACTIONS(49), 2,
      sym_string,
      sym_real,
    STATE(38), 2,
      sym_comparison_operator,
      sym_boolean_operator,
    STATE(196), 2,
      sym_assignment,
      sym_augmented_assignment,
    ACTIONS(27), 3,
      sym_true,
      sym_false,
      sym_integer,
    STATE(189), 3,
      sym_function_definition,
      sym_procedure_definition,
      sym_intrinsic_definition,
    STATE(36), 5,
      sym_unary_operator,
      sym_binary_operator,
      sym_ternary_operator,
      sym_parenthesized_expression,
      sym_call,
    STATE(223), 12,
      sym_expression_statement,
      sym_return_statement,
      sym_break_statement,
      sym_continue_statement,
      sym_eval_statement,
      sym_print_statement,
      sym__definition,
      sym__assignment,
      sym_if_statement,
      sym_while_statement,
      sym_repeat_statement,
      sym_case_statement,
  [2823] = 35,
    ACTIONS(3), 1,
      anon_sym_SLASH_SLASH,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(9), 1,
      anon_sym_return,
    ACTIONS(11), 1,
      anon_sym_break,
    ACTIONS(13), 1,
      anon_sym_continue,
    ACTIONS(15), 1,
      anon_sym_eval,
    ACTIONS(17), 1,
      anon_sym_print,
    ACTIONS(19), 1,
      anon_sym_not,
    ACTIONS(21), 1,
      anon_sym_DASH,
    ACTIONS(23), 1,
      anon_sym_TILDE,
    ACTIONS(25), 1,
      anon_sym_LPAREN,
    ACTIONS(29), 1,
      anon_sym_function,
    ACTIONS(31), 1,
      anon_sym_procedure,
    ACTIONS(33), 1,
      anon_sym_intrinsic,
    ACTIONS(35), 1,
      anon_sym__,
    ACTIONS(37), 1,
      anon_sym_if,
    ACTIONS(41), 1,
      anon_sym_while,
    ACTIONS(43), 1,
      anon_sym_repeat,
    ACTIONS(45), 1,
      anon_sym_case,
    ACTIONS(47), 1,
      sym_identifier,
    ACTIONS(120), 1,
      anon_sym_endfunction,
    ACTIONS(152), 1,
      sym_for_statement,
    STATE(22), 1,
      aux_sym_block_repeat1,
    STATE(24), 1,
      sym_comment,
    STATE(53), 1,
      sym_primary_expression,
    STATE(85), 1,
      sym__statement,
    STATE(99), 1,
      sym_expression,
    STATE(157), 1,
      sym_gen_expression,
    ACTIONS(49), 2,
      sym_string,
      sym_real,
    STATE(38), 2,
      sym_comparison_operator,
      sym_boolean_operator,
    STATE(196), 2,
      sym_assignment,
      sym_augmented_assignment,
    ACTIONS(27), 3,
      sym_true,
      sym_false,
      sym_integer,
    STATE(189), 3,
      sym_function_definition,
      sym_procedure_definition,
      sym_intrinsic_definition,
    STATE(36), 5,
      sym_unary_operator,
      sym_binary_operator,
      sym_ternary_operator,
      sym_parenthesized_expression,
      sym_call,
    STATE(218), 12,
      sym_expression_statement,
      sym_return_statement,
      sym_break_statement,
      sym_continue_statement,
      sym_eval_statement,
      sym_print_statement,
      sym__definition,
      sym__assignment,
      sym_if_statement,
      sym_while_statement,
      sym_repeat_statement,
      sym_case_statement,
  [2951] = 35,
    ACTIONS(3), 1,
      anon_sym_SLASH_SLASH,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(9), 1,
      anon_sym_return,
    ACTIONS(11), 1,
      anon_sym_break,
    ACTIONS(13), 1,
      anon_sym_continue,
    ACTIONS(15), 1,
      anon_sym_eval,
    ACTIONS(17), 1,
      anon_sym_print,
    ACTIONS(19), 1,
      anon_sym_not,
    ACTIONS(21), 1,
      anon_sym_DASH,
    ACTIONS(23), 1,
      anon_sym_TILDE,
    ACTIONS(25), 1,
      anon_sym_LPAREN,
    ACTIONS(29), 1,
      anon_sym_function,
    ACTIONS(31), 1,
      anon_sym_procedure,
    ACTIONS(33), 1,
      anon_sym_intrinsic,
    ACTIONS(35), 1,
      anon_sym__,
    ACTIONS(37), 1,
      anon_sym_if,
    ACTIONS(41), 1,
      anon_sym_while,
    ACTIONS(43), 1,
      anon_sym_repeat,
    ACTIONS(45), 1,
      anon_sym_case,
    ACTIONS(47), 1,
      sym_identifier,
    ACTIONS(120), 1,
      anon_sym_endintrinsic,
    ACTIONS(130), 1,
      sym_for_statement,
    STATE(25), 1,
      sym_comment,
    STATE(29), 1,
      aux_sym_block_repeat1,
    STATE(53), 1,
      sym_primary_expression,
    STATE(93), 1,
      sym__statement,
    STATE(99), 1,
      sym_expression,
    STATE(157), 1,
      sym_gen_expression,
    ACTIONS(49), 2,
      sym_string,
      sym_real,
    STATE(38), 2,
      sym_comparison_operator,
      sym_boolean_operator,
    STATE(196), 2,
      sym_assignment,
      sym_augmented_assignment,
    ACTIONS(27), 3,
      sym_true,
      sym_false,
      sym_integer,
    STATE(189), 3,
      sym_function_definition,
      sym_procedure_definition,
      sym_intrinsic_definition,
    STATE(36), 5,
      sym_unary_operator,
      sym_binary_operator,
      sym_ternary_operator,
      sym_parenthesized_expression,
      sym_call,
    STATE(210), 12,
      sym_expression_statement,
      sym_return_statement,
      sym_break_statement,
      sym_continue_statement,
      sym_eval_statement,
      sym_print_statement,
      sym__definition,
      sym__assignment,
      sym_if_statement,
      sym_while_statement,
      sym_repeat_statement,
      sym_case_statement,
  [3079] = 35,
    ACTIONS(3), 1,
      anon_sym_SLASH_SLASH,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(9), 1,
      anon_sym_return,
    ACTIONS(11), 1,
      anon_sym_break,
    ACTIONS(13), 1,
      anon_sym_continue,
    ACTIONS(15), 1,
      anon_sym_eval,
    ACTIONS(17), 1,
      anon_sym_print,
    ACTIONS(19), 1,
      anon_sym_not,
    ACTIONS(21), 1,
      anon_sym_DASH,
    ACTIONS(23), 1,
      anon_sym_TILDE,
    ACTIONS(25), 1,
      anon_sym_LPAREN,
    ACTIONS(29), 1,
      anon_sym_function,
    ACTIONS(31), 1,
      anon_sym_procedure,
    ACTIONS(33), 1,
      anon_sym_intrinsic,
    ACTIONS(35), 1,
      anon_sym__,
    ACTIONS(37), 1,
      anon_sym_if,
    ACTIONS(41), 1,
      anon_sym_while,
    ACTIONS(43), 1,
      anon_sym_repeat,
    ACTIONS(45), 1,
      anon_sym_case,
    ACTIONS(47), 1,
      sym_identifier,
    ACTIONS(144), 1,
      sym_for_statement,
    STATE(11), 1,
      aux_sym_block_repeat1,
    STATE(26), 1,
      sym_comment,
    STATE(53), 1,
      sym_primary_expression,
    STATE(76), 1,
      sym__statement,
    STATE(99), 1,
      sym_expression,
    STATE(157), 1,
      sym_gen_expression,
    STATE(205), 1,
      sym_block,
    ACTIONS(49), 2,
      sym_string,
      sym_real,
    STATE(38), 2,
      sym_comparison_operator,
      sym_boolean_operator,
    STATE(196), 2,
      sym_assignment,
      sym_augmented_assignment,
    ACTIONS(27), 3,
      sym_true,
      sym_false,
      sym_integer,
    STATE(189), 3,
      sym_function_definition,
      sym_procedure_definition,
      sym_intrinsic_definition,
    STATE(36), 5,
      sym_unary_operator,
      sym_binary_operator,
      sym_ternary_operator,
      sym_parenthesized_expression,
      sym_call,
    STATE(225), 12,
      sym_expression_statement,
      sym_return_statement,
      sym_break_statement,
      sym_continue_statement,
      sym_eval_statement,
      sym_print_statement,
      sym__definition,
      sym__assignment,
      sym_if_statement,
      sym_while_statement,
      sym_repeat_statement,
      sym_case_statement,
  [3207] = 35,
    ACTIONS(3), 1,
      anon_sym_SLASH_SLASH,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(9), 1,
      anon_sym_return,
    ACTIONS(11), 1,
      anon_sym_break,
    ACTIONS(13), 1,
      anon_sym_continue,
    ACTIONS(15), 1,
      anon_sym_eval,
    ACTIONS(17), 1,
      anon_sym_print,
    ACTIONS(19), 1,
      anon_sym_not,
    ACTIONS(21), 1,
      anon_sym_DASH,
    ACTIONS(23), 1,
      anon_sym_TILDE,
    ACTIONS(25), 1,
      anon_sym_LPAREN,
    ACTIONS(29), 1,
      anon_sym_function,
    ACTIONS(31), 1,
      anon_sym_procedure,
    ACTIONS(33), 1,
      anon_sym_intrinsic,
    ACTIONS(35), 1,
      anon_sym__,
    ACTIONS(37), 1,
      anon_sym_if,
    ACTIONS(41), 1,
      anon_sym_while,
    ACTIONS(43), 1,
      anon_sym_repeat,
    ACTIONS(45), 1,
      anon_sym_case,
    ACTIONS(47), 1,
      sym_identifier,
    ACTIONS(122), 1,
      sym_for_statement,
    STATE(3), 1,
      aux_sym_block_repeat1,
    STATE(27), 1,
      sym_comment,
    STATE(53), 1,
      sym_primary_expression,
    STATE(64), 1,
      sym__statement,
    STATE(99), 1,
      sym_expression,
    STATE(157), 1,
      sym_gen_expression,
    STATE(160), 1,
      sym_block,
    ACTIONS(49), 2,
      sym_string,
      sym_real,
    STATE(38), 2,
      sym_comparison_operator,
      sym_boolean_operator,
    STATE(196), 2,
      sym_assignment,
      sym_augmented_assignment,
    ACTIONS(27), 3,
      sym_true,
      sym_false,
      sym_integer,
    STATE(189), 3,
      sym_function_definition,
      sym_procedure_definition,
      sym_intrinsic_definition,
    STATE(36), 5,
      sym_unary_operator,
      sym_binary_operator,
      sym_ternary_operator,
      sym_parenthesized_expression,
      sym_call,
    STATE(223), 12,
      sym_expression_statement,
      sym_return_statement,
      sym_break_statement,
      sym_continue_statement,
      sym_eval_statement,
      sym_print_statement,
      sym__definition,
      sym__assignment,
      sym_if_statement,
      sym_while_statement,
      sym_repeat_statement,
      sym_case_statement,
  [3335] = 35,
    ACTIONS(3), 1,
      anon_sym_SLASH_SLASH,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(9), 1,
      anon_sym_return,
    ACTIONS(11), 1,
      anon_sym_break,
    ACTIONS(13), 1,
      anon_sym_continue,
    ACTIONS(15), 1,
      anon_sym_eval,
    ACTIONS(17), 1,
      anon_sym_print,
    ACTIONS(19), 1,
      anon_sym_not,
    ACTIONS(21), 1,
      anon_sym_DASH,
    ACTIONS(23), 1,
      anon_sym_TILDE,
    ACTIONS(25), 1,
      anon_sym_LPAREN,
    ACTIONS(29), 1,
      anon_sym_function,
    ACTIONS(31), 1,
      anon_sym_procedure,
    ACTIONS(33), 1,
      anon_sym_intrinsic,
    ACTIONS(35), 1,
      anon_sym__,
    ACTIONS(37), 1,
      anon_sym_if,
    ACTIONS(39), 1,
      sym_for_statement,
    ACTIONS(41), 1,
      anon_sym_while,
    ACTIONS(43), 1,
      anon_sym_repeat,
    ACTIONS(45), 1,
      anon_sym_case,
    ACTIONS(47), 1,
      sym_identifier,
    ACTIONS(227), 1,
      ts_builtin_sym_end,
    STATE(17), 1,
      aux_sym_program_repeat1,
    STATE(28), 1,
      sym_comment,
    STATE(53), 1,
      sym_primary_expression,
    STATE(86), 1,
      sym__statement,
    STATE(99), 1,
      sym_expression,
    STATE(157), 1,
      sym_gen_expression,
    ACTIONS(49), 2,
      sym_string,
      sym_real,
    STATE(38), 2,
      sym_comparison_operator,
      sym_boolean_operator,
    STATE(196), 2,
      sym_assignment,
      sym_augmented_assignment,
    ACTIONS(27), 3,
      sym_true,
      sym_false,
      sym_integer,
    STATE(189), 3,
      sym_function_definition,
      sym_procedure_definition,
      sym_intrinsic_definition,
    STATE(36), 5,
      sym_unary_operator,
      sym_binary_operator,
      sym_ternary_operator,
      sym_parenthesized_expression,
      sym_call,
    STATE(194), 12,
      sym_expression_statement,
      sym_return_statement,
      sym_break_statement,
      sym_continue_statement,
      sym_eval_statement,
      sym_print_statement,
      sym__definition,
      sym__assignment,
      sym_if_statement,
      sym_while_statement,
      sym_repeat_statement,
      sym_case_statement,
  [3463] = 34,
    ACTIONS(3), 1,
      anon_sym_SLASH_SLASH,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(51), 1,
      anon_sym_return,
    ACTIONS(54), 1,
      anon_sym_break,
    ACTIONS(57), 1,
      anon_sym_continue,
    ACTIONS(60), 1,
      anon_sym_eval,
    ACTIONS(63), 1,
      anon_sym_print,
    ACTIONS(66), 1,
      anon_sym_not,
    ACTIONS(69), 1,
      anon_sym_DASH,
    ACTIONS(72), 1,
      anon_sym_TILDE,
    ACTIONS(77), 1,
      anon_sym_LPAREN,
    ACTIONS(83), 1,
      anon_sym_function,
    ACTIONS(86), 1,
      anon_sym_procedure,
    ACTIONS(89), 1,
      anon_sym_intrinsic,
    ACTIONS(92), 1,
      anon_sym__,
    ACTIONS(95), 1,
      anon_sym_if,
    ACTIONS(98), 1,
      anon_sym_endintrinsic,
    ACTIONS(103), 1,
      anon_sym_while,
    ACTIONS(106), 1,
      anon_sym_repeat,
    ACTIONS(109), 1,
      anon_sym_case,
    ACTIONS(112), 1,
      sym_identifier,
    ACTIONS(229), 1,
      sym_for_statement,
    STATE(53), 1,
      sym_primary_expression,
    STATE(93), 1,
      sym__statement,
    STATE(99), 1,
      sym_expression,
    STATE(157), 1,
      sym_gen_expression,
    ACTIONS(115), 2,
      sym_string,
      sym_real,
    STATE(29), 2,
      sym_comment,
      aux_sym_block_repeat1,
    STATE(38), 2,
      sym_comparison_operator,
      sym_boolean_operator,
    STATE(196), 2,
      sym_assignment,
      sym_augmented_assignment,
    ACTIONS(80), 3,
      sym_true,
      sym_false,
      sym_integer,
    STATE(189), 3,
      sym_function_definition,
      sym_procedure_definition,
      sym_intrinsic_definition,
    STATE(36), 5,
      sym_unary_operator,
      sym_binary_operator,
      sym_ternary_operator,
      sym_parenthesized_expression,
      sym_call,
    STATE(210), 12,
      sym_expression_statement,
      sym_return_statement,
      sym_break_statement,
      sym_continue_statement,
      sym_eval_statement,
      sym_print_statement,
      sym__definition,
      sym__assignment,
      sym_if_statement,
      sym_while_statement,
      sym_repeat_statement,
      sym_case_statement,
  [3589] = 5,
    ACTIONS(3), 1,
      anon_sym_SLASH_SLASH,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    STATE(30), 1,
      sym_comment,
    ACTIONS(232), 9,
      anon_sym_SLASH,
      anon_sym_DASH,
      anon_sym_PLUS,
      anon_sym_STAR,
      anon_sym_CARET,
      anon_sym_div,
      anon_sym_or,
      anon_sym_and,
      anon_sym_COLON,
    ACTIONS(234), 33,
      anon_sym_SEMI,
      anon_sym_COMMA,
      anon_sym_mod,
      anon_sym_CARET_CARET,
      anon_sym_join,
      anon_sym_diff,
      anon_sym_sdiff,
      anon_sym_meet,
      anon_sym_cat,
      anon_sym_select,
      anon_sym_else,
      anon_sym_gt,
      anon_sym_ge,
      anon_sym_lt,
      anon_sym_le,
      anon_sym_eq,
      anon_sym_ne,
      anon_sym_cmpeq,
      anon_sym_cmpne,
      anon_sym_xor,
      anon_sym_LPAREN,
      anon_sym_RPAREN,
      anon_sym_DASH_GT,
      anon_sym_COLON_EQ,
      anon_sym_PLUS_COLON_EQ,
      anon_sym_DASH_COLON_EQ,
      anon_sym_STAR_COLON_EQ,
      anon_sym_SLASH_COLON_EQ,
      anon_sym_and_COLON_EQ,
      anon_sym_or_COLON_EQ,
      anon_sym_div_COLON_EQ,
      anon_sym_then,
      anon_sym_do,
  [3645] = 8,
    ACTIONS(3), 1,
      anon_sym_SLASH_SLASH,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(240), 1,
      anon_sym_select,
    ACTIONS(242), 1,
      anon_sym_LPAREN,
    STATE(31), 1,
      sym_comment,
    STATE(34), 1,
      sym_argument_list,
    ACTIONS(236), 9,
      anon_sym_SLASH,
      anon_sym_DASH,
      anon_sym_PLUS,
      anon_sym_STAR,
      anon_sym_CARET,
      anon_sym_div,
      anon_sym_or,
      anon_sym_and,
      anon_sym_COLON,
    ACTIONS(238), 30,
      anon_sym_SEMI,
      anon_sym_COMMA,
      anon_sym_mod,
      anon_sym_CARET_CARET,
      anon_sym_join,
      anon_sym_diff,
      anon_sym_sdiff,
      anon_sym_meet,
      anon_sym_cat,
      anon_sym_else,
      anon_sym_gt,
      anon_sym_ge,
      anon_sym_lt,
      anon_sym_le,
      anon_sym_eq,
      anon_sym_ne,
      anon_sym_cmpeq,
      anon_sym_cmpne,
      anon_sym_xor,
      anon_sym_RPAREN,
      anon_sym_COLON_EQ,
      anon_sym_PLUS_COLON_EQ,
      anon_sym_DASH_COLON_EQ,
      anon_sym_STAR_COLON_EQ,
      anon_sym_SLASH_COLON_EQ,
      anon_sym_and_COLON_EQ,
      anon_sym_or_COLON_EQ,
      anon_sym_div_COLON_EQ,
      anon_sym_then,
      anon_sym_do,
  [3707] = 5,
    ACTIONS(3), 1,
      anon_sym_SLASH_SLASH,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    STATE(32), 1,
      sym_comment,
    ACTIONS(244), 9,
      anon_sym_SLASH,
      anon_sym_DASH,
      anon_sym_PLUS,
      anon_sym_STAR,
      anon_sym_CARET,
      anon_sym_div,
      anon_sym_or,
      anon_sym_and,
      anon_sym_COLON,
    ACTIONS(246), 33,
      anon_sym_SEMI,
      anon_sym_COMMA,
      anon_sym_mod,
      anon_sym_CARET_CARET,
      anon_sym_join,
      anon_sym_diff,
      anon_sym_sdiff,
      anon_sym_meet,
      anon_sym_cat,
      anon_sym_select,
      anon_sym_else,
      anon_sym_gt,
      anon_sym_ge,
      anon_sym_lt,
      anon_sym_le,
      anon_sym_eq,
      anon_sym_ne,
      anon_sym_cmpeq,
      anon_sym_cmpne,
      anon_sym_xor,
      anon_sym_LPAREN,
      anon_sym_RPAREN,
      anon_sym_DASH_GT,
      anon_sym_COLON_EQ,
      anon_sym_PLUS_COLON_EQ,
      anon_sym_DASH_COLON_EQ,
      anon_sym_STAR_COLON_EQ,
      anon_sym_SLASH_COLON_EQ,
      anon_sym_and_COLON_EQ,
      anon_sym_or_COLON_EQ,
      anon_sym_div_COLON_EQ,
      anon_sym_then,
      anon_sym_do,
  [3763] = 5,
    ACTIONS(3), 1,
      anon_sym_SLASH_SLASH,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    STATE(33), 1,
      sym_comment,
    ACTIONS(248), 9,
      anon_sym_SLASH,
      anon_sym_DASH,
      anon_sym_PLUS,
      anon_sym_STAR,
      anon_sym_CARET,
      anon_sym_div,
      anon_sym_or,
      anon_sym_and,
      anon_sym_COLON,
    ACTIONS(250), 33,
      anon_sym_SEMI,
      anon_sym_COMMA,
      anon_sym_mod,
      anon_sym_CARET_CARET,
      anon_sym_join,
      anon_sym_diff,
      anon_sym_sdiff,
      anon_sym_meet,
      anon_sym_cat,
      anon_sym_select,
      anon_sym_else,
      anon_sym_gt,
      anon_sym_ge,
      anon_sym_lt,
      anon_sym_le,
      anon_sym_eq,
      anon_sym_ne,
      anon_sym_cmpeq,
      anon_sym_cmpne,
      anon_sym_xor,
      anon_sym_LPAREN,
      anon_sym_RPAREN,
      anon_sym_DASH_GT,
      anon_sym_COLON_EQ,
      anon_sym_PLUS_COLON_EQ,
      anon_sym_DASH_COLON_EQ,
      anon_sym_STAR_COLON_EQ,
      anon_sym_SLASH_COLON_EQ,
      anon_sym_and_COLON_EQ,
      anon_sym_or_COLON_EQ,
      anon_sym_div_COLON_EQ,
      anon_sym_then,
      anon_sym_do,
  [3819] = 5,
    ACTIONS(3), 1,
      anon_sym_SLASH_SLASH,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    STATE(34), 1,
      sym_comment,
    ACTIONS(252), 9,
      anon_sym_SLASH,
      anon_sym_DASH,
      anon_sym_PLUS,
      anon_sym_STAR,
      anon_sym_CARET,
      anon_sym_div,
      anon_sym_or,
      anon_sym_and,
      anon_sym_COLON,
    ACTIONS(254), 32,
      anon_sym_SEMI,
      anon_sym_COMMA,
      anon_sym_mod,
      anon_sym_CARET_CARET,
      anon_sym_join,
      anon_sym_diff,
      anon_sym_sdiff,
      anon_sym_meet,
      anon_sym_cat,
      anon_sym_select,
      anon_sym_else,
      anon_sym_gt,
      anon_sym_ge,
      anon_sym_lt,
      anon_sym_le,
      anon_sym_eq,
      anon_sym_ne,
      anon_sym_cmpeq,
      anon_sym_cmpne,
      anon_sym_xor,
      anon_sym_LPAREN,
      anon_sym_RPAREN,
      anon_sym_COLON_EQ,
      anon_sym_PLUS_COLON_EQ,
      anon_sym_DASH_COLON_EQ,
      anon_sym_STAR_COLON_EQ,
      anon_sym_SLASH_COLON_EQ,
      anon_sym_and_COLON_EQ,
      anon_sym_or_COLON_EQ,
      anon_sym_div_COLON_EQ,
      anon_sym_then,
      anon_sym_do,
  [3874] = 10,
    ACTIONS(3), 1,
      anon_sym_SLASH_SLASH,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(262), 1,
      anon_sym_CARET,
    ACTIONS(264), 1,
      anon_sym_mod,
    STATE(35), 1,
      sym_comment,
    ACTIONS(260), 2,
      anon_sym_DASH,
      anon_sym_PLUS,
    ACTIONS(266), 2,
      anon_sym_meet,
      anon_sym_cat,
    ACTIONS(256), 3,
      anon_sym_SLASH,
      anon_sym_STAR,
      anon_sym_div,
    ACTIONS(268), 3,
      anon_sym_or,
      anon_sym_and,
      anon_sym_COLON,
    ACTIONS(258), 29,
      anon_sym_SEMI,
      anon_sym_COMMA,
      anon_sym_CARET_CARET,
      anon_sym_join,
      anon_sym_diff,
      anon_sym_sdiff,
      anon_sym_select,
      anon_sym_else,
      anon_sym_gt,
      anon_sym_ge,
      anon_sym_lt,
      anon_sym_le,
      anon_sym_eq,
      anon_sym_ne,
      anon_sym_cmpeq,
      anon_sym_cmpne,
      anon_sym_xor,
      anon_sym_LPAREN,
      anon_sym_RPAREN,
      anon_sym_COLON_EQ,
      anon_sym_PLUS_COLON_EQ,
      anon_sym_DASH_COLON_EQ,
      anon_sym_STAR_COLON_EQ,
      anon_sym_SLASH_COLON_EQ,
      anon_sym_and_COLON_EQ,
      anon_sym_or_COLON_EQ,
      anon_sym_div_COLON_EQ,
      anon_sym_then,
      anon_sym_do,
  [3939] = 5,
    ACTIONS(3), 1,
      anon_sym_SLASH_SLASH,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    STATE(36), 1,
      sym_comment,
    ACTIONS(270), 9,
      anon_sym_SLASH,
      anon_sym_DASH,
      anon_sym_PLUS,
      anon_sym_STAR,
      anon_sym_CARET,
      anon_sym_div,
      anon_sym_or,
      anon_sym_and,
      anon_sym_COLON,
    ACTIONS(272), 32,
      anon_sym_SEMI,
      anon_sym_COMMA,
      anon_sym_mod,
      anon_sym_CARET_CARET,
      anon_sym_join,
      anon_sym_diff,
      anon_sym_sdiff,
      anon_sym_meet,
      anon_sym_cat,
      anon_sym_select,
      anon_sym_else,
      anon_sym_gt,
      anon_sym_ge,
      anon_sym_lt,
      anon_sym_le,
      anon_sym_eq,
      anon_sym_ne,
      anon_sym_cmpeq,
      anon_sym_cmpne,
      anon_sym_xor,
      anon_sym_LPAREN,
      anon_sym_RPAREN,
      anon_sym_COLON_EQ,
      anon_sym_PLUS_COLON_EQ,
      anon_sym_DASH_COLON_EQ,
      anon_sym_STAR_COLON_EQ,
      anon_sym_SLASH_COLON_EQ,
      anon_sym_and_COLON_EQ,
      anon_sym_or_COLON_EQ,
      anon_sym_div_COLON_EQ,
      anon_sym_then,
      anon_sym_do,
  [3994] = 5,
    ACTIONS(3), 1,
      anon_sym_SLASH_SLASH,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    STATE(37), 1,
      sym_comment,
    ACTIONS(274), 9,
      anon_sym_SLASH,
      anon_sym_DASH,
      anon_sym_PLUS,
      anon_sym_STAR,
      anon_sym_CARET,
      anon_sym_div,
      anon_sym_or,
      anon_sym_and,
      anon_sym_COLON,
    ACTIONS(276), 32,
      anon_sym_SEMI,
      anon_sym_COMMA,
      anon_sym_mod,
      anon_sym_CARET_CARET,
      anon_sym_join,
      anon_sym_diff,
      anon_sym_sdiff,
      anon_sym_meet,
      anon_sym_cat,
      anon_sym_select,
      anon_sym_else,
      anon_sym_gt,
      anon_sym_ge,
      anon_sym_lt,
      anon_sym_le,
      anon_sym_eq,
      anon_sym_ne,
      anon_sym_cmpeq,
      anon_sym_cmpne,
      anon_sym_xor,
      anon_sym_LPAREN,
      anon_sym_RPAREN,
      anon_sym_COLON_EQ,
      anon_sym_PLUS_COLON_EQ,
      anon_sym_DASH_COLON_EQ,
      anon_sym_STAR_COLON_EQ,
      anon_sym_SLASH_COLON_EQ,
      anon_sym_and_COLON_EQ,
      anon_sym_or_COLON_EQ,
      anon_sym_div_COLON_EQ,
      anon_sym_then,
      anon_sym_do,
  [4049] = 5,
    ACTIONS(3), 1,
      anon_sym_SLASH_SLASH,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    STATE(38), 1,
      sym_comment,
    ACTIONS(236), 9,
      anon_sym_SLASH,
      anon_sym_DASH,
      anon_sym_PLUS,
      anon_sym_STAR,
      anon_sym_CARET,
      anon_sym_div,
      anon_sym_or,
      anon_sym_and,
      anon_sym_COLON,
    ACTIONS(238), 32,
      anon_sym_SEMI,
      anon_sym_COMMA,
      anon_sym_mod,
      anon_sym_CARET_CARET,
      anon_sym_join,
      anon_sym_diff,
      anon_sym_sdiff,
      anon_sym_meet,
      anon_sym_cat,
      anon_sym_select,
      anon_sym_else,
      anon_sym_gt,
      anon_sym_ge,
      anon_sym_lt,
      anon_sym_le,
      anon_sym_eq,
      anon_sym_ne,
      anon_sym_cmpeq,
      anon_sym_cmpne,
      anon_sym_xor,
      anon_sym_LPAREN,
      anon_sym_RPAREN,
      anon_sym_COLON_EQ,
      anon_sym_PLUS_COLON_EQ,
      anon_sym_DASH_COLON_EQ,
      anon_sym_STAR_COLON_EQ,
      anon_sym_SLASH_COLON_EQ,
      anon_sym_and_COLON_EQ,
      anon_sym_or_COLON_EQ,
      anon_sym_div_COLON_EQ,
      anon_sym_then,
      anon_sym_do,
  [4104] = 15,
    ACTIONS(3), 1,
      anon_sym_SLASH_SLASH,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(262), 1,
      anon_sym_CARET,
    ACTIONS(264), 1,
      anon_sym_mod,
    ACTIONS(280), 1,
      anon_sym_join,
    ACTIONS(282), 1,
      anon_sym_diff,
    ACTIONS(284), 1,
      anon_sym_sdiff,
    ACTIONS(290), 1,
      anon_sym_and,
    STATE(39), 1,
      sym_comment,
    ACTIONS(260), 2,
      anon_sym_DASH,
      anon_sym_PLUS,
    ACTIONS(266), 2,
      anon_sym_meet,
      anon_sym_cat,
    ACTIONS(288), 2,
      anon_sym_or,
      anon_sym_COLON,
    ACTIONS(256), 3,
      anon_sym_SLASH,
      anon_sym_STAR,
      anon_sym_div,
    ACTIONS(286), 8,
      anon_sym_gt,
      anon_sym_ge,
      anon_sym_lt,
      anon_sym_le,
      anon_sym_eq,
      anon_sym_ne,
      anon_sym_cmpeq,
      anon_sym_cmpne,
    ACTIONS(278), 18,
      anon_sym_SEMI,
      anon_sym_COMMA,
      anon_sym_CARET_CARET,
      anon_sym_select,
      anon_sym_else,
      anon_sym_xor,
      anon_sym_LPAREN,
      anon_sym_RPAREN,
      anon_sym_COLON_EQ,
      anon_sym_PLUS_COLON_EQ,
      anon_sym_DASH_COLON_EQ,
      anon_sym_STAR_COLON_EQ,
      anon_sym_SLASH_COLON_EQ,
      anon_sym_and_COLON_EQ,
      anon_sym_or_COLON_EQ,
      anon_sym_div_COLON_EQ,
      anon_sym_then,
      anon_sym_do,
  [4179] = 6,
    ACTIONS(3), 1,
      anon_sym_SLASH_SLASH,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(262), 1,
      anon_sym_CARET,
    STATE(40), 1,
      sym_comment,
    ACTIONS(268), 8,
      anon_sym_SLASH,
      anon_sym_DASH,
      anon_sym_PLUS,
      anon_sym_STAR,
      anon_sym_div,
      anon_sym_or,
      anon_sym_and,
      anon_sym_COLON,
    ACTIONS(258), 32,
      anon_sym_SEMI,
      anon_sym_COMMA,
      anon_sym_mod,
      anon_sym_CARET_CARET,
      anon_sym_join,
      anon_sym_diff,
      anon_sym_sdiff,
      anon_sym_meet,
      anon_sym_cat,
      anon_sym_select,
      anon_sym_else,
      anon_sym_gt,
      anon_sym_ge,
      anon_sym_lt,
      anon_sym_le,
      anon_sym_eq,
      anon_sym_ne,
      anon_sym_cmpeq,
      anon_sym_cmpne,
      anon_sym_xor,
      anon_sym_LPAREN,
      anon_sym_RPAREN,
      anon_sym_COLON_EQ,
      anon_sym_PLUS_COLON_EQ,
      anon_sym_DASH_COLON_EQ,
      anon_sym_STAR_COLON_EQ,
      anon_sym_SLASH_COLON_EQ,
      anon_sym_and_COLON_EQ,
      anon_sym_or_COLON_EQ,
      anon_sym_div_COLON_EQ,
      anon_sym_then,
      anon_sym_do,
  [4236] = 9,
    ACTIONS(3), 1,
      anon_sym_SLASH_SLASH,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(262), 1,
      anon_sym_CARET,
    ACTIONS(264), 1,
      anon_sym_mod,
    STATE(41), 1,
      sym_comment,
    ACTIONS(260), 2,
      anon_sym_DASH,
      anon_sym_PLUS,
    ACTIONS(256), 3,
      anon_sym_SLASH,
      anon_sym_STAR,
      anon_sym_div,
    ACTIONS(268), 3,
      anon_sym_or,
      anon_sym_and,
      anon_sym_COLON,
    ACTIONS(258), 31,
      anon_sym_SEMI,
      anon_sym_COMMA,
      anon_sym_CARET_CARET,
      anon_sym_join,
      anon_sym_diff,
      anon_sym_sdiff,
      anon_sym_meet,
      anon_sym_cat,
      anon_sym_select,
      anon_sym_else,
      anon_sym_gt,
      anon_sym_ge,
      anon_sym_lt,
      anon_sym_le,
      anon_sym_eq,
      anon_sym_ne,
      anon_sym_cmpeq,
      anon_sym_cmpne,
      anon_sym_xor,
      anon_sym_LPAREN,
      anon_sym_RPAREN,
      anon_sym_COLON_EQ,
      anon_sym_PLUS_COLON_EQ,
      anon_sym_DASH_COLON_EQ,
      anon_sym_STAR_COLON_EQ,
      anon_sym_SLASH_COLON_EQ,
      anon_sym_and_COLON_EQ,
      anon_sym_or_COLON_EQ,
      anon_sym_div_COLON_EQ,
      anon_sym_then,
      anon_sym_do,
  [4299] = 14,
    ACTIONS(3), 1,
      anon_sym_SLASH_SLASH,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(262), 1,
      anon_sym_CARET,
    ACTIONS(264), 1,
      anon_sym_mod,
    ACTIONS(280), 1,
      anon_sym_join,
    ACTIONS(282), 1,
      anon_sym_diff,
    ACTIONS(284), 1,
      anon_sym_sdiff,
    STATE(42), 1,
      sym_comment,
    ACTIONS(260), 2,
      anon_sym_DASH,
      anon_sym_PLUS,
    ACTIONS(266), 2,
      anon_sym_meet,
      anon_sym_cat,
    ACTIONS(256), 3,
      anon_sym_SLASH,
      anon_sym_STAR,
      anon_sym_div,
    ACTIONS(294), 3,
      anon_sym_or,
      anon_sym_and,
      anon_sym_COLON,
    ACTIONS(286), 8,
      anon_sym_gt,
      anon_sym_ge,
      anon_sym_lt,
      anon_sym_le,
      anon_sym_eq,
      anon_sym_ne,
      anon_sym_cmpeq,
      anon_sym_cmpne,
    ACTIONS(292), 18,
      anon_sym_SEMI,
      anon_sym_COMMA,
      anon_sym_CARET_CARET,
      anon_sym_select,
      anon_sym_else,
      anon_sym_xor,
      anon_sym_LPAREN,
      anon_sym_RPAREN,
      anon_sym_COLON_EQ,
      anon_sym_PLUS_COLON_EQ,
      anon_sym_DASH_COLON_EQ,
      anon_sym_STAR_COLON_EQ,
      anon_sym_SLASH_COLON_EQ,
      anon_sym_and_COLON_EQ,
      anon_sym_or_COLON_EQ,
      anon_sym_div_COLON_EQ,
      anon_sym_then,
      anon_sym_do,
  [4372] = 6,
    ACTIONS(3), 1,
      anon_sym_SLASH_SLASH,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(262), 1,
      anon_sym_CARET,
    STATE(43), 1,
      sym_comment,
    ACTIONS(294), 8,
      anon_sym_SLASH,
      anon_sym_DASH,
      anon_sym_PLUS,
      anon_sym_STAR,
      anon_sym_div,
      anon_sym_or,
      anon_sym_and,
      anon_sym_COLON,
    ACTIONS(292), 32,
      anon_sym_SEMI,
      anon_sym_COMMA,
      anon_sym_mod,
      anon_sym_CARET_CARET,
      anon_sym_join,
      anon_sym_diff,
      anon_sym_sdiff,
      anon_sym_meet,
      anon_sym_cat,
      anon_sym_select,
      anon_sym_else,
      anon_sym_gt,
      anon_sym_ge,
      anon_sym_lt,
      anon_sym_le,
      anon_sym_eq,
      anon_sym_ne,
      anon_sym_cmpeq,
      anon_sym_cmpne,
      anon_sym_xor,
      anon_sym_LPAREN,
      anon_sym_RPAREN,
      anon_sym_COLON_EQ,
      anon_sym_PLUS_COLON_EQ,
      anon_sym_DASH_COLON_EQ,
      anon_sym_STAR_COLON_EQ,
      anon_sym_SLASH_COLON_EQ,
      anon_sym_and_COLON_EQ,
      anon_sym_or_COLON_EQ,
      anon_sym_div_COLON_EQ,
      anon_sym_then,
      anon_sym_do,
  [4429] = 8,
    ACTIONS(3), 1,
      anon_sym_SLASH_SLASH,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(262), 1,
      anon_sym_CARET,
    ACTIONS(264), 1,
      anon_sym_mod,
    STATE(44), 1,
      sym_comment,
    ACTIONS(256), 3,
      anon_sym_SLASH,
      anon_sym_STAR,
      anon_sym_div,
    ACTIONS(268), 5,
      anon_sym_DASH,
      anon_sym_PLUS,
      anon_sym_or,
      anon_sym_and,
      anon_sym_COLON,
    ACTIONS(258), 31,
      anon_sym_SEMI,
      anon_sym_COMMA,
      anon_sym_CARET_CARET,
      anon_sym_join,
      anon_sym_diff,
      anon_sym_sdiff,
      anon_sym_meet,
      anon_sym_cat,
      anon_sym_select,
      anon_sym_else,
      anon_sym_gt,
      anon_sym_ge,
      anon_sym_lt,
      anon_sym_le,
      anon_sym_eq,
      anon_sym_ne,
      anon_sym_cmpeq,
      anon_sym_cmpne,
      anon_sym_xor,
      anon_sym_LPAREN,
      anon_sym_RPAREN,
      anon_sym_COLON_EQ,
      anon_sym_PLUS_COLON_EQ,
      anon_sym_DASH_COLON_EQ,
      anon_sym_STAR_COLON_EQ,
      anon_sym_SLASH_COLON_EQ,
      anon_sym_and_COLON_EQ,
      anon_sym_or_COLON_EQ,
      anon_sym_div_COLON_EQ,
      anon_sym_then,
      anon_sym_do,
  [4490] = 6,
    ACTIONS(3), 1,
      anon_sym_SLASH_SLASH,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(262), 1,
      anon_sym_CARET,
    STATE(45), 1,
      sym_comment,
    ACTIONS(268), 8,
      anon_sym_SLASH,
      anon_sym_DASH,
      anon_sym_PLUS,
      anon_sym_STAR,
      anon_sym_div,
      anon_sym_or,
      anon_sym_and,
      anon_sym_COLON,
    ACTIONS(258), 32,
      anon_sym_SEMI,
      anon_sym_COMMA,
      anon_sym_mod,
      anon_sym_CARET_CARET,
      anon_sym_join,
      anon_sym_diff,
      anon_sym_sdiff,
      anon_sym_meet,
      anon_sym_cat,
      anon_sym_select,
      anon_sym_else,
      anon_sym_gt,
      anon_sym_ge,
      anon_sym_lt,
      anon_sym_le,
      anon_sym_eq,
      anon_sym_ne,
      anon_sym_cmpeq,
      anon_sym_cmpne,
      anon_sym_xor,
      anon_sym_LPAREN,
      anon_sym_RPAREN,
      anon_sym_COLON_EQ,
      anon_sym_PLUS_COLON_EQ,
      anon_sym_DASH_COLON_EQ,
      anon_sym_STAR_COLON_EQ,
      anon_sym_SLASH_COLON_EQ,
      anon_sym_and_COLON_EQ,
      anon_sym_or_COLON_EQ,
      anon_sym_div_COLON_EQ,
      anon_sym_then,
      anon_sym_do,
  [4547] = 6,
    ACTIONS(3), 1,
      anon_sym_SLASH_SLASH,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(262), 1,
      anon_sym_CARET,
    STATE(46), 1,
      sym_comment,
    ACTIONS(294), 8,
      anon_sym_SLASH,
      anon_sym_DASH,
      anon_sym_PLUS,
      anon_sym_STAR,
      anon_sym_div,
      anon_sym_or,
      anon_sym_and,
      anon_sym_COLON,
    ACTIONS(292), 32,
      anon_sym_SEMI,
      anon_sym_COMMA,
      anon_sym_mod,
      anon_sym_CARET_CARET,
      anon_sym_join,
      anon_sym_diff,
      anon_sym_sdiff,
      anon_sym_meet,
      anon_sym_cat,
      anon_sym_select,
      anon_sym_else,
      anon_sym_gt,
      anon_sym_ge,
      anon_sym_lt,
      anon_sym_le,
      anon_sym_eq,
      anon_sym_ne,
      anon_sym_cmpeq,
      anon_sym_cmpne,
      anon_sym_xor,
      anon_sym_LPAREN,
      anon_sym_RPAREN,
      anon_sym_COLON_EQ,
      anon_sym_PLUS_COLON_EQ,
      anon_sym_DASH_COLON_EQ,
      anon_sym_STAR_COLON_EQ,
      anon_sym_SLASH_COLON_EQ,
      anon_sym_and_COLON_EQ,
      anon_sym_or_COLON_EQ,
      anon_sym_div_COLON_EQ,
      anon_sym_then,
      anon_sym_do,
  [4604] = 17,
    ACTIONS(3), 1,
      anon_sym_SLASH_SLASH,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(262), 1,
      anon_sym_CARET,
    ACTIONS(264), 1,
      anon_sym_mod,
    ACTIONS(268), 1,
      anon_sym_COLON,
    ACTIONS(280), 1,
      anon_sym_join,
    ACTIONS(282), 1,
      anon_sym_diff,
    ACTIONS(284), 1,
      anon_sym_sdiff,
    ACTIONS(290), 1,
      anon_sym_and,
    ACTIONS(296), 1,
      anon_sym_or,
    ACTIONS(298), 1,
      anon_sym_xor,
    STATE(47), 1,
      sym_comment,
    ACTIONS(260), 2,
      anon_sym_DASH,
      anon_sym_PLUS,
    ACTIONS(266), 2,
      anon_sym_meet,
      anon_sym_cat,
    ACTIONS(256), 3,
      anon_sym_SLASH,
      anon_sym_STAR,
      anon_sym_div,
    ACTIONS(286), 8,
      anon_sym_gt,
      anon_sym_ge,
      anon_sym_lt,
      anon_sym_le,
      anon_sym_eq,
      anon_sym_ne,
      anon_sym_cmpeq,
      anon_sym_cmpne,
    ACTIONS(258), 17,
      anon_sym_SEMI,
      anon_sym_COMMA,
      anon_sym_CARET_CARET,
      anon_sym_select,
      anon_sym_else,
      anon_sym_LPAREN,
      anon_sym_RPAREN,
      anon_sym_COLON_EQ,
      anon_sym_PLUS_COLON_EQ,
      anon_sym_DASH_COLON_EQ,
      anon_sym_STAR_COLON_EQ,
      anon_sym_SLASH_COLON_EQ,
      anon_sym_and_COLON_EQ,
      anon_sym_or_COLON_EQ,
      anon_sym_div_COLON_EQ,
      anon_sym_then,
      anon_sym_do,
  [4683] = 11,
    ACTIONS(3), 1,
      anon_sym_SLASH_SLASH,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(262), 1,
      anon_sym_CARET,
    ACTIONS(264), 1,
      anon_sym_mod,
    ACTIONS(284), 1,
      anon_sym_sdiff,
    STATE(48), 1,
      sym_comment,
    ACTIONS(260), 2,
      anon_sym_DASH,
      anon_sym_PLUS,
    ACTIONS(266), 2,
      anon_sym_meet,
      anon_sym_cat,
    ACTIONS(256), 3,
      anon_sym_SLASH,
      anon_sym_STAR,
      anon_sym_div,
    ACTIONS(268), 3,
      anon_sym_or,
      anon_sym_and,
      anon_sym_COLON,
    ACTIONS(258), 28,
      anon_sym_SEMI,
      anon_sym_COMMA,
      anon_sym_CARET_CARET,
      anon_sym_join,
      anon_sym_diff,
      anon_sym_select,
      anon_sym_else,
      anon_sym_gt,
      anon_sym_ge,
      anon_sym_lt,
      anon_sym_le,
      anon_sym_eq,
      anon_sym_ne,
      anon_sym_cmpeq,
      anon_sym_cmpne,
      anon_sym_xor,
      anon_sym_LPAREN,
      anon_sym_RPAREN,
      anon_sym_COLON_EQ,
      anon_sym_PLUS_COLON_EQ,
      anon_sym_DASH_COLON_EQ,
      anon_sym_STAR_COLON_EQ,
      anon_sym_SLASH_COLON_EQ,
      anon_sym_and_COLON_EQ,
      anon_sym_or_COLON_EQ,
      anon_sym_div_COLON_EQ,
      anon_sym_then,
      anon_sym_do,
  [4750] = 12,
    ACTIONS(3), 1,
      anon_sym_SLASH_SLASH,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(262), 1,
      anon_sym_CARET,
    ACTIONS(264), 1,
      anon_sym_mod,
    ACTIONS(282), 1,
      anon_sym_diff,
    ACTIONS(284), 1,
      anon_sym_sdiff,
    STATE(49), 1,
      sym_comment,
    ACTIONS(260), 2,
      anon_sym_DASH,
      anon_sym_PLUS,
    ACTIONS(266), 2,
      anon_sym_meet,
      anon_sym_cat,
    ACTIONS(256), 3,
      anon_sym_SLASH,
      anon_sym_STAR,
      anon_sym_div,
    ACTIONS(268), 3,
      anon_sym_or,
      anon_sym_and,
      anon_sym_COLON,
    ACTIONS(258), 27,
      anon_sym_SEMI,
      anon_sym_COMMA,
      anon_sym_CARET_CARET,
      anon_sym_join,
      anon_sym_select,
      anon_sym_else,
      anon_sym_gt,
      anon_sym_ge,
      anon_sym_lt,
      anon_sym_le,
      anon_sym_eq,
      anon_sym_ne,
      anon_sym_cmpeq,
      anon_sym_cmpne,
      anon_sym_xor,
      anon_sym_LPAREN,
      anon_sym_RPAREN,
      anon_sym_COLON_EQ,
      anon_sym_PLUS_COLON_EQ,
      anon_sym_DASH_COLON_EQ,
      anon_sym_STAR_COLON_EQ,
      anon_sym_SLASH_COLON_EQ,
      anon_sym_and_COLON_EQ,
      anon_sym_or_COLON_EQ,
      anon_sym_div_COLON_EQ,
      anon_sym_then,
      anon_sym_do,
  [4819] = 14,
    ACTIONS(3), 1,
      anon_sym_SLASH_SLASH,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(262), 1,
      anon_sym_CARET,
    ACTIONS(264), 1,
      anon_sym_mod,
    ACTIONS(280), 1,
      anon_sym_join,
    ACTIONS(282), 1,
      anon_sym_diff,
    ACTIONS(284), 1,
      anon_sym_sdiff,
    STATE(50), 1,
      sym_comment,
    ACTIONS(260), 2,
      anon_sym_DASH,
      anon_sym_PLUS,
    ACTIONS(266), 2,
      anon_sym_meet,
      anon_sym_cat,
    ACTIONS(256), 3,
      anon_sym_SLASH,
      anon_sym_STAR,
      anon_sym_div,
    ACTIONS(288), 3,
      anon_sym_or,
      anon_sym_and,
      anon_sym_COLON,
    ACTIONS(286), 8,
      anon_sym_gt,
      anon_sym_ge,
      anon_sym_lt,
      anon_sym_le,
      anon_sym_eq,
      anon_sym_ne,
      anon_sym_cmpeq,
      anon_sym_cmpne,
    ACTIONS(278), 18,
      anon_sym_SEMI,
      anon_sym_COMMA,
      anon_sym_CARET_CARET,
      anon_sym_select,
      anon_sym_else,
      anon_sym_xor,
      anon_sym_LPAREN,
      anon_sym_RPAREN,
      anon_sym_COLON_EQ,
      anon_sym_PLUS_COLON_EQ,
      anon_sym_DASH_COLON_EQ,
      anon_sym_STAR_COLON_EQ,
      anon_sym_SLASH_COLON_EQ,
      anon_sym_and_COLON_EQ,
      anon_sym_or_COLON_EQ,
      anon_sym_div_COLON_EQ,
      anon_sym_then,
      anon_sym_do,
  [4892] = 18,
    ACTIONS(3), 1,
      anon_sym_SLASH_SLASH,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(262), 1,
      anon_sym_CARET,
    ACTIONS(264), 1,
      anon_sym_mod,
    ACTIONS(280), 1,
      anon_sym_join,
    ACTIONS(282), 1,
      anon_sym_diff,
    ACTIONS(284), 1,
      anon_sym_sdiff,
    ACTIONS(290), 1,
      anon_sym_and,
    ACTIONS(296), 1,
      anon_sym_or,
    ACTIONS(298), 1,
      anon_sym_xor,
    ACTIONS(302), 1,
      anon_sym_CARET_CARET,
    ACTIONS(304), 1,
      anon_sym_COLON,
    STATE(51), 1,
      sym_comment,
    ACTIONS(260), 2,
      anon_sym_DASH,
      anon_sym_PLUS,
    ACTIONS(266), 2,
      anon_sym_meet,
      anon_sym_cat,
    ACTIONS(256), 3,
      anon_sym_SLASH,
      anon_sym_STAR,
      anon_sym_div,
    ACTIONS(286), 8,
      anon_sym_gt,
      anon_sym_ge,
      anon_sym_lt,
      anon_sym_le,
      anon_sym_eq,
      anon_sym_ne,
      anon_sym_cmpeq,
      anon_sym_cmpne,
    ACTIONS(300), 16,
      anon_sym_SEMI,
      anon_sym_COMMA,
      anon_sym_select,
      anon_sym_else,
      anon_sym_LPAREN,
      anon_sym_RPAREN,
      anon_sym_COLON_EQ,
      anon_sym_PLUS_COLON_EQ,
      anon_sym_DASH_COLON_EQ,
      anon_sym_STAR_COLON_EQ,
      anon_sym_SLASH_COLON_EQ,
      anon_sym_and_COLON_EQ,
      anon_sym_or_COLON_EQ,
      anon_sym_div_COLON_EQ,
      anon_sym_then,
      anon_sym_do,
  [4973] = 13,
    ACTIONS(3), 1,
      anon_sym_SLASH_SLASH,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(262), 1,
      anon_sym_CARET,
    ACTIONS(264), 1,
      anon_sym_mod,
    ACTIONS(280), 1,
      anon_sym_join,
    ACTIONS(282), 1,
      anon_sym_diff,
    ACTIONS(284), 1,
      anon_sym_sdiff,
    STATE(52), 1,
      sym_comment,
    ACTIONS(260), 2,
      anon_sym_DASH,
      anon_sym_PLUS,
    ACTIONS(266), 2,
      anon_sym_meet,
      anon_sym_cat,
    ACTIONS(256), 3,
      anon_sym_SLASH,
      anon_sym_STAR,
      anon_sym_div,
    ACTIONS(308), 3,
      anon_sym_or,
      anon_sym_and,
      anon_sym_COLON,
    ACTIONS(306), 26,
      anon_sym_SEMI,
      anon_sym_COMMA,
      anon_sym_CARET_CARET,
      anon_sym_select,
      anon_sym_else,
      anon_sym_gt,
      anon_sym_ge,
      anon_sym_lt,
      anon_sym_le,
      anon_sym_eq,
      anon_sym_ne,
      anon_sym_cmpeq,
      anon_sym_cmpne,
      anon_sym_xor,
      anon_sym_LPAREN,
      anon_sym_RPAREN,
      anon_sym_COLON_EQ,
      anon_sym_PLUS_COLON_EQ,
      anon_sym_DASH_COLON_EQ,
      anon_sym_STAR_COLON_EQ,
      anon_sym_SLASH_COLON_EQ,
      anon_sym_and_COLON_EQ,
      anon_sym_or_COLON_EQ,
      anon_sym_div_COLON_EQ,
      anon_sym_then,
      anon_sym_do,
  [5044] = 14,
    ACTIONS(3), 1,
      anon_sym_SLASH_SLASH,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(240), 1,
      anon_sym_select,
    ACTIONS(242), 1,
      anon_sym_LPAREN,
    ACTIONS(310), 1,
      anon_sym_SEMI,
    ACTIONS(312), 1,
      anon_sym_COMMA,
    ACTIONS(314), 1,
      anon_sym_COLON_EQ,
    STATE(34), 1,
      sym_argument_list,
    STATE(53), 1,
      sym_comment,
    STATE(147), 1,
      aux_sym__left_hand_side_repeat1,
    STATE(151), 1,
      aux_sym_expression_statement_repeat1,
    ACTIONS(316), 7,
      anon_sym_PLUS_COLON_EQ,
      anon_sym_DASH_COLON_EQ,
      anon_sym_STAR_COLON_EQ,
      anon_sym_SLASH_COLON_EQ,
      anon_sym_and_COLON_EQ,
      anon_sym_or_COLON_EQ,
      anon_sym_div_COLON_EQ,
    ACTIONS(236), 8,
      anon_sym_SLASH,
      anon_sym_DASH,
      anon_sym_PLUS,
      anon_sym_STAR,
      anon_sym_CARET,
      anon_sym_div,
      anon_sym_or,
      anon_sym_and,
    ACTIONS(238), 16,
      anon_sym_mod,
      anon_sym_CARET_CARET,
      anon_sym_join,
      anon_sym_diff,
      anon_sym_sdiff,
      anon_sym_meet,
      anon_sym_cat,
      anon_sym_gt,
      anon_sym_ge,
      anon_sym_lt,
      anon_sym_le,
      anon_sym_eq,
      anon_sym_ne,
      anon_sym_cmpeq,
      anon_sym_cmpne,
      anon_sym_xor,
  [5115] = 6,
    ACTIONS(3), 1,
      anon_sym_SLASH_SLASH,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(318), 1,
      anon_sym_LT,
    STATE(54), 1,
      sym_comment,
    ACTIONS(270), 8,
      anon_sym_SLASH,
      anon_sym_DASH,
      anon_sym_PLUS,
      anon_sym_STAR,
      anon_sym_CARET,
      anon_sym_div,
      anon_sym_or,
      anon_sym_and,
    ACTIONS(272), 28,
      anon_sym_SEMI,
      anon_sym_COMMA,
      anon_sym_mod,
      anon_sym_CARET_CARET,
      anon_sym_join,
      anon_sym_diff,
      anon_sym_sdiff,
      anon_sym_meet,
      anon_sym_cat,
      anon_sym_select,
      anon_sym_gt,
      anon_sym_ge,
      anon_sym_lt,
      anon_sym_le,
      anon_sym_eq,
      anon_sym_ne,
      anon_sym_cmpeq,
      anon_sym_cmpne,
      anon_sym_xor,
      anon_sym_LPAREN,
      anon_sym_COLON_EQ,
      anon_sym_PLUS_COLON_EQ,
      anon_sym_DASH_COLON_EQ,
      anon_sym_STAR_COLON_EQ,
      anon_sym_SLASH_COLON_EQ,
      anon_sym_and_COLON_EQ,
      anon_sym_or_COLON_EQ,
      anon_sym_div_COLON_EQ,
  [5168] = 11,
    ACTIONS(3), 1,
      anon_sym_SLASH_SLASH,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(240), 1,
      anon_sym_select,
    ACTIONS(242), 1,
      anon_sym_LPAREN,
    ACTIONS(320), 1,
      anon_sym_SEMI,
    ACTIONS(322), 1,
      anon_sym_COMMA,
    ACTIONS(325), 1,
      anon_sym_COLON_EQ,
    STATE(34), 1,
      sym_argument_list,
    STATE(55), 1,
      sym_comment,
    ACTIONS(236), 2,
      anon_sym_SLASH,
      anon_sym_CARET,
    ACTIONS(238), 22,
      anon_sym_DASH,
      anon_sym_PLUS,
      anon_sym_STAR,
      anon_sym_div,
      anon_sym_mod,
      anon_sym_CARET_CARET,
      anon_sym_join,
      anon_sym_diff,
      anon_sym_sdiff,
      anon_sym_meet,
      anon_sym_cat,
      anon_sym_gt,
      anon_sym_ge,
      anon_sym_lt,
      anon_sym_le,
      anon_sym_eq,
      anon_sym_ne,
      anon_sym_cmpeq,
      anon_sym_cmpne,
      anon_sym_or,
      anon_sym_xor,
      anon_sym_and,
  [5224] = 11,
    ACTIONS(3), 1,
      anon_sym_SLASH_SLASH,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(240), 1,
      anon_sym_select,
    ACTIONS(242), 1,
      anon_sym_LPAREN,
    ACTIONS(310), 1,
      anon_sym_SEMI,
    ACTIONS(327), 1,
      anon_sym_COMMA,
    STATE(34), 1,
      sym_argument_list,
    STATE(56), 1,
      sym_comment,
    STATE(151), 1,
      aux_sym_expression_statement_repeat1,
    ACTIONS(236), 2,
      anon_sym_SLASH,
      anon_sym_CARET,
    ACTIONS(238), 22,
      anon_sym_DASH,
      anon_sym_PLUS,
      anon_sym_STAR,
      anon_sym_div,
      anon_sym_mod,
      anon_sym_CARET_CARET,
      anon_sym_join,
      anon_sym_diff,
      anon_sym_sdiff,
      anon_sym_meet,
      anon_sym_cat,
      anon_sym_gt,
      anon_sym_ge,
      anon_sym_lt,
      anon_sym_le,
      anon_sym_eq,
      anon_sym_ne,
      anon_sym_cmpeq,
      anon_sym_cmpne,
      anon_sym_or,
      anon_sym_xor,
      anon_sym_and,
  [5280] = 9,
    ACTIONS(3), 1,
      anon_sym_SLASH_SLASH,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(240), 1,
      anon_sym_select,
    ACTIONS(242), 1,
      anon_sym_LPAREN,
    STATE(34), 1,
      sym_argument_list,
    STATE(57), 1,
      sym_comment,
    ACTIONS(236), 2,
      anon_sym_SLASH,
      anon_sym_CARET,
    ACTIONS(325), 2,
      anon_sym_COMMA,
      anon_sym_COLON_EQ,
    ACTIONS(238), 22,
      anon_sym_DASH,
      anon_sym_PLUS,
      anon_sym_STAR,
      anon_sym_div,
      anon_sym_mod,
      anon_sym_CARET_CARET,
      anon_sym_join,
      anon_sym_diff,
      anon_sym_sdiff,
      anon_sym_meet,
      anon_sym_cat,
      anon_sym_gt,
      anon_sym_ge,
      anon_sym_lt,
      anon_sym_le,
      anon_sym_eq,
      anon_sym_ne,
      anon_sym_cmpeq,
      anon_sym_cmpne,
      anon_sym_or,
      anon_sym_xor,
      anon_sym_and,
  [5331] = 9,
    ACTIONS(3), 1,
      anon_sym_SLASH_SLASH,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(240), 1,
      anon_sym_select,
    ACTIONS(242), 1,
      anon_sym_LPAREN,
    STATE(34), 1,
      sym_argument_list,
    STATE(58), 1,
      sym_comment,
    ACTIONS(236), 2,
      anon_sym_SLASH,
      anon_sym_CARET,
    ACTIONS(320), 2,
      anon_sym_SEMI,
      anon_sym_COMMA,
    ACTIONS(238), 22,
      anon_sym_DASH,
      anon_sym_PLUS,
      anon_sym_STAR,
      anon_sym_div,
      anon_sym_mod,
      anon_sym_CARET_CARET,
      anon_sym_join,
      anon_sym_diff,
      anon_sym_sdiff,
      anon_sym_meet,
      anon_sym_cat,
      anon_sym_gt,
      anon_sym_ge,
      anon_sym_lt,
      anon_sym_le,
      anon_sym_eq,
      anon_sym_ne,
      anon_sym_cmpeq,
      anon_sym_cmpne,
      anon_sym_or,
      anon_sym_xor,
      anon_sym_and,
  [5382] = 9,
    ACTIONS(3), 1,
      anon_sym_SLASH_SLASH,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(240), 1,
      anon_sym_select,
    ACTIONS(242), 1,
      anon_sym_LPAREN,
    ACTIONS(329), 1,
      anon_sym_SEMI,
    STATE(34), 1,
      sym_argument_list,
    STATE(59), 1,
      sym_comment,
    ACTIONS(236), 2,
      anon_sym_SLASH,
      anon_sym_CARET,
    ACTIONS(238), 22,
      anon_sym_DASH,
      anon_sym_PLUS,
      anon_sym_STAR,
      anon_sym_div,
      anon_sym_mod,
      anon_sym_CARET_CARET,
      anon_sym_join,
      anon_sym_diff,
      anon_sym_sdiff,
      anon_sym_meet,
      anon_sym_cat,
      anon_sym_gt,
      anon_sym_ge,
      anon_sym_lt,
      anon_sym_le,
      anon_sym_eq,
      anon_sym_ne,
      anon_sym_cmpeq,
      anon_sym_cmpne,
      anon_sym_or,
      anon_sym_xor,
      anon_sym_and,
  [5432] = 9,
    ACTIONS(3), 1,
      anon_sym_SLASH_SLASH,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(240), 1,
      anon_sym_select,
    ACTIONS(242), 1,
      anon_sym_LPAREN,
    ACTIONS(331), 1,
      anon_sym_COLON,
    STATE(34), 1,
      sym_argument_list,
    STATE(60), 1,
      sym_comment,
    ACTIONS(236), 2,
      anon_sym_SLASH,
      anon_sym_CARET,
    ACTIONS(238), 22,
      anon_sym_DASH,
      anon_sym_PLUS,
      anon_sym_STAR,
      anon_sym_div,
      anon_sym_mod,
      anon_sym_CARET_CARET,
      anon_sym_join,
      anon_sym_diff,
      anon_sym_sdiff,
      anon_sym_meet,
      anon_sym_cat,
      anon_sym_gt,
      anon_sym_ge,
      anon_sym_lt,
      anon_sym_le,
      anon_sym_eq,
      anon_sym_ne,
      anon_sym_cmpeq,
      anon_sym_cmpne,
      anon_sym_or,
      anon_sym_xor,
      anon_sym_and,
  [5482] = 9,
    ACTIONS(3), 1,
      anon_sym_SLASH_SLASH,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(240), 1,
      anon_sym_select,
    ACTIONS(242), 1,
      anon_sym_LPAREN,
    ACTIONS(333), 1,
      anon_sym_COLON,
    STATE(34), 1,
      sym_argument_list,
    STATE(61), 1,
      sym_comment,
    ACTIONS(236), 2,
      anon_sym_SLASH,
      anon_sym_CARET,
    ACTIONS(238), 22,
      anon_sym_DASH,
      anon_sym_PLUS,
      anon_sym_STAR,
      anon_sym_div,
      anon_sym_mod,
      anon_sym_CARET_CARET,
      anon_sym_join,
      anon_sym_diff,
      anon_sym_sdiff,
      anon_sym_meet,
      anon_sym_cat,
      anon_sym_gt,
      anon_sym_ge,
      anon_sym_lt,
      anon_sym_le,
      anon_sym_eq,
      anon_sym_ne,
      anon_sym_cmpeq,
      anon_sym_cmpne,
      anon_sym_or,
      anon_sym_xor,
      anon_sym_and,
  [5532] = 18,
    ACTIONS(3), 1,
      anon_sym_SLASH_SLASH,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(256), 1,
      anon_sym_SLASH,
    ACTIONS(262), 1,
      anon_sym_CARET,
    ACTIONS(280), 1,
      anon_sym_join,
    ACTIONS(282), 1,
      anon_sym_diff,
    ACTIONS(284), 1,
      anon_sym_sdiff,
    ACTIONS(302), 1,
      anon_sym_CARET_CARET,
    ACTIONS(335), 1,
      anon_sym_COMMA,
    ACTIONS(339), 1,
      anon_sym_and,
    ACTIONS(341), 1,
      anon_sym_RPAREN,
    STATE(62), 1,
      sym_comment,
    STATE(149), 1,
      aux_sym_print_statement_repeat1,
    ACTIONS(266), 2,
      anon_sym_meet,
      anon_sym_cat,
    ACTIONS(298), 2,
      anon_sym_or,
      anon_sym_xor,
    ACTIONS(337), 2,
      anon_sym_DASH,
      anon_sym_PLUS,
    ACTIONS(264), 3,
      anon_sym_STAR,
      anon_sym_div,
      anon_sym_mod,
    ACTIONS(286), 8,
      anon_sym_gt,
      anon_sym_ge,
      anon_sym_lt,
      anon_sym_le,
      anon_sym_eq,
      anon_sym_ne,
      anon_sym_cmpeq,
      anon_sym_cmpne,
  [5599] = 16,
    ACTIONS(3), 1,
      anon_sym_SLASH_SLASH,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(256), 1,
      anon_sym_SLASH,
    ACTIONS(262), 1,
      anon_sym_CARET,
    ACTIONS(280), 1,
      anon_sym_join,
    ACTIONS(282), 1,
      anon_sym_diff,
    ACTIONS(284), 1,
      anon_sym_sdiff,
    ACTIONS(302), 1,
      anon_sym_CARET_CARET,
    ACTIONS(339), 1,
      anon_sym_and,
    STATE(63), 1,
      sym_comment,
    ACTIONS(266), 2,
      anon_sym_meet,
      anon_sym_cat,
    ACTIONS(298), 2,
      anon_sym_or,
      anon_sym_xor,
    ACTIONS(337), 2,
      anon_sym_DASH,
      anon_sym_PLUS,
    ACTIONS(264), 3,
      anon_sym_STAR,
      anon_sym_div,
      anon_sym_mod,
    ACTIONS(343), 3,
      anon_sym_SEMI,
      anon_sym_COMMA,
      anon_sym_RPAREN,
    ACTIONS(286), 8,
      anon_sym_gt,
      anon_sym_ge,
      anon_sym_lt,
      anon_sym_le,
      anon_sym_eq,
      anon_sym_ne,
      anon_sym_cmpeq,
      anon_sym_cmpne,
  [5662] = 5,
    ACTIONS(3), 1,
      anon_sym_SLASH_SLASH,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    STATE(64), 1,
      sym_comment,
    ACTIONS(347), 7,
      anon_sym_DASH,
      anon_sym_TILDE,
      anon_sym_LPAREN,
      anon_sym_endif,
      sym_for_statement,
      sym_string,
      sym_real,
    ACTIONS(345), 20,
      anon_sym_return,
      anon_sym_break,
      anon_sym_continue,
      anon_sym_eval,
      anon_sym_print,
      anon_sym_not,
      anon_sym_else,
      sym_true,
      sym_false,
      anon_sym_function,
      anon_sym_procedure,
      anon_sym_intrinsic,
      anon_sym__,
      anon_sym_if,
      anon_sym_elif,
      anon_sym_while,
      anon_sym_repeat,
      anon_sym_case,
      sym_identifier,
      sym_integer,
  [5703] = 18,
    ACTIONS(3), 1,
      anon_sym_SLASH_SLASH,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(256), 1,
      anon_sym_SLASH,
    ACTIONS(262), 1,
      anon_sym_CARET,
    ACTIONS(280), 1,
      anon_sym_join,
    ACTIONS(282), 1,
      anon_sym_diff,
    ACTIONS(284), 1,
      anon_sym_sdiff,
    ACTIONS(302), 1,
      anon_sym_CARET_CARET,
    ACTIONS(335), 1,
      anon_sym_COMMA,
    ACTIONS(339), 1,
      anon_sym_and,
    ACTIONS(349), 1,
      anon_sym_SEMI,
    STATE(65), 1,
      sym_comment,
    STATE(154), 1,
      aux_sym_print_statement_repeat1,
    ACTIONS(266), 2,
      anon_sym_meet,
      anon_sym_cat,
    ACTIONS(298), 2,
      anon_sym_or,
      anon_sym_xor,
    ACTIONS(337), 2,
      anon_sym_DASH,
      anon_sym_PLUS,
    ACTIONS(264), 3,
      anon_sym_STAR,
      anon_sym_div,
      anon_sym_mod,
    ACTIONS(286), 8,
      anon_sym_gt,
      anon_sym_ge,
      anon_sym_lt,
      anon_sym_le,
      anon_sym_eq,
      anon_sym_ne,
      anon_sym_cmpeq,
      anon_sym_cmpne,
  [5770] = 18,
    ACTIONS(3), 1,
      anon_sym_SLASH_SLASH,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(256), 1,
      anon_sym_SLASH,
    ACTIONS(262), 1,
      anon_sym_CARET,
    ACTIONS(280), 1,
      anon_sym_join,
    ACTIONS(282), 1,
      anon_sym_diff,
    ACTIONS(284), 1,
      anon_sym_sdiff,
    ACTIONS(302), 1,
      anon_sym_CARET_CARET,
    ACTIONS(335), 1,
      anon_sym_COMMA,
    ACTIONS(339), 1,
      anon_sym_and,
    ACTIONS(351), 1,
      anon_sym_RPAREN,
    STATE(66), 1,
      sym_comment,
    STATE(146), 1,
      aux_sym_print_statement_repeat1,
    ACTIONS(266), 2,
      anon_sym_meet,
      anon_sym_cat,
    ACTIONS(298), 2,
      anon_sym_or,
      anon_sym_xor,
    ACTIONS(337), 2,
      anon_sym_DASH,
      anon_sym_PLUS,
    ACTIONS(264), 3,
      anon_sym_STAR,
      anon_sym_div,
      anon_sym_mod,
    ACTIONS(286), 8,
      anon_sym_gt,
      anon_sym_ge,
      anon_sym_lt,
      anon_sym_le,
      anon_sym_eq,
      anon_sym_ne,
      anon_sym_cmpeq,
      anon_sym_cmpne,
  [5837] = 18,
    ACTIONS(3), 1,
      anon_sym_SLASH_SLASH,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(256), 1,
      anon_sym_SLASH,
    ACTIONS(262), 1,
      anon_sym_CARET,
    ACTIONS(280), 1,
      anon_sym_join,
    ACTIONS(282), 1,
      anon_sym_diff,
    ACTIONS(284), 1,
      anon_sym_sdiff,
    ACTIONS(302), 1,
      anon_sym_CARET_CARET,
    ACTIONS(335), 1,
      anon_sym_COMMA,
    ACTIONS(339), 1,
      anon_sym_and,
    ACTIONS(353), 1,
      anon_sym_RPAREN,
    STATE(67), 1,
      sym_comment,
    STATE(152), 1,
      aux_sym_print_statement_repeat1,
    ACTIONS(266), 2,
      anon_sym_meet,
      anon_sym_cat,
    ACTIONS(298), 2,
      anon_sym_or,
      anon_sym_xor,
    ACTIONS(337), 2,
      anon_sym_DASH,
      anon_sym_PLUS,
    ACTIONS(264), 3,
      anon_sym_STAR,
      anon_sym_div,
      anon_sym_mod,
    ACTIONS(286), 8,
      anon_sym_gt,
      anon_sym_ge,
      anon_sym_lt,
      anon_sym_le,
      anon_sym_eq,
      anon_sym_ne,
      anon_sym_cmpeq,
      anon_sym_cmpne,
  [5904] = 5,
    ACTIONS(3), 1,
      anon_sym_SLASH_SLASH,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    STATE(68), 1,
      sym_comment,
    ACTIONS(357), 7,
      anon_sym_DASH,
      anon_sym_TILDE,
      anon_sym_LPAREN,
      anon_sym_endif,
      sym_for_statement,
      sym_string,
      sym_real,
    ACTIONS(355), 20,
      anon_sym_return,
      anon_sym_break,
      anon_sym_continue,
      anon_sym_eval,
      anon_sym_print,
      anon_sym_not,
      anon_sym_else,
      sym_true,
      sym_false,
      anon_sym_function,
      anon_sym_procedure,
      anon_sym_intrinsic,
      anon_sym__,
      anon_sym_if,
      anon_sym_elif,
      anon_sym_while,
      anon_sym_repeat,
      anon_sym_case,
      sym_identifier,
      sym_integer,
  [5945] = 18,
    ACTIONS(3), 1,
      anon_sym_SLASH_SLASH,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(256), 1,
      anon_sym_SLASH,
    ACTIONS(262), 1,
      anon_sym_CARET,
    ACTIONS(280), 1,
      anon_sym_join,
    ACTIONS(282), 1,
      anon_sym_diff,
    ACTIONS(284), 1,
      anon_sym_sdiff,
    ACTIONS(302), 1,
      anon_sym_CARET_CARET,
    ACTIONS(335), 1,
      anon_sym_COMMA,
    ACTIONS(339), 1,
      anon_sym_and,
    ACTIONS(359), 1,
      anon_sym_SEMI,
    STATE(69), 1,
      sym_comment,
    STATE(155), 1,
      aux_sym_print_statement_repeat1,
    ACTIONS(266), 2,
      anon_sym_meet,
      anon_sym_cat,
    ACTIONS(298), 2,
      anon_sym_or,
      anon_sym_xor,
    ACTIONS(337), 2,
      anon_sym_DASH,
      anon_sym_PLUS,
    ACTIONS(264), 3,
      anon_sym_STAR,
      anon_sym_div,
      anon_sym_mod,
    ACTIONS(286), 8,
      anon_sym_gt,
      anon_sym_ge,
      anon_sym_lt,
      anon_sym_le,
      anon_sym_eq,
      anon_sym_ne,
      anon_sym_cmpeq,
      anon_sym_cmpne,
  [6012] = 5,
    ACTIONS(3), 1,
      anon_sym_SLASH_SLASH,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    STATE(70), 1,
      sym_comment,
    ACTIONS(347), 7,
      anon_sym_DASH,
      anon_sym_TILDE,
      anon_sym_LPAREN,
      sym_for_statement,
      anon_sym_endcase,
      sym_string,
      sym_real,
    ACTIONS(345), 19,
      anon_sym_return,
      anon_sym_break,
      anon_sym_continue,
      anon_sym_eval,
      anon_sym_print,
      anon_sym_not,
      sym_true,
      sym_false,
      anon_sym_function,
      anon_sym_procedure,
      anon_sym_intrinsic,
      anon_sym__,
      anon_sym_if,
      anon_sym_while,
      anon_sym_repeat,
      anon_sym_case,
      anon_sym_when,
      sym_identifier,
      sym_integer,
  [6052] = 5,
    ACTIONS(3), 1,
      anon_sym_SLASH_SLASH,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    STATE(71), 1,
      sym_comment,
    ACTIONS(357), 7,
      anon_sym_DASH,
      anon_sym_TILDE,
      anon_sym_LPAREN,
      sym_for_statement,
      anon_sym_endcase,
      sym_string,
      sym_real,
    ACTIONS(355), 19,
      anon_sym_return,
      anon_sym_break,
      anon_sym_continue,
      anon_sym_eval,
      anon_sym_print,
      anon_sym_not,
      sym_true,
      sym_false,
      anon_sym_function,
      anon_sym_procedure,
      anon_sym_intrinsic,
      anon_sym__,
      anon_sym_if,
      anon_sym_while,
      anon_sym_repeat,
      anon_sym_case,
      anon_sym_when,
      sym_identifier,
      sym_integer,
  [6092] = 16,
    ACTIONS(3), 1,
      anon_sym_SLASH_SLASH,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(256), 1,
      anon_sym_SLASH,
    ACTIONS(262), 1,
      anon_sym_CARET,
    ACTIONS(280), 1,
      anon_sym_join,
    ACTIONS(282), 1,
      anon_sym_diff,
    ACTIONS(284), 1,
      anon_sym_sdiff,
    ACTIONS(302), 1,
      anon_sym_CARET_CARET,
    ACTIONS(339), 1,
      anon_sym_and,
    ACTIONS(361), 1,
      anon_sym_SEMI,
    STATE(72), 1,
      sym_comment,
    ACTIONS(266), 2,
      anon_sym_meet,
      anon_sym_cat,
    ACTIONS(298), 2,
      anon_sym_or,
      anon_sym_xor,
    ACTIONS(337), 2,
      anon_sym_DASH,
      anon_sym_PLUS,
    ACTIONS(264), 3,
      anon_sym_STAR,
      anon_sym_div,
      anon_sym_mod,
    ACTIONS(286), 8,
      anon_sym_gt,
      anon_sym_ge,
      anon_sym_lt,
      anon_sym_le,
      anon_sym_eq,
      anon_sym_ne,
      anon_sym_cmpeq,
      anon_sym_cmpne,
  [6153] = 5,
    ACTIONS(3), 1,
      anon_sym_SLASH_SLASH,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    STATE(73), 1,
      sym_comment,
    ACTIONS(357), 7,
      anon_sym_DASH,
      anon_sym_TILDE,
      anon_sym_LPAREN,
      anon_sym_endintrinsic,
      sym_for_statement,
      sym_string,
      sym_real,
    ACTIONS(355), 18,
      anon_sym_return,
      anon_sym_break,
      anon_sym_continue,
      anon_sym_eval,
      anon_sym_print,
      anon_sym_not,
      sym_true,
      sym_false,
      anon_sym_function,
      anon_sym_procedure,
      anon_sym_intrinsic,
      anon_sym__,
      anon_sym_if,
      anon_sym_while,
      anon_sym_repeat,
      anon_sym_case,
      sym_identifier,
      sym_integer,
  [6192] = 16,
    ACTIONS(3), 1,
      anon_sym_SLASH_SLASH,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(256), 1,
      anon_sym_SLASH,
    ACTIONS(262), 1,
      anon_sym_CARET,
    ACTIONS(280), 1,
      anon_sym_join,
    ACTIONS(282), 1,
      anon_sym_diff,
    ACTIONS(284), 1,
      anon_sym_sdiff,
    ACTIONS(302), 1,
      anon_sym_CARET_CARET,
    ACTIONS(339), 1,
      anon_sym_and,
    ACTIONS(363), 1,
      anon_sym_else,
    STATE(74), 1,
      sym_comment,
    ACTIONS(266), 2,
      anon_sym_meet,
      anon_sym_cat,
    ACTIONS(298), 2,
      anon_sym_or,
      anon_sym_xor,
    ACTIONS(337), 2,
      anon_sym_DASH,
      anon_sym_PLUS,
    ACTIONS(264), 3,
      anon_sym_STAR,
      anon_sym_div,
      anon_sym_mod,
    ACTIONS(286), 8,
      anon_sym_gt,
      anon_sym_ge,
      anon_sym_lt,
      anon_sym_le,
      anon_sym_eq,
      anon_sym_ne,
      anon_sym_cmpeq,
      anon_sym_cmpne,
  [6253] = 5,
    ACTIONS(3), 1,
      anon_sym_SLASH_SLASH,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    STATE(75), 1,
      sym_comment,
    ACTIONS(357), 7,
      anon_sym_DASH,
      anon_sym_TILDE,
      anon_sym_LPAREN,
      anon_sym_endif,
      sym_for_statement,
      sym_string,
      sym_real,
    ACTIONS(355), 18,
      anon_sym_return,
      anon_sym_break,
      anon_sym_continue,
      anon_sym_eval,
      anon_sym_print,
      anon_sym_not,
      sym_true,
      sym_false,
      anon_sym_function,
      anon_sym_procedure,
      anon_sym_intrinsic,
      anon_sym__,
      anon_sym_if,
      anon_sym_while,
      anon_sym_repeat,
      anon_sym_case,
      sym_identifier,
      sym_integer,
  [6292] = 5,
    ACTIONS(3), 1,
      anon_sym_SLASH_SLASH,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    STATE(76), 1,
      sym_comment,
    ACTIONS(347), 7,
      anon_sym_DASH,
      anon_sym_TILDE,
      anon_sym_LPAREN,
      anon_sym_endif,
      sym_for_statement,
      sym_string,
      sym_real,
    ACTIONS(345), 18,
      anon_sym_return,
      anon_sym_break,
      anon_sym_continue,
      anon_sym_eval,
      anon_sym_print,
      anon_sym_not,
      sym_true,
      sym_false,
      anon_sym_function,
      anon_sym_procedure,
      anon_sym_intrinsic,
      anon_sym__,
      anon_sym_if,
      anon_sym_while,
      anon_sym_repeat,
      anon_sym_case,
      sym_identifier,
      sym_integer,
  [6331] = 16,
    ACTIONS(3), 1,
      anon_sym_SLASH_SLASH,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(256), 1,
      anon_sym_SLASH,
    ACTIONS(262), 1,
      anon_sym_CARET,
    ACTIONS(280), 1,
      anon_sym_join,
    ACTIONS(282), 1,
      anon_sym_diff,
    ACTIONS(284), 1,
      anon_sym_sdiff,
    ACTIONS(302), 1,
      anon_sym_CARET_CARET,
    ACTIONS(339), 1,
      anon_sym_and,
    ACTIONS(365), 1,
      anon_sym_then,
    STATE(77), 1,
      sym_comment,
    ACTIONS(266), 2,
      anon_sym_meet,
      anon_sym_cat,
    ACTIONS(298), 2,
      anon_sym_or,
      anon_sym_xor,
    ACTIONS(337), 2,
      anon_sym_DASH,
      anon_sym_PLUS,
    ACTIONS(264), 3,
      anon_sym_STAR,
      anon_sym_div,
      anon_sym_mod,
    ACTIONS(286), 8,
      anon_sym_gt,
      anon_sym_ge,
      anon_sym_lt,
      anon_sym_le,
      anon_sym_eq,
      anon_sym_ne,
      anon_sym_cmpeq,
      anon_sym_cmpne,
  [6392] = 5,
    ACTIONS(3), 1,
      anon_sym_SLASH_SLASH,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    STATE(78), 1,
      sym_comment,
    ACTIONS(357), 7,
      ts_builtin_sym_end,
      anon_sym_DASH,
      anon_sym_TILDE,
      anon_sym_LPAREN,
      sym_for_statement,
      sym_string,
      sym_real,
    ACTIONS(355), 18,
      anon_sym_return,
      anon_sym_break,
      anon_sym_continue,
      anon_sym_eval,
      anon_sym_print,
      anon_sym_not,
      sym_true,
      sym_false,
      anon_sym_function,
      anon_sym_procedure,
      anon_sym_intrinsic,
      anon_sym__,
      anon_sym_if,
      anon_sym_while,
      anon_sym_repeat,
      anon_sym_case,
      sym_identifier,
      sym_integer,
  [6431] = 16,
    ACTIONS(3), 1,
      anon_sym_SLASH_SLASH,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(256), 1,
      anon_sym_SLASH,
    ACTIONS(262), 1,
      anon_sym_CARET,
    ACTIONS(280), 1,
      anon_sym_join,
    ACTIONS(282), 1,
      anon_sym_diff,
    ACTIONS(284), 1,
      anon_sym_sdiff,
    ACTIONS(302), 1,
      anon_sym_CARET_CARET,
    ACTIONS(339), 1,
      anon_sym_and,
    ACTIONS(367), 1,
      anon_sym_do,
    STATE(79), 1,
      sym_comment,
    ACTIONS(266), 2,
      anon_sym_meet,
      anon_sym_cat,
    ACTIONS(298), 2,
      anon_sym_or,
      anon_sym_xor,
    ACTIONS(337), 2,
      anon_sym_DASH,
      anon_sym_PLUS,
    ACTIONS(264), 3,
      anon_sym_STAR,
      anon_sym_div,
      anon_sym_mod,
    ACTIONS(286), 8,
      anon_sym_gt,
      anon_sym_ge,
      anon_sym_lt,
      anon_sym_le,
      anon_sym_eq,
      anon_sym_ne,
      anon_sym_cmpeq,
      anon_sym_cmpne,
  [6492] = 5,
    ACTIONS(3), 1,
      anon_sym_SLASH_SLASH,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    STATE(80), 1,
      sym_comment,
    ACTIONS(347), 6,
      anon_sym_DASH,
      anon_sym_TILDE,
      anon_sym_LPAREN,
      sym_for_statement,
      sym_string,
      sym_real,
    ACTIONS(345), 19,
      anon_sym_return,
      anon_sym_break,
      anon_sym_continue,
      anon_sym_eval,
      anon_sym_print,
      anon_sym_not,
      sym_true,
      sym_false,
      anon_sym_function,
      anon_sym_procedure,
      anon_sym_intrinsic,
      anon_sym__,
      anon_sym_if,
      anon_sym_while,
      anon_sym_repeat,
      anon_sym_until,
      anon_sym_case,
      sym_identifier,
      sym_integer,
  [6531] = 5,
    ACTIONS(3), 1,
      anon_sym_SLASH_SLASH,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    STATE(81), 1,
      sym_comment,
    ACTIONS(357), 7,
      anon_sym_DASH,
      anon_sym_TILDE,
      anon_sym_LPAREN,
      sym_for_statement,
      anon_sym_endwhile,
      sym_string,
      sym_real,
    ACTIONS(355), 18,
      anon_sym_return,
      anon_sym_break,
      anon_sym_continue,
      anon_sym_eval,
      anon_sym_print,
      anon_sym_not,
      sym_true,
      sym_false,
      anon_sym_function,
      anon_sym_procedure,
      anon_sym_intrinsic,
      anon_sym__,
      anon_sym_if,
      anon_sym_while,
      anon_sym_repeat,
      anon_sym_case,
      sym_identifier,
      sym_integer,
  [6570] = 16,
    ACTIONS(3), 1,
      anon_sym_SLASH_SLASH,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(256), 1,
      anon_sym_SLASH,
    ACTIONS(262), 1,
      anon_sym_CARET,
    ACTIONS(280), 1,
      anon_sym_join,
    ACTIONS(282), 1,
      anon_sym_diff,
    ACTIONS(284), 1,
      anon_sym_sdiff,
    ACTIONS(302), 1,
      anon_sym_CARET_CARET,
    ACTIONS(339), 1,
      anon_sym_and,
    ACTIONS(369), 1,
      anon_sym_then,
    STATE(82), 1,
      sym_comment,
    ACTIONS(266), 2,
      anon_sym_meet,
      anon_sym_cat,
    ACTIONS(298), 2,
      anon_sym_or,
      anon_sym_xor,
    ACTIONS(337), 2,
      anon_sym_DASH,
      anon_sym_PLUS,
    ACTIONS(264), 3,
      anon_sym_STAR,
      anon_sym_div,
      anon_sym_mod,
    ACTIONS(286), 8,
      anon_sym_gt,
      anon_sym_ge,
      anon_sym_lt,
      anon_sym_le,
      anon_sym_eq,
      anon_sym_ne,
      anon_sym_cmpeq,
      anon_sym_cmpne,
  [6631] = 5,
    ACTIONS(3), 1,
      anon_sym_SLASH_SLASH,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    STATE(83), 1,
      sym_comment,
    ACTIONS(347), 7,
      anon_sym_DASH,
      anon_sym_TILDE,
      anon_sym_LPAREN,
      sym_for_statement,
      anon_sym_endwhile,
      sym_string,
      sym_real,
    ACTIONS(345), 18,
      anon_sym_return,
      anon_sym_break,
      anon_sym_continue,
      anon_sym_eval,
      anon_sym_print,
      anon_sym_not,
      sym_true,
      sym_false,
      anon_sym_function,
      anon_sym_procedure,
      anon_sym_intrinsic,
      anon_sym__,
      anon_sym_if,
      anon_sym_while,
      anon_sym_repeat,
      anon_sym_case,
      sym_identifier,
      sym_integer,
  [6670] = 5,
    ACTIONS(3), 1,
      anon_sym_SLASH_SLASH,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    STATE(84), 1,
      sym_comment,
    ACTIONS(357), 6,
      anon_sym_DASH,
      anon_sym_TILDE,
      anon_sym_LPAREN,
      sym_for_statement,
      sym_string,
      sym_real,
    ACTIONS(355), 19,
      anon_sym_return,
      anon_sym_break,
      anon_sym_continue,
      anon_sym_eval,
      anon_sym_print,
      anon_sym_not,
      sym_true,
      sym_false,
      anon_sym_function,
      anon_sym_procedure,
      anon_sym_intrinsic,
      anon_sym__,
      anon_sym_if,
      anon_sym_while,
      anon_sym_repeat,
      anon_sym_until,
      anon_sym_case,
      sym_identifier,
      sym_integer,
  [6709] = 5,
    ACTIONS(3), 1,
      anon_sym_SLASH_SLASH,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    STATE(85), 1,
      sym_comment,
    ACTIONS(347), 7,
      anon_sym_DASH,
      anon_sym_TILDE,
      anon_sym_LPAREN,
      anon_sym_endfunction,
      sym_for_statement,
      sym_string,
      sym_real,
    ACTIONS(345), 18,
      anon_sym_return,
      anon_sym_break,
      anon_sym_continue,
      anon_sym_eval,
      anon_sym_print,
      anon_sym_not,
      sym_true,
      sym_false,
      anon_sym_function,
      anon_sym_procedure,
      anon_sym_intrinsic,
      anon_sym__,
      anon_sym_if,
      anon_sym_while,
      anon_sym_repeat,
      anon_sym_case,
      sym_identifier,
      sym_integer,
  [6748] = 5,
    ACTIONS(3), 1,
      anon_sym_SLASH_SLASH,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    STATE(86), 1,
      sym_comment,
    ACTIONS(371), 7,
      ts_builtin_sym_end,
      anon_sym_DASH,
      anon_sym_TILDE,
      anon_sym_LPAREN,
      sym_for_statement,
      sym_string,
      sym_real,
    ACTIONS(373), 18,
      anon_sym_return,
      anon_sym_break,
      anon_sym_continue,
      anon_sym_eval,
      anon_sym_print,
      anon_sym_not,
      sym_true,
      sym_false,
      anon_sym_function,
      anon_sym_procedure,
      anon_sym_intrinsic,
      anon_sym__,
      anon_sym_if,
      anon_sym_while,
      anon_sym_repeat,
      anon_sym_case,
      sym_identifier,
      sym_integer,
  [6787] = 16,
    ACTIONS(3), 1,
      anon_sym_SLASH_SLASH,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(256), 1,
      anon_sym_SLASH,
    ACTIONS(262), 1,
      anon_sym_CARET,
    ACTIONS(280), 1,
      anon_sym_join,
    ACTIONS(282), 1,
      anon_sym_diff,
    ACTIONS(284), 1,
      anon_sym_sdiff,
    ACTIONS(302), 1,
      anon_sym_CARET_CARET,
    ACTIONS(339), 1,
      anon_sym_and,
    ACTIONS(375), 1,
      anon_sym_RPAREN,
    STATE(87), 1,
      sym_comment,
    ACTIONS(266), 2,
      anon_sym_meet,
      anon_sym_cat,
    ACTIONS(298), 2,
      anon_sym_or,
      anon_sym_xor,
    ACTIONS(337), 2,
      anon_sym_DASH,
      anon_sym_PLUS,
    ACTIONS(264), 3,
      anon_sym_STAR,
      anon_sym_div,
      anon_sym_mod,
    ACTIONS(286), 8,
      anon_sym_gt,
      anon_sym_ge,
      anon_sym_lt,
      anon_sym_le,
      anon_sym_eq,
      anon_sym_ne,
      anon_sym_cmpeq,
      anon_sym_cmpne,
  [6848] = 5,
    ACTIONS(3), 1,
      anon_sym_SLASH_SLASH,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    STATE(88), 1,
      sym_comment,
    ACTIONS(357), 7,
      anon_sym_DASH,
      anon_sym_TILDE,
      anon_sym_LPAREN,
      anon_sym_endprocedure,
      sym_for_statement,
      sym_string,
      sym_real,
    ACTIONS(355), 18,
      anon_sym_return,
      anon_sym_break,
      anon_sym_continue,
      anon_sym_eval,
      anon_sym_print,
      anon_sym_not,
      sym_true,
      sym_false,
      anon_sym_function,
      anon_sym_procedure,
      anon_sym_intrinsic,
      anon_sym__,
      anon_sym_if,
      anon_sym_while,
      anon_sym_repeat,
      anon_sym_case,
      sym_identifier,
      sym_integer,
  [6887] = 16,
    ACTIONS(3), 1,
      anon_sym_SLASH_SLASH,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(256), 1,
      anon_sym_SLASH,
    ACTIONS(262), 1,
      anon_sym_CARET,
    ACTIONS(280), 1,
      anon_sym_join,
    ACTIONS(282), 1,
      anon_sym_diff,
    ACTIONS(284), 1,
      anon_sym_sdiff,
    ACTIONS(302), 1,
      anon_sym_CARET_CARET,
    ACTIONS(339), 1,
      anon_sym_and,
    ACTIONS(377), 1,
      anon_sym_SEMI,
    STATE(89), 1,
      sym_comment,
    ACTIONS(266), 2,
      anon_sym_meet,
      anon_sym_cat,
    ACTIONS(298), 2,
      anon_sym_or,
      anon_sym_xor,
    ACTIONS(337), 2,
      anon_sym_DASH,
      anon_sym_PLUS,
    ACTIONS(264), 3,
      anon_sym_STAR,
      anon_sym_div,
      anon_sym_mod,
    ACTIONS(286), 8,
      anon_sym_gt,
      anon_sym_ge,
      anon_sym_lt,
      anon_sym_le,
      anon_sym_eq,
      anon_sym_ne,
      anon_sym_cmpeq,
      anon_sym_cmpne,
  [6948] = 5,
    ACTIONS(3), 1,
      anon_sym_SLASH_SLASH,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    STATE(90), 1,
      sym_comment,
    ACTIONS(246), 7,
      anon_sym_DASH,
      anon_sym_TILDE,
      anon_sym_LPAREN,
      anon_sym_endprocedure,
      sym_for_statement,
      sym_string,
      sym_real,
    ACTIONS(244), 18,
      anon_sym_return,
      anon_sym_break,
      anon_sym_continue,
      anon_sym_eval,
      anon_sym_print,
      anon_sym_not,
      sym_true,
      sym_false,
      anon_sym_function,
      anon_sym_procedure,
      anon_sym_intrinsic,
      anon_sym__,
      anon_sym_if,
      anon_sym_while,
      anon_sym_repeat,
      anon_sym_case,
      sym_identifier,
      sym_integer,
  [6987] = 5,
    ACTIONS(3), 1,
      anon_sym_SLASH_SLASH,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    STATE(91), 1,
      sym_comment,
    ACTIONS(357), 7,
      anon_sym_DASH,
      anon_sym_TILDE,
      anon_sym_LPAREN,
      anon_sym_endfunction,
      sym_for_statement,
      sym_string,
      sym_real,
    ACTIONS(355), 18,
      anon_sym_return,
      anon_sym_break,
      anon_sym_continue,
      anon_sym_eval,
      anon_sym_print,
      anon_sym_not,
      sym_true,
      sym_false,
      anon_sym_function,
      anon_sym_procedure,
      anon_sym_intrinsic,
      anon_sym__,
      anon_sym_if,
      anon_sym_while,
      anon_sym_repeat,
      anon_sym_case,
      sym_identifier,
      sym_integer,
  [7026] = 5,
    ACTIONS(3), 1,
      anon_sym_SLASH_SLASH,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    STATE(92), 1,
      sym_comment,
    ACTIONS(347), 7,
      anon_sym_DASH,
      anon_sym_TILDE,
      anon_sym_LPAREN,
      anon_sym_endprocedure,
      sym_for_statement,
      sym_string,
      sym_real,
    ACTIONS(345), 18,
      anon_sym_return,
      anon_sym_break,
      anon_sym_continue,
      anon_sym_eval,
      anon_sym_print,
      anon_sym_not,
      sym_true,
      sym_false,
      anon_sym_function,
      anon_sym_procedure,
      anon_sym_intrinsic,
      anon_sym__,
      anon_sym_if,
      anon_sym_while,
      anon_sym_repeat,
      anon_sym_case,
      sym_identifier,
      sym_integer,
  [7065] = 5,
    ACTIONS(3), 1,
      anon_sym_SLASH_SLASH,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    STATE(93), 1,
      sym_comment,
    ACTIONS(347), 7,
      anon_sym_DASH,
      anon_sym_TILDE,
      anon_sym_LPAREN,
      anon_sym_endintrinsic,
      sym_for_statement,
      sym_string,
      sym_real,
    ACTIONS(345), 18,
      anon_sym_return,
      anon_sym_break,
      anon_sym_continue,
      anon_sym_eval,
      anon_sym_print,
      anon_sym_not,
      sym_true,
      sym_false,
      anon_sym_function,
      anon_sym_procedure,
      anon_sym_intrinsic,
      anon_sym__,
      anon_sym_if,
      anon_sym_while,
      anon_sym_repeat,
      anon_sym_case,
      sym_identifier,
      sym_integer,
  [7104] = 5,
    ACTIONS(3), 1,
      anon_sym_SLASH_SLASH,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    STATE(94), 1,
      sym_comment,
    ACTIONS(250), 7,
      anon_sym_DASH,
      anon_sym_TILDE,
      anon_sym_LPAREN,
      anon_sym_endprocedure,
      sym_for_statement,
      sym_string,
      sym_real,
    ACTIONS(248), 18,
      anon_sym_return,
      anon_sym_break,
      anon_sym_continue,
      anon_sym_eval,
      anon_sym_print,
      anon_sym_not,
      sym_true,
      sym_false,
      anon_sym_function,
      anon_sym_procedure,
      anon_sym_intrinsic,
      anon_sym__,
      anon_sym_if,
      anon_sym_while,
      anon_sym_repeat,
      anon_sym_case,
      sym_identifier,
      sym_integer,
  [7143] = 5,
    ACTIONS(3), 1,
      anon_sym_SLASH_SLASH,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    STATE(95), 1,
      sym_comment,
    ACTIONS(234), 7,
      anon_sym_DASH,
      anon_sym_TILDE,
      anon_sym_LPAREN,
      anon_sym_endprocedure,
      sym_for_statement,
      sym_string,
      sym_real,
    ACTIONS(232), 18,
      anon_sym_return,
      anon_sym_break,
      anon_sym_continue,
      anon_sym_eval,
      anon_sym_print,
      anon_sym_not,
      sym_true,
      sym_false,
      anon_sym_function,
      anon_sym_procedure,
      anon_sym_intrinsic,
      anon_sym__,
      anon_sym_if,
      anon_sym_while,
      anon_sym_repeat,
      anon_sym_case,
      sym_identifier,
      sym_integer,
  [7182] = 5,
    ACTIONS(3), 1,
      anon_sym_SLASH_SLASH,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    STATE(96), 1,
      sym_comment,
    ACTIONS(246), 6,
      anon_sym_DASH,
      anon_sym_TILDE,
      anon_sym_LPAREN,
      sym_for_statement,
      sym_string,
      sym_real,
    ACTIONS(244), 18,
      anon_sym_return,
      anon_sym_break,
      anon_sym_continue,
      anon_sym_eval,
      anon_sym_print,
      anon_sym_not,
      sym_true,
      sym_false,
      anon_sym_function,
      anon_sym_procedure,
      anon_sym_intrinsic,
      anon_sym__,
      anon_sym_if,
      anon_sym_while,
      anon_sym_repeat,
      anon_sym_case,
      sym_identifier,
      sym_integer,
  [7220] = 5,
    ACTIONS(3), 1,
      anon_sym_SLASH_SLASH,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    STATE(97), 1,
      sym_comment,
    ACTIONS(234), 6,
      anon_sym_DASH,
      anon_sym_TILDE,
      anon_sym_LPAREN,
      sym_for_statement,
      sym_string,
      sym_real,
    ACTIONS(232), 18,
      anon_sym_return,
      anon_sym_break,
      anon_sym_continue,
      anon_sym_eval,
      anon_sym_print,
      anon_sym_not,
      sym_true,
      sym_false,
      anon_sym_function,
      anon_sym_procedure,
      anon_sym_intrinsic,
      anon_sym__,
      anon_sym_if,
      anon_sym_while,
      anon_sym_repeat,
      anon_sym_case,
      sym_identifier,
      sym_integer,
  [7258] = 5,
    ACTIONS(3), 1,
      anon_sym_SLASH_SLASH,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    STATE(98), 1,
      sym_comment,
    ACTIONS(250), 6,
      anon_sym_DASH,
      anon_sym_TILDE,
      anon_sym_LPAREN,
      sym_for_statement,
      sym_string,
      sym_real,
    ACTIONS(248), 18,
      anon_sym_return,
      anon_sym_break,
      anon_sym_continue,
      anon_sym_eval,
      anon_sym_print,
      anon_sym_not,
      sym_true,
      sym_false,
      anon_sym_function,
      anon_sym_procedure,
      anon_sym_intrinsic,
      anon_sym__,
      anon_sym_if,
      anon_sym_while,
      anon_sym_repeat,
      anon_sym_case,
      sym_identifier,
      sym_integer,
  [7296] = 15,
    ACTIONS(3), 1,
      anon_sym_SLASH_SLASH,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(256), 1,
      anon_sym_SLASH,
    ACTIONS(262), 1,
      anon_sym_CARET,
    ACTIONS(280), 1,
      anon_sym_join,
    ACTIONS(282), 1,
      anon_sym_diff,
    ACTIONS(284), 1,
      anon_sym_sdiff,
    ACTIONS(302), 1,
      anon_sym_CARET_CARET,
    ACTIONS(339), 1,
      anon_sym_and,
    STATE(99), 1,
      sym_comment,
    ACTIONS(266), 2,
      anon_sym_meet,
      anon_sym_cat,
    ACTIONS(298), 2,
      anon_sym_or,
      anon_sym_xor,
    ACTIONS(337), 2,
      anon_sym_DASH,
      anon_sym_PLUS,
    ACTIONS(264), 3,
      anon_sym_STAR,
      anon_sym_div,
      anon_sym_mod,
    ACTIONS(286), 8,
      anon_sym_gt,
      anon_sym_ge,
      anon_sym_lt,
      anon_sym_le,
      anon_sym_eq,
      anon_sym_ne,
      anon_sym_cmpeq,
      anon_sym_cmpne,
  [7354] = 16,
    ACTIONS(3), 1,
      anon_sym_SLASH_SLASH,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(19), 1,
      anon_sym_not,
    ACTIONS(21), 1,
      anon_sym_DASH,
    ACTIONS(23), 1,
      anon_sym_TILDE,
    ACTIONS(25), 1,
      anon_sym_LPAREN,
    ACTIONS(47), 1,
      sym_identifier,
    ACTIONS(379), 1,
      anon_sym__,
    STATE(57), 1,
      sym_primary_expression,
    STATE(99), 1,
      sym_expression,
    STATE(100), 1,
      sym_comment,
    STATE(165), 1,
      sym_gen_expression,
    ACTIONS(49), 2,
      sym_string,
      sym_real,
    STATE(38), 2,
      sym_comparison_operator,
      sym_boolean_operator,
    ACTIONS(27), 3,
      sym_true,
      sym_false,
      sym_integer,
    STATE(36), 5,
      sym_unary_operator,
      sym_binary_operator,
      sym_ternary_operator,
      sym_parenthesized_expression,
      sym_call,
  [7411] = 16,
    ACTIONS(3), 1,
      anon_sym_SLASH_SLASH,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(19), 1,
      anon_sym_not,
    ACTIONS(21), 1,
      anon_sym_DASH,
    ACTIONS(23), 1,
      anon_sym_TILDE,
    ACTIONS(25), 1,
      anon_sym_LPAREN,
    ACTIONS(47), 1,
      sym_identifier,
    ACTIONS(379), 1,
      anon_sym__,
    STATE(55), 1,
      sym_primary_expression,
    STATE(99), 1,
      sym_expression,
    STATE(101), 1,
      sym_comment,
    STATE(165), 1,
      sym_gen_expression,
    ACTIONS(49), 2,
      sym_string,
      sym_real,
    STATE(38), 2,
      sym_comparison_operator,
      sym_boolean_operator,
    ACTIONS(27), 3,
      sym_true,
      sym_false,
      sym_integer,
    STATE(36), 5,
      sym_unary_operator,
      sym_binary_operator,
      sym_ternary_operator,
      sym_parenthesized_expression,
      sym_call,
  [7468] = 15,
    ACTIONS(3), 1,
      anon_sym_SLASH_SLASH,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(19), 1,
      anon_sym_not,
    ACTIONS(21), 1,
      anon_sym_DASH,
    ACTIONS(23), 1,
      anon_sym_TILDE,
    ACTIONS(25), 1,
      anon_sym_LPAREN,
    ACTIONS(381), 1,
      anon_sym_SEMI,
    STATE(56), 1,
      sym_primary_expression,
    STATE(99), 1,
      sym_expression,
    STATE(102), 1,
      sym_comment,
    STATE(215), 1,
      sym_expression_statement,
    ACTIONS(49), 2,
      sym_string,
      sym_real,
    STATE(38), 2,
      sym_comparison_operator,
      sym_boolean_operator,
    ACTIONS(27), 4,
      sym_true,
      sym_false,
      sym_identifier,
      sym_integer,
    STATE(36), 5,
      sym_unary_operator,
      sym_binary_operator,
      sym_ternary_operator,
      sym_parenthesized_expression,
      sym_call,
  [7523] = 14,
    ACTIONS(3), 1,
      anon_sym_SLASH_SLASH,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(19), 1,
      anon_sym_not,
    ACTIONS(21), 1,
      anon_sym_DASH,
    ACTIONS(23), 1,
      anon_sym_TILDE,
    ACTIONS(25), 1,
      anon_sym_LPAREN,
    ACTIONS(383), 1,
      anon_sym_RPAREN,
    STATE(31), 1,
      sym_primary_expression,
    STATE(67), 1,
      sym_expression,
    STATE(103), 1,
      sym_comment,
    ACTIONS(49), 2,
      sym_string,
      sym_real,
    STATE(38), 2,
      sym_comparison_operator,
      sym_boolean_operator,
    ACTIONS(27), 4,
      sym_true,
      sym_false,
      sym_identifier,
      sym_integer,
    STATE(36), 5,
      sym_unary_operator,
      sym_binary_operator,
      sym_ternary_operator,
      sym_parenthesized_expression,
      sym_call,
  [7575] = 14,
    ACTIONS(3), 1,
      anon_sym_SLASH_SLASH,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(19), 1,
      anon_sym_not,
    ACTIONS(21), 1,
      anon_sym_DASH,
    ACTIONS(23), 1,
      anon_sym_TILDE,
    ACTIONS(25), 1,
      anon_sym_LPAREN,
    ACTIONS(385), 1,
      anon_sym_RPAREN,
    STATE(31), 1,
      sym_primary_expression,
    STATE(62), 1,
      sym_expression,
    STATE(104), 1,
      sym_comment,
    ACTIONS(49), 2,
      sym_string,
      sym_real,
    STATE(38), 2,
      sym_comparison_operator,
      sym_boolean_operator,
    ACTIONS(27), 4,
      sym_true,
      sym_false,
      sym_identifier,
      sym_integer,
    STATE(36), 5,
      sym_unary_operator,
      sym_binary_operator,
      sym_ternary_operator,
      sym_parenthesized_expression,
      sym_call,
  [7627] = 14,
    ACTIONS(3), 1,
      anon_sym_SLASH_SLASH,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(19), 1,
      anon_sym_not,
    ACTIONS(21), 1,
      anon_sym_DASH,
    ACTIONS(23), 1,
      anon_sym_TILDE,
    ACTIONS(25), 1,
      anon_sym_LPAREN,
    ACTIONS(387), 1,
      anon_sym_RPAREN,
    STATE(31), 1,
      sym_primary_expression,
    STATE(66), 1,
      sym_expression,
    STATE(105), 1,
      sym_comment,
    ACTIONS(49), 2,
      sym_string,
      sym_real,
    STATE(38), 2,
      sym_comparison_operator,
      sym_boolean_operator,
    ACTIONS(27), 4,
      sym_true,
      sym_false,
      sym_identifier,
      sym_integer,
    STATE(36), 5,
      sym_unary_operator,
      sym_binary_operator,
      sym_ternary_operator,
      sym_parenthesized_expression,
      sym_call,
  [7679] = 14,
    ACTIONS(3), 1,
      anon_sym_SLASH_SLASH,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(19), 1,
      anon_sym_not,
    ACTIONS(21), 1,
      anon_sym_DASH,
    ACTIONS(23), 1,
      anon_sym_TILDE,
    ACTIONS(25), 1,
      anon_sym_LPAREN,
    STATE(31), 1,
      sym_primary_expression,
    STATE(65), 1,
      sym_expression,
    STATE(106), 1,
      sym_comment,
    STATE(206), 1,
      sym__right_hand_side,
    ACTIONS(49), 2,
      sym_string,
      sym_real,
    STATE(38), 2,
      sym_comparison_operator,
      sym_boolean_operator,
    ACTIONS(27), 4,
      sym_true,
      sym_false,
      sym_identifier,
      sym_integer,
    STATE(36), 5,
      sym_unary_operator,
      sym_binary_operator,
      sym_ternary_operator,
      sym_parenthesized_expression,
      sym_call,
  [7731] = 14,
    ACTIONS(3), 1,
      anon_sym_SLASH_SLASH,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(19), 1,
      anon_sym_not,
    ACTIONS(21), 1,
      anon_sym_DASH,
    ACTIONS(23), 1,
      anon_sym_TILDE,
    ACTIONS(25), 1,
      anon_sym_LPAREN,
    STATE(31), 1,
      sym_primary_expression,
    STATE(65), 1,
      sym_expression,
    STATE(107), 1,
      sym_comment,
    STATE(187), 1,
      sym__right_hand_side,
    ACTIONS(49), 2,
      sym_string,
      sym_real,
    STATE(38), 2,
      sym_comparison_operator,
      sym_boolean_operator,
    ACTIONS(27), 4,
      sym_true,
      sym_false,
      sym_identifier,
      sym_integer,
    STATE(36), 5,
      sym_unary_operator,
      sym_binary_operator,
      sym_ternary_operator,
      sym_parenthesized_expression,
      sym_call,
  [7783] = 13,
    ACTIONS(3), 1,
      anon_sym_SLASH_SLASH,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(19), 1,
      anon_sym_not,
    ACTIONS(21), 1,
      anon_sym_DASH,
    ACTIONS(23), 1,
      anon_sym_TILDE,
    ACTIONS(25), 1,
      anon_sym_LPAREN,
    STATE(31), 1,
      sym_primary_expression,
    STATE(46), 1,
      sym_expression,
    STATE(108), 1,
      sym_comment,
    ACTIONS(49), 2,
      sym_string,
      sym_real,
    STATE(38), 2,
      sym_comparison_operator,
      sym_boolean_operator,
    ACTIONS(27), 4,
      sym_true,
      sym_false,
      sym_identifier,
      sym_integer,
    STATE(36), 5,
      sym_unary_operator,
      sym_binary_operator,
      sym_ternary_operator,
      sym_parenthesized_expression,
      sym_call,
  [7832] = 13,
    ACTIONS(3), 1,
      anon_sym_SLASH_SLASH,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(19), 1,
      anon_sym_not,
    ACTIONS(21), 1,
      anon_sym_DASH,
    ACTIONS(23), 1,
      anon_sym_TILDE,
    ACTIONS(25), 1,
      anon_sym_LPAREN,
    STATE(60), 1,
      sym_primary_expression,
    STATE(99), 1,
      sym_expression,
    STATE(109), 1,
      sym_comment,
    ACTIONS(49), 2,
      sym_string,
      sym_real,
    STATE(38), 2,
      sym_comparison_operator,
      sym_boolean_operator,
    ACTIONS(27), 4,
      sym_true,
      sym_false,
      sym_identifier,
      sym_integer,
    STATE(36), 5,
      sym_unary_operator,
      sym_binary_operator,
      sym_ternary_operator,
      sym_parenthesized_expression,
      sym_call,
  [7881] = 13,
    ACTIONS(3), 1,
      anon_sym_SLASH_SLASH,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(19), 1,
      anon_sym_not,
    ACTIONS(21), 1,
      anon_sym_DASH,
    ACTIONS(23), 1,
      anon_sym_TILDE,
    ACTIONS(25), 1,
      anon_sym_LPAREN,
    STATE(31), 1,
      sym_primary_expression,
    STATE(87), 1,
      sym_expression,
    STATE(110), 1,
      sym_comment,
    ACTIONS(49), 2,
      sym_string,
      sym_real,
    STATE(38), 2,
      sym_comparison_operator,
      sym_boolean_operator,
    ACTIONS(27), 4,
      sym_true,
      sym_false,
      sym_identifier,
      sym_integer,
    STATE(36), 5,
      sym_unary_operator,
      sym_binary_operator,
      sym_ternary_operator,
      sym_parenthesized_expression,
      sym_call,
  [7930] = 13,
    ACTIONS(3), 1,
      anon_sym_SLASH_SLASH,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(19), 1,
      anon_sym_not,
    ACTIONS(21), 1,
      anon_sym_DASH,
    ACTIONS(23), 1,
      anon_sym_TILDE,
    ACTIONS(25), 1,
      anon_sym_LPAREN,
    STATE(31), 1,
      sym_primary_expression,
    STATE(89), 1,
      sym_expression,
    STATE(111), 1,
      sym_comment,
    ACTIONS(49), 2,
      sym_string,
      sym_real,
    STATE(38), 2,
      sym_comparison_operator,
      sym_boolean_operator,
    ACTIONS(27), 4,
      sym_true,
      sym_false,
      sym_identifier,
      sym_integer,
    STATE(36), 5,
      sym_unary_operator,
      sym_binary_operator,
      sym_ternary_operator,
      sym_parenthesized_expression,
      sym_call,
  [7979] = 13,
    ACTIONS(3), 1,
      anon_sym_SLASH_SLASH,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(19), 1,
      anon_sym_not,
    ACTIONS(21), 1,
      anon_sym_DASH,
    ACTIONS(23), 1,
      anon_sym_TILDE,
    ACTIONS(25), 1,
      anon_sym_LPAREN,
    STATE(31), 1,
      sym_primary_expression,
    STATE(45), 1,
      sym_expression,
    STATE(112), 1,
      sym_comment,
    ACTIONS(49), 2,
      sym_string,
      sym_real,
    STATE(38), 2,
      sym_comparison_operator,
      sym_boolean_operator,
    ACTIONS(27), 4,
      sym_true,
      sym_false,
      sym_identifier,
      sym_integer,
    STATE(36), 5,
      sym_unary_operator,
      sym_binary_operator,
      sym_ternary_operator,
      sym_parenthesized_expression,
      sym_call,
  [8028] = 13,
    ACTIONS(3), 1,
      anon_sym_SLASH_SLASH,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(19), 1,
      anon_sym_not,
    ACTIONS(21), 1,
      anon_sym_DASH,
    ACTIONS(23), 1,
      anon_sym_TILDE,
    ACTIONS(25), 1,
      anon_sym_LPAREN,
    STATE(31), 1,
      sym_primary_expression,
    STATE(43), 1,
      sym_expression,
    STATE(113), 1,
      sym_comment,
    ACTIONS(49), 2,
      sym_string,
      sym_real,
    STATE(38), 2,
      sym_comparison_operator,
      sym_boolean_operator,
    ACTIONS(27), 4,
      sym_true,
      sym_false,
      sym_identifier,
      sym_integer,
    STATE(36), 5,
      sym_unary_operator,
      sym_binary_operator,
      sym_ternary_operator,
      sym_parenthesized_expression,
      sym_call,
  [8077] = 13,
    ACTIONS(3), 1,
      anon_sym_SLASH_SLASH,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(19), 1,
      anon_sym_not,
    ACTIONS(21), 1,
      anon_sym_DASH,
    ACTIONS(23), 1,
      anon_sym_TILDE,
    ACTIONS(25), 1,
      anon_sym_LPAREN,
    STATE(31), 1,
      sym_primary_expression,
    STATE(42), 1,
      sym_expression,
    STATE(114), 1,
      sym_comment,
    ACTIONS(49), 2,
      sym_string,
      sym_real,
    STATE(38), 2,
      sym_comparison_operator,
      sym_boolean_operator,
    ACTIONS(27), 4,
      sym_true,
      sym_false,
      sym_identifier,
      sym_integer,
    STATE(36), 5,
      sym_unary_operator,
      sym_binary_operator,
      sym_ternary_operator,
      sym_parenthesized_expression,
      sym_call,
  [8126] = 13,
    ACTIONS(3), 1,
      anon_sym_SLASH_SLASH,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(19), 1,
      anon_sym_not,
    ACTIONS(21), 1,
      anon_sym_DASH,
    ACTIONS(23), 1,
      anon_sym_TILDE,
    ACTIONS(25), 1,
      anon_sym_LPAREN,
    STATE(31), 1,
      sym_primary_expression,
    STATE(44), 1,
      sym_expression,
    STATE(115), 1,
      sym_comment,
    ACTIONS(49), 2,
      sym_string,
      sym_real,
    STATE(38), 2,
      sym_comparison_operator,
      sym_boolean_operator,
    ACTIONS(27), 4,
      sym_true,
      sym_false,
      sym_identifier,
      sym_integer,
    STATE(36), 5,
      sym_unary_operator,
      sym_binary_operator,
      sym_ternary_operator,
      sym_parenthesized_expression,
      sym_call,
  [8175] = 13,
    ACTIONS(3), 1,
      anon_sym_SLASH_SLASH,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(19), 1,
      anon_sym_not,
    ACTIONS(21), 1,
      anon_sym_DASH,
    ACTIONS(23), 1,
      anon_sym_TILDE,
    ACTIONS(25), 1,
      anon_sym_LPAREN,
    STATE(31), 1,
      sym_primary_expression,
    STATE(77), 1,
      sym_expression,
    STATE(116), 1,
      sym_comment,
    ACTIONS(49), 2,
      sym_string,
      sym_real,
    STATE(38), 2,
      sym_comparison_operator,
      sym_boolean_operator,
    ACTIONS(27), 4,
      sym_true,
      sym_false,
      sym_identifier,
      sym_integer,
    STATE(36), 5,
      sym_unary_operator,
      sym_binary_operator,
      sym_ternary_operator,
      sym_parenthesized_expression,
      sym_call,
  [8224] = 13,
    ACTIONS(3), 1,
      anon_sym_SLASH_SLASH,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(19), 1,
      anon_sym_not,
    ACTIONS(21), 1,
      anon_sym_DASH,
    ACTIONS(23), 1,
      anon_sym_TILDE,
    ACTIONS(25), 1,
      anon_sym_LPAREN,
    STATE(31), 1,
      sym_primary_expression,
    STATE(69), 1,
      sym_expression,
    STATE(117), 1,
      sym_comment,
    ACTIONS(49), 2,
      sym_string,
      sym_real,
    STATE(38), 2,
      sym_comparison_operator,
      sym_boolean_operator,
    ACTIONS(27), 4,
      sym_true,
      sym_false,
      sym_identifier,
      sym_integer,
    STATE(36), 5,
      sym_unary_operator,
      sym_binary_operator,
      sym_ternary_operator,
      sym_parenthesized_expression,
      sym_call,
  [8273] = 13,
    ACTIONS(3), 1,
      anon_sym_SLASH_SLASH,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(19), 1,
      anon_sym_not,
    ACTIONS(21), 1,
      anon_sym_DASH,
    ACTIONS(23), 1,
      anon_sym_TILDE,
    ACTIONS(25), 1,
      anon_sym_LPAREN,
    STATE(31), 1,
      sym_primary_expression,
    STATE(40), 1,
      sym_expression,
    STATE(118), 1,
      sym_comment,
    ACTIONS(49), 2,
      sym_string,
      sym_real,
    STATE(38), 2,
      sym_comparison_operator,
      sym_boolean_operator,
    ACTIONS(27), 4,
      sym_true,
      sym_false,
      sym_identifier,
      sym_integer,
    STATE(36), 5,
      sym_unary_operator,
      sym_binary_operator,
      sym_ternary_operator,
      sym_parenthesized_expression,
      sym_call,
  [8322] = 13,
    ACTIONS(3), 1,
      anon_sym_SLASH_SLASH,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(19), 1,
      anon_sym_not,
    ACTIONS(21), 1,
      anon_sym_DASH,
    ACTIONS(23), 1,
      anon_sym_TILDE,
    ACTIONS(25), 1,
      anon_sym_LPAREN,
    STATE(59), 1,
      sym_primary_expression,
    STATE(99), 1,
      sym_expression,
    STATE(119), 1,
      sym_comment,
    ACTIONS(49), 2,
      sym_string,
      sym_real,
    STATE(38), 2,
      sym_comparison_operator,
      sym_boolean_operator,
    ACTIONS(27), 4,
      sym_true,
      sym_false,
      sym_identifier,
      sym_integer,
    STATE(36), 5,
      sym_unary_operator,
      sym_binary_operator,
      sym_ternary_operator,
      sym_parenthesized_expression,
      sym_call,
  [8371] = 13,
    ACTIONS(3), 1,
      anon_sym_SLASH_SLASH,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(19), 1,
      anon_sym_not,
    ACTIONS(21), 1,
      anon_sym_DASH,
    ACTIONS(23), 1,
      anon_sym_TILDE,
    ACTIONS(25), 1,
      anon_sym_LPAREN,
    STATE(31), 1,
      sym_primary_expression,
    STATE(63), 1,
      sym_expression,
    STATE(120), 1,
      sym_comment,
    ACTIONS(49), 2,
      sym_string,
      sym_real,
    STATE(38), 2,
      sym_comparison_operator,
      sym_boolean_operator,
    ACTIONS(27), 4,
      sym_true,
      sym_false,
      sym_identifier,
      sym_integer,
    STATE(36), 5,
      sym_unary_operator,
      sym_binary_operator,
      sym_ternary_operator,
      sym_parenthesized_expression,
      sym_call,
  [8420] = 13,
    ACTIONS(3), 1,
      anon_sym_SLASH_SLASH,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(19), 1,
      anon_sym_not,
    ACTIONS(21), 1,
      anon_sym_DASH,
    ACTIONS(23), 1,
      anon_sym_TILDE,
    ACTIONS(25), 1,
      anon_sym_LPAREN,
    STATE(58), 1,
      sym_primary_expression,
    STATE(99), 1,
      sym_expression,
    STATE(121), 1,
      sym_comment,
    ACTIONS(49), 2,
      sym_string,
      sym_real,
    STATE(38), 2,
      sym_comparison_operator,
      sym_boolean_operator,
    ACTIONS(27), 4,
      sym_true,
      sym_false,
      sym_identifier,
      sym_integer,
    STATE(36), 5,
      sym_unary_operator,
      sym_binary_operator,
      sym_ternary_operator,
      sym_parenthesized_expression,
      sym_call,
  [8469] = 13,
    ACTIONS(3), 1,
      anon_sym_SLASH_SLASH,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(19), 1,
      anon_sym_not,
    ACTIONS(21), 1,
      anon_sym_DASH,
    ACTIONS(23), 1,
      anon_sym_TILDE,
    ACTIONS(25), 1,
      anon_sym_LPAREN,
    STATE(31), 1,
      sym_primary_expression,
    STATE(47), 1,
      sym_expression,
    STATE(122), 1,
      sym_comment,
    ACTIONS(49), 2,
      sym_string,
      sym_real,
    STATE(38), 2,
      sym_comparison_operator,
      sym_boolean_operator,
    ACTIONS(27), 4,
      sym_true,
      sym_false,
      sym_identifier,
      sym_integer,
    STATE(36), 5,
      sym_unary_operator,
      sym_binary_operator,
      sym_ternary_operator,
      sym_parenthesized_expression,
      sym_call,
  [8518] = 13,
    ACTIONS(3), 1,
      anon_sym_SLASH_SLASH,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(19), 1,
      anon_sym_not,
    ACTIONS(21), 1,
      anon_sym_DASH,
    ACTIONS(23), 1,
      anon_sym_TILDE,
    ACTIONS(25), 1,
      anon_sym_LPAREN,
    STATE(31), 1,
      sym_primary_expression,
    STATE(72), 1,
      sym_expression,
    STATE(123), 1,
      sym_comment,
    ACTIONS(49), 2,
      sym_string,
      sym_real,
    STATE(38), 2,
      sym_comparison_operator,
      sym_boolean_operator,
    ACTIONS(27), 4,
      sym_true,
      sym_false,
      sym_identifier,
      sym_integer,
    STATE(36), 5,
      sym_unary_operator,
      sym_binary_operator,
      sym_ternary_operator,
      sym_parenthesized_expression,
      sym_call,
  [8567] = 13,
    ACTIONS(3), 1,
      anon_sym_SLASH_SLASH,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(19), 1,
      anon_sym_not,
    ACTIONS(21), 1,
      anon_sym_DASH,
    ACTIONS(23), 1,
      anon_sym_TILDE,
    ACTIONS(25), 1,
      anon_sym_LPAREN,
    STATE(31), 1,
      sym_primary_expression,
    STATE(79), 1,
      sym_expression,
    STATE(124), 1,
      sym_comment,
    ACTIONS(49), 2,
      sym_string,
      sym_real,
    STATE(38), 2,
      sym_comparison_operator,
      sym_boolean_operator,
    ACTIONS(27), 4,
      sym_true,
      sym_false,
      sym_identifier,
      sym_integer,
    STATE(36), 5,
      sym_unary_operator,
      sym_binary_operator,
      sym_ternary_operator,
      sym_parenthesized_expression,
      sym_call,
  [8616] = 13,
    ACTIONS(3), 1,
      anon_sym_SLASH_SLASH,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(19), 1,
      anon_sym_not,
    ACTIONS(21), 1,
      anon_sym_DASH,
    ACTIONS(23), 1,
      anon_sym_TILDE,
    ACTIONS(25), 1,
      anon_sym_LPAREN,
    STATE(31), 1,
      sym_primary_expression,
    STATE(82), 1,
      sym_expression,
    STATE(125), 1,
      sym_comment,
    ACTIONS(49), 2,
      sym_string,
      sym_real,
    STATE(38), 2,
      sym_comparison_operator,
      sym_boolean_operator,
    ACTIONS(27), 4,
      sym_true,
      sym_false,
      sym_identifier,
      sym_integer,
    STATE(36), 5,
      sym_unary_operator,
      sym_binary_operator,
      sym_ternary_operator,
      sym_parenthesized_expression,
      sym_call,
  [8665] = 13,
    ACTIONS(3), 1,
      anon_sym_SLASH_SLASH,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(19), 1,
      anon_sym_not,
    ACTIONS(21), 1,
      anon_sym_DASH,
    ACTIONS(23), 1,
      anon_sym_TILDE,
    ACTIONS(25), 1,
      anon_sym_LPAREN,
    STATE(31), 1,
      sym_primary_expression,
    STATE(74), 1,
      sym_expression,
    STATE(126), 1,
      sym_comment,
    ACTIONS(49), 2,
      sym_string,
      sym_real,
    STATE(38), 2,
      sym_comparison_operator,
      sym_boolean_operator,
    ACTIONS(27), 4,
      sym_true,
      sym_false,
      sym_identifier,
      sym_integer,
    STATE(36), 5,
      sym_unary_operator,
      sym_binary_operator,
      sym_ternary_operator,
      sym_parenthesized_expression,
      sym_call,
  [8714] = 13,
    ACTIONS(3), 1,
      anon_sym_SLASH_SLASH,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(19), 1,
      anon_sym_not,
    ACTIONS(21), 1,
      anon_sym_DASH,
    ACTIONS(23), 1,
      anon_sym_TILDE,
    ACTIONS(25), 1,
      anon_sym_LPAREN,
    STATE(31), 1,
      sym_primary_expression,
    STATE(50), 1,
      sym_expression,
    STATE(127), 1,
      sym_comment,
    ACTIONS(49), 2,
      sym_string,
      sym_real,
    STATE(38), 2,
      sym_comparison_operator,
      sym_boolean_operator,
    ACTIONS(27), 4,
      sym_true,
      sym_false,
      sym_identifier,
      sym_integer,
    STATE(36), 5,
      sym_unary_operator,
      sym_binary_operator,
      sym_ternary_operator,
      sym_parenthesized_expression,
      sym_call,
  [8763] = 13,
    ACTIONS(3), 1,
      anon_sym_SLASH_SLASH,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(19), 1,
      anon_sym_not,
    ACTIONS(21), 1,
      anon_sym_DASH,
    ACTIONS(23), 1,
      anon_sym_TILDE,
    ACTIONS(25), 1,
      anon_sym_LPAREN,
    STATE(31), 1,
      sym_primary_expression,
    STATE(49), 1,
      sym_expression,
    STATE(128), 1,
      sym_comment,
    ACTIONS(49), 2,
      sym_string,
      sym_real,
    STATE(38), 2,
      sym_comparison_operator,
      sym_boolean_operator,
    ACTIONS(27), 4,
      sym_true,
      sym_false,
      sym_identifier,
      sym_integer,
    STATE(36), 5,
      sym_unary_operator,
      sym_binary_operator,
      sym_ternary_operator,
      sym_parenthesized_expression,
      sym_call,
  [8812] = 13,
    ACTIONS(3), 1,
      anon_sym_SLASH_SLASH,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(19), 1,
      anon_sym_not,
    ACTIONS(21), 1,
      anon_sym_DASH,
    ACTIONS(23), 1,
      anon_sym_TILDE,
    ACTIONS(25), 1,
      anon_sym_LPAREN,
    STATE(31), 1,
      sym_primary_expression,
    STATE(39), 1,
      sym_expression,
    STATE(129), 1,
      sym_comment,
    ACTIONS(49), 2,
      sym_string,
      sym_real,
    STATE(38), 2,
      sym_comparison_operator,
      sym_boolean_operator,
    ACTIONS(27), 4,
      sym_true,
      sym_false,
      sym_identifier,
      sym_integer,
    STATE(36), 5,
      sym_unary_operator,
      sym_binary_operator,
      sym_ternary_operator,
      sym_parenthesized_expression,
      sym_call,
  [8861] = 13,
    ACTIONS(3), 1,
      anon_sym_SLASH_SLASH,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(19), 1,
      anon_sym_not,
    ACTIONS(21), 1,
      anon_sym_DASH,
    ACTIONS(23), 1,
      anon_sym_TILDE,
    ACTIONS(25), 1,
      anon_sym_LPAREN,
    STATE(31), 1,
      sym_primary_expression,
    STATE(52), 1,
      sym_expression,
    STATE(130), 1,
      sym_comment,
    ACTIONS(49), 2,
      sym_string,
      sym_real,
    STATE(38), 2,
      sym_comparison_operator,
      sym_boolean_operator,
    ACTIONS(27), 4,
      sym_true,
      sym_false,
      sym_identifier,
      sym_integer,
    STATE(36), 5,
      sym_unary_operator,
      sym_binary_operator,
      sym_ternary_operator,
      sym_parenthesized_expression,
      sym_call,
  [8910] = 13,
    ACTIONS(3), 1,
      anon_sym_SLASH_SLASH,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(19), 1,
      anon_sym_not,
    ACTIONS(21), 1,
      anon_sym_DASH,
    ACTIONS(23), 1,
      anon_sym_TILDE,
    ACTIONS(25), 1,
      anon_sym_LPAREN,
    STATE(61), 1,
      sym_primary_expression,
    STATE(99), 1,
      sym_expression,
    STATE(131), 1,
      sym_comment,
    ACTIONS(49), 2,
      sym_string,
      sym_real,
    STATE(38), 2,
      sym_comparison_operator,
      sym_boolean_operator,
    ACTIONS(27), 4,
      sym_true,
      sym_false,
      sym_identifier,
      sym_integer,
    STATE(36), 5,
      sym_unary_operator,
      sym_binary_operator,
      sym_ternary_operator,
      sym_parenthesized_expression,
      sym_call,
  [8959] = 13,
    ACTIONS(3), 1,
      anon_sym_SLASH_SLASH,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(19), 1,
      anon_sym_not,
    ACTIONS(21), 1,
      anon_sym_DASH,
    ACTIONS(23), 1,
      anon_sym_TILDE,
    ACTIONS(25), 1,
      anon_sym_LPAREN,
    STATE(31), 1,
      sym_primary_expression,
    STATE(41), 1,
      sym_expression,
    STATE(132), 1,
      sym_comment,
    ACTIONS(49), 2,
      sym_string,
      sym_real,
    STATE(38), 2,
      sym_comparison_operator,
      sym_boolean_operator,
    ACTIONS(27), 4,
      sym_true,
      sym_false,
      sym_identifier,
      sym_integer,
    STATE(36), 5,
      sym_unary_operator,
      sym_binary_operator,
      sym_ternary_operator,
      sym_parenthesized_expression,
      sym_call,
  [9008] = 13,
    ACTIONS(3), 1,
      anon_sym_SLASH_SLASH,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(19), 1,
      anon_sym_not,
    ACTIONS(21), 1,
      anon_sym_DASH,
    ACTIONS(23), 1,
      anon_sym_TILDE,
    ACTIONS(25), 1,
      anon_sym_LPAREN,
    STATE(31), 1,
      sym_primary_expression,
    STATE(48), 1,
      sym_expression,
    STATE(133), 1,
      sym_comment,
    ACTIONS(49), 2,
      sym_string,
      sym_real,
    STATE(38), 2,
      sym_comparison_operator,
      sym_boolean_operator,
    ACTIONS(27), 4,
      sym_true,
      sym_false,
      sym_identifier,
      sym_integer,
    STATE(36), 5,
      sym_unary_operator,
      sym_binary_operator,
      sym_ternary_operator,
      sym_parenthesized_expression,
      sym_call,
  [9057] = 13,
    ACTIONS(3), 1,
      anon_sym_SLASH_SLASH,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(19), 1,
      anon_sym_not,
    ACTIONS(21), 1,
      anon_sym_DASH,
    ACTIONS(23), 1,
      anon_sym_TILDE,
    ACTIONS(25), 1,
      anon_sym_LPAREN,
    STATE(31), 1,
      sym_primary_expression,
    STATE(51), 1,
      sym_expression,
    STATE(134), 1,
      sym_comment,
    ACTIONS(49), 2,
      sym_string,
      sym_real,
    STATE(38), 2,
      sym_comparison_operator,
      sym_boolean_operator,
    ACTIONS(27), 4,
      sym_true,
      sym_false,
      sym_identifier,
      sym_integer,
    STATE(36), 5,
      sym_unary_operator,
      sym_binary_operator,
      sym_ternary_operator,
      sym_parenthesized_expression,
      sym_call,
  [9106] = 13,
    ACTIONS(3), 1,
      anon_sym_SLASH_SLASH,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(19), 1,
      anon_sym_not,
    ACTIONS(21), 1,
      anon_sym_DASH,
    ACTIONS(23), 1,
      anon_sym_TILDE,
    ACTIONS(25), 1,
      anon_sym_LPAREN,
    STATE(31), 1,
      sym_primary_expression,
    STATE(35), 1,
      sym_expression,
    STATE(135), 1,
      sym_comment,
    ACTIONS(49), 2,
      sym_string,
      sym_real,
    STATE(38), 2,
      sym_comparison_operator,
      sym_boolean_operator,
    ACTIONS(27), 4,
      sym_true,
      sym_false,
      sym_identifier,
      sym_integer,
    STATE(36), 5,
      sym_unary_operator,
      sym_binary_operator,
      sym_ternary_operator,
      sym_parenthesized_expression,
      sym_call,
  [9155] = 9,
    ACTIONS(3), 1,
      anon_sym_SLASH_SLASH,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(389), 1,
      anon_sym_else,
    ACTIONS(391), 1,
      anon_sym_endif,
    ACTIONS(393), 1,
      anon_sym_elif,
    STATE(136), 1,
      sym_comment,
    STATE(137), 1,
      aux_sym_if_statement_repeat1,
    STATE(148), 1,
      sym_elif_clause,
    STATE(219), 1,
      sym_else_clause,
  [9183] = 9,
    ACTIONS(3), 1,
      anon_sym_SLASH_SLASH,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(389), 1,
      anon_sym_else,
    ACTIONS(393), 1,
      anon_sym_elif,
    ACTIONS(395), 1,
      anon_sym_endif,
    STATE(137), 1,
      sym_comment,
    STATE(138), 1,
      aux_sym_if_statement_repeat1,
    STATE(148), 1,
      sym_elif_clause,
    STATE(201), 1,
      sym_else_clause,
  [9211] = 6,
    ACTIONS(3), 1,
      anon_sym_SLASH_SLASH,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(399), 1,
      anon_sym_elif,
    STATE(148), 1,
      sym_elif_clause,
    ACTIONS(397), 2,
      anon_sym_else,
      anon_sym_endif,
    STATE(138), 2,
      sym_comment,
      aux_sym_if_statement_repeat1,
  [9232] = 7,
    ACTIONS(3), 1,
      anon_sym_SLASH_SLASH,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(402), 1,
      anon_sym_endcase,
    ACTIONS(404), 1,
      anon_sym_when,
    STATE(139), 1,
      sym_comment,
    STATE(143), 1,
      aux_sym_case_statement_repeat1,
    STATE(169), 1,
      sym_when_clause,
  [9254] = 6,
    ACTIONS(3), 1,
      anon_sym_SLASH_SLASH,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(406), 1,
      anon_sym_LBRACE,
    STATE(140), 1,
      sym_comment,
    STATE(172), 1,
      sym_type,
    ACTIONS(408), 2,
      anon_sym_DOT,
      sym_identifier,
  [9274] = 5,
    ACTIONS(3), 1,
      anon_sym_SLASH_SLASH,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(410), 1,
      anon_sym_COMMA,
    ACTIONS(343), 2,
      anon_sym_SEMI,
      anon_sym_RPAREN,
    STATE(141), 2,
      sym_comment,
      aux_sym_print_statement_repeat1,
  [9292] = 7,
    ACTIONS(3), 1,
      anon_sym_SLASH_SLASH,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(314), 1,
      anon_sym_COLON_EQ,
    ACTIONS(318), 1,
      anon_sym_LT,
    ACTIONS(413), 1,
      anon_sym_COMMA,
    STATE(142), 1,
      sym_comment,
    STATE(147), 1,
      aux_sym__left_hand_side_repeat1,
  [9314] = 6,
    ACTIONS(3), 1,
      anon_sym_SLASH_SLASH,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(415), 1,
      anon_sym_endcase,
    ACTIONS(417), 1,
      anon_sym_when,
    STATE(169), 1,
      sym_when_clause,
    STATE(143), 2,
      sym_comment,
      aux_sym_case_statement_repeat1,
  [9334] = 6,
    ACTIONS(3), 1,
      anon_sym_SLASH_SLASH,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(404), 1,
      anon_sym_when,
    STATE(139), 1,
      aux_sym_case_statement_repeat1,
    STATE(144), 1,
      sym_comment,
    STATE(169), 1,
      sym_when_clause,
  [9353] = 5,
    ACTIONS(3), 1,
      anon_sym_SLASH_SLASH,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(320), 1,
      anon_sym_SEMI,
    ACTIONS(420), 1,
      anon_sym_COMMA,
    STATE(145), 2,
      sym_comment,
      aux_sym_expression_statement_repeat1,
  [9370] = 6,
    ACTIONS(3), 1,
      anon_sym_SLASH_SLASH,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(335), 1,
      anon_sym_COMMA,
    ACTIONS(423), 1,
      anon_sym_RPAREN,
    STATE(141), 1,
      aux_sym_print_statement_repeat1,
    STATE(146), 1,
      sym_comment,
  [9389] = 6,
    ACTIONS(3), 1,
      anon_sym_SLASH_SLASH,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(413), 1,
      anon_sym_COMMA,
    ACTIONS(425), 1,
      anon_sym_COLON_EQ,
    STATE(147), 1,
      sym_comment,
    STATE(159), 1,
      aux_sym__left_hand_side_repeat1,
  [9408] = 4,
    ACTIONS(3), 1,
      anon_sym_SLASH_SLASH,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    STATE(148), 1,
      sym_comment,
    ACTIONS(427), 3,
      anon_sym_else,
      anon_sym_endif,
      anon_sym_elif,
  [9423] = 6,
    ACTIONS(3), 1,
      anon_sym_SLASH_SLASH,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(335), 1,
      anon_sym_COMMA,
    ACTIONS(429), 1,
      anon_sym_RPAREN,
    STATE(141), 1,
      aux_sym_print_statement_repeat1,
    STATE(149), 1,
      sym_comment,
  [9442] = 5,
    ACTIONS(3), 1,
      anon_sym_SLASH_SLASH,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(431), 1,
      anon_sym_COMMA,
    ACTIONS(434), 1,
      anon_sym_GT,
    STATE(150), 2,
      sym_comment,
      aux_sym_gen_expression_repeat1,
  [9459] = 6,
    ACTIONS(3), 1,
      anon_sym_SLASH_SLASH,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(327), 1,
      anon_sym_COMMA,
    ACTIONS(436), 1,
      anon_sym_SEMI,
    STATE(145), 1,
      aux_sym_expression_statement_repeat1,
    STATE(151), 1,
      sym_comment,
  [9478] = 6,
    ACTIONS(3), 1,
      anon_sym_SLASH_SLASH,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(335), 1,
      anon_sym_COMMA,
    ACTIONS(438), 1,
      anon_sym_RPAREN,
    STATE(141), 1,
      aux_sym_print_statement_repeat1,
    STATE(152), 1,
      sym_comment,
  [9497] = 6,
    ACTIONS(3), 1,
      anon_sym_SLASH_SLASH,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(440), 1,
      anon_sym_COMMA,
    ACTIONS(442), 1,
      anon_sym_GT,
    STATE(150), 1,
      aux_sym_gen_expression_repeat1,
    STATE(153), 1,
      sym_comment,
  [9516] = 6,
    ACTIONS(3), 1,
      anon_sym_SLASH_SLASH,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(335), 1,
      anon_sym_COMMA,
    ACTIONS(444), 1,
      anon_sym_SEMI,
    STATE(141), 1,
      aux_sym_print_statement_repeat1,
    STATE(154), 1,
      sym_comment,
  [9535] = 6,
    ACTIONS(3), 1,
      anon_sym_SLASH_SLASH,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(335), 1,
      anon_sym_COMMA,
    ACTIONS(446), 1,
      anon_sym_SEMI,
    STATE(141), 1,
      aux_sym_print_statement_repeat1,
    STATE(155), 1,
      sym_comment,
  [9554] = 5,
    ACTIONS(3), 1,
      anon_sym_SLASH_SLASH,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(318), 1,
      anon_sym_LT,
    STATE(156), 1,
      sym_comment,
    ACTIONS(325), 2,
      anon_sym_COMMA,
      anon_sym_COLON_EQ,
  [9571] = 6,
    ACTIONS(3), 1,
      anon_sym_SLASH_SLASH,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(314), 1,
      anon_sym_COLON_EQ,
    ACTIONS(413), 1,
      anon_sym_COMMA,
    STATE(147), 1,
      aux_sym__left_hand_side_repeat1,
    STATE(157), 1,
      sym_comment,
  [9590] = 6,
    ACTIONS(3), 1,
      anon_sym_SLASH_SLASH,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(440), 1,
      anon_sym_COMMA,
    ACTIONS(448), 1,
      anon_sym_GT,
    STATE(153), 1,
      aux_sym_gen_expression_repeat1,
    STATE(158), 1,
      sym_comment,
  [9609] = 5,
    ACTIONS(3), 1,
      anon_sym_SLASH_SLASH,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(325), 1,
      anon_sym_COLON_EQ,
    ACTIONS(450), 1,
      anon_sym_COMMA,
    STATE(159), 2,
      sym_comment,
      aux_sym__left_hand_side_repeat1,
  [9626] = 4,
    ACTIONS(3), 1,
      anon_sym_SLASH_SLASH,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    STATE(160), 1,
      sym_comment,
    ACTIONS(453), 3,
      anon_sym_else,
      anon_sym_endif,
      anon_sym_elif,
  [9641] = 5,
    ACTIONS(3), 1,
      anon_sym_SLASH_SLASH,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(242), 1,
      anon_sym_LPAREN,
    STATE(161), 1,
      sym_comment,
    STATE(209), 1,
      sym_argument_list,
  [9657] = 5,
    ACTIONS(3), 1,
      anon_sym_SLASH_SLASH,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(455), 1,
      anon_sym_LPAREN,
    STATE(4), 1,
      sym_argument_list,
    STATE(162), 1,
      sym_comment,
  [9673] = 4,
    ACTIONS(3), 1,
      anon_sym_SLASH_SLASH,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    STATE(163), 1,
      sym_comment,
    ACTIONS(434), 2,
      anon_sym_COMMA,
      anon_sym_GT,
  [9687] = 5,
    ACTIONS(3), 1,
      anon_sym_SLASH_SLASH,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(457), 1,
      anon_sym_LPAREN,
    STATE(16), 1,
      sym_argument_list,
    STATE(164), 1,
      sym_comment,
  [9703] = 4,
    ACTIONS(3), 1,
      anon_sym_SLASH_SLASH,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    STATE(165), 1,
      sym_comment,
    ACTIONS(325), 2,
      anon_sym_COMMA,
      anon_sym_COLON_EQ,
  [9717] = 4,
    ACTIONS(3), 1,
      anon_sym_SLASH_SLASH,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    STATE(166), 1,
      sym_comment,
    ACTIONS(459), 2,
      anon_sym_COMMA,
      anon_sym_COLON_EQ,
  [9731] = 4,
    ACTIONS(3), 1,
      anon_sym_SLASH_SLASH,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    STATE(167), 1,
      sym_comment,
    ACTIONS(461), 2,
      anon_sym_COMMA,
      anon_sym_COLON_EQ,
  [9745] = 5,
    ACTIONS(3), 1,
      anon_sym_SLASH_SLASH,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(463), 1,
      anon_sym_SEMI,
    ACTIONS(465), 1,
      sym_identifier,
    STATE(168), 1,
      sym_comment,
  [9761] = 4,
    ACTIONS(3), 1,
      anon_sym_SLASH_SLASH,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    STATE(169), 1,
      sym_comment,
    ACTIONS(467), 2,
      anon_sym_endcase,
      anon_sym_when,
  [9775] = 4,
    ACTIONS(3), 1,
      anon_sym_SLASH_SLASH,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    STATE(170), 1,
      sym_comment,
    ACTIONS(469), 2,
      anon_sym_endcase,
      anon_sym_when,
  [9789] = 5,
    ACTIONS(3), 1,
      anon_sym_SLASH_SLASH,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(471), 1,
      anon_sym_SEMI,
    ACTIONS(473), 1,
      sym_identifier,
    STATE(171), 1,
      sym_comment,
  [9805] = 4,
    ACTIONS(3), 1,
      anon_sym_SLASH_SLASH,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(475), 1,
      anon_sym_LBRACE,
    STATE(172), 1,
      sym_comment,
  [9818] = 4,
    ACTIONS(3), 1,
      anon_sym_SLASH_SLASH,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(477), 1,
      sym_identifier,
    STATE(173), 1,
      sym_comment,
  [9831] = 4,
    ACTIONS(3), 1,
      anon_sym_SLASH_SLASH,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(479), 1,
      anon_sym_endintrinsic,
    STATE(174), 1,
      sym_comment,
  [9844] = 4,
    ACTIONS(3), 1,
      anon_sym_SLASH_SLASH,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(481), 1,
      anon_sym_LBRACE,
    STATE(175), 1,
      sym_comment,
  [9857] = 4,
    ACTIONS(3), 1,
      anon_sym_SLASH_SLASH,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(483), 1,
      anon_sym_SEMI,
    STATE(176), 1,
      sym_comment,
  [9870] = 4,
    ACTIONS(3), 1,
      anon_sym_SLASH_SLASH,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(485), 1,
      anon_sym_SEMI,
    STATE(177), 1,
      sym_comment,
  [9883] = 4,
    ACTIONS(3), 1,
      anon_sym_SLASH_SLASH,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(487), 1,
      anon_sym_endintrinsic,
    STATE(178), 1,
      sym_comment,
  [9896] = 4,
    ACTIONS(3), 1,
      anon_sym_SLASH_SLASH,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(489), 1,
      anon_sym_SEMI,
    STATE(179), 1,
      sym_comment,
  [9909] = 4,
    ACTIONS(491), 1,
      anon_sym_SLASH_SLASH,
    ACTIONS(493), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(495), 1,
      aux_sym_intrinsic_definition_token1,
    STATE(180), 1,
      sym_comment,
  [9922] = 4,
    ACTIONS(3), 1,
      anon_sym_SLASH_SLASH,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(497), 1,
      anon_sym_SEMI,
    STATE(181), 1,
      sym_comment,
  [9935] = 4,
    ACTIONS(3), 1,
      anon_sym_SLASH_SLASH,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(499), 1,
      anon_sym_SEMI,
    STATE(182), 1,
      sym_comment,
  [9948] = 4,
    ACTIONS(3), 1,
      anon_sym_SLASH_SLASH,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(501), 1,
      ts_builtin_sym_end,
    STATE(183), 1,
      sym_comment,
  [9961] = 4,
    ACTIONS(3), 1,
      anon_sym_SLASH_SLASH,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(503), 1,
      anon_sym_SEMI,
    STATE(184), 1,
      sym_comment,
  [9974] = 4,
    ACTIONS(3), 1,
      anon_sym_SLASH_SLASH,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(505), 1,
      anon_sym_SEMI,
    STATE(185), 1,
      sym_comment,
  [9987] = 4,
    ACTIONS(3), 1,
      anon_sym_SLASH_SLASH,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(507), 1,
      anon_sym_endwhile,
    STATE(186), 1,
      sym_comment,
  [10000] = 4,
    ACTIONS(3), 1,
      anon_sym_SLASH_SLASH,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(509), 1,
      anon_sym_SEMI,
    STATE(187), 1,
      sym_comment,
  [10013] = 4,
    ACTIONS(3), 1,
      anon_sym_SLASH_SLASH,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(511), 1,
      anon_sym_SEMI,
    STATE(188), 1,
      sym_comment,
  [10026] = 4,
    ACTIONS(3), 1,
      anon_sym_SLASH_SLASH,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(513), 1,
      anon_sym_SEMI,
    STATE(189), 1,
      sym_comment,
  [10039] = 4,
    ACTIONS(3), 1,
      anon_sym_SLASH_SLASH,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(515), 1,
      sym_identifier,
    STATE(190), 1,
      sym_comment,
  [10052] = 4,
    ACTIONS(3), 1,
      anon_sym_SLASH_SLASH,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(517), 1,
      anon_sym_RBRACE,
    STATE(191), 1,
      sym_comment,
  [10065] = 4,
    ACTIONS(3), 1,
      anon_sym_SLASH_SLASH,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(519), 1,
      anon_sym_endprocedure,
    STATE(192), 1,
      sym_comment,
  [10078] = 4,
    ACTIONS(3), 1,
      anon_sym_SLASH_SLASH,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(521), 1,
      anon_sym_SEMI,
    STATE(193), 1,
      sym_comment,
  [10091] = 4,
    ACTIONS(3), 1,
      anon_sym_SLASH_SLASH,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(523), 1,
      anon_sym_SEMI,
    STATE(194), 1,
      sym_comment,
  [10104] = 4,
    ACTIONS(3), 1,
      anon_sym_SLASH_SLASH,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(525), 1,
      anon_sym_endfunction,
    STATE(195), 1,
      sym_comment,
  [10117] = 4,
    ACTIONS(3), 1,
      anon_sym_SLASH_SLASH,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(527), 1,
      anon_sym_SEMI,
    STATE(196), 1,
      sym_comment,
  [10130] = 4,
    ACTIONS(3), 1,
      anon_sym_SLASH_SLASH,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(529), 1,
      sym_identifier,
    STATE(197), 1,
      sym_comment,
  [10143] = 4,
    ACTIONS(3), 1,
      anon_sym_SLASH_SLASH,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(531), 1,
      anon_sym_SEMI,
    STATE(198), 1,
      sym_comment,
  [10156] = 4,
    ACTIONS(3), 1,
      anon_sym_SLASH_SLASH,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(533), 1,
      anon_sym_SEMI,
    STATE(199), 1,
      sym_comment,
  [10169] = 4,
    ACTIONS(3), 1,
      anon_sym_SLASH_SLASH,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(535), 1,
      sym_identifier,
    STATE(200), 1,
      sym_comment,
  [10182] = 4,
    ACTIONS(3), 1,
      anon_sym_SLASH_SLASH,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(537), 1,
      anon_sym_endif,
    STATE(201), 1,
      sym_comment,
  [10195] = 4,
    ACTIONS(3), 1,
      anon_sym_SLASH_SLASH,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(539), 1,
      anon_sym_SEMI,
    STATE(202), 1,
      sym_comment,
  [10208] = 4,
    ACTIONS(491), 1,
      anon_sym_SLASH_SLASH,
    ACTIONS(493), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(541), 1,
      aux_sym_comment_token1,
    STATE(203), 1,
      sym_comment,
  [10221] = 4,
    ACTIONS(3), 1,
      anon_sym_SLASH_SLASH,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(543), 1,
      anon_sym_SEMI,
    STATE(204), 1,
      sym_comment,
  [10234] = 4,
    ACTIONS(3), 1,
      anon_sym_SLASH_SLASH,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(545), 1,
      anon_sym_endif,
    STATE(205), 1,
      sym_comment,
  [10247] = 4,
    ACTIONS(3), 1,
      anon_sym_SLASH_SLASH,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(547), 1,
      anon_sym_SEMI,
    STATE(206), 1,
      sym_comment,
  [10260] = 4,
    ACTIONS(491), 1,
      anon_sym_SLASH_SLASH,
    ACTIONS(493), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(549), 1,
      aux_sym_intrinsic_definition_token1,
    STATE(207), 1,
      sym_comment,
  [10273] = 4,
    ACTIONS(3), 1,
      anon_sym_SLASH_SLASH,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(551), 1,
      anon_sym_RBRACE,
    STATE(208), 1,
      sym_comment,
  [10286] = 4,
    ACTIONS(3), 1,
      anon_sym_SLASH_SLASH,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(553), 1,
      anon_sym_DASH_GT,
    STATE(209), 1,
      sym_comment,
  [10299] = 4,
    ACTIONS(3), 1,
      anon_sym_SLASH_SLASH,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(555), 1,
      anon_sym_SEMI,
    STATE(210), 1,
      sym_comment,
  [10312] = 4,
    ACTIONS(3), 1,
      anon_sym_SLASH_SLASH,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(557), 1,
      anon_sym_SLASH,
    STATE(211), 1,
      sym_comment,
  [10325] = 4,
    ACTIONS(3), 1,
      anon_sym_SLASH_SLASH,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(559), 1,
      anon_sym_SEMI,
    STATE(212), 1,
      sym_comment,
  [10338] = 4,
    ACTIONS(3), 1,
      anon_sym_SLASH_SLASH,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(561), 1,
      anon_sym_SEMI,
    STATE(213), 1,
      sym_comment,
  [10351] = 4,
    ACTIONS(3), 1,
      anon_sym_SLASH_SLASH,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(563), 1,
      anon_sym_SEMI,
    STATE(214), 1,
      sym_comment,
  [10364] = 4,
    ACTIONS(3), 1,
      anon_sym_SLASH_SLASH,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(565), 1,
      anon_sym_SEMI,
    STATE(215), 1,
      sym_comment,
  [10377] = 4,
    ACTIONS(3), 1,
      anon_sym_SLASH_SLASH,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(567), 1,
      anon_sym_until,
    STATE(216), 1,
      sym_comment,
  [10390] = 4,
    ACTIONS(3), 1,
      anon_sym_SLASH_SLASH,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(569), 1,
      anon_sym_SEMI,
    STATE(217), 1,
      sym_comment,
  [10403] = 4,
    ACTIONS(3), 1,
      anon_sym_SLASH_SLASH,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(571), 1,
      anon_sym_SEMI,
    STATE(218), 1,
      sym_comment,
  [10416] = 4,
    ACTIONS(3), 1,
      anon_sym_SLASH_SLASH,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(573), 1,
      anon_sym_endif,
    STATE(219), 1,
      sym_comment,
  [10429] = 4,
    ACTIONS(491), 1,
      anon_sym_SLASH_SLASH,
    ACTIONS(493), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(575), 1,
      aux_sym_comment_token2,
    STATE(220), 1,
      sym_comment,
  [10442] = 4,
    ACTIONS(3), 1,
      anon_sym_SLASH_SLASH,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(577), 1,
      sym_identifier,
    STATE(221), 1,
      sym_comment,
  [10455] = 4,
    ACTIONS(3), 1,
      anon_sym_SLASH_SLASH,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(579), 1,
      anon_sym_SEMI,
    STATE(222), 1,
      sym_comment,
  [10468] = 4,
    ACTIONS(3), 1,
      anon_sym_SLASH_SLASH,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(581), 1,
      anon_sym_SEMI,
    STATE(223), 1,
      sym_comment,
  [10481] = 4,
    ACTIONS(3), 1,
      anon_sym_SLASH_SLASH,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(583), 1,
      anon_sym_SEMI,
    STATE(224), 1,
      sym_comment,
  [10494] = 4,
    ACTIONS(3), 1,
      anon_sym_SLASH_SLASH,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(585), 1,
      anon_sym_SEMI,
    STATE(225), 1,
      sym_comment,
  [10507] = 1,
    ACTIONS(587), 1,
      ts_builtin_sym_end,
  [10511] = 1,
    ACTIONS(589), 1,
      ts_builtin_sym_end,
};

static const uint32_t ts_small_parse_table_map[] = {
  [SMALL_STATE(2)] = 0,
  [SMALL_STATE(3)] = 130,
  [SMALL_STATE(4)] = 262,
  [SMALL_STATE(5)] = 393,
  [SMALL_STATE(6)] = 524,
  [SMALL_STATE(7)] = 655,
  [SMALL_STATE(8)] = 784,
  [SMALL_STATE(9)] = 915,
  [SMALL_STATE(10)] = 1043,
  [SMALL_STATE(11)] = 1169,
  [SMALL_STATE(12)] = 1297,
  [SMALL_STATE(13)] = 1423,
  [SMALL_STATE(14)] = 1549,
  [SMALL_STATE(15)] = 1677,
  [SMALL_STATE(16)] = 1805,
  [SMALL_STATE(17)] = 1933,
  [SMALL_STATE(18)] = 2059,
  [SMALL_STATE(19)] = 2187,
  [SMALL_STATE(20)] = 2313,
  [SMALL_STATE(21)] = 2441,
  [SMALL_STATE(22)] = 2569,
  [SMALL_STATE(23)] = 2695,
  [SMALL_STATE(24)] = 2823,
  [SMALL_STATE(25)] = 2951,
  [SMALL_STATE(26)] = 3079,
  [SMALL_STATE(27)] = 3207,
  [SMALL_STATE(28)] = 3335,
  [SMALL_STATE(29)] = 3463,
  [SMALL_STATE(30)] = 3589,
  [SMALL_STATE(31)] = 3645,
  [SMALL_STATE(32)] = 3707,
  [SMALL_STATE(33)] = 3763,
  [SMALL_STATE(34)] = 3819,
  [SMALL_STATE(35)] = 3874,
  [SMALL_STATE(36)] = 3939,
  [SMALL_STATE(37)] = 3994,
  [SMALL_STATE(38)] = 4049,
  [SMALL_STATE(39)] = 4104,
  [SMALL_STATE(40)] = 4179,
  [SMALL_STATE(41)] = 4236,
  [SMALL_STATE(42)] = 4299,
  [SMALL_STATE(43)] = 4372,
  [SMALL_STATE(44)] = 4429,
  [SMALL_STATE(45)] = 4490,
  [SMALL_STATE(46)] = 4547,
  [SMALL_STATE(47)] = 4604,
  [SMALL_STATE(48)] = 4683,
  [SMALL_STATE(49)] = 4750,
  [SMALL_STATE(50)] = 4819,
  [SMALL_STATE(51)] = 4892,
  [SMALL_STATE(52)] = 4973,
  [SMALL_STATE(53)] = 5044,
  [SMALL_STATE(54)] = 5115,
  [SMALL_STATE(55)] = 5168,
  [SMALL_STATE(56)] = 5224,
  [SMALL_STATE(57)] = 5280,
  [SMALL_STATE(58)] = 5331,
  [SMALL_STATE(59)] = 5382,
  [SMALL_STATE(60)] = 5432,
  [SMALL_STATE(61)] = 5482,
  [SMALL_STATE(62)] = 5532,
  [SMALL_STATE(63)] = 5599,
  [SMALL_STATE(64)] = 5662,
  [SMALL_STATE(65)] = 5703,
  [SMALL_STATE(66)] = 5770,
  [SMALL_STATE(67)] = 5837,
  [SMALL_STATE(68)] = 5904,
  [SMALL_STATE(69)] = 5945,
  [SMALL_STATE(70)] = 6012,
  [SMALL_STATE(71)] = 6052,
  [SMALL_STATE(72)] = 6092,
  [SMALL_STATE(73)] = 6153,
  [SMALL_STATE(74)] = 6192,
  [SMALL_STATE(75)] = 6253,
  [SMALL_STATE(76)] = 6292,
  [SMALL_STATE(77)] = 6331,
  [SMALL_STATE(78)] = 6392,
  [SMALL_STATE(79)] = 6431,
  [SMALL_STATE(80)] = 6492,
  [SMALL_STATE(81)] = 6531,
  [SMALL_STATE(82)] = 6570,
  [SMALL_STATE(83)] = 6631,
  [SMALL_STATE(84)] = 6670,
  [SMALL_STATE(85)] = 6709,
  [SMALL_STATE(86)] = 6748,
  [SMALL_STATE(87)] = 6787,
  [SMALL_STATE(88)] = 6848,
  [SMALL_STATE(89)] = 6887,
  [SMALL_STATE(90)] = 6948,
  [SMALL_STATE(91)] = 6987,
  [SMALL_STATE(92)] = 7026,
  [SMALL_STATE(93)] = 7065,
  [SMALL_STATE(94)] = 7104,
  [SMALL_STATE(95)] = 7143,
  [SMALL_STATE(96)] = 7182,
  [SMALL_STATE(97)] = 7220,
  [SMALL_STATE(98)] = 7258,
  [SMALL_STATE(99)] = 7296,
  [SMALL_STATE(100)] = 7354,
  [SMALL_STATE(101)] = 7411,
  [SMALL_STATE(102)] = 7468,
  [SMALL_STATE(103)] = 7523,
  [SMALL_STATE(104)] = 7575,
  [SMALL_STATE(105)] = 7627,
  [SMALL_STATE(106)] = 7679,
  [SMALL_STATE(107)] = 7731,
  [SMALL_STATE(108)] = 7783,
  [SMALL_STATE(109)] = 7832,
  [SMALL_STATE(110)] = 7881,
  [SMALL_STATE(111)] = 7930,
  [SMALL_STATE(112)] = 7979,
  [SMALL_STATE(113)] = 8028,
  [SMALL_STATE(114)] = 8077,
  [SMALL_STATE(115)] = 8126,
  [SMALL_STATE(116)] = 8175,
  [SMALL_STATE(117)] = 8224,
  [SMALL_STATE(118)] = 8273,
  [SMALL_STATE(119)] = 8322,
  [SMALL_STATE(120)] = 8371,
  [SMALL_STATE(121)] = 8420,
  [SMALL_STATE(122)] = 8469,
  [SMALL_STATE(123)] = 8518,
  [SMALL_STATE(124)] = 8567,
  [SMALL_STATE(125)] = 8616,
  [SMALL_STATE(126)] = 8665,
  [SMALL_STATE(127)] = 8714,
  [SMALL_STATE(128)] = 8763,
  [SMALL_STATE(129)] = 8812,
  [SMALL_STATE(130)] = 8861,
  [SMALL_STATE(131)] = 8910,
  [SMALL_STATE(132)] = 8959,
  [SMALL_STATE(133)] = 9008,
  [SMALL_STATE(134)] = 9057,
  [SMALL_STATE(135)] = 9106,
  [SMALL_STATE(136)] = 9155,
  [SMALL_STATE(137)] = 9183,
  [SMALL_STATE(138)] = 9211,
  [SMALL_STATE(139)] = 9232,
  [SMALL_STATE(140)] = 9254,
  [SMALL_STATE(141)] = 9274,
  [SMALL_STATE(142)] = 9292,
  [SMALL_STATE(143)] = 9314,
  [SMALL_STATE(144)] = 9334,
  [SMALL_STATE(145)] = 9353,
  [SMALL_STATE(146)] = 9370,
  [SMALL_STATE(147)] = 9389,
  [SMALL_STATE(148)] = 9408,
  [SMALL_STATE(149)] = 9423,
  [SMALL_STATE(150)] = 9442,
  [SMALL_STATE(151)] = 9459,
  [SMALL_STATE(152)] = 9478,
  [SMALL_STATE(153)] = 9497,
  [SMALL_STATE(154)] = 9516,
  [SMALL_STATE(155)] = 9535,
  [SMALL_STATE(156)] = 9554,
  [SMALL_STATE(157)] = 9571,
  [SMALL_STATE(158)] = 9590,
  [SMALL_STATE(159)] = 9609,
  [SMALL_STATE(160)] = 9626,
  [SMALL_STATE(161)] = 9641,
  [SMALL_STATE(162)] = 9657,
  [SMALL_STATE(163)] = 9673,
  [SMALL_STATE(164)] = 9687,
  [SMALL_STATE(165)] = 9703,
  [SMALL_STATE(166)] = 9717,
  [SMALL_STATE(167)] = 9731,
  [SMALL_STATE(168)] = 9745,
  [SMALL_STATE(169)] = 9761,
  [SMALL_STATE(170)] = 9775,
  [SMALL_STATE(171)] = 9789,
  [SMALL_STATE(172)] = 9805,
  [SMALL_STATE(173)] = 9818,
  [SMALL_STATE(174)] = 9831,
  [SMALL_STATE(175)] = 9844,
  [SMALL_STATE(176)] = 9857,
  [SMALL_STATE(177)] = 9870,
  [SMALL_STATE(178)] = 9883,
  [SMALL_STATE(179)] = 9896,
  [SMALL_STATE(180)] = 9909,
  [SMALL_STATE(181)] = 9922,
  [SMALL_STATE(182)] = 9935,
  [SMALL_STATE(183)] = 9948,
  [SMALL_STATE(184)] = 9961,
  [SMALL_STATE(185)] = 9974,
  [SMALL_STATE(186)] = 9987,
  [SMALL_STATE(187)] = 10000,
  [SMALL_STATE(188)] = 10013,
  [SMALL_STATE(189)] = 10026,
  [SMALL_STATE(190)] = 10039,
  [SMALL_STATE(191)] = 10052,
  [SMALL_STATE(192)] = 10065,
  [SMALL_STATE(193)] = 10078,
  [SMALL_STATE(194)] = 10091,
  [SMALL_STATE(195)] = 10104,
  [SMALL_STATE(196)] = 10117,
  [SMALL_STATE(197)] = 10130,
  [SMALL_STATE(198)] = 10143,
  [SMALL_STATE(199)] = 10156,
  [SMALL_STATE(200)] = 10169,
  [SMALL_STATE(201)] = 10182,
  [SMALL_STATE(202)] = 10195,
  [SMALL_STATE(203)] = 10208,
  [SMALL_STATE(204)] = 10221,
  [SMALL_STATE(205)] = 10234,
  [SMALL_STATE(206)] = 10247,
  [SMALL_STATE(207)] = 10260,
  [SMALL_STATE(208)] = 10273,
  [SMALL_STATE(209)] = 10286,
  [SMALL_STATE(210)] = 10299,
  [SMALL_STATE(211)] = 10312,
  [SMALL_STATE(212)] = 10325,
  [SMALL_STATE(213)] = 10338,
  [SMALL_STATE(214)] = 10351,
  [SMALL_STATE(215)] = 10364,
  [SMALL_STATE(216)] = 10377,
  [SMALL_STATE(217)] = 10390,
  [SMALL_STATE(218)] = 10403,
  [SMALL_STATE(219)] = 10416,
  [SMALL_STATE(220)] = 10429,
  [SMALL_STATE(221)] = 10442,
  [SMALL_STATE(222)] = 10455,
  [SMALL_STATE(223)] = 10468,
  [SMALL_STATE(224)] = 10481,
  [SMALL_STATE(225)] = 10494,
  [SMALL_STATE(226)] = 10507,
  [SMALL_STATE(227)] = 10511,
};

static const TSParseActionEntry ts_parse_actions[] = {
  [0] = {.entry = {.count = 0, .reusable = false}},
  [1] = {.entry = {.count = 1, .reusable = false}}, RECOVER(),
  [3] = {.entry = {.count = 1, .reusable = true}}, SHIFT(203),
  [5] = {.entry = {.count = 1, .reusable = true}}, SHIFT(220),
  [7] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_program, 0),
  [9] = {.entry = {.count = 1, .reusable = false}}, SHIFT(102),
  [11] = {.entry = {.count = 1, .reusable = false}}, SHIFT(171),
  [13] = {.entry = {.count = 1, .reusable = false}}, SHIFT(168),
  [15] = {.entry = {.count = 1, .reusable = false}}, SHIFT(119),
  [17] = {.entry = {.count = 1, .reusable = false}}, SHIFT(117),
  [19] = {.entry = {.count = 1, .reusable = false}}, SHIFT(114),
  [21] = {.entry = {.count = 1, .reusable = true}}, SHIFT(113),
  [23] = {.entry = {.count = 1, .reusable = true}}, SHIFT(108),
  [25] = {.entry = {.count = 1, .reusable = true}}, SHIFT(110),
  [27] = {.entry = {.count = 1, .reusable = false}}, SHIFT(36),
  [29] = {.entry = {.count = 1, .reusable = false}}, SHIFT(200),
  [31] = {.entry = {.count = 1, .reusable = false}}, SHIFT(173),
  [33] = {.entry = {.count = 1, .reusable = false}}, SHIFT(197),
  [35] = {.entry = {.count = 1, .reusable = false}}, SHIFT(142),
  [37] = {.entry = {.count = 1, .reusable = false}}, SHIFT(116),
  [39] = {.entry = {.count = 1, .reusable = true}}, SHIFT(194),
  [41] = {.entry = {.count = 1, .reusable = false}}, SHIFT(124),
  [43] = {.entry = {.count = 1, .reusable = false}}, SHIFT(21),
  [45] = {.entry = {.count = 1, .reusable = false}}, SHIFT(109),
  [47] = {.entry = {.count = 1, .reusable = false}}, SHIFT(54),
  [49] = {.entry = {.count = 1, .reusable = true}}, SHIFT(36),
  [51] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_block_repeat1, 2), SHIFT_REPEAT(102),
  [54] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_block_repeat1, 2), SHIFT_REPEAT(171),
  [57] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_block_repeat1, 2), SHIFT_REPEAT(168),
  [60] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_block_repeat1, 2), SHIFT_REPEAT(119),
  [63] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_block_repeat1, 2), SHIFT_REPEAT(117),
  [66] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_block_repeat1, 2), SHIFT_REPEAT(114),
  [69] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_block_repeat1, 2), SHIFT_REPEAT(113),
  [72] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_block_repeat1, 2), SHIFT_REPEAT(108),
  [75] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_block_repeat1, 2),
  [77] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_block_repeat1, 2), SHIFT_REPEAT(110),
  [80] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_block_repeat1, 2), SHIFT_REPEAT(36),
  [83] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_block_repeat1, 2), SHIFT_REPEAT(200),
  [86] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_block_repeat1, 2), SHIFT_REPEAT(173),
  [89] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_block_repeat1, 2), SHIFT_REPEAT(197),
  [92] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_block_repeat1, 2), SHIFT_REPEAT(142),
  [95] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_block_repeat1, 2), SHIFT_REPEAT(116),
  [98] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_block_repeat1, 2),
  [100] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_block_repeat1, 2), SHIFT_REPEAT(223),
  [103] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_block_repeat1, 2), SHIFT_REPEAT(124),
  [106] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_block_repeat1, 2), SHIFT_REPEAT(21),
  [109] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_block_repeat1, 2), SHIFT_REPEAT(109),
  [112] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_block_repeat1, 2), SHIFT_REPEAT(54),
  [115] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_block_repeat1, 2), SHIFT_REPEAT(36),
  [118] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_block, 1),
  [120] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_block, 1),
  [122] = {.entry = {.count = 1, .reusable = true}}, SHIFT(223),
  [124] = {.entry = {.count = 1, .reusable = true}}, SHIFT(193),
  [126] = {.entry = {.count = 1, .reusable = true}}, SHIFT(222),
  [128] = {.entry = {.count = 1, .reusable = true}}, SHIFT(199),
  [130] = {.entry = {.count = 1, .reusable = true}}, SHIFT(210),
  [132] = {.entry = {.count = 1, .reusable = true}}, SHIFT(177),
  [134] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_block_repeat1, 2), SHIFT_REPEAT(213),
  [137] = {.entry = {.count = 1, .reusable = true}}, SHIFT(213),
  [139] = {.entry = {.count = 1, .reusable = true}}, SHIFT(224),
  [141] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_block_repeat1, 2), SHIFT_REPEAT(225),
  [144] = {.entry = {.count = 1, .reusable = true}}, SHIFT(225),
  [146] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_block_repeat1, 2), SHIFT_REPEAT(224),
  [149] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_block_repeat1, 2), SHIFT_REPEAT(214),
  [152] = {.entry = {.count = 1, .reusable = true}}, SHIFT(218),
  [154] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_program_repeat1, 2),
  [156] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_program_repeat1, 2), SHIFT_REPEAT(102),
  [159] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_program_repeat1, 2), SHIFT_REPEAT(171),
  [162] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_program_repeat1, 2), SHIFT_REPEAT(168),
  [165] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_program_repeat1, 2), SHIFT_REPEAT(119),
  [168] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_program_repeat1, 2), SHIFT_REPEAT(117),
  [171] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_program_repeat1, 2), SHIFT_REPEAT(114),
  [174] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_program_repeat1, 2), SHIFT_REPEAT(113),
  [177] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_program_repeat1, 2), SHIFT_REPEAT(108),
  [180] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_program_repeat1, 2), SHIFT_REPEAT(110),
  [183] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_program_repeat1, 2), SHIFT_REPEAT(36),
  [186] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_program_repeat1, 2), SHIFT_REPEAT(200),
  [189] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_program_repeat1, 2), SHIFT_REPEAT(173),
  [192] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_program_repeat1, 2), SHIFT_REPEAT(197),
  [195] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_program_repeat1, 2), SHIFT_REPEAT(142),
  [198] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_program_repeat1, 2), SHIFT_REPEAT(116),
  [201] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_program_repeat1, 2), SHIFT_REPEAT(194),
  [204] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_program_repeat1, 2), SHIFT_REPEAT(124),
  [207] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_program_repeat1, 2), SHIFT_REPEAT(21),
  [210] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_program_repeat1, 2), SHIFT_REPEAT(109),
  [213] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_program_repeat1, 2), SHIFT_REPEAT(54),
  [216] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_program_repeat1, 2), SHIFT_REPEAT(36),
  [219] = {.entry = {.count = 1, .reusable = true}}, SHIFT(214),
  [221] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_block_repeat1, 2), SHIFT_REPEAT(222),
  [224] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_block_repeat1, 2), SHIFT_REPEAT(218),
  [227] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_program, 1),
  [229] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_block_repeat1, 2), SHIFT_REPEAT(210),
  [232] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_argument_list, 3),
  [234] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_argument_list, 3),
  [236] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_expression, 1),
  [238] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_expression, 1),
  [240] = {.entry = {.count = 1, .reusable = true}}, SHIFT(126),
  [242] = {.entry = {.count = 1, .reusable = true}}, SHIFT(103),
  [244] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_argument_list, 4),
  [246] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_argument_list, 4),
  [248] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_argument_list, 2),
  [250] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_argument_list, 2),
  [252] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_call, 2, .production_id = 2),
  [254] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_call, 2, .production_id = 2),
  [256] = {.entry = {.count = 1, .reusable = false}}, SHIFT(112),
  [258] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_binary_operator, 3, .production_id = 4),
  [260] = {.entry = {.count = 1, .reusable = false}}, SHIFT(115),
  [262] = {.entry = {.count = 1, .reusable = false}}, SHIFT(118),
  [264] = {.entry = {.count = 1, .reusable = true}}, SHIFT(112),
  [266] = {.entry = {.count = 1, .reusable = true}}, SHIFT(132),
  [268] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_binary_operator, 3, .production_id = 4),
  [270] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_primary_expression, 1),
  [272] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_primary_expression, 1),
  [274] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_parenthesized_expression, 3),
  [276] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_parenthesized_expression, 3),
  [278] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_boolean_operator, 3, .production_id = 4),
  [280] = {.entry = {.count = 1, .reusable = true}}, SHIFT(128),
  [282] = {.entry = {.count = 1, .reusable = true}}, SHIFT(133),
  [284] = {.entry = {.count = 1, .reusable = true}}, SHIFT(135),
  [286] = {.entry = {.count = 1, .reusable = true}}, SHIFT(130),
  [288] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_boolean_operator, 3, .production_id = 4),
  [290] = {.entry = {.count = 1, .reusable = false}}, SHIFT(127),
  [292] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_unary_operator, 2, .production_id = 1),
  [294] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_unary_operator, 2, .production_id = 1),
  [296] = {.entry = {.count = 1, .reusable = false}}, SHIFT(129),
  [298] = {.entry = {.count = 1, .reusable = true}}, SHIFT(129),
  [300] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_ternary_operator, 5, .production_id = 13),
  [302] = {.entry = {.count = 1, .reusable = true}}, SHIFT(122),
  [304] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_ternary_operator, 5, .production_id = 13),
  [306] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_comparison_operator, 3, .production_id = 4),
  [308] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_comparison_operator, 3, .production_id = 4),
  [310] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_expression_statement, 1),
  [312] = {.entry = {.count = 1, .reusable = true}}, SHIFT(101),
  [314] = {.entry = {.count = 1, .reusable = true}}, SHIFT(106),
  [316] = {.entry = {.count = 1, .reusable = true}}, SHIFT(123),
  [318] = {.entry = {.count = 1, .reusable = true}}, SHIFT(221),
  [320] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_expression_statement_repeat1, 2),
  [322] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_expression_statement_repeat1, 2), REDUCE(aux_sym__left_hand_side_repeat1, 2),
  [325] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym__left_hand_side_repeat1, 2),
  [327] = {.entry = {.count = 1, .reusable = true}}, SHIFT(121),
  [329] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_eval_statement, 2),
  [331] = {.entry = {.count = 1, .reusable = true}}, SHIFT(144),
  [333] = {.entry = {.count = 1, .reusable = true}}, SHIFT(14),
  [335] = {.entry = {.count = 1, .reusable = true}}, SHIFT(120),
  [337] = {.entry = {.count = 1, .reusable = true}}, SHIFT(115),
  [339] = {.entry = {.count = 1, .reusable = true}}, SHIFT(127),
  [341] = {.entry = {.count = 1, .reusable = true}}, SHIFT(97),
  [343] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_print_statement_repeat1, 2),
  [345] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_block_repeat1, 1),
  [347] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_block_repeat1, 1),
  [349] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__right_hand_side, 1),
  [351] = {.entry = {.count = 1, .reusable = true}}, SHIFT(95),
  [353] = {.entry = {.count = 1, .reusable = true}}, SHIFT(30),
  [355] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym__statement, 2),
  [357] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__statement, 2),
  [359] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_print_statement, 2),
  [361] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_augmented_assignment, 3, .production_id = 3),
  [363] = {.entry = {.count = 1, .reusable = true}}, SHIFT(134),
  [365] = {.entry = {.count = 1, .reusable = true}}, SHIFT(23),
  [367] = {.entry = {.count = 1, .reusable = true}}, SHIFT(15),
  [369] = {.entry = {.count = 1, .reusable = true}}, SHIFT(27),
  [371] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_program_repeat1, 1),
  [373] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_program_repeat1, 1),
  [375] = {.entry = {.count = 1, .reusable = true}}, SHIFT(37),
  [377] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_repeat_statement, 4, .production_id = 7),
  [379] = {.entry = {.count = 1, .reusable = false}}, SHIFT(156),
  [381] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_return_statement, 1),
  [383] = {.entry = {.count = 1, .reusable = true}}, SHIFT(33),
  [385] = {.entry = {.count = 1, .reusable = true}}, SHIFT(98),
  [387] = {.entry = {.count = 1, .reusable = true}}, SHIFT(94),
  [389] = {.entry = {.count = 1, .reusable = true}}, SHIFT(26),
  [391] = {.entry = {.count = 1, .reusable = true}}, SHIFT(185),
  [393] = {.entry = {.count = 1, .reusable = true}}, SHIFT(125),
  [395] = {.entry = {.count = 1, .reusable = true}}, SHIFT(202),
  [397] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_if_statement_repeat1, 2, .production_id = 17),
  [399] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_if_statement_repeat1, 2, .production_id = 17), SHIFT_REPEAT(125),
  [402] = {.entry = {.count = 1, .reusable = true}}, SHIFT(212),
  [404] = {.entry = {.count = 1, .reusable = true}}, SHIFT(131),
  [406] = {.entry = {.count = 1, .reusable = true}}, SHIFT(180),
  [408] = {.entry = {.count = 1, .reusable = true}}, SHIFT(175),
  [410] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_print_statement_repeat1, 2), SHIFT_REPEAT(120),
  [413] = {.entry = {.count = 1, .reusable = true}}, SHIFT(100),
  [415] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_case_statement_repeat1, 2),
  [417] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_case_statement_repeat1, 2), SHIFT_REPEAT(131),
  [420] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_expression_statement_repeat1, 2), SHIFT_REPEAT(121),
  [423] = {.entry = {.count = 1, .reusable = true}}, SHIFT(90),
  [425] = {.entry = {.count = 1, .reusable = true}}, SHIFT(107),
  [427] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_if_statement_repeat1, 1, .production_id = 10),
  [429] = {.entry = {.count = 1, .reusable = true}}, SHIFT(96),
  [431] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_gen_expression_repeat1, 2), SHIFT_REPEAT(190),
  [434] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_gen_expression_repeat1, 2),
  [436] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_expression_statement, 2),
  [438] = {.entry = {.count = 1, .reusable = true}}, SHIFT(32),
  [440] = {.entry = {.count = 1, .reusable = true}}, SHIFT(190),
  [442] = {.entry = {.count = 1, .reusable = true}}, SHIFT(166),
  [444] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__right_hand_side, 2),
  [446] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_print_statement, 3),
  [448] = {.entry = {.count = 1, .reusable = true}}, SHIFT(167),
  [450] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym__left_hand_side_repeat1, 2), SHIFT_REPEAT(100),
  [453] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_elif_clause, 4, .production_id = 9),
  [455] = {.entry = {.count = 1, .reusable = true}}, SHIFT(105),
  [457] = {.entry = {.count = 1, .reusable = true}}, SHIFT(104),
  [459] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_gen_expression, 5),
  [461] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_gen_expression, 4),
  [463] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_continue_statement, 1),
  [465] = {.entry = {.count = 1, .reusable = true}}, SHIFT(184),
  [467] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_case_statement_repeat1, 1),
  [469] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_when_clause, 4, .production_id = 19),
  [471] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_break_statement, 1),
  [473] = {.entry = {.count = 1, .reusable = true}}, SHIFT(198),
  [475] = {.entry = {.count = 1, .reusable = true}}, SHIFT(207),
  [477] = {.entry = {.count = 1, .reusable = true}}, SHIFT(162),
  [479] = {.entry = {.count = 1, .reusable = true}}, SHIFT(176),
  [481] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_type, 1),
  [483] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_intrinsic_definition, 9, .production_id = 21),
  [485] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_intrinsic_definition, 9, .production_id = 22),
  [487] = {.entry = {.count = 1, .reusable = true}}, SHIFT(179),
  [489] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_intrinsic_definition, 10, .production_id = 23),
  [491] = {.entry = {.count = 1, .reusable = false}}, SHIFT(203),
  [493] = {.entry = {.count = 1, .reusable = false}}, SHIFT(220),
  [495] = {.entry = {.count = 1, .reusable = false}}, SHIFT(208),
  [497] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_procedure_definition, 5, .production_id = 8),
  [499] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_function_definition, 5, .production_id = 8),
  [501] = {.entry = {.count = 1, .reusable = true}},  ACCEPT_INPUT(),
  [503] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_continue_statement, 2),
  [505] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_if_statement, 5, .production_id = 9),
  [507] = {.entry = {.count = 1, .reusable = true}}, SHIFT(217),
  [509] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_assignment, 4, .production_id = 6),
  [511] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_if_statement, 7, .production_id = 18),
  [513] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__definition, 1),
  [515] = {.entry = {.count = 1, .reusable = true}}, SHIFT(163),
  [517] = {.entry = {.count = 1, .reusable = true}}, SHIFT(6),
  [519] = {.entry = {.count = 1, .reusable = true}}, SHIFT(181),
  [521] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_procedure_definition, 4, .production_id = 5),
  [523] = {.entry = {.count = 1, .reusable = true}}, SHIFT(78),
  [525] = {.entry = {.count = 1, .reusable = true}}, SHIFT(182),
  [527] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__assignment, 1),
  [529] = {.entry = {.count = 1, .reusable = true}}, SHIFT(161),
  [531] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_break_statement, 2),
  [533] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_intrinsic_definition, 8, .production_id = 20),
  [535] = {.entry = {.count = 1, .reusable = true}}, SHIFT(164),
  [537] = {.entry = {.count = 1, .reusable = true}}, SHIFT(188),
  [539] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_if_statement, 6, .production_id = 16),
  [541] = {.entry = {.count = 1, .reusable = false}}, SHIFT(227),
  [543] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_if_statement, 6, .production_id = 15),
  [545] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_else_clause, 2, .production_id = 14),
  [547] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_assignment, 3, .production_id = 3),
  [549] = {.entry = {.count = 1, .reusable = false}}, SHIFT(191),
  [551] = {.entry = {.count = 1, .reusable = true}}, SHIFT(5),
  [553] = {.entry = {.count = 1, .reusable = true}}, SHIFT(140),
  [555] = {.entry = {.count = 1, .reusable = true}}, SHIFT(73),
  [557] = {.entry = {.count = 1, .reusable = false}}, SHIFT(226),
  [559] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_case_statement, 5, .production_id = 12),
  [561] = {.entry = {.count = 1, .reusable = true}}, SHIFT(71),
  [563] = {.entry = {.count = 1, .reusable = true}}, SHIFT(84),
  [565] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_return_statement, 2),
  [567] = {.entry = {.count = 1, .reusable = true}}, SHIFT(111),
  [569] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_while_statement, 5, .production_id = 11),
  [571] = {.entry = {.count = 1, .reusable = true}}, SHIFT(91),
  [573] = {.entry = {.count = 1, .reusable = true}}, SHIFT(204),
  [575] = {.entry = {.count = 1, .reusable = false}}, SHIFT(211),
  [577] = {.entry = {.count = 1, .reusable = true}}, SHIFT(158),
  [579] = {.entry = {.count = 1, .reusable = true}}, SHIFT(88),
  [581] = {.entry = {.count = 1, .reusable = true}}, SHIFT(68),
  [583] = {.entry = {.count = 1, .reusable = true}}, SHIFT(81),
  [585] = {.entry = {.count = 1, .reusable = true}}, SHIFT(75),
  [587] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_comment, 3),
  [589] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_comment, 2),
};

#ifdef __cplusplus
extern "C" {
#endif
#ifdef _WIN32
#define extern __declspec(dllexport)
#endif

extern const TSLanguage *tree_sitter_magma(void) {
  static const TSLanguage language = {
    .version = LANGUAGE_VERSION,
    .symbol_count = SYMBOL_COUNT,
    .alias_count = ALIAS_COUNT,
    .token_count = TOKEN_COUNT,
    .external_token_count = EXTERNAL_TOKEN_COUNT,
    .state_count = STATE_COUNT,
    .large_state_count = LARGE_STATE_COUNT,
    .production_id_count = PRODUCTION_ID_COUNT,
    .field_count = FIELD_COUNT,
    .max_alias_sequence_length = MAX_ALIAS_SEQUENCE_LENGTH,
    .parse_table = &ts_parse_table[0][0],
    .small_parse_table = ts_small_parse_table,
    .small_parse_table_map = ts_small_parse_table_map,
    .parse_actions = ts_parse_actions,
    .symbol_names = ts_symbol_names,
    .field_names = ts_field_names,
    .field_map_slices = ts_field_map_slices,
    .field_map_entries = ts_field_map_entries,
    .symbol_metadata = ts_symbol_metadata,
    .public_symbol_map = ts_symbol_map,
    .alias_map = ts_non_terminal_alias_map,
    .alias_sequences = &ts_alias_sequences[0][0],
    .lex_modes = ts_lex_modes,
    .lex_fn = ts_lex,
    .primary_state_ids = ts_primary_state_ids,
  };
  return &language;
}
#ifdef __cplusplus
}
#endif
