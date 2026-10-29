load "file.m";
// <- keyword.directive
//   ^ string

iload "file.m";
// <- keyword.directive
//    ^ string

import "file.m": f;
// <- keyword.directive
//     ^ string
//               ^ variable

save "file.sav";
// <- keyword.directive
//   ^ string

restore "file.sav";
// <- keyword.directive
//      ^ string

freeze;
// <- keyword.directive

clear;
// <- keyword.directive

delete x;
// <- keyword.directive
//     ^ variable

local x, y;
// <- keyword.directive
//    ^ variable

assert 1 eq 1;
// <- keyword.directive
//     ^ number
//       ^ keyword.operator

require true: "message";
// <- keyword.directive
//      ^ constant.builtin
//            ^ string

print 1: Maximal;
// <- keyword.directive
//    ^ number
//       ^ constant.builtin

printf "%o", 1;
// <- keyword.directive
//     ^ string
//           ^ number

vprint Test, 1: "message";
// <- keyword.directive
//     ^ variable
//           ^ number
//              ^ string

read x, "prompt";
// <- keyword.directive
//   ^ variable
//      ^ string

time n := 1;
// <- keyword.directive
//   ^ variable
//     ^ operator
//        ^ number

vtime Test: n := 1;
// <- keyword.directive
//    ^ variable
//          ^ variable

quit;
// <- keyword.directive
