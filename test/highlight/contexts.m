function Inspect(field, Flag, rec, apply : Offset := 1)
//               ^ variable.parameter
//                      ^ variable.parameter
//                            ^ variable.parameter
//                                 ^ variable.parameter
//                                         ^ variable.parameter

    fmt := recformat<field>;
//                   ^ property

    value := rec<fmt | field := 1>;
//           ^ function.builtin
//                     ^ property

    value`field;
//  ^ variable
//        ^ property

    apply(value : Flag := Offset);
//  ^ function
//                ^ variable.parameter
//                        ^ variable

    value := func<x : Flag := 1 | x>;
//                    ^ variable.parameter

    return field + Offset;
//         ^ variable
//                 ^ variable

end function;

intrinsic Example(First, ~Second::RngIntElt, `Third : Flag := 1, Other) -> RngIntElt
//                ^ variable.parameter
//                        ^ variable.parameter
//                                            ^ variable.parameter
//                                                    ^ variable.parameter
//                                                               ^ variable.parameter

{Exercise each kind of intrinsic parameter.}
// <- string.documentation

    return First + Second + Third + Flag + Other;
//         ^ variable
//                 ^ variable
//                          ^ variable
//                                  ^ variable
//                                         ^ variable

end intrinsic;

intrinsic Types(RngIntElt::RngIntElt) -> RngIntElt
//              ^ variable.parameter
//                         ^ type

{Type names do not refer to a parameter with the same spelling.}

    return RngIntElt;
//         ^ variable

end intrinsic;

function 'quoted function'(x)
//       ^ function

    return x;
//         ^ variable

end function;

'quoted function'(1);
// <- function

f := function(x) return x; end function;
// <- function

f(1);
// <- function

rep := func<x | x>;
// <- variable
//     ^ function.builtin

rep{1};
// <- keyword.operator

// A line comment with if, true, := and "strings".
// <- comment

/* A block comment with operators: &+, ->. */
// <- comment

"text with \"quotes\" and \n";
// <- string

item`/* selected */field;
// <- variable
//                 ^ property
item /* receiver */`/* selected */invoke /* arguments */(1);
//                                ^ property
item`/* first */child`/* middle */make(1)`/* final */finish(2);
//              ^ property
//                                ^ property
//                                                   ^ property
