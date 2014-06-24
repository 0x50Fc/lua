//
//  GLScreenElement.h
//  glelement
//
//  Created by zhang hailong on 14-6-24.
//  Copyright (c) 2014年 hailong.org. All rights reserved.
//

#ifndef __glelement__GLScreenElement__
#define __glelement__GLScreenElement__

#include <iostream>

#include "GLCanvasElement.h"

namespace cc {
    
    
    class GLScreenElement : public GLCanvasElement {
    
    public:
        
        GLScreenElement();
        
        virtual ~GLScreenElement();
        
        virtual void begin(GLContext * context);
        
        virtual GLfloat zPosition();
        
        virtual void setZPosition(GLfloat value);
        
        DEC_CLASS
        
    private:
        
        GLfloat _zPosition;
        
    };
    
    
}

#endif /* defined(__glelement__GLScreenElement__) */
