//
//  GLRoleElement.cpp
//  glelement
//
//  Created by zhang hailong on 14-6-24.
//  Copyright (c) 2014年 hailong.org. All rights reserved.
//

#include "GLRoleElement.h"

#include "GLTacticElement.h"

namespace cc {
    
    
    IMP_CLASS(GLRoleElement, GLElement)
    
    GLRoleElement::GLRoleElement(){
        
    }
    
    GLRoleElement::~GLRoleElement(){
        
    }
    
    void GLRoleElement::setStatus(int * status,int count){
        _status.clear();
        while (count >0) {
            _status.insert(* status);
            status ++;
            count --;
        }
        onStatusChanged();
    }
    
    void GLRoleElement::setStatus(int status,...){
        _status.clear();
        _status.insert(status);
        va_list ap;
        va_start(ap, status);
        
        int s;
        
        while((s = va_arg(ap, int))) {
            _status.insert(s);
        }
        
        va_end(ap);
        
        onStatusChanged();
    }
    
    void GLRoleElement::setStatus(int status){
        _status.clear();
        _status.insert(status);
        onStatusChanged();
    }
    
    bool GLRoleElement::hasStatus(int status){
        return _status.find(status) != _status.end();
    }
    
    void GLRoleElement::addStatus(int status){
        _status.insert(status);
        onStatusChanged();
    }
    
    void GLRoleElement::removeStatus(int status){
        
        std::set<int>::iterator i = _status.find(status);
        
        if(i != _status.end()){
            _status.erase(i);
        }
        
        onStatusChanged();
        
    }
    
    void GLRoleElement::removeStatus(int status,...){
        
        std::set<int>::iterator i = _status.find(status);
        if(i != _status.end()){
            _status.erase(i);
        }
        
        va_list ap;
        va_start(ap, status);
        
        int s;
        
        while((s = va_arg(ap, int))) {
            
            i = _status.find(s);
            if(i != _status.end()){
                _status.erase(i);
            }

        }
        
        va_end(ap);
        
        onStatusChanged();
    }
    
    void GLRoleElement::clearStatus(){
        _status.clear();
        onStatusChanged();
    }
    
    void GLRoleElement::onStatusChanged(){
        
        int c = childCount();
        
        for(int i=0;i<c;i++){
            
            Element * child = childAt(i);
            
            if(child->isKindOfClass(& GLTacticElement::clazz)){
                
                GLTacticElement * tactic = (GLTacticElement *) child;
                
                tactic->onElementChanged(this);
                

            }
        }
    }
    
    Value GLRoleElement::invoke(const char * key,InvokeArgs * args){
        if(strcmp(key, "removeStatus") == 0){
            
            std::set<int>::iterator ii;
            
            for (int i=0;i<args->count;i++) {
                ii = _status.find(ValueToInt(InvokeArgsValue(args, i), 0));
                if(ii != _status.end()){
                    _status.erase(ii);
                }
            }
            
            onStatusChanged();
            
            return Value();
        }
        else if(strcmp(key, "setStatus") == 0){
            
            _status.clear();
            
            for (int i=0;i<args->count;i++) {
                _status.insert(ValueToInt(InvokeArgsValue(args, i), 0));
            }
            
            onStatusChanged();
            
            return Value();
        }
        else if(strcmp(key, "hasStatus") == 0){
            if(args->count >0 ){
                return Value(hasStatus(ValueToInt(InvokeArgsValue(args, 0), 0)));
            }
            return Value(false);
        }
        else{
            return GLElement::invoke(key, args);
        }
    }
    
    void GLRoleElement::addChild(Element * element){
        
        if(element->isKindOfClass(& GLTacticElement::clazz)){
            
            GLTacticElement * tactic = (GLTacticElement *) element;
            
            tactic->onElementChanged(this);
    
        }

        GLElement::addChild(element);
    }
}
