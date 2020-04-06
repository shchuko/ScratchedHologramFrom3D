cmake_minimum_required(VERSION 3.15)


project(ScratchedHologramFrom3D VERSION 0.0.0)

enable_testing()

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wall")
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(TEST_RESOURCES_FILES ${PROJECT_SOURCE_DIR})
add_compile_definitions(PROJECT_SOURCE_DIR="${PROJECT_SOURCE_DIR}")

set(COMMON_INCLUDES ${PROJECT_SOURCE_DIR}/include)
include_directories(${COMMON_INCLUDES})

file(GLOB SRC_FILES ${PROJECT_SOURCE_DIR}/source/*.cpp)

add_library(app_lib SHARED ${SRC_FILES})
set_target_properties(app_lib
        PROPERTIES
        ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
        LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
        RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
        )

add_subdirectory(./extern)

add_subdirectory(ScratchedHologramFrom3DCLI)
add_subdirectory(libs/CliTools)
add_subdirectory(libs/File2DProcessingTools)
add_subdirectory(libs/File3DProcessingTools)
add_subdirectory(libs/Geometry2D)
add_subdirectory(libs/Geometry3D)

target_link_libraries(app_lib Geometry3D)
target_link_libraries(app_lib Geometry2D)
target_link_libraries(app_lib CliTools)
target_link_libraries(app_lib File2DProcessingTools)
target_link_libraries(app_lib File3DProcessingTools)

add_subdirectory(test)
