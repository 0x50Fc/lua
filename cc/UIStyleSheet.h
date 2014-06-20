//
//  UIStyleSheet.h
//  uielement
//
//  Created by zhang hailong on 14-6-20.
//  Copyright (c) 2014年 hailong.org. All rights reserved.
//

#ifndef __uielement__UIStyleSheet__
#define __uielement__UIStyleSheet__

#include <iostream>
#include <map>

#include "Object.h"
#include "UIStyle.h"

namespace ui {
    
    class UIStyleSheet : public cc::Object {
        
    public:
        
        UIStyleSheet();
        
        virtual ~UIStyleSheet();
        
        // "color: #000000; font-size: 14;"
        
        virtual void setStyle(const char * name,const char * style);
        
        virtual void setCSS(const char * css);
        
        virtual void clear();
        
        virtual void selector(const char * styleName,UIStyle * style);
        
        virtual void invoke(const char * key,cc::InvokeArgs * args);
        
        DEC_CLASS
        
    private:
        std::map<std::string,std::map<std::string,std::string>> _styles;
    };
}

#endif /* defined(__uielement__UIStyleSheet__) */
