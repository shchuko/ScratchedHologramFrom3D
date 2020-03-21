#include <random>
#include <chrono>

#include <gtest/gtest.h>
#include <CPoint3D.hpp>
#include <CVector3D.hpp>


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

    TEST(CPoint3D, CPoint3D_DefaultConstructor_Test) {
        CPoint3D cPoint3D;
        EXPECT_DOUBLE_EQ(cPoint3D.getX(), 0.0);
        EXPECT_DOUBLE_EQ(cPoint3D.getY(), 0.0);
        EXPECT_DOUBLE_EQ(cPoint3D.getZ(), 0.0);
    }

    TEST(CPoint3D, CPoint3D_BuildFromCoordinatesConstructor_Test) {
        double x = randomDouble();
        double y = randomDouble();
        double z = randomDouble();
        CPoint3D cPoint3D(x, y, z);
        EXPECT_DOUBLE_EQ(x, cPoint3D.getX());
        EXPECT_DOUBLE_EQ(y, cPoint3D.getY());
        EXPECT_DOUBLE_EQ(z, cPoint3D.getZ());
    }

    TEST(CPoint3D, CPoint3D_getX_Test) {
        double x = randomDouble();
        double y = 0.0;
        double z = 0.0;
        CPoint3D cPoint(x, y, z);
        EXPECT_DOUBLE_EQ(x, cPoint.getX());
    }

    TEST(CPoint, CPoint3D_getY_Test) {
        double x = 0.0;
        double y = randomDouble();
        double z = 0.0;
        CPoint3D cPoint(x, y, z);
        EXPECT_DOUBLE_EQ(y, cPoint.getY());
    }

    TEST(CPoint3D, CPoint3D_getZ_Test) {
        double x = 0.0;
        double y = 0.0;
        double z = randomDouble();
        CPoint3D cPoint(x, y, z);
        EXPECT_DOUBLE_EQ(z, cPoint.getZ());
    }

    TEST(CPoint3D, CPoint3D_CopyConstReferenceConstructor_Test) {
        double x = randomDouble();
        double y = randomDouble();
        double z = randomDouble();
        CPoint3D cPoint(x, y, z);
        CPoint3D cPointCopy(cPoint);
        EXPECT_DOUBLE_EQ(cPoint.getX(), cPointCopy.getX());
        EXPECT_DOUBLE_EQ(cPoint.getY(), cPointCopy.getY());
        EXPECT_DOUBLE_EQ(cPoint.getZ(), cPointCopy.getZ());
    }

    TEST(CPoint3D, CPoint3D_CopyConstructorRValue_Test) {
        double x = randomDouble();
        double y = randomDouble();
        double z = randomDouble();
        CPoint3D cPoint(x, y, z);
        CPoint3D cPoint3DCopy(std::move(cPoint));

        EXPECT_DOUBLE_EQ(x, cPoint3DCopy.getX());
        EXPECT_DOUBLE_EQ(y, cPoint3DCopy.getY());
        EXPECT_DOUBLE_EQ(z, cPoint3DCopy.getZ());
    }

    TEST(CPoint3D, CPoint3D_moveVector_Test) {
        double x = randomDouble();
        double y = randomDouble();
        double z = randomDouble();
        CPoint3D cPoint(x, y, z);

        double x1 = randomDouble();
        double y1 = randomDouble();
        double z1 = randomDouble();
        CVector3D cVector3D(x1, y1, z1);

        cPoint.move(cVector3D);
        EXPECT_DOUBLE_EQ(x + x1, cPoint.getX());
        EXPECT_DOUBLE_EQ(y + y1, cPoint.getY());
        EXPECT_DOUBLE_EQ(z + z1, cPoint.getZ());
    }

    TEST(CPoint3D, CPoint3D_moveVectorCopy_Test) {
        double x = randomDouble();
        double y = randomDouble();
        double z = randomDouble();
        CPoint3D cPoint(x, y, z);

        double x1 = randomDouble();
        double y1 = randomDouble();
        double z1 = randomDouble();
        CVector3D cVector3D(x1, y1, z1);

        CPoint3D new_cPoint(cPoint.moveCopy(cVector3D));

        EXPECT_DOUBLE_EQ(x + x1, new_cPoint.getX());
        EXPECT_DOUBLE_EQ(y + y1, new_cPoint.getY());
        EXPECT_DOUBLE_EQ(z + z1, new_cPoint.getZ());
    }

}