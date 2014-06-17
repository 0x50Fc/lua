
require("Class")

Logic = {};

Logic.Object = Class:extend("Logic.Object",Object);

function Logic.Object:value(key)
  return self[key];
end

function Logic.Object:setValue(key,value)
  self[key] = value;
end
