//
//  GLElement.cpp
//  glelement
//
//  Created by zhang hailong on 14-6-19.
//  Copyright (c) 2014年 hailong.org. All rights reserved.
//

#include "GLElement.h"


namespace cc {
    
    
    IMP_CLASS(GLElement, Element)
    
    GLElement::GLElement(){
        
    }
    
    GLElement::~GLElement(){
        
        std::vector<GLTask *>::iterator i = _tasks.begin();
        
        while (i != _tasks.end()) {
            
            GLTask * task = * i;
            
            task->release();
            
            i ++;
            
        }
        
    }
    
    void GLElement::tick(GLSchedule * schedule){
        
        std::vector<GLTask *>::iterator i = _tasks.begin();
        
        while (i != _tasks.end()) {
            
            GLTask * task = * i;
            
            if(task->start == 0.0){
                task->start = schedule->timestamp();
            }
            
            if(schedule->timestamp() - task->start >= task->afterDelay){
                
                if(task->callback){
                    (* task->callback)(schedule,this,task);
                }
                
                i = _tasks.erase(i);
            }
            else{
                i ++;
            }
        }
        
    }
  
    void GLElement::schedule(GLTask * task){
        task->start = 0;
        task->retain();
        _tasks.push_back(task);
    }
    
    void GLElement::unschedule(GLTask * task){
        
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
