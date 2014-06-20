//
//  UIStyle.cpp
//  uielement
//
//  Created by zhang hailong on 14-6-20.
//  Copyright (c) 2014年 hailong.org. All rights reserved.
//

#include "UIStyle.h"

namespace ui {
    
    IMP_CLASS(UIStyle, cc::Object)
    
    UIStyle::UIStyle(){
        
    }
    
    UIStyle::~UIStyle(){
        
    }
    
    const char * UIStyle::attr(const char * key){
        std::map<std::string,std::string>::iterator i = _attrs.find(key);
        return i != _attrs.end() ? i->second.c_str() : NULL;
    }
    
    void UIStyle::setAttr(const char * key,const char * value){
        if(value){
            _attrs[key] = value;
        }
        else {
            std::map<std::string,std::string>::iterator i = _attrs.find(key);
            if(i != _attrs.end()){
                _attrs.erase(i);
            }
        }
    }
    
    cc::Value UIStyle::value(const char * key){
        if(key[0] == 'a' && key[1] == 't' && key[2] == 't' && key[3] == 'r' && key[4] == '.'){
            const char * v = attr(key);
            if(v){
                return cc::Value(v);
            }
            return cc::Value();
        }
        else {
            return cc::Object::value(key);
        }
    }
    
    void UIStyle::setValue(const char * key,cc::Value value){
        if(key[0] == 'a' && key[1] == 't' && key[2] == 't' && key[3] == 'r' && key[4] == '.'){
            setAttr(key, cc::ValueToString(value, NULL));
        }
        else {
            cc::Object::setValue(key,value);
        }
    }

}
