//
//  GLGamepadElement.h
//  glelement
//
//  Created by zhang hailong on 14-6-24.
//  Copyright (c) 2014年 hailong.org. All rights reserved.
//

#ifndef __glelement__GLGamepadElement__
#define __glelement__GLGamepadElement__

#include <iostream>

#include "GLControlElement.h"

namespace cc {
    
    class GLGamepadElement : public GLControlElement {
    
    public:
        
        GLGamepadElement();
        
        virtual ~GLGamepadElement();
        
        virtual void begin(GLContext * context);
        
        virtual bool touch(GLTouch * touch,GLTouchState touchState, GLVector2 location);
        
        virtual void addChild(Element * element);
        
        virtual void removeChild(Element * element);
        
        DEC_CLASS
        
    private:
        
        GLLayerElement * _beginElement;
        
        GLLayerElement * _toElement;
        
        GLLayerElement * _buttonsElement;
        
        GLVector2 _beginLocation;
        
        GLVector2 _toLocation;
        
        GLTouch * _touch;
        
    };
}

#endif /* defined(__glelement__GLGamepadElement__) */
