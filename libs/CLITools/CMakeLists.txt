project(CLITools)

file(GLOB CLITools_SOURCES ./source/*.cpp)
file(GLOB CLITools_HEADERS ./include/*.hpp)

add_library(CLITools SHARED ${CLITools_SOURCES} ${CLITools_HEADERS})
target_include_directories(CLITools PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

set_target_properties(CLITools
        PROPERTIES
        ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
        LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
        RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
        )

add_subdirectory(test)
