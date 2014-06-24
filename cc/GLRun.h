//
//  GLRun.h
//  glelement
//
//  Created by zhang hailong on 14-6-19.
//  Copyright (c) 2014年 hailong.org. All rights reserved.
//

#ifndef __glelement__GLRun__
#define __glelement__GLRun__

#include <iostream>

#include "GLSchedule.h"
#include "Element.h"
#include "GLContext.h"
#include "GLTouch.h"

namespace cc {
    
    void GLRunSchedule(GLSchedule * schedule,Element * element);
    
    void GLRunContext(GLContext * context,Element * element);
    
    bool GLRunTouch(GLTouch * touch,GLTouchState touchState, Element * element);
    
}

#endif /* defined(__glelement__GLRun__) */
