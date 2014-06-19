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

namespace cc {
    
    class GLTask;
    
    class GLSchedule : public Object {
    
    public:
        
        GLSchedule();
        
        virtual ~GLSchedule();
    
        virtual void tick();
        
        virtual void schedule(GLTask * task);
        
        virtual void unschedule(GLTask * task);
       
        double timestamp;
        
        DEC_CLASS
        
    private:
        std::vector<GLTask *> _tasks;
    };
}

#endif /* defined(__glelement__GLSchedule__) */
