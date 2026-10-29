R<x> := PolynomialRing(Rationals());
// <- variable
//^ variable
//      ^ function

x^2 + R!1;
// <- variable
//    ^ variable

_<y> := PolynomialRing(Rationals());
// <- variable.builtin
//^ variable

y^2;
// <- variable

f := func<z : Offset := 1 | z + Offset>;
//        ^ variable.parameter
//            ^ variable.parameter
//                          ^ variable
//                              ^ variable

z := 2;
// <- variable

Offset := 2;
// <- variable

func<: Flag | Flag>;
//     ^ variable.parameter
//            ^ variable

Flag := 1;
// <- variable
