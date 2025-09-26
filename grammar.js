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
	parenthesis: 33, 		 // TOK_LEFTROUND                   (left)
	backquote: 34,           // TOK_BACKQUOTE TOK_BACKQUOTE_BACKQUOTE (left)
	call: 35                 // function application; keep as top-most
};

const MAPS = [
    'hom', 'map', 'pmap', 'iso',
]

const CONSTRUCTORS = [
    'ideal', 'lideal', 'rideal', 'case', 'quo', 'sub', 'ext','ncl', 'elt', 'cop',
    'Group', 'AbelianGroup', 'MatrixGroup', 'PolycyclicGroup', 'PermutationGroup', 'FPGroup',  
    'Semigroup', 'Monoid',
    'func', 'proc'
]

// TODO: add line continuation character: \ // Is this necessary?
// TODO: move expression tests to new test file
// TODO: add ext, quo, ideal etc.
// TODO: add random in front of enumerated structures, cf paragraph before H10E8
// TODO: add exists/forall in front of enumerated structures, cf H10E12

// MAYBE: should this be at the bottom like the other helper functions?

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
	$.parameter
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
	    $.print_statement,
	    $.assert_statement,
	    $._definition,
	    $._assignment,
	    $.where_expression,
	    $.try_catch_statement,
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

	// TODO: eval actually works like an expression:
	// (eval "1 + 2") + eval "3"; // returns 6.
	// I don't immediately see a clean way to handle this,
	// since
	// eval "1 + 2" + eval "3"; // Errors
	// but currently it parses just fine

	eval_expression: $ => prec.left(PREC.eval, seq(
	    'eval',
	    // can be anything that evaluates to a string!
	    $.primary_expression)
	),

	print_statement: $ => seq(
	    'print',
	    commaSep1($.expression),
	),

	assert_statement: $ => seq(
	    /assert[12]*/,
	    $.expression,
	),


	try_catch_statement: $ => seq(
	    'try',
	    $.block,
	    'catch',
	    field('error', $.identifier),
	    $.block,
	    'end try',
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
		['~', PREC.tilde],
		['#', PREC.hash],
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
		[prec.left, '@', PREC.at],
		[prec.left, '@@', PREC.at],
		[prec.right, '!', PREC.bang],
		[prec.right, '!!', PREC.bang],
		[prec.left, '.', PREC.dot],
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
	    field('variables', commaSep1(choice($.identifier, $.anonymous_identifier))),
	    field('operator', choice('is', ':=')),
	    field('definition', $.expression),
	)),
	
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
	    $.where_expression,	// MAYBE: Should this be a primary expression?
	    $.eval_expression
	),

	parenthesized_expression: $ => prec(
	    PREC.parenthesized_expression,
	    seq(
		'(',
		$.expression,
		')'
	    )),

	// TODO: the expression (1,2) can mean permuation group cycle; implement this!
	// NB: It can also mean commutator! cf Chapter 70 of the documentation pdf
	
	primary_expression: $ => choice(
	    $.identifier,
	    $.integer,
	    $.real,
	    $.string,
	    $.binary_operator,
	    $.unary_operator,
	    $.ternary_operator,
	    $.attribute,
	    $.map,
	    $.seq_slice,
	    $.true,
	    $.false,
	    $.call,
	    $.double_dollar,		// MAYBE: should this really be here?
	    $.parenthesized_expression, // should this really be here?
	    $.literal_sequence,
	    $.aggregate,
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

	// Function definition - semantic validation should ensure it has a return statement with expression
	function_definition: $ => seq(
	    choice(
		seq('function', field('name', $.identifier)),
		seq(field('name', $.identifier), ':=', 'function')
	    ),
	    field('parameters', $.parameters),
	    field('body', $.block),
	    'end function',
	),
	
	procedure_definition: $ => seq(
	    choice(
		seq('procedure', field('name', $.identifier)),
		seq(field('name', $.identifier), ':=', 'procedure')
	    ),
	    field('parameters', $.parameters),
	    optional(field('body', $.block)),
	    'end procedure',
	),
    
	parameters: $ => seq(
	    '(',
	    optional(commaSep1($.parameter)),
	    optional(seq(
		':',
		commaSep1($.optional_parameter))),
	    ')'
	),

	// TODO: technically, this is not valid syntax for e.g. functions;
	// can only pass typed identifiers to intrinsics, and only identifiers to functions
	// but for simplicity we count this as a semantic and not syntactic difference
	parameter: $ => choice(
	    $.identifier,
	    $.typed_identifier,
	    $.ref_identifier
	),

	ref_identifier: $ => seq(
	    '~',
	    $.identifier,
	),
	
	// TODO: should this be token.immediate?
	typed_identifier: $ => seq(
	    $.identifier,
	    "::",
	    $._type,
	),

	optional_parameter: $ => seq(
	    field('name', $.identifier),
	    ':=',
	    field('value', $.primary_expression)
	),
	
	intrinsic_definition: $ => seq(
	    'intrinsic',
	    field('name', $.identifier),
	    field('parameters', $._intrinsic_parameters),
	    optional(seq('->', field('return_type', $._type))),
	    field('docstring',
		  seq('{',
		      /[^{}]*/,	// matches anything that's not a squirly brace
		      '}')),
	    optional(field('body', $.block)),
	    'end intrinsic'
	),
	
	_intrinsic_parameters: $ => seq(
	    '(',
	    optional(commaSep1($._intrinsic_parameter)),
	    optional(seq(
		':',
		commaSep1($.optional_parameter))),
	    ')'
	),

	_intrinsic_parameter: $ => choice(
	    $.identifier,
	    seq('~', $.identifier),
	    $.typed_identifier
	),


	call: $ => prec(PREC.call, seq(
	    field('function', $.primary_expression),
	    field('arguments', $.argument_list),
	)),

	argument_list: $ => seq(
	    '(',
	    optional(commaSep1(field('argument', $.primary_expression))),
	    optional(seq(
		':',
		commaSep1($.optional_argument))),
	    ')',
	),
	
	_optional_argument_list: $ => seq(
	    ':',
	    commaSep1($.optional_argument)),

	optional_argument: $ => seq(
	    field('argument', $.identifier),
	    ':=',
	    field('default_value', $.primary_expression)),

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
		$.anonymous_identifier
	    )),

	_right_hand_side: $ => commaSep1($.expression),

	gen_expression: $ => seq(
	    choice($.identifier, '_'),
	    '<',
	    commaSep1($.identifier),
	    '>'
	),

	// TODO: What about square brackets?
	// should include anything described here:
	// https://magma.maths.usyd.edu.au/magma/handbook/text/24
	_type: $ => choice(
	    $.identifier,
	    '.',
	),

	attribute: $ => choice(
	    $._backquote,
	    $._double_backquote
	),
	
	_backquote: $ => seq(
	    prec.left(PREC.backquote, seq(
		$.primary_expression,
		'`',
		$.identifier))
	),

	_double_backquote: $ => seq(
	    prec.left(PREC.backquote, seq(
		$.primary_expression,
		'``',
		$.expression))
	),

	// Maps
	// TODO: pmap can also take 
	map: $ => {
	    return choice(...MAPS.map((name) => seq(
		name,
		'<',
		field('domain', $.primary_expression),
		'->',
		field('codomain', $.primary_expression),
		'|',
		field('map_constructor', $._map_constructor),
		'>',
	    )));
	},

	// TODO: this should probably be changed, but the naive solution runs into
	// parsing errors.
	// In particular, right now it's technically legal to do things like
	// map< A -> B | x, y -> z>;
	// which probably isn't valid
	_map_constructor: $ => commaSep1(
	    seq(
		optional(seq(field('domain_element', $.identifier), ':->')),
		field('image', $.primary_expression))
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

	// TODO: clean up structure of tokens here
	for_quantifier: $ => choice(
	    seq($.identifier,
		':=', field('from', $.primary_expression),
		'to', field('to', $.primary_expression),
		optional(seq(
		    'by', field('by', $.primary_expression)))
	       ),
	    seq(
		optional('random'),
		optional(seq(
		    field('index', $.identifier),
		    '->')),
		field('element', $.identifier),
		'in',
		field('parent', $.primary_expression)),
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
	
	// DONE: fix regex such that "_" by itself is not a valid identifier
	identifier: $ => /[_]*[a-zA-Z][a-zA-Z0-9_]*/,
	anonymous_identifier: $ => '_',
	block: $ => repeat1($._statement),

	// Aggregates
	
	// TODO: add all the aggregate functionality from https://magma.maths.usyd.edu.au/magma/handbook/text/116#949
	// TODO: add formal sequences
	// Literal sequence \[ 1, 2, 3 ], no expressions allowed
	literal_sequence: $ => seq(
	    '\\[',
		optional(commaSep1($.integer)),
	    ']'
	),

	seqenum: $ => aggregate_of($, '[', ']', true),
	list: $ => aggregate_of($, '[*', '*]', false),
	tuple: $ => aggregate_of($, '<', '>', false),
	set: $ => aggregate_of($, '{', '}', true),
	indexed_set: $ => aggregate_of($, '{@', '@}', true),
	multiset: $ => aggregate_of($, '{*', '*}', true),
	aggregate: $ => choice(
		$.seqenum, $.list, $.tuple, $.set, $.indexed_set, $.multiset
	),

	seq_slice: $ => prec.left(PREC.sq_bracket, seq(
	    field('parent', $.primary_expression),
	    commaSep1($.seqenum))
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
   // Function sets: {!1, 2, 3!}
	    seq(
		'{!',
		optional(commaSep1($.primary_expression)),
		'!}'
	    )
	),
 * @return {SeqRule}
 *
 */
function sep1(rule, separator) {
    return seq(rule, repeat(seq(separator, rule)));
}

// // Possible choices of parameters for {function, procedure, intrinsic}
// function parameter_choices($, def_type)  {
//     switch (def_type) {
//     case 'function':
// 	return $.identifier;
//     case 'procedure':
// 	return choice($.identifier, $.ref_identifier);
//     case 'intrinsic':
// 	return choice($.identifier, $.ref_identifier, $.typed_identifier);
//     }
// }

// TODO: add option to support trailing comma
function aggregate_of($, left, right, has_universe) {
	return seq(
		left,
		optional(has_universe ? seq(
			field('universe', $.primary_expression),
			'|'
		) : seq()),
		optional(commaSep1($.primary_expression)),
		right
	);
}

