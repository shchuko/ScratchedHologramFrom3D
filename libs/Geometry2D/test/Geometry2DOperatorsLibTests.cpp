#include <random>
#include <chrono>
#include <gtest/gtest.h>

#include <Geometry2DOperators.hpp>
#include <CVector2D.hpp>

namespace Geometry2DOperatorsLibTests {
    using Geometry2D::operator-;
    using Geometry2D::operator+;
    using Geometry2D::CVector2D;
    using Geometry2D::AVector2D;

    class Geometry2DOperatorsFixture : public ::testing::Test {
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

    TEST_F(Geometry2DOperatorsFixture, AVector2D_operator_binary_plus_Test) {
        double x_first = nextRandomDouble();
        double y_first = nextRandomDouble();
        AVector2D &&a_vector_2d_first = CVector2D(x_first, y_first);

        double x_second = nextRandomDouble();
        double y_second = nextRandomDouble();
        AVector2D &&a_vector_2d_second = CVector2D(x_second, y_second);

        double x_expected = x_first + x_second;
        double y_expected = y_first + y_second;

        EXPECT_DOUBLE_EQ(x_expected, (a_vector_2d_first + a_vector_2d_second).getX());
        EXPECT_DOUBLE_EQ(y_expected, (a_vector_2d_first + a_vector_2d_second).getY());
    }

    TEST_F(Geometry2DOperatorsFixture, AVector2D_operator_binary_minus_Test) {
        double x_first = nextRandomDouble();
        double y_first = nextRandomDouble();
        AVector2D &&a_vector_2d_first = CVector2D(x_first, y_first);

        double x_second = nextRandomDouble();
        double y_second = nextRandomDouble();
        AVector2D &&a_vector_2d_second = CVector2D(x_second, y_second);

        double x_expected = x_first - x_second;
        double y_expected = y_first - y_second;

        EXPECT_DOUBLE_EQ(x_expected, (a_vector_2d_first - a_vector_2d_second).getX());
        EXPECT_DOUBLE_EQ(y_expected, (a_vector_2d_first - a_vector_2d_second).getY());
    }
}
