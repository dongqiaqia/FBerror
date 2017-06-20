cmake_minimum_required(VERSION 2.8)
project(FB)

set(CMAKE_BUILD_TYPE "Debug")
SET(CMAKE_CXX_FLAGS_DEBUG "$ENV{CXXFLAGS} -O0 -Wall -g -ggdb ")
#SET(CMAKE_CXX_FLAGS_RELEASE "$ENV{CXXFLAGS} -O3 -Wall")


find_package(OpenCV REQUIRED)
message("OpenCV version is ${OpenCV_VERSION}")
message("OpenCV_DIR is ${OpenCV_DIR}")

if(NOT WIN32)
ADD_DEFINITIONS("-std=c++0x -O3")
endif(NOT WIN32)

add_library (${PROJECT_NAME}
FBerror.cpp
main.cpp

FBerror.h
)

add_executable (main main.cpp)
target_link_libraries(${PROJECT_NAME} ${OpenCV_LIBS})
target_link_libraries (main ${PROJECT_NAME})
