//
//  GLImage.h
//  glelement
//
//  Created by zhang hailong on 14-6-19.
//  Copyright (c) 2014年 hailong.org. All rights reserved.
//

#ifndef __glelement__GLImage__
#define __glelement__GLImage__

#include <iostream>

#include "Object.h"
#include "GL.h"

namespace cc {
    
    enum GLImagePixelFormat {
        GLImagePixelFormatRGBA
        ,GLImagePixelFormatBGRA
    };
    
    class GLImage : public Object {
    
    public:
        
        GLImage();
        
        GLImage(int width,int height,unsigned int texture);
        
        GLImage(int width,int height,void * pixels,GLImagePixelFormat format);
        
        virtual ~GLImage();
        
        virtual int width();
        
        virtual int height();
        
        virtual void active(unsigned int textureId);
        
        DEC_CLASS
        
    private:
        
        int _width;
        int _height;
        unsigned int _texture;
        
    };
    
}

#endif /* defined(__glelement__GLImage__) */
