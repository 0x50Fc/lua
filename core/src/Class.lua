
Object = {};

function Object:new(...)

    local object = {};
    
    setmetatable(object,{ __index = self });
    
    object.class = self;
    object.super = self.super;
    
    if object.init then
        object:init(...);
    end
    
    return object;
end

function Object:toString()
  return "Object";
end

function Object:className()
  return self.class.name; 
end

function Object:isKindClassOf(class)
  local c = self.class;
  while c and c ~= class do
    c = c.super;
  end
  return c == class;
end

Class = {};

function Class:extend(className,superClass)

    local class = {name = className};
    
    if superClass then 
        class.super = superClass;
        setmetatable(class,{ __index = superClass });
    else 
        class.super = Object;
        setmetatable(class,{ __index = Object });
    end  

    Class[className] = class;
    
    return class;
   
end

function Class:isKindClassOf(class,ofClass)
  local c = class;
  while c and c ~= ofClass do
    c = c.super;
  end
  return c == ofClass;
end

