//
//  GLContext.cpp
//  glelement
//
//  Created by zhang hailong on 14-6-19.
//  Copyright (c) 2014年 hailong.org. All rights reserved.
//

#include "GLContext.h"

namespace cc {
    
    GLContext::GLContext(int width,int height){
        _width = width;
        _height = height;
        _state = new GLContextState();
    }
    
    GLContext::~GLContext(){
        
        GLContextState * s = _state , *t;
        
        while (s) {
            
            t = s->prev;
            
            delete s;
            
            s = t;
        }
        
    }
    
    int GLContext::width(){
        return _width;
    }
    
    int GLContext::height(){
        return _height;
    }
    
    void GLContext::setViewport(int width,int height){
        _width = width;
        _height = height;
    }
    
    void GLContext::translation(float x,float y,float z){
        _state->transform = GLMatrix4Translate(_state->transform, x, y, z);
    }
    
    void GLContext::scale(float x,float y,float z){
        _state->transform = GLMatrix4Scale(_state->transform, x, y, z);
    }
    
    void GLContext::rotate(float radians, float x, float y, float z){
        _state->transform = GLMatrix4Rotate(_state->transform, radians, x, y, z);
    }
    
    void GLContext::alpha(float alpha){
        _state->alpha = _state->alpha * alpha;
    }
    
    void GLContext::zIndex(){
        _state->zIndex += 0.000001;
    }
    
    GLContextState * GLContext::state(){
        return _state;
    }
    
    void GLContext::saveState(){
        
        GLContextState * s = new GLContextState(_state);
        
        s->prev = _state;
        
        _state = s;
        
    }
    
    void GLContext::restoreState(){
        
        GLContextState * s = _state->prev;
        
        delete _state;
        
        _state = s;
    }
    
    virtual float x(float screenX);
    
    virtual float y(float screenY);
    
    virtual float screenX(float x);
    
    virtual float screenY(float y);
    
}
