x:=Foo(
a,b,
Bar(c,
d)
);
y:=[
1,2,
3,4
];
s:={1,
2};
l:=[*1,
2*];
i:={@1,
2@};
f:={!1,
2!};
m:={*1,
2*};
t:=<1,
2>;
v:=\[1,
2];
r:=recformat<a:RngIntElt,
b:BoolElt>;
q:=quo<R|
x,y
:Option:=true>;
g:=map<X->Y|
x:->x^2>;
c:=[x^2
:x in S
|x gt 0];
p:=(a +
b);
Foo(
// Argument comment.
a,
b
// Closing comment.
);
Foo(
// No arguments.
);
