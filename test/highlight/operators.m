true and false or true xor false;
//   ^ keyword.operator
//             ^ keyword.operator
//                     ^ keyword.operator
// <- constant.builtin

not false;
// <- keyword.operator

1 + 2 * 3 div 2 mod 2;
//^ operator
//    ^ operator
//        ^ keyword.operator
//              ^ keyword.operator

1 eq 1 and 2 ne 3;
//^ keyword.operator
//           ^ keyword.operator

{1} join {2} diff {3} meet {1,2};
//  ^ keyword.operator
//           ^ keyword.operator
//                    ^ keyword.operator

[1] cat [2];
//  ^ keyword.operator

&+[1,2];
// <- operator

&and[true,false];
// <- operator

&or[true,false];
// <- operator

&cat[[1],[2]];
// <- operator

n := 1;
// <- variable
//^ operator

n +:= 2;
//^ operator

n div:= 2;
//^ operator

n := 0.5;
//   ^ number.float

n := n where n is 2;
//     ^ keyword
//             ^ keyword

n := n where n := 2;
//     ^ keyword
//             ^ operator

eval "1 + 2";
// <- keyword
//   ^ string

exists(x){x : x in {1} | x eq 1};
// <- keyword.operator
//              ^ keyword.operator
//                     ^ punctuation.special

forall{x : x in {1} | x eq 1};
// <- keyword.operator

random{1};
// <- keyword.operator

rep{1};
// <- keyword.operator

rep(1);
// <- function

rep := 1;
// <- variable

a := $1;
//   ^ variable.builtin

_, b := 1, 2;
// <- variable.builtin

Integers()!1;
//        ^ operator
// <- function
