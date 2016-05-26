# Insta360PlayerSDK 

## 使用说明
* 本SDK仅支持iOS 8及以上的真机，不支持模拟器
* 视频播放支持Mp4/Insv，图片播放支持UIImage支持的所有格式及Insp
* 播放器支持file、http的视频点播，和rtmp、rtsp协议的直播, 支持m3u8播放
## 工程配置
### 添加下列库
1. libstdc++.tbd
2. libz.1.2.5.tbd
3. libbz2.1.0.tbd
4. libiconv.2.4.0.tbd
5. <ImageIO.framework>
6. <CoreMedia.framework>
7. <CoreMotion.framework>
8. <AudioToolbox.framework>
9. <VideoToolbox.framework>
10. <INSMediaSDK.framework>
11. <ARVPlayerController.framework>

### 额外设置
+ General->Embedded Binaries中添加<INSMediaSDK.framework>，


## 使用Insta360SDK 
1. 添加头文件引用`#import <ARVPlayerController/ARVPlayerController.h>`
2. 如果是视频，需继承委托<ARVPlayerStatusDelegate>, 并实现代理方法
3. 初始化ARVPlayerController，初始化单个文件方式进行初始化。
4. 将`self.player.playerView`添加作为当前view的subview用来显示图像

### 播放单个文件
* 使用`- (instancetype)initWithFrame:(CGRect)frame item:(ARVPlayerItem *)item renderType:(ARVRenderType)type;`初始化控制器
* 切换文件使用`- (void)replaceCurrentItemWithItem:(ARVPlayerItem *)item;`
* 目前仅可设置循环模式为单个循环
### 使用ARVPlayerController实例控制

```
//设置缓冲(可选)，如需设置，必须在prepare之前设置, 单位byte(可参考demo)
- (void)setMiniumBufferSize:(long)size;//设置缓冲区最小大小，一旦小于这个值，会进行缓冲
- (void)setMaxiumBufferSize:(long)size;//缓冲区最大值，建议不超过10M
- (void)setBufferSizeForPerPiece:(long)size;//设置缓冲会缓冲的大小

- (void)prepare;//使播放器进入准备状态
- (void)play;//play前，必须先调用prepare
- (void)pause;
- (void)stop;
- (void)seekToTime:(double)time;
- (void)setHttpOnLanMode:(BOOL)lanMode;//局域网播放视频时，设置YES实现低延迟
- (void)replaceCurrentItemWithItem:(ARVPlayerItem *)item;//初始化后，替换当前资源，切换资源
```

### 使用ARVPlayerController实例的playerView属性控制

```
- //陀螺仪
playerView.interactiveMode
//双屏，参数设置是否竖直方向
playerView.presentMode
//小行星，鱼眼，透视效果
playerView.projectionMode
//播放图片
- (void)playImage:(UIImage *)image offset:(NSString *)offset;
- (void)playImageWithURL:(NSURL *)url offset:(NSString *)offset;
//播放视频
- (void)playVideo:(id<INSPlayerProtocol>)player offset:(NSString *)offset;
```

### 播放3D效果（即使用ARVRenderType3DRender作为渲染类型）
+ 需要将logo2.png放入当前工程中

## 播放器相关
### 创建、状态、操作
* 查询状态操作必须在Preapred后进行，比如getVideWidth、getVideHeight等。
* 在INSPlayerStatusBuffering状态下，用户可以操作，会进入队列执行。
* 对于流媒体和直播，不支持seek、当前播放时长、总时长、暂停等操作。
### 缓存机制
* 播放器在播放network的资源的时候，默认会有缓存机制，播放器会进入Buffering的状态，需要开发者调用ActivityIndicator提醒用户。
### 后台处理 （重要!!）
* 当程序进入后台applicationWillResignActive，播放器会自动暂停。!!重复调用可能会导致Crash
* 当程序进入前台applicationDidBecomeActive，播放器会自动播放。
* 目前在进入后台或者前台，调用者无需也不要尝试改变播放器状态，因为这会涉及很多复杂的状态改变，让播放器自己处理。（建议在播放器playing状态和paused状态时，只需改变播放按钮UI，使其行为与表现一致）

## 界面旋转
陀螺仪状态下，不应旋转
```
- (BOOL)shouldAutorotate {
    if(self.playerController.playerView.interactiveMode == INSViewInteractiveModeGyro) {
        return NO;
    } else {
        self.playerController.playerView.frame = self.view.bounds;
        return YES;
    }
}
```

## Demo
* 移除了视频和图片演示资源，如要运行DEMO，自行替换
* 详见Insta360SDKDemo
