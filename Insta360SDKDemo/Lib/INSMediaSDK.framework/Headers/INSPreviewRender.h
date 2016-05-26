//
//  INSPreviewRender.h
//  INSVideoPlayApp
//
//  Created by pwx on 28/2/16.
//  Copyright © 2016年 insta360. All rights reserved.
//


#import "INSRender.h"


typedef enum {
    INSFloatingTypeNone,            //无浮窗
    INSFloatingTypeSphereBackLens,  //以球体渲染，观看角度为后镜头
    INSFloatingTypeFlatPano,        //平面展开全景
} INSFloatingType;




@class INSScene;

@interface INSPreviewRender : INSRender

/**
 *  浮动窗口类型
 */
@property (nonatomic) INSFloatingType floatingType;

/**
 *  浮动窗口大小
    origin的坐标体系以屏幕左上角为原点，向右为X正向，向下为Y正向
    size大小以像素点为单位, 当属性floatingType为INSFloatingTypeFlatPano时，size的width和height的比例是2:1
    当floatingType为INSFloatingTypeNone时，此参数不起作用
 */
@property (nonatomic) CGRect floatingFrame;

/**
 *  主视图下方视图高度，以像素为单位
    其值应该不小于10，否则不予渲染此窗口
 */
@property (nonatomic) int downViewHeight;

/**
 *  主窗口渲染场景
 */
@property (nonatomic, strong) INSScene *scene;


@end
