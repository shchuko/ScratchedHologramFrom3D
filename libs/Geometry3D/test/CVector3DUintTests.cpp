#include <random>
#include <chrono>

#include <gtest/gtest.h>
#include <CVector3D.hpp>
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

    TEST(CVector3D, CVector3D_DefaultConstructor_Test) {
        CVector3D cVector3D;
        EXPECT_DOUBLE_EQ(cVector3D.getX(), 0.0);
        EXPECT_DOUBLE_EQ(cVector3D.getY(), 0.0);
        EXPECT_DOUBLE_EQ(cVector3D.getZ(), 0.0);
    }

    TEST(CVector3D, CVector3D_BuildFromCoordinatesConstructor_Test) {
        double x = randomDouble();
        double y = randomDouble();
        double z = randomDouble();
        CVector3D cVector3D(x, y, z);
        EXPECT_DOUBLE_EQ(x, cVector3D.getX());
        EXPECT_DOUBLE_EQ(y, cVector3D.getY());
        EXPECT_DOUBLE_EQ(z, cVector3D.getZ());
    }

    TEST(CVector3D, CVector3D_getX_Test) {
        double x = randomDouble();
        CVector3D cVector3D(x, 0.0, 0.0);
        EXPECT_DOUBLE_EQ(x, cVector3D.getX());
    }

    TEST(CVector3D, CVector3D_getY_Test) {
        double y = randomDouble();
        CVector3D cVector3D(0.0, y, 0.0);
        EXPECT_DOUBLE_EQ(y, cVector3D.getY());
    }

    TEST(CVector3D, CVector3D_getZ_Test) {
        double z = randomDouble();
        CVector3D cVector3D(0.0, 0.0, z);
        EXPECT_DOUBLE_EQ(z, cVector3D.getZ());
    }

    TEST(CVector3D, CVector3D_CopyConstReferenceConstructor_Test) {
        CVector3D cVector3D(randomDouble(), randomDouble(), randomDouble());
        CVector3D cVector3DCopy(cVector3D);
        EXPECT_DOUBLE_EQ(cVector3D.getX(), cVector3DCopy.getX());
        EXPECT_DOUBLE_EQ(cVector3D.getY(), cVector3DCopy.getY());
        EXPECT_DOUBLE_EQ(cVector3D.getZ(), cVector3DCopy.getZ());
    }

    TEST(CVector3D, CVector3D_CopyConstructorRValue_Test) {
        double x = randomDouble();
        double y = randomDouble();
        double z = randomDouble();
        CVector3D cVector3D(x, y, z);
        CVector3D cVector3DCopy(std::move(cVector3D));

        EXPECT_DOUBLE_EQ(x, cVector3DCopy.getX());
        EXPECT_DOUBLE_EQ(y, cVector3DCopy.getY());
        EXPECT_DOUBLE_EQ(z, cVector3DCopy.getZ());
    }

    TEST(CVector3D, CVector3D_getLen_Test) {
        double x = randomDouble();
        double y = randomDouble();
        double z = randomDouble();
        CVector3D cVector3D(x, y, z);
        EXPECT_DOUBLE_EQ(sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2)), cVector3D.getLen());
    }

    TEST(CVector3D, CVector3D_isCollinear_Test) {
        CVector3D cVector3D(randomDouble(), randomDouble(), randomDouble());
        CVector3D cVector3D1(randomDouble(), randomDouble(), randomDouble());
        EXPECT_EQ(IsCollinear(cVector3D, cVector3D1), cVector3D.isCollinear(cVector3D1));
    }

    TEST(CVector3D, CVector3D_getAngleCos_Test) {
        double x = randomDouble();
        double y = randomDouble();
        double z = randomDouble();
        double x1 = randomDouble();
        double y1 = randomDouble();
        double z1 = randomDouble();
        CVector3D cVector3D(x, y, z);
        CVector3D cVector3D1(x1, y1, z1);
        EXPECT_DOUBLE_EQ(getAngleCos(cVector3D, cVector3D1), cVector3D.getAngleCos(cVector3D1));
    }

    TEST(CVector3D, CVector3D_operatorPlus_Test) {
        double x = randomDouble();
        double y = randomDouble();
        double z = randomDouble();
        CVector3D cVector3D(x, y, z);
        EXPECT_DOUBLE_EQ(x, cVector3D.operator+().getX());
        EXPECT_DOUBLE_EQ(y, cVector3D.operator+().getY());
        EXPECT_DOUBLE_EQ(z, cVector3D.operator+().getZ());
    }

    TEST(CVector3D, CVector3D_operatorMinus_Test) {
        double x = randomDouble();
        double y = randomDouble();
        double z = randomDouble();
        CVector3D cVector3D(x, y, z);
        EXPECT_DOUBLE_EQ(-x, cVector3D.operator-().getX());
        EXPECT_DOUBLE_EQ(-y, cVector3D.operator-().getY());
        EXPECT_DOUBLE_EQ(-z, cVector3D.operator-().getZ());
    }

    TEST(CVector3D, CVector3D_operatorEqPlus_Test) {
        double x = randomDouble();
        double y = randomDouble();
        double z = randomDouble();
        CVector3D cVector3D(x, y, z);
        double x1 = randomDouble();
        double y1 = randomDouble();
        double z1 = randomDouble();
        CVector3D cVector3D1(x1, y1, z1);
        EXPECT_DOUBLE_EQ(x + cVector3D1.getX(), cVector3D.operator+=(cVector3D1).getX());
        EXPECT_DOUBLE_EQ(y + cVector3D1.getY() + cVector3D1.getY(),
                         cVector3D.operator+=(cVector3D1).getY());
        EXPECT_DOUBLE_EQ(z + cVector3D1.getZ() + cVector3D1.getZ() + cVector3D1.getZ(),
                         cVector3D.operator+=(cVector3D1).getZ());
    }

    TEST(CVector3D, CVector3D_opertorEqMinus_Test) {
        double x = randomDouble();
        double y = randomDouble();
        double z = randomDouble();
        CVector3D cVector3D(x, y, z);
        double x1 = randomDouble();
        double y1 = randomDouble();
        double z1 = randomDouble();
        CVector3D cVector3D1(x1, y1, z1);
        EXPECT_DOUBLE_EQ(x - cVector3D1.getX(), cVector3D.operator-=(cVector3D1).getX());
        EXPECT_DOUBLE_EQ(y - cVector3D1.getY() - cVector3D1.getY(),
                         cVector3D.operator-=(cVector3D1).getY());
        EXPECT_DOUBLE_EQ(z - cVector3D1.getZ() - cVector3D1.getZ() - cVector3D1.getZ(),
                         cVector3D.operator-=(cVector3D1).getZ());
    }
}