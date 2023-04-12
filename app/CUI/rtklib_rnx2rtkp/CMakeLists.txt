cmake_minimum_required(VERSION 3.5)

project(rtklib_rnx2rtkp LANGUAGES CXX)

#版本14以下可能会导致abseil不支持
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)



#包含的源文件和头文件
IF(CMAKE_HOST_SYSTEM_NAME MATCHES "Windows")
set(SOURCES
    rnx2rtkp_win.cpp
)
ENDIF()
IF(CMAKE_HOST_SYSTEM_NAME MATCHES "Linux")
set(SOURCES
    rnx2rtkp.cpp
)
ENDIF()

#生成的可执行文件名称和包含的文件
add_executable(${PROJECT_NAME} ${SOURCES})


#rtklib
include_directories(${CMAKE_SOURCE_DIR}/third/rtklib)
target_link_libraries(${PROJECT_NAME}  ${CMAKE_BINARY_DIR}/third/rtklib/librtklib.a)
#如果是windows环境，则rtklib还需要加两个库
IF(CMAKE_HOST_SYSTEM_NAME MATCHES "Windows")
target_link_libraries(${PROJECT_NAME} Ws2_32 winmm)
ENDIF()
#如果是linux环境，需要手动链接math.h pthread库
IF(CMAKE_HOST_SYSTEM_NAME MATCHES "Linux")
target_link_libraries(${PROJECT_NAME} m pthread)
ENDIF()


# Eigen3
include_directories(${CMAKE_SOURCE_DIR}/third/eigen-3.4.0)

## yaml-cpp-0.7.0
include_directories(${CMAKE_SOURCE_DIR}/third/yaml-cpp-0.7.0)
target_link_libraries(${PROJECT_NAME} yaml-cpp)


