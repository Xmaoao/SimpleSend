cmake_minimum_required(VERSION 3.10)

project(Simplesend)

add_subdirectory(GUI)

if(EXISTS ${PROJECT_SOURCE_DIR}/bin)
    file(REMOVE_RECURSE ${PROJECT_SOURCE_DIR}/bin)
endif()

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin)

file(COPY ${PROJECT_SOURCE_DIR}/GUI/dist/SimplesendGUI
     DESTINATION ${PROJECT_SOURCE_DIR}/bin)