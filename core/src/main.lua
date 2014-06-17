
require("Class")

local function main()

local A = {};

A.a = function()

  print "A";
  
end

local B = {};


setmetatable(B,{ __index = A })

local C = {};

setmetatable(C,{ __index = B })

B.a()

end

main()

local o = Object:new();

print(o.toString());
