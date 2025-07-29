# Example Code Patterns

This file contains example code snippets showing various Magma constructs.

## Basic Syntax

### Variables and Assignment
```magma
function SomeFunction() return 1; end function;
x := 42;
name := "Hello, World";
flag := true;
a, b, c := 1, 2, 3;        // multiple assignment
_ := SomeFunction();       // ignore return value
```

### Arithmetic Expressions
```magma
a := 1; b := 2; c := 3; d := 4; e := 5; x := 1; y := 2;
result := (a + b) * c - d / e;
power := x^y;
modulo := a mod b;
negation := -x;
```

## Control Flow

### Conditional Statements
```magma
x := 1;
if x gt 0 then
    print "Positive";
elif x eq 0 then
    print "Zero";
else  
    print "Negative";
end if;
```

### Loops
```magma
// Range-based for loop
for i := 1 to 10 do
    print i;
end for;

// For-each loop
MySet := {1,2,3};
for element in MySet do
    print element;
end for;

// While loop
count := 0;
while count lt 100 do
    count +:= 1;
end while;

// Repeat-until loop
repeat
    x := Random(100);
until x gt 50;
```

## Functions and Procedures

### Function Definition
```magma
function Factorial(n)
    if n le 1 then
        return 1;
    else
        return n * Factorial(n - 1);
    end if;
end function;
Factorial(5);
```

### Procedure Definition
```magma
procedure Swap(~a, ~b)
    temp := a;
    a := b;
    b := temp;
end procedure;
x:=1; y:=2;
Swap(~x,~y);
```

### Lambda Functions
```magma
square := func<x | x^2>;
add := func<x, y | x + y>;
printer := proc<msg | print msg>;
square(2);
add(2,3);
printer("hello");
```

## Collection Constructors

### Sets
```magma
// Explicit set
S := {1, 2, 3, 4, 5};

// Range set
R := {1..100};

// Set comprehension
Squares := {x^2 : x in {1..10}};
Evens := {x : x in {1..100} | x mod 2 eq 0};
```

### Sequences  
```magma
// Explicit sequence
seq := [1, 2, 3, 4, 5];

// Empty sequence
empty := [];

// Range sequence
range_seq := [1..50];

// Sequence comprehension
function IsPrime(n) return IsFundamental(n); end function;
squares := [x^2 : x in [1..10]];
filtered := [x : x in [1..100] | IsPrime(x)];
```

### Tuples
```magma
point := <3, 4>;
triple := <"name", 42, true>;
empty_tuple := <>;

// Tuple comprehension
coords := <x, y : x in Integers(5), y in Integers(5) | x^2 + y^2 eq 25>;
```

### Multisets and Indexed Sets
```magma
// Multiset
mset := {* 1, 1, 2, 2, 2, 3 *};

// Indexed set  
iset := {@ 1, 2, 3 @};
```

## Maps

### Map Construction
```magma
G := AbelianGroup([2,2]); H := G; g1:=G.1; g2:=G.2; h1:=H.1; h2:=H.2;
// Simple map
f := map<Integers() -> Integers() | x :-> x^2>;

// Partial map
g := pmap<{1..10} -> Integers() |
    1 :-> 1, 2 :-> 4, 3 :-> 9>;

// Homomorphism
phi := hom<G -> H | g1 :-> h1, g2 :-> h2>;
```

## Mathematical Structures

### Groups
```magma
// Symmetric group
S4 := Sym(4);

// Cyclic group
C12 := CyclicGroup(12);

// Finitely presented group
G := Group<a, b | a^3, b^2, (ab)^2>;

// Matrix group
F := GF(3);
G := MatrixGroup<2, F | [1,1,0,1], [1,0,1,1]>;
```

### Rings and Fields
```magma
// Polynomial ring
R<x, y> := PolynomialRing(Integers(), 2);
f := x^2 + 2*x*y + y^2;

// Finite field
F := GF(25);
a := PrimitiveElement(F);

// Number field
Q_sqrt2 := QuadraticField(2);
```

### Codes
```magma
// Linear code
C := LinearCode(GF(2), [[1,1,0], [0,1,1]]);

// Hamming code
H := HammingCode(3, GF(2));
```

## Record Operations

### Record Construction
```magma
// Record with format
MyFormat := recformat<name, age, height>;
person := rec<MyFormat | name := "Alice", age := 25, height := 170>;

// Direct record construction  
point := rec<| x := 3, y := 4, z := 5 |>;
```

### Record Field Access
```magma
format := recformat<name, age>;
person := rec<format | name := "a", age := 1>;
point := rec<| x,y | x:=1, y:=2>;
name := person`name;
x_coord := point`x;

// Dynamic field access
field_name := "age";
value := person``field_name``;
```

## Advanced Constructs

### Quantifiers
```magma
S := {1, 2, 3, 4, 5, 6};
// Existential quantifier
result := exists(x){ x^2 eq 25 : x in {1..100} | x gt 0 };

// Universal quantifier
all_positive := forall{ x gt 0 : x in S };

// Random element
function IsPrime(n) return n in {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97}; end function;
rand_prime := random{ p : p in {2..100} | IsPrime(p) };
```

### Case Expressions
```magma
x := 1;
type_name := case<Type(x) | 
    Integers() : "integer",
    Rationals() : "rational", 
    default : "other"
>;
```

### Where Clauses
```magma
result := (a + b)^2 where a := 3, b := 4;
discriminant := b^2 - 4*a*c where a := 1, b := -5, c := 6;
```

## Intrinsic Definitions

### Simple Intrinsic
```magma-spec
intrinsic IsEven(n :: RngIntElt) -> BoolElt
{
Returns true if n is even, false otherwise.
}
    return n mod 2 eq 0;
end intrinsic;
IsEven(4);
```

### Complex Intrinsic
```magma-spec
intrinsic MyGCD(a :: RngIntElt, b :: RngIntElt) -> RngIntElt, RngIntElt, RngIntElt
{
Extended Euclidean algorithm.
Returns gcd(a,b), and integers x,y such that ax + by = gcd(a,b).
}
    require a ne 0 or b ne 0 : "Arguments cannot both be zero";
    
    if b eq 0 then
        return Abs(a), Sign(a), 0;
    end if;
    
    // Euclidean algorithm implementation
    return ExtendedGCD(a, b);
end intrinsic;
MyGCD(10,6);
```

## Error Handling

### Try-Catch
```magma
n := 10;
try
    result := Factorization(n);
    print "Factorization:", result;
catch e
    print "Could not factor", n;
    print "Error:", e;
end try;
```

### Assertions
```magma
n := 1; p := 3; S := {1};
function IsPrime(n) return IsFundamental(n); end function;
assert n gt 0;
assert2 IsPrime(p);
assert3 #S eq 1;
```

## I/O Operations

### Printing
```magma
x := 5; data := "hello";
print "Hello, World!";
printf "The value is %o\\n", x;

// Verbose printing
vprint User, 1 : "Debug information:", data;
```

### File Operations
```magma
// The following commands will likely fail if files do not exist,
// but they test the syntax.
try load "myfile.m"; catch e; end try;
try save "workspace.m"; catch e; end try;

// Package imports
try import "algebra/groups.m" : SymmetricGroup, AlternatingGroup; catch e; end try;
```

## Complex Examples

### Matrix Operations
```magma
M := Matrix(Rationals(), 2, 2, [1, 2, 3, 4]);
det := Determinant(M);
inv := M^(-1);
```

### Polynomial Factorization
```magma
R<x> := PolynomialRing(Rationals());
f := x^4 - 1;
factors := Factorization(f);
```

### Group Theory Computation
```magma
G := Sym(5);
H := Stabilizer(G, 1);
orbits := Orbits(G);
order := #G;
```

### Number Theory
```magma
// Quadratic residues
p := 17;
residues := {x^2 mod p : x in {1..p-1}};

// Continued fraction
cf := ContinuedFraction(Sqrt(2));
```

These examples demonstrate the rich syntax and mathematical capabilities of the Magma language, from basic programming constructs to advanced mathematical computations. 