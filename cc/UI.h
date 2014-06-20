//
//  UI.h
//  uielement
//
//  Created by zhang hailong on 14-6-20.
//  Copyright (c) 2014年 hailong.org. All rights reserved.
//

#ifndef __uielement__UI__
#define __uielement__UI__

#include <iostream>

namespace ui {
    
    struct UIColor {
        float r,g,b,a;
        UIColor():r(0.0f),g(0.0f),b(0.0f),a(0.0f){};
        UIColor(float r,float g,float b,float a):r(r),g(g),b(b),a(a){};
        UIColor(const char * string);
    };
    
    struct UISize {
        float width,height;
        UISize():width(0.0f),height(0.0f){};
        UISize(float width,float height):width(width),height(height){};
    };
    
    struct UIPoint {
        float x,y;
        UIPoint():x(0.0f),y(0.0f){};
        UIPoint(float x,float y):x(x),y(y){};
    };
    
    struct UIRect {
        UIPoint origin;
        UISize size;
        UIRect():origin(),size(){};
        UIRect(float x,float y,float width,float height):origin(x,y),size(width,height){};
    };
    
    struct UIEdge {
        float left,top,right,bottom;
        UIEdge():left(0),top(0),right(0),bottom(0){};
        UIEdge(float left,float top,float right,float bottom)
            :left(left),top(top),right(right),bottom(bottom){};
    };
    
    enum UIFontStyle {
        UIFontStyleNone,UIFontStyleBold,UIFontStyleItalic
    };
    
    struct UIFont {
        char name[64];
        float size;
        UIFontStyle style;
        UIFont():name(""),size(14),style(UIFontStyleNone){};
        UIFont(float size):name(""),size(size),style(UIFontStyleNone){};
        UIFont(float size,UIFontStyle style):name(""),size(size),style(style){};
        UIFont(const char * fontName,float size,UIFontStyle style):size(size),style(style){
            strncpy(name,fontName,sizeof(name));
        };
        UIFont(const char * fontName,float size):size(size),style(UIFontStyleNone){
            strncpy(name,fontName,sizeof(name));
        };
    };
    
    extern float UIAutoValue;
}

#endif /* defined(__uielement__UI__) */
