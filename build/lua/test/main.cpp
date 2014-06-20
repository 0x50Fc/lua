//
//  main.c
//  test
//
//  Created by zhang hailong on 14-6-19.
//  Copyright (c) 2014年 hailong.org. All rights reserved.
//

#include <stdio.h>

#include "Context.h"

int main(int argc, const char * argv[])
{
    cc::Context ctx;
    
    if(ctx.loadString("function main()  local o = cc.new(\"Object\"); print(o.className); end main();")){
        
        printf("%s",ctx.error());
    }
    
    return 0;
}

