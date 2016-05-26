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

- (IBAction)playImage:(id)sender {
    UIStoryboard *storyBoard = [UIStoryboard storyboardWithName:@"Main" bundle:nil];
    ARVPlayerVC *playerVC = [storyBoard instantiateViewControllerWithIdentifier:@"playerVC"];
    playerVC.isSourceVideo = NO;
    [self presentViewController:playerVC animated:YES completion:nil];
}

- (IBAction)playVideo:(id)sender {
    UIStoryboard *storyBoard = [UIStoryboard storyboardWithName:@"Main" bundle:nil];
    ARVPlayerVC *playerVC = [storyBoard instantiateViewControllerWithIdentifier:@"playerVC"];
    playerVC.isSourceVideo = YES;
    [self presentViewController:playerVC animated:YES completion:nil];
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

@end
