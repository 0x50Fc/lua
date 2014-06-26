//
//  SKSceneElement.h
//  shank
//
//  Created by zhang hailong on 14-6-26.
//  Copyright (c) 2014年 hailong.org. All rights reserved.
//

#ifndef __shank__SKSceneElement__
#define __shank__SKSceneElement__

#include <iostream>

#include "GLSceneElement.h"

namespace sk {
    
    class SKPlayerElement;
    
    class SKSceneElement : public cc::GLSceneElement {
    
    public:
        
        SKSceneElement();
        
        virtual ~SKSceneElement();
        
        virtual cc::Value value(const char * key);
        
        virtual void setValue(const char * key,cc::Value value);
        
        virtual cc::Value invoke(const char * key,cc::InvokeArgs * args);
        
        virtual void addChild(Element * element);
        
        virtual void doAction(cc::Action * action);
        
        virtual void tick(cc::GLSchedule * schedule);
        
        virtual SKPlayerElement * playerElement();
        
        virtual cc::GLVector3 screenPosition(cc::GLVector3 mapPosition);
        
        virtual cc::GLVector3 playScreenPosition();
        
        DEC_CLASS
        
        cc::GLVector2 mapSize;
        cc::GLVector2 mapOffset;
        cc::GLVector2 moveOffset;
        cc::GLVector3 playMapPosition;
        
    private:

        double _tickTimestamp;
        
    };
}

#endif /* defined(__shank__SKSceneElement__) */
