file(GLOB TEST_SRC_FILES ./*.cpp)


add_executable(ScratchProjectionMathsUnitTests ${TEST_SRC_FILES})
target_include_directories(ScratchProjectionMathsUnitTests PRIVATE ${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})
target_link_libraries(ScratchProjectionMathsUnitTests gtest gtest_main)
target_link_libraries(ScratchProjectionMathsUnitTests ScratchProjectionMaths)

set_target_properties(ScratchProjectionMathsUnitTests
        PROPERTIES
        RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
        )

add_test(
        NAME
        AppLibUnitTests
        COMMAND
        ${CMAKE_BINARY_DIR}/bin/AppLibUnitTests
)