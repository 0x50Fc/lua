//
//  GLLoader.mm
//  glelement
//
//  Created by zhang hailong on 14-6-19.
//  Copyright (c) 2014年 hailong.org. All rights reserved.
//

#include "GLImage.h"

#import <OpenGLES/ES2/gl.h>
#import <ImageIO/ImageIO.h>
#import "GLPVRTexture.h"

namespace cc {
    
    static GLImage * GLLoaderImageCreateFromPVRFilePath(NSString * filePath){
        
        GLPVRTexture * texture = [GLPVRTexture pvrTextureWithContentsOfFile:filePath];
        
        GLImage * img = nil;
        
        if(texture){
            
            img = new GLImage((int) texture.width, (int) texture.height,texture.name);
            
            texture.name = 0;
            
        }
        
        [texture release];
        
        return img;
    }
    
    GLImage * GLLoaderImageCreateFromFilePath(const char * filePath){
        
        NSString * path = [NSString stringWithCString:filePath encoding:NSUTF8StringEncoding];

        if([path hasSuffix:@".pvr"]){
            return GLLoaderImageCreateFromPVRFilePath(path);
        }
        
        GLImage * img = nil;
        
        CFURLRef url = CFURLCreateWithFileSystemPath(nil, (CFStringRef) path, kCFURLPOSIXPathStyle, NO);
        
        CGImageSourceRef source = CGImageSourceCreateWithURL(url, nil);
        
        if(CGImageSourceGetCount(source) ){
            
            CGImageRef image = CGImageSourceCreateImageAtIndex(source, 0, nil);
            
            size_t width = CGImageGetWidth(image);
            size_t height = CGImageGetHeight(image);
            
            CGColorSpaceRef rgbSpace = CGColorSpaceCreateDeviceRGB();
            
            CGContextRef ctx = CGBitmapContextCreate(NULL, width, height, 8, width * 4, rgbSpace, kCGImageAlphaPremultipliedLast);
            
            CGContextDrawImage(ctx, CGRectMake(0, 0, width, height), image);
            
            img = new GLImage((int) width, (int) height,CGBitmapContextGetData(ctx),GLImagePixelFormatRGBA);
            
            CGContextRelease(ctx);
            
            CGColorSpaceRelease(rgbSpace);
            
            CGImageRelease(image);
            
        }
        
        CFRelease(source);
        
        CFRelease(url);

        return img;
    }
    
}
