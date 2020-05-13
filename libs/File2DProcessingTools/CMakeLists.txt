project(File2DProcessingTools)

file(GLOB File2DProcessingTools_SOURCES ./source/*.cpp)
file(GLOB File2DProcessingTools_HEADERS ./include/*.hpp)

if (SCRATCH_STATIC_LIB_LINKING)
    add_library(File2DProcessingTools STATIC ${File2DProcessingTools_SOURCES} ${File2DProcessingTools_HEADERS})
else (SCRATCH_STATIC_LIB_LINKING)
    add_library(File2DProcessingTools SHARED ${File2DProcessingTools_SOURCES} ${File2DProcessingTools_HEADERS} include/CPath.hpp source/CPath.cpp)
endif (SCRATCH_STATIC_LIB_LINKING)

target_include_directories(File2DProcessingTools PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

target_link_libraries(File2DProcessingTools Geometry2D)

set_target_properties(File2DProcessingTools
        PROPERTIES
        ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
        LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
        RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
        )

if (NOT DISABLE_TESTING)
    add_subdirectory(test)
endif (NOT DISABLE_TESTING)
