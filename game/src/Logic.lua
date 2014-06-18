
require("Class")

Logic = {};

Logic.Object = Class:extend("Logic.Object",Object);

function Logic.Object.value(self,key)
  return self[key];
end

function Logic.Object:value(key)
  return Logic.Object.value(self,key);
end

function Logic.Object.setValue(self,key,value)
  self[key] = value;
end

function Logic.Object:setValue(key,value)
  Logic.Object.setValue(self,key,value);
end


