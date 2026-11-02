function Sum(values)
//       ^ definition.function
    function Identity(x)
//           ^ definition.function
        return x;
    end function;
    return Identity(&+values);
//         ^ reference.call
end function;

procedure Bump(~value)
//        ^ definition.function
    value +:= 1;
end procedure;

intrinsic Twice(x::RngIntElt) -> RngIntElt
//        ^ definition.function
{Return twice the input.}
    return 2*x;
end intrinsic;

intrinsic Twice(x::FldRatElt) -> FldRatElt
//        ^ definition.function
{The rational overload.};
    return 2*x;
end intrinsic;

intrinsic Reset(~x::RngIntElt)
//        ^ definition.function
{Reset the input.}
    x := 0;
end intrinsic;

closure := function(x)
// <- definition.function
    return Twice(x);
//         ^ reference.call
end function;

change := procedure(~x)
// <- definition.function
    Bump(~x);
//  ^ reference.call
end procedure;

square := func<x | x^2>;
// <- definition.function
scaled := func<x : Scale := 2 | Scale*x>;
// <- definition.function
update := proc<~x | Bump(~x)>;
// <- definition.function
//                  ^ reference.call

declare type Widget: Parent;
//           ^ definition.type
declare type GrpPSL2[GrpPSL2Elt]: Parent;
//           ^ definition.type
declare attributes Widget: value, action;
//                         ^ definition.field
//                                ^ definition.field
format := recformat<value: RngIntElt, action>;
//                  ^ definition.field
//                                    ^ definition.field

answer := Sum([1, 2]);
//        ^ reference.call
answer := square(answer);
//        ^ reference.call
item`action(answer);
//   ^ reference.call
item`child`action(answer);
//         ^ reference.call
Factory()(answer);
// <- reference.call

// These have no definitions or named call references of their own.
forward Pending;
import "other.m": Imported;
ordinary := 1;
alias := Sum;
record := rec<format | value := 1>;
mapping := map<domain -> codomain | x :-> x>;
left, right := func<x | x>, 1;
single := func<x | x>, 1;
handlers[1](answer);
