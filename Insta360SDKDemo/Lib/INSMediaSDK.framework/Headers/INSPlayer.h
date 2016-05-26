//
//
//  Created by jerett on 20/02/16.
//  Copyright © 2015年 insta360. All rights reserved.
//

#import <Foundation/Foundation.h>


@protocol INSPlayerProtocol;

/**
 *  播放状态
 */
typedef enum : NSUInteger {
  INSPlayerStatusUnknown,  /** 未知状态*/
  INSPlayerStatusPrepared,  /** 准备*/
  INSPlayerStatusPlaying,  /** 播放*/
  INSPlayerStatusBuffering,  /** 缓冲*/
  INSPlayerStatusPaused,  /** 暂停*/
  INSPlayerStatusEnd,  /** 完成*/
  INSPlayerStatusFailed  /** 失败*/
} INSPlayerStatus;

@interface INSPlayer : NSObject <INSPlayerProtocol>

/**
 *  播放的状态
 *  可以使用KVC进行状态观察
 */
@property (nonatomic, readonly) INSPlayerStatus status;

/**
 *  设置播放器的数据源
 *
 *  @param URL 播放器数据源的资源路径
 */
-(void)setDataSource:(NSURL*)URL;

/**
 *  准备
 */
-(void)prepare;

/**
 *  播放
 */
-(void)play;

/**
 *  设置播放的位置
 */
-(void)seek:(double)position;

/**
 *  暂停
 */
-(void)pause;

/**
 *  关闭
 */
-(void)shutdown;

-(int64_t)currentPositionInMs;

-(int)getVideWidth;

-(int)getVideoHeight;

-(int64_t)getVideoDuration;

-(NSString*)getMetadata:(NSString*)key;

-(void)setOption:(NSString*)key value:(NSString*)val;

-(NSString*)getNanoOffset;

@end
