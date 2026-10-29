function Scope(x, i, a, b)
//             ^ variable.parameter
//                ^ variable.parameter
    values := [x : x in [1..3] | x gt 0];
//                 ^ variable
//                               ^ variable
    indexed := [j : j -> i in [2,3] | i gt 0];
//                  ^ variable
//                       ^ variable
//                                    ^ variable
    pairs := [a + b : a, b in [1..3] | a gt b];
//                    ^ variable
//                       ^ variable
//                                     ^ variable
//                                          ^ variable
    return x + i;
//         ^ variable
//             ^ variable
end function;

x := function(t) return t; end function;
// <- function
f := map<Integers() -> Integers() | x :-> x + 1>;
//                                  ^ variable.parameter
//                                        ^ variable
x(1);
// <- function

p := proc<~items | Append(~items, 1)>;
//         ^ variable.parameter
//                         ^ variable
items := [];
// <- variable

function Outer(x)
//             ^ variable.parameter
    function Inner(y)
//                 ^ variable.parameter
        return x + y;
//             ^ variable
//                 ^ variable
    end function;
    y := 2;
//  ^ variable
    result := t where t is x + 1;
//                    ^ variable
//                         ^ variable
    return x + y;
//         ^ variable
//             ^ variable
end function;
x(1);
// <- function

// Forward bindings must not inherit a parameter or function color.
function ForwardBindings(x, apply)
//                       ^ variable.parameter
//                          ^ variable.parameter
    values := [x : x in [1..3] | x gt 0];
//             ^ variable
//                 ^ variable
//                               ^ variable
    value := x where x is x + 1;
//           ^ variable
//                   ^ variable
//                        ^ variable
    nested := [x + y : x in [1..3], y in [x..3]];
//             ^ variable
//                 ^ variable
//                     ^ variable
//                                  ^ variable
//                                        ^ variable
    mapped := [apply(x) : x in values];
//             ^ function
//                   ^ variable
//                        ^ variable
    return apply(value) + x;
//         ^ function
//                        ^ variable
end function;
  [x : x in [1..3]];
// ^ variable
//     ^ variable
x where x is 1;
// <- variable
//      ^ variable
