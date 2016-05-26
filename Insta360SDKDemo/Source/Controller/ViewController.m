//
//  ViewController.m
//  Insta360SDKDemo
//
//  Created by RonanWhite on 4/8/16.
//  Copyright © 2016 Insta360. All rights reserved.
//

#import "ViewController.h"
#import "ARVPlayerVC.h"

@interface ViewController ()

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view, typically from a nib.
}

/**
 *  播放图片
 */
- (IBAction)playImage:(id)sender {
    /** 从 storyBoard 获取 ARVPlayerVC*/
    UIStoryboard *storyBoard = [UIStoryboard storyboardWithName:@"Main" bundle:nil];
    ARVPlayerVC *playerVC = [storyBoard instantiateViewControllerWithIdentifier:@"playerVC"];
    /** 设置播放的条件*/
    playerVC.isSourceVideo = NO;
    /** 以模态视图的方式跳转到对应的 ARVPlayerVC 控制器*/
    [self presentViewController:playerVC animated:YES completion:nil];
}

/**
 *  播放视频
 */
- (IBAction)playVideo:(id)sender {
    /** 从 storyBoard 获取 ARVPlayerVC*/
    UIStoryboard *storyBoard = [UIStoryboard storyboardWithName:@"Main" bundle:nil];
    ARVPlayerVC *playerVC = [storyBoard instantiateViewControllerWithIdentifier:@"playerVC"];
    /** 设置播放的条件*/
    playerVC.isSourceVideo = YES;
    /** 以模态视图的方式跳转到对应的 ARVPlayerVC 控制器*/
    [self presentViewController:playerVC animated:YES completion:nil];
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

@end
