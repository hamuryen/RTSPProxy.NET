cmake_minimum_required(VERSION 3.0)
project(RTSPProxy)

set(CPACK_PACKAGE_NAME "RTSPProxy")
set(CPACK_PACKAGE_VERSION_MAJOR 1)
set(CPACK_PACKAGE_VERSION_MINOR 0)
set(CPACK_PACKAGE_VERSION_PATCH 0)

set(CMAKE_WARNINGE_MAKEFILE OFF)
set_property(GLOBAL PROPERTY USE_FOLDERS ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../live555/BasicUsageEnvironment/include
					${CMAKE_CURRENT_SOURCE_DIR}/../live555/groupsock/include
					${CMAKE_CURRENT_SOURCE_DIR}/../live555/liveMedia/include
					${CMAKE_CURRENT_SOURCE_DIR}/../live555/UsageEnvironment/include)

file(GLOB SOURCES "*.c*")
file(GLOB HEADERS "*.h*")

file(GLOB LIVE555_SOURCES 	"${CMAKE_CURRENT_SOURCE_DIR}/../live555/BasicUsageEnvironment/*.c*"
							"${CMAKE_CURRENT_SOURCE_DIR}/../live555/groupsock/*.c*"
							"${CMAKE_CURRENT_SOURCE_DIR}/../live555/liveMedia/*.c*"
							"${CMAKE_CURRENT_SOURCE_DIR}/../live555/UsageEnvironment/*.c*")					

source_group("live555" FILES ${LIVE555_SOURCES})

add_definitions(-D_CRT_SECURE_NO_WARNINGS -D_WINSOCK_DEPRECATED_NO_WARNINGS)
add_library(${PROJECT_NAME} SHARED ${SOURCES} ${HEADERS} ${LIVE555_SOURCES})
target_link_libraries(${PROJECT_NAME} debug "ws2_32.lib" optimized "ws2_32.lib")