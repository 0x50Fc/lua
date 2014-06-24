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
    
    GLAnimationElement::GLAnimationElement():_enabled(true),_timestamp(0){
        
    }
    
    GLAnimationElement::~GLAnimationElement(){
        
    }
    
    void GLAnimationElement::tick(GLSchedule * schedule){
        
        if(_tickTimestamp == 0 ){
            _tickTimestamp = schedule->timestamp();
            _timestamp = 0;
        }
        else if(_enabled){
            _timestamp += schedule->timestamp() - _tickTimestamp;
            _tickTimestamp = schedule->timestamp();
        }
        else {
            _tickTimestamp = schedule->timestamp();
        }

        GLElement::tick(schedule);
    }
    
    double GLAnimationElement::timestamp(){
        return _timestamp;
    }
    
    Value GLAnimationElement::value(const char * key){
        
        if(strcmp(key, "enabled") == 0){
            return Value(_enabled);
        }
        else {
            return GLElement::value(key);
        }
    }
    
    void GLAnimationElement::setValue(const char * key,Value value){
        
        if(strcmp(key, "enalbed") == 0){
            _enabled = ValueToBoolean(value, _enabled);
        }
        else {
            GLElement::setValue(key,value);
        }
        
    }
    
    bool GLAnimationElement::isEnabled(){
        return _enabled;
    }
    
    void GLAnimationElement::setEnabled(bool value){
        _enabled = value;
    }
    
    
}
