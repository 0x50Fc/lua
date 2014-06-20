//
//  GLElementLayer.h
//  glui
//
//  Created by zhang hailong on 14-6-20.
//  Copyright (c) 2014年 hailong.org. All rights reserved.
//

#import <UIKit/UIKit.h>

#import <OpenGLES/EAGL.h>
#import <OpenGLES/EAGLDrawable.h>


@interface GLElementLayer : CAEAGLLayer

@property(nonatomic,readonly) CGSize viewport;

-(void) glDrawContext:(void *) context element:(void *) element;

@end
