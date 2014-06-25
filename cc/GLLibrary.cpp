//
//  GLLibrary.cpp
//  glelement
//
//  Created by zhang hailong on 14-6-24.
//  Copyright (c) 2014年 hailong.org. All rights reserved.
//

#include "GLLibrary.h"

namespace cc {
    
    void GLLibraryLoadClass(Context * context){
        
        context->registerClass(& cc::GLLayerElement::clazz);
        context->registerClass(& cc::GLScreenElement::clazz);
        context->registerClass(& cc::GLGamepadElement::clazz);
        context->registerClass(& cc::GLGamepadButtonElement::clazz);
        context->registerClass(& cc::GLControlElement::clazz);
        context->registerClass(& cc::GLCanvasElement::clazz);
        context->registerClass(& cc::GLElement::clazz);
        context->registerClass(& GLSceneElement::clazz);
        context->registerClass(& GLRoleElement::clazz);
        context->registerClass(& cc::Element::clazz);
        context->registerClass(& GLSpriteElement::clazz);
        context->registerClass(& GLTacticElement::clazz);
        context->registerClass(& GLTacticFramesElement::clazz);
    }
    
}
