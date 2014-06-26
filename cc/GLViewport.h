//
//  GLViewport.h
//  glelement
//
//  Created by zhang hailong on 14-6-26.
//  Copyright (c) 2014年 hailong.org. All rights reserved.
//

#ifndef __glelement__GLViewport__
#define __glelement__GLViewport__

#include <iostream>

#include "Object.h"
#include "GL.h"

namespace cc {
    
    class GLViewport : public Object {
    
    public:
        
        GLViewport();
        
        virtual ~GLViewport();
        
        virtual void setViewport(GLfloat width,GLfloat heigh);
        
        virtual GLfloat width();
        
        virtual GLfloat height();
        
        virtual GLfloat global(GLfloat screen);
        
        virtual GLfloat screen(GLfloat global);
        
        virtual GLMatrix4 project();
        
        DEC_CLASS
        
    private:
        
        GLfloat _width;
        GLfloat _height;
        GLMatrix4 _project;
    };
}

#endif /* defined(__glelement__GLViewport__) */
