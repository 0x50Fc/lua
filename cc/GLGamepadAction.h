//
//  GLGamepadAction.h
//  glelement
//
//  Created by zhang hailong on 14-6-24.
//  Copyright (c) 2014年 hailong.org. All rights reserved.
//

#ifndef __glelement__GLGamepadAction__
#define __glelement__GLGamepadAction__

#include <iostream>

#include "Action.h"
#include "GL.h"

namespace cc {
    
    enum GLGamepadActionType {
        GLGamepadActionTypeNone,
        GLGamepadActionTypePosition,
        GLGamepadActionTypeButtonDown,
        GLGamepadActionTypeButtonUp,
        GLGamepadActionTypeButtonUpInset
    };
    
    class GLGamepadAction : public Action {
    
    public:
        
        GLGamepadAction();
        
        GLGamepadAction(Element * element, GLVector2 position);
        
        GLGamepadAction(Element * element,const char * buttonName,GLGamepadActionType actionType);
        
        virtual ~GLGamepadAction();
        
        DEC_CLASS
        
        virtual const char * buttonName();
        
        virtual GLVector2 position();
        
        virtual GLGamepadActionType actionType();
        
        virtual Value value(const char * key);
        
        
    private:
        std::string _buttonName;
        GLVector2 _position;
        GLGamepadActionType _actionType;
    };
    
}

#endif /* defined(__glelement__GLGamepadAction__) */
