cmake_minimum_required(VERSION 3.2)
project(Callcenter)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -pthread")

set(SOURCE_FILES main.cpp)
add_executable(Callcenter ${SOURCE_FILES} Mitarbeiter.cpp Mitarbeiter.h Anrufer.cpp Anrufer.h Callcenter.cpp Callcenter.h CallerQueue.cpp CallerQueue.h)