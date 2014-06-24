
Element = {};

setmetatable(Element,{__index = Object});

function Element:add(element)
  
  if not self.childs then
    self.childs = {};
  end
  
  element.parent = self;

  table.insert(self.childs,element);

  self.object:add(element.object);

  return self;
end

function Element:remove()
  if self.parent and self.parent.childs then
    table.remove(self.parent.childs,self);
  end
  self.parent = nil;
  self.object:remove();
  return self;
end

function E(class)

  if not class then
    return;
  end

  local e = {};
  
  setmetatable(e,{ __index = Element , __mode = "parent"});
  
  if type(class) == "string" then
    e.object = cc.new(class);
  else
    e.object = class;
  end

  return e;

end
