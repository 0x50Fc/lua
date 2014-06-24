//
//  GLSchedule.h
//  glelement
//
//  Created by zhang hailong on 14-6-19.
//  Copyright (c) 2014年 hailong.org. All rights reserved.
//

#ifndef __glelement__GLSchedule__
#define __glelement__GLSchedule__

#include <iostream>
#include <vector>

#include "Object.h"
#include "GLLoader.h"

namespace cc {
    
    class GLTask;
    
    class GLSchedule : public Object {
    
    public:
        
        GLSchedule();
        
        GLSchedule(GLLoader * loader);
        
        virtual ~GLSchedule();
    
        virtual void tick(double tickTimestamp);
        
        virtual void schedule(GLTask * task);
        
        virtual void unschedule(GLTask * task);
       
        virtual double timestamp();
        
        virtual bool isEnabled();
        
        virtual void setEnabled(bool value);
        
        virtual GLLoader * loader();
        
        DEC_CLASS
        
    private:
        GLLoader * _loader;
        std::vector<GLTask *> _tasks;
        double _timestamp;
        double _tickTimestamp;
        bool _enabled;
    };
}

#endif /* defined(__glelement__GLSchedule__) */
