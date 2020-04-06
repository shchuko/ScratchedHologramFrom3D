file(GLOB TEST_SRC_FILES ./*.cpp)


add_executable(AppLibUnitTests ${TEST_SRC_FILES})
target_include_directories(AppLibUnitTests PRIVATE ${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})
target_link_libraries(AppLibUnitTests gtest gtest_main)
target_link_libraries(AppLibUnitTests app_lib)

set_target_properties(AppLibUnitTests
        PROPERTIES
        RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
        )

add_test(
        NAME
        AppLibUnitTests
        COMMAND
        ${CMAKE_BINARY_DIR}/bin/AppLibUnitTests
)