project(ScratchProjectionMaths)

file(GLOB ScratchProjectionMaths_SOURCES ./source/*.cpp)
file(GLOB ScratchProjectionMaths_HEADERS ./include/*.hpp)

add_library(ScratchProjectionMaths SHARED ${ScratchProjectionMaths_SOURCES} ${ScratchProjectionMaths_HEADERS})
target_include_directories(ScratchProjectionMaths PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

set_target_properties(ScratchProjectionMaths
        PROPERTIES
        ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
        LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
        RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
        )

target_link_libraries(ScratchProjectionMaths Geometry3D)
target_link_libraries(ScratchProjectionMaths Geometry2D)
target_link_libraries(ScratchProjectionMaths File3DProcessingTools)
target_link_libraries(ScratchProjectionMaths File2DProcessingTools)

add_subdirectory(test)