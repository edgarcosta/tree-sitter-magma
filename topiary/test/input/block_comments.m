function F(x)
// Function header.
if x then
// First branch.
return 1;
// First branch tail.
elif false then
// Comment-only branch.
else
/* Otherwise. */
return 0;
// Else tail.
end if;
// Function tail.
end function;

procedure Empty()
// No statements.
end procedure;

intrinsic EmptyIntrinsic()
{Documentation.}
// No statements here either.
end intrinsic;

for i:=1 to 3 do
// Loop header.
while true do
// While header.
break;
// While tail.
end while;
// Loop tail.
end for;

repeat
// Repeat header.
x+:=1;
// Repeat tail.
until x gt 3;

try
// Try header.
F();
// Try tail.
catch e
// Catch header.
print e;
// Catch tail.
end try;

try F(); catch e
// Empty catch.
end try;
