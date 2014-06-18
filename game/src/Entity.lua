
require("Logic")

-- ΚµΜε

Logic.Entity = Class:extend("Logic.Entity",Logic.Object);

function Logic.Entity.init(self,...)
  self.super.init(self,...);
  self.tactics = {};
end

function Logic.Entity.addTactic(self,tactic,key)
 
  self.tactics:insert(tactic);
  
  if key then
    self:setValue(key,tactic);
  end
  
  tactic:setValue("entity",self);
  
end

function Logic.Entity:addTactic(tactic,key)
  self.addTactic(self,tactic,key);
end
