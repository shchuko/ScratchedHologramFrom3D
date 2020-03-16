file(GLOB Geometry3D_TEST_SOURCES ./*.cpp)

add_executable(Geometry3DUnitTests ${Geometry3D_TEST_SOURCES})

target_include_directories(Geometry3DUnitTests PRIVATE ${Geometry3D_SOURCE_DIR}/include)
target_include_directories(Geometry3DUnitTests PRIVATE ${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

target_link_libraries(Geometry3DUnitTests gtest gtest_main)

set_target_properties(Geometry3DUnitTests
        PROPERTIES
        RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
        )

add_test(
        NAME
        Geometry3DUnitTests
        COMMAND
        ${CMAKE_BINARY_DIR}/bin/Geometry3DUnitTests
)