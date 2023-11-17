cmake_minimum_required(VERSION 3.26)
project(17B23)
set(CMAKE_CXX_STANDARD 17)
set(HEAD_PATH ${CMAKE_CURRENT_SOURCE_DIR}/core/include)# 头文件目录
set(CORE_LIB core)# 静态库的名字
set(APP_NAME test)# 可执行程序的名字
include_directories(${HEAD_PATH})
add_subdirectory(core)
add_subdirectory(test)