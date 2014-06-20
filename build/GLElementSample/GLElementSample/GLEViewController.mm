//
//  GLEViewController.m
//  GLElementSample
//
//  Created by zhang hailong on 14-6-20.
//  Copyright (c) 2014年 hailong.org. All rights reserved.
//

#import "GLEViewController.h"

#import "GLElementLayer.h"

#import "Context.h"

#import "GLContext.h"

#import "GLLayerElement.h"

#import "GLSchedule.h"

#import "GLRun.h"

@interface GLEViewController (){
    
    cc::GLSchedule * _schedule;
    cc::Context * _luaContext;
    cc::GLContext * _glContext;
    cc::Element * _rootElement;
    GLElementLayer * _elementLayer;
    CADisplayLink * _displayLink;
    
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
}

- (void)viewDidLoad
{
    [super viewDidLoad];

    if(_schedule == nil){
        
        _schedule = new cc::GLSchedule();
        
    }
    
    if(_luaContext == nil){
        _luaContext = new cc::Context();
        _luaContext->registerClass(& cc::GLLayerElement::clazz);
        _luaContext->registerClass(& cc::GLCanvasElement::clazz);
        _luaContext->registerClass(& cc::GLElement::clazz);
        _luaContext->registerClass(& cc::Element::clazz);
        
        NSBundle * bundle = [NSBundle mainBundle];
        
        NSString * path = [bundle pathForResource:@"Element" ofType:@"lua"];
        
        if(_luaContext->loadFile([path UTF8String])){
            NSLog(@"%s",_luaContext->error());
        }
        
        path = [bundle pathForResource:@"root" ofType:@"lua"];
        
        if(_luaContext->loadFile([path UTF8String])){
            NSLog(@"%s",_luaContext->error());
        }
    }
    
    if(_rootElement == nil){
        cc::Object * object = _luaContext->globalObject("root");
        if(object && object->isKindOfClass(& cc::Element::clazz)){
            _rootElement = (cc::Element *)  object;
        }
    }
    
    if(_glContext == nil){
        _glContext = new cc::GLContext();
    }
    
    if(_elementLayer == nil){
        
        _elementLayer = [[GLElementLayer alloc] init];
    
    }
    
    CGSize size = self.view.bounds.size;
    
    _elementLayer.frame = CGRectMake(0, 0, size.width, size.height);
    
    [self.view.layer addSublayer:_elementLayer];
    
    if(_displayLink == nil){
        _displayLink = [CADisplayLink displayLinkWithTarget:self selector:@selector(doFrameAction)];
        [_displayLink setFrameInterval:1.0 / 60.0];
    }
    
    [_displayLink addToRunLoop:[NSRunLoop currentRunLoop] forMode:NSDefaultRunLoopMode];
    
}

-(void) doFrameAction{
    
    if(_schedule && _rootElement){
        
        _schedule->timestamp = CFAbsoluteTimeGetCurrent();
        
        cc::GLRunSchedule(_schedule, _rootElement);
        
    }
    
    if(_glContext && _rootElement){
        [_elementLayer glDrawContext:_glContext element:_rootElement];
    }
    
}

- (void)didReceiveMemoryWarning
{
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

@end
