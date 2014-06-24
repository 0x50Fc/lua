//
//  GLTacticElement.cpp
//  glelement
//
//  Created by zhang hailong on 14-6-24.
//  Copyright (c) 2014年 hailong.org. All rights reserved.
//

#include "GLTacticElement.h"


namespace cc {
    
    IMP_CLASS(GLTacticElement,GLAnimationElement)
    
    GLTacticElement::GLTacticElement():status(0){
        
    }
    
    GLTacticElement::~GLTacticElement(){
        
    }
    
    Value GLTacticElement::value(const char * key){
        if(strcmp(key,"status") == 0){
            return Value(status);
        }
        else {
            return GLAnimationElement::value(key);
        }
    }
    
    void GLTacticElement::setValue(const char * key,Value value){
        if(strcmp(key,"status") == 0){
            status = ValueToInt(value,status);
        }
        else {
            GLAnimationElement::setValue(key,value);
        }
    }
    
    
}