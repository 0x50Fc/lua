
require("Logic")

Logic.Layer = Class:extend("Logic.Layer",Logic.Object);

function Logic.Layer:locationEntity(entity)
  return entity:value("x"),entity:value("y"),entity:value("z");
end


