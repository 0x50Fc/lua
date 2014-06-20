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
   
        UIRect frame = frame();
	    UISize size();
	    UISize insetSize = new Size(frame.size.width - padding.left - padding.right
                                  , frame.size.height - padding.top - padding.bottom);
	    
	    const char * layout = stringValue("layout", NULL);
 
	    if(layout &&& strcmp(layout, "flow") == 0){
	        
	    	float x = padding.left;
	    	float y = padding.top
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
                    
                    float margin = floatValueOf("margin", insetSize.width, 0);
                    
                    UIEdge margin(
                                  floatValueOf("margin-left", insetSize.width, margin),
                                  floatValueOf("margin-top", insetSize.height, margin),
                                  floatValueOf("margin-right", insetSize.width, margin),
                                  floatValueOf("margin-bottom", insetSize.height, margin),
                    );
                    
                    layoutElement->setMargin(margin);
                    
                    layoutElement->layout(UISize(insetSize.width - margin.left - margin.right
                                                 ,insetSize.height - margin.top - margin.bottom));
                    
                    UIRect r = layoutElement->frame();
                    
                    if(( x + r.size.width + margin.left + margin.right <= maxWidth - padding.left)){
		                
		            	r.x = x + margin.left;
		            	r.y = y + margin.top;
		            	
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
		                r.x = x + margin.left;
		                r.y = y + margin.top;
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
		            
		            Rect r = layoutElement.getFrame();
		            
		            String left = element.stringValue("left","0");
		            String right = element.stringValue("right","0");
		            String top = element.stringValue("top","0");
		            String bottom = element.stringValue("bottom","0");
		            
		            if("auto".equals(left)){
		                if("auto".equals(right)){
		                    r.x = (frame.getWidth() - r.getWidth()) / 2.0f;
		                }
		                else{
		                    r.x = (frame.getWidth() - r.getWidth() - padding.right - Float.valueOf(right));
		                }
		            }
		            else{
		                r.x = padding.left + Float.valueOf(left);
		            }
		            
		            if("auto".equals(top)){
		                if("auto".equals(bottom)){
		                    r.y = (frame.getHeight() - r.getHeight()) / 2.0f;
		                }
		                else{
		                    r.y = frame.getHeight() - r.getHeight() - padding.bottom - Float.valueOf(bottom);
		                }
		            }
		            else{
		                r.y = padding.top + Float.valueOf(top);
		            }
		            
		            if(r.getX() + r.getWidth() + padding.right > size.getWidth()){
		                size.width = r.getX() +r.getWidth() +padding.right;
		            }
		            
		            if(r.getY() + r.getHeight() + padding.bottom > size.getHeight()){
		                size.height = r.getY() +r.getHeight() +padding.bottom;
		            }
	        	}
	        }
	    }
	    
	    setContentSize(size);
	    
	    return size;
        
    }
    
    UISize UILayoutElement::layout(UISize size){
        
        float padding = floatValueOf("padding", size.width, 0);
        
        UIEdge padding(
                       floatValueOf("padding-left", size.width, padding),
                       floatValueOf("padding-top", size.height, padding),
                       floatValueOf("padding-right", size.width, padding),
                       floatValueOf("padding-height", size.height, padding),
        );
        
        setPadding(padding);
        
        UIRect frame (
                      0,0,
                      floatValueOf("width", size.width, 0),
                      floatValueOf("height", size.height, 0),
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

