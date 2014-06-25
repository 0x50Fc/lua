//
//  GLTacticFramesElement.cpp
//  glelement
//
//  Created by zhang hailong on 14-6-25.
//  Copyright (c) 2014年 hailong.org. All rights reserved.
//

#include "GLTacticFramesElement.h"

#include "GLCanvasElement.h"

#include "GLRoleElement.h"

#include "Log.h"

namespace cc {
    
    
    IMP_CLASS(GLTacticFramesElement, GLTacticElement)
    
    GLTacticFramesElement::GLTacticFramesElement():duration(0),visableStatus(0),enabledStatus(0),visable(true){
        
    }
    
    GLTacticFramesElement::~GLTacticFramesElement(){
        
    }
    
    void GLTacticFramesElement::tick(GLSchedule * schedule){
        GLTacticElement::tick(schedule);
        
        if(visable){
        
            int c = childCount();
            
            if(c == 1){
                Element * el = childAt(0);
                if(el->isKindOfClass(& GLCanvasElement::clazz)){
                    ((GLCanvasElement *) el)->hidden = false;
                }
            }
            else if(c > 1 && duration > 0.0){
                
                int index ;
                
                if(isEnabled()){
                    index =(int) (c * timestamp() / duration) % c;
                }
                else {
                    index = defaultIndex;
                }
                
                for (int i=0;i <c ;i++ ) {
                    Element * el = childAt(i);
                    if(el->isKindOfClass(& GLCanvasElement::clazz)){
                        ((GLCanvasElement *) el)->hidden = (i != index);
                    }
                }
            }
        }
        else{
            
            int c = childCount();
            
            for (int i=0;i <c ;i++ ) {
                Element * el = childAt(i);
                if(el->isKindOfClass(& GLCanvasElement::clazz)){
                    ((GLCanvasElement *) el)->hidden = true;
                }
            }
            
        }
    }
    
    Value GLTacticFramesElement::value(const char * key){
        if(strcmp(key, "duration") == 0){
            return Value(duration);
        }
        else if(strcmp(key, "visableStatus") == 0){
            return Value(visableStatus);
        }
        else if(strcmp(key, "enabledStatus") == 0){
            return Value(enabledStatus);
        }
        else if(strcmp(key, "defaultIndex") == 0){
            return Value(defaultIndex);
        }
        else {
            return GLTacticElement::value(key);
        }
    }
    
    void GLTacticFramesElement::setValue(const char * key,Value value){
        if(strcmp(key, "duration") == 0){
            duration = ValueToDouble(value, duration);
        }
        else if(strcmp(key, "visableStatus") == 0){
            visableStatus = ValueToInt(value, 0);
        }
        else if(strcmp(key, "enabledStatus") == 0){
            enabledStatus = ValueToInt(value, 0);
        }
        else if(strcmp(key, "defaultIndex") == 0){
            defaultIndex = ValueToInt(value, 0);
        }
        else {
            GLTacticElement::setValue(key,value);
        }
    }
    
    void GLTacticFramesElement::onElementChanged(Element * element){
        if(element->isKindOfClass(& GLRoleElement::clazz)){
            GLRoleElement * role = (GLRoleElement *) element;
            setEnabled(enabledStatus == 0 || role->hasStatus(enabledStatus));
            visable = visableStatus == 0 || role->hasStatus(visableStatus);
        }
    }
    
}
