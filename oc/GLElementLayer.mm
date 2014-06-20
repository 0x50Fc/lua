//
//  GLElementLayer.m
//  glui
//
//  Created by zhang hailong on 14-6-20.
//  Copyright (c) 2014年 hailong.org. All rights reserved.
//

#import "GLElementLayer.h"
#import "GLContext.h"
#import "GLRun.h"
#import "GL.h"

@interface GLElementLayer()

@property(nonatomic,readonly) EAGLContext * context;
@property(nonatomic,readonly) GLuint viewFramebuffer;
@property(nonatomic,readonly) GLuint viewRenderbuffer;
@property(nonatomic,readonly) GLuint depthRenderbuffer;

@end

@implementation GLElementLayer

@synthesize context = _context;
@synthesize viewport = _viewport;
@synthesize viewFramebuffer = _viewFramebuffer;
@synthesize viewRenderbuffer = _viewRenderbuffer;
@synthesize depthRenderbuffer = _depthRenderbuffer;

-(id) init{
    if((self = [super init])) {
        
        self.opaque = YES;
        self.drawableProperties = [NSDictionary dictionaryWithObjectsAndKeys:
                                   [NSNumber numberWithBool:YES], kEAGLDrawablePropertyRetainedBacking, kEAGLColorFormatRGBA8, kEAGLDrawablePropertyColorFormat, nil];
        
        _context = [[EAGLContext alloc] initWithAPI:kEAGLRenderingAPIOpenGLES2];
        
        if(!_context){
            _context = [[EAGLContext alloc] initWithAPI:kEAGLRenderingAPIOpenGLES1];
            if (!_context || ![EAGLContext setCurrentContext:_context]) {
                NSLog(@"Failed to initialize OpenGLES context");
                exit(1);
            }
        }
        else if(![EAGLContext setCurrentContext:_context]){
            NSLog(@"Failed to initialize OpenGLES context");
            exit(1);
        }
        

        glGenFramebuffers(1, &_viewFramebuffer);
        glGenRenderbuffers(1, &_viewRenderbuffer);
        glGenRenderbuffers(1, &_depthRenderbuffer);

        [self resizeGL];
        
    }
    return self;
}

-(void) resizeGL{
    
    CGSize size = self.bounds.size;
    
    if(_viewport.width != size.width || _viewport.height != size.height){
        
        _viewport = size;
        
        int width = size.width;
        int height = size.height;
        
        [EAGLContext setCurrentContext:_context];
        
        glBindRenderbuffer(GL_RENDERBUFFER, _viewRenderbuffer);
        [_context renderbufferStorage:GL_RENDERBUFFER fromDrawable:(CAEAGLLayer*)self];
        
        glGetRenderbufferParameteriv(GL_RENDERBUFFER, GL_RENDERBUFFER_WIDTH, &width);
        glGetRenderbufferParameteriv(GL_RENDERBUFFER, GL_RENDERBUFFER_HEIGHT, &height);
        
        glBindRenderbuffer(GL_RENDERBUFFER, _depthRenderbuffer);
        glRenderbufferStorage(GL_RENDERBUFFER, GL_DEPTH_COMPONENT16, width, height);
        
        glBindFramebuffer(GL_FRAMEBUFFER, _viewFramebuffer);
        glFramebufferRenderbuffer(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_RENDERBUFFER, _viewRenderbuffer);
        glFramebufferRenderbuffer(GL_FRAMEBUFFER, GL_DEPTH_ATTACHMENT, GL_RENDERBUFFER, _depthRenderbuffer);
        
    }
}

-(void) setBounds:(CGRect)bounds{
    [super setBounds:bounds];
    [self resizeGL];
}

-(void) setFrame:(CGRect)frame{
    [super setFrame:frame];
    [self resizeGL];
}

-(void) glDrawContext:(void *) context element:(void *) element{
    
    // 设为当前画布
	[EAGLContext setCurrentContext:_context];
    
	// 设置视图窗口大小
    
    glViewport(0,0,_viewport.width,_viewport.height);
    
    glEnable(GL_DEPTH_TEST);
    
    if(self.opaque){
        glBlendFunc(GL_ONE, GL_ONE_MINUS_SRC_ALPHA);
        glEnable(GL_BLEND);
    }
    
    CGFloat r = 0.0,g = 0.0,b = 0.0,a = 1.0;
    
    if(self.backgroundColor){
        UIColor * color = [UIColor colorWithCGColor:self.backgroundColor];
        [color getRed:&r green:&g blue:&b alpha:&a];
    }
    
    glClearColor(r, g, b, a);
    
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    
    cc::GLContext * ctx = (cc::GLContext *) context;
    
    cc::Element * el = (cc::Element *) element;
    
    if(ctx->width() != _viewport.width || ctx->height() != _viewport.height){
        
        ctx->setViewport(_viewport.width, _viewport.height);

    }
    
    cc::GLRunContext(ctx, el);
    
    glBindRenderbuffer(GL_RENDERBUFFER, _viewRenderbuffer);
    
    [_context presentRenderbuffer:GL_RENDERBUFFER]; // 渲染到设备
}

@end
