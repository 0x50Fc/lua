//
//  GLTouch.cpp
//  glelement
//
//  Created by zhang hailong on 14-6-24.
//  Copyright (c) 2014年 hailong.org. All rights reserved.
//

#include "GLTouch.h"

#include "GLScreenElement.h"
#include "GLLayerElement.h"

namespace cc {
    
    IMP_CLASS(GLTouch, Object)
    
    GLTouch::GLTouch():screenX(0),screenY(0),cancled(false),screenWidth(0),screenHeight(0){
        
    }
    
    GLTouch::GLTouch(GLfloat screenX,GLfloat screenY,GLfloat screenWidth,GLfloat screenHeight)
        :screenX(screenX),screenY(screenY),cancled(false),screenWidth(screenWidth),screenHeight(screenHeight){
        
    }
    
    GLTouch::~GLTouch(){
        
    }
    
    GLVector2 GLTouch::locationInElement(Element * element){
        
        GLVector2 location({screenX,screenY});
        
        while (element && ! element->isKindOfClass(& GLScreenElement::clazz)) {
            
            if(element->isKindOfClass(& GLLayerElement::clazz )){
                
                GLVector4 frame = ((GLLayerElement *) element)->frame;
                
                location.x -= frame.origin.x;
                location.y -= frame.origin.y;
                
            }
            
            element = element->parent();
            
        }
        
        return location;
    }
    
    

}
