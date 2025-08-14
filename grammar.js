// precedence table
// precedence: low -> high
const PREC = {
	parenthesized_expression: 1, // TOK_LEFTROUND                   (left)
	eval: 2,                 // TOK_EVAL
	where: 3,                // TOK_WHERE TOK_IS TOK_BECOMES
	eq: 4,                   // TOK_EQUALITY
	arrow: 5,                // TOK_ARROW
	ternary: 6,              // TOK_QUESTION TOK_SELECT TOK_ELSE   (right)
	hathat: 7,               // TOK_HAT_HAT                         (nonassoc)
	or: 8,                   // TOK_OR TOK_XOR                      (left)
	and: 9,                  // TOK_AND                             (left)
	not: 10,                 // TOK_NOT                             (right)
	cmp: 11,                 // TOK_EQ TOK_CMPEQ TOK_CMPNE TOK_NE TOK_GT TOK_GE TOK_LT TOK_LE (left)
	membership: 12,          // TOK_IN TOK_NOTIN TOK_ADJ TOK_NOTADJ TOK_SUBSET TOK_NOTSUBSET  (nonassoc)
	join: 13,                // TOK_JOIN                            (left)
	diff: 14,                // TOK_DIFF                            (left)
	sdiff: 15,               // TOK_SDIFF                           (left)
	meet: 16,                // TOK_MEET                            (left)
	plus: 17,                // TOK_PLUS TOK_MINUS                  (left)
	times: 18,               // TOK_DIV TOK_MOD TOK_STAR TOK_SLASH  (left)
	tilde: 19,               // TOK_TILDE                           (left)
	cat: 20,                 // TOK_CAT                             (left)
	negate: 21,              // TOK_UMINUS                          (right)
	power: 22,               // TOK_HAT                             (right)
	bang: 23,                // TOK_BANG TOK_BANG_BANG              (right)
	colon: 24,               // TOK_COLON TOK_COLON_COLON            (left)
	at: 25,                  // TOK_AT TOK_ATAT                     (left)
	dot: 26,                 // TOK_DOT                             (left)
	dollar: 27,              // TOK_DOLLAR TOK_DOLLAR_DOLLAR        (nonassoc)
	reduct: 28,              // TOK_REDUCT_PLUS TOK_REDUCT_MULT TOK_REDUCT_AND TOK_REDUCT_OR (nonassoc)
	hash: 29,                // TOK_HASH                            (nonassoc)
	utilde: 30,              // TOK_UTILDE                          (nonassoc)
	assigned: 31,            // TOK_ASSIGNED                        (right)
	sq_bracket: 32,          // TOK_LEFTSQUARE                      (left)   // indexing
	parenthesis: 33, // TOK_LEFTROUND                   (left)
	backquote: 34,           // TOK_BACKQUOTE TOK_BACKQUOTE_BACKQUOTE (left)
	call: 35                 // function application; keep as top-most
};


// TODO: what does double backquote mean?
/*

Double Backquote: Used for dynamic selection. The name of the field is determined by evaluating an expression.
The grammar defines this as an expression followed by a double backquote and another expression (

expr TOK_BACKQUOTE_BACKQUOTE expr).

    Example: MyRecord``"na" cat "me"

        In this case, the expression "na" cat "me" is first evaluated to the string "name".
		The result is then used to access the name field from the MyRecord object. This is useful when field names are constructed programmatically.
*/


// TODO: add line continuation character: \

module.exports = grammar({
    name: 'magma',

    extras: $ => [
	/\s/,           // whitespace
	$.comment,      // comments
    ],

    conflicts: $ => [
	[$.expression_statement, $.assignment],
	[$.function_definition, $.primary_expression, $.procedure_definition],
	// [$.procedure_definition, $.primary_expression],
	// [$.procedure_definition, $.function_definition],
    ],
    // A _statement_ is any valid sequence of symbols followed by a semicolon
    // eg. a variable assignment, a function/intrinsic definition

    // An _expression_ is a collection of symbols which evaluates to something (possibly nothing)
    // eg. a + 3, NumberField(x^2 +1), a generator expression

    // A _primary expression_ is a smaller unit, e.g. an integer, a real number,
    // The distinction is taken from tree-sitter-python, so I don't know if it's necessary
    // in our context, but it provides a cleaner structure

    supertypes: $ => [
	$._simple_statement,
	$._compound_statement,
	$.expression,
	$.primary_expression,
    ],

    inline: $ => [
	$._simple_statement,
	$._compound_statement,
	$._left_hand_side,
	// $._right_hand_side,
    ],
    rules: {
	program: $ => choice(
	    repeat(choice(
		// $.expression,
		$._statement,
		// $.directive,
		// $.intrinsic,
		// $.declaration
	    )),
	    // Empty program -- is this really necessary?
	    seq()
	),
	
	// Comments
	comment: $ => choice(
	    seq('//', /.*/),
	    seq('/*', /[^*]*\*+([^/*][^*]*\*+)*/, '/')
	),

	// Core tokens converted from yacc %token declarations

	// Comparison operators
	// eq: $ => 'eq',
	// ne: $ => 'ne',
	// gt: $ => 'gt',
	// ge: $ => 'ge',
	// lt: $ => 'lt',
	// le: $ => 'le',
	// TODO: what are the prec rules for these?
	// cmpeq: $ => 'cmpeq',
	// cmpne: $ => 'cmpne',
	// adj: $ => 'adj',
	// notadj: $ => 'notadj',

	// // Logical operators
	// not: $ => 'not',
	// and: $ => 'and',
	// or: $ => 'or',
	// xor: $ => 'xor',

	// // Set operators
	// // in: $ => 'in',
	// notin: $ => 'notin',
	// subset: $ => 'subset',
	// notsubset: $ => 'notsubset',

	// // Arithmetic operators
	// plus: $ => '+',
	// minus: $ => '-',
	// star: $ => '*',
	// div: $ => 'div',
	// mod: $ => 'mod',
	// hat: $ => '^',
	// // TODO: what does ^^ do?
	// // hat_hat: $ => '^^',
	// slash: $ => '/',

	
	_statement: $ => seq(
	    choice(
		$._simple_statement,
		$._compound_statement),
	    ';',
	),

	_simple_statement: $ => choice(
	    $.expression_statement,
	    $.return_statement,
	    $.break_statement,
	    $.continue_statement,
	    $.eval_statement,
	    $.print_statement,
	    $._definition,
	    $._assignment,
		$.where_expression,
	),

	expression_statement: $ => commaSep1($.primary_expression),
	//     // $.assignment
	// ),

	return_statement: $ => seq(
	    "return",
	    // Procedures return nothing, and can only have empty return statements, as an early exit
	    // Functions must have a return statement with an expression (semantic validation)
	    optional($.expression_statement)
	),


	break_statement: $ => seq(
	    prec.left('break'),
	    optional($.identifier)
	),

	continue_statement: $ => seq(
	    prec.left('continue'),
	    optional($.identifier)
	),

	eval_statement: $ => seq(
	    'eval',
	    // can be anything that evaluates to a string!
	    $.primary_expression
	),

	
	print_statement: $ => seq(
	    'print',
	    commaSep1($.expression),
	),

	// MAYBE: consider moving 'not' to separate function
	boolean_statement: $ => choice(
	    $.unary_operator,
	    $.binary_operator,
	),
	
	unary_operator: $ => {
	    const table = [
		['not', PREC.not],
		['-', PREC.negate],
		['~', PREC.tilde]
	    ];
	    // @ts-ignore
	    return choice(...table.map(([operator, precedence]) => prec.right(precedence, seq(
		field('operator', operator),
		field('right', $.expression),
	    ))));
	},
	
	binary_operator: $ => {
	    const table = [
		[prec.left, '+', PREC.plus],
		[prec.left, '-', PREC.plus],
		[prec.left, '*', PREC.times],
		[prec.left, '/', PREC.times],
		[prec.right, '^', PREC.power],
		[prec.left, 'div', PREC.times],
		[prec.left, 'mod', PREC.times],
		[prec.left, '^^', PREC.hathat],
		[prec.left, 'join', PREC.join],
		[prec.left, 'diff', PREC.diff],
		[prec.left, 'sdiff', PREC.sdiff],
		[prec.left, 'meet', PREC.meet],
		[prec.left, 'cat', PREC.meet],
		
	    ];

	    // @ts-ignore
	    return choice(...table.map(([fn, operator, precedence]) => fn(precedence, seq(
		field('left', $.expression),
		// @ts-ignore
		field('operator', operator),
		field('right', $.expression),
	    ))));
	},

	ternary_operator: $ => prec(PREC.ternary, seq(
	    field('conditional', $.primary_expression),
	    'select',
	    field('then', $.expression),
	    'else',
	    field('else', $.expression))
	),

	// TODO: decide if this should be part of binary operator
	comparison_operator: $ => {
	    const table = ['gt', 'ge', 'lt', 'le', 'eq', 'ne', 'cmpeq', 'cmpne'];

	    // @ts-ignore
	    return choice(...table.map((operator) => prec.left(PREC.cmp, seq(
		field('left', $.expression),
		// @ts-ignore
		field('operator', operator),
		field('right', $.expression),
	    ))));
	    
	},

	where_expression: $ => prec.left(PREC.where, seq(
		field('value', $.expression),
		'where',
		field('variables', $.ident_underscore_list),
		field('operator', choice('is', ':=')),
		field('definition', $.expression),
	)),
	
	ident_underscore_list: $ => commaSep1(
		choice($.identifier, '_')
	),
	
	boolean_operator: $ => {
	    const table = [
		['or', PREC.or],
		['xor', PREC.or],
		['and', PREC.and],
	    ];
	    // @ts-ignore
	    return choice(...table.map(([operator, precedence]) => prec.left(precedence, seq(
		field('left', $.expression),
		// @ts-ignore
		field('operator', operator),
		field('right', $.expression),
	    ))));
	},
	
	
	// // Set operations
	// diff: $ => 'diff',
	// sdiff: $ => 'sdiff',
	// meet: $ => 'meet',
	// join: $ => 'join',

	// // Special operators
	// hash: $ => '#',
	// cat: $ => 'cat',
	// tilde: $ => '~',

	// // Delimiters
	// leftangle: $ => '<',
	// rightangle: $ => '>',
	// leftbrace: $ => '{',
	// rightbrace: $ => '}',
	// leftsquare: $ => '[',
	// rightsquare: $ => ']',
	// leftround: $ => '(',
	// rightround: $ => ')',

	// // Special bracket combinations
	// leftbrace_at: $ => '{@',
	// at_rightbrace: $ => '@}',
	// leftbrace_bang: $ => '{!',
	// bang_rightbrace: $ => '!}',
	// leftbrace_star: $ => '{*',
	// star_rightbrace: $ => '*}',
	// leftsquare_star: $ => '[*',
	// star_rightsquare: $ => '*]',

	// // Special symbols
	// arrow: $ => '->',
	// at: $ => '@',
	// atat: $ => '@@',
	// bar: $ => '|',
	// bar_arrow: $ => '|->',
	// becomes: $ => ':=',
	// bang: $ => '!',
	// bang_bang: $ => '!!',
	// colon: $ => ':',
	// colon_colon: $ => '::',
	// comma: $ => ',',
	// dollar: $ => '$',
	// dollar_dollar: $ => '$$',
	// dot: $ => '.',
	// dotdot: $ => '..',
	// dotdotdot: $ => '...',
	// semi: $ => ';',
	// equality: $ => '=',
	// star_star: $ => '**',
	// underscore: $ => '_',
	// undefconst: $ => 'undefined',

	// // Backquotes
	// backquote: $ => '`',
	// backquote_backquote: $ => '``',

	// Keywords - control flow
	// if: $ => 'if',
	// then: $ => 'then',
	// else: $ => 'else',
	// elif: $ => 'elif',
	// end: $ => 'end',
	// while: $ => 'while',
	// do: $ => 'do',
	// repeat: $ => 'repeat',
	// until: $ => 'until',
	// for: $ => 'for',
	// to: $ => 'to',
	// by: $ => 'by',
	// break: $ => 'break',
	// continue: $ => 'continue',
	// return: $ => 'return',
	// case: $ => 'case',
	// when: $ => 'when',
	// default: $ => 'default',

	// // Keywords - functions and procedures
	// function: $ => 'function',
	// func: $ => 'func',
	// procedure: $ => 'procedure',
	// proc: $ => 'proc',
	// forward: $ => 'forward',
	// intrinsic: $ => 'intrinsic',
	// local: $ => 'local',
	// TODO: add local which has syntax:
	// local var1, var2, ... varn;

	// // Keywords - declarations and directives
	// declare: $ => 'declare',
	// TODO: add declare which has syntax:
	// declare attributes X: Y, Z; 
	// declare type T[E]: Supertype;
	// declare verbose fn, lvl;
	
	// clear: $ => 'clear',
	// TODO: clear only appears as "clear;" - implement this
	// load: $ => 'load',
	// iload: $ => 'iload',
	// save: $ => 'save',
	// restore: $ => 'restore',
	// freeze: $ => 'freeze',
	// import: $ => 'import',
	// export: $ => 'export',

	// Keywords - I/O and debugging
	// print: $ => 'print',
	// printf: $ => 'printf',
	// fprintf: $ => 'fprintf',
	// vprint: $ => 'vprint',
	// vprintf: $ => 'vprintf',
	// read: $ => 'read',
	// readi: $ => 'readi',
	// error: $ => 'error',
	// assert: $ => 'assert',
	// assert2: $ => 'assert2',
	// assert3: $ => 'assert3',
	// time: $ => 'time', // TODO: timed_statement?
	// vtime: $ => 'vtime', 

	// // Keywords - special constructs
	// try: $ => 'try',
	// catch: $ => 'catch',
	// where: $ => 'where',
	// // is: $ => 'is',
	// exists: $ => 'exists',
	// forall: $ => 'forall',
	// assigned: $ => 'assigned',
	// delete: $ => 'delete',
	// quit: $ => 'quit',


	// // Reduction operators
	// reduct_plus: $ => '&+',
	// reduct_minus: $ => '&-',
	// reduct_mult: $ => '&*',
	// reduct_and: $ => '&and',
	// reduct_or: $ => '&or',
	// reduct_meet: $ => '&meet',
	// reduct_join: $ => '&join',
	// reduct_cat: $ => '&cat',

	expression: $ => choice(
	    $.primary_expression,
	    $.boolean_operator,
	    $.comparison_operator,
	    $.where_expression,
	),

	parenthesized_expression: $ => prec(
	    PREC.parenthesized_expression,
	    seq(
		'(',
		$.expression,
		')'
	    )),
	// TODO: the expression (1,2) can mean permuation group cycle; implement this!
	
	primary_expression: $ => choice(
	    $.identifier,
	    $.integer,
	    $.real,
	    $.string,
	    $.binary_operator,
	    $.unary_operator,
	    $.ternary_operator,
	    $.true,
	    $.false,
	    $.call,
	    $.double_dollar,		// MAYBE: should this really be here?
	    $.parenthesized_expression, // should this really be here?
	),
	
	true: _ => 'true',
	false: _ => 'false',
	
	expression_list: $ => 'placeholder_expr_list',

	// TODO: add anonymous func's and proc's
	// TODO: add foo := procedure, bar := function
	
	_definition: $ => choice(
	    $.function_definition,
	    $.intrinsic_definition,
	    $.procedure_definition,
	),

	// TODO: functions should always have return statements!
	// But this might not be the parser's job to enforce
	// Difficult to implement because it might appear in the middle of `body`
	
	// Function definition - semantic validation should ensure it has a return statement with expression
	function_definition: $ => seq(
	    choice(
		seq('function', field('name', $.identifier)),
		seq(field('name', $.identifier), ':=', 'function')
	    ),
	    field('arguments', $.argument_list),
	    field('body', $.block),
	    'end function',
	),

	// TODO: enable early exits via empty return statements
	procedure_definition: $ => seq(
	    choice(
		seq('procedure', field('name', $.identifier)),
		seq(field('name', $.identifier), ':=', 'procedure')
	    ),
	    field('arguments', $.argument_list),
	    optional(field('body', $.block)),
	    'end procedure',
	),

	// TODO: it must have a return statement it has a return type!
	intrinsic_definition: $ => seq(
	    'intrinsic',
	    field('name', $.identifier),
	    field('arguments', $.argument_list),
	    '->',
	    optional(field('return_type', $.type)),
	    field('docstring',
		  seq('{',
		      /[^{}]*/,	// matches anything that's not a squirly brace
		      '}')),
	    optional(field('body', $.block)),
	    'end intrinsic'
	),

	call: $ => prec(PREC.call, seq(
	    field('function', $.primary_expression),
	    field('arguments', $.argument_list),
	)),

	argument_list: $ => seq(
	    '(',
	    optional(commaSep1(field('argument', $.expression))),
	    optional($._optional_argument_list),
	    ')',
	),
	
	_optional_argument_list: $ => seq(
	    ':',
	    commaSep1(
		field('optional_argument', seq(
		    $.identifier,
		    ':=',
		    field('default_value', $.primary_expression))))),

	_assignment: $ => choice(
	    $.assignment,
	    $.augmented_assignment
	),
	
	assignment: $ => seq(
	    field('left', $._left_hand_side),
	    ':=',
	    field('right', $._right_hand_side),
	),

	// TODO: Refactor to make use of all binary operators
	// we can use the operators
	// join, meet, diff, sdiff, cat, *, +, -, /, ^, div, mod, and, or, xor
	// 
	augmented_assignment: $ => seq(
	    field('left', $.primary_expression),
	    choice(
		// TODO: Find out if there are more options here like in python!
		'+:=',
		'-:=',
		'*:=',
		'/:=',
		'and:=',
		'or:=',
		'div:='
	    ),
	    field('right', $.expression),
	),

	_left_hand_side: $ => commaSep1(
	    choice(
		$.primary_expression, // TODO: is this too general?
		$.gen_expression,
		'_'
	    )),

	_right_hand_side: $ => commaSep1($.expression),

	gen_expression: $ => seq(
	    choice($.identifier, '_'),
	    '<',
	    commaSep1($.identifier),
	    '>'
	),

	// TODO: What about square brackets?
	type: $ => choice(
	    $.identifier,
	    '.',
	),
	// TODO: should this be token.immediate?
	typed_identifier: $ => seq(
	    $.identifier,
	    "::",
	    $.type,
	),
	


	// Control flow
	_compound_statement: $ => choice(
	    $.if_statement,
	    $.for_statement,
	    $.while_statement,
	    $.case_statement,
	    $.repeat_statement
	),
	
	if_statement: $ => seq(
	    'if',
	    field('condition', $.expression),
	    'then',
	    field('consequence', $.block),
	    repeat(field('alternative', $.elif_clause)),
	    optional(field('alternative', $.else_clause)),
	    'end if'
	),

	elif_clause: $ => seq(
	    'elif',
	    field('condition', $.expression),
	    'then',
	    field('consequence', $.block),
	),

	else_clause: $ => seq(
	    'else',
	    field('consequence', $.block),
	),

	
	for_statement: $ => seq(
	    'for',
	    field('quantifier', $.for_quantifier),
	    'do',
	    field('body', $.block),
	    'end for'
	),

	for_quantifier: $ => choice(
	    seq($.identifier,
		':=', $.primary_expression,
		'to', $.primary_expression,
		optional(seq('by', $.primary_expression))
	       ),
	    seq(
		optional('random'),
		$.identifier,
		optional(seq('->', $.identifier)),
		'in',
		$.primary_expression),
	),
	// needs to take into account all the variations in
	// https://magma.maths.usyd.edu.au/magma/handbook/text/13#86
				     
	while_statement: $ => seq(
	    'while',
	    field('condition', $.expression),
	    'do',
	    field('body', $.block),
	    'end while',
	),
	
	repeat_statement: $ => seq(
	    'repeat',
	    field('body', $.block),
	    'until',
	    field('condition', $.expression),
	),
	

	// MAYBE: consider renaming "matchee"
	case_statement: $ => seq(
	    'case',
	    field('matchee', $.primary_expression),
	    ':',
	    repeat1($.when_clause),
	    'end case',
	),

	when_clause: $ => seq(
	    'when',
	    field('match', $.primary_expression),
	    ':',
	    field('consequence', $.block)
	),

	// Misc:
	// MAYBE: rename this to parent_function or something?
	double_dollar: $ => prec.left(
	    PREC.dollar, seq("$$", $.argument_list)),
	
	
	// Basic tokens:
	
	identifier: $ => /[a-zA-Z_][a-zA-Z0-9_]*/,
	block: $ => repeat1($._statement),
	// TODO: add all the sequence functionality from https://magma.maths.usyd.edu.au/magma/handbook/text/116#949
	sequence: $ => seq(
	    choice('[', '\['),
	    optional(commaSep1($.primary_expression)),
	    ']'
	),
	    
	
	// AI generated, hopefully works as intended
	string: $ => /"[^"\\]*(?:\\.[^"\\]*)*"/,

	integer: $ => /\d+/,
	// TODO: implement scanner to allow scientific notation
	real: $ => /\d+\.\d+/,
	// /\d+[\.\d+]?[eE][+-]?\d+/,
	
    },

});


// Stolen from tree-sitter-python:
/**
 * Creates a rule to match one or more of the rules separated by a comma
 *
 * @param {RuleOrLiteral} rule
 *
 * @return {SeqRule}
 *
 */
function commaSep1(rule) {
    return sep1(rule, ',');
}

/**
 * Creates a rule to match one or more occurrences of `rule` separated by `sep`
 *
 * @param {RuleOrLiteral} rule
 *
 * @param {RuleOrLiteral} separator
 *
 * @return {SeqRule}
 *
 */
function sep1(rule, separator) {
    return seq(rule, repeat(seq(separator, rule)));
}


