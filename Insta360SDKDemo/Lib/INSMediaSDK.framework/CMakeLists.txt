cmake_minimum_required(VERSION 3.2)
project(llog)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp llog.cpp llog.h llog_message.cpp llog_message.h)

link_libraries(pthread)
add_executable(llog ${SOURCE_FILES})