f:=function(x) return x; end function;
g  :=  function (a, b)
return a+b;
end function;
p:=procedure(~x) x+:=1; end procedure;
q :=Apply(function(x) return x+1; end function ,[1,2,3]);
