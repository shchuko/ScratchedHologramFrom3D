project(File2DProcessingTools)

file(GLOB File2DProcessingTools_SOURCES ./source/*.cpp)
file(GLOB File2DProcessingTools_HEADERS ./include/*.hpp)

add_library(File2DProcessingTools SHARED ${File2DProcessingTools_SOURCES} ${File2DProcessingTools_HEADERS})
target_include_directories(File2DProcessingTools PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

set_target_properties(File2DProcessingTools
        PROPERTIES
        ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
        LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
        RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
        )
