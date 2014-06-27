//
//  CLDataObject.h
//  cloud
//
//  Created by zhang hailong on 14-6-27.
//  Copyright (c) 2014年 hailong.org. All rights reserved.
//

#ifndef __cloud__CLDataObject__
#define __cloud__CLDataObject__

#include <iostream>

namespace cl {
    
    
    enum CLDataObjectPropertyType {
        
    };
    
    struct CLDataObjectProperty {
        
    };
    
    unsigned char * CLDataObjectWrite(unsigned char * desc,unsigned char * value,size_t length);
    
    unsigned char * CLDataObjectWrite(unsigned char * desc,int value,size_t length);
    
    unsigned char * CLDataObjectWrite(unsigned char * desc,long long value,size_t length);
    
    unsigned char * CLDataObjectWrite(unsigned char * desc,double value,size_t length);

    int CLDataObjectReadInt(unsigned char * src,size_t length);
    
}

#endif /* defined(__cloud__CLDataObject__) */
