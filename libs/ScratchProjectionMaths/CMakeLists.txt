project(ScratchProjectionMaths)

file(GLOB ScratchProjectionMaths_SOURCES ./source/*.cpp)
file(GLOB ScratchProjectionMaths_HEADERS ./include/*.hpp)

if (SCRATCH_STATIC_LIB_LINKING)
    add_library(ScratchProjectionMaths STATIC ${ScratchProjectionMaths_SOURCES} ${ScratchProjectionMaths_HEADERS})
else (SCRATCH_STATIC_LIB_LINKING)
    add_library(ScratchProjectionMaths SHARED ${ScratchProjectionMaths_SOURCES} ${ScratchProjectionMaths_HEADERS})
endif (SCRATCH_STATIC_LIB_LINKING)

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

if (NOT DISABLE_TESTING)
    add_subdirectory(test)
endif (NOT DISABLE_TESTING)
