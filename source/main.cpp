#include <iostream>
#include <cstdlib>

#include <CAppRunner.hpp>

int main(int argc, char* argv[]) {
    try {
        ScratchedHologramFrom3D::CAppRunner runner;
        return runner.run(argc, argv);
    } catch (...) {
        return EXIT_FAILURE;
    }
}

