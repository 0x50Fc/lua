
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

function Element:elementsOfClass(class,level)
  local fn = self.object["elementsOfClass"];
  if fn and type(fn) == "function" then
    return fn(self.object,class,level);
  end
end

function Element:elementOfClass(class,level)
  local fn = self.object["elementOfClass"];
  if fn and type(fn) == "function" then
    return fn(self.object,class,level);
  end
end

ElementList = {};

function ElementList:setValue(key,value)
  for i,v in ipairs(self.objects) do
    v[key] = value;
  end
  return self;
end

function ElementList:call(key,...)
  for i,v in ipairs(self.objects) do
    local fn = v[key];
    if fn and type(fn) == "function" then
      fn(v,...);
    end
  end
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
  local t = type(class);
  
  if t == "string" then
    setmetatable(e,{ __index = Element , __mode = "parent"});
    e.object = cc.new(class);
  elseif t == "table" then
    setmetatable(e,{ __index = ElementList });
    e.objects = class;
  else
    setmetatable(e,{ __index = Element , __mode = "parent"});
    e.object = class;
  end
  
  if id then
    _ElementById[id] = e;
  end

  return e;

end
