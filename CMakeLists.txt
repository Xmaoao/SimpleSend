cmake_minimum_required(VERSION 3.10)

project(Simplesend)

message(STATUS "STATUS> Accessing folder ./GUI \n")

add_subdirectory(GUI)
# build SimplesendGUI

message(STATUS "STATUS> Leaving folder ./GUI \n")

include_directories(include)
include_directories(${PROJECT_SOURCE_DIR}/lib/md5/include)

message(STATUS "STATUS> Start linking static libraries")

set(CMAKE_FIND_LIBRARY_SUFFIXES ".a")
# link static lib first

message(STATUS "LINK>   Link gflags static lib")
find_package(gflags REQUIRED)
message(STATUS "LINK>   Link glog static lib")
find_package(glog REQUIRED)

message(STATUS "LINK>   Link MD5 calculate static lib")
link_directories(${PROJECT_SOURCE_DIR}/lib/md5/lib)

message(STATUS "STATUS> Finish linking static libraries \n")

message(STATUS "STATUS> Accessing folder ./src \n")

add_subdirectory(src)

message(STATUS "STAUTS> Leaving folder ./src \n")

set(MAIN main.cpp)
#set(MAIN test.cpp)
# test file

message(STATUS "FILE>   main file: " ${MAIN} "\n")

if((EXISTS ${PROJECT_SOURCE_DIR}/bin) AND (${REBUILT_GUI} STREQUAL "YES"))
    file(REMOVE_RECURSE ${PROJECT_SOURCE_DIR}/bin)
endif()

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin)

add_executable(Simplesend ${SRC_LIST} ${MAIN})

target_link_libraries(Simplesend 
    gflags
    glog::glog
    libmd5fcxx.a
)

if(${REBUILT_GUI} STREQUAL "YES")
    message(STATUS "STATUS> Start copying GUI target")
    file(COPY ${PROJECT_SOURCE_DIR}/GUI/dist/SimplesendGUI
         DESTINATION ${PROJECT_SOURCE_DIR}/bin)
    message(STATUS "STATUS> Finish copying GUI target \n")
endif()