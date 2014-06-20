//
//  GLProgram.h
//  glelement
//
//  Created by zhang hailong on 14-6-20.
//  Copyright (c) 2014年 hailong.org. All rights reserved.
//

#ifndef __glelement__GLProgram__
#define __glelement__GLProgram__

#include <iostream>

#include "Object.h"
#include "GL.h"

namespace cc {
    
    class GLProgram : public Object {
        
    public:
        
        GLProgram();
        
        GLProgram(const char * vsh,const char * fsh);
        
        virtual ~GLProgram();
        
        GLint getUniformLocation(const char * name);
        
        GLint getAttribLocation(const char * name);
        
        virtual void setVertexAttribPointer(GLint attrib, int size,void * data,int stride);
        
        virtual void setUniform1f(GLint uniform,GLfloat value);
        
        virtual void setUniform1fv(GLint uniform,GLfloat * value, GLint count);
        
        virtual void setUniform2f(GLint uniform,GLVector2 value);
        
        virtual void setUniform2fv(GLint uniform,GLVector2 * value,GLint count);
        
        virtual void setUniform3f(GLint uniform,GLVector3 value);
        
        virtual void setUniform3fv(GLint uniform,GLVector3 * value,GLint count);
        
        virtual void setUniform4f(GLint uniform,GLVector4 value);
        
        virtual void setUniform4fv(GLint uniform,GLVector4 * value,GLint count);
        
        virtual void setUniform1i(GLint uniform,GLint value);
        
        virtual void setUniform1iv(GLint uniform,GLint * value, GLint count);
        
        virtual void setUniform3m(GLint uniform,GLMatrix3 value);
        
        virtual void setUniform4m(GLint uniform,GLMatrix4 value);
        
        virtual void use();
        
        DEC_CLASS
        
    protected:
        
        GLuint _program;
    };
}

#endif /* defined(__glelement__GLProgram__) */
