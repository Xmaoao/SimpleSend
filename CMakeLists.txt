cmake_minimum_required(VERSION 3.10)

project(Simplesend)

add_subdirectory(GUI)
# build SimplesendGUI

find_package(gflags REQUIRED)
# link gflags lib

add_subdirectory(src)

set(MAIN main.cpp)

message(STATUS "
main file: " ${MAIN})

message(STATUS "
src list:  " ${SRC_LIST})

if(EXISTS ${PROJECT_SOURCE_DIR}/bin)
    file(REMOVE_RECURSE ${PROJECT_SOURCE_DIR}/bin)
endif()

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin)

add_executable(Simplesend ${SRC_LIST} ${MAIN})

target_link_libraries(Simplesend gflags)

file(COPY ${PROJECT_SOURCE_DIR}/GUI/dist/SimplesendGUI
     DESTINATION ${PROJECT_SOURCE_DIR}/bin)