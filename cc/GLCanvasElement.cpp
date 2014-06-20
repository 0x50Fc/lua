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
    
    GLCanvasElement::GLCanvasElement()
    :transform(GLMatrix4Identity)
    ,alpha(1.0)
    ,scale(1.0)
    ,hidden(false)
    ,position({0.0,0.0}){

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
    
    Value GLCanvasElement::value(const char * key){
        
        if(strcmp(key, "hidden") == 0){
            return Value(hidden);
        }
        else if(strcmp(key, "alpha") == 0){
            return Value((double)alpha);
        }
        else if(strcmp(key, "scale") == 0){
            return Value((double)scale);
        }
        else {
            return GLElement::value(key);
        }
        
    }
    
    void GLCanvasElement::setValue(const char * key,Value value){
        
        if(strcmp(key, "hidden") == 0){
            hidden = ValueToBoolean(value, false);
        }
        else if(strcmp(key, "alpha") == 0){
            alpha = ValueToDouble(value, 0.0);
        }
        else if(strcmp(key, "scale") == 0){
            scale = ValueToDouble(value, 0.0);
        }
        else {
            GLElement::setValue(key,value);
        }
        
    }
    
}
