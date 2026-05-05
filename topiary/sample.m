function factorial(n)
if n le 1 then
    return 1;
  else
return n * factorial(n - 1);
    end if;
end function;

function fibonacci(n)
    if n lt 2 then
return n;
    end if;
    a := 0;
b := 1;
  for i := 2 to n do
        c := a + b;
    a := b;
      b := c;
  end for;
return b;
end function;
