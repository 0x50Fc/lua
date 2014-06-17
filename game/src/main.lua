
require("Scene")

local function main()

local s = Logic.Scene:new();

s:setValue("a",123);

print(s:className());

end
main()
