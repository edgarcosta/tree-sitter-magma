# Example Code Patterns

This file contains example code snippets showing various Magma constructs.

## Basic Syntax

### Variables and Assignment
```magma
x := 42;
name := "Hello, World";
flag := true;
a, b, c := 1, 2, 3;        // multiple assignment
_ := SomeFunction();       // ignore return value
```

### Arithmetic Expressions
```magma
result := (a + b) * c - d / e;
power := x^y;
modulo := a mod b;
negation := -x;
```

## Control Flow

### Conditional Statements
```magma
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
for element in MySet do
    print element;
end for;

// While loop
count := 0;
while count lt 100 do
    count := count + 1;
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
```

### Procedure Definition
```magma
procedure Swap(~a, ~b)
    temp := a;
    a := b;
    b := temp;
end procedure;
```

### Lambda Functions
```magma
square := func<x | x^2>;
add := func<x, y | x + y>;
printer := proc<msg | print msg>;
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
squares := [x^2 : x in [1..10]];
filtered := [x : x in [1..100] | IsPrime(x)];
```

### Tuples
```magma
point := <3, 4>;
triple := <"name", 42, true>;
empty_tuple := <>;

// Tuple comprehension
coords := <x, y : x, y in Integers() | x^2 + y^2 eq 25>;
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
// Simple map
f := map<Integers() -> Integers() | x :-> x^2>;

// Partial map
g := partial_map<{1..10} -> Integers() | 
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
G := fp_group<a, b | a^3, b^2, (ab)^2>;

// Matrix group
F := GF(3);
G := matrix_group<F, 2 | [1,1,0,1], [1,0,1,1]>;
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
Q<sqrt2> := QuadraticField(2);
```

### Codes
```magma
// Linear code
C := linear_code<GF(2), 3 | [1,1,0], [0,1,1]>;

// Hamming code
H := HammingCode(GF(2), 3);
```

## Record Operations

### Record Construction
```magma
// Record with format
format := recformat<name, age, height>;
person := rec<format | name := "Alice", age := 25, height := 170>;

// Direct record construction  
point := rec<| x := 3, y := 4, z := 5 |>;
```

### Record Field Access
```magma
name := person`name;
x_coord := point`x;

// Dynamic field access
field_name := "age";
value := person``field_name``;
```

## Advanced Constructs

### Quantifiers
```magma
// Existential quantifier
result := exists(x){ x^2 eq 25 : x in Integers() | x gt 0 };

// Universal quantifier
all_positive := forall{ x gt 0 : x in S };

// Random element
rand_prime := random{ p : p in {2..100} | IsPrime(p) };
```

### Case Expressions
```magma
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
```magma
intrinsic IsEven(n :: RngIntElt) -> BoolElt
{
Returns true if n is even, false otherwise.
}
    return n mod 2 eq 0;
end intrinsic;
```

### Complex Intrinsic
```magma
intrinsic GCD(a :: RngIntElt, b :: RngIntElt) -> RngIntElt, RngIntElt, RngIntElt
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
```

## Error Handling

### Try-Catch
```magma
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
assert n gt 0;
assert2 IsPrime(p);
assert3 #S eq 10;
```

## I/O Operations

### Printing
```magma
print "Hello, World!";
printf "The value is %o\n", x;

// Verbose printing
vprint User, 1 : "Debug information:", data;
```

### File Operations
```magma
load "myfile.m";
save "workspace.m";

// Package imports
import "algebra/groups.m" : SymmetricGroup, AlternatingGroup;
```

## Complex Examples

### Matrix Operations
```magma
M := Matrix(Integers(), [[1, 2], [3, 4]]);
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