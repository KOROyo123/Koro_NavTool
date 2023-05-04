add_subdirectory(KF-GINS/)


IF(CMAKE_HOST_SYSTEM_NAME MATCHES "Linux")
add_subdirectory(OB_GINS/)
ENDIF()
