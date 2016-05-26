//
//  INSRender.h
//  INSVideoPlayApp
//
//  Created by pwx on 20/2/16.
//  Copyright © 2016年 insta360. All rights reserved.
//

#import <UIKit/UIKit.h>

@class INSCamera;
@class INS3DObject;
@class INSRenderManager;
@class INSFilter;
@class INSRenderTarget;



@interface INSRender : NSObject
{
}


//初始化一个配置好参数的CAEAGLLayer
+ (CAEAGLLayer*) initRenderLayerWithFrame:(CGRect)frame;

//初始化一个渲染器
- (instancetype) initWithRenderWidth:(int)width renderHeight:(int)height drawable:(id<EAGLDrawable>)drawable;

@property (nonatomic, readonly) int width;                  //渲染图形宽
@property (nonatomic, readonly) int height;                 //渲染图形高

@property (nonatomic) BOOL isDuplicate;                     //是否为双屏               默认：NO
@property (nonatomic) BOOL isDuplicateWidth;                //是否宽度方向双屏          默认：NO
@property (nonatomic) BOOL enableLogo;                      //是否展示logo图片          默认：NO
@property (nonatomic) float logoSize;                       //logo图片大小              默认：35
@property (nonatomic, strong) UIImage *logoImage;           //logo图片

@property (nonatomic, copy) NSString *offset;               //镜头offset值
@property (nonatomic, strong) INSCamera *camera;            //相机
@property (nonatomic, strong) INS3DObject *object3D;        //3D模型
@property (nonatomic, strong) EAGLContext *glContext;       //gl上下文
@property (nonatomic, weak) id<EAGLDrawable> drawable;      //EAGLDrawable协议

@property (nonatomic, strong, readonly) INSRenderTarget *drawableRenderTarget;     //drawable渲染target

/**
 *  获取渲染场景锁, 跟函数sceneUnlock成对使用
 */
- (void) sceneLock;

/**
 *  释放渲染场景锁, 跟函数sceneLock成对使用
 */
- (void) sceneUnlock;

/**
 *  当前渲染结果的画面快照
 *  @param block 用作返回快照图片，block是在GCD的全局队列中调用返回的
 */
- (void) snapshot:(void(^)(UIImage *image))block;

//添加滤镜
- (void) addFilter:(INSFilter*)filter;

//移除滤镜
- (void) removeFilter:(INSFilter*)filter;

//移除所有滤镜
- (void) removeAllFilters;

//设置渲染场景
- (void) setScenes:(NSArray*)scenes;

//更新渲染场景
- (void) updateScene;

//更新logo
- (void) updateLogo;

//设置渲染宽、高，   width、height必须与drawable的属性对应的图层大小相匹配，否则可能出现设置失败
- (void) setRenderWidth:(int)width renderHeight:(int)height;

//渲染视频帧（YUV图像数据）
- (void) renderPixelBuffer:(CVPixelBufferRef)pixelBuffer;

//渲染图片
- (void) renderImage:(UIImage *)image;

//执行渲染操作
- (void) onRender;


@end
