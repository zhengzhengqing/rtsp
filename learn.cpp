
#define __STDC_CONSTANT_MACROS  // ???
#define MAX_AUDIO_FRAME_SIZE 192000 // 1 second of 48khz 32bit 
// #define MAX_AUDIO_FRAME_SIZE 192000

extern "C"{
    // #include <libavutil/imgutils.h>
    #include <libavformat/avformat.h>
    #include <libswresample/swresample.h>
    #include <libswscale/swscale.h> 
    #include <libavcodec/avcodec.h>
}
#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <unistd.h>
#include <signal.h>

//#include <ros/ros.h>
// #include <thread>
// #include <pthread.h>
#include "SDL.h"


using std::cout;
using std::endl;
using std::string;
using std::vector;

static volatile int AudioStatus = 1;
void SetAudioStatus(int sig){
    if( sig ==  SIGINT )
    AudioStatus = 0;
}


// void SetAudioSpec(SDL_AudioSpec*,
//                     int a_frep, SDL_AudioFormat a_fromat, int a_channel,
//                     int a_silence, int a_samples, int a_size)
// {}

static  Uint8* audio_chunk;
static  Uint32 audio_len;
static  Uint8* audio_pos;

void  fill_audio_buffer(void* udata, Uint8* stream, int len) 
{
    static int numCallback = 0 ;
    SDL_memset(stream, 0, len);
    if (audio_len == 0)
        return;
    len = (len > audio_len ? audio_len : len);
    SDL_MixAudio(stream, audio_pos, len, SDL_MIX_MAXVOLUME); // play audio
    audio_pos += len;
    audio_len -= len;
    return;
}

int main(int argc, char ** argv)
{
    signal( SIGINT, SetAudioStatus );
    
    string str_url = "rtsp://zlm.robot.genius-pros.com:18554/virtual-robot/900106-900106-573c887e-d19e-47e9-8040-3d1fad20edc8";
    const char* url = str_url.c_str();
    FILE* fw = fopen("outPcm_learnNode.pcm","w");
    if( fw == NULL ){
        cout << "No output file found!" << endl;
        return -1;
    }

    //注册所有可用的文件格式和编解码器
    av_register_all();
    avformat_network_init();

    //打开RTSP流
    AVFormatContext* fmtCtx = NULL;
    AVDictionary* options = NULL;
   
    av_dict_set(&options, "rtsp_transport", "tcp", 0);
    av_dict_set(&options, "stimeout", "3000000", 0);
    av_dict_set(&options, "max_delay", "500000", 0);

    if (avformat_open_input(&fmtCtx, url, NULL, &options) != 0){
        std::cerr << "Could not open input file." << std::endl;
        return -1;
    }
    //查找RTSP流信息
    if (avformat_find_stream_info(fmtCtx, NULL) < 0){
        std::cerr << "Failed to retrieve input stream information." << std::endl;
        return -1;
    }
    //打印流相关信息
    av_dump_format(fmtCtx, 0, url, 0);
    //找到包含流的流索引

    int videoStreamIndex = -1;
    for (int i = 0; i < fmtCtx->nb_streams; i++){  
        if(fmtCtx->streams[i]->codecpar->codec_type == AVMEDIA_TYPE_AUDIO){
            videoStreamIndex = i;
            double fps = fmtCtx->streams[i]->avg_frame_rate.num * 1.0f / fmtCtx->streams[i]->avg_frame_rate.den;
            double interval = 1 * 1000 / fps;
            cout << "[Calc]平均帧率: " << fps << ", 帧间隔: " << interval << " ms" << endl << endl;               
            break;
        }
    }
    if (videoStreamIndex == -1){
        std::cerr<<"Could not find video stream."<<std::endl;
        return -1;
    }

    //获取解码参数
    AVCodecParameters* codecParams = fmtCtx->streams[videoStreamIndex]->codecpar;
    //查找解码器
    AVCodec* pCodec = avcodec_find_decoder(codecParams->codec_id);
    if (pCodec == NULL){
        std::cerr << "Could not find codec." << std::endl;
        return -1;
    }
    //创建并初始化解码器上下文
   
    AVCodecContext* codecCtx = avcodec_alloc_context3(pCodec);
    
    if (codecCtx == NULL){
        std::cerr << "Could not allocate codec context." << std::endl;
        return -1;
    }
    if (avcodec_parameters_to_context(codecCtx, codecParams) < 0){
        std::cerr << "Could not copy codec parameters to context." << std::endl;
        return -1;
    }
    if (avcodec_open2(codecCtx, pCodec, NULL) < 0){
        std::cerr << "Could not open codec." << std::endl;
        return -1;
    }

    //处理流,解码
    AVPacket pkt;
    av_init_packet(&pkt);
    AVFrame* pFrame = av_frame_alloc();

	uint64_t out_channel_layout = AV_CH_LAYOUT_STEREO;  
    
    cout << out_channel_layout << "|" << codecCtx->channel_layout << "|" << fmtCtx->streams[0]->codec->channel_layout << endl;
	int out_nb_samples = codecCtx->frame_size;
	AVSampleFormat out_sample_fmt = AV_SAMPLE_FMT_S16;


	int out_sample_rate = 44100;
	int out_channels = av_get_channel_layout_nb_channels(out_channel_layout);
    cout <<  endl << "OutChannels: " << out_channels << endl << endl;

	int out_buffer_size = av_samples_get_buffer_size(NULL,out_channels ,out_nb_samples,out_sample_fmt, 1);
    


    cout << endl;
    if( SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER | SDL_INIT_AUDIO | SDL_INIT_EVENTS) ){
        cout << "Failed Init SDL" << endl;
    }else {cout << "SDL Created..." << endl;}
    SDL_AudioSpec wanted_spec;
    SDL_AudioSpec actual_spec;
	wanted_spec.freq = codecCtx->sample_rate; 
	wanted_spec.format = AUDIO_S16SYS; 
    
	wanted_spec.channels = codecCtx->channels;
	wanted_spec.silence = 0; 

    wanted_spec.samples = 2048;
	wanted_spec.callback = fill_audio_buffer;

    wanted_spec.userdata = NULL;  

    int ret_open_audio = SDL_OpenAudio(&wanted_spec,&actual_spec);
    if( ret_open_audio == -1 ){
        cout << "Failed Open Audio Device" << endl;
        return -1;
    }
    else if( ret_open_audio == 0 ){
        cout << "SDL Opened Audio Device..." << endl;
    }

	int64_t  in_channel_layout = av_get_default_channel_layout(codecCtx->channels);
	struct SwrContext* au_convert_ctx = swr_alloc();
    // TODO 
	au_convert_ctx = swr_alloc_set_opts(
        au_convert_ctx,
        out_channel_layout, 
        out_sample_fmt,
         out_sample_rate,
		in_channel_layout,
        codecCtx->sample_fmt ,
         codecCtx->sample_rate,
         0, 
         NULL
         );

    

	swr_init(au_convert_ctx);

   
	uint8_t* out_buffer = (uint8_t *)av_malloc(MAX_AUDIO_FRAME_SIZE*2);
  
    SDL_PauseAudio(0);  

    int index = 0;
    int counter = 0;
    int gotFrame = 0;
    int ret;
    while( AudioStatus && (av_read_frame(fmtCtx,&pkt) == 0) ){  // av_new_packet()  返回流的下一帧
        
        if(pkt.stream_index==videoStreamIndex){
            ret = avcodec_decode_audio4(codecCtx,pFrame,&gotFrame,&pkt);
            if( ret < 0)
            {
                std::cerr << "Error decoding frame." << std::endl;
                break;
            }
            if(!gotFrame){
                cout << "$Not got Frame$" << endl;
            }
            if(gotFrame)
            {
                out_buffer = (Uint8 *)pFrame->data[0];
                printf("index:%5d\t stream_index:%5d\t dts:%lld\t pts:%lld\t packet size:%d\t duration:%lld\t pos:%lld\n ", index, pkt.stream_index, pkt.dts, pkt.pts, pkt.size, pkt.duration, pkt.pos);

                fwrite(out_buffer, 1, out_buffer_size, fw);
                index++;
            }


            SDL_Delay(23);
			audio_chunk = (Uint8 *) out_buffer; 
			audio_len = out_buffer_size;
			audio_pos = audio_chunk;
        }
    }
    cout << "read frame done..." << endl;

    fclose(fw);

    SDL_CloseAudio();
    SDL_Quit();


    av_frame_free(&pFrame);  // av_free_packet(&pkt);
    avcodec_free_context(&codecCtx);
    avformat_close_input(&fmtCtx);
    cout << "Exit..." << endl;
    return 0;
}