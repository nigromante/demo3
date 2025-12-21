cmake_minimum_required(VERSION 3.5.1)

set(TARGET test)
set(LIBS escr23 common)
set(CMAKE_BUILD_TYPE Debug)

file(GLOB SOURCES src/*)

add_executable(${TARGET} ${SOURCES})

target_include_directories(${TARGET} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_link_libraries(${TARGET} ${LIBS})

target_compile_features(${TARGET} PUBLIC cxx_std_20)
