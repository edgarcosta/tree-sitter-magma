// precedence table
// TODO: fill this in with details from 
// https://github.com/edgarcosta/tree-sitter-magma/blob/95816b192272e8d4eb6d986f18a2741476b26269/grammar-docs/precedence.md
const PREC = {
    parenthesized_expression: 1,
    eval: 2,
    where: 3,
    eq: 4,
    ternary: 5,
    hathat: 6,
    or: 7,
    and: 8,
    not: 9,
    cmp: 10,
    membership: 11,
    join: 12,
    diff: 13,
    sdiff: 14,
    meet: 15,
    plus: 16,
    times: 17,
    tilde: 18,
    cat: 19,
    negate: 20,
    power: 21,
    coercion: 22,
    at: 23,
    dot: 24,
    dollar: 25,
    reduct: 26,
    hash: 27,
    assigned: 28,
    sq_bracket: 29,
    parenthesis: 30,
    backquote: 31,
    // TODO: what does double backquote mean?
    call: 32,
};


module.exports = grammar({
    name: 'magma',

    extras: $ => [
	/\s/,           // whitespace
	$.comment,      // comments
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
	$._simple_statement
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
	    $._compound_statement,
	    ),
	    ';',
	),

	_simple_statement: $ => choice(
	    $.expression_statement,
	    $.return_statement,
	    $._definition,
	    $._assignment,
	),

	expression_statement: $ => choice(
	    $.expression,
	    // $.assignment
	),

	_compound_statement: $ => "placeholder",

	return_statement: $ => seq(
	    "return",
	    // TODO: can this be optional?
	    $.expression
	),

	// TODO: includes 'not', '-', '~' ..?
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
		[prec.left, '//', PREC.times],
		[prec.right, '^', PREC.power],
		[prec.left, 'div', PREC.times],
		[prec.left, 'rem', PREC.times],
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

	// TODO: implement ternary operators
	ternary_operator: $ => "placeholder",

	// TODO: decide if this should be part of binary operator
	comparison_operator: $ => {
	    const table = [
		['gt'],
		['ge'],
		['lt'],
		['le'],
		['eq'],
		['ne'],
		['cmpeq'],
		['cmpne'],
	    ];

	    // @ts-ignore
	    return choice(...table.map(([operator]) => prec.left(PREC.cmp, seq(
		field('left', $.expression),
		// @ts-ignore
		field('operator', operator),
		field('right', $.expression),
	    ))));
	    
	},
	// TODO: same as above
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

	// // Keywords - declarations and directives
	// declare: $ => 'declare',
	// clear: $ => 'clear',
	// load: $ => 'load',
	// iload: $ => 'iload',
	// save: $ => 'save',
	// restore: $ => 'restore',
	// freeze: $ => 'freeze',
	// import: $ => 'import',
	// export: $ => 'export',

	// Keywords - I/O and debugging
	print: $ => 'print',
	printf: $ => 'printf',
	fprintf: $ => 'fprintf',
	vprint: $ => 'vprint',
	vprintf: $ => 'vprintf',
	read: $ => 'read',
	readi: $ => 'readi',
	error: $ => 'error',
	assert: $ => 'assert',
	assert2: $ => 'assert2',
	assert3: $ => 'assert3',
	time: $ => 'time',
	vtime: $ => 'vtime',

	// // Keywords - special constructs
	// try: $ => 'try',
	// catch: $ => 'catch',
	// where: $ => 'where',
	// // is: $ => 'is',
	// exists: $ => 'exists',
	// forall: $ => 'forall',
	// select: $ => 'select',
	// eval: $ => 'eval',
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

	// // Boolean literals
	// bool_true: $ => 'true',
	// bool_false: $ => 'false',

	// Literals
	// integer_literal: $ => /\d+/,
	
	// real_literal: $ => /\d+\.\d+([eE][+-]?\d+)?/,
	


	// Sequence and cycle literals (simplified for now)
	sequence_literal: $ => seq('[', optional($.expression_list), ']'),
	cycle_literal: $ => seq('(', $.expression_list, ')'),

	// Basic structure placeholders - will be implemented in later tasks
	// statement: $ => choice(
	//     $.normal_statement,
	//     seq($.time, $.normal_statement),
	//     seq($.vtime, $.identifier, optional(seq($.comma, $.expression)), $.colon, $.normal_statement)
	// ),

	// normal_statement: $ => choice(
	//   $.semi,  // null statement
	//   'placeholder_statement'  // placeholder for other statements
	// ),

	// directive: $ => choice(
	//     seq($.clear, $.semi),
	//     seq($.load, $.directive_string, $.semi),
	//     seq($.iload, $.directive_string, $.semi),
	//     seq($.save, $.directive_string, $.semi),
	//     seq($.restore, $.directive_string, $.semi),
	//     seq($.freeze, $.semi)
	// ),

	// directive_string: $ => choice(
	//     $.string_literal,
	//     $.identifier
	// ),

	// declaration: $ => choice(
	//     seq($.declare),

	//     opt_elt_t: $ => seq($.leftsquare, $.identifier, $.rightsquare),

	//     identifier_list: $ => seq($.identifier, repeat(seq($.comma, $.identifier))),

	//     intrinsic: $ => seq(
	// 	$.intrinsic,
	// 	$.identifier,
	// 	$.leftround,
	// 	'placeholder_intrinsic_args',
	// 	$.rightround,
	// 	'placeholder_intrinsic_opt'
	//     ),

	// literal: $ => choice(
	//     $.integer_literal,
	//     $.real_literal,
	//     $.string_literal,
	//     $.bool_true,
	//     $.bool_false,
	//     $.sequence_literal,
	//     $.cycle_literal
	// ),

	// TODO: should differentiate between expression and statement
	expression: $ => choice(
	    $.primary_expression,
	    $.boolean_operator,
	    $.comparison_operator,
	),

	primary_expression: $ => choice(
	    $.identifier,
	    $.integer,
	    $.real,
	    $.string,
	    $.binary_operator,
	    $.unary_operator,
	    $.true,
	    $.false,
	    $.call,
	),
	
	true: _ => 'True',
	false: _ => 'False',
	
	expression_list: $ => 'placeholder_expr_list',

	// TODO: add anonymous func's and proc's
	// TODO: add procedures
	
	_definition: $ => choice(
	    $.function_definition,
	    $.intrinsic_definition,
	),

	// TODO: prevent functions from being wrapped in expressions
	
	function_definition: $ => seq(
	    // TODO: Can this be capitalized?
	    'function',
	    field('name', $.identifier),
	    field('arguments', $.argument_list),
	    optional(field('body', $.block)),
	    'end function',
	),

	intrinsic_definition: $ => seq(
	    'intrinsic',
	    field('name', $.identifier),
	    field('arguments', $.argument_list),
	    '->',
	    field('return_type', $.type),
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
	
	// TODO: this should be expression
	argument_list: $ => seq(
	    '(',
	    optional(commaSep1(
		$.expression
		)),
	    ')',
	),

	_assignment: $ => choice(
	    $.assignment,
	    $.augmented_assignment
	),
	
	assignment: $ => seq(
	    field('left', $._left_hand_side),
	    ':=',
	    field('right', $._right_hand_side),
	),
	
	augmented_assignment: $ => seq(
	    field('left', $._left_hand_side),
	    choice(
		// TODO: Find out if there are more options here like in python!
		'+:=',
		'-:=',
		'*:=',
		'/:=',
	    ),
	    field('right', $._right_hand_side),
	),

	_left_hand_side: $ => commaSep1(
	    choice(
		$.identifier, // TODO: can probably be a primary expression? e.g. F[1] = ...
		$.gen_expression,
		'_'
	    )),

	_right_hand_side: $ => commaSep1($.expression),

	gen_expression: $ => seq(
	    $.identifier,
	    '<',
	    commaSep1($.identifier),
	    '>'
	),

	// TODO: What about square brackets?
	type: $ => choice(
	    $.identifier,
	    '.',
	),
	typed_identifier: $ => seq(
	    $.identifier,
	    "::",
	    $.type,
	),
	
	identifier: $ => /[a-zA-Z_][a-zA-Z0-9_]*/,
	block: $ => repeat1($._statement),
	string: $ => seq(
	    '"',
	    /[a-zA-Z0-9_]*/,
	    '"'
	),
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
