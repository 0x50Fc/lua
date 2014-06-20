//
//  GLSchedule.cpp
//  glelement
//
//  Created by zhang hailong on 14-6-19.
//  Copyright (c) 2014年 hailong.org. All rights reserved.
//

#include "GLSchedule.h"

#include "GLTask.h"

namespace cc {
    
    IMP_CLASS(GLSchedule,Object)
    
    
    GLSchedule::GLSchedule():timestamp(0){
        
    }
    
    GLSchedule::~GLSchedule(){
        
        std::vector<GLTask *>::iterator i = _tasks.begin();
        
        while (i != _tasks.end()) {
            
            GLTask * task = * i;
            
            task->release();
            
            i ++;
            
        }
        
    }
    
    void GLSchedule::tick(){
        
        std::vector<GLTask *>::iterator i = _tasks.begin();
        
        while (i != _tasks.end()) {
            
            GLTask * task = * i;
            
            if(task->start == 0.0){
                task->start = timestamp;
            }
            
            if(timestamp - task->start >= task->afterDelay){
                
                if(task->callback){
                    (* task->callback)(this,this,task);
                }
                
                i = _tasks.erase(i);
            }
            else{
                i ++;
            }
        }
        
    }
    
    void GLSchedule::schedule(GLTask * task){
        task->start = 0;
        task->retain();
        _tasks.push_back(task);
    }
    
    void GLSchedule::unschedule(GLTask * task){
        
        std::vector<GLTask *>::iterator i = _tasks.begin();
        
        while (i != _tasks.end()) {
            
            GLTask * t = * i;
            
            if(t == task){
                i = _tasks.erase(i);
            }
            else {
                i ++;
            }
            
        }
    }

    
}
