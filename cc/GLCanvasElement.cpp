//
//  GLCanvasElement.cpp
//  glelement
//
//  Created by zhang hailong on 14-6-19.
//  Copyright (c) 2014年 hailong.org. All rights reserved.
//

#include "GLCanvasElement.h"


namespace cc {
    
    IMP_CLASS(GLCanvasElement, GLElement)
    
    GLCanvasElement::GLCanvasElement(){
        transform = GLMatrix4Identity;
        alpha = 1.0f;
        scale = 1.0f;
        hidden = false;
    }
    
    GLCanvasElement::~GLCanvasElement(){
        
    }
    
    void GLCanvasElement::draw(GLContext * context){
        
    }
    
    
    void GLCanvasElement::begin(GLContext * context){
        
        context->saveState();
        
        context->translation(position.x, position.y, position.z);
        context->scale(scale, scale, scale);
        context->alpha(alpha);
        context->transform(transform);
        
    }
    
    void GLCanvasElement::end(GLContext * context){
        
        context->restoreState();
        
    }
}
