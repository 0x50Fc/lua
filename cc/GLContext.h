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

#include "GL.h"

namespace cc {
    
    struct GLContextState {
        GLMatrix4 transform;
        float alpha;
        float zIndex;
        GLContextState * prev;
        GLContextState(){
            transform = GLMatrix4Identity;
            alpha = 1.0f;
            prev = NULL;
            zIndex = 0;
        }
        GLContextState(GLContextState * state){
            transform = state->transform;
            alpha = state->alpha;
            zIndex = state->zIndex;
            prev = NULL;
        }
    };
    
    class GLContext {
        
    public:
        
        GLContext(int width,int height);
        
        virtual ~GLContext();
        
        virtual int width();
        
        virtual int height();
        
        virtual void setViewport(int width,int height);
        
        virtual void translation(float x,float y,float z);
        
        virtual void scale(float x,float y,float z);
        
        virtual void rotate(float radians, float x, float y, float z);
        
        virtual void alpha(float alpha);
        
        virtual void zIndex();
        
        virtual GLContextState * state();
        
        virtual void saveState();
        
        virtual void restoreState();
        
        virtual float x(float screenX);
        
        virtual float y(float screenY);
        
        virtual float screenX(float x);
        
        virtual float screenY(float y);
        
    private:
        
        int _width;
        int _height;
        
        GLContextState * _state;
        
    };
    
}

#endif /* defined(__glelement__GLContext__) */
