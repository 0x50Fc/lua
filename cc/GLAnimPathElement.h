//
//  GLAnimPathElement.h
//  glelement
//
//  Created by zhang hailong on 14-6-23.
//  Copyright (c) 2014年 hailong.org. All rights reserved.
//

#ifndef __glelement__GLAnimPathElement__
#define __glelement__GLAnimPathElement__

#include <iostream>

#include "GLAnimationElement.h"

namespace cc {
    
    class GLAnimPathElement : public GLAnimationElement {
        
    public:
        
        GLAnimPathElement();
        
        virtual ~GLAnimPathElement();
        
        virtual void tick(GLSchedule * schedule);
       
        virtual void invoke(const char * key,InvokeArgs * args);

        virtual void setPositions(GLVector3 * positions,int length);
        
        virtual void clearPositions();
        
        virtual void addPosition(GLVector3 position);
        
        virtual GLVector3 position();
        
        DEC_CLASS
        
    private:
        
        std::vector<GLVector3> _positions;
        

    };
}

#endif /* defined(__glelement__GLAnimPathElement__) */
