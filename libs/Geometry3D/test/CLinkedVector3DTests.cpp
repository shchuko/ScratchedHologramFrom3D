#include <random>
#include <chrono>
#include <cmath>

#include <gtest/gtest.h>
#include <CLinkedVector3D.hpp>
#include <CPoint3D.hpp>

namespace Geometry3DCLinkedVector3DTests {
    using Geometry3D::CLinkedVector3D;
    using Geometry3D::CPoint3D;

    class CLinkedVector3DFixture : public ::testing::Test {
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

        CPoint3D nextRandomPoint3D() {
            double x = nextRandomDouble();
            double y = nextRandomDouble();
            double z = nextRandomDouble();
            return {x, y, z};
        }

        CLinkedVector3D nextRandomLinkedVector3D() {
            return {nextRandomPoint3D(), nextRandomPoint3D()};
        }
    };

    TEST_F(CLinkedVector3DFixture, CLinkedVector3D_Constructor_Test) {
        CPoint3D point_begin = nextRandomPoint3D();
        CPoint3D point_end = nextRandomPoint3D();
        CLinkedVector3D linked_vector_instance(point_begin, point_end);

        double x_expected = point_end.getX() - point_begin.getX();
        double y_expected = point_end.getY() - point_begin.getY();
        double z_expected = point_end.getZ() - point_begin.getZ();

        EXPECT_DOUBLE_EQ(x_expected, linked_vector_instance.getX());
        EXPECT_DOUBLE_EQ(y_expected, linked_vector_instance.getY());
        EXPECT_DOUBLE_EQ(z_expected, linked_vector_instance.getZ());
    }

    TEST_F(CLinkedVector3DFixture, CLinkedVector3D_getX_Test) {
        CPoint3D point_begin = nextRandomPoint3D();
        CPoint3D point_end = nextRandomPoint3D();

        CLinkedVector3D cLinkedVector3DTests(point_begin, point_end);
        double expected_get_x = point_end.getX() - point_begin.getX();
        EXPECT_DOUBLE_EQ(expected_get_x, cLinkedVector3DTests.getX());
    }

    TEST_F(CLinkedVector3DFixture, CLinkedVector3D_getY_Test) {
        CPoint3D point_begin = nextRandomPoint3D();
        CPoint3D point_end = nextRandomPoint3D();

        CLinkedVector3D cLinkedVector3DTests(point_begin, point_end);
        double expected_get_y = point_end.getY() - point_begin.getY();
        EXPECT_DOUBLE_EQ(expected_get_y, cLinkedVector3DTests.getY());
    }

    TEST_F(CLinkedVector3DFixture, CLinkedVector3D_getZ_Test) {
        CPoint3D point_begin = nextRandomPoint3D();
        CPoint3D point_end = nextRandomPoint3D();

        CLinkedVector3D cLinkedVector3DTests(point_begin, point_end);
        double expected_get_z = point_end.getZ() - point_begin.getZ();
        EXPECT_DOUBLE_EQ(expected_get_z, cLinkedVector3DTests.getZ());
    }

    TEST_F(CLinkedVector3DFixture, CLinkedVector3D_getLen_Test) {
        CPoint3D point_begin = nextRandomPoint3D();
        CPoint3D point_end = nextRandomPoint3D();

        CLinkedVector3D linked_vector(point_begin, point_end);
        double expected_len = sqrt(pow(linked_vector.getX(), 2)
                                   + pow(linked_vector.getY(), 2)
                                   + pow(linked_vector.getZ(), 2));

        EXPECT_DOUBLE_EQ(expected_len, linked_vector.getLen());
    }

    TEST_F(CLinkedVector3DFixture, CLinkedVector3D_getAngleCos_zero_vectors_Test) {
        CLinkedVector3D vector_first({0.0, 0, 0.0}, {0.0, 0, 0.0});
        CLinkedVector3D vector_second({0.0, 0, 0.0}, {0.0, 0, 0.0});

        double expected_cos_value = 1;
        EXPECT_DOUBLE_EQ(expected_cos_value, vector_first.getAngleCos(vector_second));
    }

    TEST_F(CLinkedVector3DFixture, CLinkedVector3D_getAngleCos_two_zero_vectors_Test) {
        CLinkedVector3D vector_first({4.1, 0, 0.0}, {11.1, 0, 0.0});
        CLinkedVector3D vector_second({2.1, 0, 0.0}, {7.1, 0, 0.0});

        double expected_cos_value = 1;
        EXPECT_DOUBLE_EQ(expected_cos_value, vector_first.getAngleCos(vector_second));
    }

    TEST_F(CLinkedVector3DFixture, CLinkedVector3D_getAngleCos_one_zero_vectors_Test) {
        CLinkedVector3D vector_first({4.1, 6.1, 0.0}, {11.1, 7.1, 0.0});
        CLinkedVector3D vector_second({2.1, 1.1, 0.0}, {7.1, 6.1, 0.0});

        double expected_cos_value = 0.8;
        EXPECT_DOUBLE_EQ(expected_cos_value, vector_first.getAngleCos(vector_second));
    }

    TEST_F(CLinkedVector3DFixture, CLinkedVector3D_getAngleCos_non_zero_vectors_Test) {
        CLinkedVector3D vector_first({4.1, 7.1, 1.1}, {6.1, 7.1, 0.1});
        CLinkedVector3D vector_second({2.1, 4.1, 0.0}, {3.1, 6.1, 3.0});

        double expected_cos_value = -1 / sqrt(70);
        EXPECT_DOUBLE_EQ(expected_cos_value, vector_first.getAngleCos(vector_second));
    }

    TEST_F(CLinkedVector3DFixture, CLinkedVector3D_isCollinear_zero_vectors_Test) {
        CLinkedVector3D vector_first({0.0, 0.0, 0.0}, {0.0, 0.0, 0.0});
        CLinkedVector3D vector_second({0.0, 0.0, 0.0}, {0.0, 0.0, 0.0});

        EXPECT_EQ(true, vector_first.isCollinear(vector_second));
    }

    TEST_F(CLinkedVector3DFixture, CLinkedVector3D_isCollinear_one_zero_vector_Test) {
        CPoint3D cPoint3D(0.0, 2.1, 2.1);
        CPoint3D cPoint3D1(0.0, 3.1, 3.1);

        CLinkedVector3D cLinkedVector3DTests(cPoint3D, cPoint3D1);

        CPoint3D new_cPoint3D(0.0, 2.1, 2.1);
        CPoint3D new_cPoint3D1(0.0, 3.1, 3.1);

        CLinkedVector3D new_cLinkedVector3DTests(new_cPoint3D, new_cPoint3D1);

        EXPECT_EQ(true, cLinkedVector3DTests.isCollinear(new_cLinkedVector3DTests));
    }

    TEST_F(CLinkedVector3DFixture, CLinkedVector3D_isCollinear_two_zero_vector_Test) {
        CPoint3D cPoint3D(0.0, 0.0, 2.1);
        CPoint3D cPoint3D1(0.0, 0.0, 3.1);

        CLinkedVector3D cLinkedVector3DTests(cPoint3D, cPoint3D1);

        CPoint3D new_cPoint3D(0.0, 0.0, 2.1);
        CPoint3D new_cPoint3D1(0.0, 0.0, 3.1);

        CLinkedVector3D new_cLinkedVector3DTests(new_cPoint3D, new_cPoint3D1);

        EXPECT_EQ(true, cLinkedVector3DTests.isCollinear(new_cLinkedVector3DTests));
    }

    TEST_F(CLinkedVector3DFixture, CLinkedVector3D_isCollinear_non_zero_vector_Test) {
        CPoint3D cPoint3D(2.1, 6.1, 999.1);
        CPoint3D cPoint3D1(3.1, 7.1, 1000.1);

        CLinkedVector3D cLinkedVector3DTests(cPoint3D, cPoint3D1);

        CPoint3D new_cPoint3D(2.1, 8.1, 119.1);
        CPoint3D new_cPoint3D1(3.1, 9.1, 120.1);

        CLinkedVector3D new_cLinkedVector3DTests(new_cPoint3D, new_cPoint3D1);

        EXPECT_EQ(true, cLinkedVector3DTests.isCollinear(new_cLinkedVector3DTests));
    }

    TEST_F(CLinkedVector3DFixture, CLinkedVector3D_isCollinear_false_Test) {
        CPoint3D cPoint3D(4, 6.1, 999.1);
        CPoint3D cPoint3D1(1, 7.1, 1000.1);

        CLinkedVector3D cLinkedVector3DTests(cPoint3D, cPoint3D1);

        CPoint3D new_cPoint3D(2.1, 9, 119.1);
        CPoint3D new_cPoint3D1(3.1, 2, 120.1);

        CLinkedVector3D new_cLinkedVector3DTests(new_cPoint3D, new_cPoint3D1);

        EXPECT_EQ(false, cLinkedVector3DTests.isCollinear(new_cLinkedVector3DTests));
    }


}