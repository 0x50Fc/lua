//
//  GLAnimPathElement.cpp
//  glelement
//
//  Created by zhang hailong on 14-6-23.
//  Copyright (c) 2014年 hailong.org. All rights reserved.
//

#include "GLAnimPathElement.h"

namespace cc {
    
    IMP_CLASS(GLAnimPathElement, GLAnimationElement)
    
    GLAnimPathElement::GLAnimPathElement(){
        
    }
    
    GLAnimPathElement::~GLAnimPathElement(){
        
    }
    
    void GLAnimPathElement::tick(GLSchedule * schedule){
        
    }

    void GLAnimPathElement::invoke(const char * key,InvokeArgs * args){
        if(strcmp(key, "clearPositions") == 0){
            clearPositions();
        }
        else if(strcmp(key, "addPosition") == 0){
            
            GLVector3 v3 = {
                (GLfloat) ValueToDouble(InvokeArgsValue(args, 0),0.0)
                              , (GLfloat) ValueToDouble(InvokeArgsValue(args, 1),0.0)
                              , (GLfloat) ValueToDouble(InvokeArgsValue(args, 2),0.0)};
            
            addPosition(v3);
            
        }
        else {
            GLAnimationElement::invoke(key, args);
        }
    }
    
    void GLAnimPathElement::setPositions(GLVector3 * positions,int length){
        
    }
    
    void GLAnimPathElement::clearPositions(){
        _positions.clear();
    }
    
    void GLAnimPathElement::addPosition(GLVector3 position){
        _positions.push_back(position);
    }
    
    GLVector3 GLAnimPathElement::position(){
        
        size_t s = _positions.size();
        
        if(s == 0){
            return GLVector3({0.0,0.0,0.0});
        }
        else if(s == 1){
            return _positions[0];
        }
        else {
            size_t i = (size_t)(value() * s) % s;
            return GLVector3({0.0,0.0,0.0});
        }
    }
    
}
