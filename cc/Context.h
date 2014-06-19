//
//  Context.h
//  lua
//
//  Created by zhang hailong on 14-6-19.
//  Copyright (c) 2014年 hailong.org. All rights reserved.
//

#ifndef __lua__Context__
#define __lua__Context__

#include <iostream>

struct lua_State;

namespace cc {
    
    
    class Class;
    
    class Context {
    
    public:
        
        Context(void);
        
        virtual ~Context();
        
        virtual int loadString(const char * string);
        
        virtual int loadBuffer(const char * buffer,size_t length);
        
        virtual int loadFile(const char * file);
        
        virtual const char * error();
        
        virtual void registerClass(Class * clazz);
        
    private:
        struct lua_State * _lua;
        std::string _error;
    };
    
}

#endif /* defined(__lua__Context__) */
