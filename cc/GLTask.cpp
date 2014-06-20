//
//  GLTask.cpp
//  glelement
//
//  Created by zhang hailong on 14-6-19.
//  Copyright (c) 2014年 hailong.org. All rights reserved.
//

#include "GLTask.h"

namespace cc {
    
    IMP_CLASS(GLTask, Object)
    
    GLTask::GLTask():afterDelay(0),start(0),callback(NULL){
        
    }
    
    GLTask::~GLTask(){
        
    }
    
}
