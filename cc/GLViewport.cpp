//
//  GLViewport.cpp
//  glelement
//
//  Created by zhang hailong on 14-6-26.
//  Copyright (c) 2014年 hailong.org. All rights reserved.
//

#include "GLViewport.h"

namespace cc {
    
    IMP_CLASS(GLViewport, Object)
    
    
    GLViewport::GLViewport():_width(0),_height(0),_project(GLMatrix4Identity){
        
    }
    
    GLViewport::~GLViewport(){
        
    }
    
    void GLViewport::setViewport(GLfloat width,GLfloat height){
        _width = width;
        _height = height;
        _project = cc::GLMatrix4MakeScale(2.0f, - 2.0 * width / height, - 0.000001);
        _project = cc::GLMatrix4Translate(_project, -0.5, -0.5 * height / width, 0);
    }
    
    GLfloat GLViewport::width(){
        return _width;
    }
    
    GLfloat GLViewport::height(){
        return _height;
    }
    
    GLfloat GLViewport::global(GLfloat screen){
        return screen / _width;
    }
    
    GLfloat GLViewport::screen(GLfloat global){
        return global * _width;
    }
    
    GLMatrix4 GLViewport::project(){
        return _project;
    }
    
}