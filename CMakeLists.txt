project(sort)
cmake_minimum_required(VERSION 2.8)
find_package(OpenCV REQUIRED)
aux_source_directory(. SRC_LIST)
add_definitions(-std=c++11)
add_executable(${PROJECT_NAME} main.cpp)
target_link_libraries(${PROJECT_NAME} ${OpenCV_LIBS})

