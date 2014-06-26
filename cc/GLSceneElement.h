//
//  GLSceneElement.h
//  glelement
//
//  Created by zhang hailong on 14-6-24.
//  Copyright (c) 2014年 hailong.org. All rights reserved.
//

#ifndef __glelement__GLSceneElement__
#define __glelement__GLSceneElement__

#include <iostream>

#include "GLElement.h"
#include "GLTask.h"

namespace cc {
    
    class GLSceneElement : public GLElement {
        
    public:
        
        GLSceneElement();
        
        virtual ~GLSceneElement();
        
        virtual void doAction(Action * action);
        
        DEC_CLASS
        
    };
}

#endif /* defined(__glelement__GLSceneElement__) */

