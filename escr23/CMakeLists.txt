cmake_minimum_required(VERSION 3.5.1)

set(TARGET escr23)
set(CMAKE_BUILD_TYPE Debug)
file(GLOB SOURCES src/*)

add_library(${TARGET} ${SOURCES})

target_include_directories(${TARGET} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

target_compile_features(${TARGET} PUBLIC cxx_std_20)
