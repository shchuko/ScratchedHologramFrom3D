#include <random>
#include <chrono>
#include <cmath>

#include <gtest/gtest.h>
#include <CLineSegment2D.hpp>
#include <CPoint2D.hpp>

namespace Geometry2DCLineSegment2DTests {
    using Geometry2D::CLineSegment2D;
    using Geometry2D::CPoint2D;

    class CLineSegment2DFixture : public ::testing::Test {
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

        CPoint2D nextRandomPoint2D() {
            double x = nextRandomDouble();
            double y = nextRandomDouble();
            return {x, y};
        }
    };

    TEST_F(CLineSegment2DFixture, CLineSegment2D_Constructor_Test) {
        CPoint2D first_point = nextRandomPoint2D();
        CPoint2D second_point = nextRandomPoint2D();
        CLineSegment2D line_segment_2D(first_point, second_point);
        EXPECT_DOUBLE_EQ(first_point.getX(), line_segment_2D.getFirstPoint().getX());
        EXPECT_DOUBLE_EQ(first_point.getY(), line_segment_2D.getFirstPoint().getY());
        EXPECT_DOUBLE_EQ(second_point.getX(), line_segment_2D.getSecondPoint().getX());
        EXPECT_DOUBLE_EQ(second_point.getY(), line_segment_2D.getSecondPoint().getY());
    }

    TEST_F(CLineSegment2DFixture, CLineSegment2D_getFirstPoint_Test) {
        CPoint2D first_point = nextRandomPoint2D();
        CPoint2D second_point = nextRandomPoint2D();
        CLineSegment2D line_segment_2D(first_point, second_point);
        EXPECT_DOUBLE_EQ(first_point.getX(), line_segment_2D.getFirstPoint().getX());
        EXPECT_DOUBLE_EQ(first_point.getY(), line_segment_2D.getFirstPoint().getY());
    }

    TEST_F(CLineSegment2DFixture, CLineSegment2D_getSecondPoint_Test) {
        CPoint2D first_point = nextRandomPoint2D();
        CPoint2D second_point = nextRandomPoint2D();
        CLineSegment2D line_segment_2D(first_point, second_point);
        EXPECT_DOUBLE_EQ(second_point.getX(), line_segment_2D.getSecondPoint().getX());
        EXPECT_DOUBLE_EQ(second_point.getY(), line_segment_2D.getSecondPoint().getY());
    }

    TEST_F(CLineSegment2DFixture, CLineSegment2D_getLen_Test) {
        CPoint2D first_point = nextRandomPoint2D();
        CPoint2D second_point = nextRandomPoint2D();
        CLineSegment2D line_segment_2D(first_point, second_point);

        double expected_length = sqrt(
                (second_point.getX() - first_point.getX()) * (second_point.getX() - first_point.getX()) +
                (second_point.getY() - first_point.getY()) * (second_point.getY() - first_point.getY()));
        EXPECT_DOUBLE_EQ(expected_length, line_segment_2D.getLen());
    }
}