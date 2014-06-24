//
//  GLGamepadAction.cpp
//  glelement
//
//  Created by zhang hailong on 14-6-24.
//  Copyright (c) 2014年 hailong.org. All rights reserved.
//

#include "GLGamepadAction.h"

namespace cc {
    
    
    IMP_CLASS(GLGamepadAction, Action)
    
    GLGamepadAction::GLGamepadAction():_position({0.0,0.0}),_actionType(GLGamepadActionTypeNone){
        
    }
    
    GLGamepadAction::GLGamepadAction(Element * element,GLVector2 position)
        :Action(element)
        ,_position(position)
        ,_actionType(GLGamepadActionTypePosition)
        ,_buttonName("position"){
        
    }
    
    GLGamepadAction::GLGamepadAction(Element * sender,const char * buttonName,GLGamepadActionType actionType)
        :Action(sender)
        ,_buttonName(buttonName)
        ,_position({0.0,0.0})
        ,_actionType(actionType){
        
    }
    
    GLGamepadAction::~GLGamepadAction(){
        
    }
    
    const char * GLGamepadAction::buttonName(){
        return _buttonName.c_str();
    }
    
    GLVector2 GLGamepadAction::position(){
        return _position;
    }
    
    GLGamepadActionType GLGamepadAction::actionType(){
        return _actionType;
    }
    
    Value GLGamepadAction::value(const char * key){
        
        if(strcmp(key,"actionType") == 0){
            return Value((int) _actionType);
        }
        else if(strcmp(key,"x") == 0){
            return Value((double) _position.x);
        }
        else if(strcmp(key,"y") == 0){
            return Value((double) _position.y);
        }
        else if(strcmp(key,"buttonName") == 0){
            return Value(_buttonName.c_str());
        }
        else {
            return Action::value(key);
        }
    }
    
    
}
