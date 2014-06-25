//
//  Element.h
//  element
//
//  Created by zhang hailong on 14-6-19.
//  Copyright (c) 2014年 hailong.org. All rights reserved.
//

#ifndef __element__Element__
#define __element__Element__

#include <iostream>
#include <vector>

#include "Object.h"
#include "Action.h"

namespace cc {
    
    class Element : public Object {
    
    public:
        
        Element();
        
        virtual ~Element();
        
        virtual Element * parent();
        
        virtual Element * childAt(int index);
        
        virtual int childCount();
        
        virtual void addChild(Element * element);
        
        virtual void insertChild(Element * element,int index);
        
        virtual void removeChildAt(int index);
        
        virtual void removeChild(Element * element);
        
        virtual void removeFromParent();
        
        virtual Element * parentOfClass(Class * elementClass);
        
        virtual void elementsOfClass(std::vector<Element *> & elements,Class * elementClass,int level);
        
        virtual void elementsOfClass(std::vector<Element *> & elements,Class * elementClass);
        
        virtual Value value(const char * key);
        
        virtual void setValue(const char * key,Value value);

        virtual Value invoke(const char * key,InvokeArgs * args);

        virtual const char * name();
        
        virtual void setName(const char * value);
        
        virtual void doAction(Action * action);
        
        DEC_CLASS
        
    private:
        
        Element * _parent;
        std::vector<Element *> _childs;
        std::string _name;
        
    };
    
    
}

#endif /* defined(__element__Element__) */
