load"one.m";
iload"two.m";
save"state";
restore"state";

function Foo(W:Context:=false,
Verbose:=true)
return W@@Context;
end function;

procedure Bar(~W:Context:=false)
W:=W@@Context;
end procedure;

intrinsic Baz(~W :: RngIntElt,
`Field:Context:=false) -> RngIntElt,
BoolElt
{Documentation stays intact.}
return W,Context;
end intrinsic;
