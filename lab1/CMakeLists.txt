cmake_minimum_required(VERSION 3.21)

set(CMAKE_CXX_STANDARD 23)
include_directories(include)

aux_source_directory(. DIR_SRCS)
add_executable(lab1 ${DIR_SRCS})
