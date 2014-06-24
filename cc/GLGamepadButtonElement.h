//
//  GLGamepadButtonElement.h
//  glelement
//
//  Created by zhang hailong on 14-6-24.
//  Copyright (c) 2014年 hailong.org. All rights reserved.
//

#ifndef __glelement__GLGamepadButtonElement__
#define __glelement__GLGamepadButtonElement__

#include <iostream>

#include "GLControlElement.h"

namespace cc {
    
    class GLGamepadButtonElement : public GLControlElement {
    
    public:
        
        GLGamepadButtonElement();
        
        virtual ~GLGamepadButtonElement();
        
        virtual bool touch(GLTouch * touch,GLTouchState touchState, GLVector2 location);
        
        DEC_CLASS
        
    private:
        
        GLTouch * _touch;
        bool _insetTouch;
        
    };
}

#endif /* defined(__glelement__GLGamepadButtonElement__) */
