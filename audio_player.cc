#include <gst/gst.h>
#include <iostream>
// int main(int argc, char *argv[]) {
//     GstElement *pipeline;
//     GstBus *bus;
//     GstMessage *msg;

//     /* Initialize GStreamer */
//     gst_init(&argc, &argv);

//     /* Create the pipeline with uridecodebin */
//     pipeline = gst_parse_launch("uridecodebin uri=rtsp://zlm.robot.genius-pros.com:18554/virtual-robot/900106-900106-573c887e-d19e-47e9-8040-3d1fad20edc8  ! autoaudiosink", NULL);

//     /* Configure the uridecodebin element to adjust buffer sizes */
//     g_object_set(G_OBJECT(pipeline), "max-size-time", G_GINT64_CONSTANT(1000000000), NULL);  // Set the maximum buffer size (1 second in nanoseconds)
//     g_object_set(G_OBJECT(pipeline), "min-size-time", G_GINT64_CONSTANT(500000000), NULL);  // Set the minimum buffer size (0.5 seconds in nanoseconds)
//     g_object_set(G_OBJECT(pipeline), "latency", 1000000000, NULL); // Set latency to 1 second in nanoseconds

//     /* Start playing */
//     gst_element_set_state(pipeline, GST_STATE_PLAYING);

//     /* Wait until error or EOS */
//     bus = gst_element_get_bus(pipeline);
//     msg = gst_bus_timed_pop_filtered(bus, GST_CLOCK_TIME_NONE, (GstMessageType)(GST_MESSAGE_ERROR | GST_MESSAGE_EOS));

//     if (msg != NULL)
//         gst_message_unref(msg);

//     gst_object_unref(bus);
//     gst_element_set_state(pipeline, GST_STATE_NULL);
//     gst_object_unref(pipeline);
//     return 0;
// }



//  int main(int argc, char *argv[]) {
//     GstElement *pipeline;
// GstElement *uridecodebin;
// GstBus *bus;
// GstMessage *msg;

// /* Initialize GStreamer */
// gst_init(NULL, NULL);

// /* Create the pipeline with uridecodebin */
// pipeline = gst_parse_launch("uridecodebin uri=rtsp://zlm.robot.genius-pros.com:18554/virtual-robot/900106-900106-573c887e-d19e-47e9-8040-3d1fad20edc8 ! autoaudiosink", NULL);

// /* Get the uridecodebin element from the pipeline by name */
// uridecodebin = gst_bin_get_by_name(GST_BIN(pipeline), "uridecodebin0");

// /* Configure the uridecodebin element to adjust buffer sizes */
// g_object_set(G_OBJECT(uridecodebin), "max-size-time", G_GINT64_CONSTANT(1000000000), NULL);  // Set the maximum buffer size (1 second in nanoseconds)
// g_object_set(G_OBJECT(uridecodebin), "min-size-time", G_GINT64_CONSTANT(500000000), NULL);  // Set the minimum buffer size (0.5 seconds in nanoseconds)
// g_object_set(G_OBJECT(pipeline), "latency", 1000000000, NULL); // Set latency to 1 second in nanoseconds
// /* Start playing */
// gst_element_set_state(pipeline, GST_STATE_PLAYING);

// /* Wait until error or EOS */
// bus = gst_element_get_bus(pipeline);
// msg = gst_bus_timed_pop_filtered(bus, GST_CLOCK_TIME_NONE, (GstMessageType)(GST_MESSAGE_ERROR | GST_MESSAGE_EOS));

// if (msg != NULL)
//     gst_message_unref(msg);

// gst_object_unref(bus);
// gst_element_set_state(pipeline, GST_STATE_NULL);
// gst_object_unref(pipeline);

// return 0;
//  }


//2 秒
// int main(int argc, char *argv[]) 
// {
//     GstElement *pipeline;
//     GstElement *uridecodebin;
//     GstElement *queue;
//     GstBus *bus;
//     GstMessage *msg;

//     /* Initialize GStreamer */
//     gst_init(NULL, NULL);

//     /* Create the pipeline with uridecodebin */
//     pipeline = gst_parse_launch("uridecodebin uri=rtsp://zlm.robot.genius-pros.com:18554/virtual-robot/900106-900106-573c887e-d19e-47e9-8040-3d1fad20edc8 ! queue ! autoaudiosink", NULL);
//     g_object_set(G_OBJECT(pipeline), "latency", 1000000000, NULL); // Set latency to 1 second in nanoseconds
//     gst_element_set_state(pipeline, GST_STATE_PLAYING);

//     /* Wait until error or EOS */
//     bus = gst_element_get_bus(pipeline);
//     msg = gst_bus_timed_pop_filtered(bus, GST_CLOCK_TIME_NONE, (GstMessageType)(GST_MESSAGE_ERROR | GST_MESSAGE_EOS));

//     if (msg != NULL)
//         gst_message_unref(msg);

//     gst_object_unref(bus);
//     gst_element_set_state(pipeline, GST_STATE_NULL);
//     gst_object_unref(pipeline);

//     return 0;
// }


// int main(int argc, char *argv[]) {
//     GstElement *pipeline;
//     GstElement *source;
//     GstElement *queue;
//     GstElement *audioconvert;
//     GstElement *autoaudiosink;
//     GstBus *bus;
//     GstMessage *msg;

//     /* Initialize GStreamer */
//     gst_init(&argc, &argv);

//     /* Create the pipeline */
//     pipeline = gst_pipeline_new("audio-player");
//     source = gst_element_factory_make("uridecodebin", "source");
//     queue = gst_element_factory_make("queue", "my-queue");
//     audioconvert = gst_element_factory_make("audioconvert", "audioconvert");
//     autoaudiosink = gst_element_factory_make("autoaudiosink", "autoaudiosink");

//     if (!pipeline || !source || !queue || !audioconvert || !autoaudiosink) {
//         g_printerr("Not all elements could be created.\n");
//         std::cout << "111" <<std::endl;
//         return -1;
//     }

//     /* Set the URI for the RTSP stream */
//     g_object_set(G_OBJECT(source), "uri", "rtsp://zlm.robot.genius-pros.com:18554/virtual-robot/900106-900106-573c887e-d19e-47e9-8040-3d1fad20edc8", NULL);
//     std::cout << "222" <<std::endl;
//     /* Configure queue element to adjust buffer sizes */
//     g_object_set(G_OBJECT(queue), "max-size-buffers", 100, NULL);  // Set the maximum buffer count
//     g_object_set(G_OBJECT(queue), "max-size-time", G_GINT64_CONSTANT(1000000000), NULL);  // Set the maximum buffer time (1 second in nanoseconds)
//     std::cout << "333" <<std::endl;
//     /* Build the pipeline */
//     gst_bin_add_many(GST_BIN(pipeline), source, queue, audioconvert, autoaudiosink, NULL);
//     gst_element_link_many(source, queue, audioconvert, autoaudiosink, NULL);
//     std::cout << "444" <<std::endl;
//     /* Set the pipeline state to playing */
//     gst_element_set_state(pipeline, GST_STATE_PLAYING);
//     std::cout << "555" <<std::endl;
//     /* Wait until error or EOS */
//     bus = gst_element_get_bus(pipeline);
//     msg = gst_bus_timed_pop_filtered(bus, GST_CLOCK_TIME_NONE, (GstMessageType)(GST_MESSAGE_ERROR | GST_MESSAGE_EOS));
//     std::cout << "666" <<std::endl;
//     if (msg != NULL)
//         gst_message_unref(msg);
//     std::cout << "777" <<std::endl;
//     gst_object_unref(bus);
//     gst_element_set_state(pipeline, GST_STATE_NULL);
//     gst_object_unref(pipeline);

//     return 0;
// }

// #include <gst/gst.h>

// int main(int argc, char *argv[]) {
//     GstElement *pipeline;
//     GstBus *bus;
//     GstMessage *msg;

//     /* Initialize GStreamer */
//     gst_init(&argc, &argv);

//     /* Create the pipeline with playbin */
//     pipeline = gst_parse_launch("playbin uri=rtsp://zlm.robot.genius-pros.com:18554/virtual-robot/900106-900106-573c887e-d19e-47e9-8040-3d1fad20edc8", NULL);

//     /* Preload the pipeline to reduce latency */
//     gst_element_set_state(pipeline, GST_STATE_PAUSED);
//     gst_element_get_state(pipeline, NULL, NULL, GST_CLOCK_TIME_NONE);

//     /* Configure hardware acceleration if supported */
//     GstElement *sink = gst_bin_get_by_name(GST_BIN(pipeline), "playsink");
//     if (sink) {
//         g_object_set(sink, "flags", 0x00000080, NULL); // Enable hardware acceleration flags
//     }

//     /* Start playing */
//     gst_element_set_state(pipeline, GST_STATE_PLAYING);

//     /* Wait until error or EOS */
//     bus = gst_element_get_bus(pipeline);
//     msg = gst_bus_timed_pop_filtered(bus, GST_CLOCK_TIME_NONE, (GstMessageType)(GST_MESSAGE_ERROR | GST_MESSAGE_EOS));

//     if (msg != NULL)
//         gst_message_unref(msg);

//     gst_object_unref(bus);
//     gst_element_set_state(pipeline, GST_STATE_NULL);
//     gst_object_unref(pipeline);

//     return 0;
// }



// 延迟2 秒
// #include <gst/gst.h>  
  
// int main(int argc, char *argv[]) {  
//     GstElement *pipeline = nullptr;  
//     GstElement *uridecodebin;  
//     GstElement *queue = nullptr;  
//     GstBus *bus;  
//     GstMessage *msg;  
//      GstElement *element; 

//     /* Initialize GStreamer */  
//     gst_init(&argc, &argv);  
  
//     /* Create the pipeline with uridecodebin */  
//     pipeline = gst_parse_launch("uridecodebin uri=rtsp://zlm.robot.genius-pros.com:18554/virtual-robot/900106-900106-573c887e-d19e-47e9-8040-3d1fad20edc8 ! queue ! autoaudiosink", NULL);  
  
//     element = gst_element_factory_make("queue", "queue");  

//     if(element)
//     {
//         std::cout <<"element is not empty" <<std::endl;
//     }

//     gst_bin_add(GST_BIN(pipeline), element);

//     /* Create the queue element */  
//     if(pipeline)
//     {
//         std::cout <<"pipeline not empty" <<std::endl;
//         queue = gst_bin_get_by_name(GST_BIN(pipeline), "queue");  
//     }

//     if(queue)
//     {
//          /* Set the max-size-buffers, max-size-time, and max-size-bytes properties */  
//         g_object_set(G_OBJECT(queue), "max-size-buffers", 3, NULL);   // 设置缓冲区数量限制为5  
//         g_object_set(G_OBJECT(queue), "max-size-time", 100 * GST_MSECOND, NULL);   // 设置最大数据持续时间为200毫秒  
//         g_object_set(G_OBJECT(queue), "max-size-bytes", 512 * 1024, NULL);   // 设置最大数据量为1MB  
    
//         gst_object_unref(queue);  
//         std::cout <<"sss" <<std::endl;
//     }
   
  
//     /* Set latency to 1 second in nanoseconds */  
//     g_object_set(G_OBJECT(pipeline), "latency", 1500000000, NULL);  
  
//     /* Start playing */  
//     gst_element_set_state(pipeline, GST_STATE_PLAYING);  
  
//     /* Wait until error or EOS */  
//     bus = gst_element_get_bus(pipeline);  
//     msg = gst_bus_timed_pop_filtered(bus, GST_CLOCK_TIME_NONE, (GstMessageType)(GST_MESSAGE_ERROR | GST_MESSAGE_EOS));  
  
//     /* Free resources */  
//     if (msg != NULL)  
//         gst_message_unref(msg);  
//     gst_object_unref(bus);  
//     gst_element_set_state(pipeline, GST_STATE_NULL);  
//     gst_object_unref(pipeline);  
  
//     return 0;  
// }


#include <iostream>
#include <functional>
#include <SDL2/SDL.h>

extern "C" {
#include <libavformat/avformat.h>
#include <libavcodec/avcodec.h>
#include <libavutil/avutil.h>
#include <libswresample/swresample.h>
}

AVCodecContext* audioCodecContext = nullptr;
AVFormatContext *formatContext  = nullptr;


std::function<void(void*, Uint8*, int)> audioCallbackFunction = [](void *userdata, Uint8 *stream, int len) {
    //auto audioDevice = static_cast<SDL_AudioDeviceID>(reinterpret_cast<uintptr_t>(userdata));

    std::cout << "size = " << len <<std::endl;
    // 从 FFmpeg 获取解码后的音频数据
    AVPacket packet;
    av_init_packet(&packet);
    packet.data = nullptr;
    packet.size = 0;

    if (av_read_frame(reinterpret_cast<AVFormatContext*>(userdata), &packet) < 0) {
        // 处理错误或结束
        std::cerr << "Error reading audio frame" << std::endl;
        return;
    }

    // if (av_read_frame(formatContext, &packet) < 0) {
    //     // 处理错误或结束
    //     std::cerr << "Error reading audio frame" << std::endl;
    //     return;
    // }

    int ret = avcodec_send_packet(audioCodecContext, &packet);
    av_packet_unref(&packet);
    if (ret < 0) {
        std::cerr << "Error sending a packet for decoding" << std::endl;
        return;
    }

    AVFrame *decodedFrame = av_frame_alloc();
    if (!decodedFrame) {
        std::cerr << "Error allocating audio frame" << std::endl;
        return;
    }

    ret = avcodec_receive_frame(audioCodecContext, decodedFrame);
    if (ret < 0) {
        std::cerr << "Error receiving a frame from the decoder" << std::endl;
        av_frame_free(&decodedFrame);
        return;
    }

    // 初始化重采样上下文
    SwrContext *swrContext = swr_alloc_set_opts(nullptr,
                                                 AV_CH_LAYOUT_STEREO,
                                                 AV_SAMPLE_FMT_S16,
                                                 audioCodecContext->sample_rate,
                                                 av_get_default_channel_layout(audioCodecContext->channels),
                                                 audioCodecContext->sample_fmt,
                                                 audioCodecContext->sample_rate,
                                                 0,
                                                 nullptr);

    if (!swrContext || swr_init(swrContext) < 0) {
        std::cerr << "Error initializing audio resampler" << std::endl;
        swr_free(&swrContext);
        av_frame_free(&decodedFrame);
        return;
    }

    // 重采样
    uint8_t *buffer = nullptr;
    int out_samples = av_rescale_rnd(swr_get_delay(swrContext, audioCodecContext->sample_rate) + decodedFrame->nb_samples,
                                     audioCodecContext->sample_rate,
                                     audioCodecContext->sample_rate,
                                     AV_ROUND_UP);
    av_samples_alloc(&buffer, nullptr, audioCodecContext->channels, out_samples, AV_SAMPLE_FMT_S16, 0);
    swr_convert(swrContext, &buffer, out_samples, (const uint8_t **)decodedFrame->data, decodedFrame->nb_samples);

    // 将音频数据拷贝到 SDL 音频缓冲区
    memcpy(stream, buffer, len);

    av_frame_free(&decodedFrame);
    swr_free(&swrContext);
    av_freep(&buffer);
};

int main() 
{
    av_register_all();
    avformat_network_init();

    // 打开 RTSP 音频流
    formatContext = avformat_alloc_context();
    if (avformat_open_input(&formatContext, "rtsp://zlm.robot.genius-pros.com:18554/virtual-robot/900106-900106-573c887e-d19e-47e9-8040-3d1fad20edc8", nullptr, nullptr) < 0) {
        std::cerr << "Error opening input" << std::endl;
        return -1;
    }

    // 寻找音频流信息
    if (avformat_find_stream_info(formatContext, nullptr) < 0) {
        std::cerr << "Error finding stream information" << std::endl;
        avformat_close_input(&formatContext);
        avformat_free_context(formatContext);
        return -1;
    }

    // 寻找音频流索引
    int audioStreamIndex = -1;
    std::cout <<"nb_streams =====" << formatContext->nb_streams <<std::endl;
    for (int i = 0; i < formatContext->nb_streams; i++) {
        if (formatContext->streams[i]->codecpar->codec_type == AVMEDIA_TYPE_AUDIO) {
            audioStreamIndex = i;
            break;
        }
    }

   
    if (audioStreamIndex == -1) {
        std::cerr << "Error finding audio stream" << std::endl;
        avformat_close_input(&formatContext);
        avformat_free_context(formatContext);
        return -1;
    }

    // 根据音频流索引查找对应的编码器参数
    // 再根据编码器id 寻找对应的解码器，并返回解码器的结构体指针
    AVCodecParameters *audioCodecParameters = formatContext->streams[audioStreamIndex]->codecpar;
    AVCodec *audioCodec = avcodec_find_decoder(audioCodecParameters->codec_id);
    if (!audioCodec) {
        std::cerr << "Error finding audio decoder" << std::endl;
        avformat_close_input(&formatContext);
        avformat_free_context(formatContext);
        return -1;
    }

    // 创建并初始化解码器上下文
    audioCodecContext = avcodec_alloc_context3(audioCodec);
    if (!audioCodecContext) {
        std::cerr << "Error allocating audio codec context" << std::endl;
        avformat_close_input(&formatContext);
        avformat_free_context(formatContext);
        return -1;
    }

    // 是将音频流的编解码参数（AVCodecParameters）复制到音频解码器的上下文
    if (avcodec_parameters_to_context(audioCodecContext, audioCodecParameters) < 0) {
        std::cerr << "Error initializing audio codec context" << std::endl;
        avcodec_free_context(&audioCodecContext);
        avformat_close_input(&formatContext);
        avformat_free_context(formatContext);
        return -1;
    }

    // 打开音频解码器
    if (avcodec_open2(audioCodecContext, audioCodec, nullptr) < 0) {
        std::cerr << "Error opening audio codec" << std::endl;
        avcodec_free_context(&audioCodecContext);
        avformat_close_input(&formatContext);
        avformat_free_context(formatContext);
        return -1;
    }

    // SDL 初始化
    if (SDL_Init(SDL_INIT_AUDIO) < 0) {
        std::cerr << "Error initializing SDL: " << SDL_GetError() << std::endl;
        avcodec_free_context(&audioCodecContext);
        avformat_close_input(&formatContext);
        avformat_free_context(formatContext);
        return -1;
    }

    SDL_AudioSpec wanted_spec, spec;
    SDL_AudioDeviceID audioDevice;

    wanted_spec.freq = audioCodecContext->sample_rate;
    wanted_spec.format = AUDIO_S16SYS;
    wanted_spec.channels = audioCodecContext->channels;
    wanted_spec.samples = 1024;
    wanted_spec.userdata = static_cast<void*>(formatContext);
    wanted_spec.callback = [](void* userdata, Uint8* stream, int len) {
        audioCallbackFunction(userdata, stream, len);
    
    };

    audioDevice = SDL_OpenAudioDevice(nullptr, 0, &wanted_spec, &spec, 0);
    if (audioDevice == 0) {
        std::cerr << "Error opening audio device: " << SDL_GetError() << std::endl;
        SDL_Quit();
        avcodec_free_context(&audioCodecContext);
        avformat_close_input(&formatContext);
        avformat_free_context(formatContext);
        return -1;
    }

    // 设置音频流索引到 FFmpeg 音频解码器的上下文中
    audioCodecContext->opaque = reinterpret_cast<void*>(audioDevice);

    // 开始播放
    SDL_PauseAudioDevice(audioDevice, 0);

    // 主循环
    SDL_Event event;
    while (SDL_WaitEvent(&event)) {
        if (event.type == SDL_QUIT) {
            break;
        }
    }

    // 清理资源
    SDL_CloseAudioDevice(audioDevice);
    SDL_Quit();
    avcodec_free_context(&audioCodecContext);
    avformat_close_input(&formatContext);
    avformat_free_context(formatContext);
    return 0;
}
