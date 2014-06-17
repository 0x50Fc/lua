
require("Logic")

Logic.Game = Class:extend("Logic.Game",Logic.Object);

Logic.Game.Status = {None = 0, Playing = 1, Pause = 2};

function Logic.Game:init()

  self:setValue("speed",1.0);
  self:setValue("status",Logic.Game.Status.None);
  self:setValue("scene",nil);
  
end

function Logic.Game:openScene(scene)
  if self.scene then
    self.scene:setValue("game",nil);
  end
  self:setValue("scene",scene);
  if self.scene then
    self.scene:setValue("game",nil);
  end
end

function Logic.Game:play()
  if self.status == Logic.Game.Status.None then
    self:setValue("status",Logic.Game.Status.Playing);
  end
end

function Logic.Game:pause()
  if self.status == Logic.Game.Status.Playing then
    self:setValue("status",Logic.Game.Status.Pause);
  end
end

function Logic.Game:resume()
  if self.status == Logic.Game.Status.Pause then
    self:setValue("status",Logic.Game.Status.Playing)
  end
end

function Logic.Game:stop()
  if self.status ~= Logic.Game.Status.None then
    self:setValue("status",Logic.Game.Status.None)
  end
end


