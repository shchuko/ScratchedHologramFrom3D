file(GLOB File2DProcessingTools_TEST_SOURCES ./*.cpp)

add_executable(File2DProcessingToolsUnitTests ${File2DProcessingTools_TEST_SOURCES} ENotAColorHexUnitTests.cpp)

target_include_directories(File2DProcessingToolsUnitTests PRIVATE ${File2DProcessingTools_SOURCE_DIR}/include)
target_include_directories(File2DProcessingToolsUnitTests PRIVATE ${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

target_link_libraries(File2DProcessingToolsUnitTests gtest gtest_main File2DProcessingTools)

set_target_properties(File2DProcessingToolsUnitTests
        PROPERTIES
        RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
        )

add_test(
        NAME
        File2DProcessingToolsUnitTests
        COMMAND
        ${CMAKE_BINARY_DIR}/bin/File2DProcessingToolsUnitTests
)
