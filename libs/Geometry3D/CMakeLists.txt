project(Geometry3D)

file(GLOB Geometry3D_SOURCES ./source/*.cpp)
file(GLOB Geometry3D_HEADERS ./include/*.hpp)

add_library(Geometry3D SHARED ${Geometry3D_SOURCES} ${Geometry3D_HEADERS})
target_include_directories(Geometry3D PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

set_target_properties(Geometry3D
        PROPERTIES
        ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
        LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
        RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
        )

add_subdirectory(test)