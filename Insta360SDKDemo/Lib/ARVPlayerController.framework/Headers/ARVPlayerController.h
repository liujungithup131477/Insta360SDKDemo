//
//  ARVPlayerController.h
//  ARVPlayerController
//
//  Created by RonanWhite on 3/2/16.
//  Copyright © 2016 Insta360. All rights reserved.
//

#import "ARVPlayerItem.h"
#import "ARVNPlayerUtils.h"
#import <Foundation/Foundation.h>

typedef NS_ENUM(NSInteger, ARVPlayRepeatMode) {
    ARVPlayRepeatModeCycleNone,//default
    ARVPlayRepeatModeCycleSingle,
    ARVPlayRepeatModeCycleAll
};

@protocol ARVPlayerStatusDelegate <NSObject>

- (void)updateCurrentTime:(double)time;
- (void)playerStatusChanged:(INSPlayerStatus)status;
@end

@interface ARVPlayerController : NSObject

- (instancetype)initWithFrame:(CGRect)frame renderType:(INSRenderType)type;
- (instancetype)initWithFrame:(CGRect)frame item:(ARVPlayerItem *)item renderType:(INSRenderType)type;
- (instancetype)initWithFrame:(CGRect)frame playList:(NSArray<ARVPlayerItem*> *)list renderType:(INSRenderType)type;

@property (nonatomic, strong) INSRenderView *playerView;
@property (nonatomic, strong) ARVPlayerItem *currentItem;

@property (nonatomic, readonly) double duration;

@property (nonatomic) BOOL shuffle;
@property (nonatomic) ARVPlayRepeatMode repeatMode;

@property (nonatomic, weak) id<ARVPlayerStatusDelegate> delegate;

//设置缓冲，必须在play之前设置, 单位byte
- (void)setMiniumBufferSize:(long)size;//设置缓冲区最小大小，一旦小于这个值，会进行缓冲
- (void)setMaxiumBufferSize:(long)size;//缓冲区最大值，建议不超过10M
- (void)setBufferSizeForPerPiece:(long)size;//设置缓冲会缓冲的大小

- (void)prepare;
- (void)play;
- (void)pause;
- (void)stop;
- (void)seekToTime:(double)time;
- (void)setHttpOnLanMode:(BOOL)lanMode;//局域网播放视频时，设置YES实现低延迟
- (void)replaceCurrentItemWithItem:(ARVPlayerItem *)item;//切换文件

- (void)movePrevious;
- (void)moveNext;
@end
