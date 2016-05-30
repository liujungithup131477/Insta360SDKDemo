//
//  INSVideoInfo.h
//  INSVideoPlayApp
//
//  Created by jerett on 15/12/3.
//  Copyright © 2015年 insta360. All rights reserved.
//

/**
 *  视频的基本信息
 */
#import <Foundation/Foundation.h>
#import <UIKit/UIImage.h>

@interface INSVideoInfo : NSObject

-(instancetype)initWithFrameRate:(double)framerate duration:(double)duration width:(int)width height:(int)height;

/**
 *   帧速率
 */
@property (nonatomic, readonly) double frameRate;
/**
 *  视频持续的时间
 */
@property (nonatomic, readonly) double duration;
/**
 *  宽度
 */
@property (nonatomic, readonly) int width;
/**
 *  高度
 */
@property (nonatomic, readonly) int height;
/**
 *  偏移量
 */
@property (nonatomic, strong, readwrite) NSString *offset;
/**
 *  截屏图片
 */
@property (nonatomic, strong, readwrite) UIImage *screenShotImage;

@end
