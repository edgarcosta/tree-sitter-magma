// A runnable sample for reviewing the highlight queries.
// Package-only constructs also appear in test/highlight/definitions.m.

R<x> := PolynomialRing(Rationals());
f := x^4 - 1;
assert Degree(f) eq 4;

function SumSquares(values : Offset := 0)
    error if #values eq 0, "Expected a nonempty sequence";
    total := &+[n^2 : n in values];
    return total + Offset;
end function;

procedure Bump(~value : Step := 1)
    value +:= Step;
end procedure;

answer := SumSquares([1..5] : Offset := 1);
Bump(~answer : Step := 2);
printf "Result: %o\n", answer;

square := func<n | n^2>;
assert square(3) eq 9;
scaled := func<n : Scale := 2 | Scale * n>;
assert scaled(3) eq 6;

positive := forall{n : n in [1..5] | n gt 0};
witness := exists(n){n : n in [1..5] | IsPrime(n)};
assert positive and witness and not false;

s := {1, 2} join {2, 3};
s diff:= {3};
chosen := rep{n : n in s};
rep := "rep is also an ordinary identifier";
assert chosen in s;
assert &and[true, true] and &or[false, true];

item_format := recformat<name: MonStgElt, count: RngIntElt>;
item := rec<item_format | name := "example", count := 1>;
item`count +:= 1;
print item`name, item`count;

inclusion := map<Integers() -> Rationals() | n :-> n>;
assert 2 @ inclusion eq 2;
small := case<answer | 1: "one", 2: "two", default: "many">;
print small;

for i := 1 to 5 by 2 do
    if i eq 1 then
        continue;
    elif i eq 3 then
        print "three";
    else
        break;
    end if;
end for;

count := 0;
while count lt 2 do
    count +:= 1;
end while;
repeat
    count -:= 1;
until count eq 0;

try
    error if count ne 0, "Unexpected count";
catch err
    print err;
end try;

case count:
when 0: print "zero";
else: print "nonzero";
end case;

answer := value^2 where value is 3;
assert answer eq 9;
print answer: Minimal;
print true select "yes" else "no";

// Distinct collection delimiters, strings, reals, and literal forms.
print [*1, "two"*], <1, 2>, {@1, 2@}, {*1, 1, 2*};
print 0.5, 0xFF, \[1, 2], \(1, 2);
