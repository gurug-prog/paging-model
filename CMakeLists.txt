cmake_minimum_required(VERSION 3.21)

project(paging-model)

include_directories(src)

file(GLOB_RECURSE SOURCES "src/*.c")

add_executable(${PROJECT_NAME} ${SOURCES})
