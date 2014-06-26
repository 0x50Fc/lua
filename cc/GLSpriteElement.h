//
//  GLSpriteElement.h
//  glelement
//
//  Created by zhang hailong on 14-6-25.
//  Copyright (c) 2014年 hailong.org. All rights reserved.
//

#ifndef __glelement__GLSpriteElement__
#define __glelement__GLSpriteElement__

#include <iostream>

#include "GLCanvasElement.h"
#include "GLImage.h"

namespace cc {
    
    class GLSpriteElementProgram : public GLProgram {
        
    public:
        
        GLSpriteElementProgram();
        
        GLint position;
        GLint txtCoord;
        GLint transform;
        GLint projectTransform;
        GLint image;
        
        DEC_CLASS
    };

    
    class GLSpriteElement : public GLCanvasElement {
    
    public:
        
        GLSpriteElement();
        
        virtual ~GLSpriteElement();
        
        virtual void begin(GLContext * context);
        
        virtual void draw(GLContext * context);
        
        virtual Value value(const char * key);
        
        virtual void setValue(const char * key,Value value);

        virtual Value invoke(const char * key,InvokeArgs * args);

        virtual GLImage * image();
        
        virtual void setImage(GLImage * image);
        
        virtual const char * uri();
        
        virtual void setUri(const char * value);
        
        DEC_CLASS

        GLVector3 position;
        GLVector2 size;
        GLVector4 rect;
        GLVector2 anchor;
        
    private:
        std::string _uri;
        GLImage * _image;
        GLSpriteElementProgram * _program;
    };
}

#endif /* defined(__glelement__GLSpriteElement__) */
