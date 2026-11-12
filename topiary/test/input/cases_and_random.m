case x:
// Case header.
when 1:
// First case.
x:=2;
// First case tail.
when 2:
// Empty case.
else:
// Default header.
x:=3;
// Default tail.
end case;

case x: when 1: x:=2; else x:=3; end case;
case x: when 1: /* Empty. */ end case;

for random i,j in S do
print i,j;
end for;

x:=case<a|1:b,
2:c
default:d>;
y:=[a:a->i in S];
z:=random{1,2};
w:=rep{1,2};
q:=exists(i){i:i in S|i gt 0};
print x:Maximal;
