//
//  GLLoader.cpp
//  glelement
//
//  Created by zhang hailong on 14-6-24.
//  Copyright (c) 2014年 hailong.org. All rights reserved.
//

#include "GLLoader.h"

#include "Log.h"

namespace cc {
    
    IMP_CLASS(GLLoader, Object)
    
    GLLoader::GLLoader(){
        
    }
    
    GLLoader::GLLoader(const char * res,const char * doc,const char * tmp)
        : _res(res),_doc(doc),_tmp(tmp){
        
    }
    
    GLLoader::~GLLoader(){
        
        std::map<std::string,GLImage *>::iterator i = _images.begin();
        
        while (i != _images.end()) {
            
            i->second->release();
            
            i ++;
        }
        
    }
    
    GLImage * GLLoader::getImageForURI(const char * uri){
        
        std::string key(uri);
        std::map<std::string,GLImage *>::iterator i = _images.find(key);
        
        if(i == _images.end()){
            
            std::string path = getFilePath(uri);
            
            GLImage * image = GLLoaderImageCreateFromFilePath(path.c_str());
            
            if(image){
                _images[key] = image;
            }
            else {
                Log("Not Found Image %s",uri);
            }
            
            return image;
        }
        else {
            return i->second;
        }
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

    void GLLoader::clearImages(){
        
        std::map<std::string,GLImage *>::iterator i = _images.begin();
        
        while (i != _images.end()) {
            
            i->second->release();
            
            i ++;
        }
        
        _images.clear();
        
    }
    
    void GLLoader::clearImageForURI(const char * uri){
        std::map<std::string,GLImage *>::iterator i = _images.find(uri);
        if(i != _images.end()){
            i->second->release();
            _images.erase(i);
        }
    }
    
}
