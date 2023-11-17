cmake_minimum_required(VERSION 3.26)
project(treeTest)
aux_source_directory(. SRC_LIST)
#link_directories(${LIB_PATH})
add_executable(${APP_NAME} ${SRC_LIST})
target_link_libraries(${APP_NAME} ${CORE_LIB})
set(DBG_PATH "${CMAKE_CURRENT_BINARY_DIR}/cmake-build-debug/")

#https://blog.csdn.net/qq_45414478/article/details/128818388
add_custom_command(TARGET ${APP_NAME}  POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
        "${CMAKE_CURRENT_BINARY_DIR}/../${CORE_LIB}/lib${CORE_LIB}.dll"
        ${CMAKE_CURRENT_BINARY_DIR})