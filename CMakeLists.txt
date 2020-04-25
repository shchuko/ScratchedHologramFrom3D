cmake_minimum_required(VERSION 3.15)

project(ScratchedHologramFrom3D VERSION 0.0.1)

# Options can be used:
#option(SCRATCH_STATIC_LIB_LINKING "Static linking enabled" ON)
#option(DISABLE_TESTING "Tests compiling disabled" ON)

if (DISABLE_TESTING)
    message(STATUS "Tests compiling disabled")
else (DISABLE_TESTING)
    message(STATUS "Tests compiling enabled")
    enable_testing()
endif (DISABLE_TESTING)


set(CMAKE_INSTALL_PATH "$ORIGIN")
set(CMAKE_BUILD_RPATH_USE_ORIGIN TRUE)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wall")
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_compile_definitions(PROJECT_SOURCE_DIR="${CMAKE_CURRENT_SOURCE_DIR}")
add_compile_definitions(PROJECT_VERSION_DEF="${PROJECT_VERSION}")

if (DISABLE_TESTING)
    message(STATUS "Googletest subdirectory add skipped due to disabled testing")
else (DISABLE_TESTING)
    add_subdirectory(./extern/googletest)
endif (DISABLE_TESTING)

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

if (SCRATCH_STATIC_LIB_LINKING)
    message(STATUS "ScratchedHologramFrom3D project libs will be static-linked")
    add_library(ScratchedHologramFrom3DAppLib STATIC ${App_HEADERS} ${App_SOURCES})
else (SCRATCH_STATIC_LIB_LINKING)
    add_library(ScratchedHologramFrom3DAppLib SHARED ${App_HEADERS} ${App_SOURCES})
endif (SCRATCH_STATIC_LIB_LINKING)

target_include_directories(ScratchedHologramFrom3DAppLib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

find_package(Threads REQUIRED)
target_link_libraries(ScratchedHologramFrom3DAppLib ${CMAKE_THREAD_LIBS_INIT})
target_link_libraries(ScratchedHologramFrom3DAppLib CliTools)
target_link_libraries(ScratchedHologramFrom3DAppLib File2DProcessingTools)
target_link_libraries(ScratchedHologramFrom3DAppLib File3DProcessingTools)
target_link_libraries(ScratchedHologramFrom3DAppLib ScratchProjectionMaths)
target_link_libraries(ScratchedHologramFrom3DAppLib Geometry3D)


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

if (NOT DISABLE_TESTING)
    add_subdirectory(test)
endif (NOT DISABLE_TESTING)
