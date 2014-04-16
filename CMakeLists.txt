cmake_minimum_required(VERSION 2.8)
project(Rougelike)

add_subdirectory(${PROJECT_SOURCE_DIR}/src)
add_subdirectory(${PROJECT_SOURCE_DIR}/src/Framework/src/)
include_directories("src")
include_directories("src/Framework/src")

if ("${CMAKE_CXX_COMPILER_ID}" MATCHES "GNU")
	list(APPEND CMAKE_CXX_FLAGS "-std=c++11")
endif()

set(LIBRARIES SDL2)

set(CMAKE_BUILD_TYPE DEBUG)

set(PROJECT_BIN_DIR "${CMAKE_BINARY_DIR}/bin")

add_executable(roguelike ${FRAMEWORK_SOURCES} ${SOURCES})
target_link_libraries(roguelike ${LIBRARIES})

if(DEFINED BUILD_TEST_PROGRAMS)
	message("Building test binaries...")
	add_subdirectory(${PROJECT_SOURCE_DIR}/test)
endif()

set_target_properties(roguelike PROPERTIES 
	RUNTIME_OUTPUT_DIRECTORY_DEBUG "${PROJECT_BIN_DIR}/debug"
	RUNTIME_OUTPUT_DIRECTORY "${PROJECT_BIN_DIR}/release")
