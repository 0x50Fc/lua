//
//  SKPlayerElement.h
//  shank
//
//  Created by zhang hailong on 14-6-26.
//  Copyright (c) 2014年 hailong.org. All rights reserved.
//

#ifndef __shank__SKPlayerElement__
#define __shank__SKPlayerElement__

#include <iostream>

#include "GLRoleElement.h"

namespace sk {
    
    class SKSceneElement;
    
    class SKPlayerElement : public cc::GLRoleElement {
    
    public:
        
        SKPlayerElement();
        
        virtual ~SKPlayerElement();
        
        virtual void tick(cc::GLSchedule * schedule);
        
        virtual cc::Value value(const char * key);
        
        virtual void setValue(const char * key,cc::Value value);

        DEC_CLASS
        
        virtual SKSceneElement * sceneElement();
        
        double moveSpeed;
        
    private:
        
        SKSceneElement * _sceneElement;
    };
    
}

#endif /* defined(__shank__SKPlayerElement__) */
