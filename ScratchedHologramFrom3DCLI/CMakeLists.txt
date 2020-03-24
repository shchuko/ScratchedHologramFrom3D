add_executable(ScratchedHologramFrom3DCLI main)

target_link_libraries(ScratchedHologramFrom3DCLI app_lib)

target_link_libraries(ScratchedHologramFrom3DCLI CliTools)
target_link_libraries(ScratchedHologramFrom3DCLI File2DProcessingTools)
target_link_libraries(ScratchedHologramFrom3DCLI File3DProcessingTools)
target_link_libraries(ScratchedHologramFrom3DCLI Geometry2D)
target_link_libraries(ScratchedHologramFrom3DCLI Geometry3D)

set_target_properties(ScratchedHologramFrom3DCLI
        PROPERTIES
        ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
        LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
        RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
        LINK_FLAGS "-Wl,-rpath,'$ORIGIN/../lib'"
        )


