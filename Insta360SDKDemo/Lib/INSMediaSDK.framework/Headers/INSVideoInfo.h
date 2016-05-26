//
//  INSVideoInfo.h
//  INSVideoPlayApp
//
//  Created by jerett on 15/12/3.
//  Copyright © 2015年 insta360. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIImage.h>

@interface INSVideoInfo : NSObject

-(instancetype)initWithFrameRate:(double)framerate duration:(double)duration width:(int)width height:(int)height;

@property (nonatomic, readonly) double frameRate;
@property (nonatomic, readonly) double duration;
@property (nonatomic, readonly) int width;
@property (nonatomic, readonly) int height;
@property (nonatomic, strong, readwrite) NSString *offset;
@property (nonatomic, strong, readwrite) UIImage *screenShotImage;

@end
