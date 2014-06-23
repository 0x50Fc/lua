//
//  GLAnimationElement.cpp
//  glelement
//
//  Created by zhang hailong on 14-6-23.
//  Copyright (c) 2014年 hailong.org. All rights reserved.
//

#include "GLAnimationElement.h"

namespace cc {
    
    IMP_CLASS(GLAnimationElement, GLElement)
    
    GLAnimationElement::GLAnimationElement():_status(GLScheduleStatusNone),_timestamp(0){
        
    }
    
    GLAnimationElement::~GLAnimationElement(){
        
    }
    
    void GLAnimationElement::tick(GLSchedule * schedule){
        
        if(_tickTimestamp == 0 || _status != GLScheduleStatusNone){
            _tickTimestamp = schedule->timestamp();
        }
        
        if(_status == GLScheduleStatusNone){
            _timestamp += schedule->timestamp() - _tickTimestamp;
        }

        GLElement::tick(schedule);
    }
    
    double GLAnimationElement::timestamp(){
        return _timestamp;
    }
    
    GLScheduleStatus GLAnimationElement::status(){
        return _status;
    }
    
    void GLAnimationElement::setStatus(GLScheduleStatus value){
        _status = value;
    }
    
    double GLAnimationElement::duration(){
        return _duration;
    }
    
    void GLAnimationElement::setDuration(double duration){
        _duration = duration;
    }
    
    Value GLAnimationElement::value(const char * key){
        
        if(strcmp(key, "duration") == 0){
            return Value(_duration);
        }
        else if(strcmp(key, "status") == 0){
            return Value((int) _status);
        }
        else {
            return GLElement::value(key);
        }
    }
    
    void GLAnimationElement::setValue(const char * key,Value value){
        
        if(strcmp(key, "duration") == 0){
            _duration = ValueToDouble(value, _duration);
        }
        else if(strcmp(key, "status") == 0){
            _status = (GLScheduleStatus) ValueToInt(value, _status);
        }
        else {
            GLElement::setValue(key,value);
        }
        
    }
    
    double GLAnimationElement::value(){
        return _duration == 0.0 ? 0.0 : _timestamp / _duration;
    }
    
}
