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
#include "Log.h"

namespace cc {
    
    static int cc_Object_invoke(lua_State * lua);
    
    int ValueToInt(Value value,int defaultValue){
       
        switch (value.type) {
            case ValueTypeInt:
                return value.intValue;
            case ValueTypeInt64:
                return (int) value.int64Value;
            case ValueTypeDouble:
                return (int) value.doubleValue;
            case ValueTypeBoolean:
                return (int) value.booleanValue;
            case ValueTypeString:
                return atoi(value.stringValue);
            default:
                break;
        }
        
        return defaultValue;
    }
    
    long long ValueToInt64(Value value,long long defaultValue){
        
        switch (value.type) {
                case ValueTypeInt:
                return value.intValue;
                case ValueTypeInt64:
                return value.int64Value;
                case ValueTypeDouble:
                return value.doubleValue;
                case ValueTypeBoolean:
                return value.booleanValue;
                case ValueTypeString:
                return atoll(value.stringValue);
            default:
                break;
        }
        
        return defaultValue;
        
    }
    
    double ValueToDouble(Value value,double defaultValue){
        switch (value.type) {
                case ValueTypeInt:
                return value.intValue;
                case ValueTypeInt64:
                return value.int64Value;
                case ValueTypeDouble:
                return value.doubleValue;
                case ValueTypeBoolean:
                return value.booleanValue;
                case ValueTypeString:
                return atof(value.stringValue);
            default:
                break;
        }
        
        return defaultValue;
    }
    
    const char * ValueToString(Value value,const char * defaultValue){
        switch (value.type) {
            case ValueTypeString:
                return value.stringValue;
            default:
                break;
        }
        
        return defaultValue;
    }
    
    Object * ValueToObject(Value value){
        switch (value.type) {
                case ValueTypeObject:
                return value.objectValue;
            default:
                break;
        }
        
        return NULL;
    }
    
    bool ValueToBoolean(Value value,bool defaultValue){
        switch (value.type) {
                case ValueTypeInt:
                return value.intValue ? true : false;
                case ValueTypeInt64:
                return value.int64Value ? true : false;
                case ValueTypeDouble:
                return value.doubleValue ? true : false;
                case ValueTypeBoolean:
                return value.booleanValue;
                case ValueTypeString:
                return value.stringValue ? false : true;
            default:
                break;
        }
        
        return defaultValue;
    }
    
    Value InvokeArgsValue(InvokeArgs * args,int index){
        
        lua_State * lua = (lua_State *) args->p;
        int i = - args->count + args->offset + index;
        int type = lua_type(lua, i);

        switch (type) {
            case LUA_TBOOLEAN:
                return Value((bool) lua_toboolean(lua,i));
            case LUA_TNUMBER:
                return Value(lua_tonumber(lua,i));
            case LUA_TNIL:
                return Value();
            case LUA_TUSERDATA:
                return Value(* (Object **) lua_touserdata(lua,i));
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
    
    static void cc_Object_pushValue(lua_State * lua,Value v){
        
        switch (v.type) {
            case ValueTypeInt:
                
                lua_pushinteger(lua, v.intValue);
                
                break;
            case ValueTypeInt64:
                
                lua_pushinteger(lua, (lua_Integer) v.int64Value);
                
                break;
            case ValueTypeDouble:
                
                lua_pushnumber(lua, v.doubleValue);
                
                break;
            case ValueTypeString:
                
                lua_pushstring(lua, v.stringValue);
                
                break;
                
            case ValueTypeObject:
                
                if(v.objectValue){
                    
                    Object ** pobject = (Object **) lua_newuserdata(lua, sizeof(Object *));
                    
                    * pobject = v.objectValue->retain();
                    
                    luaL_getmetatable(lua, "ccObject");
                    
                    lua_setmetatable(lua, -2);
                    
                    
                }
                else {
                    lua_pushnil(lua);
                }
                
                break;
                
            case ValueTypeBoolean:
                
                lua_pushboolean(lua, v.booleanValue);
                
                break;
                
            default:
                
                lua_pushnil(lua);
                
                break;
        }
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
                        InvokeArgs args = {0,c - 1,lua};
                        Value v = ((* pobject)->*invoke)(key,& args);
                        
                        cc_Object_pushValue(lua,v);
                        
                        return 1;
                    }

                }
                
            }
            
        }
        
        return 0;
    }
    
    static int cc_Object_function(lua_State * lua){
        
        int c = lua_gettop(lua);
        
        if(c > 0 ){
            
            int type = lua_type(lua, - c);
            
            if(type == LUA_TUSERDATA){
                
                Object ** pobject = (Object **) lua_touserdata(lua, - c);
                
                if(pobject){
                    
                    const char * key = lua_tostring(lua, lua_upvalueindex(1));
                    Object * object = (Object *) lua_touserdata(lua, lua_upvalueindex(2));
                    LUAFunction function = (LUAFunction) lua_touserdata(lua, lua_upvalueindex(3));
                    
                    if(key && object && function){
                        InvokeArgs args = {0,c - 1,lua};
                        return (*function)(lua,object,key,&args);
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
                
                if(v.type == ValueTypeInvoke){
                    
                    lua_pushstring(lua, key);
                    
                    {
                        Invoke * p = (Invoke *) lua_newuserdata(lua, sizeof(Invoke));
                        
                        * p = v.invokeValue;
                        
                    }
                    
                    lua_pushcclosure(lua, cc_Object_invoke, 2);

                }
                else if(v.type == ValueTypeFunction){
                    
                    lua_pushstring(lua, key);
                    
                    lua_pushlightuserdata(lua, * pobject);
                    
                    lua_pushlightuserdata(lua, (void *) v.functionValue);
                
                    lua_pushcclosure(lua, cc_Object_function, 3);
                    
                }
                else {
                    cc_Object_pushValue(lua,v);
                }
                
                return 1;
                
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
                    (* pobject)->setValue(key, Value((bool) lua_toboolean(lua, - c + 2)));
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
            else {
                Log("Not Found Class %s",className);
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
        
        lua_setglobal(_lua, "ccObject");
        
        registerClass( & Object::clazz);
        
        if(_current == NULL){
            _current = this;
        }
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
    
    Class * Context::getClass(const char * className){
        return getClass(_lua,className);
    }
    
    const char * Context::error(){
        return _error.c_str();
    }
    
    Context::~Context(){
        
        if(_current == this){
            _current = NULL;
        }
        
        lua_close(_lua);
    }
    
    Object * Context::globalObject(const char * name){
        
        lua_getglobal(_lua, name);
        
        int type = lua_type(_lua, -1);
        
        if(type == LUA_TUSERDATA){
            
            Object * object = (Object *) lua_touserdata(_lua, -1);
            
            lua_pop(_lua, 1);
            
            return object;
        }
        else if(type == LUA_TTABLE){
            
            lua_pushstring(_lua, "object");
            
            lua_gettable(_lua, -2);
            
            type = lua_type(_lua, -1);
            
            if(type == LUA_TUSERDATA){
                
                Object ** pobject = (Object **) lua_touserdata(_lua, -1);
                
                if(pobject){
                
                    lua_pop(_lua, 1);
                    
                    return * pobject;
                }

            }
            
        }
        
        return NULL;
    }
    
    void Context::globalObjectInvoke(const char * name,const char * invoke,Value * values,int count){
        
        lua_getglobal(_lua, name);
        
        int type = lua_type(_lua, -1);
        
        if(type == LUA_TTABLE){
            
            lua_getfield(_lua, -1, invoke);
            
            type = lua_type(_lua, -1);
            
            lua_pushvalue(_lua, -2);
            
            for(int i=0; i < count; i++){
                Value * v = values + i;
                
                switch (v->type) {
                    case ValueTypeInt:
                        
                        lua_pushinteger(_lua, v->intValue);
                        
                        break;
                        
                    case ValueTypeInt64:
                        
                        lua_pushinteger(_lua, (lua_Integer) v->int64Value);
                        
                        break;
                        
                    case ValueTypeDouble:
                        
                        lua_pushnumber(_lua, v->doubleValue);
                        
                        break;
                        
                    case ValueTypeString:
                        
                        if(v->stringValue){
                            lua_pushstring(_lua, v->stringValue);
                        }
                        else {
                            lua_pushnil(_lua);
                        }
                        
                        break;
                        
                    case ValueTypeObject:
                        
                        if(v->objectValue){
                            
                            Object ** pobject = (Object **) lua_newuserdata(_lua, sizeof(Object *));
                            
                            * pobject = v->objectValue->retain();
                            
                            luaL_getmetatable(_lua, "ccObject");
                            
                            lua_setmetatable(_lua, -2);

                        }
                        else{
                            lua_pushnil(_lua);
                        }
                        
                        break;
                        
                    case ValueTypeBoolean:
                        
                        lua_pushboolean(_lua, v->booleanValue);
                        
                        break;
                        
                    default:
                        
                        lua_pushnil(_lua);
                        
                        break;
                }
            }
            
            lua_pcall(_lua, count + 1, 0, 0);
            
        }
    }
    
    void Context::globalInvoke(const char * invoke,Value * values,int count){
        
        lua_getglobal(_lua, invoke);
    
        int type = lua_type(_lua, -1);
        
        if(type == LUA_TFUNCTION){

            
            for(int i=0; i < count; i++){
                Value * v = values + i;
                
                switch (v->type) {
                        case ValueTypeInt:
                        
                        lua_pushinteger(_lua, v->intValue);
                        
                        break;
                        
                        case ValueTypeInt64:
                        
                        lua_pushinteger(_lua, (lua_Integer) v->int64Value);
                        
                        break;
                        
                        case ValueTypeDouble:
                        
                        lua_pushnumber(_lua, v->doubleValue);
                        
                        break;
                        
                        case ValueTypeString:
                        
                        if(v->stringValue){
                            lua_pushstring(_lua, v->stringValue);
                        }
                        else {
                            lua_pushnil(_lua);
                        }
                        
                        break;
                        
                        case ValueTypeObject:
                        
                        if(v->objectValue){
                            
                            Object ** pobject = (Object **) lua_newuserdata(_lua, sizeof(Object *));
                            
                            * pobject = v->objectValue->retain();
                            
                            luaL_getmetatable(_lua, "ccObject");
                            
                            lua_setmetatable(_lua, -2);
                            
                        }
                        else{
                            lua_pushnil(_lua);
                        }
                        
                        break;
                        
                        case ValueTypeBoolean:
                        
                        lua_pushboolean(_lua, v->booleanValue);
                        
                        break;
                        
                    default:
                        
                        lua_pushnil(_lua);
                        
                        break;
                }
            }
            
            lua_pcall(_lua, count, 0, 0);
        }
    }
    
    void Context::gc(){
        lua_gc(_lua, LUA_GCCOLLECT, 0);
    }
    
    Context * Context::_current = NULL;
    
    Context * Context::current(){
        return _current;
    }
    
    void Context::setCurrent(Context * context){
        _current = context;
    }
    
    Class * Context::getClass(lua_State * lua,const char * className){
        
        Class * clazz = NULL;
        
        lua_getglobal(lua, "cc");
        
        lua_getfield(lua, -1, className);
        
        int type = lua_type(lua, -1);
        
        if(type == LUA_TUSERDATA){
            clazz = (Class *) lua_touserdata(lua, -1);
        }
        
        lua_pop(lua, 1);
        
        return clazz;
    }
    
    void Context::newObject(lua_State * lua,Object * object){
        
        Object ** pobject = (Object **) lua_newuserdata(lua, sizeof(Object *));
        
        * pobject = object->retain();
        
        luaL_getmetatable(lua, "ccObject");
        
        lua_setmetatable(lua, -2);
        
    }
}

