cmake_minimum_required(VERSION 3.0)
project(audio_player)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g")

# 设置 C++17 标准
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


find_package(PkgConfig REQUIRED)
pkg_search_module(GST REQUIRED gstreamer-1.0)
pkg_search_module(GST_RTSP REQUIRED gstreamer-rtsp-server-1.0)
#pkg_check_modules(PULSEAUDIO REQUIRED libpulse)

include_directories(${GST_INCLUDE_DIRS} ${GST_RTSP_INCLUDE_DIRS})
link_directories(${GST_LIBRARY_DIRS} ${GST_RTSP_LIBRARY_DIRS})

add_executable(rtsp_server audio_player.cc)
target_link_libraries(rtsp_server ${GST_LIBRARIES} ${GST_RTSP_LIBRARIES})



# 
# add_executable(audio_player audio_player.cc)
# add_executable(learn learn.cpp)
# add_executable(play_audio play_audio.cc)
# add_executable(ffplay ffplayer.cc)
# target_include_directories(audio_player PUBLIC ${GST_INCLUDE_DIRS})
# target_link_libraries(audio_player
       
#         ${GST_LIBRARIES}
#         )

# target_link_libraries(
#         learn
#         ${SDL2_LIBRARIES}
#         avformat
#         avcodec
#         avutil
#         swresample
#         ${GST_LIBRARIES}
#         )

# target_link_libraries(
#         play_audio
#         ${SDL2_LIBRARIES}
#         avformat
#         avcodec
#         avutil
#         swresample
#         ${GST_LIBRARIES}
#         )

# target_link_libraries(
#         ffplay
#         ${SDL2_LIBRARIES}
#         avformat
#         avcodec
#         avutil
#         swresample
#         ${GST_LIBRARIES}

#         )


# 链接 GStreamer 库
#target_link_libraries(audio_player ${GST_LIBRARIES} -lcurl -lavformat -lavcodec -lavutil 
#libavformat libavcodec libavutil libswresample sdl2 -lm -lpthread)
