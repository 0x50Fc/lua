
Element = {};

function Element:value(key)
  return self.object[key];
end

function Element:setValue(key,value)
  self.object[key] = value;
  return self;
end

function Element:add(element)
  self.object.add(element);
  return self;
end

function Element:call(key,...)
  local fn = self.object[key];
  if fn and type(fn) == "function" then
    fn(self.object,...);
  end
  return self;
end

function E(class)

  local e = {};
  
  setmetatable(e,{ __index = Element });
  
  if type(class) == "string" then
    e.object = cc.new(class);
  else
    e.object = class;
  end

  return e;

end
