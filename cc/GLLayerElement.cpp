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
        
        drawBackground(context);
        
        onDraw(context);
        
        drawBorder(context);
        
    }
    
    void GLLayerElement::drawBackground(GLContext * context){
        
        if(_backgroundColor.a != 0.0){
            
        }
        
    }
    
    void GLLayerElement::drawBorder(GLContext * context){
        
    }
    
    void GLLayerElement::onDraw(GLContext * context){
        
    }
    
    void GLLayerElement::begin(GLContext * context){
        
        float x = context->x(center.x);
        float y = context->y(center.y);
        
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
    
    
}