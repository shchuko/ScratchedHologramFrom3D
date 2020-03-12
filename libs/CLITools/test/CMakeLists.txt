file(GLOB CLITools_TEST_SOURCES ./*.cpp)

add_executable(CLIToolsUnitTests ${CLITools_TEST_SOURCES})

target_include_directories(CLIToolsUnitTests PRIVATE ${CLITools_SOURCE_DIR}/include)
target_include_directories(CLIToolsUnitTests PRIVATE ${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

target_link_libraries(CLIToolsUnitTests gtest gtest_main)

set_target_properties(CLIToolsUnitTests
        PROPERTIES
        RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/test/bin"
        )

add_test(
        NAME
        CLIToolsUnitTests
        COMMAND
        ${CMAKE_BINARY_DIR}/test/bin/CLIToolsUnitTests
)