#include <random>
#include <chrono>
#include <cmath>

#include <gtest/gtest.h>
#include <CLinkedVector3D.hpp>
#include <CPoint3D.hpp>
#include "FunctionsForTests.cpp"

namespace Geometry3D {
    /**
     * Make a random double
     * @return random double
     */
    double randomDouble() {
        double MIN_DOUBLE_VALUE = -10000;
        double MAX_DOUBLE_VALUE = 10000;
        std::uniform_real_distribution<double> distribution(MIN_DOUBLE_VALUE, MAX_DOUBLE_VALUE);
        std::mt19937 random_engine(std::chrono::system_clock::now().time_since_epoch().count());
        return distribution(random_engine);
    }

    TEST(CLinkedVector3D, CLinkedVector3D_Constructor_Test) {
        double x = randomDouble();
        double y = randomDouble();
        double z = randomDouble();
        CPoint3D cPoint3D(x, y, z);
        double x1 = randomDouble();
        double y1 = randomDouble();
        double z1 = randomDouble();
        CPoint3D cPoint3D1(x1, y1, z1);

        CLinkedVector3D cLinkedVector3DTests(cPoint3D, cPoint3D1);
        EXPECT_DOUBLE_EQ(cPoint3D1.getX() - cPoint3D.getX(), cLinkedVector3DTests.getX());
        EXPECT_DOUBLE_EQ(cPoint3D1.getY() - cPoint3D1.getY(), cLinkedVector3DTests.getY());
        EXPECT_DOUBLE_EQ(cPoint3D1.getZ() - cPoint3D1.getZ(), cLinkedVector3DTests.getZ());
    }

    TEST(CLinkedVector3D, CLinkedVector3D_getX_Test) {
        double x = randomDouble();
        double y = 0.0;
        double z = 0.0;
        CPoint3D cPoint3D(x, y, z);
        double x1 = randomDouble();
        double y1 = 0.0;
        double z1 = 0.0;
        CPoint3D cPoint3D1(x1, y1, z1);

        CLinkedVector3D cLinkedVector3DTests(cPoint3D, cPoint3D1);
        EXPECT_DOUBLE_EQ(cPoint3D1.getX() - cPoint3D.getX(), cLinkedVector3DTests.getX());
    }

    TEST(CLinkedVector3D, CLinkedVector3D_getY_Test) {
        double x = 0.0;
        double y = randomDouble();
        double z = 0.0;
        CPoint3D cPoint3D(x, y, z);
        double x1 = 0.0;
        double y1 = randomDouble();
        double z1 = 0.0;
        CPoint3D cPoint3D1(x1, y1, z1);

        CLinkedVector3D cLinkedVector3DTests(cPoint3D, cPoint3D1);
        EXPECT_DOUBLE_EQ(cPoint3D1.getY() - cPoint3D.getY(), cLinkedVector3DTests.getY());
    }

    TEST(CLinkedVector3D, CLinkedVector3D_getZ_Test) {
        double x = 0.0;
        double y = 0.0;
        double z = randomDouble();
        CPoint3D cPoint3D(x, y, z);
        double x1 = 0.0;
        double y1 = 0.0;
        double z1 = randomDouble();
        CPoint3D cPoint3D1(x1, y1, z1);

        CLinkedVector3D cLinkedVector3DTests(cPoint3D, cPoint3D1);
        EXPECT_DOUBLE_EQ(cPoint3D1.getZ() - cPoint3D.getZ(), cLinkedVector3DTests.getZ());
    }

    TEST(CLinkedVector3D, CLinkedVector3D_getLen_Test) {
        double x = randomDouble();
        double y = randomDouble();
        double z = randomDouble();
        CPoint3D cPoint3D(x, y, z);
        double x1 = randomDouble();
        double y1 = randomDouble();
        double z1 = randomDouble();
        CPoint3D cPoint3D1(x1, y1, z1);

        CLinkedVector3D cLinkedVector3DTests(cPoint3D, cPoint3D1);
        EXPECT_DOUBLE_EQ(sqrt(pow(x1 - x, 2) + pow(y1 - y, 2) + pow(z1 - z, 2)), cLinkedVector3DTests.getLen());
    }

    TEST(CLinkedVector3D, CLinkedVector3D_isCollinear_Test) {
        double x = randomDouble();
        double y = randomDouble();
        double z = randomDouble();
        CPoint3D cPoint3D(x, y, z);
        double x1 = randomDouble();
        double y1 = randomDouble();
        double z1 = randomDouble();
        CPoint3D cPoint3D1(x1, y1, z1);

        CLinkedVector3D cLinkedVector3DTests(cPoint3D, cPoint3D1);

        double new_x = randomDouble();
        double new_y = randomDouble();
        double new_z = randomDouble();
        CPoint3D new_cPoint3D(new_x, new_y, new_z);
        double new_x1 = randomDouble();
        double new_y1 = randomDouble();
        double new_z1 = randomDouble();
        CPoint3D new_cPoint3D1(new_x1, new_y1, new_z1);

        CLinkedVector3D new_cLinkedVector3DTests(new_cPoint3D, new_cPoint3D1);

        EXPECT_EQ(IsCollinear(cLinkedVector3DTests, new_cLinkedVector3DTests),
                  cLinkedVector3DTests.isCollinear(new_cLinkedVector3DTests));
    }

    TEST(CLinkedVector3D, CLinkedVector3D_getAngleCos_Test) {
        double x = randomDouble();
        double y = randomDouble();
        double z = randomDouble();
        CPoint3D cPoint3D(x, y, z);
        double x1 = randomDouble();
        double y1 = randomDouble();
        double z1 = randomDouble();
        CPoint3D cPoint3D1(x1, y1, z1);

        CLinkedVector3D cLinkedVector3DTests(cPoint3D, cPoint3D1);

        double new_x = randomDouble();
        double new_y = randomDouble();
        double new_z = randomDouble();
        CPoint3D new_cPoint3D(new_x, new_y, new_z);
        double new_x1 = randomDouble();
        double new_y1 = randomDouble();
        double new_z1 = randomDouble();
        CPoint3D new_cPoint3D1(new_x1, new_y1, new_z1);

        CLinkedVector3D new_cLinkedVector3DTests(new_cPoint3D, new_cPoint3D1);

        EXPECT_DOUBLE_EQ(getAngleCos(cLinkedVector3DTests, new_cLinkedVector3DTests),
                         cLinkedVector3DTests.getAngleCos(new_cLinkedVector3DTests));
    }
}