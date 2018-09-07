cmake_minimum_required(VERSION 3.0)
project(RTSPProxySample)

set(SOURCE ${CMAKE_CURRENT_SOURCE_DIR}/source)
add_subdirectory(${SOURCE})

include_directories(${SOURCE})
file(GLOB MAIN "*.c*")

add_executable(${PROJECT_NAME} ${MAIN})
target_link_libraries(${PROJECT_NAME} RTSPProxy)