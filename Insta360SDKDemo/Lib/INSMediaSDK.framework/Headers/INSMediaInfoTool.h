//
//  INSMediaInfoTool.h
//  INSVideoPlayApp
//
//  Created by jerett on 16/1/21.
//  Copyright © 2016年 insta360. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreVideo/CVPixelBuffer.h>

@class INSVideoInfo;
@class UIImage;

@interface INSMediaInfoTool : NSObject

/**
 *
 *
 *  @param url 查询视频信息,并且获得offset。
 *
 *  @return 返回视频信息
 */
+(INSVideoInfo*)queryMediaVideoInfo:(NSURL*)url;


/**
 *
 *
 *  @param url 查询视频信息，并且截图
 *
 *  @return 返回视频信息
 */
+(INSVideoInfo*)queryMediaVideoInfo:(NSURL*)url AndScreenShotVideoAt:(double (^)(double totalDuration))timeBlock;

/**
 *  视频截图的方法
 *
 *  @param url  支持HTTP协议和FILE协议
 *  @param time 截图的时间，但实际的时间会因为视频的数据格式有所差距
 *
 *  @return 截图内容
 */
+(UIImage*)screenShotVideoToUIImage:(NSURL*)url at:(double)time;

/**
 *  视频截图的方法
 *
 *  @param url  支持HTTP协议和FILE协议
 *  @param time 截图的时间，但实际的时间会因为视频的数据格式有所差距
 *
 *  @return 截图内容
 */
+(CVImageBufferRef)screenShotVideoToCVImageBufferCreate:(NSURL*)url at:(double)time;

@end
