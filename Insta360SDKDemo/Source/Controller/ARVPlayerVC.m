//
//  ARVPlayerVC.m
//  Insta360SDKDemo
//
//  Created by RonanWhite on 4/8/16.
//  Copyright © 2016 Insta360. All rights reserved.
//

/**
 *  使用 Insta360SDK
 *  添加头文件引用 #import <ARVPlayerController/ARVPlayerController.h>
 *  如果是视频，需继承委托, 并实现代理方法
 *  初始化ARVPlayerController，初始化单个文件方式进行初始化。
 *  将self.player.playerView添加作为当前view的subview用来显示图像
 */

//MARK: - 定义设备屏幕的宽和高
#define ScreenWidth ([UIScreen mainScreen].bounds.size.width)
#define ScreenHeight ([UIScreen mainScreen].bounds.size.height)

#define IndicatorWidth 100

#import "ARVPlayerVC.h"
#import <ARVPlayerController/ARVPlayerController.h>

@interface ARVPlayerVC ()<ARVPlayerStatusDelegate>

/** 是否可以播放*/
@property (nonatomic) BOOL isPlaying;
/** 是否是视频结尾*/
@property (nonatomic) BOOL isVideoEnd;
/** 是否可以拖动进度条*/
@property (nonatomic) BOOL isSliding;
/** 是否可以拖拽*/
@property (nonatomic) BOOL isHandleDrag;
/** 是否是单屏*/
@property (nonatomic) BOOL isSingleScrren;
@property (nonatomic) NSInteger viewModeType;
/** 持续时间*/
@property (nonatomic, strong) NSString *duration;
/** 指示器*/
@property (nonatomic, strong) UIActivityIndicatorView *indicatorView;
@property (nonatomic, strong) ARVPlayerItem *playerItem;
@property (nonatomic, strong) ARVPlayerController *playerController;
/** 播放视图工具条视图*/
@property (weak, nonatomic) IBOutlet UIView *videoToolView;
/** 播放按钮*/
@property (weak, nonatomic) IBOutlet UIButton *playButton;
/** 进度滑动器*/
@property (weak, nonatomic) IBOutlet UISlider *progressSlider;
/** 时间展示栏*/
@property (weak, nonatomic) IBOutlet UILabel *timeLabel;

/** 基本操作视图工具条*/
@property (weak, nonatomic) IBOutlet UIView *basicToolView;
/** 单双屏展示按钮*/
@property (weak, nonatomic) IBOutlet UIButton *screenButton;
/** 展示画面是可以通过拖拽方式动还是可以通过陀螺仪方式动*/
@property (weak, nonatomic) IBOutlet UIButton *handleButton;
/** 鱼眼效果展示*/
@property (weak, nonatomic) IBOutlet UIButton *fisheyeButton;
/** 透视效果展示*/
@property (weak, nonatomic) IBOutlet UIButton *perspectiveButton;
/** 小行星效果展示*/
@property (weak, nonatomic) IBOutlet UIButton *asteriodButton;
@end

@implementation ARVPlayerVC

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view.
    self.view.backgroundColor = [UIColor blackColor];
    NSString *filePath;
    NSURL *fileURL;
    if (self.isSourceVideo) {
        //网络MP4视频
        filePath = @"http://cloud.insta360.com/public/media/mp4/88a951c7acf980f716c1bf1eb6cf12ca_1440x720.mp4";
        
//        filePath = @"http://60.55.12.147:80/45f1c9b883f8be484652306556e7f596.m3u8?w=1&key=19cbaf0bf152a9105c97a5998f776f3f&k=f77ff661a8c55b1ab955785b54e99c7a-5ae2-1464172960&bppcataid=961&type=phone.ios.vip&sv=7.5&platform=iphone4&ft=1&accessType=wifi&vvid=7D38F7BB-CB9E-423A-8620-707DC7739B0E&video=true";
//        filePath = @"http://video.iwjw.com/14651978969258742911-8000k";
        //网络rtmp
//        filePath = @"rtmp://ess.vzhibo.tv/live/test";
        //本地视频
//        filePath = [[NSBundle mainBundle] pathForResource:@"concert" ofType:@"mp4"];
//        [filePath stringByAddingPercentEscapesUsingEncoding:NSUTF8StringEncoding];
//        fileURL = [NSURL fileURLWithPath:filePath];
        
//        filePath = @"http://vr.ijntv.cn/vrvod/太极拳.mp4";
//        filePath = @"http://hls-vzhibo.vzhibo.tv/464067c1bbc988c401a8e0b508cfb8d9_360/playlist.m3u8";
        filePath = [filePath stringByAddingPercentEscapesUsingEncoding:NSUTF8StringEncoding];
        fileURL = [NSURL URLWithString:filePath];

        self.playerItem = [[ARVPlayerItem alloc] initWithURL:fileURL offset:nil type:ARVItemTypeVideo];
        self.playerController = [[ARVPlayerController alloc] initWithFrame:CGRectMake(0, 0, ScreenWidth, ScreenHeight) item:self.playerItem renderType:INSRenderTypeSphericalRender];
        self.playerController.delegate = self;
        //可设置单个视频循环播放
        self.playerController.repeatMode = ARVPlayRepeatModeCycleSingle;
        [self.view insertSubview:self.playerController.playerView atIndex:0];
        [self setupUI];
        
        
        
        //播放Insv 文件
//        filePath = [[NSBundle mainBundle] pathForResource:@"VID_20160507_161359_016" ofType:@"insv"];
//        fileURL = [NSURL fileURLWithPath:filePath];
////         fileURL = [NSURL URLWithString:@"http://kssws.ks-cdn.com/iwjw-test/anliInsta3603.insv"];
//        [ARVNPlayerUtils asyncVideoOffsetBy:fileURL offsetBlock:^(NSString *offset) {
//            dispatch_async(dispatch_get_main_queue(), ^{
//                NSLog(@"offset: %@", offset);
//                self.playerItem = [[ARVPlayerItem alloc] initWithURL:fileURL offset:offset type:ARVItemTypeVideo];
//                self.playerController = [[ARVPlayerController alloc] initWithFrame:CGRectMake(0, 0, ScreenWidth, ScreenHeight) item:self.playerItem renderType:INSRenderTypeSphericalPanoRender];
//                self.playerController.delegate = self;
//        //可设置单个视频循环播放
//        self.playerController.repeatMode = ARVPlayRepeatModeCycleSingle;
//                [self.view insertSubview:self.playerController.playerView atIndex:0];
//                
//                [self setupUI];
//            });
//        }];
        
    } else {
        //播放jpg文件
        filePath = [[NSBundle mainBundle] pathForResource:@"demo" ofType:@"jpg"];
        fileURL = [NSURL fileURLWithPath:filePath];
        self.videoToolView.hidden = YES;
        
        self.playerItem = [[ARVPlayerItem alloc] initWithURL:fileURL offset:nil type:ARVItemTypeUnknown];
        self.playerController = [[ARVPlayerController alloc] initWithFrame:CGRectMake(0, 0, ScreenWidth, ScreenHeight) item:self.playerItem renderType:INSRenderTypeSphericalRender];
        [self.view insertSubview:self.playerController.playerView atIndex:0];
        [self setupUI];
        
        
        //播放Insp文件
//        filePath = [[NSBundle mainBundle] pathForResource:@"1" ofType:@"insp"];
//        fileURL = [NSURL fileURLWithPath:filePath];
//        self.videoToolView.hidden = YES;
//        [ARVNPlayerUtils asyncImageOffsetBy:fileURL offsetBlock:^(NSString *offset) {
//            self.playerItem = [[ARVPlayerItem alloc] initWithURL:fileURL offset:offset type:ARVItemTypeImage];
//            self.playerController = [[ARVPlayerController alloc] initWithFrame:CGRectMake(0, 0, ScreenWidth, ScreenHeight) item:self.playerItem renderType:INSRenderTypeFlatPanoRender];
//            //可设置单个视频循环播放
//            [self.view insertSubview:self.playerController.playerView atIndex:0];
//            [self setupUI];
//        }];
        
    }
    
    
//    [self.playerController setMiniumBufferSize:2 *1024 * 1024];//2m
//    [self.playerController setMaxiumBufferSize:10 * 1024 * 1024];
//    [self.playerController setBufferSizeForPerPiece:2 * 1024 * 1024];
    [self.playerController prepare];
    self.isPlaying = YES;
    [self.playerController play];
}

- (void)setupUI {
    self.isPlaying = NO;
    self.isSingleScrren = YES;
    self.isHandleDrag = YES;
    
    self.fisheyeButton.tag = 0;
    self.perspectiveButton.tag = 1;
    self.asteriodButton.tag = 2;
    [self.fisheyeButton setBackgroundColor:[UIColor grayColor]];
    
    self.progressSlider.enabled = NO;
    [self.progressSlider addTarget:self action:@selector(sliderTouchDown:) forControlEvents:UIControlEventTouchDown];
    [self.progressSlider addTarget:self action:@selector(sliderTouchUp:) forControlEvents:UIControlEventTouchUpOutside | UIControlEventTouchUpInside];
}

- (void)sliderTouchDown:(UISlider *)slider {
    self.isSliding = YES;
}

- (void)sliderTouchUp:(UISlider *)slider {
    self.isSliding = NO;
}

#pragma mark - 照片/视频可调整的共同参数
- (IBAction)screenButtonClicked:(id)sender {
    UIButton *button = (UIButton *)sender;
    if (self.isSingleScrren) {
        [button setTitle:@"双屏" forState:UIControlStateNormal];
        self.playerController.playerView.presentMode = INSViewPresentModeWidthDirectionDuplicate;
    } else {
        [button setTitle:@"单屏" forState:UIControlStateNormal];
        self.playerController.playerView.presentMode = INSViewPresentModeSingle;
    }
    self.isSingleScrren = !self.isSingleScrren;
}

- (IBAction)handleButtonClicked:(id)sender {
    UIButton *button = (UIButton *)sender;
    if (self.isHandleDrag) {
        [button setTitle:@"陀螺仪" forState:UIControlStateNormal];
        self.playerController.playerView.interactiveMode = INSViewInteractiveModeGyro;
    } else {
        [button setTitle:@"拖拽" forState:UIControlStateNormal];
        self.playerController.playerView.interactiveMode = INSViewInteractiveModeFinger;
    }
    self.isHandleDrag = !self.isHandleDrag;
}

- (IBAction)viewModeButtonClicked:(id)sender {
    UIButton *button = (UIButton *)sender;
    [self.fisheyeButton setBackgroundColor:[UIColor clearColor]];
    [self.perspectiveButton setBackgroundColor:[UIColor clearColor]];
    [self.asteriodButton setBackgroundColor:[UIColor clearColor]];
    [button setBackgroundColor:[UIColor grayColor]];
    switch (button.tag) {
        case 0:
        {
            self.playerController.playerView.projectionMode = INSViewProjectionModeFisheye;
        }
            break;
        case 1:
        {
            self.playerController.playerView.projectionMode = INSViewProjectionModePerspective;
        }
            break;
        case 2:
        {
            self.playerController.playerView.projectionMode = INSViewProjectionModeAsteroid;
        }
            break;
        default:
            break;
    }
}

#pragma mark - 播放视频处理
- (IBAction)playButtonClilcked:(id)sender {
    NSLog(@"按了播放按钮");
    UIButton *button = (UIButton *)sender;
    if (self.isPlaying) {
        [button setTitle:@"播放" forState:UIControlStateNormal];
        [self.playerController pause];
    } else {
        [button setTitle:@"暂停" forState:UIControlStateNormal];
        if (self.isVideoEnd) {
            self.isVideoEnd = NO;
            [self.playerController replaceCurrentItemWithItem:self.playerController.currentItem];
        }
        [self.playerController play];
    }
    self.isPlaying = !self.isPlaying;
    if (!self.progressSlider.enabled) {
        self.progressSlider.enabled = YES;
    }
}

- (IBAction)replaceButtonClicked:(id)sender {
//    NSURL *fileURL = [NSURL URLWithString:@"http://kssws.ks-cdn.com/iwjw-test/anliInsta3603.insv"];
    NSURL *fileURL = [NSURL URLWithString:@"http://60.55.12.147:80/45f1c9b883f8be484652306556e7f596.m3u8?w=1&key=19cbaf0bf152a9105c97a5998f776f3f&k=f77ff661a8c55b1ab955785b54e99c7a-5ae2-1464172960&bppcataid=961&type=phone.ios.vip&sv=7.5&platform=iphone4&ft=1&accessType=wifi&vvid=7D38F7BB-CB9E-423A-8620-707DC7739B0E&video=true"];
    [ARVNPlayerUtils asyncVideoOffsetBy:fileURL offsetBlock:^(NSString *offset) {
    dispatch_async(dispatch_get_main_queue(), ^{
        NSLog(@"offset: %@", offset);
        self.playerItem = [[ARVPlayerItem alloc] initWithURL:fileURL offset:offset type:ARVItemTypeVideo];
        [self.playerController replaceCurrentItemWithItem:self.playerItem];
        [self.playerController prepare];
        [self.playerController play];
        });
    }];
}

- (IBAction)progressValueChanged:(id)sender {
    UISlider *slider = (UISlider *)sender;
    double value = slider.value;
    NSLog(@"滑动时间seek:%f", value);
    [self.progressSlider setValue:ceilf(value)];
    [self.playerController seekToTime:ceilf(value)*1000];
}

//视频才需要实现该委托的两个方法
#pragma mark - ARVPlayerStatusDelegate
- (void)playerStatusChanged:(INSPlayerStatus)status {
    switch (status) {
        case INSPlayerStatusPrepared:
        {
            NSLog(@"INSPlayerStatusPrepared");
            double duration = self.playerController.duration;
            [self.progressSlider setMaximumValue:ceilf(duration)];
            self.duration = [self formatTimeWithSecondsValue:ceilf(duration)];
            dispatch_async(dispatch_get_main_queue(), ^{
                self.timeLabel.text = @"00:00/00:00";
                [self.progressSlider setValue:0.0f];
            });
        }
            break;
        case INSPlayerStatusBuffering:
        {
            NSLog(@"INSPlayerStatusBuffering");
            dispatch_async(dispatch_get_main_queue(), ^{
                if (!self.indicatorView) {
                    self.indicatorView = [[UIActivityIndicatorView alloc] initWithFrame:CGRectMake(0, 0, IndicatorWidth, IndicatorWidth)];
                    self.indicatorView.activityIndicatorViewStyle = UIActivityIndicatorViewStyleGray;
                    self.indicatorView.center = self.view.center;
                    self.indicatorView.hidesWhenStopped = YES;
                    [self.view insertSubview:self.indicatorView atIndex:100];
                }
                [self.indicatorView startAnimating];
            });
        }
            break;
        case INSPlayerStatusPlaying:
        {
            NSLog(@"INSPlayerStatusPlaying");
            self.isVideoEnd = NO;
            self.isPlaying = YES;
            dispatch_async(dispatch_get_main_queue(), ^{
                [self.playButton setTitle:@"暂停" forState:UIControlStateNormal];
                if ([self.indicatorView isAnimating]) {
                    [self.indicatorView stopAnimating];
                }
            });
        }
            break;
        case INSPlayerStatusPaused:
        {
            NSLog(@"INSPlayerStatusPaused");
            self.isPlaying = NO;
            dispatch_async(dispatch_get_main_queue(), ^{
                [self.playButton setTitle:@"播放" forState:UIControlStateNormal];
            });
        }
            break;
        case INSPlayerStatusEnd:
        {
            NSLog(@"INSPlayerStatusEnd");
            self.isVideoEnd = YES;
            self.isPlaying = NO;
            dispatch_async(dispatch_get_main_queue(), ^{
                [self.playButton setTitle:@"播放" forState:UIControlStateNormal];
            });
        }
            break;
        case INSPlayerStatusFailed:
        {
            NSLog(@"播放失败");
        }
            break;
        case INSPlayerStatusUnknown:
        {
            NSLog(@"INSPlayerStatusUnknown");
        }
            break;
        default:
            break;
    }
}

- (void)updateCurrentTime:(double)time {
    if (!self.isSliding) {
        dispatch_async(dispatch_get_main_queue(), ^{
            [self.progressSlider setValue:ceilf(time)];
            self.timeLabel.text = [NSString stringWithFormat:@"%@/%@", [self formatTimeWithSecondsValue:ceilf(time)], self.duration];
        });
    }
}

#pragma mark - 格式化时间
- (NSString *)formatTimeWithSecondsValue:(NSInteger)seconds {
    NSString *formatTime;
    if (seconds < 60) {
        formatTime = [NSString stringWithFormat:@"00:%02ld", (long)seconds];
    }else if (seconds < 3600) {
        NSInteger minute = seconds / 60;
        NSInteger second = seconds % 60;
        formatTime = [NSString stringWithFormat:@"%ld:%ld",(long)minute, (long)second];
    }else if (seconds < 216000) {
        NSInteger hour = seconds / 3600;
        NSInteger minute = seconds % 3600 /60;
        NSInteger second = seconds % 3600 %60;
        formatTime = [NSString stringWithFormat:@"%ld:%ld:%ld", (long)hour, (long)minute, (long)second];
    }
    return formatTime;
}

- (IBAction)exitButtonClicked:(id)sender {
    NSLog(@"%s", __FUNCTION__);
    [self.playerController stop];
    [self dismissViewControllerAnimated:YES completion:nil];
}

- (BOOL)shouldAutorotate {
    if(self.playerController.playerView.interactiveMode == INSViewInteractiveModeGyro) {
        return NO;
    } else {
        self.playerController.playerView.frame = self.view.bounds;
        return YES;
    }
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

- (void)dealloc {
    NSLog(@"播放页面 vc dealloc");
}

/*
#pragma mark - Navigation

// In a storyboard-based application, you will often want to do a little preparation before navigation
- (void)prepareForSegue:(UIStoryboardSegue *)segue sender:(id)sender {
    // Get the new view controller using [segue destinationViewController].
    // Pass the selected object to the new view controller.
}
*/

@end
