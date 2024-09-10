cmake_minimum_required(VERSION 3.16)
include_directories(.)
project(bit)

find_package(OpenCV REQUIRED)
include_directories(
    ${OpenCV_INCLUDE_DIRS}
    )
    link_directories(
        ${OpenCV_LIBS}
    )
add_executable(bit src/main.cpp)
target_link_libraries(bit ${OpenCV_LIBS})