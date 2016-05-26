//
//  INSRenderType.h
//  INSMediaApp
//
//  Created by pengwx on 5/10/16.
//  Copyright © 2016 Insta360. All rights reserved.
//

#import <Foundation/Foundation.h>



//画面交互模式
typedef enum
{
    INSViewInteractiveModeFinger,                   //手指拖动模式
    INSViewInteractiveModeGyro,                     //陀螺仪模式
} INSViewInteractiveMode;

//画面展示方式
typedef enum
{
    INSViewPresentModeSingle,                       //单屏模式
    INSViewPresentModeWidthDirectionDuplicate,      //宽度方向双屏
    INSViewPresentModeHeightDirectionDuplicate,     //高度方向双屏
} INSViewPresentMode;

//视图投影观看方式
typedef enum
{
    INSViewProjectionModeFisheye,                   //鱼眼模式
    INSViewProjectionModeAsteroid,                  //小行星模式
    INSViewProjectionModePerspective,               //透视投影模式
    INSViewProjectionModeCustom,                    //自定义模式，     此模式需要需要设置自定义视图投影观看方式的参数值才能够使用
} INSViewProjectionMode;

//渲染器类型
typedef enum
{
    INSRenderTypePreview,                           //相机预览流渲染器, 对应渲染器类型INSPreviewRender
    INSRenderTypeSphericalRender,                   //普通全景渲染器(已经展开为flat,mp4,jpg格式), 对应渲染器类型INSSphericalRender
    INSRenderTypeSphericalPanoRender,               //双圆全景渲染器(insv,insp格式)，对应渲染器类型INSSphericalPanoRender
    INSRenderTypeFlatPanoRender,                    //flat全景展开渲染器(insv,insp格式), 对应渲染器类型INSFlatPanoRender
    INSRenderTypeSphericalParallaxRender,           //3D 180渲染器(insv,insp格式), 对应渲染器类型INSSphericalParallaxRender
    INSRenderTypeParallaxPanoRender,                //3D 360全景渲染器(已经展开为上下两个flat,mp4,jpg格式), 对应渲染器类型INSParallaxPanoRender
} INSRenderType;

//自定义视图投影观看方式
typedef struct
{
    float yFov;                 //Y向Fov        单位：弧度
    float cameraMove;           //相机离球心距离
    float rotationX;            //X方向偏转角度   单位：弧度
    float rotationY;            //Y方向偏转角度   单位：弧度
    float rotationZ;            //Z方向偏转角度   单位：弧度
} INSCustomProjection;