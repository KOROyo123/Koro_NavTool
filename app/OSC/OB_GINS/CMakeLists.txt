cmake_minimum_required(VERSION 3.12)
project(ob_gins)

set(CMAKE_CXX_STANDARD 14)

if (CMAKE_BUILD_TYPE MATCHES "Debug")
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")
else ()
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -O3")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -O3")
endif ()

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)

file(GLOB_RECURSE SOURCE
        src/ob_gins.cc
        src/fileio/fileloader.cc
        src/fileio/filesaver.cc
        src/preintegration/preintegration_base.cc
        src/preintegration/preintegration_normal.cc
        src/preintegration/preintegration_earth.cc
        src/preintegration/preintegration_odo.cc
        src/preintegration/preintegration_earth_odo.cc)

include_directories(${PROJECT_SOURCE_DIR})
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

# Ceres
include_directories(${CMAKE_SOURCE_DIR}/third/ceres-solver-2.0.0)
include_directories(${CMAKE_SOURCE_DIR}/third/ceres-solver-2.0.0/include)

target_link_libraries(${PROJECT_NAME} ${CERES_LIBRARIES})

include_directories(${CMAKE_SOURCE_DIR}/third/ceres-solver-2.0.0/internal)
include_directories(${CMAKE_SOURCE_DIR}/third/ceres-solver-2.0.0/internal/ceres/miniglog)
#find_package(Ceres REQUIRED)

