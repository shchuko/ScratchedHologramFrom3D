file(GLOB Geometry2D_TEST_SOURCES ./*.cpp)

add_executable(Geometry2DUnitTests ${Geometry2D_TEST_SOURCES})

target_include_directories(Geometry2DUnitTests PRIVATE ${Geometry2D_SOURCE_DIR}/include)
target_include_directories(Geometry2DUnitTests PRIVATE ${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

target_link_libraries(Geometry2DUnitTests gtest gtest_main Geometry2D)

set_target_properties(Geometry2DUnitTests
        PROPERTIES
        RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
        )

add_test(
        NAME
        Geometry2DUnitTests
        COMMAND
        ${CMAKE_BINARY_DIR}/bin/Geometry2DUnitTests
)