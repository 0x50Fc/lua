//
//  GLElement.cpp
//  glelement
//
//  Created by zhang hailong on 14-6-19.
//  Copyright (c) 2014年 hailong.org. All rights reserved.
//

#include "GLElement.h"


namespace cc {
    
    
    IMP_CLASS(GLElement, Element)
    
    GLElement::GLElement(){
        transform = GLMatrix4Identity;
        alpha = 1.0f;
        scale = GLVector3Make(1.0f, 1.0f, 1.0f);
    }
    
    GLElement::~GLElement(){
        
    }
    
    void GLElement::draw(GLContext * context){
        
    }
    
    
    void GLElement::begin(GLContext * context){
        
    }
    
    void GLElement::end(GLContext * context){
        
    }
    
}
