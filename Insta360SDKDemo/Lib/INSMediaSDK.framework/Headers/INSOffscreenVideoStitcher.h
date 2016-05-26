//
//  INSOffscreenVideoStitcher.h
//  INSVideoPlayApp
//
//  Created by jerett on 15/12/21.
//  Copyright © 2015年 insta360. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef enum : NSUInteger {
    /**
     *  stitcher可以进行转码操作
     */
    INSStitcherStatusReadyToStitch,
    /**
     *  stitcher在合成中
     */
    INSStitcherStatusOnStitching,
    /**
     *  stitcher状态失败
     */
    INSStitcherStatusFailed,
} INSStitcherStatus;


typedef enum : NSUInteger {
    INSStitcherErrorInputFileNoExist,
    INSStitcherErrorDemux,
    INSStitcherErrorOpenEncoder,
    INSStitcherErrorWriteOutput,
} INSStitcherErrorCode;

@interface INSOffscreenVideoStitcher : NSObject

/**
 *  返回当前进度，范围在0.0-1.0
 */
@property (readonly, nonatomic) double currentProgress;

/**
 *  stitcher当前状态，可以使用kvc进行观察
 */
@property (readonly, nonatomic) INSStitcherStatus status;

/**
 *  当Stitcher状态在Failed是，返回相关错误描述
 */
@property (readonly, strong, nonatomic) NSError* error;
/**
 *  构造OffscreenVideoStitcher
 *
 *  @param inputUrl  原视频地址，目前支持mp4协议
 *  @param width     要转出的视频的宽度
 *  @param height    要转出的视频的高度，宽高比最好2:1
 *  @param bitrate   转出视频的码率
 *  @param metadata  要写入视频的metaData,key和value都要求为NSString
 *  @param outputUrl 转出视频的地址,目前支持mp4协议，如果地址已经存在文件将会覆盖
 *
 *  @return OffscreenVideoStitcher实例,参数不合法返回nil
 */
-(instancetype)initWithInputUrl:(NSURL*)inputUrl offset:(NSString*)offset stitchWidth:(int)width stitchHeight:(int)height bitrate:(int)bitrate metadata:(NSDictionary*)metadata outputURL:(NSURL*)outputUrl;


/**
 *  访问此变量，必须状态在INSStitcherStatusOnStitching状态下，否则返回0
 *  得到预估的文件大小, 必须在开启固定文件大小模式的时候使用。
 *  在需要预先固定转出的文件大小的场景，可以使用此文件大小，但是最后必须在stitch完成后进行文件大小校验，如果不一样，则说明预测失败。
 *  通常预测能够成功。
 *  @return 估计的文件大小
 */
@property (nonatomic, readonly) uint64_t estimateMp4Size;

/**
 *  重置拼接器，重新配置参数
 *
 *  @param inputUrl  原视频地址，目前支持mp4协议，视频不存在返回NO
 *  @param width     要转出的视频的宽度
 *  @param height    要转出的视频的高度，宽高比最好2:1
 *  @param bitrate   转出视频的码率
 *  @param metadata  要写入视频的metaData,key和value都要求为NSString
 *  @param outputUrl 转出视频的地址，目前支持mp4协议，如果地址已经存在文件将会覆盖
 *  @return 返回设置是否成功
 */
-(BOOL)reset:(NSURL*)inputUrl offset:(NSString*)offset stitchWidth:(int)width stitchHeight:(int)height bitrate:(int)bitrate metadata:(NSDictionary*)metadata outputURL:(NSURL*)outputUrl;

/**
 *  开始进行视频拼接转码,会堵塞当前调用线程,结束后返回;
 *  如果状态没有ready，立刻返回
 *
 *  @param fixSize 指定是否提前固定文件大小，可以通过getEstimateOutputFileSize得到文件大小。如果没有特别需要，不建议使用此模式，会造成冗余数据。
 */
-(void)stitch:(BOOL)fixSize;

/**
 *  在stitch时候，每隔指定的进度，回调指定的代码快;progress范围在0.0-1.0内
 *
 *  @param interval 进度间隔，范围在0.0-1.0
 *  @param queue    代码块指定的串行队列，传入并行队列会导致未定义行为
 *  @param block    提交的代码快
 *
 *  @return 返回句柄，用来移除observer
 */
-(id)addPeriodicProgressObserverForInterval:(double)interval queue:(dispatch_queue_t)queue usingBlock:(void(^)(double progress))block;

/**
 *  移除进度观察
 *
 *  @param handle 从addPeriodicProgressObserverForInterval获得的句柄;
 */
-(void)removeProgressObserver:(id)handle;

/**
 *  请求停止拼接 将会保存已经转码的视频
 *  @param completeCallback 完成后回调
 */
-(BOOL)requestStopWithCompleteCallback:(void(^)())completeCallback;


@end
