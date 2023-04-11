add_subdirectory(str_mult/)
add_subdirectory(svr_core/)
add_subdirectory(template/)


add_subdirectory(rtklib_str2str/)
add_subdirectory(rtklib_rnx2rtkp/)




IF(CMAKE_HOST_SYSTEM_NAME MATCHES "Linux")
add_subdirectory(rtklib_rtkrcv/)
ENDIF()
