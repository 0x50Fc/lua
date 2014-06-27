//
//  CL.h
//  cloud
//
//  Created by zhang hailong on 14-6-27.
//  Copyright (c) 2014年 hailong.org. All rights reserved.
//

#ifndef __cloud__CL__
#define __cloud__CL__

#include <iostream>

namespace cl {
    
#define CL_VERSION  0x0001
    
#define CL_IDENTIFIER_SIZE 64
    
    struct Identifier {
        char s[CL_IDENTIFIER_SIZE];
    };
    
};

#endif /* defined(__cloud__CL__) */
