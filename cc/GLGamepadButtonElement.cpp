//
//  GLGamepadButtonElement.cpp
//  glelement
//
//  Created by zhang hailong on 14-6-24.
//  Copyright (c) 2014年 hailong.org. All rights reserved.
//

#include "GLGamepadButtonElement.h"

#include "GLGamepadAction.h"

#include "Log.h"

namespace cc {
    
    IMP_CLASS(GLGamepadButtonElement,GLControlElement)
    
    
    GLGamepadButtonElement::GLGamepadButtonElement():_insetTouch(false),_touch(NULL){
        
    }
    
    GLGamepadButtonElement::~GLGamepadButtonElement(){
        
    }

    
    bool GLGamepadButtonElement::touch(GLTouch * touch,GLTouchState touchState, GLVector2 location){
        
        bool rs = GLControlElement::touch(touch,touchState,location);
        
        if(_touch == NULL && touchState == GLTouchStateBegin && rs){
            _touch = touch;
            _insetTouch = true;
            
            GLGamepadAction * action = new GLGamepadAction(this,name(),GLGamepadActionTypeButtonDown);
            doAction(action);
            action->release();
            
        }
        
        if(_touch == touch && touchState == GLTouchStateMoved){
            _insetTouch = location.x >=0 && location.y >=0 && location.x < frame.size.width && location.y < frame.size.height;
        }
        
        if(_touch == touch && (touchState == GLTouchStateCanceled || touchState == GLTouchStateEnded)){
            
            GLGamepadAction * action = new GLGamepadAction(this,name(),_insetTouch ? GLGamepadActionTypeButtonUpInset : GLGamepadActionTypeButtonUp);
            doAction(action);
            action->release();
            
            _touch = NULL;
            _insetTouch = false;
        }
        
        if(_insetTouch){
            scale = 0.9;
        }
        else {
            scale = 1.0;
        }
        
        return rs;
    }
    
}
