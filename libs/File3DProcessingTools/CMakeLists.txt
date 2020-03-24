project(File3DProcessingTools)

file(GLOB File3DProcessingTools_SOURCES ./source/*.cpp)
file(GLOB File3DProcessingTools_HEADERS ./include/*.hpp)

add_library(File3DProcessingTools SHARED ${File3DProcessingTools_SOURCES} ${File3DProcessingTools_HEADERS})
target_include_directories(File3DProcessingTools PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

target_link_libraries(File3DProcessingTools Geometry3D)

set_target_properties(File3DProcessingTools
        PROPERTIES
        ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
        LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
        RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
        )
