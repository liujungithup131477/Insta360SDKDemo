//
//  INSBClientOffsetTool.h
//  INSVideoPlayApp
//
//  Created by jerett on 15/12/8.
//  Copyright © 2015年 insta360. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <ImageIO/ImageIO.h>

@interface INSBClientOffsetTool : NSObject

/**
 *  判断offset是否有效
 *
 *  @param offset offset
 *
 *  @return 是否有效
 */
+(BOOL)isValidOffset:(NSString*)offset;

/**
 *  获取视频的offset，支持http和file协议，以后根据需求可以提供rtmp和rtsp等流氏协议的支持
 *
 *  @param videoUrl 视频地址
 *
 *  @return 视频的拼接参数
 */
+(NSString*)queryVideoOffset:(NSURL*)videoUrl;

/**
 *  获取jpeg图片的拼接参数，支持http和file协议
 *
 *  @param imgUrl 图片地址
 *
 *  @return 视频拼接参数
 */
+(NSString*)queryImgOffset:(NSURL*)imgUrl;

/**
 *  获取jpeg图片的拼接参数
 *
 *  @param data 图片数据
 *
 *  @return 视频拼接参数
 */
+(NSString*)queryImgOffsetWithData:(NSData*)data;


+(NSString*)getVideoOffsetWithDemux:(void*)context;

@end
