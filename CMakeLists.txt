set(CMAKE_VERSION 3.26)
set(CMAKE_CXX_STANDARD 17)
cmake_minimum_required(VERSION ${CMAKE_VERSION})
project(17B23)
set(LIB_PATH ${CMAKE_CURRENT_SOURCE_DIR}/lib)# 静态库生成的路径
set(EXEC_PATH ${CMAKE_CURRENT_SOURCE_DIR}/bin)# 测试程序生成的路径
#set(C_LIB fc)
#add_subdirectory(c)
set(CM_LIB fcm)
add_subdirectory(cm)
#set(CC_LIB fcc)
#add_subdirectory(cc)
add_subdirectory(test)