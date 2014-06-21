//
//  UIControlElement.h
//  uielement
//
//  Created by zhang hailong on 14-6-21.
//  Copyright (c) 2014年 hailong.org. All rights reserved.
//

#ifndef __uielement__UIControlElement__
#define __uielement__UIControlElement__

#include <iostream>

#include "UICanvasElement.h"

namespace ui {
    
    class UIControlElement : public UICanvasElement {
    
    public:
        
        UIControlElement();
        
        virtual ~UIControlElement();
        
        virtual bool onToucheBegin(UIPoint location);
        
        virtual void onToucheMoved(UIPoint location);
        
        virtual void onToucheEnd(UIPoint location);
        
        virtual void onToucheCanceled(UIPoint location);
        
        virtual bool isEnabled();
        
        DEC_CLASS
    };
    
}

#endif /* defined(__uielement__UIControlElement__) */
