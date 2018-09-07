cmake_minimum_required(VERSION 3.0)
project(RTSPProxy)

set(NATIVE ${CMAKE_CURRENT_SOURCE_DIR}/native)
set(WRAPPER ${CMAKE_CURRENT_SOURCE_DIR}/wrapper)

add_subdirectory(${NATIVE})
add_subdirectory(${WRAPPER})