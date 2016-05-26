//
//  ARVPlayerItem.h
//  ARVPlayerController
//
//  Created by RonanWhite on 3/2/16.
//  Copyright © 2016 Insta360. All rights reserved.
//

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

- (instancetype)initWithURL:(NSURL *)url offset:(NSString *)offset type:(ARVItemType)itemType;

@property (nonatomic, assign, readonly) ARVItemType itemType;
@property (nonatomic, strong, readonly) NSURL *itemURL;
@property (nonatomic, copy, readonly) NSString *itemOffset;

@end
