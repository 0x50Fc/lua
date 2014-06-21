//
//  UICanvasElement.h
//  uielement
//
//  Created by zhang hailong on 14-6-20.
//  Copyright (c) 2014年 hailong.org. All rights reserved.
//

#ifndef __uielement__UICanvasElement__
#define __uielement__UICanvasElement__

#include <iostream>

#include "UILayoutElement.h"
#include "UI.h"
#include <QuartzCore/QuartzCore.h>

#import "IUIViewEntity.h"

namespace ui {
    
    class UICanvasElement : public UILayoutElement {
    
    public:
        
        UICanvasElement();
        
        virtual ~UICanvasElement();
        
        virtual bool isHidden();
        
        virtual void drawInContext(CGContextRef context);
        
        virtual UIColor backgroundColor();
        
        virtual UIColor borderColor();
        
        virtual float borderWidth();
        
        virtual float cornerRadius();
        
        virtual id<IUIViewEntity> viewEntity();
        
        virtual void setViewEntity(id<IUIViewEntity> viewEntity);
        
        virtual bool isViewEntity(id<IUIViewEntity> viewEntity);
        
        virtual void setNeedsDisplay();
        
        DEC_CLASS
        
    protected:
        
        virtual void onDrawBackground(CGContextRef context);
        
        virtual void onDraw(CGContextRef context);
        
        virtual void onDrawBorder(CGContextRef context);
        
        virtual void onViewEntityChanged(id<IUIViewEntity> viewEntity);
        
    private:
        
        id<IUIViewEntity> _viewEntity;
    };
    
    void UICanvasRun(id<IUIViewEntity> viewEntity, CGContextRef context,cc::Element * element);
    
}

#endif /* defined(__uielement__UICanvasElement__) */
