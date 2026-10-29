function Add(x, y : offset := 1)
// <- keyword.function
//       ^ function
//           ^ variable.parameter
//              ^ variable.parameter
//                  ^ variable.parameter
//                         ^ operator
//                            ^ number

    return x + y + offset;
//  ^ keyword.return
//         ^ variable

end function;
// <- keyword.function

f := function(x)
// <- function
//            ^ variable.parameter

    return $$(x);
//         ^ function.builtin

end function;

procedure Change(~x : value := 1)
//        ^ function
//               ^ operator
//                ^ variable.parameter
//                    ^ variable.parameter

    x := value;
//       ^ variable

end procedure;

intrinsic Example(x::RngIntElt, y, ~z::SeqEnum, `attr : Flag := true, Other) -> RngIntElt
//        ^ function
//                ^ variable.parameter
//                 ^ operator
//                   ^ type
//                              ^ variable.parameter
//                                  ^ variable.parameter
//                                     ^ type
//                                               ^ variable.parameter
//                                                      ^ variable.parameter
//                                                                    ^ variable.parameter
//                                                                           ^ operator

{Return the input.}
// <- string.documentation

    return x;
//         ^ variable

end intrinsic;

forward Pending;
// <- keyword.directive
//      ^ function

Add(1, 2 : offset := 3);
// <- function
//         ^ variable.parameter
//                   ^ number

declare attributes Rec: field;
// <- keyword.directive
//      ^ keyword.directive
//                 ^ type
//                      ^ property

declare type ExampleType: Parent;
//      ^ keyword.directive
//           ^ type
//                        ^ type
