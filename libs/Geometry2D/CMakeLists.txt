project(Geometry2D)

file(GLOB Geometry2D_SOURCES ./source/*.cpp)
file(GLOB Geometry2D_HEADERS ./include/*.hpp)

add_library(Geometry2D SHARED ${Geometry2D_SOURCES} ${Geometry2D_HEADERS})
target_include_directories(Geometry2D PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

set_target_properties(Geometry2D
        PROPERTIES
        ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
        LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
        RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
        )

add_subdirectory(test)