//
//  ARVPlayerItem.h
//  ARVPlayerController
//
//  Created by RonanWhite on 3/2/16.
//  Copyright © 2016 Insta360. All rights reserved.
//

// MARK: - 播放单个视频文件类

#import <Foundation/Foundation.h>
#import <INSMediaSDK/INSMediaSDK.h>


//数据类型
typedef enum:NSInteger
{
    ARVItemTypeUnknown = 0,      //选择此类型时，会自动校验URL是否合法
    ARVItemTypeImage = 1,       //图片
    ARVItemTypeVideo,            //视频
}ARVItemType;

@interface ARVPlayerItem : NSObject
/**
 *  初始化控制器，创建播放单个视频文件的播放控制器
 */
- (instancetype)initWithURL:(NSURL *)url offset:(NSString *)offset type:(ARVItemType)itemType;

/** 播放文件源的数据类型*/
@property (nonatomic, assign, readonly) ARVItemType itemType;
/** 播放文件源的路径*/
@property (nonatomic, strong, readonly) NSURL *itemURL;
/** 视频文件播放的偏移量*/
@property (nonatomic, copy, readonly) NSString *itemOffset;

@end
