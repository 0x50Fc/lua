//
//  GLLoader.h
//  glelement
//
//  Created by zhang hailong on 14-6-24.
//  Copyright (c) 2014年 hailong.org. All rights reserved.
//

#ifndef __glelement__GLLoader__
#define __glelement__GLLoader__

#include <iostream>

#include "GLImage.h"

namespace cc {
    
    extern GLImage * GLLoaderImageCreateFromFilePath(const char * filePath);

    class GLLoader : public Object {
        
    public:
        
        GLLoader();
        
        GLLoader(const char * res,const char * doc,const char * tmp);
        
        virtual ~GLLoader();
        
        GLImage * createImageForURI(const char * uri);
        
        std::string getFilePath(const char * uri);
        
        DEC_CLASS
        
    private:
        std::string _res;
        std::string _doc;
        std::string _tmp;
    };
}

#endif /* defined(__glelement__GLLoader__) */
