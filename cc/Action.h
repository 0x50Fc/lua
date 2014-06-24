//
//  Action.h
//  element
//
//  Created by zhang hailong on 14-6-24.
//  Copyright (c) 2014年 hailong.org. All rights reserved.
//

#ifndef __element__Action__
#define __element__Action__

#include <iostream>

#include "Object.h"

namespace cc {
    
    class Element;
    
    class Action : public Object {
    
    public:
        
        Action();
        
        Action(Element * element);
        
        virtual ~Action();
        
        virtual Value value(const char * key);
        
        virtual Element * element();
        
        DEC_CLASS
        
    private:
        
        Element * _element;
    };
}

#endif /* defined(__element__Action__) */
