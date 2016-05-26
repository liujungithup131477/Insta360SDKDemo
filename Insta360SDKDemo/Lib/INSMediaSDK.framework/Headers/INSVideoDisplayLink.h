//
//  INSVideoDisplayLink.h
//  DebugApp
//
//  Created by pwx on 26/11/15.
//  Copyright © 2015年 insta360. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "QuartzCore/CADisplayLink.h"

typedef void (^INSVideoDisplayBlock)();

@interface INSVideoDisplayLink : NSObject

@property(nonatomic, strong) CADisplayLink *displayLink;                  //显示
@property(nonatomic, copy) INSVideoDisplayBlock displayBlock;


- (instancetype)initWithDisplayBlock:(INSVideoDisplayBlock)block;

- (void)removeDisplayLinkFromRunLoop;

@end
