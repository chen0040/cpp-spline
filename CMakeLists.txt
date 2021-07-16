cmake_minimum_required(VERSION 2.8.12)
project(spline_proj)


set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall  -O3 -march=native")

set(SRCS_SPLINE
    spline/src/main/cpp/Bezier.cpp
    spline/src/main/cpp/BSpline.cpp
    spline/src/main/cpp/CatmullRom.cpp
    spline/src/main/cpp/Curve.cpp
    spline/src/main/cpp/Vector.cpp)

include_directories(
    ${PROJECT_SOURCE_DIR}/spline/src/main/cpp
)

add_library(${PROJECT_NAME} SHARED ${SRCS_SPLINE})
add_executable(spline_app
    spline/src/test/cpp/main.cpp)
target_link_libraries(spline_app ${PROJECT_NAME})

