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
    
    class GLContext : public Object{
        
    public:
        
        GLContext();
        
        GLContext(int width,int height);
        
        virtual ~GLContext();
        
        virtual int width();
        
        virtual int height();
        
        virtual void setViewport(int width,int height);
        
        virtual void translation(float x,float y,float z);
        
        virtual void scale(float x,float y,float z);
        
        virtual void rotate(float radians, float x, float y, float z);
        
        virtual void alpha(float alpha);
        
        virtual void transform(GLMatrix4 transform);
        
        virtual void zIndex();
        
        virtual GLContextState * state();
        
        virtual void saveState();
        
        virtual void restoreState();
        
        virtual GLfloat global(GLfloat screen);

        virtual GLfloat screen(GLfloat global);
        
        virtual GLProgram * program(const char * key);
        
        virtual void setProgram(const char * key,GLProgram * program);
        
        virtual GLImage * image(const char * key);
        
        virtual void setImage(const char * key, GLImage * image);
        
        virtual void clearImages();
        
        GLMatrix4 projectTransform;
        
        DEC_CLASS
        
    private:
        
        std::map<std::string,GLProgram *> _programs;
        std::map<std::string,GLImage *> _images;
        
        int _width;
        int _height;
        
        GLContextState * _state;
        
    };
    
}

#endif /* defined(__glelement__GLContext__) */
