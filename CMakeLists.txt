cmake_minimum_required(VERSION 3.0)
project(lambda)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O3")

set(CMAKE_CXX_STANDARD 14)

if(BUILD_TEST)
    find_package(GTest REQUIRED)
    find_package(GMock REQUIRED)
endif()
if(BUILD_BENCHMARK)
    find_package(benchmark REQUIRED)
endif()

add_library(lambda INTERFACE)

target_include_directories(lambda
  INTERFACE
    $<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}/lib>
    $<INSTALL_INTERFACE:lib/>)

if(BUILD_DEMO)
	add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/demo)
endif()
if(BUILD_TEST)
	add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/test)
endif()
if(BUILD_BENCHMARK)
	add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/bench)
endif()

# Create an install target
install(TARGETS lambda
        EXPORT lambda-config
        INCLUDES DESTINATION include)

install(EXPORT lambda-config
        FILE lambda-config.cmake
        NAMESPACE lambda::
        DESTINATION share/lambda/cmake)

install(DIRECTORY lib/lambda
        DESTINATION include)