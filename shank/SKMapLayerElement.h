//
//  SKMapLayerElement.h
//  shank
//
//  Created by zhang hailong on 14-6-26.
//  Copyright (c) 2014年 hailong.org. All rights reserved.
//

#ifndef __shank__SKMapLayerElement__
#define __shank__SKMapLayerElement__

#include <iostream>

#include "GLLayerElement.h"

namespace sk {
    
    class SKSceneElement;
    
    class SKMapLayerElement : public cc::GLLayerElement {
    
    public:
        
        SKMapLayerElement();
        
        virtual ~SKMapLayerElement();
        
        virtual void tick(cc::GLSchedule * schedule);
        
        virtual SKSceneElement * sceneElement();
        
        DEC_CLASS
        
    private:
        
        SKSceneElement * _sceneElement;
    };
}

#endif /* defined(__shank__SKMapLayerElement__) */
