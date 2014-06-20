//
//  UILayoutElement.cpp
//  uielement
//
//  Created by zhang hailong on 14-6-20.
//  Copyright (c) 2014年 hailong.org. All rights reserved.
//

#include "UILayoutElement.h"

namespace ui {
    
    IMP_CLASS(UILayoutElement,UIElement)
    
    UILayoutElement::UILayoutElement():_layouted(false){
        
    }
    
    UILayoutElement::~UILayoutElement(){
        
    }

    UIRect UILayoutElement::frame(){
        return _frame;
    }
    
    void UILayoutElement::setFrame(UIRect frame){
        _frame = frame;
        _layouted = true;
    }
    
    UISize UILayoutElement::contentSize(){
        return _contentSize;
    }
    
    void UILayoutElement::setContentSize(UISize size){
        _contentSize = size;
    }
    
    UIEdge UILayoutElement::padding(){
        return _padding;
    }
    
    void UILayoutElement::setPadding(UIEdge padding){
        _padding = padding;
    }
    
    UIEdge UILayoutElement::margin(){
        return _margin;
    }
    
    void UILayoutElement::setMargin(UIEdge margin){
        _margin = margin;
    }
    
    UISize UILayoutElement::layoutChildren(UIEdge padding){
   
        UIRect frame = this->frame();
	    UISize size;
	    UISize insetSize(frame.size.width - padding.left - padding.right
                                  , frame.size.height - padding.top - padding.bottom);
	    
	    const char * layout = stringValue("layout", NULL);
 
	    if(layout && strcmp(layout, "flow") == 0){
	        
	    	float x = padding.left;
	    	float y = padding.top;
	        float lineHeight = 0;
	        float width = padding.left + padding.right;
	        float maxWidth = frame.size.width;
	        
	        if(maxWidth == UIAutoValue){
	        	maxWidth = floatValueOf("max-width",insetSize.width, maxWidth);
	        }
            
            for(int i=0;i< childCount();i++){
                
                cc::Element * element = childAt(i);
                
                if(element->isKindOfClass(& UILayoutElement::clazz)){
                    
                    UILayoutElement * layoutElement = (UILayoutElement *) element;
                    
                    float v = floatValueOf("margin", insetSize.width, 0);
                    
                    UIEdge margin(
                                  floatValueOf("margin-left", insetSize.width, v),
                                  floatValueOf("margin-top", insetSize.height, v),
                                  floatValueOf("margin-right", insetSize.width, v),
                                  floatValueOf("margin-bottom", insetSize.height, v));
                    
                    layoutElement->setMargin(margin);
                    
                    layoutElement->layout(UISize(insetSize.width - margin.left - margin.right
                                                 ,insetSize.height - margin.top - margin.bottom));
                    
                    UIRect r = layoutElement->frame();
                    
                    if(( x + r.size.width + margin.left + margin.right <= maxWidth - padding.left)){
		                
		            	r.origin.x = x + margin.left;
		            	r.origin.y = y + margin.top;
		            	
		                x += r.size.width + margin.left + margin.right;
		                
		                if(lineHeight < r.size.height + margin.top + margin.bottom){
		                    lineHeight = r.size.height + margin.top + margin.bottom;
		                }
		                if(width < x + padding.right){
		                    width = x + padding.right;
		                }
		            }
		            else {
		                x = padding.left;
		                y += lineHeight;
		                lineHeight = r.size.height + margin.top + margin.bottom;
		                r.origin.x = x + margin.left;
		                r.origin.y = y + margin.top;
		                x += r.size.width + margin.left + margin.right;
		                if(width < x + padding.right){
		                    width = x + padding.right;
		                }
		            }
                    
                }
                
            }

            size.width = width;
            size.height = y + lineHeight + padding.bottom;
	        
	    }
	    else{
	        
	    	size.width = padding.left + padding.right;
	    	size.height = padding.top + padding.bottom;
	    	
            for(int i=0;i< childCount();i++){
                
                cc::Element * element = childAt(i);
                
                if(element->isKindOfClass(& UILayoutElement::clazz)){
            		
	        		UILayoutElement * layoutElement = (UILayoutElement *) element;
                    
	        		layoutElement->layout(insetSize);
		            
		            UIRect r = layoutElement->frame();
		            
                    float left = layoutElement->floatValueOf("left", insetSize.width, 0);
                    float top = layoutElement->floatValueOf("top", insetSize.width, 0);
                    float right = layoutElement->floatValueOf("right", insetSize.width, 0);
                    float bottom = layoutElement->floatValueOf("bottom", insetSize.width, 0);
                    
		            if(left == UIAutoValue){
		                if(right == UIAutoValue){
		                    r.origin.x = (frame.size.width - r.size.width) / 2.0f;
		                }
		                else{
		                    r.origin.x = (frame.size.width - r.size.width - padding.right - right);
		                }
		            }
		            else{
		                r.origin.x = padding.left + left;
		            }
		            
		            if(top == UIAutoValue){
		                if(bottom == UIAutoValue){
		                    r.origin.y = (frame.size.height - r.size.height) / 2.0f;
		                }
		                else{
		                    r.origin.y = frame.size.height - r.size.height - padding.bottom - bottom;
		                }
		            }
		            else{
		                r.origin.y = padding.top + top;
		            }
		            
		            if(r.origin.x + r.size.width + padding.right > size.width){
		                size.width = r.origin.x + r.size.width +padding.right;
		            }
		            
		            if(r.origin.x + r.size.height + padding.bottom > size.height){
		                size.height = r.origin.y + r.size.height +padding.bottom;
		            }
	        	}
	        }
	    }
	    
	    setContentSize(size);
	    
	    return size;
        
    }
    
    UISize UILayoutElement::layout(UISize size){
        
        float v = floatValueOf("padding", size.width, 0);
        
        UIEdge padding(
                       floatValueOf("padding-left", size.width, v),
                       floatValueOf("padding-top", size.height, v),
                       floatValueOf("padding-right", size.width, v),
                       floatValueOf("padding-height", size.height, v)
        );
        
        setPadding(padding);
        
        UIRect frame (
                      0,0,
                      floatValueOf("width", size.width, 0),
                      floatValueOf("height", size.height, 0)
        );
        
        setFrame(frame);
        
        if(frame.size.width == UIAutoValue || frame.size.height == UIAutoValue){
            
            UISize contentSize = layoutChildren(padding);
            
            if(frame.size.width == UIAutoValue){
                frame.size.width = contentSize.width;
                float max = floatValueOf("max-width", size.width, frame.size.width);
                float min = floatValueOf("min-width", size.width, frame.size.width);
                if(frame.size.width > max){
                    frame.size.width = max;
                }
                if(frame.size.width < min){
                    frame.size.width = min;
                }
            }
            
            if(frame.size.height == UIAutoValue){
                frame.size.height = contentSize.height;
                float max = floatValueOf("max-width", size.height, frame.size.height);
                float min = floatValueOf("min-width", size.height, frame.size.height);
                if(frame.size.height > max){
                    frame.size.height = max;
                }
                if(frame.size.height < min){
                    frame.size.height = min;
                }
            }

            setFrame(frame);
            
            return contentSize;
        }
        else {
            return layoutChildren(padding);
        }
    }
    
    UISize UILayoutElement::layout(){
        return layoutChildren(padding());
    }
    
    bool UILayoutElement::isLayouted(){
        return _layouted;
    }
}

