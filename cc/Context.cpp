//
//  Context.cpp
//  lua
//
//  Created by zhang hailong on 14-6-19.
//  Copyright (c) 2014年 hailong.org. All rights reserved.
//

#include "lua.hpp"
#include "Context.h"
#include "Object.h"

namespace cc {
    
    
    Value InvokeArgsValue(InvokeArgs * args,int index){
        
        lua_State * lua = (lua_State *) args->p;
        int i = - args->count + args->offset + index;
        int type = lua_type(lua, i);

        switch (type) {
            case LUA_TBOOLEAN:
                return Value(lua_toboolean(lua,i));
            case LUA_TNUMBER:
                return Value(lua_tonumber(lua,i));
            case LUA_TNIL:
                return Value();
            case LUA_TUSERDATA:
                return Value((Object *) lua_touserdata(lua,i));
            default:
                const char * v = lua_tostring(lua,i);
                if(v){
                    return Value(v);
                }
                return Value();
        }
        
    }
    
    static int cc_Object_gc(lua_State * lua){
    
        int c = lua_gettop(lua);
        int type = lua_type(lua, - c);
        
        if(type == LUA_TUSERDATA){
            
            Object ** pobject = (Object **) lua_touserdata(lua, - c);
            
            if(pobject){
                (* pobject)->release();
            }
        }
        
        return 0;
    }
    
    static int cc_Object_invoke(lua_State * lua){
        
        int c = lua_gettop(lua);
        
        
        if(c > 0 ){
            
            int type = lua_type(lua, - c);
            
            if(type == LUA_TUSERDATA){
                
                Object ** pobject = (Object **) lua_touserdata(lua, - c);
                
                if(pobject){
                    
                    const char * key = lua_tostring(lua, lua_upvalueindex(1));
                    Invoke * fun = (Invoke *) lua_touserdata(lua, lua_upvalueindex(2));
                    
                    if(key && fun){
                        Invoke invoke = * fun;
                        InvokeArgs args = {2,c - 1,lua};
                        ((* pobject)->*invoke)(key,& args);
                    }

                }
                
            }
            
        }
        
        return 0;
    }
    
    static int cc_Object_value(lua_State * lua){
        
        int c = lua_gettop(lua);
        int type = lua_type(lua, - c);
        
        if(type == LUA_TUSERDATA){
        
            Object ** pobject = (Object **) lua_touserdata(lua, - c);
            const char * key = lua_tostring(lua, - c + 1);
            
            if(pobject && key){
                
                Value v = (* pobject)->value(key);
                
                switch (v.type) {
                    case ValueTypeInt:
                        
                        lua_pushinteger(lua, v.intValue);
                        
                        return 1;
                    case ValueTypeInt64:
                        
                        lua_pushinteger(lua, v.int64Value);
                        
                        return 1;
                    case ValueTypeDouble:
                        
                        lua_pushnumber(lua, v.doubleValue);
                        
                        return 1;
                    case ValueTypeString:
                        
                        lua_pushstring(lua, v.stringValue);
                        
                        return 1;
                        
                    case ValueTypeObject:
                        
                        if(v.objectValue){
                            
                            Object ** pobject = (Object **) lua_newuserdata(lua, sizeof(Object *));
                            
                            * pobject = v.objectValue->retain();
                            
                            luaL_getmetatable(lua, "ccObject");
                            
                            lua_setmetatable(lua, -2);
                            
                            return 1;
                        }
                        
                        return 0;
                        
                    case ValueTypeInvoke:
                        
                        lua_pushstring(lua, key);
                        
                    {
                        Invoke * p = (Invoke *) lua_newuserdata(lua, sizeof(Invoke));
                        
                        * p = v.invokeValue;
                        
                    }
                        lua_pushcclosure(lua, cc_Object_invoke, 2);
                        
                        return 1;
                    default:
                        
                        lua_pushnil(lua);
                        
                        return 1;
                }
            }
            
        }
        
        return 0;
    }
    
    static int cc_Object_setValue(lua_State * lua){
        
        int c = lua_gettop(lua);
        Object ** pobject = (Object **) lua_touserdata(lua, - c);
        const char * key = lua_tostring(lua, - c + 1);
        int type = lua_type(lua, - c + 2);
        
        if(pobject && key){
            
            switch (type) {
                case LUA_TBOOLEAN:
                    (* pobject)->setValue(key, Value(lua_toboolean(lua, - c + 2)));
                    break;
                case LUA_TNUMBER:
                    (* pobject)->setValue(key, Value(lua_tonumber(lua, - c + 2)));
                    break;
                case LUA_TNIL:
                    (* pobject)->setValue(key, Value());
                    break;
                case LUA_TUSERDATA:
                    (* pobject)->setValue(key, Value((Object *)lua_touserdata(lua, - c + 2)));
                    break;
                default:
                    (* pobject)->setValue(key, Value(lua_tostring(lua, - c + 2)));
                    break;
            }
            
        }
        
        return 0;
    }
    
    static int cc_new(lua_State * lua){
        
        const char * className = lua_tostring(lua, 1);
        
        if(className){
            
            lua_getglobal(lua, "cc");
            
            lua_getfield(lua, -1, className);
            
            Class * clazz = (Class *) lua_touserdata(lua, -1);
            
            if(clazz){
                
                lua_pop(lua, 1);
            
                Object * obj = (* clazz->alloc)();
                
                if(obj){
                    
                    Object ** pobject = (Object **) lua_newuserdata(lua, sizeof(Object *));
                    
                    * pobject = obj;

                    luaL_getmetatable(lua, "ccObject");
                    
                    lua_setmetatable(lua, -2);
                    
                    return 1;
                    
                }
                
            }
            
        }
        
        return 0;
    }
                      
    Context::Context(void){
        
        _lua = luaL_newstate();
        
        static const struct luaL_Reg cc[] = {
            {"new", cc_new},
            {NULL, NULL}
        };
        
        luaL_openlibs(_lua);
        
        luaL_openlib(_lua,"cc",cc,0);
        
        luaL_newmetatable(_lua, "ccObject");
        
        lua_pushcfunction(_lua, cc_Object_gc);
        
        lua_setfield(_lua, -2,"__gc");
        
        lua_pushcfunction(_lua, cc_Object_value);
        
        lua_setfield(_lua, -2,"__index");
        
        lua_pushcfunction(_lua, cc_Object_setValue);
        
        lua_setfield(_lua, -2,"__newindex");
        
        registerClass( & Object::clazz);
        
    }
    
    int Context::loadString(const char * string){
        int rs = luaL_loadstring(_lua,string) || lua_pcall(_lua, 0, 0, 0);
        
        if(rs){
         
            _error = lua_tostring(_lua,-1);
            
            lua_pop(_lua, 1);
        }
        
        return rs;
    }
    
    int Context::loadBuffer(const char * buffer,size_t length){
        
        int rs = luaL_loadbuffer(_lua,buffer,length,NULL) || lua_pcall(_lua, 0, 0, 0);
        
        if(rs){
            
            _error = lua_tostring(_lua,-1);
            
            lua_pop(_lua, 1);
        }

        return rs;
    }
    
    int Context::loadFile(const char * file){
        
        int rs = luaL_loadfile(_lua, file) || lua_pcall(_lua, 0, 0, 0);
        
        if(rs){
            
            _error = lua_tostring(_lua,-1);
            
            lua_pop(_lua, 1);
        }
        
        return rs;
    }
    
    void Context::registerClass(Class * clazz){
        
        lua_getglobal(_lua, "cc");
        
        lua_pushstring(_lua, clazz->name);
        
        lua_pushlightuserdata(_lua, clazz);
        
        lua_settable(_lua, -3);
    
    }
    
    const char * Context::error(){
        return _error.c_str();
    }
    
    Context::~Context(){
        lua_close(_lua);
    }
    
}

