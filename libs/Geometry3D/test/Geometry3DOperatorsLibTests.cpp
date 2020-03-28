#include <random>
#include <chrono>
#include <gtest/gtest.h>

#include <Geometry3DOperators.hpp>
#include <CVector3D.hpp>

namespace Geometry3DOperatorsLibTests {
    using Geometry3D::operator-;
    using Geometry3D::operator+;
    using Geometry3D::CVector3D;
    using Geometry3D::AVector3D;
    using Geometry3D::CLinkedVector3D;


class Geometry3DOperatorsFixture : public ::testing::Test {
    private:
        static constexpr double MAX_DOUBLE_VALUE = 10000.0;
        static constexpr double MIN_DOUBLE_VALUE = -10000.0;

        std::uniform_real_distribution<double> *distribution = nullptr;
        std::mt19937 *random_engine = nullptr;

    protected:
        void SetUp() override {
            distribution = new std::uniform_real_distribution<double>(MIN_DOUBLE_VALUE, MAX_DOUBLE_VALUE);
            random_engine = new std::mt19937(std::chrono::system_clock::now().time_since_epoch().count());

        }

        void TearDown() override {
            delete random_engine;
            delete distribution;
        }

        double nextRandomDouble() {
            return (*distribution)(*random_engine);
        }

    };

    TEST_F(Geometry3DOperatorsFixture, AVector3D_operator_binary_plus_Test) {
        double x_first = nextRandomDouble();
        double y_first = nextRandomDouble();
        double z_first = nextRandomDouble();
        AVector3D &&a_vector_3d_first = CVector3D(x_first, y_first, z_first);

        double x_second = nextRandomDouble();
        double y_second = nextRandomDouble();
        double z_second = nextRandomDouble();
        AVector3D &&a_vector_3d_second = CVector3D(x_second, y_second, z_second);

        double x_expected = x_first + x_second;
        double y_expected = y_first + y_second;
        double z_expected = z_first + z_second;

        EXPECT_DOUBLE_EQ(x_expected, (a_vector_3d_first + a_vector_3d_second).getX());
        EXPECT_DOUBLE_EQ(y_expected, (a_vector_3d_first + a_vector_3d_second).getY());
        EXPECT_DOUBLE_EQ(z_expected, (a_vector_3d_first + a_vector_3d_second).getZ());
    }

    TEST_F(Geometry3DOperatorsFixture, AVector3D_operator_binary_minus_Test) {
        double x_first = nextRandomDouble();
        double y_first = nextRandomDouble();
        double z_first = nextRandomDouble();
        AVector3D &&a_vector_3d_first = CVector3D(x_first, y_first, z_first);

        double x_second = nextRandomDouble();
        double y_second = nextRandomDouble();
        double z_second = nextRandomDouble();
        AVector3D &&a_vector_3d_second = CVector3D(x_second, y_second, z_second);

        double x_expected = x_first - x_second;
        double y_expected = y_first - y_second;
        double z_expected = z_first - z_second;

        EXPECT_DOUBLE_EQ(x_expected, (a_vector_3d_first - a_vector_3d_second).getX());
        EXPECT_DOUBLE_EQ(y_expected, (a_vector_3d_first - a_vector_3d_second).getY());
        EXPECT_DOUBLE_EQ(z_expected, (a_vector_3d_first - a_vector_3d_second).getZ());
    }

    // CPoint3D equals operator==
    TEST(CPoint3DEquals, CPoint3DEquals_EqualsObjects_Test) {
        Geometry3D::CPoint3D point{1.0, 2.0, 3.0};
        EXPECT_TRUE(point == point);
    }

    TEST(CPoint3DEquals, CPoint3DEquals_EqualsCoordinates_Test) {
        Geometry3D::CPoint3D point1{1.0, 2.0, 3.0};
        auto point2 = point1;

        EXPECT_FALSE(&point1 == &point2) << "Test creation error: points have equal addresses!";
        EXPECT_TRUE(point1 == point2);
    }

    TEST(CPoint3DEquals, CPoint3DEquals_DifferentCoordinates_X_Test) {
        Geometry3D::CPoint3D point1{1.0, 2.0, 3.0};
        Geometry3D::CPoint3D point2{1.1, 2.0, 3.0};
        EXPECT_FALSE(point1 == point2);
    }

    TEST(CPoint3DEquals, CPoint3DEquals_DifferentCoordinates_Y_Test) {
        Geometry3D::CPoint3D point1{1.0, 2.0, 3.0};
        Geometry3D::CPoint3D point2{1.0, 2.1, 3.0};
        EXPECT_FALSE(point1 == point2);
    }

    TEST(CPoint3DEquals, CPoint3DEquals_DifferentCoordinates_Z_Test) {
        Geometry3D::CPoint3D point1{1.0, 2.0, 3.0};
        Geometry3D::CPoint3D point2{1.0, 2.0, 3.1};
        EXPECT_FALSE(point1 == point2);
    }

    // AVector3D equals operator==
    TEST(AVector3DEquals, AVector3DEquals_EqualsObjects_Test) {
        Geometry3D::CVector3D vector{1.0, 2.0, 3.0};
        EXPECT_TRUE(vector == vector);
    }

    TEST(AVector3DEquals, AVector3DEquals_EqualsCoordinates_Test) {
        Geometry3D::CVector3D vector1{1.0, 2.0, 3.0};
        auto vector2 = vector1;

        EXPECT_FALSE(&vector1 == &vector2) << "Test creation error: vectors have equal addresses!";
        EXPECT_TRUE(vector1 == vector2);
    }

    TEST(AVector3DEquals, AVector3DEquals_DifferentCoordinates_X_Test) {
        Geometry3D::CVector3D vector1{1.0, 2.0, 3.0};
        Geometry3D::CVector3D vector2{1.1, 2.0, 3.0};
        EXPECT_FALSE(vector1 == vector2);
    }

    TEST(AVector3DEquals, AVector3DEquals_DifferentCoordinates_Y_Test) {
        Geometry3D::CVector3D vector1{1.0, 2.0, 3.0};
        Geometry3D::CVector3D vector2{1.0, 2.1, 3.0};
        EXPECT_FALSE(vector1 == vector2);
    }

    TEST(AVector3DEquals, AVector3DEquals_DifferentCoordinates_Z_Test) {
        Geometry3D::CVector3D vector1{1.0, 2.0, 3.0};
        Geometry3D::CVector3D vector2{1.0, 2.0, 3.1};
        EXPECT_FALSE(vector1 == vector2);
    }
}
