//
//  GLLoader.cpp
//  glelement
//
//  Created by zhang hailong on 14-6-24.
//  Copyright (c) 2014年 hailong.org. All rights reserved.
//

#include "GLLoader.h"

namespace cc {
    
    IMP_CLASS(GLLoader, Object)
    
    GLLoader::GLLoader(){
        
    }
    
    GLLoader::GLLoader(const char * resBasePath,const char * docBasePath,const char * tmpBasePath){
        
    }
    
    GLLoader::~GLLoader(){
        
    }
    
    GLImage * GLLoader::createImageForURI(const char * uri){
        
        
    }
    
    
    std::string GLLoader::getFilePath(const char * uri){
        
        std::string s(uri);
        
        std::string::size_type pos = s.find("res://");
        
        if(pos ==0){
            s.replace(pos, 6, _resBasePath);
            return s;
        }

        pos = s.find("doc://");
        
        if(pos ==0){
            s.replace(pos, 6, _docBasePath);
            return s;
        }
        
        pos = s.find("tmp://");
        
        if(pos ==0){
            s.replace(pos, 6, _tmpBasePath);
            return s;
        }
    
       
        return s;
    }
    
}
