file(GLOB TEST_SRC_FILES ./*.cpp)


add_executable(HeadSourceUnitTests ${TEST_SRC_FILES})
target_include_directories(HeadSourceUnitTests PRIVATE ${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})
target_link_libraries(HeadSourceUnitTests gtest gtest_main)
target_link_libraries(HeadSourceUnitTests app_lib)

set_target_properties(HeadSourceUnitTests
        PROPERTIES
        RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
        )

add_test(
        NAME
        HeadSourceUnitTests
        COMMAND
        ${CMAKE_BINARY_DIR}/bin/HeadSourceUnitTests
)