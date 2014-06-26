//
//  SKPlayerElement.cpp
//  shank
//
//  Created by zhang hailong on 14-6-26.
//  Copyright (c) 2014年 hailong.org. All rights reserved.
//

#include "SKPlayerElement.h"

#include "GLSpriteElement.h"

#include "SKSceneElement.h"

namespace sk {
    
    IMP_CLASS(SKPlayerElement, cc::GLRoleElement)
    
    SKPlayerElement::SKPlayerElement():_sceneElement(NULL),moveSpeed(10){
        
    }
    
    SKPlayerElement::~SKPlayerElement(){
        
    }
    
    SKSceneElement * SKPlayerElement::sceneElement(){
        
        if(_sceneElement == NULL){
            _sceneElement = (SKSceneElement *) parentOfClass(& SKSceneElement::clazz);
        }
        
        return _sceneElement;
    }
    
    void SKPlayerElement::tick(cc::GLSchedule * schedule){
        cc::GLRoleElement::tick(schedule);
        
        SKSceneElement * scene = sceneElement();
        
        if(scene){
            
            cc::Element * p = parent();
            
            if(p && p->isKindOfClass(& cc::GLSpriteElement::clazz)){
                cc::GLSpriteElement * sprite = (cc::GLSpriteElement *) p;
                sprite->position = scene->playScreenPosition();
            }            
        }
        
    }
    
    cc::Value SKPlayerElement::value(const char * key){
        if(strcmp(key, "moveSpeed") == 0){
            return cc::Value(moveSpeed);
        }
        else {
            return cc::GLRoleElement::value(key);
        }
    }
    
    void SKPlayerElement::setValue(const char * key,cc::Value value){
        if(strcmp(key, "moveSpeed") == 0){
            moveSpeed = cc::ValueToDouble(value, 0);
        }
        else {
            cc::GLRoleElement::setValue(key,value);
        }
    }

}
