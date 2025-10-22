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
	backquote: 34,           // TOK_BACKQUOTE TOK_BACKQUOTE_BACKQUOTE (left)
	call: 35                 // function application; keep as top-most
};


module.exports = grammar({
    name: 'magma',

    extras: $ => [
	// whitespace & line continuation (taken from https://github.com/tree-sitter/tree-sitter-c/blob/master/grammar.js)
	/\s|\\\r?\n/,       
	$.comment,
    ],
    // word: $ => $.identifier,
    
    conflicts: $ => [
	[$.expression_statement, $.assignment],
	[$.map, $.identifier],
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
	$.parameter,
    ],

    
    inline: $ => [
	// $._map_keyword,
	$._simple_statement,
	$._compound_statement,
	$._left_hand_side,
	// $._right_hand_side,
    ],

    externals: $ => [
	$.real,
    ],
    
    rules: {
	program: $ => choice(
	    repeat(choice(
		// $.expression,
		$._statement,
	    )),
	    seq()
	),
	
	// Comments
	// taken from
	// https://github.com/tree-sitter/tree-sitter-c/blob/master/grammar.js
	comment: _ => token(choice(
	    seq('//', /(\\+(.|\r?\n)|[^\\\n])*/),
	    seq(
		'/*',
		/[^*]*\*+([^/*][^*]*\*+)*/,
		'/',
	    ),
	)),

	_statement: $ => seq(
	    choice(
		seq(choice(
		    $._simple_statement,
		    $._compound_statement),
		    repeat1(';')),
		$.intrinsic_definition,
		// intrinsic definitions don't need ;
	    )
	),

	_simple_statement: $ => choice(
	    $.expression_statement,
	    $.return_statement,
	    $.break_statement,
	    $.continue_statement,
	    $.print_statement,
	    $.vprint_statement,
	    $.read_statement,
	    $.time_statement,
	    $.vtime_statement,
	    $.assert_statement,
	    $.require_statement,
	    $.declare_statement,
	    $.local_statement,
	    $._assignment,
	    $._directive,
	    $.error_statement,
	),

	expression_statement: $ => commaSep1(choice(
	    $.primary_expression, $.print_level_statement)),

	return_statement: $ => seq(
	    "return",
	    // Procedures return nothing, and can only have empty return statements, as an early exit
	    // Functions must have a return statement with an expression (semantic validation)
	    optional(commaSep1($.expression))
	),


	break_statement: $ => seq(
	    prec.left('break'),
	    optional($.identifier)
	),

	continue_statement: $ => seq(
	    prec.left('continue'),
	    optional($.identifier)
	),

	// eval actually works like an expression:
	// (eval "1 + 2") + eval "3"; // returns 6.
	// Note that
	// eval "1 + 2" + eval "3"; // Errors
	// but currently it parses just fine

	eval_expression: $ => prec.left(PREC.eval, seq(
	    'eval',
	    // can be anything that evaluates to a string!
	    // Also, can be used with round brackets
	    $.primary_expression
	)),

	print_statement: $ => seq(
	    choice('print', 'printf', 'fprintf'),
	    commaSep1(choice($.primary_expression, $.print_level_statement))
	),

	vprint_statement: $ => seq(
	    choice('vprint', 'vprintf'),
	    field('flag', $.identifier),
	    optional(seq(',', field('n', $.primary_expression))),
	    ':',
	    commaSep1(choice($.primary_expression, $.print_level_statement))
	),

	read_statement: $ => seq(
	    choice('read', 'readi'),
	    field('identifier', $.identifier),
	    ',',
	    optional(field('prompt', $.primary_expression))
	),

	print_level_statement: $ => seq(
	    $.primary_expression,
	    ':',
	    choice('Default' , 'Maximal', 'Minimal', 'Magma', 'Hex', 'Latex')
	),
	

	assert_statement: $ => seq(
	    choice('assert', 'assert2', 'assert3'),
	    $.expression,
	),

	require_statement: $ => choice(
	    $._require,
	    $._require_cond
	),

	_require: $ => seq(
	    'require',
	    $.expression,
	    ':',
	    commaSep1($.expression),
	),
	
	_require_cond: $ => seq(
	    choice('requirege', 'requirerange'),
	    commaSep1($.primary_expression)
	),

	time_statement: $ => seq(
	    'time',
	    // _statement requires a semicolon, so using it here would require two!
	    choice($._simple_statement, $._compound_statement)
	),

	vtime_statement: $ => seq(
	    'vtime',
	    $.expression,
	    field('flag', $.identifier),
	    optional(seq(',', field('n', $.integer))),
	    ':',
	    choice($._simple_statement, $._compound_statement)
	),
	
	
	declare_statement: $ => seq(
	    'declare',
	    choice(
		$.attribute_declaration,
		$.type_declaration,
		$.verbosity_declaration,
	    )
	),

	// MAYBE: should these be directives? Doesn't affect parsing directly, unless we can access _directive token
	local_statement: $ => seq(
	    'local',
	    commaSep1($.expression),
	),
	
	attribute_declaration: $ => seq(
	    'attributes',
	    field('category', $.identifier),
	    ':',
	    field('attribute',
		commaSep1($.identifier))
	),

	type_declaration: $ => seq(
	    'type',
	    $.type,
	    optional(seq(
		':', commaSep1(field('supertype', $.identifier))))
	),

	verbosity_declaration: $ => seq(
	    'verbose',
	    field('function', $.identifier),
	    ',',
	    field('level', $.integer)
	),

	try_catch_statement: $ => seq(
	    'try',
	    $.block,
	    'catch',
	    field('error', $.identifier),
	    optional(';'),
	    optional($.block),
	    'end',
	    'try',
	),

	error_statement: $ => seq(
	    'error',
	    choice(
		commaSep1($.expression),
		seq('if',
		    field('condition', $.expression),
		    ',',
		    commaSep1($.expression)))
	),

	// MAYBE: consider moving 'not' to separate function
	
	unary_operator: $ => {
	    const table = [
		['not', PREC.not],
		['-', PREC.negate],
		['+', PREC.negate],
		['~', PREC.tilde],
		['#', PREC.hash],
		['assigned', PREC.assigned],
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
		[prec.left, '~', PREC.tilde],
		[prec.left, 'div', PREC.times],
		[prec.left, 'mod', PREC.times],
		[prec.left, '^^', PREC.hathat],
		[prec.left, 'join', PREC.join],
		[prec.left, 'diff', PREC.diff],
		[prec.left, 'sdiff', PREC.sdiff],
		[prec.left, 'meet', PREC.meet],
		[prec.left, 'cat', PREC.cat],
		[prec.left, '@', PREC.at],
		[prec.left, '@@', PREC.at],
		[prec.right, '!', PREC.bang],
		[prec.right, '!!', PREC.bang],
		[prec.left, '.', PREC.dot],
		[prec.left, 'in', PREC.membership],
		[prec.left, 'notin', PREC.membership],
		[prec.left, 'adj', PREC.membership],
		[prec.left, 'notadj', PREC.membership],
		[prec.left, 'subset', PREC.membership],
		[prec.left, 'notsubset', PREC.membership],
		[prec.left, 'gt', PREC.cmp],
		[prec.left, 'ge', PREC.cmp],
		[prec.left, 'lt', PREC.cmp],
		[prec.left, 'le', PREC.cmp],
		[prec.left, 'eq', PREC.cmp],
		[prec.left, 'ne', PREC.cmp],
		[prec.left, 'cmpeq', PREC.cmp],
		[prec.left, 'cmpne', PREC.cmp],
	    ];

	    // @ts-ignore
	    return choice(...table.map(([fn, operator, precedence]) => fn(precedence, seq(
		field('left', $.expression),
		// @ts-ignore
		field('operator', operator),
		field('right', $.expression),
	    ))));
	},
	
	group_relation : $ => prec.left(PREC.eq, seq(
	    field('left', $.expression),
	    '=',
	    field('right', $.expression)
	)),
	
	ternary_operator: $ => prec(PREC.ternary, seq(
	    field('conditional', $.primary_expression),
	    'select',
	    field('then', $.expression),
	    'else',
	    field('else', $.expression))
	),

	reduct_operator: $ => {
	    const table = ['+', '-', '*', 'and', 'or', 'meet', 'join', 'cat'];

	    // @ts-ignore
	    return choice(...table.map((sym) => prec.left(PREC.reduct, seq(
		field('operator', '&'+ sym),
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


	// // Keywords - functions and procedures

	// --- Directives ---
	_directive: $ => choice(
	    $.clear,
	    $.freeze,
	    $.forward,
	    $.delete,
	    $.exit_directive,
	    $.load_directive,
	    $.save_directive,
	    $.import_directive,
	),
	
	// should only appear alone:
	clear: $ => 'clear',
	freeze: $ => 'freeze',
	exit_directive: $ => seq(choice('quit', 'exit'), optional($.primary_expression)),
	
	forward: $ => seq(
	    'forward',
	    commaSep1($.identifier)
	),

	delete: $ => seq(
	    'delete',
	    commaSep1($.primary_expression)
	),

	load_directive: $ => seq(
	    choice('load', 'iload'),
	    choice($.string, $.identifier),
	),

	save_directive: $ => seq(
	    choice('save', 'restore'),
	    $.string
	),

	import_directive: $ => seq(
	    'import',
	    optional('!'), 
	    field('filename', $.string),
	    ':',
	    field('variable', commaSep1($.identifier))
	),

	// --- Expressions ---

	expression: $ => choice($.primary_expression,
				$.eval_expression),
				

	parenthesized_expression: $ => prec(
	    PREC.parenthesized_expression,
	    seq(
		'(',
		$.expression,
		')'
	    )),

	primary_expression: $ => choice(
	    $.identifier,
	    $.anonymous_identifier,
	    $.integer,
	    $.real,
	    $.string,
	    $.binary_operator,
	    $.unary_operator,
	    $.ternary_operator,
	    $.reduct_operator,
	    $.boolean_operator,
	    $.attribute,
	    $.map,
	    $._constructors,
	    $.seq_slice,
	    $.true,
	    $.false,
	    $.call,
	    $.dollar,
	    $.double_dollar,		// MAYBE: should this really be here?
	    $.parenthesized_expression, // should this really be here?
	    $.where_expression,	// This should definitely be here
	    $.aggregate,
	    $._set_operator,
	    $.group_relation,
	    $._definition,	
	),

	
	true: _ => 'true',
	false: _ => 'false',
	
	_definition: $ => choice(
	    $.function_definition,
	    // $.intrinsic_definition,
	    $.procedure_definition,
	),

	// Function definition - semantic validation should ensure it has a return statement with expression
	function_definition: $ => seq(
	    // choice(
	    'function',
	    optional(field('name', $.identifier)),
		// seq(field('name', $.identifier), ':=', 'function')
	    // ),
	    field('parameters', $.parameters),
	    optional(';'),
	    optional(field('body', $.block)),
	    'end',
	    'function',
	),
	
	procedure_definition: $ => seq(
	    // choice(
	    'procedure',
	    optional(field('name', $.identifier)),
		// seq(field('name', $.identifier), ':=', 'procedure')
	    // ),
	    field('parameters', $.parameters),
	    optional(';'),
	    optional(field('body', $.block)),
	    'end',
	    'procedure',
	),

	// inline_function: $ => choice(
	//     seq(
	// 	'func',
	// 	'<',
	// 	optional(field('parameters', $._parameter_list)),
	// 	'|',
	// 	field('body', $.primary_expression),
	// 	'>'
	//     )
	// ),

	// inline_procedure: $ => choice(
	//     seq(
	// 	'proc',
	// 	'<',
	// 	optional(field('parameters', $._parameter_list)),
	// 	'|',
	// 	field('body', $.primary_expression),
	// 	'>'
	//     )
	// ),

	_parameter_list: $ => choice(
	    seq(commaSep1($.parameter), optional($._optional_parameters)),
	    $._optional_parameters),

	_optional_parameters: $ => seq(
	    ':',
	    commaSep1(choice($.identifier,
			     $.optional_parameter)
		     )
	),
	
	parameters: $ => seq(
	    '(',
	    optional($._parameter_list),
	    ')'
	),

	parameter: $ => choice(
	    $.identifier,
	    $.typed_identifier,
	    $.ref_identifier,
	    '...'
	),

	ref_identifier: $ => seq(
	    '~',
	    $.identifier,
	),
	
	// MAYBE: should this be token.immediate?
	// what's the precedence?
	typed_identifier: $ => prec.left(PREC.colon, seq(
	    $.identifier,
	    "::",
	    $.type,
	)),

	optional_parameter: $ => seq(
	    field('name', $.identifier),
	    ':=',
	    field('value', $.primary_expression),
	),

	intrinsic_definition: $ => seq(
	    'intrinsic',
	    field('name', $.identifier),
	    field('parameters', $._intrinsic_parameters),
	    optional('[~]'),
	    optional(seq('->', commaSep1(field('return_type', $.type)))),
	    field('docstring',
		  seq('{',
		     /(?:[^\\}]|\\.)*/,	// matches anything that's not a squirly brace
		      '}',
		      optional(';'),
		     )
		 ),
	    optional(field('body', $.block)),
	    'end',
	    'intrinsic',
	    optional(';')
	),

	_intrinsic_parameters: $ => seq(
	    '(',
	    optional(commaSep1($._intrinsic_parameter)),
	    optional(seq(
		':',
		commaSep1(choice($.optional_parameter, $.identifier)))),
	    // optional parameters don't need default value
	    ')'
	),

	_intrinsic_parameter: $ => choice(
	    $.identifier,
	    $.backtick_identifier,
	    $.ref_identifier,
	    $.typed_identifier,
	    $.ref_typed_identifier
	),

	backtick_identifier: $ => seq('`', $.identifier),

	ref_typed_identifier: $ => seq(
	    '~',
	    $.identifier,
	    '::',
	    $.type,
	),


	call: $ => prec.right(PREC.call, seq(
	    field('function',  $.primary_expression),
	    field('arguments', $.argument_list),
	    
	)),

	argument_list: $ => seq(
	    '(',
	    optional(commaSep1(field('argument', $.primary_expression))),
	    optional($._optional_argument_list),
	    ')',
	),
	
	_optional_argument_list: $ => seq(
	    ':',
	    commaSep1($.optional_argument)),

	optional_argument: $ => seq(
	    field('argument', $.identifier),
	    optional(seq(':=',
			 field('default_value', $.primary_expression)))
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

	augmented_assignment: $ => {
	    const table =  ['join', 'meet', 'diff', 'sdiff', 'cat', '*', '+', '-', '/', '^', 'div', 'mod', 'and', 'or', 'xor'];

	    return choice(...table.map((symbol) =>
		seq(
		    field('left', $.primary_expression),
		    symbol + ':=',
		    field('right', $.expression)
		)));
	},

	_left_hand_side: $ => commaSep1(
	    choice(
		$.primary_expression, 
		$.anonymous_constructor
	    )),

	_right_hand_side: $ => commaSep1($.expression),

	anonymous_constructor: $ => seq(
	    $.anonymous_identifier,
	    '<',
	    choice(commaSep1($.identifier),
		   seq('[', commaSep1($.identifier), ']')),
	    '>'
	),

	type: $ => choice(
	    // Simple and any-type
	    $.identifier,
	    $.string,
	    '.',
	    // Extended types: Category[<type>, ...] (allow nested types)
	    seq('[', optional($.type), ']'),	 // Sequence type
	    seq('{', optional($.type), '}'),		 // Set type
	    seq('{[', optional($.type), ']}'),		 // Set or sequence type
	    seq('{@', optional($.type), '@}'),		 // Iset type
	    seq('{*', optional($.type), '*}'),		 // Multiset type
	    seq('<', '>'),		                 // Tuple type
	    seq($.identifier, '[', commaSep1($.type), ']'),
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

	map: $ => seq(
	    choice('hom', 'map', 'pmap', 'iso'),
	    '<',
	    field('domain', $.primary_expression),
	    '->',
	    field('codomain', $.primary_expression),
	    '|',
	    field('map_constructor', $._map_constructor),
	    optional(
		seq(':', commaSep1($.optional_parameter))
	    ),
	    '>',
	),

	_map_constructor: $ => commaSep1(
	    seq(
		optional(
		    seq(field('domain_element', $.primary_expression),
			choice(':->', '->'))),
		field('image', $.primary_expression)),
	),

	// Constructors

	_constructors: $ => choice(
	    $.constructor,
	    $.recformat_constructor,
	    $.cycle_or_commutator,
	    $.case_constructor,
	),
	
	constructor: $ => seq(
	    field('name', $.identifier),
	    '<',
	    choice(
		commaSep1($.primary_expression),
		seq(optional(commaSep1($.primary_expression)),
		    optional($.constructor_elements),
		    optional($.constructor_options),
		   )),
	    '>'
	),

	_simple_assignment: $ => seq(
	    $.identifier, ':=', $.primary_expression
	),
	// constructor_field: $ => seq(
	//     choice(commaSep1($.primary_expression),
	// 	   seq($.identifier, ':', $.primary_expression))
	// ),

	constructor_elements: $ => seq(
	    optional($.constructor_options),
	    // this is to accommodate the construction
	    // quo< GrpPC : F | R : parameters > : GrpFP, List(GrpFPRel) -> GrpPC, Map
	    // as well as optional arguments in func
	    '|',
	    optional(commaSep1(
		choice($.primary_expression,
		       $._simple_assignment)))
	),
	
	constructor_options: $ => seq(
	    ':',
	    optional(commaSep1(
		choice($.primary_expression,
		       $._simple_assignment)))
	),
	
	field_definition: $ => seq(
	    field('name', $.identifier),
	    ':',
	    field('type', $.primary_expression)
	),

	recformat_constructor: $ => seq(
	    'recformat',
	    '<',
	    commaSep1(choice($.field_definition, $.identifier)),
	    '>'
	),

	case_constructor: $ => seq(
	    'case',
	    '<',
	    $.primary_expression,
	    '|',
	    commaSep1(seq(
		field('match', $.primary_expression),
		':',
		field('consequence', $.primary_expression))),
	    optional(seq('default', ':',
			 field('default', $.primary_expression))),
	    '>'
	),

	// NB: these are usually parsed as function calls!!
	cycle_or_commutator: $ => prec.left(
	    choice(
		$.literal_cycle,
		repeat1(seq(
		    '(',
		    commaSep2($.primary_expression),
		    ')')))
	),

	literal_cycle: $ => prec.right(seq(
	    '\\(',
	    commaSep1($.integer),
	    ')',
	    optional(repeat1(seq('(', commaSep1($.integer), ')')))
	)),
	
	
	// Control flow

	_compound_statement: $ => choice(
	    $.if_statement,
	    $.for_statement,
	    $.while_statement,
	    $.case_statement,
	    $.repeat_statement,
	    $.try_catch_statement
	),
	
	if_statement: $ => seq(
	    'if',
	    field('condition', $.expression),
	    'then',
	    optional(';'),
	    optional(field('consequence', $.block)),
	    repeat(field('alternative', $.elif_clause)),
	    optional(field('alternative', $.else_clause)),
	    'end',
	    'if'
	),

	elif_clause: $ => seq(
	    'elif',
	    optional(';'),
	    field('condition', $.expression),
	    'then',
	    optional(';'),
	    optional(field('consequence', $.block)),
	    // optional(';')
	),

	else_clause: $ => seq(
	    'else',
	    optional(';'),
	    optional(field('consequence', $.block)),
	),

	
	for_statement: $ => seq(
	    'for',
	    field('quantifier', $.for_quantifier),
	    'do',
	    optional(';'),
	    field('body', $.block),
	    'end',
	    'for'
	),

	for_quantifier: $ => choice(
	    commaSep1(seq($.identifier,
		':=', field('from', $.primary_expression),
		'to', field('to', $.primary_expression),
		optional(seq(
		    'by', field('by', $.primary_expression)))
			 )),
	    choice(commaSep1($.primary_expression),
		   seq('random', commaSep1($.identifier), 'in', $.primary_expression))
	),

	// _iterable_binding: $ => seq(
	//     commaSep1(choice($.two_tuple, $.identifier)),
	//     'in',
	//     field('parent', $.primary_expression)
	// ),

	// needs to take into account all the variations in
	// https://magma.maths.usyd.edu.au/magma/handbook/text/13#86
				     
	while_statement: $ => seq(
	    'while',
	    field('condition', $.expression),
	    'do',
	    optional(';'),
	    field('body', $.block),
	    'end',
	    'while',
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
	    optional(seq('else', optional(':'), field('else', $.block))),
	    'end',
	    'case',
	),
	
	when_clause: $ => seq(
	    'when',
	    field('match', commaSep1($.primary_expression)),
	    ':',
	    field('consequence', $.block)
	),

	// Misc:

	dollar: $ => prec.left(PREC.dollar, choice(
		seq('$', optional(token.immediate(/\d+/))),
	)),
	    
	// MAYBE: rename this to parent_function or something?
	double_dollar: $ => "$$",
	
	
	// Basic tokens:
	
	// handles regular identifiers as well as quoted ones (e.g., foo, 'foo', or even 'foo.1 + 2')
	// also need to manually add in keywords which are not reserved
	// see https://magma.maths.usyd.edu.au/magma/handbook/text/85
	identifier: $ => choice(/(?:'[^']*'|[_a-zA-Z]+[a-zA-Z0-9_]*)/,
				'hom', 'map', 'pmap', 'iso', 'rep'), 
	
	anonymous_identifier: _ => '_',
	block: $ => repeat1($._statement),

	// Aggregates
	
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
	formal_set: $ => aggregate_of($, '{!', '!}', false),
	multiset: $ => aggregate_of($, '{*', '*}', true),

	two_tuple: $ => prec.left(PREC.arrow, seq(
	    $.primary_expression,
	    '->',
	    $.primary_expression
	)),
	
	aggregate: $ => choice(
	    $.seqenum,
	    $.list,
	    $.tuple,
	    $.two_tuple,
	    $.set,
	    $.indexed_set,
	    $.multiset,
	    $.formal_set,
	    $.literal_sequence,
	),


	range: $ => seq(
	    field('start', $.primary_expression),
	    '..',
	    field('end', $.primary_expression),
	    optional(seq('by', field('by', $.primary_expression)))
	),


	_set_operator: $ => choice(
	    $.quantified_set,
	    $.random_element_of_set,
	    $.representative_of_set,
	),

	quantified_set: $ => seq(
	    choice('exists', 'forall'),
	    optional(seq(
		'(',
		commaSep1($.identifier),
		')')),
	    $.set
	),

	random_element_of_set: $ => seq('random', $.set),

	representative_of_set: $ => prec.left(seq('rep', $.set)),
	// representative_of_set: $ => seq("blablabla", $.identifier),

	
	seq_slice: $ => prec.left(PREC.sq_bracket, seq(
	    field('parent', $.primary_expression),
	    commaSep1($.seqenum))
	),

	integer: _ => {
	    const separator = /\\\s+/;
	    const hex = /[0-9a-fA-F]/;
	    const decimal = /[0-9]/;
	    const hexDigits = seq(repeat1(hex), repeat(seq(separator, repeat1(hex))));
	    const decimalDigits = seq(repeat1(decimal), repeat(seq(separator, repeat1(decimal))));
	    return token(seq(
		optional(/-\s*/),
		optional(choice(/0[xX]/, /0[bB]/)),
		choice(decimalDigits,
		       seq(/0[bB]/, decimalDigits),
		       seq(/0[xX]/, hexDigits),
		)
	    ));
	},
	// AI generated, hopefully works as intended
	string: $ => /"[^"\\]*(?:\\(?:[\s\S])[^"\\]*)*"/,

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

function commaSep2(rule) {
    return seq(rule, ',', sep1(rule, ','));
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

 * @return {SeqRule}
 *
 */
function sep1(rule, separator) {
    return seq(rule, repeat(seq(separator, rule)));
}

function aggregate_of($, left, right, has_universe) {
	return seq(
	    left,
	    // universe
	    optional(has_universe ? seq(
		field('universe', $.primary_expression),
		'|'
	    ) : seq()),
	    // elements
	    optional(
		choice(commaSep1($.primary_expression), $.range)
	    ),
	    // specify parent(s) of element(s)
	    optional(
		seq(':',
		    commaSep1($.primary_expression),
		    // conditions
		    optional(
			seq('|', field('condition', $.primary_expression)))
		   )),
	    right
	);
}

