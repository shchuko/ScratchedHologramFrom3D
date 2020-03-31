#include <random>
#include <chrono>

#include <gtest/gtest.h>
#include <CPoint3D.hpp>
#include <CVector3D.hpp>


namespace Geometry3DCPoint3DTests {
    using Geometry3D::CPoint3D;
    using Geometry3D::CVector3D;
    using Geometry3D::AVector3D;

    class CPoint3DFixture : public ::testing::Test {
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
            z = nextRandomDouble();

            c_point_3d_fixture = new CPoint3D(x, y, z);
        }

        void TearDown() override {
            delete random_engine;
            delete distribution;
            delete c_point_3d_fixture;
        }

        CPoint3D *c_point_3d_fixture = nullptr;

        double x = 0.0;
        double y = 0.0;
        double z = 0.0;
    };

    TEST_F(CPoint3DFixture, CPoint3D_DefaultConstructor_Test) {
        CPoint3D point;
        EXPECT_DOUBLE_EQ(point.getX(), 0.0);
        EXPECT_DOUBLE_EQ(point.getY(), 0.0);
        EXPECT_DOUBLE_EQ(point.getZ(), 0.0);
    }

    TEST_F(CPoint3DFixture, CPoint3D_BuildFromCoordinatesConstructor_Test) {
        EXPECT_DOUBLE_EQ(x, c_point_3d_fixture->getX());
        EXPECT_DOUBLE_EQ(y, c_point_3d_fixture->getY());
        EXPECT_DOUBLE_EQ(z, c_point_3d_fixture->getZ());
    }

    TEST_F(CPoint3DFixture, CPoint3D_getX_Test) {
        EXPECT_DOUBLE_EQ(x, c_point_3d_fixture->getX());
    }

    TEST_F(CPoint3DFixture, CPoint3D_getY_Test) {
        EXPECT_DOUBLE_EQ(y, c_point_3d_fixture->getY());
    }

    TEST_F(CPoint3DFixture, CPoint3D_getZ_Test) {
        EXPECT_DOUBLE_EQ(z, c_point_3d_fixture->getZ());
    }

    TEST_F(CPoint3DFixture, CPoint3D_CopyConstReferenceConstructor_Test) {
        CPoint3D point_reference_copy(*c_point_3d_fixture);
        EXPECT_DOUBLE_EQ(c_point_3d_fixture->getX(), point_reference_copy.getX());
        EXPECT_DOUBLE_EQ(c_point_3d_fixture->getY(), point_reference_copy.getY());
        EXPECT_DOUBLE_EQ(c_point_3d_fixture->getZ(), point_reference_copy.getZ());
    }

    TEST_F(CPoint3DFixture, CPoint3D_CopyConstructorRValue_Test) {
        CPoint3D point_copy(*c_point_3d_fixture);

        CPoint3D point_rvalue_copy(std::move(point_copy));
        EXPECT_DOUBLE_EQ(c_point_3d_fixture->getX(), point_rvalue_copy.getX());
        EXPECT_DOUBLE_EQ(c_point_3d_fixture->getY(), point_rvalue_copy.getY());
        EXPECT_DOUBLE_EQ(c_point_3d_fixture->getZ(), point_rvalue_copy.getZ());
    }

    TEST_F(CPoint3DFixture, CPoint3D_move_Test) {
        double x_vector = nextRandomDouble();
        double y_vector = nextRandomDouble();
        double z_vector = nextRandomDouble();
        CVector3D vector(x_vector, y_vector, z_vector);

        CPoint3D point_copy(*c_point_3d_fixture);
        point_copy.move(vector);
        double x_expected = c_point_3d_fixture->getX() + vector.getX();
        double y_expected = c_point_3d_fixture->getY() + vector.getY();
        double z_expected = c_point_3d_fixture->getZ() + vector.getZ();

        EXPECT_DOUBLE_EQ(x_expected, point_copy.getX());
        EXPECT_DOUBLE_EQ(y_expected, point_copy.getY());
        EXPECT_DOUBLE_EQ(z_expected, point_copy.getZ());
    }

    TEST_F(CPoint3DFixture, CPoint3D_moveCopy_Test) {
        double x_vector = nextRandomDouble();
        double y_vector = nextRandomDouble();
        double z_vector = nextRandomDouble();
        CVector3D vector(x_vector, y_vector, z_vector);

        CPoint3D point_moved_copy = c_point_3d_fixture->moveCopy(vector);
        double x_expected = c_point_3d_fixture->getX() + vector.getX();
        double y_expected = c_point_3d_fixture->getY() + vector.getY();
        double z_expected = c_point_3d_fixture->getZ() + vector.getZ();

        EXPECT_DOUBLE_EQ(x_expected, point_moved_copy.getX());
        EXPECT_DOUBLE_EQ(y_expected, point_moved_copy.getY());
        EXPECT_DOUBLE_EQ(z_expected, point_moved_copy.getZ());
    }

    TEST_F(CPoint3DFixture, CPoint3D_getDistance_LValue_Test) {
        double x = nextRandomDouble();
        double y = nextRandomDouble();
        double z = nextRandomDouble();
        CPoint3D first_point(x, y, z);

        double x1 = nextRandomDouble();
        double y1 = nextRandomDouble();
        double z1 = nextRandomDouble();
        CPoint3D second_point(x1, y1, z1);

        double difference_between_x = x1 - x;
        double difference_between_y = y1 - y;
        double difference_between_z = z1 - z;

        double expected_distance = std::sqrt(
                difference_between_x * difference_between_x + difference_between_y * difference_between_y +
                difference_between_z * difference_between_z);

        EXPECT_DOUBLE_EQ(expected_distance, first_point.getDistance(second_point));
    }

    TEST_F(CPoint3DFixture, CPoint3D_getDistance_RValue_Test) {
        double x = nextRandomDouble();
        double y = nextRandomDouble();
        double z = nextRandomDouble();
        CPoint3D first_point(x, y, z);

        double x1 = nextRandomDouble();
        double y1 = nextRandomDouble();
        double z1 = nextRandomDouble();
        CPoint3D second_point(x1, y1, z1);
        double difference_between_x = x1 - x;
        double difference_between_y = y1 - y;
        double difference_between_z = z1 - z;

        double expected_distance = std::sqrt(
                difference_between_x * difference_between_x + difference_between_y * difference_between_y +
                difference_between_z * difference_between_z);
        EXPECT_DOUBLE_EQ(expected_distance, first_point.getDistance(std::move(second_point)));
    }

    TEST_F(CPoint3DFixture, CPoint3D_setX_Test) {
        double new_x = 1213.421;
        c_point_3d_fixture->setX(new_x);
        EXPECT_DOUBLE_EQ(new_x, c_point_3d_fixture->getX());

        new_x = nextRandomDouble();
        c_point_3d_fixture->setX(new_x);
        EXPECT_DOUBLE_EQ(new_x, c_point_3d_fixture->getX());
    }

    TEST_F(CPoint3DFixture, CPoint3D_setY_Test) {
        double new_y = 3425.342;
        c_point_3d_fixture->setY(new_y);
        EXPECT_DOUBLE_EQ(new_y, c_point_3d_fixture->getY());

        new_y = nextRandomDouble();
        c_point_3d_fixture->setY(new_y);
        EXPECT_DOUBLE_EQ(new_y, c_point_3d_fixture->getY());
    }

    TEST_F(CPoint3DFixture, CPoint3D_setZ_Test) {
        double new_z = -234235.342;
        c_point_3d_fixture->setZ(new_z);
        EXPECT_DOUBLE_EQ(new_z, c_point_3d_fixture->getZ());

        new_z = nextRandomDouble();
        c_point_3d_fixture->setZ(new_z);
        EXPECT_DOUBLE_EQ(new_z, c_point_3d_fixture->getZ());
    }
}
