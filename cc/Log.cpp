//
//  Log.cpp
//  lua
//
//  Created by zhang hailong on 14-6-20.
//  Copyright (c) 2014年 hailong.org. All rights reserved.
//

#include "Log.h"

#include <time.h>

namespace cc {
    
    void LogV(const char * format,va_list ap){
        
        char buf[32];
        time_t t = time(NULL);
        
        strftime(buf,sizeof(buf),"%Y-%m-%d %H:%M:%S",localtime(& t));
        
        printf("[%s] ",buf);
        
        vprintf(format, ap);
        
        printf("\n");
    }
    
    void Log(const char * format,...){
        
        va_list ap;
        va_start(ap, format);
        
        LogV(format, ap);
        
        va_end(ap);
        
    }
    
}