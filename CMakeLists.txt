cmake_minimum_required(VERSION 3.10)

project(Simplesend)

message(STATUS "STATUS> Start building GUI target")

add_subdirectory(GUI)
# build SimplesendGUI

message(STATUS "STATUS> Finish building GUI target")

set(CMAKE_FIND_LIBRARY_SUFFIXES ".a")
# link static lib first

find_package(gflags REQUIRED)
find_package(glog REQUIRED)

add_subdirectory(src)

#set(MAIN main.cpp)
set(MAIN test.cpp)

message(STATUS "FILE>   main file: " ${MAIN})
message(STATUS "FILE>   src list:  " ${SRC_LIST})

if(EXISTS ${PROJECT_SOURCE_DIR}/bin)
    file(REMOVE_RECURSE ${PROJECT_SOURCE_DIR}/bin)
endif()

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin)

add_executable(Simplesend ${SRC_LIST} ${MAIN})

target_link_libraries(Simplesend 
    gflags
    glog::glog
)

message(STATUS "STATUS> Start copying GUI target")

file(COPY ${PROJECT_SOURCE_DIR}/GUI/dist/SimplesendGUI
     DESTINATION ${PROJECT_SOURCE_DIR}/bin)

message(STATUS "STATUS> Finish copying GUI target")