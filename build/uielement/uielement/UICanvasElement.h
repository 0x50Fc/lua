//
//  UICanvasElement.h
//  uielement
//
//  Created by zhang hailong on 14-6-20.
//  Copyright (c) 2014年 hailong.org. All rights reserved.
//

#ifndef __uielement__UICanvasElement__
#define __uielement__UICanvasElement__

#include <iostream>

#include "UILayoutElement.h"

namespace ui {
    
    class UICanvasElement : public UILayoutElement {
    
    public:
        
        UICanvasElement();
        
        virtual ~UICanvasElement();
        
        DEC_CLASS
        
    };
}

#endif /* defined(__uielement__UICanvasElement__) */
