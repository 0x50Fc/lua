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
        
        state->zIndex = _zPosition;
        state->transform = GLMatrix4Identity;
        state->alpha = 1.0;
        
    }
    
    GLfloat GLScreenElement::zPosition(){
        return _zPosition;
    }
    
    void GLScreenElement::setZPosition(GLfloat value){
        _zPosition = value;
    }
    
    
}
