cmake_minimum_required(VERSION 3.15)


project(ScratchedHologramFrom3D VERSION 0.0.0)

enable_testing()

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wall")
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

IF(MINGW)
    set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -static-libgcc -static-libstdc++ -Wl,-allow-multiple-definition")
    set(CMAKE_SHARED_LINKER_FLAGS "${CMAKE_SHARED_LINKER_FLAGS} -static-libgcc -static-libstdc++ -Wl,-allow-multiple-definition")
    set(CMAKE_STATIC_LIBRARY_FLAGS "${CMAKE_STATIC_LIBRARY_FLAGS} -static-libgcc -static-libstdc++ -Wl,-allow-multiple-definition")
ENDIF(MINGW)

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
add_subdirectory(libs/CLITools)
add_subdirectory(libs/File2DProcessingTools)
add_subdirectory(libs/File3DProcessingTools)
add_subdirectory(libs/Geometry2D)
add_subdirectory(libs/Geometry3D)

add_subdirectory(test)
