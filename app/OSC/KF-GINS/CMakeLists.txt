cmake_minimum_required(VERSION 3.10)
project(KF-GINS)

set(CMAKE_CXX_STANDARD 14)

#set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)
#set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib)

if ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "MSVC")
    add_definitions( -D_USE_MATH_DEFINES=True)
    add_compile_options("$<$<C_COMPILER_ID:MSVC>:/utf-8>")
    add_compile_options("$<$<CXX_COMPILER_ID:MSVC>:/utf-8>")
else()
    set(CMAKE_CXX_FLAGS "-Wno-unused-result")
endif()

file(GLOB_RECURSE SOURCE
        src/kf_gins.cpp
        src/fileio/fileloader.cc
        src/fileio/filesaver.cc
        src/kf-gins/gi_engine.cpp
        src/kf-gins/insmech.cpp)

include_directories(${PROJECT_SOURCE_DIR}/src)
add_executable(${PROJECT_NAME} ${SOURCE})

# Eigen3
include_directories(${CMAKE_SOURCE_DIR}/third/eigen-3.4.0)

# yaml-cpp-0.7.0
include_directories(${CMAKE_SOURCE_DIR}/third/yaml-cpp-0.7.0)
target_link_libraries(${PROJECT_NAME} yaml-cpp)

## abseil
set(ABSL_PROPAGATE_CXX_STD true)
include_directories(${CMAKE_SOURCE_DIR}/third/abseil-cpp-20230125.2)
target_link_libraries(${PROJECT_NAME}
        absl::strings
        absl::str_format
        absl::time)
