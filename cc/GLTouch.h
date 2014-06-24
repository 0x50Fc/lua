//
//  GLTouch.h
//  glelement
//
//  Created by zhang hailong on 14-6-24.
//  Copyright (c) 2014年 hailong.org. All rights reserved.
//

#ifndef __glelement__GLTouch__
#define __glelement__GLTouch__

#include <iostream>

#include "Element.h"
#include "GL.h"

namespace cc {
    
    enum GLTouchState {
        GLTouchStateBegin,GLTouchStateMoved,GLTouchStateEnded,GLTouchStateCanceled
    };
    
    class GLTouch : public Object {
        
    public:
        
        GLTouch();
        
        GLTouch(GLfloat screenX,GLfloat screenY,GLfloat screenWidth,GLfloat screenHeight);
        
        virtual ~GLTouch();
        
        virtual GLVector2 locationInElement(Element * element);
        
        DEC_CLASS;
        
        GLfloat screenX;
        
        GLfloat screenY;
        
        GLfloat screenWidth;
        
        GLfloat screenHeight;
        
        bool cancled;
    };

}
#endif /* defined(__glelement__GLTouch__) */
