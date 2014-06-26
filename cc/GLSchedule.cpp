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
    
    IMP_CLASS(GLSchedule,GLViewport)
    
    
    GLSchedule::GLSchedule()
    :_timestamp(0),_enabled(true),_tickTimestamp(0),_loader(NULL),_speed(1.0){
        
    }
    
    GLSchedule::GLSchedule(GLLoader * loader)
    :_timestamp(0),_enabled(true),_tickTimestamp(0),_loader(loader),_speed(1.0){
        loader->retain();
    }
    
    GLSchedule::~GLSchedule(){
        
        std::vector<GLTask *>::iterator i = _tasks.begin();
        
        while (i != _tasks.end()) {
            
            GLTask * task = * i;
            
            task->release();
            
            i ++;
            
        }
        
        if(_loader){
            _loader->retain();
        }
        
    }
    
    void GLSchedule::tick(double tickTimestamp){
        
        if(_tickTimestamp == 0 ){
            _tickTimestamp = tickTimestamp;
            _timestamp = 0;
        }
        else if(_enabled){
            _timestamp += (tickTimestamp - _tickTimestamp) * _speed;
            _tickTimestamp = tickTimestamp;
        }
        else {
            _tickTimestamp = tickTimestamp;
        }
        
        std::vector<GLTask *>::iterator i = _tasks.begin();
        
        while (i != _tasks.end()) {
            
            GLTask * task = * i;
            
            if(task->start == 0.0){
                task->start = _timestamp;
            }
            
            if(_timestamp - task->start >= task->afterDelay){
                
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
    
    double GLSchedule::timestamp(){
        return _timestamp;
    }
    
    bool GLSchedule::isEnabled(){
        return _enabled;
    }
    
    void GLSchedule::setEnabled(bool value){
        _enabled = value;
    }
    
    GLLoader * GLSchedule::loader(){
        return _loader;
    }
    
    double GLSchedule::speed(){
        return _speed;
    }
    
    void GLSchedule::setSpeed(double value){
        _speed = value;
    }
    
}
