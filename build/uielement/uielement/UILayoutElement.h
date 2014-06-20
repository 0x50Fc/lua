//
//  UILayoutElement.h
//  uielement
//
//  Created by zhang hailong on 14-6-20.
//  Copyright (c) 2014年 hailong.org. All rights reserved.
//

#ifndef __uielement__UILayoutElement__
#define __uielement__UILayoutElement__

#include <iostream>

#include "UIElement.h"

#include "UI.h"

namespace ui {
    
    class UILayoutElement : public UIElement {
  
    public:
        
        UILayoutElement();
        
        virtual ~UILayoutElement();
        
        virtual UIRect frame();
        
        virtual void setFrame(UIRect frame);
        
        virtual UISize contentSize();
        
        virtual void setContentSize(UISize size);
        
        virtual UIEdge padding();
        
        virtual void setPadding(UIEdge padding);
        
        virtual UIEdge margin();
        
        virtual void setMargin(UIEdge margin);
        
        virtual UISize layoutChildren(UIEdge padding);
        
        virtual UISize layout(UISize size);
        
        virtual UISize layout();
        
        virtual bool isLayouted();
        
        DEC_CLASS
        
    private:
        
        UIRect _frame;
        UISize _contentSize;
        UIEdge _padding;
        UIEdge _margin;
        bool _layouted;
        
    };
}

#endif /* defined(__uielement__UILayoutElement__) */
