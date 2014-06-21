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
        
        virtual const char * text();
        
        virtual void setText(const char * text);
        
        virtual const char * name();
        
        virtual void setName(const char * name);
        
        virtual const char * attr(const char * key);
        
        virtual void setAttr(const char * key,const char * value);
        
        virtual cc::Value value(const char * key);
        
        virtual void setValue(const char * key,cc::Value value);

        virtual UIStyle * style();
        
        virtual void setStyle(UIStyle * style);
        
        virtual bool booleanValue(const char * key,bool defaultValue);
        
        virtual int intValue(const char *key,int defaultValue);
        
        virtual float floatValue(const char * key,float defaultValue);
        
        virtual float floatValueOf(const char * key,float baseValue,float defaultValue);
        
        virtual const char * stringValue(const char * key,const char * defaultValue);
        
        virtual UIColor colorValue(const char * key,UIColor defaultValue);
        
        virtual UIFont fontValue(const char * key,UIFont defaultValue);
        
        
        DEC_CLASS
        
    private:
        std::string _name;
        std::string _text;
        std::map<std::string,std::string> _attrs;
        UIStyle * _style;
    };
}

#endif /* defined(__uielement__UIElement__) */
