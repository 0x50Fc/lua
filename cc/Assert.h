//
//  Assert.h
//  lua
//
//  Created by zhang hailong on 14-6-27.
//  Copyright (c) 2014年 hailong.org. All rights reserved.
//

#ifndef __lua__Assert__
#define __lua__Assert__

#include <iostream>

namespace cc {
    
    void Assert(bool v);
    
    void Assert(void * v);
    
    void Assert(int v);
    
    void Assert(double v);
    
}
#endif /* defined(__lua__Assert__) */
