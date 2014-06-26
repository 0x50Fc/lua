//
//  GLRun.cpp
//  glelement
//
//  Created by zhang hailong on 14-6-19.
//  Copyright (c) 2014年 hailong.org. All rights reserved.
//

#include "GLRun.h"

#include "GLElement.h"

#include "GLCanvasElement.h"

#include "GLControlElement.h"

namespace cc {
    
    void GLRunSchedule(GLSchedule * schedule,Element * element){
        
        if(element->isKindOfClass(& GLElement::clazz)){
            
            GLElement * gl = (GLElement *) element;
            
            gl->tick(schedule);
            
        }
        
        int c = element->childCount();
        
        for(int i=0;i<c;i++){
            
            Element * child = element->childAt(i);
            
            if(child){
                GLRunSchedule(schedule,child);
            }
            
        }
        
    }
    
    static void GLRunContextChilds(GLContext * context,Element * element){
        
        int c = element->childCount();
        
        for(int i=0;i<c;i++){
 
            Element * child = element->childAt(i);
            
            if(child){
                GLRunContext(context,child);
            }
            
        }
        
    }
    
    void GLRunContext(GLContext * context,Element * element){
        
        if(element->isKindOfClass(& GLCanvasElement::clazz)){
            
            GLCanvasElement * gl = (GLCanvasElement *) element;
            
            if(gl->hidden){
                return;
            }
            
            context->zIndex ++;
            
            gl->begin(context);
            
            gl->draw(context);
            
            GLRunContextChilds(context,element);
            
            gl->end(context);
            
        }
        else {
            GLRunContextChilds(context,element);
        }
        
    }
    
    static bool GLRunTouchLocation(GLTouch * touch,GLTouchState touchState,Element * element, GLVector2 location){
        
        if(element->isKindOfClass(& GLLayerElement::clazz)){
            
            GLVector4 frame = ((GLLayerElement *) element)->frame;
            
            location.x -= frame.origin.x;
            location.y -= frame.origin.y;
            
        }
        
        if(element->isKindOfClass(& GLControlElement::clazz)){
            
            GLControlElement * control = (GLControlElement *) element;
            
            if(! control->touchEnabled){
                return false;
            }
            
            if(control->touch(touch,touchState, location)){
                
                int c = element->childCount();
                
                while (-- c >= 0) {
                    
                    Element * child = element->childAt(c);
                    
                    if(GLRunTouchLocation(touch,touchState, child, location) && touchState == GLTouchStateBegin){
                        return true;
                    }
                    
                }
                
                return true;
            }
            else {
                return false;
            }
        }
        else {
            
            int c = element->childCount();
            bool rs = false;
            
            while (-- c >= 0) {
                
                Element * child = element->childAt(c);
                
                if(GLRunTouchLocation(touch,touchState, child, location) ){
                    
                    if(touchState == GLTouchStateBegin){
                        return true;
                    }
                    
                    rs = true;
                }
                
            }
            
            return true;
        }
        
        return false;
    }
    
    bool GLRunTouch(GLTouch * touch,GLTouchState touchState, Element * element){
        
        GLVector2 location({touch->screenX,touch->screenY});
        
        return GLRunTouchLocation(touch,touchState,element, location);
        
    }
    
}
