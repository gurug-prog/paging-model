cmake_minimum_required(VERSION 3.21)

project(paging-model)

include_directories(src)

file(GLOB SOURCES "src/*.c" "src/allocator/*.c")

add_executable(${PROJECT_NAME} ${SOURCES})
