module.exports = grammar({
    name: 'magma',

    extras: $ => [
	/\s/,           // whitespace
	$.comment,      // comments
    ],

    rules: {
	// Program is the root rule - can contain statements, directives, intrinsics, or declarations
	// TODO: every expression should end with semicolon unless otherwise specified - can this be done top level?
	program: $ => choice(
	    repeat(choice(
		$.expression,
		// $.statement,
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
	
	string_literal: $ => choice(
	    seq('"', repeat(choice(/[^"\\]/, /\\./)), '"'),
	    // seq("'", repeat(choice(/[^'\\]/, /\\./)), "'")
	),


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

	expression: $ => seq(
	    choice(
		$._definition,
		$.assignment,
		$.identifier,
	    ),
	    ';'
	),
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
	    field('return_type', $.identifier),
	    field('docstring',
		  seq('{',
		      /[^{}]*/,	// matches anything that's not a squirly brace
		      '}')),
	    optional(field('body', $.block)),
	    'end intrinsic'
	),
	
	argument_list: $ => seq(
	    '(',
	    optional(commaSep1(
		$.identifier
		)),
	    ')',
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
	// TODO: update 
	_left_hand_side: $ => commaSep1(
	    choice(
		$.identifier,
		$.gen_expression,
		'_'
	    )),

	_right_hand_side: $ => $.expression,

	gen_expression: $ => seq(
	    $.identifier,
	    '<',
	    commaSep1($.identifier),
	    '>'
	),

	typed_identifier: $ => seq(
	    field('identifier', $.identifier),
	    '::',
	    field('type', $.identifier)
	),

	// TODO: we can have more things probably

	identifier: $ => /[a-zA-Z_][a-zA-Z0-9_]*/,
	block: $ => repeat1($.expression),
	string: $ => seq(
	    '"',
	    /[a-zA-Z_][a-zA-Z0-9_]*/,
	    '"'
	),
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
