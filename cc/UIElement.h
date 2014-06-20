//
//  UIElement.h
//  uielement
//
//  Created by zhang hailong on 14-6-20.
//  Copyright (c) 2014年 hailong.org. All rights reserved.
//

#ifndef __uielement__UIElement__
#define __uielement__UIElement__

#include <iostream>
#include <map>

#include "Element.h"
#include "UIStyle.h"
#include "UI.h"

namespace ui {
    
    class UIElement: public cc::Element {
      
    public:
        
        UIElement();
        
        virtual ~UIElement();
        
        virtual const char * attr(const char * key);
        
        virtual void setAttr(const char * key,const char * value);
        
        virtual cc::Value value(const char * key);
        
        virtual void setValue(const char * key,cc::Value value);

        virtual UIStyle * style();
        
        virtual void setStyle(UIStyle * style);
        
        virtual int intValue(const char *key,int defaultValue);
        
        virtual float floatValue(const char * key,float defaultValue);
        
        virtual float floatValueOf(const char * key,float baseValue,float defaultValue);
        
        virtual const char * stringValue(const char * key,const char * defaultValue);
        
        virtual UIColor colorValue(const char * key,UIColor defaultValue);
        
        DEC_CLASS
        
    private:
        
        std::map<std::string,std::string> _attrs;
        UIStyle * _style;
    };
}

#endif /* defined(__uielement__UIElement__) */
