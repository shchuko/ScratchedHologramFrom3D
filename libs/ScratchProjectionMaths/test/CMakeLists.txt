file(GLOB ScratchProjectionMathsUnitTests_SOURCES ./*.cpp)

add_executable(ScratchProjectionMathsUnitTests ${ScratchProjectionMathsUnitTests_SOURCES})

target_include_directories(ScratchProjectionMathsUnitTests PRIVATE ${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})
target_link_libraries(ScratchProjectionMathsUnitTests gtest gtest_main)
target_link_libraries(ScratchProjectionMathsUnitTests ScratchProjectionMaths)

set_target_properties(ScratchProjectionMathsUnitTests
        PROPERTIES
        RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
        )

add_test(
        NAME
        ScratchProjectionMathsUnitTests
        COMMAND
        ${CMAKE_BINARY_DIR}/bin/ScratchProjectionMathsUnitTests
)