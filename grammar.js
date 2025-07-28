module.exports = grammar({
  name: 'magma',

  extras: $ => [
    /\s/,           // whitespace
    $.comment,      // comments
  ],

  rules: {
    // Program is the root rule - can contain statements, directives, intrinsics, or declarations
    program: $ => choice(
      repeat(choice(
        $.statement,
        $.directive,
        $.intrinsic,
        $.declaration
      )),
      // Empty program
      seq()
    ),

    // Comments
    comment: $ => choice(
      seq('//', /.*/),
      seq('/*', /[^*]*\*+([^/*][^*]*\*+)*/, '/')
    ),

    // Core tokens converted from yacc %token declarations

    // Comparison operators
    eq: $ => 'eq',
    ne: $ => 'ne',
    gt: $ => 'gt',
    ge: $ => 'ge',
    lt: $ => 'lt',
    le: $ => 'le',
    cmpeq: $ => 'cmpeq',
    cmpne: $ => 'cmpne',
    adj: $ => 'adj',
    notadj: $ => 'notadj',

    // Logical operators
    not: $ => 'not',
    and: $ => 'and',
    or: $ => 'or',
    xor: $ => 'xor',

    // Set operators
    in: $ => 'in',
    notin: $ => 'notin',
    subset: $ => 'subset',
    notsubset: $ => 'notsubset',

    // Arithmetic operators
    plus: $ => '+',
    minus: $ => '-',
    star: $ => '*',
    div: $ => 'div',
    mod: $ => 'mod',
    hat: $ => '^',
    hat_hat: $ => '^^',
    slash: $ => '/',

    // Set operations
    diff: $ => 'diff',
    sdiff: $ => 'sdiff',
    meet: $ => 'meet',
    join: $ => 'join',

    // Special operators
    hash: $ => '#',
    cat: $ => 'cat',
    tilde: $ => '~',

    // Delimiters
    leftangle: $ => '<',
    rightangle: $ => '>',
    leftbrace: $ => '{',
    rightbrace: $ => '}',
    leftsquare: $ => '[',
    rightsquare: $ => ']',
    leftround: $ => '(',
    rightround: $ => ')',

    // Special bracket combinations
    leftbrace_at: $ => '{@',
    at_rightbrace: $ => '@}',
    leftbrace_bang: $ => '{!',
    bang_rightbrace: $ => '!}',
    leftbrace_star: $ => '{*',
    star_rightbrace: $ => '*}',
    leftsquare_star: $ => '[*',
    star_rightsquare: $ => '*]',

    // Special symbols
    arrow: $ => '->',
    at: $ => '@',
    atat: $ => '@@',
    bar: $ => '|',
    bar_arrow: $ => '|->',
    becomes: $ => ':=',
    bang: $ => '!',
    bang_bang: $ => '!!',
    colon: $ => ':',
    colon_colon: $ => '::',
    comma: $ => ',',
    dollar: $ => '$',
    dollar_dollar: $ => '$$',
    dot: $ => '.',
    dotdot: $ => '..',
    dotdotdot: $ => '...',
    semi: $ => ';',
    equality: $ => '=',
    star_star: $ => '**',
    underscore: $ => '_',
    undefconst: $ => 'undefined',

    // Backquotes
    backquote: $ => '`',
    backquote_backquote: $ => '``',

    // Keywords - control flow
    if: $ => 'if',
    then: $ => 'then',
    else: $ => 'else',
    elif: $ => 'elif',
    end: $ => 'end',
    while: $ => 'while',
    do: $ => 'do',
    repeat: $ => 'repeat',
    until: $ => 'until',
    for: $ => 'for',
    to: $ => 'to',
    by: $ => 'by',
    break: $ => 'break',
    continue: $ => 'continue',
    return: $ => 'return',
    case: $ => 'case',
    when: $ => 'when',
    default: $ => 'default',

    // Keywords - functions and procedures
    function: $ => 'function',
    func: $ => 'func',
    procedure: $ => 'procedure',
    proc: $ => 'proc',
    forward: $ => 'forward',
    intrinsic: $ => 'intrinsic',
    local: $ => 'local',

    // Keywords - declarations and directives
    declare: $ => 'declare',
    clear: $ => 'clear',
    load: $ => 'load',
    iload: $ => 'iload',
    save: $ => 'save',
    restore: $ => 'restore',
    freeze: $ => 'freeze',
    import: $ => 'import',
    export: $ => 'export',

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

    // Keywords - special constructs
    try: $ => 'try',
    catch: $ => 'catch',
    where: $ => 'where',
    is: $ => 'is',
    exists: $ => 'exists',
    forall: $ => 'forall',
    select: $ => 'select',
    eval: $ => 'eval',
    assigned: $ => 'assigned',
    delete: $ => 'delete',
    quit: $ => 'quit',

    // Keywords - algebraic structures
    abelian_group: $ => 'AbelianGroup',
    affine_plane: $ => 'AffinePlane',
    algebra: $ => 'Algebra',
    associative_algebra: $ => 'AssociativeAlgebra',
    affine_algebra: $ => 'AffineAlgebra',
    additive_code: $ => 'AdditiveCode',
    cayley_group: $ => 'CayleyGroup',
    character: $ => 'Character',
    clifford_algebra: $ => 'CliffordAlgebra',
    database: $ => 'Database',
    design: $ => 'Design',
    digraph: $ => 'Digraph',
    elt: $ => 'elt',
    ext: $ => 'ext',
    extension_field: $ => 'ExtensionField',
    entry: $ => 'Entry',
    fp_group: $ => 'FPGroup',
    fp_semigroup: $ => 'FPSemigroup',
    fp_monoid: $ => 'FPMonoid',
    fp_algebra: $ => 'FPAlgebra',
    frac: $ => 'frac',
    graph: $ => 'Graph',
    group_algebra: $ => 'GroupAlgebra',
    hom: $ => 'hom',
    ideal: $ => 'ideal',
    incidence_structure: $ => 'IncidenceStructure',
    iso: $ => 'iso',
    library: $ => 'Library',
    lideal: $ => 'lideal',
    linear_code: $ => 'LinearCode',
    linear_space: $ => 'LinearSpace',
    loc: $ => 'loc',
    lie_algebra: $ => 'LieAlgebra',
    map: $ => 'map',
    matrix_algebra: $ => 'MatrixAlgebra',
    matrix_group: $ => 'MatrixGroup',
    multi_graph: $ => 'MultiGraph',
    multi_digraph: $ => 'MultiDigraph',
    network: $ => 'Network',
    nilpotent_group: $ => 'NilpotentGroup',
    ncl: $ => 'ncl',
    near_linear_space: $ => 'NearLinearSpace',
    permutation_group: $ => 'PermutationGroup',
    polycyclic_group: $ => 'PolycyclicGroup',
    partial_map: $ => 'PartialMap',
    projective_plane: $ => 'ProjectivePlane',
    quo: $ => 'quo',
    quaternion_algebra: $ => 'QuaternionAlgebra',
    rep: $ => 'rep',
    random: $ => 'random',
    representation: $ => 'Representation',
    rideal: $ => 'rideal',
    rec: $ => 'rec',
    recformat: $ => 'recformat',
    sub: $ => 'sub',
    require: $ => 'require',
    requirerange: $ => 'requirerange',
    requirege: $ => 'requirege',
    type: $ => 'type',
    unip_matrix_group: $ => 'UnipotentMatrixGroup',
    z_module: $ => 'ZModule',

    // Reduction operators
    reduct_plus: $ => '&+',
    reduct_minus: $ => '&-',
    reduct_mult: $ => '&*',
    reduct_and: $ => '&and',
    reduct_or: $ => '&or',
    reduct_meet: $ => '&meet',
    reduct_join: $ => '&join',
    reduct_cat: $ => '&cat',

    // Boolean literals
    bool_true: $ => 'true',
    bool_false: $ => 'false',

    // Literals
    integer_literal: $ => /\d+/,
    
    real_literal: $ => /\d+\.\d+([eE][+-]?\d+)?/,
    
    string_literal: $ => choice(
      seq('"', repeat(choice(/[^"\\]/, /\\./)), '"'),
      seq("'", repeat(choice(/[^'\\]/, /\\./)), "'")
    ),

    identifier: $ => /[a-zA-Z_][a-zA-Z0-9_]*/,

    // Sequence and cycle literals (simplified for now)
    sequence_literal: $ => seq('[', optional($.expression_list), ']'),
    cycle_literal: $ => seq('(', $.expression_list, ')'),

    // Basic structure placeholders - will be implemented in later tasks
    statement: $ => choice(
      $.normal_statement,
      seq($.time, $.normal_statement),
      seq($.vtime, $.identifier, optional(seq($.comma, $.expression)), $.colon, $.normal_statement)
    ),

    normal_statement: $ => choice(
      $.semi,  // null statement
      'placeholder_statement'  // placeholder for other statements
    ),

    directive: $ => choice(
      seq($.clear, $.semi),
      seq($.load, $.directive_string, $.semi),
      seq($.iload, $.directive_string, $.semi),
      seq($.save, $.directive_string, $.semi),
      seq($.restore, $.directive_string, $.semi),
      seq($.freeze, $.semi)
    ),

    directive_string: $ => choice(
      $.string_literal,
      $.identifier
    ),

    declaration: $ => choice(
      seq($.declare, $.identifier, $.identifier, optional($.opt_elt_t), $.semi),
      seq($.declare, $.identifier, $.identifier, optional($.opt_elt_t), $.colon, $.identifier_list, $.semi),
      seq($.declare, $.identifier, $.identifier, $.comma, $.literal, $.semi)
    ),

    opt_elt_t: $ => seq($.leftsquare, $.identifier, $.rightsquare),

    identifier_list: $ => seq($.identifier, repeat(seq($.comma, $.identifier))),

    intrinsic: $ => seq(
      $.intrinsic,
      $.identifier,
      $.leftround,
      'placeholder_intrinsic_args',
      $.rightround,
      'placeholder_intrinsic_opt'
    ),

    literal: $ => choice(
      $.integer_literal,
      $.real_literal,
      $.string_literal,
      $.bool_true,
      $.bool_false,
      $.sequence_literal,
      $.cycle_literal
    ),

    // Placeholder for expressions - will be implemented in later tasks
    expression: $ => 'placeholder_expression',
    expression_list: $ => 'placeholder_expr_list',
  },
});