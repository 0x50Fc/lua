
Object = {};

function Object:value(key)
  return self.object[key];
end

function Object:setValue(key,value)
  self.object[key] = value;
  return self;
end

function Object:call(key,...)
  local fn = self.object[key];
  if fn and type(fn) == "function" then
    fn(self.object,...);
  end
  return self;
end

function Object:pcall(key,...)
  local fn = self.object[key];
  if fn and type(fn) == "function" then
    return fn(self.object,...);
  end
end

function O(class)

  if not class then
    return;
  end
  
  local o = {};
  
  setmetatable(o,{ __index = Object});
  
  if type(class) == "string" then
    o.object = cc.new(class);
  else
    o.object = class;
  end

  return o;

end


