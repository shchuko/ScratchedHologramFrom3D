file(GLOB App_TEST_SOURCES ./*.cpp)

add_executable(ScratchedHologramFrom3DAppLibUnitTests ${App_TEST_SOURCES})

target_include_directories(ScratchedHologramFrom3DAppLibUnitTests PRIVATE ${COMMON_SOURCE_DIR}/include)
target_include_directories(ScratchedHologramFrom3DAppLibUnitTests PRIVATE ${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

target_link_libraries(ScratchedHologramFrom3DAppLibUnitTests gtest gtest_main ScratchedHologramFrom3DAppLib)

set_target_properties(ScratchedHologramFrom3DAppLibUnitTests
        PROPERTIES
        RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
        )

add_test(
        NAME
        ScratchedHologramFrom3DAppLibUnitTests
        COMMAND
        ${CMAKE_BINARY_DIR}/bin/ScratchedHologramFrom3DAppLibUnitTests
)