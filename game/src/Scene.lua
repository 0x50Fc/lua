
require("Logic")

Logic.Scene = Class:extend("Logic.Scene",Logic.Object);

function Logic.Scene:init()
  self.layers = {};
end

function Logic.Scene:addLayer(layer,key)
  self.layers:insert(layer);
  if key then
    self:setValue(key,layer);
  end
end

function Logic.Scene:doAction(action , sender)
  
end
