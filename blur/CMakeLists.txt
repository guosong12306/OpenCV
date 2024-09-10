cmake_minimum_required(VERSION 3.16)
include_directories(.)
project(blur)

find_package(OpenCV REQUIRED)
include_directories(
    ${OpenCV_INCLUDE_DIRS}
    )
    link_directories(
        ${OpenCV_LIBS}
    )
add_executable(blur src/main.cpp)
target_link_libraries(blur ${OpenCV_LIBS})