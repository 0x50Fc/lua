//
//  UIControlElement.cpp
//  uielement
//
//  Created by zhang hailong on 14-6-21.
//  Copyright (c) 2014年 hailong.org. All rights reserved.
//

#include "UIControlElement.h"

namespace ui {
    
    IMP_CLASS(UIControlElement, UICanvasElement)
    
    UIControlElement::UIControlElement(){
        
    }
    
    UIControlElement::~UIControlElement(){
        
    }
    
    bool UIControlElement::onToucheBegin(UIPoint location){
        return false;
    }
    
    void UIControlElement::onToucheMoved(UIPoint location){
        
    }
    
    void UIControlElement::onToucheEnd(UIPoint location){
        
    }
    
    void UIControlElement::onToucheCanceled(UIPoint location){
        
    }
    
    bool UIControlElement::isEnabled(){
        return booleanValue("enabled", true) && ! booleanValue("disabled", false);
    }
    
    
    
}
