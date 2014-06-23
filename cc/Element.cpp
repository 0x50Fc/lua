//
//  Element.cpp
//  element
//
//  Created by zhang hailong on 14-6-19.
//  Copyright (c) 2014年 hailong.org. All rights reserved.
//

#include "Element.h"

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
    
}
