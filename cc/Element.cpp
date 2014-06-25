//
//  Element.cpp
//  element
//
//  Created by zhang hailong on 14-6-19.
//  Copyright (c) 2014年 hailong.org. All rights reserved.
//

#include "Element.h"

#include "Context.h"

#include "Log.h"

#include "lua.hpp"

namespace cc {
    
    IMP_CLASS(Element, Object)
    
    Element::Element():_parent(NULL){
        
    }
    
    Element::~Element(){
        
        std::vector<Element *>::iterator i = _childs.begin();
        
        while (i != _childs.end()) {
            
            Element * element = * i;
            
            element->release();
            
            i ++;
        }
        
    }
    
    Element * Element::parent(){
        return _parent;
    }
    
    Element * Element::childAt(int index){
        if(index >=0 && index < _childs.size()){
            return _childs[index];
        }
        return NULL;
    }
    
    int Element::childCount(){
        return (int) _childs.size();
    }
    
    void Element::addChild(Element * element){
        element->retain();
        element->removeFromParent();
        element->_parent = this;
        _childs.push_back(element);
    }
    
    void Element::insertChild(Element * element,int index){
        element->retain();
        element->removeFromParent();
        element->_parent = this;
        _childs.insert(_childs.begin() + index, element);
    }
    
    void Element::removeChildAt(int index){
        
        if(index >=0 && index < _childs.size()){
            Element * element = _childs[index];
            element->_parent = NULL;
            element->release();
            _childs.erase(_childs.begin() + index);
        }
    }
    
    void Element::removeChild(Element * element){
        
        std::vector<Element *>::iterator i = _childs.begin();
        
        while (i != _childs.end()) {
            
            Element * child = * i;
            
            if(child == element){
                
                child->_parent = NULL;
                child->release();
                
                _childs.erase(i);
                
                break;
            }

            i ++;
        }
        
    }
    
    void Element::removeFromParent(){
        
        if(_parent != NULL){
            _parent->removeChild(this);
        }
        
    }
    
    Element * Element::parentOfClass(Class * elementClass){
        
        Element * el = _parent;
        
        while (el) {
            if(el->isKindOfClass(elementClass)){
                return el;
            }
            el = el->_parent;
        }
        
        return NULL;
    }
    
    static int ElementElementsOfClassFunction(lua_State * lua,Object * object,const char * key,InvokeArgs * args){
        
        Element * element = (Element *) object;
        
        const char * className = ValueToString(InvokeArgsValue(args, 0), NULL);
        
        if(className){
            
            Class * clazz = Context::getClass(lua,className);
            
            if(clazz){
                
                std::vector<Element *> elements;
                
                element->elementsOfClass(elements, clazz, ValueToInt(InvokeArgsValue(args, 1), -1));
                
                lua_newtable(lua);
                
                
                
            }
            else {
                Log("Not Found Class %s",className);
            }
            
        }
        
        return 0;
    }
    
    
    Value Element::value(const char * key){
        
        if(strcmp(key, "name") == 0){
            return Value(_name.c_str());
        }
        else if(strcmp(key, "elementsOfClass") == 0){
            return Value(ElementElementsOfClassFunction);
        }
        else {
            return Object::value(key);
        }
    }
    
    void Element::setValue(const char * key,Value value){
        if(strcmp(key, "name") == 0){
            _name = ValueToString(value, "");
        }
        else {
            Object::setValue(key, value);
        }
    }

    Value Element::invoke(const char * key,InvokeArgs * args){
        
        if(strcmp(key, "add") == 0){
            
            if(args->count >0){
                Object * v = ValueToObject(InvokeArgsValue(args, 0));
                if(v && v->isKindOfClass(& Element::clazz)){
                    addChild((Element *) v);
                }
            }
            
            return Value();
        }
        else if(strcmp(key, "remove") == 0){
            
            removeFromParent();
            
            return Value();
        }
        else if(strcmp(key, "parentOfClass") == 0){
            
            const char * className = ValueToString(InvokeArgsValue(args, 0), NULL);
            
            if(className){
                Context * ctx = Context::current();
                if(ctx){
                    Class * clazz = ctx->getClass(className);
                    if(clazz){
                        return Value(parentOfClass(clazz));
                    }
                    else {
                        Log("Not Found Class %s",className);
                    }
                }
            }
            return Value();
        }
        else{
            return Object::invoke(key, args);
        }
    }
    
    const char * Element::name(){
        return _name.c_str();
    }
    
    void Element::setName(const char * value){
        _name = value;
    }
    
    void Element::doAction(Action * action){
        if(_parent != NULL ){
            _parent->doAction(action);
        }
    }
    
    void Element::elementsOfClass(std::vector<Element *> & elements,Class * elementClass,int level){
        
        if(level ==0){
            return;
        }
        
        int c = childCount();
        
        for(int i=0;i<c;i++){
            
            Element * child = childAt(i);
            
            if(child->isKindOfClass(elementClass)){
                elements.push_back(child);
            }
            
        }
        
        if(level - 1 != 0){
            
            for(int i=0;i<c;i++){
                
                Element * child = childAt(i);
                
                child->elementsOfClass(elements, elementClass, level - 1);
                
            }
        }
    }
    
    void Element::elementsOfClass(std::vector<Element *> & elements,Class * elementClass){
        elementsOfClass(elements,elementClass,-1);
    }

}
