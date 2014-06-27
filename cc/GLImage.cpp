//
//  GLImage.cpp
//  glelement
//
//  Created by zhang hailong on 14-6-19.
//  Copyright (c) 2014年 hailong.org. All rights reserved.
//

#include "GLImage.h"

namespace cc {
    
    IMP_CLASS(GLImage, Object)

    GLImage::GLImage()
        :_texture(0),_width(0),_height(0){
            
    }
    
    GLImage::GLImage(int width,int height,unsigned int texture)
        :_texture(texture),_width(width),_height(height){
        
    }
    
    GLImage::GLImage(int width,int height,void * pixels,GLImagePixelFormat format){
        
        _width = width;
        _height = height;
        
        glGenTextures(1, & _texture);
        glBindTexture(GL_TEXTURE_2D, _texture);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
        
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, format == GLImagePixelFormatRGBA ? GL_RGBA : GL_BGRA, GL_UNSIGNED_BYTE, pixels);
        
    }
    
    GLImage::~GLImage(){
        
        if(_texture){
            glDeleteTextures(1, &_texture);
            glFinish();
        }
    }
    
    int GLImage::width(){
        return _width;
    }
    
    int GLImage::height(){
        return _height;
    }
    
    void GLImage::active(unsigned int textureId){
        glActiveTexture(GL_TEXTURE0 + textureId);
        glBindTexture(GL_TEXTURE_2D, _texture);
    }
    
}
