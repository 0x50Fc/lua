
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

function Object.toString(self)
  return "Object";
end

function Object:toString()
  return Object.toString(self)
end

function Object.className(self)
  return self.class.name; 
end

function Object:className()
  return Object.className(self);
end

function Object.isKindClassOf(self,class)
  local c = self.class;
  while c and c ~= class do
    c = c.super;
  end
  return c == class;
end

function Object:isKindClassOf(class)
  return Object.isKindClassOf(self,class);
end

function Object:init(...)
  Object.init(self,...);
end

function Object.init(self,...)

end

Class = {};

function Class:extend(className,superClass)

    local class = {name = className};
    
    if superClass then 
        setmetatable(class,{ __index = superClass });
        class.super = superClass;
    else 
        setmetatable(class,{ __index = Object });
        class.super = Object;
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

