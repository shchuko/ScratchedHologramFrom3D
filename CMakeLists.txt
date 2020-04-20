cmake_minimum_required(VERSION 3.15)

project(ScratchedHologramFrom3D VERSION 0.0.0)

enable_testing()

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wall")
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_compile_definitions(PROJECT_SOURCE_DIR="${CMAKE_CURRENT_SOURCE_DIR}")

add_subdirectory(./extern)

add_subdirectory(libs/CliTools)
add_subdirectory(libs/Geometry2D)
add_subdirectory(libs/Geometry3D)
add_subdirectory(libs/File2DProcessingTools)
add_subdirectory(libs/File3DProcessingTools)
add_subdirectory(libs/ScratchProjectionMaths)

set(App_INCLUDES ${CMAKE_CURRENT_SOURCE_DIR}/include)
file(GLOB App_HEADERS ${CMAKE_CURRENT_SOURCE_DIR}/include/*.hpp)
file(GLOB App_SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/source/*.cpp)
list(REMOVE_ITEM App_SOURCES main.cpp)

add_library(ScratchedHologramFrom3DAppLib ${App_HEADERS} ${App_SOURCES})
target_include_directories(ScratchedHologramFrom3DAppLib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

find_package(Threads REQUIRED)
target_link_libraries(ScratchedHologramFrom3DAppLib ${CMAKE_THREAD_LIBS_INIT})

add_executable(ScratchedHologramFrom3DApp source/main.cpp)
target_link_libraries(ScratchedHologramFrom3DApp ScratchedHologramFrom3DAppLib)

set_target_properties(ScratchedHologramFrom3DApp
        PROPERTIES
        ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
        LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
        RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
        )

set_target_properties(ScratchedHologramFrom3DAppLib
        PROPERTIES
        ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
        LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
        RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
        )

add_subdirectory(test)
