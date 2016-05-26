//
//  INSFlatOffscreenRender.h
//  INSVideoPlayApp
//
//  Created by pwx on 17/2/16.
//  Copyright © 2016年 insta360. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import <GLKit/GLKit.h>

@interface INSFlatOffscreenRender : NSObject


//初始化
- (instancetype) initWithRenderWidth:(int)width height:(int)height;

//设置渲染结果的宽和高
- (void) setRenderWidth:(int)width height:(int)height;

//渲染图片, 失败返回nil
- (UIImage*) renderImage:(UIImage *)image;
- (UIImage*) renderImageWithURL:(NSURL *)url;
- (UIImage*) renderImageWithCGImage:(CGImageRef)imageRef;

//渲染CVPixelBufferRef, 失败返回nil
- (UIImage*) renderVideo:(CVPixelBufferRef)pixelBuffer;

//渲染CVPixelBufferRef, 失败返回NULL
- (CVPixelBufferRef) createPixelBufferFramRenderVideo:(CVPixelBufferRef)pixelBuffer;


/**
 *  拼接offset参数值
 */
@property (nonatomic, copy) NSString *offset;

/**
 *  交换镜头位置   默认值：NO
 *  设置此参数为YES，会使渲染出来flat图像中间部分与两边的图像进行交换
 */
@property (nonatomic) BOOL swapLensPosition;

/**
 *  当值为YES时，会在渲染画面的下方加上logo
 */
@property (nonatomic) BOOL enableLogo;

/**
 *  logo使用的图片，当值为nil时，使用默认图片
 *  enableLogo为YES时，此属性才起作用
 */
@property (nonatomic, strong) UIImage *logoImage;

/**
 *  logo尺寸大小，默认值为35（相对于360度所占的度数比例）
 *  enableLogo为YES时，此属性才起作用
 */
@property (nonatomic) float logoSize;


@end
