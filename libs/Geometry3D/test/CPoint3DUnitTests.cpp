#include <gtest/gtest.h>
#include <CPoint3D.hpp>


namespace Geometry3D {

    TEST(CPoint3D, BasicConstructor) {
        CPoint3D cPoint3D;
        EXPECT_EQ(cPoint3D.getX(), 0);
        EXPECT_EQ(cPoint3D.getY(), 0);
        EXPECT_EQ(cPoint3D.getZ(), 0);
    }
}

