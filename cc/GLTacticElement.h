//
//  GLTacticElement.h
//  glelement
//
//  Created by zhang hailong on 14-6-24.
//  Copyright (c) 2014年 hailong.org. All rights reserved.
//

#ifndef __glelement__GLTacticElement__
#define __glelement__GLTacticElement__

#include <iostream>

#include "GLAnimationElement.h"

namespace cc {
    
    class GLTacticElement : public GLAnimationElement {
    
    public :
        
        GLTacticElement();
        
        virtual ~GLTacticElement();
        
        virtual void onElementChanged(Element * element);
        
        DEC_CLASS
        
    };
    
}

#endif /* defined(__glelement__GLTacticElement__) */
