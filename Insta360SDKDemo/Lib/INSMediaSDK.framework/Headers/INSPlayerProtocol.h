//
//  INSVideoDemux.h
//  DebugApp
//
//  Created by pwx on 25/11/15.
//  Copyright © 2015年 insta360. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <CoreVideo/CVPixelBuffer.h>


@protocol INSPlayerProtocol <NSObject>

@required

//函数功能：复制下一帧图像
//返回值：VPixelBufferRef 图像数据格式为YUV420
//说明：1. 播放器实现此函数时，应该处理时间戳与帧率的问题，当播放的帧数据还未准备好时，此函数被调用，可以返回NULL，当播放数据准备好时，返回视频帧数据
//     2. 函数内部应保证CVPixelBufferRef的有效性，即调用 CVPixelBufferRetain(), 调用此函数的对象负责此CVPixelBufferRef的释放 即调用CVPixelBufferRelease()
- (CVPixelBufferRef) copyNextFrame;

@end

