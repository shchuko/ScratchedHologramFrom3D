#include <gtest/gtest.h>
#include <CProjectionBuilder.hpp>

#include <thread>

namespace CProjectionBuilderUnitTestsNS {
    TEST(Thread_library, Thread_library_linked_Test) {
        int a = 10;
        EXPECT_EQ(10, a);

        std::thread thread([&]() { a = 100; });
        thread.join();

        EXPECT_EQ(100, a);

    }
}