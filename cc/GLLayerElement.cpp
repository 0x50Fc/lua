//
//  GLLayerElement.cpp
//  glelement
//
//  Created by zhang hailong on 14-6-19.
//  Copyright (c) 2014年 hailong.org. All rights reserved.
//

#include "GLLayerElement.h"

namespace cc {
    
    
    static const char * vsh = "\
    attribute vec4 position; \n\
    attribute vec2 txtCoord; \n\
    uniform	mat4 transform; \n\
    uniform mat4 projectTransform; \n\
    uniform float alpha;\n\
    varying vec2 vTxtCoord; \n\
    varying float vAlpha; \n\
    void main() { \n\
        vTxtCoord = txtCoord; \n\
        vAlpha = alpha; \n\
        gl_Position = projectTransform * transform * position; \n\
    } \n\
    ";
    
    static const char * fsh = "\
    #ifdef GL_ES\n\
    precision lowp float; \n\
    #endif \n\
    uniform vec4 backgroundColor;\n\
    uniform sampler2D backgroundImage;\n\
    uniform int hasBackgroundImage;\n\
    varying vec2 vTxtCoord;\n\
    varying float vAlpha; \n\
    void main(){\n\
        vec4 c ;\n\
        if(hasBackgroundImage ==1){\n\
            c = texture2D(backgroundImage,vTxtCoord) * vAlpha;\n\
        }\n\
        else{\n\
            c = backgroundColor * vAlpha;\n\
        }\n\
        gl_FragColor = c;\n\
    }\n";
    
    
    IMP_CLASS(GLLayerElementProgram, GLProgram)
    
    GLLayerElementProgram::GLLayerElementProgram():GLProgram(vsh,fsh){
        position = getAttribLocation("position");
        txtCoord = getAttribLocation("txtCoord");
        transform = getUniformLocation("transform");
        projectTransform = getUniformLocation("projectTransform");
        backgroundColor = getUniformLocation("backgroundColor");
        backgroundImage = getUniformLocation("backgroundImage");
        hasBackgroundImage = getUniformLocation("hasBackgroundImage");
        alpha = getUniformLocation("alpha");
    }
    
    IMP_CLASS(GLLayerElement,GLCanvasElement)
    
    
    GLLayerElement::GLLayerElement()
    :_backgroundColor({0.0,0.0,0.0,0.0})
    ,_backgroundImage(NULL)
    ,_backgroundRect({0.0,0.0,1.0f,1.0})
    ,_borderWidth(0)
    ,_borderColor({0.0,0.0,0.0,0.0})
    ,_program(NULL)
    ,frame({0.0,0.0,0.0,0.0}){

    }
    
    GLLayerElement::~GLLayerElement(){
        if(_backgroundImage){
            _backgroundImage->release();
        }
        if(_program){
            _program->release();
        }
    }
    
    GLLayerElementProgram * GLLayerElement::program(GLContext * context){
        
        if(_program == NULL){
            _program = (GLLayerElementProgram *) context->program(clazz.name);
            if(_program){
                _program->retain();
            }
        }
        
        if(_program == NULL){
            _program = new GLLayerElementProgram();
            context->setProgram(clazz.name, _program);
        }
        
        return _program;
    }
    
    void GLLayerElement::draw(GLContext * context){
        GLCanvasElement::draw(context);
        
        
        if(_backgroundImage == NULL && _backgroundUri.size() > 0){
            _backgroundImage = context->loader()->getImageForURI(_backgroundUri.c_str());
            if(_backgroundImage){
                _backgroundImage->retain();
            }
        }
        
        GLLayerElementProgram * p = program(context);
        
        float screenWidth = context->width();
        float screenHeight = context->height();
        
        if(p && screenWidth >0 && screenHeight >0 && frame.size.width >0 && frame.size.height > 0){
            
            float w = context->global(frame.size.width);
            float h = context->global(frame.size.height);
            
            GLVector3 position[6] = {
                {0,0,0},{w,0,0},{0,h,0},
                {0,h,0},{w,0,0},{w,h,0}
            };
            
            GLVector2 txtCoord[6] = {
                {_backgroundRect.origin.x,_backgroundRect.origin.y},
                {_backgroundRect.origin.x + _backgroundRect.size.width,_backgroundRect.origin.y},
                {_backgroundRect.origin.x,_backgroundRect.origin.y + _backgroundRect.size.height},
                {_backgroundRect.origin.x,_backgroundRect.origin.y + _backgroundRect.size.height},
                {_backgroundRect.origin.x + _backgroundRect.size.width,_backgroundRect.origin.y},
                {_backgroundRect.origin.x + _backgroundRect.size.width,_backgroundRect.origin.y + _backgroundRect.size.height},
            };
            
            p->use();
            
            p->setVertexAttribPointer(p->position, 3, position, sizeof(GLVector3));
            p->setVertexAttribPointer(p->txtCoord, 2, txtCoord, sizeof(GLVector2));
            
            if(_backgroundImage){
                _backgroundImage->active(0);
                p->setUniform1i(p->backgroundImage, 0);
                p->setUniform1i(p->hasBackgroundImage, 1);
            }
            else{
                p->setUniform1i(p->hasBackgroundImage, 0);
            }
            
            p->setUniform4f(p->backgroundColor,_backgroundColor);
        
            p->setUniform4m(p->projectTransform, context->project());
            p->setUniform4m(p->transform, context->state()->transform);
            p->setUniform1f(p->alpha, context->state()->alpha);
            
            glDrawArrays(GL_TRIANGLES, 0, 6);
            
        }
        
    }
      
    void GLLayerElement::begin(GLContext * context){
        
        context->saveState();
        
        GLfloat x = context->global(frame.origin.x);
        GLfloat y = context->global(frame.origin.y);
        
        context->translation(x, y, context->zIndex);
        context->scale(scale, scale, scale);
        context->alpha(alpha);
        context->transform(transform);
        
    }
    
    GLImage * GLLayerElement::backgroundImage(){
        return _backgroundImage;
    }
    
    void GLLayerElement::setBackgroundImage(GLImage * image){
        if(_backgroundImage != image){
            if(image){
                image->retain();
            }
            if(_backgroundImage){
                _backgroundImage->release();
            }
            _backgroundImage = image;
        }
    }
    
    GLColor3d GLLayerElement::backgroundColor(){
        return _backgroundColor;
    }
    
    void GLLayerElement::setBackgroundColor(GLColor3d color){
        _backgroundColor = color;
    }
    
    float GLLayerElement::borderWidth(){
        return _borderWidth;
    }
    
    void GLLayerElement::setBorderWidth(float width){
        _borderWidth = width;
    }
    
    GLColor3d GLLayerElement::borderColor(){
        return _borderColor;
    }
    
    void GLLayerElement::setBorderColor(GLColor3d color){
        _borderColor = color;
    }
    
    GLVector4 GLLayerElement::backgroundRect(){
        return _backgroundRect;
    }
    
    void GLLayerElement::setBackgroundRect(GLVector4 rect){
        _backgroundRect = rect;
    }
    
    Value GLLayerElement::value(const char * key){
        
        if(strcmp(key, "width") == 0){
            return Value((double) frame.size.width);
        }
        else if(strcmp(key, "height") == 0){
            return Value((double) frame.size.height);
        }
        else if(strcmp(key, "x") == 0){
            return Value((double) frame.origin.x);
        }
        else if(strcmp(key, "y") == 0){
            return Value((double) frame.origin.y);
        }
        else if(strcmp(key, "background-color") == 0){
            return Value((long long) GLColor3dToIntValue(_backgroundColor));
        }
        else if(strcmp(key, "background-uri") == 0){
            return Value(_backgroundUri.c_str());
        }
        else {
            return GLCanvasElement::value(key);
        }
    }
    
    void GLLayerElement::setValue(const char * key,Value value){
        
        if(strcmp(key, "width") == 0){
            frame.size.width = ValueToDouble(value, 0.0);
        }
        else if(strcmp(key, "height") == 0){
            frame.size.height = ValueToDouble(value, 0.0);
        }
        else if(strcmp(key, "x") == 0){
            frame.origin.x = ValueToDouble(value, 0.0);
        }
        else if(strcmp(key, "y") == 0){
            frame.origin.y = ValueToDouble(value, 0.0);
        }
        else if(strcmp(key, "background-color") == 0){
            if(value.type == ValueTypeString){
                _backgroundColor = GLColor3dFromString(value.stringValue);
            }
            else {
                _backgroundColor = GLColor3dFromIntValue(ValueToInt(value, 0));
            }
        }
        else if(strcmp(key, "background-uri") == 0){
            _backgroundUri = ValueToString(value, "");
        }
        else {
            GLCanvasElement::setValue(key,value);
        }
        
    }
    
    Value GLLayerElement::invoke(const char * key,InvokeArgs * args){
        
        if(strcmp(key, "setFrame") == 0){
            frame.origin.x = ValueToDouble(InvokeArgsValue(args, 0),0.0);
            frame.origin.y = ValueToDouble(InvokeArgsValue(args, 1),0.0);
            frame.size.width = ValueToDouble(InvokeArgsValue(args, 2),0.0);
            frame.size.height = ValueToDouble(InvokeArgsValue(args, 3),0.0);
            return Value();
        }
        else if(strcmp(key, "setSize") == 0){
            frame.size.width = ValueToDouble(InvokeArgsValue(args, 0),0.0);
            frame.size.height = ValueToDouble(InvokeArgsValue(args, 1),0.0);
            return Value();
        }
        else{
            return GLCanvasElement::invoke(key, args);
        }
        
    }
    
    const char * GLLayerElement::backgroundUri(){
        return _backgroundUri.c_str();
    }
    
    void GLLayerElement::setBackgroundUri(const char * uri){
        _backgroundUri = uri;
    }
    
}