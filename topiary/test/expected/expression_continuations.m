x := a +
    b +
    c;
y := a
    and b
    and c;
z := a*
    b;
w := a @@
    f;
v := a
    where a := b
    where b := 3;
t := test
    select yes
    else no;

function F(x)
    return x +
        1;
end function;

function G()
    return
        Foo(a,
            b);
end function;

function H()
    return [a,
        b];
end function;

if a
    and b then
    assert a
        or b;
end if;

x :=
    Foo(a,
        b);
x := // Explain the assigned call.
    Foo(a,
        b);
y :=
    [
        1, 2,
        3, 4
    ];
z := a + Foo(
        b,
        c
    );
x, y := a,
    b;
print a,
    b;
