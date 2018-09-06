cmake_minimum_required(VERSION 3.0)
project(NativeRtspProxy)

set(CPACK_PACKAGE_NAME "NativeRtspProxy")
set(CPACK_PACKAGE_VERSION_MAJOR 1)
set(CPACK_PACKAGE_VERSION_MINOR 0)
set(CPACK_PACKAGE_VERSION_PATCH 0)

set(CMAKE_WARNINGE_MAKEFILE OFF)
set_property(GLOBAL PROPERTY USE_FOLDERS ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")

if (CMAKE_SIZEOF_VOID_P EQUAL 8)
	message ("Compiling will be for x64")
	set (x64 1)
elseif()
	message ("Compiling will be for x86")
	set (x64 0)	
endif()


if(BUILD_TYPE EQUAL "Debug")
	set(CMAKE_BUILD_TYPE Debug)
elseif(BUILD_TYPE EQUAL "Release")
	set(CMAKE_BUILD_TYPE Reelase)
endif()

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/live555/BasicUsageEnvironment/include
					${CMAKE_CURRENT_SOURCE_DIR}/live555/groupsock/include
					${CMAKE_CURRENT_SOURCE_DIR}/live555/liveMedia/include
					${CMAKE_CURRENT_SOURCE_DIR}/live555/UsageEnvironment/include)

file(GLOB SOURCES "*.c*")
file(GLOB HEADERS "*.h*")

file(GLOB LIVE555_SOURCES 	"${CMAKE_CURRENT_SOURCE_DIR}/live555/BasicUsageEnvironment/*.c*"
							"${CMAKE_CURRENT_SOURCE_DIR}/live555/groupsock/*.c*"
							"${CMAKE_CURRENT_SOURCE_DIR}/live555/liveMedia/*.c*"
							"${CMAKE_CURRENT_SOURCE_DIR}/live555/UsageEnvironment/*.c*")					
source_group("live555" FILES ${LIVE555_SOURCES})

if(MSVC)
    add_definitions(-D_CRT_SECURE_NO_WARNINGS -D_WINSOCK_DEPRECATED_NO_WARNINGS)
endif()

add_executable(${PROJECT_NAME} ${SOURCES} ${HEADERS} ${LIVE555_SOURCES})
target_link_libraries(${PROJECT_NAME} debug "ws2_32.lib" optimized "ws2_32.lib")