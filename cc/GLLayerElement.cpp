//
//  GLLayerElement.cpp
//  glelement
//
//  Created by zhang hailong on 14-6-19.
//  Copyright (c) 2014年 hailong.org. All rights reserved.
//

#include "GLLayerElement.h"

namespace cc {
    
    
    IMP_CLASS(GLLayerElement,GLElement)
    
    
    GLLayerElement::GLLayerElement(){
        
    }
    
    GLLayerElement::~GLLayerElement(){
        
    }
    
    void GLElement::draw(GLContext * context){
        
    }
    
    void GLElement::begin(GLContext * context){
        
        position = GLVector3Make(<#float x#>, <#float y#>, <#float z#>)
        
    }
    
}