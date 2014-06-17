
require("Logic")

Logic.Scene = Class:extend(Logic.Object);

function Logic.Scene:toString()
  return self.super.toString(self);
end
