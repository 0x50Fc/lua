//
//  GLAnimationElement.h
//  glelement
//
//  Created by zhang hailong on 14-6-23.
//  Copyright (c) 2014年 hailong.org. All rights reserved.
//

#ifndef __glelement__GLAnimationElement__
#define __glelement__GLAnimationElement__

#include <iostream>

#include "GLElement.h"

namespace cc {
    
    class GLAnimationElement : public GLElement {
        
    public:
        
        GLAnimationElement();
        
        virtual ~GLAnimationElement();
        
        virtual void tick(GLSchedule * schedule);
        
        virtual double timestamp();
        
        virtual GLScheduleStatus status();
        
        virtual void setStatus(GLScheduleStatus value);
        
        virtual double duration();
        
        virtual void setDuration(double duration);
        
        virtual Value value(const char * key);
        
        virtual void setValue(const char * key,Value value);
        
        virtual double value();
        
        DEC_CLASS
        
    private:
        
        double _duration;
        double _timestamp;
        double _tickTimestamp;
        GLScheduleStatus _status;
        
    };
    
}

#endif /* defined(__glelement__GLAnimationElement__) */
