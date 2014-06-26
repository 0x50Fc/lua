//
//  SKSceneElement.cpp
//  shank
//
//  Created by zhang hailong on 14-6-26.
//  Copyright (c) 2014年 hailong.org. All rights reserved.
//

#include "SKSceneElement.h"

#include "GLGamepadAction.h"

#include "SKPlayerElement.h"

#include "SKMapLayerElement.h"

#include "Log.h"

namespace sk {
    
    IMP_CLASS(SKSceneElement, cc::GLSceneElement)
    
    
    SKSceneElement::SKSceneElement()
        :mapOffset({0.0,0.0}),mapSize({0.0,0.0}),playMapPosition({0,0,0})
        ,moveOffset({0.0,0.0}),_tickTimestamp(0){
        
    }
    
    SKSceneElement::~SKSceneElement(){
        
    }
    
    SKPlayerElement * SKSceneElement::playerElement(){
        return (SKPlayerElement *) elementOfClass(& SKPlayerElement::clazz);
    }
    
    void SKSceneElement::tick(cc::GLSchedule * schedule){
        cc::GLSceneElement::tick(schedule);
        
        if(_tickTimestamp == 0){
            _tickTimestamp = schedule->timestamp();
        }
        
        if(moveOffset.x || moveOffset.y){
            
            SKPlayerElement * player = playerElement();
            
            if(player){
                
                GLfloat speed = player->moveSpeed * (schedule->timestamp() - _tickTimestamp);
                
                GLfloat v = moveOffset.x;
                
                if(v < -1){
                    v = -1;
                }
                
                if(v > 1){
                    v = 1;
                }
                
                playMapPosition.x += v * speed;
                
                v = moveOffset.y;
                
                if(v < -1){
                    v = -1;
                }
                
                if(v > 1){
                    v = 1;
                }
                
                playMapPosition.y += v * speed;

                GLfloat width = schedule->width();
                GLfloat minWidth = width * 0.25;
                
                if(playMapPosition.x < - mapOffset.x + minWidth){
                    mapOffset.x =  minWidth - playMapPosition.x;
                    if(mapOffset.x > 0){
                        mapOffset.x = 0;
                    }
                }
                
                if(playMapPosition.x > - mapOffset.x + width - minWidth){
                    mapOffset.x = width - minWidth - playMapPosition.x;
                    if(mapOffset.x < width - mapSize.width){
                        mapOffset.x = width - mapSize.width;
                    }
                }
                
            }
            
        }

        
        _tickTimestamp = schedule->timestamp();
    }
    
    cc::Value SKSceneElement::value(const char * key){
        if(strcmp(key,"mapWidth") == 0){
            return cc::Value(mapSize.width);
        }
        else if(strcmp(key,"mapHeight") == 0){
            return cc::Value(mapSize.height);
        }
        else if(strcmp(key,"mapOffsetX") == 0){
            return cc::Value(mapOffset.x);
        }
        else if(strcmp(key,"mapOffsetY") == 0){
            return cc::Value(mapOffset.y);
        }
        else {
            return cc::GLSceneElement::value(key);
        }
    }
    
    void SKSceneElement::setValue(const char * key,cc::Value value){
        if(strcmp(key,"mapWidth") == 0){
            mapSize.width = cc::ValueToDouble(value, 0);
        }
        else if(strcmp(key,"mapHeight") == 0){
            mapSize.height = cc::ValueToDouble(value, 0);
        }
        else if(strcmp(key,"mapOffsetX") == 0){
            mapOffset.x = cc::ValueToDouble(value, 0);
        }
        else if(strcmp(key,"mapOffsetY") == 0){
            mapOffset.y = cc::ValueToDouble(value, 0);
        }
        else {
            cc::GLSceneElement::setValue(key,value);
        }
    }
    
    cc::Value SKSceneElement::invoke(const char * key,cc::InvokeArgs * args){
        
        if(strcmp(key, "setMapSize") == 0){
            mapSize.width = cc::ValueToDouble(cc::InvokeArgsValue(args, 0), 0);
            mapSize.height = cc::ValueToDouble(cc::InvokeArgsValue(args, 1), 0);
            return cc::Value();
        }
        else if(strcmp(key, "setMapOffset") == 0){
            mapOffset.x = cc::ValueToDouble(cc::InvokeArgsValue(args, 0), 0);
            mapOffset.y = cc::ValueToDouble(cc::InvokeArgsValue(args, 1), 0);
            return cc::Value();
        }
        else if(strcmp(key, "setPlayMapPosition") == 0){
            playMapPosition.x = cc::ValueToDouble(cc::InvokeArgsValue(args, 0), 0);
            playMapPosition.y = cc::ValueToDouble(cc::InvokeArgsValue(args, 1), 0);
            playMapPosition.z = cc::ValueToDouble(cc::InvokeArgsValue(args, 2), 0);
            return cc::Value();
        }
        else {
            return cc::GLSceneElement::invoke(key, args);
        }
    }
    
    void SKSceneElement::addChild(Element * element){
        
        element->onElementChanged(this);
        
        cc::GLSceneElement::addChild(element);
    }
    
    void SKSceneElement::doAction(cc::Action * action){
        
        if(action->isKindOfClass(& cc::GLGamepadAction::clazz)){
            
            cc::GLGamepadAction * gamepad = (cc::GLGamepadAction *) action;
            
            if(gamepad->actionType() == cc::GLGamepadActionTypePosition){
            
                moveOffset = gamepad->position();

            }
            
        }
        
        GLSceneElement::doAction(action);
    }
    
    cc::GLVector3 SKSceneElement::screenPosition(cc::GLVector3 mapPosition){
        
        cc::GLVector3 v3 = {
            mapPosition.x + mapOffset.x,mapPosition.y + mapOffset.y,mapPosition.z
        };
        
        return v3;
    }
    
    cc::GLVector3 SKSceneElement::playScreenPosition(){
        return screenPosition(playMapPosition);
    }
}
