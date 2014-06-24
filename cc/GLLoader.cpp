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
    
    GLLoader::GLLoader(const char * res,const char * doc,const char * tmp)
        : _res(res),_doc(doc),_tmp(tmp){
        
    }
    
    GLLoader::~GLLoader(){
        
    }
    
    GLImage * GLLoader::createImageForURI(const char * uri){
        
        std::string path = getFilePath(uri);
        
        return GLLoaderImageCreateFromFilePath(path.c_str());
        
    }
    
    std::string GLLoader::getFilePath(const char * uri){
        
        if(uri[0] == 'r' && uri[1] == 'e' && uri[2] == 's'
           && uri[3] == ':' && uri[4] == '/' && uri[5] == '/'){
            return _res + (uri + 6);
        }
        
        if(uri[0] == 'd' && uri[1] == 'o' && uri[2] == 'c'
           && uri[3] == ':' && uri[4] == '/' && uri[5] == '/'){
            return _doc + (uri + 6);
        }
        
        if(uri[0] == 't' && uri[1] == 'm' && uri[2] == 'p'
           && uri[3] == ':' && uri[4] == '/' && uri[5] == '/'){
            return _doc + (uri + 6);
        }
        
        if(uri[0] == '/'){
            return std::string(uri);
        }
        
        return _res + '/' + uri;
    }
    
}
