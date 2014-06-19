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

namespace cc {
    
    
    class GLLayerElement : public GLCanvasElement {
      
    public:
        
        GLLayerElement();
        
        virtual ~GLLayerElement();
        
        DEC_CLASS
        
        virtual void begin(GLContext * context);
        
        virtual void draw(GLContext * context);
        
        GLVector4 frame;
        
        virtual GLImage * backgroundImage();
        
        virtual void setBackgroundImage(GLImage * image);
        
        virtual GLColor3d backgroundColor();
        
        virtual void setBackgroundColor(GLColor3d color);
        
        virtual float borderWidth();
        
        virtual void setBorderWidth(float width);
        
        virtual GLColor3d borderColor();
        
        virtual void setBorderColor(GLColor3d color);
        
        
    private:
        
        GLImage * _backgroundImage;
        GLColor3d _backgroundColor;
        float _borderWidth;
        GLColor3d _borderColor;
        
    };
    
}

#endif /* defined(__glelement__GLLayerElement__) */
