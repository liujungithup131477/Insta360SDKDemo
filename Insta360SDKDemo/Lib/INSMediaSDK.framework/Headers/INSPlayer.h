//
//
//  Created by jerett on 20/02/16.
//  Copyright © 2015年 insta360. All rights reserved.
//

#import <Foundation/Foundation.h>


@protocol INSPlayerProtocol;

typedef enum : NSUInteger {
  INSPlayerStatusUnknown,
  INSPlayerStatusPrepared,
  INSPlayerStatusPlaying,
  INSPlayerStatusBuffering,
  INSPlayerStatusPaused,
  INSPlayerStatusEnd,
  INSPlayerStatusFailed
} INSPlayerStatus;

@interface INSPlayer : NSObject <INSPlayerProtocol>

/**
 *  可以使用KVC进行状态观察
 */
@property (nonatomic, readonly) INSPlayerStatus status;

-(void)setDataSource:(NSURL*)URL;

-(void)prepare;

-(void)play;

-(void)seek:(double)position;

-(void)pause;

-(void)shutdown;

-(int64_t)currentPositionInMs;

-(int)getVideWidth;

-(int)getVideoHeight;

-(int64_t)getVideoDuration;

-(NSString*)getMetadata:(NSString*)key;

-(void)setOption:(NSString*)key value:(NSString*)val;

-(NSString*)getNanoOffset;

@end
