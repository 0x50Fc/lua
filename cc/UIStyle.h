//
//  UIStyle.h
//  uielement
//
//  Created by zhang hailong on 14-6-20.
//  Copyright (c) 2014年 hailong.org. All rights reserved.
//

#ifndef __uielement__UIStyle__
#define __uielement__UIStyle__

#include <iostream>
#include <map>

#include "Object.h"

namespace ui {
    
    class UIStyle : public cc::Object {
        
    public:
        
        UIStyle();
        
        virtual ~UIStyle();
        
        virtual const char * attr(const char * key);
        
        virtual void setAttr(const char * key,const char * value);
        
        virtual cc::Value value(const char * key);
        
        virtual void setValue(const char * key,cc::Value value);
        
        DEC_CLASS
        
    private:
        std::map<std::string,std::string> _attrs;
    };
}

#endif /* defined(__uielement__UIStyle__) */
