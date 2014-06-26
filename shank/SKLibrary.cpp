//
//  SKLibrary.cpp
//  shank
//
//  Created by zhang hailong on 14-6-26.
//  Copyright (c) 2014年 hailong.org. All rights reserved.
//

#include "SKLibrary.h"


namespace sk {
    
    void SKLibraryLoadClass(cc::Context * context){
        
        context->registerClass(& SKSceneElement::clazz);
        context->registerClass(& SKMapLayerElement::clazz);
        context->registerClass(& SKPlayerElement::clazz);
        
    }
}
