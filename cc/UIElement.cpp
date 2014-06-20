//
//  UIElement.cpp
//  uielement
//
//  Created by zhang hailong on 14-6-20.
//  Copyright (c) 2014年 hailong.org. All rights reserved.
//

#include "UIElement.h"

namespace ui {
    
    IMP_CLASS(UIElement, cc::Element)
    
    UIElement::UIElement(){
        
    }
    
    UIElement::~UIElement(){
        if(_style){
            _style->release();
        }
    }
    
    const char * UIElement::attr(const char * key){
        std::map<std::string,std::string>::iterator i = _attrs.find(key);
        return i != _attrs.end() ? i->second.c_str() : NULL;
    }
    
    void UIElement::setAttr(const char * key,const char * value){
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
    
    cc::Value UIElement::value(const char * key){
        if(key[0] == 'a' && key[1] == 't' && key[2] == 't' && key[3] == 'r' && key[4] == '.'){
            const char * v = attr(key + 5);
            if(v){
                return cc::Value(v);
            }
            return cc::Value();
        }
        else {
            return cc::Element::value(key);
        }
    }
    
    void UIElement::setValue(const char * key,cc::Value value){
        if(key[0] == 'a' && key[1] == 't' && key[2] == 't' && key[3] == 'r' && key[4] == '.'){
            setAttr(key + 5, cc::ValueToString(value, NULL));
        }
        else {
            cc::Element::setValue(key,value);
        }
    }
    
    UIStyle * UIElement::style(){
        return _style;
    }
    
    void UIElement::setStyle(UIStyle * style){
        
        if(_style != style){
            
            if(style){
                style->retain();
            }
            
            if(_style){
                _style->release();
            }
            
            _style = style;
        }
    }
    
    int UIElement::intValue(const char *key,int defaultValue){
        const char * v = stringValue(key, NULL);
        if(v){
            return atoi(v);
        }
        return defaultValue;
    }
    
    float UIElement::floatValue(const char * key,float defaultValue){
        const char * v = stringValue(key, NULL);
        if(v){
            return atof(v);
        }
        return defaultValue;
    }
    
    float UIElement::floatValueOf(const char * key,float baseValue,float defaultValue){
        
        const char * v = stringValue(key, NULL);
        
        if(v){
            
            if(strcmp(v, "auto") == 0){
                return UIAutoValue;
            }
            
            float vv = 0;
            char * p = (char *) v;
            float d0 = 10,d1 = 1;
            
            while (*p != '\0') {
                
                if(*p == '.'){
                    d1 = 0.1;
                    d0 = 1;
                }
                else if(*p == '%'){
                    vv = vv * baseValue * 0.001;
                }
                else if(*p == '-'){
                    vv = vv - atof(p + 1);
                    break;
                }
                else if(*p == '+'){
                    vv = vv + atof(p + 1);
                    break;
                }
                else if(*p == ' ' || *p == '\r' || *p == '\n'){
                    
                }
                else if(*p >= '0' && *p <='9'){
                    vv = vv * d0 + (*p - '0') * d1;
                    if(d1 < 1){
                        d1 = d1 * 0.1;
                    }
                }
                else {
                    break;
                }
                
                p ++;
            }
            
            return vv;
        }
        
        return defaultValue;
    }
    
    const char * UIElement::stringValue(const char * key,const char * defaultValue){
       
        const char * v = attr(key);
        
        if(v == NULL && _style){
            v = _style->attr(key);
        }
        
        if(v){
            return v;
        }
        
        return defaultValue;
    }
    
    UIColor UIElement::colorValue(const char * key,UIColor defaultValue){
        const char * v = stringValue(key, NULL);
        if(v){
            return UIColor(v);
        }
        return defaultValue;
    }
    
    
}
