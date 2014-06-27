//
//  Assert.cpp
//  lua
//
//  Created by zhang hailong on 14-6-27.
//  Copyright (c) 2014年 hailong.org. All rights reserved.
//

#include "Assert.h"

#include <assert.h>

namespace cc {
    
    void Assert(bool v){
        assert(v);
    }
    
    void Assert(void * v){
        Assert(v ? true : false);
    }
    
    void Assert(int v){
        Assert(v ? true : false);
    }
    
    void Assert(double v){
        Assert(v ? true : false);
    }
}
