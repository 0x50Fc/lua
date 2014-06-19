//
//  GLElement.h
//  glelement
//
//  Created by zhang hailong on 14-6-19.
//  Copyright (c) 2014年 hailong.org. All rights reserved.
//

#ifndef __glelement__GLElement__
#define __glelement__GLElement__

#include <iostream>

#include "Element.h"
#include "GL.h"
#include "GLContext.h"

namespace cc {
    
    
    class GLElement : public Element {
    
    public:
        
        GLElement();
        
        virtual ~GLElement();
        
        virtual void tick();
        
        DEC_CLASS
    };
    
}

#endif /* defined(__glelement__GLElement__) */
