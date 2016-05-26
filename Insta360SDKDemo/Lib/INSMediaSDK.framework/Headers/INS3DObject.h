//
//  INS3DObject.h
//  INSVideoPlayApp
//
//  Created by pwx on 27/1/16.
//  Copyright © 2016年 insta360. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <GLKit/GLKit.h>

@class INSCamera;
@class INSGeometry;
@class INSMaterial;

@interface INS3DObject : NSObject
{
    GLKMatrix4 _tModelView;
    GLKMatrix4 _modelViewMat;
    INSGeometry *_geometry;
}


@property (nonatomic) GLKVector3 position;
@property (nonatomic) GLKVector3 scale;

@property (nonatomic) GLKVector3 eulerAngle;                        //欧拉角
@property (nonatomic) GLKQuaternion orientation;                    //方向
@property (nonatomic) GLKMatrix4 modelMat4;                         //模型矩阵


@property (nonatomic) GLenum frontFace;                             //
@property (nonatomic, strong) INSMaterial *material;                //材料
@property (nonatomic, strong) INSGeometry *geometry;                //几何体

@property (nonatomic, strong, readonly) NSMutableArray *objects;                 //3D模型

//清理
- (void) clean;

//添加3D物体
- (void) addChild:(INS3DObject*)child;

//移除3D物体
- (void) removeChild:(INS3DObject*)child;

//渲染
- (void) renderWithCamera:(INSCamera*)camera projectMat:(GLKMatrix4*)pProjectMat ViewMat:(GLKMatrix4*)pViewMat parentMat:(GLKMatrix4*)pParentMat;

@end
