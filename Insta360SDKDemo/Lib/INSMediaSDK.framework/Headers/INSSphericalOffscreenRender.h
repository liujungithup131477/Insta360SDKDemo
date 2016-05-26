//
//  INSSphericalOffscreenRender.h
//  INSMediaApp
//
//  Created by pengwx on 4/14/16.
//  Copyright © 2016 Insta360. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <GLKit/GLKit.h>
#import "INSRenderType.h"

@class INSCamera;

/**
 球形离屏渲染器
 主要完成将输入图像渲染成在camera观察角度下的图像
 */

@interface INSSphericalOffscreenRender : NSObject

/**
 *  以自定义投影方式初始化
 *  @param customProjection 自定义投影观看视图的参数值
 *  @param color            背景颜色
 *  @param width            渲染生成的图片的宽度
 *  @param height           渲染生成的图片的高度
 *  @return 完成初始化后的INSSphericalOffscreenRender对象
 */
- (instancetype) initWithCustomViewProjection:(INSCustomProjection)customProjection backgroundColor:(GLKVector3)color width:(int)width height:(int)height;

/**
 *  以小行星投影方式初始化
 *  @param width  渲染生成的图片的宽度
 *  @param height 渲染生成的图片的高度
 *  @return 完成初始化后的INSSphericalOffscreenRender对象
 */
- (instancetype) initAsteroidWithWidth:(int)width height:(int)height;

/**
 *  以圆形方式初始化
 *  @param width  渲染生成的图片的宽度
 *  @param height 渲染生成的图片的高度
 *  @return 完成初始化后的INSSphericalOffscreenRender对象
 */
- (instancetype) initCenterCircleWithWidth:(int)width height:(int)height;

/**
 *  设置渲染生成图片的宽和高
 *  @param width  渲染生成的图片的宽度
 *  @param height 渲染生成的图片的高度
 */
- (void) setRenderWidth:(int)width height:(int)height;

/**
 *  使用已经拼接好的Flat图片来进行渲染
 *  @param image 原始图片，已经拼接好的全景图片
 *  @return 渲染生成的图片，渲染失败返回nil
 */
- (UIImage*) renderWithFlatUIImage:(UIImage*)image;

/**
 *  使用已经拼接好的Flat图像数据来进行渲染
 *  @param pixelBuffer 原始图像数据，已经拼接好的全景图片, YUV420格式
 *  @return 渲染生成的图片，渲染失败返回nil
 */
- (UIImage*) renderWithFlatPixelBuffer:(CVPixelBufferRef)pixelBuffer;

/**
 *  使用相机的双圆图片来进行渲染
 *  此时offset参数起作用
 *  @param image 原始双圆图片
 *  @return 渲染生成的图片，渲染失败返回nil
 */
- (UIImage*) renderWithPanoUIImage:(UIImage*)image;

/**
 *  使用相机的双圆图像数据来进行渲染
 *  此时offset参数起作用
 *  @param pixelBuffer pixelBuffer 原始图像数据，已经拼接好的全景图片, YUV420格式
 *  @return 渲染生成的图片，渲染失败返回nil
 */
- (UIImage*) renderWithPanoPixelBuffer:(CVPixelBufferRef)pixelBuffer;

/**
 *  使用相机的双圆图像数据来进行渲染
 *  此时offset参数起作用
 *  @param pixelBuffer 原始图像数据，已经拼接好的全景图片, YUV420格式
 *  @return 渲染生成的图像数据，RGBA格式，返回的图像数据需要手动释放内存, 渲染失败返回NULL,
 */
- (CVPixelBufferRef) renderAndCopyWithPanoPixelBuffer:(CVPixelBufferRef)pixelBuffer;

/**
 *  交换镜头位置   默认值：NO
 *  设置此参数为YES，会使相机的方向反向
 */
@property (nonatomic) BOOL swapOrientation;

@property (nonatomic, copy) NSString *offset;               //镜头offset值


@end
