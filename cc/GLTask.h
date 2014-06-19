//
//  GLTask.h
//  glelement
//
//  Created by zhang hailong on 14-6-19.
//  Copyright (c) 2014年 hailong.org. All rights reserved.
//

#ifndef __glelement__GLTask__
#define __glelement__GLTask__

#include <iostream>

#include "Object.h"

namespace cc {
    
    class GLTask;
    class GLSchedule;
    
    typedef void (* GLTaskCallback ) (GLSchedule * schedule, Object * object,GLTask * task);
    
    class GLTask : public Object {
    
    public:
        
        GLTask();
        
        virtual ~GLTask();
        
        GLTaskCallback callback;
        
        double afterDelay;
        
        double start;
        
        DEC_CLASS
    };
    
}

#endif /* defined(__glelement__GLTask__) */
