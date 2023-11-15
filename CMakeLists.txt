cmake_minimum_required(VERSION 3.0)
project(audio_player)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g")
set(CMAKE_CXX_STANDARD 11)

# 添加包含目录
find_package(PkgConfig)
pkg_check_modules(GST REQUIRED gstreamer-1.0)
include_directories(${GST_INCLUDE_DIRS})

#add_executable(audio_player audio_player.cc)

# 将头文件目录与目标关联
#target_include_directories(audio_player PUBLIC ${GST_INCLUDE_DIRS})



find_package(SDL2 REQUIRED)

include_directories(${SDL2_INCLUDE_DIRS} ${GST_INCLUDE_DIRS})

add_executable(audio_player audio_player.cc)
add_executable(learn learn.cpp)
add_executable(play_audio play_audio.cc)
add_executable(ffplay ffplayer.cc)

target_link_libraries(audio_player
        ${SDL2_LIBRARIES}
        avformat
        avcodec
        avutil
        swresample
        ${GST_LIBRARIES}
        )

target_link_libraries(
        learn
        ${SDL2_LIBRARIES}
        avformat
        avcodec
        avutil
        swresample
        ${GST_LIBRARIES}
        )

target_link_libraries(
        play_audio
        ${SDL2_LIBRARIES}
        avformat
        avcodec
        avutil
        swresample
        ${GST_LIBRARIES}
        )

target_link_libraries(
        ffplay
        ${SDL2_LIBRARIES}
        avformat
        avcodec
        avutil
        swresample
        ${GST_LIBRARIES}
        )


# 链接 GStreamer 库
#target_link_libraries(audio_player ${GST_LIBRARIES} -lcurl -lavformat -lavcodec -lavutil 
#libavformat libavcodec libavutil libswresample sdl2 -lm -lpthread)
