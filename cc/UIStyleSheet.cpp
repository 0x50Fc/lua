//
//  UIStyleSheet.cpp
//  uielement
//
//  Created by zhang hailong on 14-6-20.
//  Copyright (c) 2014年 hailong.org. All rights reserved.
//

#include "UIStyleSheet.h"

namespace ui {
    
    IMP_CLASS(UIStyleSheet, cc::Object)
    
    static void UIStyleSheetStyle(const char * style, std::map<std::string,std::string> * map){
        
    }
    
    static void UIStyleSheetCSS(const char * css, std::map<std::string,std::map<std::string,std::string>> * map){
        
    }
    
    UIStyleSheet::UIStyleSheet(){
        
    }
    
    UIStyleSheet::~UIStyleSheet(){
        
    }
    
    void UIStyleSheet::setStyle(const char * name,const char * style){
        
        if(name && style){
            
            std::map<std::string,std::map<std::string,std::string>>::iterator i = _styles.find(name);
            
            if(i == _styles.end()){
                _styles[name] = std::map<std::string,std::string>();
                i = _styles.find(name);
            }
            
            UIStyleSheetStyle(style,& i->second);
        }
        
    }
    
    void UIStyleSheet::setCSS(const char * css){
        if(css){
            UIStyleSheetCSS(css, & _styles);
        }
    }
    
    void UIStyleSheet::clear(){
        _styles.clear();
    }
    
    void UIStyleSheet::selector(const char * styleName,UIStyle * style){
        
        if(styleName && style){
            
            char name[128] = "";
            char *p = (char *) styleName;
            
            while (*p != '\0' ) {
                
                sscanf(p, "%[^ ,;]",name);
                
                std::map<std::string,std::map<std::string,std::string>>::iterator ii = _styles.find(name);
                
                if(ii != _styles.end()){
                    
                    std::map<std::string,std::string>::iterator iii = ii->second.begin();
                    
                    while (iii != ii->second.end()) {
                        
                        style->setAttr(iii->first.c_str(), iii->second.c_str());
                        
                        iii ++;
                    }
                    
                    ii++;
                }
                
                p += strlen(name);
            }
            
        }
    }

    void UIStyleSheet::invoke(const char * key,cc::InvokeArgs * args){
    
        if(strcmp(key, "setStyle") == 0){
            setStyle(cc::ValueToString(cc::InvokeArgsValue(args, 0), NULL)
                     ,cc::ValueToString(cc::InvokeArgsValue(args, 1), NULL));
        }
        else if(strcmp(key, "setCSS") == 0){
            setCSS(cc::ValueToString(cc::InvokeArgsValue(args, 0), NULL));
        }
        else if(strcmp(key, "setCSS") == 0){
            setCSS(cc::ValueToString(cc::InvokeArgsValue(args, 0), NULL));
        }
        else if(strcmp(key, "clear") == 0){
            clear();
        }
        else if(strcmp(key, "selector") == 0){
            cc::Value v = cc::InvokeArgsValue(args, 1);
            if(v.type == cc::ValueTypeObject){
                cc::Object * o = v.objectValue;
                if(o && o->isKindOfClass(& UIStyle::clazz)){
                    selector(cc::ValueToString(cc::InvokeArgsValue(args, 0), NULL),(UIStyle *) o);
                }
            }
        }
        else {
            return cc::Object::invoke(key, args);
        }
    }

}
