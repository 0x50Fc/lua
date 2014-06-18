
require("Logic")

Logic.Scene = Class:extend("Logic.Scene",Logic.Object);

function Logic.Scene.init(self)
  self.super.init(self);
  self.layers = {};
  self.entitys = {};
end

function Logic.Scene.addLayer(self,layer,key)
  table.insert(self.layers,layer);
  if key then
    self:setValue(key,layer);
  end
  layer:setValue("scene",self);
end

function Logic.Scene:addLayer(layer,key)
  self.addLayer(self,layer,key);
end

function Logic.Scene.addEntity(self,entity,key)
  
  self.entitys:insert(entity);
  
  if key then
    self:setValue(key,entity);
  end
  
  entity:setValue("scene",self);
  
end

function Logic.Scene:addEntity(entity,key)
  self.addEntity(self,entity,key);
end

function Logic.Scene.removeEntityForKey(self,key)
  
  local e = self:value(key);
  
  if e then
    for i = 1, table.getn(self.entitys), 1 do
      local en = self.entitys[i];
      if en == e then
        table.remove(self.entitys,i);
        break;
      end
    end
    e:setValue("scene",nil);
  end

end

function Logic.Scene:removeEntityForKey(key)
  self.removeEntityForKey(self,key);
end

function Logic.Scene.removeEntity(self,entity)
  for i = 1, table.getn(self.entitys), 1 do
    local en = self.entitys[i];
    if en == entity then
      table.remove(self.entitys,i);
      break;
    end
  end
  entity:setValue("scene",nil);
end

function Logic.Scene:removeEntity(entity)
  self.removeEntity(self,entity);
end

function Logic.Scene:doAction(action , sender)
  self.doAction(self,action,sender);
end

function Logic.Scene.doAction(self,action , sender)
  
end
