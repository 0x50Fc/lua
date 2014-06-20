//
//  UI.cpp
//  uielement
//
//  Created by zhang hailong on 14-6-20.
//  Copyright (c) 2014年 hailong.org. All rights reserved.
//

#include "UI.h"

#include <stdio.h>
#include <math.h>

namespace ui {
    
    UIColor::UIColor(const char * value){
        
        if(value){
            size_t l = strlen(value);
            if(l ==4 && * value == '#'){
                int rr=  0,gg = 0,bb = 0;
                sscanf(value,"#%1x%1x%1x",&rr,&gg,&bb);
                rr = rr * 16 +rr;
                gg = gg * 16 +gg;
                bb = bb * 16 +bb;
                r = (float) rr / 0xff;
                g = (float) gg / 0xff;
                b = (float) bb / 0xff;
                a = 1.0f;
            }
            else if(* value == '#'){
                int rr=  0,gg = 0,bb = 0;
                float aa = 1.0;
                sscanf(value,"#%02x%02x%02x %f",&rr,&gg,&bb,& aa);
                r = (float) rr / 0xff;
                g = (float) gg / 0xff;
                b = (float) bb / 0xff;
                a = aa;
            }
            else if(value[0] == '0' && value[1] == 'x'){
                int rr=  0,gg = 0,bb = 0,aa = 0;
                sscanf(value,"#%02x%02x%02x%02x",&aa,&rr,&gg,&bb);
                r = (float) rr / 0xff;
                g = (float) gg / 0xff;
                b = (float) bb / 0xff;
                a = (float) aa / 0xff;
            }
        }
        
    }
    
    float UIAutoValue = MAXFLOAT;
    
}
