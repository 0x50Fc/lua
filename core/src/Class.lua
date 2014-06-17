
Object = {};

function Object:new(...)

    local object = {};
    
    setmetatable(object,{ __index = self });
    
    if object.init then
        object.init(...);
    end
    
    return object;
end

function Object:toString()
    return "Object";
end

Class = {};

function Class:extend(superClass)

    local class = {};
    
    if superClass then 
        class.super = superClass;
        setmetatable(class,{ __index = superClass });
    else 
        class.super = Object;
        setmetatable(class,{ __index = Object });
    end  

    return class;
   
end



