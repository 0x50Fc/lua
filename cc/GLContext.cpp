//
//  GLContext.cpp
//  glelement
//
//  Created by zhang hailong on 14-6-19.
//  Copyright (c) 2014年 hailong.org. All rights reserved.
//

#include "GLContext.h"

#include "Log.h"

namespace cc {
    
    IMP_CLASS(GLContext, Object)
    
    GLContext::GLContext()
        :_width(0),_height(0),_loader(NULL){
        projectTransform = GLMatrix4MakeScale(1.0f, - 1.0f , -1.0f);
        _state = new GLContextState();
    }
    
    GLContext::GLContext(GLLoader * loader)
        :_width(0),_height(0),_loader(loader){
            
        loader->retain();
        projectTransform = GLMatrix4MakeScale(1.0f, - 1.0f , -1.0f);
        _state = new GLContextState();
    }
    
    GLContext::~GLContext(){
        
        GLContextState * s = _state , *t;
        
        while (s) {
            
            t = s->prev;
            
            delete s;
            
            s = t;
        }
        
        {
            std::map<std::string,GLProgram *>::iterator i = _programs.begin();
            
            while (i != _programs.end()) {
                
                i->second->release();

                i ++;
            }
        }
        
        {
        
            std::map<std::string,GLImage *>::iterator i = _images.begin();
            
            while (i != _images.end()) {
                
                i->second->release();
                
                i ++;
            }
            
        }
        
        if(_loader){
            _loader->release();
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
        projectTransform = cc::GLMatrix4MakeScale(2.0f, - 2.0 * width / height, - 0.000001);
        projectTransform = cc::GLMatrix4Translate(projectTransform, -0.5, -0.5 * height / width, 0);
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
    
    void GLContext::transform(GLMatrix4 transform){
        _state->transform = GLMatrix4Multiply(_state->transform, transform);
    }
    
    void GLContext::alpha(float alpha){
        _state->alpha = _state->alpha * alpha;
    }
    
    void GLContext::zIndex(){
        _state->zIndex += 1;
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
    
    GLfloat GLContext::global(GLfloat screen){
        return screen / _width;
    }
    
    GLfloat GLContext::screen(GLfloat global){
        return global * _width;
    }
    
    GLProgram * GLContext::program(const char * key){
        std::map<std::string,GLProgram *>::iterator i = _programs.find(key);
        return i != _programs.end() ? i->second : NULL;
    }
    
    void GLContext::setProgram(const char * key,GLProgram * program){
        
        program->retain();
        
        std::map<std::string,GLProgram *>::iterator i = _programs.find(key);
        
        if(i != _programs.end()){
            i->second->release();
            i->second = program;
        }
        else {
            _programs[key] = program;
        }
    }
    
    GLImage * GLContext::image(const char * key){
        std::map<std::string,GLImage *>::iterator i = _images.find(key);
        return i != _images.end() ? i->second : NULL;
    }
    
    void GLContext::setImage(const char * key, GLImage * image){
        
        image->retain();
        
        std::map<std::string,GLImage *>::iterator i = _images.find(key);
        
        if(i != _images.end()){
            i->second->release();
            i->second = image;
        }
        else {
            _images[key] = image;
        }
        
    }
    
    void GLContext::clearImages(){
        
        std::map<std::string,GLImage *>::iterator i = _images.begin();
        
        while (i != _images.end()) {
            
            i->second->release();
            
            i ++;
        }
        
        _images.clear();
        
    }
    
    GLLoader * GLContext::loader(){
        return _loader;
    }
}
