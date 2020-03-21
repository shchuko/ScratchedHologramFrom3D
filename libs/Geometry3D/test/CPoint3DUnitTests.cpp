#include <random>
#include <chrono>

#include <gtest/gtest.h>
#include <CPoint3D.hpp>
#include <AVector3D.hpp>
#include <CVector3D.hpp>


namespace Geometry3DCPoint3DTests{
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
        CPoint3D cPoint3D;
        EXPECT_DOUBLE_EQ(cPoint3D.getX(), 0.0);
        EXPECT_DOUBLE_EQ(cPoint3D.getY(), 0.0);
        EXPECT_DOUBLE_EQ(cPoint3D.getZ(), 0.0);
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
        CVector3D cVector3D(x_vector, y_vector, z_vector);

        CPoint3D point_copy(*c_point_3d_fixture);
        point_copy.move(cVector3D);
        double x_expected = c_point_3d_fixture->getX() + cVector3D.getX();
        double y_expected = c_point_3d_fixture->getY() + cVector3D.getY();
        double z_expected = c_point_3d_fixture->getZ() + cVector3D.getZ();

        EXPECT_DOUBLE_EQ(x_expected, point_copy.getX());
        EXPECT_DOUBLE_EQ(y_expected, point_copy.getY());
        EXPECT_DOUBLE_EQ(z_expected, point_copy.getZ());
    }

    TEST_F(CPoint3DFixture, CPoint3D_moveCopy_Test) {
        double x_vector = nextRandomDouble();
        double y_vector = nextRandomDouble();
        double z_vector = nextRandomDouble();
        CVector3D cVector3D(x_vector, y_vector, z_vector);

        CPoint3D point_moved_copy = c_point_3d_fixture->moveCopy(cVector3D);
        double x_expected = c_point_3d_fixture->getX() + cVector3D.getX();
        double y_expected = c_point_3d_fixture->getY() + cVector3D.getY();
        double z_expected = c_point_3d_fixture->getZ() + cVector3D.getZ();

        EXPECT_DOUBLE_EQ(x_expected, point_moved_copy.getX());
        EXPECT_DOUBLE_EQ(y_expected, point_moved_copy.getY());
        EXPECT_DOUBLE_EQ(z_expected, point_moved_copy.getZ());
    }

}