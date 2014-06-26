//
//  GLScreenElement.cpp
//  glelement
//
//  Created by zhang hailong on 14-6-24.
//  Copyright (c) 2014年 hailong.org. All rights reserved.
//

#include "GLScreenElement.h"

namespace cc {

    IMP_CLASS(GLScreenElement, GLCanvasElement)
    
    GLScreenElement::GLScreenElement():_zPosition(0){
        
    }
    
    GLScreenElement::~GLScreenElement(){
        
    }
    
    void GLScreenElement::begin(GLContext * context){
        
        context->saveState();
        
        GLContextState * state = context->state();

        state->transform = GLMatrix4Identity;
        state->alpha = 1.0;
        
        context->zIndex += _zPosition;
        
    }
    
    GLfloat GLScreenElement::zPosition(){
        return _zPosition;
    }
    
    void GLScreenElement::setZPosition(GLfloat value){
        _zPosition = value;
    }
    
    Value GLScreenElement::value(const char * key){
        if(strcmp(key, "zPosition") == 0){
            return Value(_zPosition);
        }
        else {
            return GLCanvasElement::value(key);
        }
    }
    
    void GLScreenElement::setValue(const char * key,Value value){
        if(strcmp(key, "zPosition") == 0){
            _zPosition = ValueToDouble(value, 0);
        }
        else {
            GLCanvasElement::setValue(key,value);
        }
    }
    
}
