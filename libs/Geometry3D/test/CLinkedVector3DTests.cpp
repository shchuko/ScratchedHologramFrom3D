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

        CLinkedVector3D linked_vector(point_begin, point_end);
        double expected_get_x = point_end.getX() - point_begin.getX();
        EXPECT_DOUBLE_EQ(expected_get_x, linked_vector.getX());
    }

    TEST_F(CLinkedVector3DFixture, CLinkedVector3D_getY_Test) {
        CPoint3D point_begin = nextRandomPoint3D();
        CPoint3D point_end = nextRandomPoint3D();

        CLinkedVector3D linked_vector(point_begin, point_end);
        double expected_get_y = point_end.getY() - point_begin.getY();
        EXPECT_DOUBLE_EQ(expected_get_y, linked_vector.getY());
    }

    TEST_F(CLinkedVector3DFixture, CLinkedVector3D_getZ_Test) {
        CPoint3D point_begin = nextRandomPoint3D();
        CPoint3D point_end = nextRandomPoint3D();

        CLinkedVector3D linked_vector(point_begin, point_end);
        double expected_get_z = point_end.getZ() - point_begin.getZ();
        EXPECT_DOUBLE_EQ(expected_get_z, linked_vector.getZ());
    }

    TEST_F(CLinkedVector3DFixture, CLinkedVector3D_getLen_Test) {
        CPoint3D point_begin = nextRandomPoint3D();
        CPoint3D point_end = nextRandomPoint3D();
        CLinkedVector3D linked_vector(point_begin, point_end);

        double expected_len = sqrt(linked_vector.getX() * linked_vector.getX()
                                   + linked_vector.getY() * linked_vector.getY()
                                   + linked_vector.getZ() * linked_vector.getZ());

        EXPECT_DOUBLE_EQ(expected_len, linked_vector.getLen());
    }

    TEST_F(CLinkedVector3DFixture, CLinkedVector3D_getAngleCos_zero_vectors_Test) {
        CPoint3D begin_first(0.0, 0.0, 0.0);
        CPoint3D end_first(0.0, 0.0, 0.0);
        CLinkedVector3D vector_first(begin_first, end_first);

        CPoint3D begin_second(0.0, 0.0, 0.0);
        CPoint3D end_second(0.0, 0.0, 0.0);
        CLinkedVector3D vector_second(begin_second, end_second);

        double expected_cos_value = 1;
        EXPECT_DOUBLE_EQ(expected_cos_value, vector_first.getAngleCos(vector_second));
    }

    TEST_F(CLinkedVector3DFixture, CLinkedVector3D_getAngleCos_two_zero_vectors_Test) {
        CPoint3D begin_first(4.1, 0.0, 0.0);
        CPoint3D end_first(11.1, 0.0, 0.0);
        CLinkedVector3D vector_first(begin_first, end_first);

        CPoint3D begin_second(2.1, 0.0, 0.0);
        CPoint3D end_second(7.1, 0.0, 0.0);
        CLinkedVector3D vector_second(begin_second, end_second);

        double expected_cos_value = 1;
        EXPECT_DOUBLE_EQ(expected_cos_value, vector_first.getAngleCos(vector_second));
    }

    TEST_F(CLinkedVector3DFixture, CLinkedVector3D_getAngleCos_one_zero_vectors_Test) {
        CPoint3D begin_first(4.1, 6.1, 0.0);
        CPoint3D end_first(11.1, 7.1, 0.0);
        CLinkedVector3D vector_first(begin_first, end_first);

        CPoint3D begin_second(2.1, 1.1, 0.0);
        CPoint3D end_second(7.1, 6.1, 0.0);
        CLinkedVector3D vector_second(begin_second, end_second);

        double expected_cos_value = 0.8;
        EXPECT_DOUBLE_EQ(expected_cos_value, vector_first.getAngleCos(vector_second));
    }

    TEST_F(CLinkedVector3DFixture, CLinkedVector3D_getAngleCos_non_zero_vectors_Test) {
        CPoint3D begin_first(4.1, 7.1, 1.1);
        CPoint3D end_first(6.1, 7.1, 0.1);
        CLinkedVector3D vector_first(begin_first, end_first);

        CPoint3D begin_second(2.1, 4.1, 0.0);
        CPoint3D end_second(3.1, 6.1, 3.0);
        CLinkedVector3D vector_second(begin_second, end_second);

        double expected_cos_value = -1 / sqrt(70);
        EXPECT_DOUBLE_EQ(expected_cos_value, vector_first.getAngleCos(vector_second));
    }

    TEST_F(CLinkedVector3DFixture, CLinkedVector3D_isCollinear_zero_vectors_Test) {
        CPoint3D begin_first(0.0, 0.0, 0.0);
        CPoint3D end_first(0.0, 0.0, 0.0);
        CLinkedVector3D vector_first(begin_first, end_first);

        CPoint3D begin_second(0.0, 0.0, 0.0);
        CPoint3D end_second(0.0, 0.0, 0.0);
        CLinkedVector3D vector_second(begin_second, end_second);

        EXPECT_EQ(true, vector_first.isCollinear(vector_second));
    }

    TEST_F(CLinkedVector3DFixture, CLinkedVector3D_isCollinear_one_zero_vector_Test) {
        CPoint3D begin_first(0.0, 2.1, 2.1);
        CPoint3D end_first(0.0, 3.1, 3.1);
        CLinkedVector3D vector_first(begin_first, end_first);

        CPoint3D begin_second(0.0, 2.1, 2.1);
        CPoint3D end_second(0.0, 3.1, 3.1);
        CLinkedVector3D vector_second(begin_second, end_second);

        EXPECT_EQ(true, vector_first.isCollinear(vector_second));
    }

    TEST_F(CLinkedVector3DFixture, CLinkedVector3D_isCollinear_two_zero_vector_Test) {
        CPoint3D begin_first(0.0, 0.0, 2.1);
        CPoint3D end_first(0.0, 0.0, 3.1);
        CLinkedVector3D vector_first(begin_first, end_first);

        CPoint3D begin_second(0.0, 0.0, 2.1);
        CPoint3D end_second(0.0, 0.0, 3.1);
        CLinkedVector3D vector_second(begin_second, end_second);

        EXPECT_EQ(true, vector_first.isCollinear(vector_second));
    }

    TEST_F(CLinkedVector3DFixture, CLinkedVector3D_isCollinear_non_zero_vector_Test) {
        CPoint3D begin_first(2.1, 6.1, 999.1);
        CPoint3D end_first(3.1, 7.1, 1000.1);
        CLinkedVector3D vector_first(begin_first, end_first);

        CPoint3D begin_second(2.1, 8.1, 119.1);
        CPoint3D end_second(3.1, 9.1, 120.1);
        CLinkedVector3D vector_second(begin_second, end_second);

        EXPECT_EQ(true, vector_first.isCollinear(vector_second));
    }

    TEST_F(CLinkedVector3DFixture, CLinkedVector3D_isCollinear_false_Test) {
        CPoint3D begin_first(4.0, 6.1, 999.1);
        CPoint3D end_first(1.0, 7.1, 1000.1);
        CLinkedVector3D vector_first(begin_first, end_first);

        CPoint3D begin_second(2.1, 9, 119.1);
        CPoint3D end_second(3.1, 2, 120.1);
        CLinkedVector3D vector_second(begin_second, end_second);

        EXPECT_EQ(false, vector_first.isCollinear(vector_second));
    }

}
