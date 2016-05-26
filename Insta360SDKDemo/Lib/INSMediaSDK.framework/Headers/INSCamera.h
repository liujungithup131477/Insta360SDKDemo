//
//  INSCamera.h
//  INSVideoPlayApp
//
//  Created by pwx on 14/1/16.
//  Copyright © 2016年 insta360. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <GLKit/GLKit.h>

@interface INSCamera : NSObject


- (instancetype) initWithOrthoLeft:(float)left right:(float)right bottom:(float)bottom top:(float)top nearZ:(float)nearZ farZ:(float)farZ;

- (instancetype) initWithPerspectiveYFov:(float) yFov aspect:(float)aspect nearZ:(float)nearZ farZ:(float)farZ;


//projection 矩阵参数
@property (nonatomic) float xFov;
@property (nonatomic) float yFov;
@property (nonatomic) float zNear;
@property (nonatomic) float zFar;
@property (nonatomic) float aspect;                                 //  值：宽/高
@property (nonatomic) GLKMatrix4 projectionMat4;            //投影矩阵


//view 矩阵参数
@property (nonatomic) GLKVector3 eye;                               //默认值：(0, 0, 0)         鱼眼设置第三个值,即eye.z
@property (nonatomic) GLKVector3 center;                            //默认值：(0, 0, -1)
@property (nonatomic) GLKVector3 up;                                //默认值：(0, 1, 0)
@property (nonatomic) GLKMatrix4 viewMat4;                  //视图矩阵


@end
