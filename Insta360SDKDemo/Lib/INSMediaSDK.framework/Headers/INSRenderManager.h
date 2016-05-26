//
//  INSRenderManager.h
//  INSVideoPlayApp
//
//  Created by pwx on 24/2/16.
//  Copyright © 2016年 insta360. All rights reserved.
//


#import <UIKit/UIKit.h>

@class INSRender;

@interface INSRenderManager : NSObject

@property (nonatomic) BOOL isGyro;                      //是否打开陀螺仪
@property (nonatomic, strong) INSRender *render;          //图形渲染器

//初始化函数
- (instancetype) initWithRender:(INSRender*)render;

//准备渲染
- (void) prepareRender;

//设置陀螺仪的开始方位
- (void) setGyroOrientation:(UIInterfaceOrientation)orientation;

//开始惯性滑动
- (void) startInertialRotationWithVelocityX:(float)Vx velocityY:(float)Vy;

//停止惯性滑动
- (void) stopInertialRotation;

//通过屏幕移动点的距离来旋转模型
- (void) rotateObjectModelWithScreenPointMoveDistanceX:(float)dx distanceY:(float)dy;

@end
