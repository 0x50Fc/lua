//
//  UILabelElement.h
//  uielement
//
//  Created by zhang hailong on 14-6-21.
//  Copyright (c) 2014年 hailong.org. All rights reserved.
//

#ifndef __uielement__UILabelElement__
#define __uielement__UILabelElement__

#include <iostream>

#include "UICanvasElement.h"

namespace ui {
    
    class UILabelElement : public UICanvasElement {
        
    public:
        
        UILabelElement();
        
        virtual ~UILabelElement();
        
        virtual UIFont font();
        
        virtual UIColor textColor();
        
        virtual UIAlignment alignment();
        
        virtual bool fitFontSize();
        
        virtual UISize layoutChildren(UIEdge padding);
        
        float actualFontSize;
        
        
        DEC_CLASS
        
    protected:
        
    
        virtual void onDraw(CGContextRef context);
        
        
    };
    
}

#endif /* defined(__uielement__UILabelElement__) */
