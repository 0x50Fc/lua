//
//  GLControlElement.cpp
//  glelement
//
//  Created by zhang hailong on 14-6-24.
//  Copyright (c) 2014年 hailong.org. All rights reserved.
//

#include "GLControlElement.h"

#include "GLScreenElement.h"

namespace cc {
    
    IMP_CLASS(GLControlElement, GLLayerElement)
    
    GLControlElement::GLControlElement():touchEnabled(true){
        
    }
    
    GLControlElement::~GLControlElement(){
        
    }
    
    bool GLControlElement::touch(GLTouch * touch,GLTouchState touchState, GLVector2 location){
        if(touchState == GLTouchStateBegin){
            return location.x >=0 && location.y >=0 && location.x < frame.size.width && location.y < frame.size.height;
        }
        return true;
    }
    
    Value GLControlElement::value(const char * key){
        
        if(strcmp(key, "touchEnabled") == 0){
            return Value(touchEnabled);
        }
        else {
            return GLLayerElement::value(key);
        }
    }
    
    
    void GLControlElement::setValue(const char * key,Value value){
        
        if(strcmp(key, "touchEnabled") == 0){
            touchEnabled = ValueToBoolean(value, touchEnabled);
        }
        else {
            GLLayerElement::setValue(key, value);
        }
    }
    
}
