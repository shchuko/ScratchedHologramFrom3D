#include <random>
#include <chrono>

#include <gtest/gtest.h>
#include <CPoint2D.hpp>
#include <CVector2D.hpp>

namespace Geometry2DCPoint2DTests {
    using Geometry2D::CPoint2D;
    using Geometry2D::CVector2D;
    using Geometry2D::AVector2D;

    class CPoint2DFixture : public ::testing::Test {
    private:
        static constexpr double MAX_DOUBLE_VALUE = 10000.0;
        static constexpr double MIN_DOUBLE_VALUE = -10000.0;

        std::uniform_real_distribution<double> *distribution = nullptr;
        std::mt19937 *random_engine = nullptr;

    protected:
        double nextRandomDouble() {
            return (*distribution)(*random_engine);
        }

        void SetUp() override {
            distribution = new std::uniform_real_distribution<double>(MIN_DOUBLE_VALUE, MAX_DOUBLE_VALUE);
            random_engine = new std::mt19937(std::chrono::system_clock::now().time_since_epoch().count());

            x = nextRandomDouble();
            y = nextRandomDouble();

            c_point_2d_fixture = new CPoint2D(x, y);
        }

        void TearDown() override {
            delete random_engine;
            delete distribution;
            delete c_point_2d_fixture;
        }

        CPoint2D *c_point_2d_fixture = nullptr;

        double x = 0.0;
        double y = 0.0;
    };

    TEST_F(CPoint2DFixture, CPoint2D_DefaultConstructor_Test) {
        CPoint2D point;
        EXPECT_DOUBLE_EQ(0.0, point.getX());
        EXPECT_DOUBLE_EQ(0.0, point.getY());
    }

    TEST_F(CPoint2DFixture, CPoint2D_BuildFromCoordinatesConstructor_Test) {
        EXPECT_DOUBLE_EQ(x, c_point_2d_fixture->getX());
        EXPECT_DOUBLE_EQ(y, c_point_2d_fixture->getY());
    }

    TEST_F(CPoint2DFixture, CPoint2D_getX_Test) {
        EXPECT_DOUBLE_EQ(x, c_point_2d_fixture->getX());
    }

    TEST_F(CPoint2DFixture, CPoint2D_getY_Test) {
        EXPECT_DOUBLE_EQ(y, c_point_2d_fixture->getY());
    }

    TEST_F(CPoint2DFixture, CPoint2D_CopyConstReferenceConstructor_Test) {
        CPoint2D point_reference_copy(*c_point_2d_fixture);
        EXPECT_DOUBLE_EQ(c_point_2d_fixture->getX(), point_reference_copy.getX());
        EXPECT_DOUBLE_EQ(c_point_2d_fixture->getY(), point_reference_copy.getY());
    }

    TEST_F(CPoint2DFixture, CPoint2D_CopyConstructorRValue_Test) {
        CPoint2D point_copy(*c_point_2d_fixture);

        CPoint2D point_rvalue_copy(std::move(point_copy));
        EXPECT_DOUBLE_EQ(c_point_2d_fixture->getX(), point_rvalue_copy.getX());
        EXPECT_DOUBLE_EQ(c_point_2d_fixture->getY(), point_rvalue_copy.getY());
    }

    TEST_F(CPoint2DFixture, CPoint2D_move_Test) {
        double x_vector = nextRandomDouble();
        double y_vector = nextRandomDouble();
        CVector2D vector(x_vector, y_vector);

        CPoint2D point_copy(*c_point_2d_fixture);
        point_copy.move(vector);
        double x_expected = c_point_2d_fixture->getX() + vector.getX();
        double y_expected = c_point_2d_fixture->getY() + vector.getY();

        EXPECT_DOUBLE_EQ(x_expected, c_point_2d_fixture->getX() + vector.getX());
        EXPECT_DOUBLE_EQ(y_expected, c_point_2d_fixture->getY() + vector.getY());
    }

    TEST_F(CPoint2DFixture, CPoint2D_moveCopy_Test) {
        double x_vector = nextRandomDouble();
        double y_vector = nextRandomDouble();
        CVector2D vector(x_vector, y_vector);

        CPoint2D point_moved_copy = c_point_2d_fixture->moveCopy(vector);
        double x_expected = c_point_2d_fixture->getX() + vector.getX();
        double y_expected = c_point_2d_fixture->getY() + vector.getY();

        EXPECT_DOUBLE_EQ(x_expected, point_moved_copy.getX());
        EXPECT_DOUBLE_EQ(y_expected, point_moved_copy.getY());
    }
}