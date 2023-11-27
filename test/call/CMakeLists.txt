cmake_minimum_required(VERSION ${CMAKE_VERSION})
project(${CALL_LIB})
aux_source_directory(. SRC_LIST)
#遍历SRC_LIST，为每个文件生成一个可执行文件
#find_package(Armadillo REQUIRED PATHS "$ENV{VCPKG_HOME}/installed/x64-windows/share/Armadillo")# vcpkg version
find_package(Armadillo REQUIRED) # default version
foreach (file ${SRC_LIST})
    get_filename_component(file_name ${file} NAME_WE)
    set(APP_NAME "${PROJECT_NAME}_${file_name}")
    add_executable(${APP_NAME} ${file})
    target_link_libraries(${APP_NAME} PRIVATE ${ARMADILLO_LIBRARIES} ${CALL_LIB})
    target_include_directories(${APP_NAME} PRIVATE ${ARMADILLO_INCLUDE_DIRS})
    #    target_link_libraries(${APP_NAME} ${CALL_LIB})
endforeach ()
#message(STATUS "SRC_LIST: ${SRC_LIST}")
#set(APP_NAME "${PROJECT_NAME}t")
#add_executable(${APP_NAME} ${SRC_LIST})
#target_link_libraries(${APP_NAME} ${CM_LIB})

#add_executable()