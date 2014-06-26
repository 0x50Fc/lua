//
//  SKMapLayerElement.cpp
//  shank
//
//  Created by zhang hailong on 14-6-26.
//  Copyright (c) 2014年 hailong.org. All rights reserved.
//

#include "SKMapLayerElement.h"

#include "SKSceneElement.h"

namespace sk {
    
    IMP_CLASS(SKMapLayerElement,cc::GLLayerElement)
    
    SKMapLayerElement::SKMapLayerElement():_sceneElement(NULL){
        
    }
    
    SKMapLayerElement::~SKMapLayerElement(){
        
    }
    
    void SKMapLayerElement::tick(cc::GLSchedule * schedule){
        cc::GLLayerElement::tick(schedule);
        
        SKSceneElement * scene = sceneElement();
        
        if(scene){
            
            frame.origin = scene->mapOffset;
            frame.size = scene->mapSize;
            
        }
        
    }
    
    SKSceneElement * SKMapLayerElement::sceneElement(){
        
        if(_sceneElement == NULL){
            _sceneElement = (SKSceneElement *) parentOfClass(& SKSceneElement::clazz);
        }
        
        return _sceneElement;
    }

    
}