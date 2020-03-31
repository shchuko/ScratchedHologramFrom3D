#include <gtest/gtest.h>


#include <CAppRunner.hpp>


TEST(CAppRunner, run) {
    EXPECT_EQ(0, CAppRunner().run());
}

