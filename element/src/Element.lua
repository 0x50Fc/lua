
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

_ElementById = {};

function E(class,id)

  if not class then
    return;
  end
  
  if type(class) == "string" and string.sub(class,1,1) == "#" then
    return _ElementById[string.sub(class,2)];
  end

  local e = {};
  
  setmetatable(e,{ __index = Element , __mode = "parent"});
  
  if type(class) == "string" then
    e.object = cc.new(class);
  else
    e.object = class;
  end
  
  if id then
    _ElementById[id] = e;
  end

  return e;

end
