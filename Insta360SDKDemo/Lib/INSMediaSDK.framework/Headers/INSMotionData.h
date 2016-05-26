//
//  INSMotionData.h
//  INSMediaApp
//
//  Created by pengwx on 5/16/16.
//  Copyright © 2016 Insta360. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreMotion/CoreMotion.h>
#import <GLKit/GLKit.h>


//陀螺仪数据
typedef struct
{
    float ax;
    float ay;
    float az;
    float gx;
    float gy;
    float gz;
} INSMediaGyroData;

/**
 *  获取重力加速度数据
 *  @param gyro 陀螺仪数据
 *  @return 重力加速度数据
 */
//GLKVector3 INSMediaGyroDataToGravity(INSMediaGyroData gyro);
static inline GLKVector3 INSMediaGyroDataToGravity(INSMediaGyroData gyro)
{
    return GLKVector3Make(gyro.gx, gyro.gy, gyro.gz);
}

/**
 *  将系统的CMDeviceMotion数据转为自定义的INSMediaGyroData数据
 *  @param CMDeviceMotion 系统motion数据
 *  @return 转换后的INSMediaGyroData数据
 */
INSMediaGyroData INSMediaGyroDataFromCMDeviceMotion(CMDeviceMotion* motionData);


/**
 *  将陀螺仪数据转换为四元数
 *  @param gyro 陀螺仪数据
 *  @return 四元数
 */
GLKQuaternion INSMediaGyroDataToGLKQuaternion(INSMediaGyroData gyro);



