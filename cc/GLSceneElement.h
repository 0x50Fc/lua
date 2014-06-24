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
#include "GLMapElement.h"
#include "GLTask.h"

namespace cc {
    
    class GLSceneElement : public GLElement {
        
    public:
        
        GLSceneElement();
        
        virtual ~GLSceneElement();
        
        virtual GLMapElement * mapElement();
        
        virtual void addChild(Element * element);
        
        virtual void removeChild(Element * element);
        
        virtual void doAction(Action * action);
        
        DEC_CLASS
        
    private:
        GLMapElement * _mapElement;
    };
}

#endif /* defined(__glelement__GLSceneElement__) */

