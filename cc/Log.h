//
//  Log.h
//  lua
//
//  Created by zhang hailong on 14-6-20.
//  Copyright (c) 2014年 hailong.org. All rights reserved.
//

#ifndef __lua__Log__
#define __lua__Log__

#include <iostream>

namespace cc {
    
    
    void LogV(const char * format,va_list ap);
    
    void Log(const char * format,...);
    
}

#endif /* defined(__lua__Log__) */
