//
//  IUIViewEntity.h
//  uielement
//
//  Created by zhang hailong on 14-6-21.
//  Copyright (c) 2014年 hailong.org. All rights reserved.
//

#import <UIKit/UIKit.h>

#import "Element.h"

@protocol IUIViewEntity <NSObject>

@optional

-(void) elementDoNeedsDisplay:(cc::Element *) element;

-(void) elementDoAction:(id<IUIViewEntity>) viewEntity element:(cc::Element *) element;

-(UIView *) elementViewOf:(cc::Element *) element viewClass:(Class)viewClass;

-(void) elementLayoutView:(cc::Element *) element view:(UIView *) view;

-(void) elementDetach:(cc::Element *) element;

-(void) elementVisable:(id<IUIViewEntity>) viewEntity element:(cc::Element *) element;

@end
