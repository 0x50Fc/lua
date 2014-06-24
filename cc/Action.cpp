//
//  Action.cpp
//  element
//
//  Created by zhang hailong on 14-6-24.
//  Copyright (c) 2014年 hailong.org. All rights reserved.
//

#include "Action.h"

#include "Element.h"

namespace cc {
    
    IMP_CLASS(Action, Object)
    
    Action::Action():_element(NULL){
        
    }
    
    Action::Action(Element * element){
        _element = element;
        _element->retain();
    }
    
    Action::~Action(){
        if(_element){
            _element->release();
        }
    }
    
    Value Action::value(const char * key){
        if(strcmp(key, "element") == 0){
            return Value(_element);
        }
        else {
            return Object::value(key);
        }
    }
    
    Element * Action::element(){
        return _element;
    }
    
}
