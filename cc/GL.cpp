//
//  GL.cpp
//  glelement
//
//  Created by zhang hailong on 14-6-19.
//  Copyright (c) 2014年 hailong.org. All rights reserved.
//

#include "GL.h"

namespace cc {
    
    const GLMatrix4 GLMatrix4Identity = {
        1.0,0.0,0.0,0.0,
        0.0,1.0,0.0,0.0,
        0.0,0.0,1.0,0.0,
        0.0,0.0,0.0,1.0,
    };
    
    const GLMatrix3 GLMatrix3Identity = {
        1.0,0.0,0.0,
        0.0,1.0,0.0,
        0.0,0.0,1.0,
    };
    
    int GLColor3dToIntValue(GLColor3d color){
        int r = color.r  * 0xff;
        int g = color.g  * 0xff;
        int b = color.b  * 0xff;
        int a = color.a  * 0xff;
        return (a << 24) | (r << 16) | (g << 8) | b ;
    }
    
    GLColor3d GLColor3dFromIntValue(int value){
        int a = value >> 24;
        int r = value & 0x00ff0000 >> 16;
        int g = value & 0x0000ff00 >> 8;
        int b = value & 0x000000ff;
        GLColor3d c = {(GLfloat) r / 0xff,(GLfloat) g / 0xff,(GLfloat) b / 0xff,(GLfloat) a / 0xff};
        return c;
    }
    
    GLColor3d GLColor3dFromString(const char * value){
        int a = 0;
        int r = 0;
        int g = 0;
        int b = 0;
        
        if(value){
            size_t l = strlen(value);
            if(l ==4 && * value == '#'){
                sscanf(value,"#%1x%1x%1x",&r,&g,&b);
                r = r * 16 +r;
                g = g * 16 +g;
                b = b * 16 +b;
                a = 1.0;
            }
            else if(* value == '#'){
                float aa = 1.0;
                sscanf(value,"#%02x%02x%02x %f",&r,&g,&b,& aa);
                a = aa * 0xff;
            }
            else if(value[0] == '0' && value[1] == 'x'){
                sscanf(value,"#%02x%02x%02x%02x",&a,&r,&g,&b);
            }
        }
        
        GLColor3d c = {(GLfloat) r / 0xff,(GLfloat) g / 0xff,(GLfloat) b / 0xff,(GLfloat) a / 0xff};
        
        return c;
    }

}