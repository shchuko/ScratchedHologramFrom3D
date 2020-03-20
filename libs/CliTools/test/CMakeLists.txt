file(GLOB CliTools_TEST_SOURCES ./*.cpp)

add_executable(CliToolsUnitTests ${CliTools_TEST_SOURCES})

target_include_directories(CliToolsUnitTests PRIVATE ${CliTools_SOURCE_DIR}/include)
target_include_directories(CliToolsUnitTests PRIVATE ${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

target_link_libraries(CliToolsUnitTests gtest gtest_main CliTools)

set_target_properties(CliToolsUnitTests
        PROPERTIES
        RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
        )

add_test(
        NAME
        CliToolsUnitTests
        COMMAND
        ${CMAKE_BINARY_DIR}/bin/CliToolsUnitTests
)
