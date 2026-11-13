R := recformat<field: RngIntElt, other>;
//   ^ function.builtin
//            ^ punctuation.bracket
//             ^ property
//                    ^ type
//                               ^ property
//                                    ^ punctuation.bracket

r := rec<R | field := 1, other := 2>;
//   ^ function.builtin
//       ^ variable
//         ^ punctuation.special
//           ^ property
//                 ^ operator

  r`field;
//^ variable
// ^ operator
//  ^ property

  r``["field"];
//^ variable
// ^ operator
//    ^ string

func<x | x + 1>;
// <- function.builtin
//   ^ variable.parameter

map<Integers() -> Rationals() | x :-> x>;
// <- function.builtin
//             ^ operator
//                                ^ operator

case<1 | 1: 2, default: 0>;
// <- keyword.conditional
//             ^ keyword.conditional

[1..5 by 2];
//^ punctuation.special
//    ^ keyword.repeat

[*1, "two"*];
// <- punctuation.bracket
//        ^ punctuation.bracket

{@1,2@};
// <- punctuation.bracket
//   ^ punctuation.bracket

{*1,2*};
// <- punctuation.bracket
//   ^ punctuation.bracket

{!1,2!};
// <- punctuation.bracket
//   ^ punctuation.bracket

<1,2>;
// <- punctuation.bracket
//  ^ punctuation.bracket

\[1,2];
// <- punctuation.bracket

\(1,2);
// <- punctuation.bracket
