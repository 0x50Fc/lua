//
//  UICanvasElement.cpp
//  uielement
//
//  Created by zhang hailong on 14-6-20.
//  Copyright (c) 2014年 hailong.org. All rights reserved.
//

#include "UICanvasElement.h"


namespace ui {

    IMP_CLASS(UICanvasElement, UILayoutElement)

    UICanvasElement::UICanvasElement():_viewEntity(nil){
        
    }
    
    UICanvasElement::~UICanvasElement(){
        
    }
   
    void UICanvasElement::drawInContext(CGContextRef context){
        
        onDrawBackground(context);
        
        onDraw(context);
        
        onDrawBorder(context);
    
    }
    
    void UICanvasElement::onDrawBackground(CGContextRef context){
        
        UIColor c = backgroundColor();
        UIRect r = frame();
        
        if(c.a){
            
            CGColorSpaceRef colorSpace = CGColorSpaceCreateDeviceRGB();
            
            CGContextSetFillColorSpace(context, colorSpace);
            
            CGFloat cc[4] = {c.r,c.g,c.b,c.a};
            
            CGContextSetFillColor(context, cc);
            
            CGContextFillRect(context, CGRectMake(0, 0, r.size.width, r.size.height));

            CFRelease(colorSpace);
            
        }
        
    }
    
    void UICanvasElement::onDrawBorder(CGContextRef context){
        
        UIColor c = borderColor();
        float width = borderWidth();
        UIRect r = frame();
        
        if(c.a && width){
            
            CGColorSpaceRef colorSpace = CGColorSpaceCreateDeviceRGB();
            
            CGContextSetStrokeColorSpace(context, colorSpace);
            
            CGFloat cc[4] = {c.r,c.g,c.b,c.a};
            
            CGContextSetStrokeColor(context, cc);
            
            CGContextSetLineWidth(context, width);
            
            float radius = cornerRadius();
            
            if(radius == 0.0){
                CGContextAddRect(context, CGRectMake(0, 0, r.size.width, r.size.height));
                CGContextDrawPath(context, kCGPathStroke);
            }
            else{
                
                // 移动到初始点
                CGContextMoveToPoint(context, radius, 0);
                
                // 绘制第1条线和第1个1/4圆弧
                CGContextAddLineToPoint(context, r.size.width - radius, 0);
                CGContextAddArc(context, r.size.width - radius, radius, radius, - M_PI_2, 0.0, 0);
                
                // 绘制第2条线和第2个1/4圆弧
                CGContextAddLineToPoint(context, r.size.width, r.size.height - radius);
                CGContextAddArc(context, r.size.width - radius, r.size.height - radius, radius, 0.0, M_PI_2, 0);
                
                // 绘制第3条线和第3个1/4圆弧
                CGContextAddLineToPoint(context, radius, r.size.height);
                CGContextAddArc(context, radius, r.size.height - radius, radius, M_PI_2, M_PI, 0);
                
                // 绘制第4条线和第4个1/4圆弧
                CGContextAddLineToPoint(context, 0, radius);
                CGContextAddArc(context, radius, radius, radius, M_PI, 1.5 * M_PI, 0);
                
                // 闭合路径
                CGContextClosePath(context);
                
                CGContextDrawPath(context, kCGPathStroke);
            }
            
            CFRelease(colorSpace);
            
        }
        
    }
    
    void UICanvasElement::onDraw(CGContextRef context){
        
    }
    
    bool UICanvasElement::isHidden(){
        return booleanValue("hidden", false) || ! booleanValue("visable", true);
    }
    
    UIColor UICanvasElement::backgroundColor(){
        return colorValue("background-color", ui::UIColor());
    }
    
    UIColor UICanvasElement::borderColor(){
        return colorValue("background-color", ui::UIColor());
    }
    
    float UICanvasElement::borderWidth(){
        return floatValue("border-width", 0);
    }
    
    float UICanvasElement::cornerRadius(){
        return floatValue("corner-radius", 0);
    }
    
    id<IUIViewEntity> UICanvasElement::viewEntity(){
        if(_viewEntity == NULL ){
            cc::Element * p = parent();
            if(p && p->isKindOfClass(& UICanvasElement::clazz)){
                return ((UICanvasElement *) p)->viewEntity();
            }
        }
        return _viewEntity;
    }
    
    void UICanvasElement::setViewEntity(id<IUIViewEntity> viewEntity){
        if(_viewEntity != viewEntity){
            if([_viewEntity respondsToSelector:@selector(elementDetach:)]){
                [_viewEntity elementDetach:this];
            }
            _viewEntity = viewEntity;
            onViewEntityChanged(viewEntity);
        }
    }
    
    void UICanvasElement::onViewEntityChanged(id<IUIViewEntity> viewEntity){
        
        int c = childCount();
        
        for(int i=0;i<c;i++){
            
            cc::Element * element = childAt(i);
            
            if(element->isKindOfClass(& UICanvasElement::clazz)){
                ((UICanvasElement *) element)->onViewEntityChanged(viewEntity);
            }
            
        }
    }
    
    bool UICanvasElement::isViewEntity(id<IUIViewEntity> viewEntity){
        return _viewEntity == nil || _viewEntity == viewEntity;
    }
    
    void UICanvasElement::setNeedsDisplay(){
        if([_viewEntity respondsToSelector:@selector(elementDoNeedsDisplay:)]){
            [_viewEntity elementDoNeedsDisplay:this];
        }
    }
    
    void UICanvasRun(id<IUIViewEntity> viewEntity,CGContextRef context,cc::Element * element){
        
        if(element->isKindOfClass(& UICanvasElement::clazz)){
        
            UICanvasElement * canvas = (UICanvasElement *) element;
        
            if(! canvas->isViewEntity(viewEntity) || canvas->isHidden()){
                return;
            }
            
            canvas->drawInContext(context);
            
        }
        
        int c = element->childCount();
        
        for(int i=0;i<c;i++){
            
            cc::Element * child = element->childAt(i);
            
            CGContextSaveGState(context);
            
            if(child->isKindOfClass(& UILayoutElement::clazz)){
                
                UIRect frame = ((UILayoutElement *) child)->frame();
                
                CGContextTranslateCTM(context, frame.origin.x, frame.origin.y);
                
                if(child->isKindOfClass(& UICanvasElement::clazz)){
                    
                    float radius = ((UICanvasElement *) child)->cornerRadius();
                    
                    if(radius == 0.0){
                        CGContextClipToRect(context, CGRectMake(0, 0, frame.size.width, frame.size.height) );
                    }
                    else{
                        
                        // 移动到初始点
                        CGContextMoveToPoint(context, radius, 0);
                        
                        // 绘制第1条线和第1个1/4圆弧
                        CGContextAddLineToPoint(context, frame.size.width - radius, 0);
                        CGContextAddArc(context, frame.size.width - radius, radius, radius, - M_PI_2, 0.0, 0);
                        
                        // 绘制第2条线和第2个1/4圆弧
                        CGContextAddLineToPoint(context, frame.size.width, frame.size.height - radius);
                        CGContextAddArc(context, frame.size.width - radius, frame.size.height - radius, radius, 0.0, M_PI_2, 0);
                        
                        // 绘制第3条线和第3个1/4圆弧
                        CGContextAddLineToPoint(context, radius, frame.size.height);
                        CGContextAddArc(context, radius, frame.size.height - radius, radius, M_PI_2, M_PI, 0);
                        
                        // 绘制第4条线和第4个1/4圆弧
                        CGContextAddLineToPoint(context, 0, radius);
                        CGContextAddArc(context, radius, radius, radius, M_PI, 1.5 * M_PI, 0);
                        
                        // 闭合路径
                        CGContextClosePath(context);
                        
                        CGContextClip(context);
                    }
                    
                    
                }
                else {
                    CGContextClipToRect(context, CGRectMake(0, 0, frame.size.width, frame.size.height) );
                }
                
            }
            
            UICanvasRun(viewEntity,context,child);
            
            CGContextRestoreGState(context);
        }
    }
}
