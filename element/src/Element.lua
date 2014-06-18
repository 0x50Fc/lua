
Element = {

  value = function(element,key)
    local v;
    if element.elementValue then
      v = element:elementValue(key);
    end
    if element.values then
      element.values[key] = v;
    end
    return v;
  end;
  
  setValue = function(element,key,value)
    if not element.values then
      element.values = {};
    end
    element.values[key] = value;
    if element.elementSetValue then
      v = element:elementSetValue(key,value);
    end
  end; 
  
  addChild = function(element,child)
    if not element.childs then
      element.childs = {};
    end
    child.parent = element;
    table.insert(element.childs,child);
    if element.elementChildAdded then
      element:elementChildAdded(child);
    end
  end;
  
  removeChildAt = function(element,index)
    if element.childs then
      local child = element.childs[index];
      if child then
        child.parent = nil;
        table.remove(element.childs,index);
        if element.elementChildRemoved then
          element:elementChildRemoved(child);
        end
      end
    end
  end;
  
  removeChild = function(element,child)
    if element.childs then
      for i = 1, table.getn(element.childs), 1 do
        local e = element.childs[i];
        if e == child then
          child.parent = nil;
          table.remove(element.childs,i);
          if element.elementChildRemoved then
            element:elementChildRemoved(child);
          end
          break;
        end
      end
    end
  end;
  
  new = function(element,parent)
  
    element.__mode = "parent";
    element.parent = parent;
    
    if element.childs then
      for i = 1, table.getn(element.childs), 1 do
        local e = element.childs[i];
        Element.new(e,element);
      end
    end
    
    return element;
    
  end;
  
};
