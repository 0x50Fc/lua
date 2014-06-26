//
//  GLSpriteElement.cpp
//  glelement
//
//  Created by zhang hailong on 14-6-25.
//  Copyright (c) 2014年 hailong.org. All rights reserved.
//

#include "GLSpriteElement.h"

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
    uniform sampler2D image;\n\
    varying vec2 vTxtCoord;\n\
    void main(){\n\
    gl_FragColor = texture2D(image,vTxtCoord);\n\
    }\n";
    
    
    IMP_CLASS(GLSpriteElementProgram, GLProgram)
    
    GLSpriteElementProgram::GLSpriteElementProgram():GLProgram(vsh,fsh){
        position = getAttribLocation("position");
        txtCoord = getAttribLocation("txtCoord");
        transform = getUniformLocation("transform");
        projectTransform = getUniformLocation("projectTransform");
        image = getUniformLocation("image");
    }
    
    IMP_CLASS(GLSpriteElement,GLCanvasElement)
    
    
    GLSpriteElement::GLSpriteElement()
        : _image(NULL),size({0.0,0.0}),rect({0.0,0.0,1.0,1.0})
        , anchor({0.5,0.5}), _program(NULL), position({0.0,0.0,0.0}){
        
    }
    
    GLSpriteElement::~GLSpriteElement(){
        
        if(_image){
            _image->release();
        }
        
        if(_program){
            _program->release();
        }
    }

    void GLSpriteElement::begin(GLContext * context){
        GLCanvasElement::begin(context);
        
        context->translation(
                             context->global(position.x)
                             , context->global(position.y)
                             , position.z);
    }
    
    void GLSpriteElement::draw(GLContext * context){
        GLCanvasElement::draw(context);
        
        if(_image == NULL && _uri.size() > 0){
            _image = context->loader()->getImageForURI(_uri.c_str());
            if(_image){
                _image->retain();
            }
        }
        
        if(_image != NULL){
            
            if(_program == NULL){
                _program = (GLSpriteElementProgram *) context->program(clazz.name);
                if(_program){
                    _program->retain();
                }
            }
            
            if(_program == NULL){
                _program = new GLSpriteElementProgram();
                context->setProgram(clazz.name, _program);
            }
            
            GLfloat width = size.width;
            GLfloat height = size.height;
            
            if(width == 0 && height == 0){
                width = _image->width();
                height = _image->height();
            }
            else if(width == 0){
                width = height * _image->width() / _image->height();
            }
            else if(height == 0){
                height = width * _image->height() / _image->width();
            }
            
            width = context->global(width);
            height = context->global(height);
            
            GLfloat left = (anchor.x - 1.0) * width;
            GLfloat right = anchor.x * width;
            GLfloat top =  (anchor.y - 1.0) * height;
            GLfloat bottom = anchor.y * height;
            
            GLVector3 position[6] = {
                {left,top,0},{right,top,0},{left,bottom,0},
                {left,bottom,0},{right,top,0},{right,bottom,0}
            };
            
            GLVector2 txtCoord[6] = {
                {rect.origin.x,rect.origin.y},
                {rect.origin.x + rect.size.width,rect.origin.y},
                {rect.origin.x,rect.origin.y + rect.size.height},
                {rect.origin.x,rect.origin.y + rect.size.height},
                {rect.origin.x + rect.size.width,rect.origin.y},
                {rect.origin.x + rect.size.width,rect.origin.y + rect.size.height},
            };
            
            _program->use();
            
            _program->setVertexAttribPointer(_program->position, 3, position, sizeof(GLVector3));
            _program->setVertexAttribPointer(_program->txtCoord, 2, txtCoord, sizeof(GLVector2));
            
            _image->active(0);
            _program->setUniform1i(_program->image, 0);
            
            _program->setUniform4m(_program->projectTransform, context->project());
            _program->setUniform4m(_program->transform, context->state()->transform);

            glDrawArrays(GL_TRIANGLES, 0, 6);

        }
    }
    
    Value GLSpriteElement::value(const char * key){
        
        if(strcmp(key,"uri") == 0){
            return Value(_uri.c_str());
        }
        else if(strcmp(key,"width") == 0){
            return Value(size.width);
        }
        else if(strcmp(key,"height") == 0){
            return Value(size.height);
        }
        else if(strcmp(key,"x") == 0){
            return Value(position.x);
        }
        else if(strcmp(key,"y") == 0){
            return Value(position.y);
        }
        else if(strcmp(key,"z") == 0){
            return Value(position.z);
        }
        else {
            return GLCanvasElement::value(key);
        }
    }
    
    void GLSpriteElement::setValue(const char * key,Value value){
        
        if(strcmp(key,"uri") == 0){
            setUri( ValueToString(value,""));
        }
        else if(strcmp(key,"width") == 0){
            size.width = ValueToDouble(value,0);
        }
        else if(strcmp(key,"height") == 0){
            size.height = ValueToDouble(value,0);
        }
        else if(strcmp(key,"x") == 0){
            position.x = ValueToDouble(value,0);
        }
        else if(strcmp(key,"y") == 0){
            position.y = ValueToDouble(value,0);
        }
        else if(strcmp(key,"z") == 0){
            position.z = ValueToDouble(value,0);
        }
        else {
            GLCanvasElement::setValue(key,value);
        }
    }
    
    Value GLSpriteElement::invoke(const char * key,InvokeArgs * args){
        if(strcmp(key, "setRect") == 0){
            rect.origin.x = ValueToDouble(InvokeArgsValue(args, 0), 0);
            rect.origin.y = ValueToDouble(InvokeArgsValue(args, 1), 0);
            rect.size.width = ValueToDouble(InvokeArgsValue(args, 2), 0);
            rect.size.height = ValueToDouble(InvokeArgsValue(args, 3), 0);
            return Value();
        }
        else if(strcmp(key, "setAnchor") == 0){
            anchor.x = ValueToDouble(InvokeArgsValue(args, 0), 0);
            anchor.y = ValueToDouble(InvokeArgsValue(args, 1), 0);
            return Value();
        }
        else if(strcmp(key, "setPosition") == 0){
            position.x = ValueToDouble(InvokeArgsValue(args, 0), 0);
            position.y = ValueToDouble(InvokeArgsValue(args, 1), 0);
            position.z = ValueToDouble(InvokeArgsValue(args, 2), 0);
            return Value();
        }
        else if(strcmp(key, "setSize") == 0){
            size.width = ValueToDouble(InvokeArgsValue(args, 0), 0);
            size.height = ValueToDouble(InvokeArgsValue(args, 1), 0);
            return Value();
        }
        else {
            return GLCanvasElement::invoke(key, args);
        }
    }
    
    GLImage * GLSpriteElement::image(){
        return _image;
    }
    
    void GLSpriteElement::setImage(GLImage * image){
        if(_image != image){
            if(image){
                image->retain();
            }
            if(_image){
                _image->release();
            }
            _image = image;
        }
    }
    
    const char * GLSpriteElement::uri(){
        return _uri.c_str();
    }
    
    void GLSpriteElement::setUri(const char * value){
        _uri = value;
        if(_image){
            _image->release();
        }
        _image = NULL;
    }
    
    
}