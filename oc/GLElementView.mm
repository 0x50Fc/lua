//
//  GLElementView.m
//  glui
//
//  Created by zhang hailong on 14-6-24.
//  Copyright (c) 2014年 hailong.org. All rights reserved.
//

#import "GLElementView.h"

#import "GLElementLayer.h"

#import "Element.h"

#import "GLRun.h"


@interface GLElementView(){
    cc::Element * _element;
    std::map<UITouch *,cc::GLTouch *> _touches;
}

@end

@implementation GLElementView

+(Class) layerClass{
    return [GLElementLayer class];
}

- (id)initWithFrame:(CGRect)frame
{
    self = [super initWithFrame:frame];
    if (self) {
        // Initialization code
    }
    return self;
}

-(void) dealloc{
    
    std::map<UITouch *,cc::GLTouch *>::iterator i = _touches.begin();
    
    while(i != _touches.end()){
        
        i->second->release();
        
        i ++;
    }
    
    if(_element){
        _element->release();
    }
}

/*
// Only override drawRect: if you perform custom drawing.
// An empty implementation adversely affects performance during animation.
- (void)drawRect:(CGRect)rect
{
    // Drawing code
}
*/

-(void) glDrawContext:(void *) context{
    if(_element){
        @synchronized(self) {
            [(GLElementLayer *)self.layer glDrawContext:context element:_element];
        }
    }
}

-(void) setElement:(void *) element{
    
    @synchronized(self) {
        
        if(element){
            ((cc::Element *) element)->retain();
        }
        
        if(_element){
            _element->release();
        }
        
        _element = (cc::Element *) element;
    }
}

-(void *) element{
    return _element;
}

-(CGSize) viewport {
    return [(GLElementLayer *)self.layer viewport];
}

-(void) touches:(NSSet *)touches touchState:(cc::GLTouchState) touchState{
    
    if(_element){
        
        CGSize viewport = [self viewport];
        
        for (UITouch * touch in touches) {
            
            CGPoint location = [touch locationInView:self];
            
            std::map<UITouch *,cc::GLTouch *>::iterator i = _touches.find(touch);
            
            cc::GLTouch * t = nil;
            
            if(i != _touches.end()){
                t = i->second;
                t->screenX = location.x;
                t->screenY = location.y;
                t->screenWidth = viewport.width;
                t->screenHeight = viewport.height;
            }
            else {
                t = new cc::GLTouch(location.x,location.y,viewport.width,viewport.height);
                _touches[touch] = t;
            }
            
            cc::GLRunTouch(t,touchState,(cc::Element *) _element);
        }
        
    }
    
}

-(void) removeTouches:(NSSet *)touches{
    
    std::map<UITouch *,cc::GLTouch *>::iterator i = _touches.begin();
    
    while(i != _touches.end()){
        
        if([touches containsObject:i->first]){
            i->second->release();
            i = _touches.erase(i);
        }
        else{
            i ++;
        }
    }
}

- (void)touchesBegan:(NSSet *)touches withEvent:(UIEvent *)event{
    [self touches:touches touchState:cc::GLTouchStateBegin];
}

- (void)touchesMoved:(NSSet *)touches withEvent:(UIEvent *)event{
    [self touches:touches touchState:cc::GLTouchStateMoved];
}

- (void)touchesEnded:(NSSet *)touches withEvent:(UIEvent *)event{
    [self touches:touches touchState:cc::GLTouchStateEnded];
    [self removeTouches:touches];
}

- (void)touchesCancelled:(NSSet *)touches withEvent:(UIEvent *)event{
    [self touches:touches touchState:cc::GLTouchStateCanceled];
    [self removeTouches:touches];
}

@end
