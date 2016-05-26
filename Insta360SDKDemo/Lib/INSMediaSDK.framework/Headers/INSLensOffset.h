//
//  INSLensOffset.h
//  INSVideoPlayApp
//
//  Created by pwx on 7/12/15.
//  Copyright © 2015年 insta360. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface INSLensOffset : NSObject

- (instancetype) initWithOffset:(NSString*)offset;

//获取镜头
- (NSArray*) getLens;

@property (nonatomic) BOOL isValid;                     //判断镜头是否有效
@property (nonatomic, assign) int fisheyeClipAngle;     //镜头融合使用的剪切角
@property (nonatomic, assign) int lenVersion;           //镜头版本信息
@property (nonatomic, assign) int offsetVersion;        //offset版本信息


/**
 *  监测offset是否有效
 *  @param offset 相机offset
 *  @return 有效offset返回YES，无效返回NO
 */
+ (BOOL) isValidOffset:(NSString*)offset;

@end

