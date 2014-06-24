//
//  GLEViewController.m
//  GLElementSample
//
//  Created by zhang hailong on 14-6-20.
//  Copyright (c) 2014年 hailong.org. All rights reserved.
//

#import "GLEViewController.h"
#import "Context.h"
#import "GLLibrary.h"

#include "GLElementView.h"

@interface GLEViewController (){
    
    cc::GLLoader * _loader;
    cc::GLSchedule * _schedule;
    cc::Context * _luaContext;
    cc::GLContext * _glContext;
    cc::Element * _rootElement;
    GLElementView * _elementView;
    CADisplayLink * _displayLink;
    NSTimeInterval _gcTimestamp;
}

@end

@implementation GLEViewController

-(void) dealloc{
    
    [_displayLink removeFromRunLoop:[NSRunLoop currentRunLoop] forMode:NSDefaultRunLoopMode];
    
    if(_luaContext){
        delete _luaContext;
    }
    
    if(_glContext){
        _glContext->release();
    }
    
    if(_schedule){
        _schedule->release();
    }
    
    if(_loader){
        _loader->release();
    }
}

- (void)viewDidLoad
{
    [super viewDidLoad];

    if(_loader == nil){
        
        NSString * res = [[NSBundle mainBundle] bundlePath];
        NSString * doc = [NSHomeDirectory() stringByAppendingPathComponent:@"Documents"];
        NSString * tmp = NSTemporaryDirectory();
        
        _loader = new cc::GLLoader([res UTF8String],[doc UTF8String],[tmp UTF8String]);
        
    }
    
    if(_schedule == nil){
        
        _schedule = new cc::GLSchedule(_loader);
        
    }
    
    if(_luaContext == nil){
        
        _luaContext = new cc::Context();
        
        GLLibraryLoadClass(_luaContext);
        
        NSBundle * bundle = [NSBundle mainBundle];
        
        NSString * path = [bundle pathForResource:@"Object" ofType:@"lua"];
        
        if(_luaContext->loadFile([path UTF8String])){
            NSLog(@"%s",_luaContext->error());
        }
        
        path = [bundle pathForResource:@"Element" ofType:@"lua"];
        
        if(_luaContext->loadFile([path UTF8String])){
            NSLog(@"%s",_luaContext->error());
        }
        
        path = [bundle pathForResource:@"root" ofType:@"lua"];
        
        if(_luaContext->loadFile([path UTF8String])){
            NSLog(@"%s",_luaContext->error());
        }
        
        _luaContext->gc();
        
    }
    
    if(_rootElement == nil){
        cc::Object * object = _luaContext->globalObject("root");
        if(object && object->isKindOfClass(& cc::Element::clazz)){
            _rootElement = (cc::Element *)  object;
        }
    }
    
    if(_glContext == nil){
        _glContext = new cc::GLContext(_loader);
    }
    
    CGSize size = self.view.bounds.size;
    
    
    if(_elementView == nil){
        
        _elementView = [[GLElementView alloc] initWithFrame:CGRectMake(0, 0, size.width, size.height)];
    
        [_elementView setAutoresizingMask:UIViewAutoresizingFlexibleWidth | UIViewAutoresizingFlexibleHeight];
        
    }
    else {
        _elementView.frame = CGRectMake(0, 0, size.width, size.height);;
    }
    
    [_elementView setElement:_rootElement];

    [self.view addSubview:_elementView];
    
    if(_displayLink == nil){
        _displayLink = [CADisplayLink displayLinkWithTarget:self selector:@selector(doFrameAction)];
        [_displayLink setFrameInterval:1.0 / 60.0];
    }
    
    [_displayLink addToRunLoop:[NSRunLoop currentRunLoop] forMode:NSDefaultRunLoopMode];
    
}


-(void) doFrameAction{
    
    cc::Context::setCurrent(_luaContext);
    
    if(_schedule && _rootElement){
        
        _schedule->tick(CFAbsoluteTimeGetCurrent());

        cc::GLRunSchedule(_schedule, _rootElement);
        
    }
    
    if(_glContext){
        [_elementView glDrawContext:_glContext];
    }
    
    if(_luaContext){
        if(CFAbsoluteTimeGetCurrent() - _gcTimestamp > 0.6){
            _luaContext->gc();
            _gcTimestamp = CFAbsoluteTimeGetCurrent();
        }
    }
}

- (void)didReceiveMemoryWarning
{
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

@end
