//
//  ISNVideoToolBoxEncoder.hpp
//  INSVideoPlayApp
//
//  Created by jerett on 15/12/21.
//  Copyright © 2015年 insta360. All rights reserved.
//

#ifndef INSVideoToolBoxEncoder_hpp
#define INSVideoToolBoxEncoder_hpp

#include <stdio.h>
#include <stdint.h>

#include <functional>
#include <mutex>
#include <CoreVideo/CoreVideo.h>
#include <CoreMedia/CoreMedia.h>
#include <VideoToolbox/VideoToolbox.h>

using SPS_PPS_CALLBACK = std::function<void(const uint8_t* sps, int sps_size, const uint8_t* pps, int pps_size)>;

using NALU_CALLBACK = std::function<void(uint8_t* nalu, int size, CMTime pts)>;

class INSVideoToolBoxEncoder {
    friend void didCompressH264(void *outputCallbackRefCon,
                           void *sourceFrameRefCon,
                           OSStatus status,
                           VTEncodeInfoFlags infoFlags,
                           CMSampleBufferRef sampleBuffer);
    
public:
    INSVideoToolBoxEncoder(int width, int height, int bitrate, int fps);
    ~INSVideoToolBoxEncoder();
    
    //copy deleted
    INSVideoToolBoxEncoder(const INSVideoToolBoxEncoder&) = delete;
    INSVideoToolBoxEncoder& operator=(const INSVideoToolBoxEncoder) = delete;
    
    //move
    INSVideoToolBoxEncoder(INSVideoToolBoxEncoder&&);
    INSVideoToolBoxEncoder& operator=(INSVideoToolBoxEncoder&&) = delete;
    
    void set_sps_pps_callback(SPS_PPS_CALLBACK callback) {
        sps_pps_callback_ = callback;
    }

    void set_nalu_callback(NALU_CALLBACK callback) {
        nalu_callback_ = callback;
    }

    
    bool open();

    bool encodeImage(CVImageBufferRef image_buffer, CMTime timestamp);
    
    void flush();
    
    void close();
    
private:
    bool createSession();
    
private:
    SPS_PPS_CALLBACK sps_pps_callback_;
    NALU_CALLBACK nalu_callback_;
    
    int width_ = 0;
    int height_ = 0;
    int bitrate_ = 0;
    int fps_ = 0;
    
    VTCompressionSessionRef encoder_session_ = nullptr;
    std::mutex mtx_;
};

#endif /* ISNVideoToolBoxEncoder_hpp */
