//
//  GLLayerElement.cpp
//  glelement
//
//  Created by zhang hailong on 14-6-19.
//  Copyright (c) 2014年 hailong.org. All rights reserved.
//

#include "GLLayerElement.h"

namespace cc {
    
    
    IMP_CLASS(GLLayerElement,GLElement)
    
    
    GLLayerElement::GLLayerElement(){
        
    }
    
    GLLayerElement::~GLLayerElement(){
        if(_backgroundImage){
            _backgroundImage->release();
        }
    }
    
    void GLLayerElement::draw(GLContext * context){
        GLCanvasElement::draw(context);
        
        
    }
    
    void GLLayerElement::begin(GLContext * context){
        
        float x = context->x(frame.origin.x);
        float y = context->y(frame.origin.y);
        float w = context->x(frame.size.width);
        float h = context->y(frame.size.height);
        
        position = GLVector3Make(x - w / 2.0f, y - h / 2.0f, context->state()->zIndex);
        
        GLCanvasElement::begin(context);
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
    
    
}