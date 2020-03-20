#include <random>
#include <chrono>

#include <gtest/gtest.h>
#include <CVector3D.hpp>
#include <Geometry3DOperators.hpp>

namespace Geometry3D {
    /**
     * @author github.com/Tulesha
     */
    class CVector3DRandomFixture : public ::testing::Test {
    private:
        static constexpr double MAX_DOUBLE_VALUE = 10000.0;
        static constexpr double MIN_DOUBLE_VALUE = -10000.0;

    protected:
        void SetUp() override {
            std::uniform_real_distribution<double> distribution(MIN_DOUBLE_VALUE, MAX_DOUBLE_VALUE);
            std::mt19937 random_engine(std::chrono::system_clock::now().time_since_epoch().count());

            x = distribution(random_engine);
            y = distribution(random_engine);
            z = distribution(random_engine);

            cVector3D = new CVector3D(x, y, z);
        }

        void TearDown() override {
            delete cVector3D;
        }

        CVector3D *cVector3D = nullptr;
        double x = 0.0;
        double y = 0.0;
        double z = 0.0;
    };

    TEST(CVector3D, CVector3D_DefaultConstructor_Test) {
        CVector3D cVector3D;
        EXPECT_DOUBLE_EQ(cVector3D.getX(), 0.0);
        EXPECT_DOUBLE_EQ(cVector3D.getY(), 0.0);
        EXPECT_DOUBLE_EQ(cVector3D.getZ(), 0.0);

    }

    TEST_F(CVector3DRandomFixture, CVector3D_BuildFromCoordinatesConstructor_Test) {
        CVector3D cVector3D(x, y, z);
        EXPECT_DOUBLE_EQ(x, cVector3D.getX());
        EXPECT_DOUBLE_EQ(y, cVector3D.getY());
        EXPECT_DOUBLE_EQ(z, cVector3D.getZ());
    }

    TEST_F(CVector3DRandomFixture, CVector3D_getX_Test) {
        EXPECT_DOUBLE_EQ(x, cVector3D->getX());
    }

    TEST_F(CVector3DRandomFixture, CVector3D_getY_Test) {
        EXPECT_DOUBLE_EQ(y, cVector3D->getY());
    }

    TEST_F(CVector3DRandomFixture, CVector3D_getZ_Test) {
        EXPECT_DOUBLE_EQ(z, cVector3D->getZ());
    }

    TEST_F(CVector3DRandomFixture, CVector3D_CopyConstReferenceConstructor_Test) {
        CVector3D cVector3DCopy(*cVector3D);
        EXPECT_DOUBLE_EQ(cVector3D->getX(), cVector3DCopy.getX());
        EXPECT_DOUBLE_EQ(cVector3D->getY(), cVector3DCopy.getY());
        EXPECT_DOUBLE_EQ(cVector3D->getZ(), cVector3DCopy.getZ());
    }

    TEST_F(CVector3DRandomFixture, CVector3D_CopyConstructorRValue_Test) {
        CVector3D cVector3D(x, y, z);
        CVector3D cVector3DCopy(std::move(cVector3D));

        EXPECT_DOUBLE_EQ(x, cVector3DCopy.getX());
        EXPECT_DOUBLE_EQ(y, cVector3DCopy.getY());
        EXPECT_DOUBLE_EQ(z, cVector3DCopy.getZ());
    }

    TEST_F(CVector3DRandomFixture, CVector3D_getLen_Test) {
        EXPECT_DOUBLE_EQ(sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2)), cVector3D->getLen());
    }

    TEST_F(CVector3DRandomFixture, CVector3D_isCollinear_Test) {
        CVector3D cVector3D1(x, y, z);
        EXPECT_EQ(x / cVector3D1.getX() == y / cVector3D1.getY() && y / cVector3D1.getY() == z / cVector3D1.getZ(),
                  cVector3D->isCollinear(cVector3D1));
    }

    TEST_F(CVector3DRandomFixture, CVector3D_getAngleCos_Test) {
        CVector3D cVector3D1(x, y, z);
        EXPECT_DOUBLE_EQ((x * cVector3D1.getX() + y * cVector3D1.getY() + z * cVector3D1.getZ()) /
                         (sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2)) +
                          sqrt((pow(cVector3D1.getX(), 2) + pow(cVector3D1.getY(), 2) + pow(cVector3D1.getZ(), 2)))),
                         cVector3D->getAngleCos(cVector3D1));
    }

    TEST_F(CVector3DRandomFixture, CVector3D_operatorPlus_Test) {
        EXPECT_DOUBLE_EQ(x, cVector3D->operator+().getX());
        EXPECT_DOUBLE_EQ(y, cVector3D->operator+().getY());
        EXPECT_DOUBLE_EQ(z, cVector3D->operator+().getZ());
    }

    TEST_F(CVector3DRandomFixture, CVector3D_operatorMinus_Test) {
        EXPECT_DOUBLE_EQ(-x, cVector3D->operator-().getX());
        EXPECT_DOUBLE_EQ(-y, cVector3D->operator-().getY());
        EXPECT_DOUBLE_EQ(-z, cVector3D->operator-().getZ());
    }

    TEST_F(CVector3DRandomFixture, CVector3D_operatorEqPlus_Test) {
        CVector3D cVector3D1(x, y, z);
        CVector3D cVector3D2 = cVector3D->operator+=(cVector3D1);
        EXPECT_DOUBLE_EQ(x + cVector3D1.getX(), cVector3D2.getX());
        EXPECT_DOUBLE_EQ(y + cVector3D1.getY(), cVector3D2.getY());
        EXPECT_DOUBLE_EQ(z + cVector3D1.getZ(), cVector3D2.getZ());
    }

    TEST_F(CVector3DRandomFixture, CVector3D_opertorEqMinus_Test) {
        CVector3D cVector3D1(x, y, z);
        CVector3D cVector3D2 = cVector3D->operator-=(cVector3D1);
        EXPECT_DOUBLE_EQ(x - cVector3D1.getX(), cVector3D2.getX());
        EXPECT_DOUBLE_EQ(y - cVector3D1.getY(), cVector3D2.getY());
        EXPECT_DOUBLE_EQ(z - cVector3D1.getZ(), cVector3D2.getZ());
    }
}