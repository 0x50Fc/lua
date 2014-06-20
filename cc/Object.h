//
//  Object.h
//  lua
//
//  Created by zhang hailong on 14-6-19.
//  Copyright (c) 2014年 hailong.org. All rights reserved.
//

#ifndef __lua__Object__
#define __lua__Object__

#include <iostream>

#define DEC_CLASS   public : static cc::Class clazz; public : virtual cc::Class * getClass();

#define IMP_CLASS(obj,superClass)   static cc::Object * obj##_alloc() { return new obj(); }; \
        cc::Class obj::clazz = {&superClass::clazz,#obj,obj##_alloc,sizeof(obj)}; \
        cc::Class * obj::getClass() { return & obj::clazz; };

namespace cc {
    
    class Object;
    
    struct Class {
        Class * const superClass;
        const char * const name;
        Object * (* const alloc)();
        size_t size;
    };
    
    struct InvokeArgs {
        int offset;
        int count;
        void * p;
    };
    
    typedef void (Object:: * Invoke)(const char * key,InvokeArgs * args);
    
    enum ValueType {
        ValueTypeVoid,ValueTypeInt,ValueTypeInt64,ValueTypeDouble,ValueTypeBoolean,ValueTypeString,ValueTypeObject,ValueTypeInvoke
    };
    

    struct Value {
        ValueType type;
        union {
            int intValue;
            long long int64Value;
            double doubleValue;
            bool booleanValue;
            const char * stringValue;
            Object * objectValue;
            Invoke invokeValue;
        };
        Value() {
            type = ValueTypeVoid;
            int64Value = 0;
        };
        Value(int value) {
            type = ValueTypeInt;
            intValue =  value;
        };
        Value(long long value) {
            type = ValueTypeInt64;
            int64Value =  value;
        };
        Value(double value) {
            type = ValueTypeDouble;
            doubleValue =  value;
        };
        Value(bool value) {
            type = ValueTypeBoolean;
            booleanValue =  value;
        };
        Value(const char * value) {
            type = ValueTypeString;
            stringValue =  value;
        };
        Value(Object * value) {
            type = ValueTypeObject;
            objectValue = value;
        };
        Value(Invoke value) {
            type = ValueTypeInvoke;
            invokeValue = value;
        };
    };
    
    int ValueToInt(Value value,int defaultValue);
    
    long long ValueToInt64(Value value,long long defaultValue);
    
    double ValueToDouble(Value value,double defaultValue);
    
    const char * ValueToString(Value value,const char * defaultValue);
    
    Object * ValueToObject(Value value);
    
    bool ValueToBoolean(Value value,bool defaultValue);
    
    
    Value InvokeArgsValue(InvokeArgs * args,int index);
    
    bool ClassIsKindOf(Class * clazz,Class * ofClass);
    
    class Object {
    
    public:
        
        Object();
        
        virtual ~Object();
        
        virtual Value value(const char * key);
        
        virtual void setValue(const char * key,Value value);
        
        virtual void invoke(const char * key,InvokeArgs * args);
        
        bool isKindOfClass(Class * ofClass);
        
        int retainCount();
        
        Object * retain();
        
        void release();
        
        DEC_CLASS

    private:
        int _retainCount;
    };
    
}

#endif /* defined(__lua__Object__) */
