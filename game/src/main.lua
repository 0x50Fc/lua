
require("Scene")

local function main()

local s = Logic.Scene:new();

s:setValue("a",123);

print(s:className());

local a = {};

table.insert(a,12222);

print(a[1]);

end
main()
