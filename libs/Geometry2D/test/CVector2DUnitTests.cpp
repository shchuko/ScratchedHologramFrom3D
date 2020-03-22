#include <random>
#include <chrono>
#include <cmath>

#include <gtest/gtest.h>
#include <AVector2D.hpp>
#include <CVector2D.hpp>

namespace Geometry3DCVector3DTests {
    using Geometry2D::CVector2D;

    class CVector2DFixture : public ::testing::Test {
    private:
        static constexpr double MAX_DOUBLE_VALUE = 10000.0;
        static constexpr double MIN_DOUBLE_VALUE = -10000.0;

        std::uniform_real_distribution<double> *distribution = nullptr;
        std::mt19937 *random_engine = nullptr;

    protected:
        void SetUp() override {
            distribution = new std::uniform_real_distribution<double>(MIN_DOUBLE_VALUE, MAX_DOUBLE_VALUE);
            random_engine = new std::mt19937(std::chrono::system_clock::now().time_since_epoch().count());

            x_fixture = nextRandomDouble();
            y_fixture = nextRandomDouble();
            c_vector_2d_fixture = new CVector2D(x_fixture, y_fixture);

        }

        void TearDown() override {
            delete random_engine;
            delete distribution;
            delete c_vector_2d_fixture;
        }

        double nextRandomDouble() {
            return (*distribution)(*random_engine);
        }

        double x_fixture = 0.0;
        double y_fixture = 0.0;

        CVector2D *c_vector_2d_fixture = nullptr;
    };

    TEST_F(CVector2DFixture, CVector2D_BuildFromCoordinatesConstructor_Test) {
        double x = nextRandomDouble();
        double y = nextRandomDouble();
        CVector2D vector_instance(x, y);

        EXPECT_DOUBLE_EQ(x, vector_instance.getX());
        EXPECT_DOUBLE_EQ(y, vector_instance.getY());
    }

    TEST_F(CVector2DFixture, CVector2D_DefaultConstructor_Test) {
        CVector2D vector;
        EXPECT_DOUBLE_EQ(0.0, vector.getX());
        EXPECT_DOUBLE_EQ(0.0, vector.getY());
    }

    TEST_F(CVector2DFixture, CVector2D_getX_Test) {
        double x = nextRandomDouble();
        CVector2D vector(x, 0.0);
        EXPECT_DOUBLE_EQ(x, vector.getX());
    }

    TEST_F(CVector2DFixture, CVector2D_getY_Test) {
        double y = nextRandomDouble();
        CVector2D vector(0.0, y);
        EXPECT_DOUBLE_EQ(y, vector.getY());
    }

    TEST_F(CVector2DFixture, CVector2D_CopyConstReferenceConstructor_Test) {
        CVector2D vector(nextRandomDouble(), nextRandomDouble());
        CVector2D vector_copy(vector);
        EXPECT_DOUBLE_EQ(vector.getX(), vector_copy.getX());
        EXPECT_DOUBLE_EQ(vector.getY(), vector_copy.getY());
    }

    TEST_F(CVector2DFixture, CVector2D_CopyConstructorRValue_Test) {
        double x = nextRandomDouble();
        double y = nextRandomDouble();
        CVector2D vector(x, y);
        CVector2D vector_copy(std::move(vector));

        EXPECT_DOUBLE_EQ(x, vector_copy.getX());
        EXPECT_DOUBLE_EQ(y, vector_copy.getY());
    }

    TEST_F(CVector2DFixture, CVector2D_getLen_Test) {
        double x = nextRandomDouble();
        double y = nextRandomDouble();
        CVector2D vector(x, y);
        EXPECT_DOUBLE_EQ(sqrt(x * x + y * y), vector.getLen());
    }

    TEST_F(CVector2DFixture, CVector2D_operatorPlus_Test) {
        double x = nextRandomDouble();
        double y = nextRandomDouble();
        CVector2D vector(x, y);
        EXPECT_DOUBLE_EQ(x, vector.operator+().getX());
        EXPECT_DOUBLE_EQ(y, vector.operator+().getY());
    }

    TEST_F(CVector2DFixture, CVector2D_operatorMinus_Test) {
        double x = nextRandomDouble();
        double y = nextRandomDouble();
        CVector2D vector(x, y);
        EXPECT_DOUBLE_EQ(-x, vector.operator-().getX());
        EXPECT_DOUBLE_EQ(-y, vector.operator-().getY());
    }

    TEST_F(CVector2DFixture, CVector2D_operatorEqPlus_Test) {
        double x = nextRandomDouble();
        double y = nextRandomDouble();
        CVector2D vector_first(x, y);

        double x1 = nextRandomDouble();
        double y1 = nextRandomDouble();
        CVector2D vector_second(x1, y1);

        EXPECT_DOUBLE_EQ(x + x1, vector_first.operator+=(vector_second).getX());
        EXPECT_DOUBLE_EQ(y + y1 + y1, vector_first.operator+=(vector_second).getY());
    }

    TEST_F(CVector2DFixture, CVector2D_operatorEqMinus_Test) {
        double x = nextRandomDouble();
        double y = nextRandomDouble();
        CVector2D vector_first(x, y);

        double x1 = nextRandomDouble();
        double y1 = nextRandomDouble();
        CVector2D vector_second(x1, y1);

        EXPECT_DOUBLE_EQ(x - x1, vector_first.operator-=(vector_second).getX());
        EXPECT_DOUBLE_EQ(y - y1 - y1, vector_first.operator-=(vector_second).getY());
    }

    TEST_F(CVector2DFixture, CVector2D_isCollinear_zero_vectors_Test) {
        CVector2D vector_first(0.0, 0.0);
        CVector2D vector_second(0.0, 0.0);

        EXPECT_EQ(true, vector_first.isCollinear(vector_second));
    }

    TEST_F(CVector2DFixture, CVector2D_isCollinear_one_zero_vector_Test) {
        CVector2D vector_first(0.0, 4.2);
        CVector2D vector_second(0.0, 2.1);

        EXPECT_EQ(true, vector_first.isCollinear(vector_second));
    }

    TEST_F(CVector2DFixture, CVector2D_isCollinear_non_zero_vector_Test) {
        CVector2D vector_first(99.2, 600.1);
        CVector2D vector_second(49.6, 300.05);

        EXPECT_EQ(true, vector_first.isCollinear(vector_second));
    }

    TEST_F(CVector2DFixture, CVector2D_getAngleCos_zero_vectors_Test) {
        CVector2D vector_first(0.0, 0.0);
        CVector2D vector_second(0.0, 0.0);
        double expected_cos_value = 1;
        EXPECT_DOUBLE_EQ(expected_cos_value, vector_first.getAngleCos(vector_second));
    }

    TEST_F(CVector2DFixture, CVector2D_getAngleCos_one_zero_vector_Test) {
        CVector2D vector_first(11.1, 0.0);
        CVector2D vector_second(9.2, 0.0);
        double expected_cos_value = 1;
        EXPECT_DOUBLE_EQ(expected_cos_value, vector_first.getAngleCos(vector_second));
    }

    TEST_F(CVector2DFixture, CVector2D_getAngleCos_non_zero_vector_Test) {
        CVector2D vector_first(3.0, 1.0);
        CVector2D vector_second(2.0, 4.0);
        double expected_cos_value = sqrt(2) / 2;
        EXPECT_DOUBLE_EQ(expected_cos_value, vector_first.getAngleCos(vector_second));
    }
}
