#include <random>
#include <chrono>
#include <gtest/gtest.h>

#include <Geometry3DOperators.hpp>
#include <CVector3D.hpp>
#include <CLinkedVector3D.hpp>

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
}