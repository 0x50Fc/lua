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
        
        virtual void begin(GLContext * context);
        
        virtual void end(GLContext * context);
        
        virtual void draw(GLContext * context);
        
        DEC_CLASS
        
        float alpha;
        GLVector3 position;
        GLVector3 scale;
        GLMatrix4 transform;
    };
    
}

#endif /* defined(__glelement__GLElement__) */
