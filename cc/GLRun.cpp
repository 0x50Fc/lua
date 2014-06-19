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
            
            gl->begin(context);
            
            gl->draw(context);
            
            GLRunContextChilds(context,element);
            
            gl->end(context);
            
        }
        else {
            GLRunContextChilds(context,element);
        }
        
    }
    
}
