//
//  GLSceneElement.cpp
//  glelement
//
//  Created by zhang hailong on 14-6-24.
//  Copyright (c) 2014年 hailong.org. All rights reserved.
//

#include "GLSceneElement.h"

#include "Context.h"

namespace cc {
    
    IMP_CLASS(GLSceneElement, GLElement)
    
    GLSceneElement::GLSceneElement():_mapElement(NULL){
        
    }
    
    GLSceneElement::~GLSceneElement(){

    }
    
    GLMapElement * GLSceneElement::mapElement(){
        return _mapElement;
    }
    
    void GLSceneElement::addChild(Element * element){
        if(_mapElement ==  NULL && element->isKindOfClass(& GLMapElement::clazz)){
            _mapElement = (GLMapElement *) element;
        }
        GLElement::addChild(element);
    }
    
    void GLSceneElement::removeChild(Element * element){
        if(_mapElement == element){
            _mapElement = NULL;
        }
        GLElement::removeChild(element);
    }
    
    void GLSceneElement::doAction(Action * action){
        
        Context * ctx = Context::current();
        
        if(ctx){
            
            Value v(action);
            
            ctx->globalObjectInvoke("root", "doAction", & v, 1);
            
        }
        
        GLElement::doAction(action);
    }
    
}
