//
//  INSTimer.h
//  DebugApp
//
//  Created by jerett on 15/11/28.
//  Copyright © 2015年 insta360. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface INSTimer : NSObject

-(instancetype)init;

/**
 *  重置计时器，所有数据归0
 */
-(void)reset;

/**
 *  计时器已经经过的时间，返回秒
 *
 *  @return 启动后经过的秒
 */
-(double)pass;

/**
 *  停止计时
 */
-(void)pause;

/**
 *  从暂停后继续，开始时间为上次停止的时间
 */
-(void)moveOn;

@end
