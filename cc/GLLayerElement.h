//
//  GLLayerElement.h
//  glelement
//
//  Created by zhang hailong on 14-6-19.
//  Copyright (c) 2014年 hailong.org. All rights reserved.
//

#ifndef __glelement__GLLayerElement__
#define __glelement__GLLayerElement__

#include <iostream>

#include "GLCanvasElement.h"
#include "GLImage.h"
#include "GLProgram.h"

namespace cc {
    
    
    class GLLayerElementProgram : public GLProgram {
        
    public:
        
        GLLayerElementProgram();
        
        GLint position;
        GLint txtCoord;
        GLint transform;
        GLint projectTransform;
        GLint backgroundColor;
        GLint backgroundImage;
        GLint hasBackgroundImage;
        GLint alpha;
        
        DEC_CLASS
    };
    
    class GLLayerElement : public GLCanvasElement {
      
    public:
        
        GLLayerElement();
        
        virtual ~GLLayerElement();

        virtual void begin(GLContext * context);

        virtual void draw(GLContext * context);
        
        GLVector2 center;
        GLVector2 size;
        
        virtual GLVector4 frame();
        
        virtual void setFrame(GLVector4 frame);
        
        virtual GLImage * backgroundImage();
        
        virtual void setBackgroundImage(GLImage * image);
        
        virtual GLColor3d backgroundColor();
        
        virtual void setBackgroundColor(GLColor3d color);
        
        virtual float borderWidth();
        
        virtual void setBorderWidth(float width);
        
        virtual GLColor3d borderColor();
        
        virtual void setBorderColor(GLColor3d color);
        
        virtual GLVector4 backgroundRect();
        
        virtual void setBackgroundRect(GLVector4 rect);
        
        virtual Value value(const char * key);
        
        virtual void setValue(const char * key,Value value);
        
        virtual void invoke(const char * key,InvokeArgs * args);
        
        DEC_CLASS
        
    protected:
        
        virtual GLLayerElementProgram * program(GLContext * context);
        
    private:
        
        GLImage * _backgroundImage;
        GLColor3d _backgroundColor;
        GLVector4 _backgroundRect;
        float _borderWidth;
        GLColor3d _borderColor;
        GLLayerElementProgram * _program;
        
    };
    
}

#endif /* defined(__glelement__GLLayerElement__) */
