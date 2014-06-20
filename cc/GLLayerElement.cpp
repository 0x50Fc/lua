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
    varying vec2 vTxtCoord; \n\
    void main() { \n\
        vTxtCoord = txtCoord; \n\
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
    uniform float alpha;\n\
    varying vec2 vTxtCoord;\n\
    void main(){\n\
        vec4 c ;\n\
        if(hasBackgroundImage ==1){\n\
            c = texture2D(backgroundImage,vTxtCoord) * alpha;\n\
        }\n\
        else{\n\
            c = backgroundColor * alpha;\n\
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
    ,size({0.0,0.0})
    ,center({0.0,0.0}){

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
        
        GLLayerElementProgram * p = program(context);
        
        float screenWidth = context->width();
        float screenHeight = context->height();
        
        if(p && screenWidth >0 && screenHeight >0 && size.width >0 && size.height > 0){
            
            float w = context->global(size.width);
            float h = context->global(size.height);
            float left = - w / 2.0f;
            float right = w / 2.0f;
            float top = - h / 2.0f;
            float bottom = h / 2.0f;
            
            GLVector3 position[6] = {
                {left,top,0},{right,top,0},{left,bottom,0},
                {left,bottom,0},{right,top,0},{right,bottom,0}
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
        
            p->setUniform4m(p->projectTransform, context->projectTransform);
            p->setUniform4m(p->transform, context->state()->transform);
            p->setUniform1f(p->alpha, context->state()->alpha);
            
            glDrawArrays(GL_TRIANGLES, 0, 6);
            
        }
        
    }
      
    void GLLayerElement::begin(GLContext * context){
        
        GLfloat x = context->global(center.x);
        GLfloat y = context->global(center.y);
        
        position = GLVector3Make(x, y , context->state()->zIndex);
        
        GLCanvasElement::begin(context);
    }
    
    GLVector4 GLLayerElement::frame(){
        GLVector4 v4 = {center.x - size.width / 2.0f,center.y - size.height / 2.0f,size.width,size.height};
        return v4;
    }
    
    void GLLayerElement::setFrame(GLVector4 frame){
        size.width = frame.size.width;
        size.height = frame.size.height;
        center.x = frame.origin.x + size.width / 2.0f;
        center.y = frame.origin.y + size.height / 2.0f;
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
        
        if(strcmp(key, "size.width") == 0){
            return Value((double) size.width);
        }
        else if(strcmp(key, "size.height") == 0){
            return Value((double) size.height);
        }
        else if(strcmp(key, "center.x") == 0){
            return Value((double) center.x);
        }
        else if(strcmp(key, "center.y") == 0){
            return Value((double) center.y);
        }
        else if(strcmp(key, "background-color") == 0){
            return Value((long long) GLColor3dToIntValue(_backgroundColor));
        }
        else {
            return GLCanvasElement::value(key);
        }
    }
    
    void GLLayerElement::setValue(const char * key,Value value){
        
        if(strcmp(key, "size.width") == 0){
            size.width = ValueToDouble(value, 0.0);
        }
        else if(strcmp(key, "size.height") == 0){
            size.height = ValueToDouble(value, 0.0);
        }
        else if(strcmp(key, "center.x") == 0){
            center.x = ValueToDouble(value, 0.0);
        }
        else if(strcmp(key, "center.y") == 0){
            center.y = ValueToDouble(value, 0.0);
        }
        else if(strcmp(key, "background-color") == 0){
            if(value.type == ValueTypeString){
                _backgroundColor = GLColor3dFromString(value.stringValue);
            }
            else {
                _backgroundColor = GLColor3dFromIntValue(ValueToInt(value, 0));
            }
        }
        else {
            GLCanvasElement::setValue(key,value);
        }
        
    }
    
    void GLLayerElement::invoke(const char * key,InvokeArgs * args){
        
        if(strcmp(key, "setFrame") == 0){
            GLVector4 v4 ;
            v4.origin.x = ValueToDouble(InvokeArgsValue(args, 0),0.0);
            v4.origin.y = ValueToDouble(InvokeArgsValue(args, 1),0.0);
            v4.size.width = ValueToDouble(InvokeArgsValue(args, 2),0.0);
            v4.size.height = ValueToDouble(InvokeArgsValue(args, 3),0.0);
            setFrame(v4);
        }
        else{
            GLCanvasElement::invoke(key, args);
        }
        
    }
    
}