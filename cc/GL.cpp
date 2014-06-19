//
//  GL.cpp
//  glelement
//
//  Created by zhang hailong on 14-6-19.
//  Copyright (c) 2014年 hailong.org. All rights reserved.
//

#include "GL.h"

namespace cc {
    
    const GLMatrix4 GLMatrix4Identity = {
        1.0,0.0,0.0,0.0,
        0.0,1.0,0.0,0.0,
        0.0,0.0,1.0,0.0,
        0.0,0.0,0.0,1.0,
    };
    
    const GLMatrix3 GLMatrix3Identity = {
        1.0,0.0,0.0,
        0.0,1.0,0.0,
        0.0,0.0,1.0,
    };

}