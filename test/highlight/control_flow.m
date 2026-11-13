if true then
// <- keyword.conditional
//      ^ keyword.conditional

    print "yes";
//  ^ keyword.directive
//        ^ string

elif false then
// <- keyword.conditional
//         ^ keyword.conditional

    print 2;
//        ^ number

else
// <- keyword.conditional

    print 3;
//        ^ number

end if;
// <- keyword.conditional
//  ^ keyword.conditional

while false do
// <- keyword.repeat
//          ^ keyword.repeat

    break;
//  ^ keyword.repeat

end while;
// <- keyword.repeat

repeat
// <- keyword.repeat

    n := 1;
//  ^ variable

until true;
// <- keyword.repeat

for i := 1 to 3 by 2 do
// <- keyword.repeat
//    ^ operator
//         ^ keyword.repeat
//              ^ keyword.repeat
//                   ^ keyword.repeat

    continue;
//  ^ keyword.repeat

end for;
// <- keyword.repeat

for random i in {1} do
//  ^ keyword.operator
//           ^ keyword.operator

    break;

end for;

try
// <- keyword.exception

    error if false, "oops";
//  ^ keyword.exception
//        ^ keyword.conditional
//           ^ constant.builtin
//                  ^ string

catch e
// <- keyword.exception
//    ^ variable

    print e;
//        ^ variable

end try;
// <- keyword.exception

case 1:
// <- keyword.conditional
//    ^ punctuation.delimiter

when 1: print 1;
// <- keyword.conditional

else: print 0;
// <- keyword.conditional

end case;
// <- keyword.conditional

true select 1 else 0;
//   ^ keyword.conditional
//            ^ keyword.conditional
