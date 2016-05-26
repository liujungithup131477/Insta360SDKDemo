//
//  INSLens.h
//  INSVideoPlayApp
//
//  Created by pwx on 7/12/15.
//  Copyright © 2015年 insta360. All rights reserved.
//

#import <Foundation/Foundation.h>
#include <GLKit/GLKMatrix4.h>

typedef enum INSLensType
{
    INSLensType_None,
    INSLensType_B,
    INSLensType_C,
    
} INSLensType;

@interface INSLens : NSObject

@property (nonatomic, assign) float centerX;
@property (nonatomic, assign) float centerY;
@property (nonatomic, assign) float centerR;
@property (nonatomic, assign) float yaw;
@property (nonatomic, assign) float pitch;
@property (nonatomic, assign) float roll;
@property (nonatomic, assign) int fov;
@property (nonatomic, assign) int originW;
@property (nonatomic, assign) int originH;
@property (nonatomic, assign) INSLensType type;

//计算高度
- (double) calHeight:(double) angle;

//获取矩阵
- (GLKMatrix4) getLensMatrix;

@end
