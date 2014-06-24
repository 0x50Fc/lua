//
//  GLControlElement.h
//  glelement
//
//  Created by zhang hailong on 14-6-24.
//  Copyright (c) 2014年 hailong.org. All rights reserved.
//

#ifndef __glelement__GLControlElement__
#define __glelement__GLControlElement__

#include <iostream>
#include <set>

#include "GLLayerElement.h"
#include "GLTouch.h"

namespace cc {
    
    
    class GLControlElement : public GLLayerElement {
    
    public:
        
        GLControlElement();
        
        virtual ~GLControlElement();
        
        virtual bool touch(GLTouch * touch,GLTouchState touchState, GLVector2 location);
        
        virtual Value value(const char * key);
        
        virtual void setValue(const char * key,Value value);
        
        DEC_CLASS
        
        bool touchEnabled;
        
    };
    
}

#endif /* defined(__glelement__GLControlElement__) */
