//
//  GLContext.h
//  glelement
//
//  Created by zhang hailong on 14-6-19.
//  Copyright (c) 2014年 hailong.org. All rights reserved.
//

#ifndef __glelement__GLContext__
#define __glelement__GLContext__

#include <iostream>
#include <map>

#include "GL.h"
#include "GLProgram.h"
#include "GLImage.h"
#include "GLLoader.h"
#include "GLViewport.h"

namespace cc {
    
    struct GLContextState {
        GLMatrix4 transform;
        float alpha;
        GLContextState * prev;
        GLContextState(){
            transform = GLMatrix4Identity;
            alpha = 1.0f;
            prev = NULL;
        }
        GLContextState(GLContextState * state){
            transform = state->transform;
            alpha = state->alpha;
            prev = NULL;
        }
    };
    
    class GLContext : public GLViewport{
        
    public:
        
        GLContext();
        
        GLContext(GLLoader * loader);
        
        virtual ~GLContext();
        
        virtual void translation(float x,float y,float z);
    
        virtual void scale(float x,float y,float z);
        
        virtual void rotate(float radians, float x, float y, float z);
        
        virtual void alpha(float alpha);
        
        virtual void transform(GLMatrix4 transform);
        
        virtual GLContextState * state();
        
        virtual void saveState();
        
        virtual void restoreState();
        
        virtual GLProgram * program(const char * key);
        
        virtual void setProgram(const char * key,GLProgram * program);

        virtual GLLoader * loader();
        
        DEC_CLASS

        GLfloat zIndex;
        
    private:
        
        GLLoader * _loader;
        std::map<std::string,GLProgram *> _programs;
        GLContextState * _state;
    };
    
}

#endif /* defined(__glelement__GLContext__) */
