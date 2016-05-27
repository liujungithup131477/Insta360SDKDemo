//
//  ARVNPlayerUtils.h
//  Insta360Camera
//
//  Created by semny on 15/12/27.
//  Copyright © 2015年 insta360. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import <INSMediaSDK/INSMediaSDK.h>

/**
 *  根据给定的条件找到对应的源文件将要从什么地方开始播放
 */
@interface ARVNPlayerUtils : NSObject

/**
 *  根据视频地址解析视频的offset(兼容B&C端视频)
 *
 *  @param videoURL 视频资源地址
 *
 *  @return offset
 */
+ (NSString *)getVideoOffsetBy:(NSURL *)videoURL;

/**
 *  根据图片地址解析视频的offset(兼容B&C端视频)
 *
 *  @param imageURL 视频资源地址
 *
 *  @return offset
 */
+ (NSString *)getImageOffsetBy:(NSURL *)imageURL;

/**
 *  根据图片资源解析视频的offset(兼容B&C端视频)
 *
 *  @param imageData 图片资源
 *
 *  @return offset
 */
+ (NSString *)getImageOffsetByData:(NSData *)imageData;

/**
 *  根据图片地址解析视频的offset(兼容B&C端视频)
 *
 *  @param imageURL 图片资源地址
 *  @param offsetBlock offset获取后的回调
 */
+ (void)asyncImageOffsetBy:(NSURL *)imageURL offsetBlock:(void (^)(NSString *offset))offsetBlock;

/**
 *  根据图片地址解析视频的offset并且返回image(兼容B&C端视频)
 *
 *  @param imageURL 图片资源地址
 *  @param resultBlock 获取后的结果回调
 */
+ (void)asyncImageInfoBy:(NSURL *)imageURL resultBlock:(void (^) (UIImage *image, NSString *offset))resultBlock;

/**
 *  根据视频地址解析视频的offset(兼容B&C端视频)
 *
 *  @param videoURL 视频资源地址
 *  @param offsetBlock offset获取后的回调
 */
+ (void)asyncVideoOffsetBy:(NSURL *)videoURL offsetBlock:(void (^)(NSString *offset))offsetBlock;

/**
 *  根据视频地址解析视频的缩略图
 *
 *  @param videoURL 视频地址
 *
 *  @return 缩略图
 */
+ (UIImage *)getPreviewImageBy:(NSURL *)videoURL;

/**
 *  判断offset是否有效
 *
 *  @param offset offset字符串
 *
 *  @return YES：有效；NO：无效；
 */
+ (BOOL)isAvailableWithOffset:(NSString *)offset;


/**
 *  根据图片判断尺寸是否正常
 *
 *  @param videoURL url地址
 *
 *  @return YES：有效；NO：无效；
 **/
+ (BOOL)isAvailableImageSizeWithImage:(UIImage *)image;
/**
 *  判断尺寸是否正常
 *
 *  @param videoURL url地址
 *
 *  @return YES：有效；NO：无效；
 */
+ (BOOL)isAvailableVideoSizeWithURL:(NSURL *)videoURL;

/**
 *  判断图片尺寸是否正常
 *
 *  @param videoURL url地址
 *
 *  @return  YES：有效；NO：无效；
 */
+ (BOOL)isAvailableImageSizeWithURL:(NSURL *)videoURL;

@end
