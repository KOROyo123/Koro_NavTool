cmake_minimum_required(VERSION 3.5)

project(str_mult LANGUAGES C)


set(SOURCES
    main.c
)

add_executable(${PROJECT_NAME} ${SOURCES})

include_directories(${PROJECT_NAME}  ${CMAKE_SOURCE_DIR}/third/rtklib)
target_link_libraries(${PROJECT_NAME}  ${CMAKE_BINARY_DIR}/third/rtklib/librtklib.a)

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
