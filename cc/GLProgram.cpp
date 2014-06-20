//
//  GLProgram.cpp
//  glelement
//
//  Created by zhang hailong on 14-6-20.
//  Copyright (c) 2014年 hailong.org. All rights reserved.
//

#include "GLProgram.h"
#include "Log.h"

namespace cc {
    
    IMP_CLASS(GLProgram,Object)
    
    GLProgram::GLProgram():_program(NULL){
        
    }
    
    GLProgram::GLProgram(const char * vsh,const char * fsh):_program(NULL){
        
        GLint status = GL_TRUE;
        GLuint vshShader = 0,fshShader = 0;
        GLchar log[1024];
        GLint logLen = 0;
        
        vshShader = glCreateShader(GL_VERTEX_SHADER);
        glShaderSource(vshShader, 1, &vsh, NULL);
        glCompileShader(vshShader);
        
        glGetShaderInfoLog(vshShader, sizeof(log), &logLen, log);
        
        if(logLen >0){
            Log("VSH Shader compile log: %s", log);
        }
        
        glGetShaderiv(vshShader, GL_COMPILE_STATUS, &status);
        if (status != GL_TRUE)
        {
            
            glDeleteShader(vshShader);
            Log("Failed to vsh compile shader");
        }
        
        fshShader = glCreateShader(GL_FRAGMENT_SHADER);
        glShaderSource(fshShader, 1, &fsh, NULL);
        glCompileShader(fshShader);
        
        
        glGetShaderInfoLog(fshShader, sizeof(log), &logLen, log);
        
        if(logLen >0){
            Log("FSH Shader compile log: %s", log);
        }
        
        glGetShaderiv(fshShader, GL_COMPILE_STATUS, &status);
        if (status != GL_TRUE)
        {
            glDeleteShader(vshShader);
            glDeleteShader(fshShader);
            Log("Failed to fsh compile shader");
        }
        
        _program = glCreateProgram();
        
        glAttachShader(_program, vshShader);
        glAttachShader(_program, fshShader);
        
        glLinkProgram(_program);
        
        if (vshShader){
            glDeleteShader(vshShader);
        }
        
        if (fshShader){
            glDeleteShader(fshShader);
        }
        
        glGetProgramInfoLog(_program, sizeof(log), &logLen, log);
        
        if(logLen >0){
            Log("Program link log: %s", log);
        }
        
        status = GL_TRUE;
        
        glGetProgramiv(_program, GL_LINK_STATUS, &status);
        
        if (status != GL_TRUE ){
            
            Log("Program link error");
            glDeleteProgram(_program);
            _program = 0;
        }
    }
    
    GLProgram::~GLProgram(){
        if(_program){
            glDeleteProgram(_program);
        }
    }
    
    GLint GLProgram::getUniformLocation(const char * name){
        return glGetUniformLocation(_program, name);
    }
    
    GLint GLProgram::getAttribLocation(const char * name){
        return glGetAttribLocation(_program, name);
    }
    
    void GLProgram::setVertexAttribPointer(GLint attrib, int size,void * data,int stride){
        glVertexAttribPointer(attrib, size, GL_FLOAT, GL_FALSE, stride, data);
        glEnableVertexAttribArray(attrib);
    }
    
    void GLProgram::setUniform1f(GLint uniform,GLfloat value){
        glUniform1f(uniform, value);
    }
    
    void GLProgram::setUniform1fv(GLint uniform,GLfloat * value, GLint count){
        glUniform1fv(uniform, count, value);
    }
    
    void GLProgram::setUniform2f(GLint uniform,GLVector2 value){
        glUniform2f(uniform, value.x,value.y);
    }
    
    void GLProgram::setUniform2fv(GLint uniform,GLVector2 * value,GLint count){
        glUniform2fv(uniform, count, (GLfloat *) value);
    }
    
    void GLProgram::setUniform3f(GLint uniform,GLVector3 value){
        glUniform3f(uniform,value.x,value.y,value.z);
    }
    
    void GLProgram::setUniform3fv(GLint uniform,GLVector3 * value,GLint count){
        glUniform3fv(uniform, count, (GLfloat *) value);
    }
    
    void GLProgram::setUniform4f(GLint uniform,GLVector4 value){
        glUniform4f(uniform,value.x,value.y,value.z,value.w);
    }
    
    void GLProgram::setUniform4fv(GLint uniform,GLVector4 * value,GLint count){
        glUniform4fv(uniform, count, (GLfloat *) value);
    }
    
    void GLProgram::setUniform1i(GLint uniform,GLint value){
        glUniform1i(uniform, value);
    }
    
    void GLProgram::setUniform1iv(GLint uniform,GLint * value, int count){
        glUniform1iv(uniform, count, value);
    }
    
    void GLProgram::setUniform3m(GLint uniform,GLMatrix3 value){
        glUniformMatrix3fv(uniform,1, GL_FALSE, (GLfloat *) & value);
    }
    
    void GLProgram::setUniform4m(GLint uniform,GLMatrix4 value){
        glUniformMatrix4fv(uniform, 1, GL_FALSE, (GLfloat *)&value);
    }
    
    void GLProgram::use(){
        glUseProgram(_program);
    }
    
}
