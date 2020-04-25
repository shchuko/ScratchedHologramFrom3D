project(CliTools)

file(GLOB CliTools_SOURCES ./source/*.cpp)
file(GLOB CliTools_HEADERS ./include/*.hpp)

if (SCRATCH_STATIC_LIB_LINKING)
    add_library(CliTools STATIC ${CliTools_SOURCES} ${CliTools_HEADERS})
else (SCRATCH_STATIC_LIB_LINKING)
    add_library(CliTools SHARED ${CliTools_SOURCES} ${CliTools_HEADERS})
endif (SCRATCH_STATIC_LIB_LINKING)

target_include_directories(CliTools PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

set_target_properties(CliTools
        PROPERTIES
        ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
        LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
        RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
        )

if (NOT DISABLE_TESTING)
    add_subdirectory(test)
endif (NOT DISABLE_TESTING)
