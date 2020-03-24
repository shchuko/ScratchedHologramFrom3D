project(CliTools)

file(GLOB CliTools_SOURCES ./source/*.cpp)
file(GLOB CliTools_HEADERS ./include/*.hpp)

add_library(CliTools SHARED ${CliTools_SOURCES} ${CliTools_HEADERS})
target_include_directories(CliTools PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

set_target_properties(CliTools
        PROPERTIES
        ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
        LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
        RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
        )

add_subdirectory(test)
