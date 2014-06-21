//
//  UILabelElement.cpp
//  uielement
//
//  Created by zhang hailong on 14-6-21.
//  Copyright (c) 2014年 hailong.org. All rights reserved.
//

#include "UILabelElement.h"


static ui::UISize UILabelElementLayoutChildren(ui::UILabelElement * element, ui::UIEdge padding){
    
    ui::UIRect r = element->frame();
    
    if(r.size.width == ui::UIAutoValue || r.size.height == ui::UIAutoValue){
        
        const char * v = element->text();
        
        NSString * text = v ? [NSString stringWithCString:v encoding:NSUTF8StringEncoding] : nil;
        
        if(text){
            
            ui::UIFont f = element->font();
            bool fitFontSize = element->fitFontSize();
            
            UIFont * font = nil;
            
            if(* f.name == '\0'){
                
                switch (f.style) {
                    case ui::UIFontStyleBold:
                        font = [UIFont boldSystemFontOfSize:f.size];
                        break;
                    case ui::UIFontStyleItalic:
                        font = [UIFont italicSystemFontOfSize:f.size];
                        break;
                    default:
                        font = [UIFont systemFontOfSize:f.size];
                        break;
                }
                
            }
            else {
                font = [UIFont fontWithName:[NSString stringWithCString:f.name encoding:NSUTF8StringEncoding] size:f.size];
            }
            
            if(font == nil){
                font = [UIFont systemFontOfSize:f.size];
            }
            
            CGFloat width = r.size.width;
            CGFloat height = r.size.height;
            
            if(width == ui::UIAutoValue){
                width = element->floatValue("max-width", width);
            }
            
            if(height == ui::UIAutoValue){
                height = element->floatValue("max-height", height);
            }
            
            CGSize s = CGSizeZero;
            
            if(! fitFontSize ){
                element->actualFontSize = 0;
                s = [text sizeWithFont:font constrainedToSize:CGSizeMake(width, height) lineBreakMode:NSLineBreakByCharWrapping];
            }
            else{
                
                CGFloat actualFontSize = 0;
                
                s = [text sizeWithFont:font minFontSize:1 actualFontSize:&actualFontSize forWidth:width lineBreakMode:NSLineBreakByClipping];
                if(actualFontSize != font.pointSize){
                    font = [UIFont fontWithName:font.fontName size:actualFontSize];
                    s = [text sizeWithFont:font
                         constrainedToSize:CGSizeMake(width, height) lineBreakMode:NSLineBreakByClipping];
                }
            }
            
            if(r.size.width == ui::UIAutoValue){
                r.size.width = (int) (s.width + 0.99999f) + padding.left + padding.right;
                float min = element->floatValue("min-width", r.size.width);
                
                if(r.size.width < min){
                    r.size.width = min;
                }

            }
            
            if(r.size.height == ui::UIAutoValue){
                r.size.height = (int) (s.height + 0.99999f) + padding.top + padding.bottom;
                
                float min = element->floatValue("min-height", r.size.height);
                
                if(r.size.height < min){
                    r.size.height = min;
                }
                
                float max = element->floatValue("max-height", r.size.height);
                
                if(r.size.height > max){
                    r.size.height = max;
                }
            }
        }
        else{
            if(r.size.width == ui::UIAutoValue){
                r.size.width = 0;
            }
            
            if(r.size.height == ui::UIAutoValue){
                r.size.height = 0;
            }
        }
        
        element->setFrame(r);
        
    }
    
    return r.size;
}

static void UILabelElementonDraw(ui::UILabelElement * element, CGContextRef context){

    const char * v = element->text();
    
    NSString * text = v ? [NSString stringWithCString:v encoding:NSUTF8StringEncoding] : nil;
    
    if(text){
        
        ui::UIEdge padding = element->padding();
        
        ui::UIFont f = element->font();
        bool fitFontSize = element->fitFontSize();
        
        UIFont * font = nil;
        
        if(* f.name == '\0'){
            
            switch (f.style) {
                case ui::UIFontStyleBold:
                    font = [UIFont boldSystemFontOfSize:f.size];
                    break;
                case ui::UIFontStyleItalic:
                    font = [UIFont italicSystemFontOfSize:f.size];
                    break;
                default:
                    font = [UIFont systemFontOfSize:f.size];
                    break;
            }
            
        }
        else {
            font = [UIFont fontWithName:[NSString stringWithCString:f.name encoding:NSUTF8StringEncoding] size:f.size];
        }
        
        if(font == nil){
            font = [UIFont systemFontOfSize:f.size];
        }
        
        if(fitFontSize && element->actualFontSize){
            font = [UIFont fontWithName:font.fontName size:element->actualFontSize];
        }
        
        ui::UIColor c = element->textColor();
        
        UIColor * color = [UIColor colorWithRed:c.r green:c.g blue:c.b alpha:c.a];
        
        ui::UIAlignment align = element->alignment();
        
        NSTextAlignment alignment = NSTextAlignmentLeft;
        
        if(align == ui::UIAlignmentRight){
            alignment = NSTextAlignmentRight;
        }
        else if(align == ui::UIAlignmentCenter){
            alignment = NSTextAlignmentCenter;
        }
        
        CGContextSetFillColorWithColor(context, [color CGColor]);
        
        CGContextSetStrokeColorWithColor(context, [color CGColor]);
        
        UIGraphicsPushContext(context);
        
        ui::UIRect r = element->frame();
        
        CGSize size = CGSizeMake(r.size.width, r.size.height);
        
        [text drawInRect:CGRectMake(padding.left, padding.top
                                    , size.width - padding.left - padding.right
                                    , size.height - padding.top - padding.bottom)
                withFont:font lineBreakMode:NSLineBreakByCharWrapping alignment:alignment];
        
        UIGraphicsPopContext();
    }
    
}

namespace ui {
    
    IMP_CLASS(UILabelElement, UICanvasElement)
    
    UILabelElement::UILabelElement(){
        
    }
    
    UILabelElement::~UILabelElement(){
        
    }
    
    UIFont UILabelElement::font(){
        float fontSize = floatValue("font-size", 0);
        if(fontSize){
            return UIFont(fontSize);
        }
        return fontValue("font", UIFont());
    }
    
    UIColor UILabelElement::textColor(){
        return colorValue("color", UIColor(0.0,0.0,0.0,1.0));
    }
    
    UIAlignment UILabelElement::alignment(){
        
        const char * v = stringValue("align", "left");
        
        if(strcmp(v, "right") == 0){
            return UIAlignmentRight;
        }
        
        if(strcmp(v, "center") == 0){
            return UIAlignmentCenter;
        }
        
        return UIAlignmentLeft;
    }
    
    bool UILabelElement::fitFontSize(){
        return booleanValue("fit-font-size", false);
    }
    
    UISize UILabelElement::layoutChildren(UIEdge padding){
        return UILabelElementLayoutChildren(this,padding);
    }

    
    void UILabelElement::onDraw(CGContextRef context){
        UICanvasElement::onDraw(context);
        
        UILabelElementonDraw(this,context);
    }
}
