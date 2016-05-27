//
//  ARVPlayerController.h
//  ARVPlayerController
//
//  Created by RonanWhite on 3/2/16.
//  Copyright © 2016 Insta360. All rights reserved.
//

/**
 *  ARVPlayerController -- 播放器类
 *  作用：可以只处理一个文件，也可以处理多个文件（数组方式），还可以通过代理获取播放器当前的状态。
 *
 *  ARVPlayerItem -- 单个源文件信息类
 *  作用：用来处理对应的单个源文件的基本信息
 *
 *  ARVNPlayerUtils
 *  作用：如果 ARVPlayerController 类中包含的 ARVPlayerItem 类（多个数据源组成）,用来确定播放器当前要播放的源文件 ARVPlayerItem 的位置以offset 的方式确定，默认 nil 从头开始播放。
 */
#import "ARVPlayerItem.h"
#import "ARVNPlayerUtils.h"
#import <Foundation/Foundation.h>

/** 循环模式*/
typedef NS_ENUM(NSInteger, ARVPlayRepeatMode) {
    ARVPlayRepeatModeCycleNone,//default
    ARVPlayRepeatModeCycleSingle,//单循环
    ARVPlayRepeatModeCycleAll //所有文件循环
};

/**
 *  播放器代理协议
 */
@protocol ARVPlayerStatusDelegate <NSObject>

/**
 *  根据传入的时间更新进度条和时间显示框的值
 *
 *  @param time 时间值
 */
- (void)updateCurrentTime:(double)time;
/**
 *  转变播放器的播放状态
 *
 *  @param status 播放状态
 */
- (void)playerStatusChanged:(INSPlayerStatus)status;
@end

@interface ARVPlayerController : NSObject
/**
 *  创建播放器控制器
 *
 *  @param frame 播放器控制器的 frame
 *  @param type  渲染器类型
 *
 *  @return 返回播放器控制器
 */
- (instancetype)initWithFrame:(CGRect)frame renderType:(INSRenderType)type;
/**
 *  创建有单个文件源的播放器
 *
 *  @param frame 播放器控制器的 frame
 *  @param item  文件源类
 *  @param type  渲染器类型
 *
 *  @return 返回播放器控制器
 */
- (instancetype)initWithFrame:(CGRect)frame item:(ARVPlayerItem *)item renderType:(INSRenderType)type;
/**
 *  创建有多个文件源的播放器
 *
 *  @param frame 播放器控制器的 frame
 *  @param list  文件源类的数组
 *  @param type  渲染器类型
 *
 *  @return 返回播放器控制器
 */
- (instancetype)initWithFrame:(CGRect)frame playList:(NSArray<ARVPlayerItem*> *)list renderType:(INSRenderType)type;

/** 渲染视图*/
@property (nonatomic, strong) INSRenderView *playerView;
/** 当前的播放源文件*/
@property (nonatomic, strong) ARVPlayerItem *currentItem;

/** 持续时间*/
@property (nonatomic, readonly) double duration;
//TODO: - shuffle
@property (nonatomic) BOOL shuffle;
/** 循环模式*/
@property (nonatomic) ARVPlayRepeatMode repeatMode;

/** 播放器状态代理对象*/
@property (nonatomic, weak) id<ARVPlayerStatusDelegate> delegate;

/**
 *  设置缓冲，必须在play之前设置, 单位byte
 *  设置缓冲区最小大小，一旦小于这个值，会进行缓冲
 */
- (void)setMiniumBufferSize:(long)size;
/**
 *  设置缓冲，必须在play之前设置, 单位byte
 *  缓冲区最大值，建议不超过10M
 */
- (void)setMaxiumBufferSize:(long)size;
/**
 *  设置缓冲，必须在play之前设置, 单位byte
 *  设置缓冲会缓冲的大小
 */
- (void)setBufferSizeForPerPiece:(long)size;

/**
 *  使播放器进入准备状态
 */
- (void)prepare;
/**
 *  使播放器进入播放状态
 *  play前，必须先调用prepare
 */
- (void)play;
/**
 *  使播放器进入暂停状态
 */
- (void)pause;
/**
 *  使播放器进入停止状态
 */
- (void)stop;
//TODO: - 有待深究
- (void)seekToTime:(double)time;
/**
 *  局域网播放视频时，设置YES实现低延迟
 */
- (void)setHttpOnLanMode:(BOOL)lanMode;
/**
 *  初始化后，替换当前资源，切换资源
 */
- (void)replaceCurrentItemWithItem:(ARVPlayerItem *)item;//切换文件

/**
 *  切换到前一个文件
 */
- (void)movePrevious;
/**
 *  切换到后一个文件
 */
- (void)moveNext;
@end
