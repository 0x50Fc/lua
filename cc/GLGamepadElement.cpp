//
//  GLGamepadElement.cpp
//  glelement
//
//  Created by zhang hailong on 14-6-24.
//  Copyright (c) 2014年 hailong.org. All rights reserved.
//

#include "GLGamepadElement.h"

#include "GLGamepadAction.h"

namespace cc {
    
    IMP_CLASS(GLGamepadElement,GLControlElement)
    
    GLGamepadElement::GLGamepadElement()
        :_beginElement(NULL),_toElement(NULL),_buttonsElement(NULL),_touch(NULL)
        ,_beginLocation({0.0,0.0}),_toLocation({0.0,0.0}){
        
    }
    
    GLGamepadElement::~GLGamepadElement(){
        
    }
    
    void GLGamepadElement::begin(GLContext * context){
        
        frame.origin.x = frame.origin.y = 0;
        frame.size.width = context->width();
        frame.size.height = context->height();
        
        if(_beginElement){
            
            GLVector4 frame = _beginElement->frame;
            
            if(_touch){
                frame.origin.x  = _beginLocation.x - frame.size.width / 2.0;
                frame.origin.y  = _beginLocation.y - frame.size.width / 2.0;
            }
            else {
                frame.origin.x = 20;
                frame.origin.y = context->height() - frame.size.height - 20;
            }
            
            _beginElement->frame = frame;
        }
        
        if(_toElement){
            
            GLVector4 frame = _toElement->frame;
            
            if(_touch){
                GLfloat dx = _toLocation.x - _beginLocation.x;
                GLfloat dy = _toLocation.y - _beginLocation.y;
                GLfloat r = sqrt(dx * dx + dy * dy);
                GLfloat rr = r > 50 ? 50 : r;
                frame.origin.x  = _beginLocation.x + rr * dx / r - frame.size.width / 2.0;
                frame.origin.y  = _beginLocation.y + rr * dy / r - frame.size.width / 2.0;
            }
            else {
                
                frame.origin.x = 20;
                frame.origin.y = context->height() - frame.size.height - 20;
                
                if(_beginElement){
                    frame.origin.x += (_beginElement->frame.size.width - frame.size.width) / 2.0;
                    frame.origin.y -= (_beginElement->frame.size.height - frame.size.height) / 2.0;
                }

            }
            
            _toElement->frame = frame;
        }
        
        if(_buttonsElement){
            
            GLVector4 frame = _buttonsElement->frame;
            
            frame.origin.x = context->width() - frame.size.width - 20;
            frame.origin.y = context->height() - frame.size.height - 20;
            
            _buttonsElement->frame = frame;
            
        }
        
        GLControlElement::begin(context);
    }
    
    bool GLGamepadElement::touch(GLTouch * touch,GLTouchState touchState, GLVector2 location){
        
        if((touchState == GLTouchStateEnded || touchState == GLTouchStateCanceled) && _touch == touch){
            
            _touch = NULL;
            
            GLVector2 v2 = {0,0};
            
            GLGamepadAction * action = new GLGamepadAction(this,v2);
            
            doAction(action);
            
            action->release();
            
        }
        
        if(GLControlElement::touch(touch,touchState,location)){
            
            if(_touch == NULL && touchState == GLTouchStateBegin) {
                if(location.x < touch->screenWidth / 2.0 && location.y > touch->screenHeight / 2.0){
                    _touch = touch;
                    _beginLocation = location;
                    _toLocation = location;
                    
                    GLVector2 v2 = {_toLocation.x - _beginLocation.x,_toLocation.y - _beginLocation.y};
                    
                    GLGamepadAction * action = new GLGamepadAction(this,v2);
                    
                    doAction(action);
                    
                    action->release();
                    
                }
            }
            else if(_touch == touch && touchState == GLTouchStateMoved){
                _toLocation = location;
                
                GLVector2 v2 = {_toLocation.x - _beginLocation.x,_toLocation.y - _beginLocation.y};
                
                GLGamepadAction * action = new GLGamepadAction(this,v2);
                
                doAction(action);
                
                action->release();
            }
            
            return true;
        }
        
        return false;
    }
    
    void GLGamepadElement::addChild(Element * element){
        
        if(_beginElement == NULL && strcmp(element->name(),"begin") ==0
           && element->isKindOfClass(& GLLayerElement::clazz)){
            _beginElement = (GLLayerElement *) element;
        }
        
        if(_toElement == NULL && strcmp(element->name(),"to") ==0
           && element->isKindOfClass(& GLLayerElement::clazz)){
            _toElement = (GLLayerElement *) element;
        }
        
        if(_buttonsElement == NULL && strcmp(element->name(),"buttons") ==0
           && element->isKindOfClass(& GLLayerElement::clazz)){
            _buttonsElement = (GLLayerElement *) element;
        }
        
        GLControlElement::addChild(element);
    }
    
    void GLGamepadElement::removeChild(Element * element){
        
        if(_beginElement == element){
            _beginElement =  NULL;
        }
        if(_toElement == element){
            _toElement =  NULL;
        }
        if(_buttonsElement == element){
            _buttonsElement =  NULL;
        }
        
        GLControlElement::removeChild(element);
    }
    
}
