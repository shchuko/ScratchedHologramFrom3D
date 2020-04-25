project(File3DProcessingTools)

file(GLOB File3DProcessingTools_SOURCES ./source/*.cpp)
file(GLOB File3DProcessingTools_HEADERS ./include/*.hpp)

if (SCRATCH_STATIC_LIB_LINKING)
    add_library(File3DProcessingTools STATIC ${File3DProcessingTools_SOURCES} ${File3DProcessingTools_HEADERS})
else (SCRATCH_STATIC_LIB_LINKING)
    add_library(File3DProcessingTools SHARED ${File3DProcessingTools_SOURCES} ${File3DProcessingTools_HEADERS})
endif (SCRATCH_STATIC_LIB_LINKING)

target_include_directories(File3DProcessingTools PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

target_link_libraries(File3DProcessingTools Geometry3D)

set_target_properties(File3DProcessingTools
        PROPERTIES
        ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
        LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
        RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
        )

if (NOT DISABLE_TESTING)
    add_subdirectory(test)
endif (NOT DISABLE_TESTING)
