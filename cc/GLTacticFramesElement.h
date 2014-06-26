//
//  GLTacticFramesElement.h
//  glelement
//
//  Created by zhang hailong on 14-6-25.
//  Copyright (c) 2014年 hailong.org. All rights reserved.
//

#ifndef __glelement__GLTacticFramesElement__
#define __glelement__GLTacticFramesElement__

#include <iostream>

#include "GLTacticElement.h"

namespace cc {
    

    class GLTacticFramesElement : public GLTacticElement {
    
    public:
        
        GLTacticFramesElement();
        
        virtual ~GLTacticFramesElement();
        
        virtual void tick(GLSchedule * schedule);
        
        virtual Value value(const char * key);
        
        virtual void setValue(const char * key,Value value);
        
        virtual void onElementChanged(Element * element);
        
        DEC_CLASS
        
        double duration;
    
        double afterDelay;
        
        int visableStatus;
        
        int enabledStatus;
        
        int defaultIndex;
        
        bool visable;
    };
    
    
}

#endif /* defined(__glelement__GLTacticFramesElement__) */
