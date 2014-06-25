//
//  GLRoleElement.h
//  glelement
//
//  Created by zhang hailong on 14-6-24.
//  Copyright (c) 2014年 hailong.org. All rights reserved.
//

#ifndef __glelement__GLRoleElement__
#define __glelement__GLRoleElement__

#include <iostream>
#include <set>

#include "GLElement.h"

namespace cc {
    
    class GLRoleElement : public GLElement {
        
    public:
        
        GLRoleElement();
        
        virtual ~GLRoleElement();
        
        virtual void setStatus(int * status,int count);
        
        virtual void setStatus(int status,...);
        
        virtual void setStatus(int status);
        
        virtual bool hasStatus(int status);
        
        virtual void addStatus(int status);
        
        virtual void removeStatus(int status);
        
        virtual void removeStatus(int status,...);
        
        virtual void clearStatus();
        
        virtual Value invoke(const char * key,InvokeArgs * args);
        
        virtual void addChild(Element * element);
        
        DEC_CLASS
        
    protected:
        
        virtual void onStatusChanged();
        
    private:
        std::set<int> _status;
    };
}


#endif /* defined(__glelement__GLRoleElement__) */
