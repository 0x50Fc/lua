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

#include "GLElement.h"

namespace cc {
    
    
    class GLLayerElement : public GLElement {
      
    public:
        
        GLLayerElement();
        
        virtual ~GLLayerElement();
        
        DEC_CLASS
        
        virtual void begin(GLContext * context);
        
        virtual void draw(GLContext * context);
        
        GLVector4 frame;
        
    };
    
}

#endif /* defined(__glelement__GLLayerElement__) */
