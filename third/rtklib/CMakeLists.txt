cmake_minimum_required(VERSION 3.14)

project(rtklib LANGUAGES C)

add_definitions(-D_RTLDLL -DNO_STRICT -DTRACE -DENAGLO -DENAQZS -DENAGAL -DENACMP -DENAIRN -DNFREQ=3 -DNEXOBS=3 -DEXTLEX -DQT)


set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(SOURCES
    rtklib_global.h
    rtklib.h
    rtkcmn.c
    convkml.c
    convrnx.c
    convgpx.c
    datum.c
    download.c
    ephemeris.c
    geoid.c
    gis.c
    ionex.c
    lambda.c
    options.c
    pntpos.c
    postpos.c
    ppp.c
    ppp_ar.c
    preceph.c
    rcvraw.c
    rinex.c
    rtcm.c
    rtcm2.c
    rtcm3.c
    rtcm3e.c
    rtkpos.c
    rtksvr.c
    sbas.c
    solution.c
    stream.c
    streamsvr.c
    tides.c
    tle.c
    rcv/binex.c
    rcv/crescent.c
    rcv/javad.c
    rcv/novatel.c
    rcv/nvs.c
    rcv/rt17.c
    rcv/septentrio.c
    rcv/skytraq.c
    rcv/ss2.c
    rcv/ublox.c
)



add_library(rtklib STATIC
  ${SOURCES}
)


target_include_directories(rtklib PUBLIC)

#include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

#target_compile_definitions(rtklib PRIVATE RTKLIB_LIBRARY)
