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

#include "Object.h"

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
        
        virtual Class * getClass(const char * className);
        
        virtual Object * globalObject(const char * name);
        
        virtual void globalObjectInvoke(const char * name,const char * invoke,Value * values,int count);
        
        virtual void globalInvoke(const char * invoke,Value * values,int count);
        
        virtual void gc();
        
        static Context * current();
        
        static void setCurrent(Context * context);
        
        static Class * getClass(lua_State * lua,const char * className);
        
        static void newObject(lua_State * lua,Object * object);
        
    private:
        
        struct lua_State * _lua;
        
        std::string _error;
        
        static Context * _current;
        
    };
    
}

#endif /* defined(__lua__Context__) */
