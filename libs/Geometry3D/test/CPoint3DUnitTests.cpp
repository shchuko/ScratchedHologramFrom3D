#include <random>
#include <chrono>

#include <gtest/gtest.h>
#include <CPoint3D.hpp>


namespace Geometry3D {
    class CPoint3DRandomFixture : public ::testing::Test {
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

            point3D = new CPoint3D(x, y, z);
        }

        void TearDown() override {
            delete point3D;
        }

        CPoint3D *point3D = nullptr;
        double x = 0.0;
        double y = 0.0;
        double z = 0.0;
    };

    TEST(CPoint3D, CPoint3D_DefaultConstructor_Test) {
        CPoint3D cPoint3D;
        EXPECT_DOUBLE_EQ(cPoint3D.getX(), 0.0);
        EXPECT_DOUBLE_EQ(cPoint3D.getY(), 0.0);
        EXPECT_DOUBLE_EQ(cPoint3D.getZ(), 0.0);
    }

    TEST_F(CPoint3DRandomFixture, CPoint3D_BuildFromCoordinatesConstructor_Test) {
        CPoint3D cPoint3D(x, y, z);
        EXPECT_DOUBLE_EQ(x, cPoint3D.getX());
        EXPECT_DOUBLE_EQ(y, cPoint3D.getY());
        EXPECT_DOUBLE_EQ(z, cPoint3D.getZ());
    }

    TEST_F(CPoint3DRandomFixture, CPoint3D_getX_Test) {
        EXPECT_DOUBLE_EQ(x, point3D->getX());
    }

    TEST_F(CPoint3DRandomFixture, CPoint3D_getY_Test) {
        EXPECT_DOUBLE_EQ(y, point3D->getY());
    }

    TEST_F(CPoint3DRandomFixture, CPoint3D_getZ_Test) {
        EXPECT_DOUBLE_EQ(z, point3D->getZ());
    }

    TEST_F(CPoint3DRandomFixture, CPoint3D_CopyConstReferenceConstructor_Test) {
        CPoint3D cPoint3DCopy(*point3D);
        EXPECT_DOUBLE_EQ(point3D->getX(), cPoint3DCopy.getX());
        EXPECT_DOUBLE_EQ(point3D->getY(), cPoint3DCopy.getY());
        EXPECT_DOUBLE_EQ(point3D->getZ(), cPoint3DCopy.getZ());
    }

    TEST_F(CPoint3DRandomFixture, CPoint3D_CopyConstructorRValue_Test) {
        CPoint3D cPoint3D(x, y, z);
        CPoint3D cPoint3DCopy(std::move(cPoint3D));

        EXPECT_DOUBLE_EQ(x, cPoint3DCopy.getX());
        EXPECT_DOUBLE_EQ(y, cPoint3DCopy.getY());
        EXPECT_DOUBLE_EQ(z, cPoint3DCopy.getZ());
    }

}
