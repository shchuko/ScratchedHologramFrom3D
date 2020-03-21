#include <random>
#include <chrono>

#include <gtest/gtest.h>
#include <AVector3D.hpp>
#include <CVector3D.hpp>
#include <Geometry3DOperators.hpp>

namespace Geometry3DCVector3DTests {
    using Geometry3D::CVector3D;

    class CVector3DFixture : public ::testing::Test {
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
            z_fixture = nextRandomDouble();
            c_vector_3d_fixture = new CVector3D(x_fixture, y_fixture, z_fixture);

        }

        void TearDown() override {
            delete random_engine;
            delete distribution;
            delete c_vector_3d_fixture;
        }

        double nextRandomDouble() {
            return (*distribution)(*random_engine);
        }

        double x_fixture = 0.0;
        double y_fixture = 0.0;
        double z_fixture = 0.0;

        CVector3D *c_vector_3d_fixture = nullptr;
    };

    TEST_F(CVector3DFixture, CVector3D_BuildFromCoordinatesConstructor_Test) {
        double x = nextRandomDouble();
        double y = nextRandomDouble();
        double z = nextRandomDouble();
        CVector3D vector_instance(x, y, z);

        EXPECT_DOUBLE_EQ(x, vector_instance.getX());
        EXPECT_DOUBLE_EQ(y, vector_instance.getY());
        EXPECT_DOUBLE_EQ(z, vector_instance.getZ());
    }


    TEST_F(CVector3DFixture, CVector3D_DefaultConstructor_Test) {
        CVector3D cVector3D;
        EXPECT_DOUBLE_EQ(cVector3D.getX(), 0.0);
        EXPECT_DOUBLE_EQ(cVector3D.getY(), 0.0);
        EXPECT_DOUBLE_EQ(cVector3D.getZ(), 0.0);
    }


    TEST_F(CVector3DFixture, CVector3D_getX_Test) {
        double x = nextRandomDouble();
        CVector3D cVector3D(x, 0.0, 0.0);
        EXPECT_DOUBLE_EQ(x, cVector3D.getX());
    }

    TEST_F(CVector3DFixture, CVector3D_getY_Test) {
        double y = nextRandomDouble();
        CVector3D cVector3D(0.0, y, 0.0);
        EXPECT_DOUBLE_EQ(y, cVector3D.getY());
    }

    TEST_F(CVector3DFixture, CVector3D_getZ_Test) {
        double z = nextRandomDouble();
        CVector3D cVector3D(0.0, 0.0, z);
        EXPECT_DOUBLE_EQ(z, cVector3D.getZ());
    }

    TEST_F(CVector3DFixture, CVector3D_CopyConstReferenceConstructor_Test) {
        CVector3D cVector3D(nextRandomDouble(), nextRandomDouble(), nextRandomDouble());
        CVector3D cVector3DCopy(cVector3D);
        EXPECT_DOUBLE_EQ(cVector3D.getX(), cVector3DCopy.getX());
        EXPECT_DOUBLE_EQ(cVector3D.getY(), cVector3DCopy.getY());
        EXPECT_DOUBLE_EQ(cVector3D.getZ(), cVector3DCopy.getZ());
    }

    TEST_F(CVector3DFixture, CVector3D_CopyConstructorRValue_Test) {
        double x = nextRandomDouble();
        double y = nextRandomDouble();
        double z = nextRandomDouble();
        CVector3D cVector3D(x, y, z);
        CVector3D cVector3DCopy(std::move(cVector3D));

        EXPECT_DOUBLE_EQ(x, cVector3DCopy.getX());
        EXPECT_DOUBLE_EQ(y, cVector3DCopy.getY());
        EXPECT_DOUBLE_EQ(z, cVector3DCopy.getZ());
    }

    TEST_F(CVector3DFixture, CVector3D_getLen_Test) {
        double x = nextRandomDouble();
        double y = nextRandomDouble();
        double z = nextRandomDouble();
        CVector3D cVector3D(x, y, z);
        EXPECT_DOUBLE_EQ(sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2)), cVector3D.getLen());
    }


    TEST_F(CVector3DFixture, CVector3D_operatorPlus_Test) {
        double x = nextRandomDouble();
        double y = nextRandomDouble();
        double z = nextRandomDouble();
        CVector3D cVector3D(x, y, z);
        EXPECT_DOUBLE_EQ(x, cVector3D.operator+().getX());
        EXPECT_DOUBLE_EQ(y, cVector3D.operator+().getY());
        EXPECT_DOUBLE_EQ(z, cVector3D.operator+().getZ());
    }

    TEST_F(CVector3DFixture, CVector3D_operatorMinus_Test) {
        double x = nextRandomDouble();
        double y = nextRandomDouble();
        double z = nextRandomDouble();
        CVector3D cVector3D(x, y, z);
        EXPECT_DOUBLE_EQ(-x, cVector3D.operator-().getX());
        EXPECT_DOUBLE_EQ(-y, cVector3D.operator-().getY());
        EXPECT_DOUBLE_EQ(-z, cVector3D.operator-().getZ());
    }

    TEST_F(CVector3DFixture, CVector3D_operatorEqPlus_Test) {
        double x = nextRandomDouble();
        double y = nextRandomDouble();
        double z = nextRandomDouble();
        CVector3D cVector3D(x, y, z);
        double x1 = nextRandomDouble();
        double y1 = nextRandomDouble();
        double z1 = nextRandomDouble();
        CVector3D cVector3D1(x1, y1, z1);
        EXPECT_DOUBLE_EQ(x + cVector3D1.getX(), cVector3D.operator+=(cVector3D1).getX());
        EXPECT_DOUBLE_EQ(y + cVector3D1.getY() + cVector3D1.getY(),
                         cVector3D.operator+=(cVector3D1).getY());
        EXPECT_DOUBLE_EQ(z + cVector3D1.getZ() + cVector3D1.getZ() + cVector3D1.getZ(),
                         cVector3D.operator+=(cVector3D1).getZ());
    }

    TEST_F(CVector3DFixture, CVector3D_opertorEqMinus_Test) {
        double x = nextRandomDouble();
        double y = nextRandomDouble();
        double z = nextRandomDouble();
        CVector3D cVector3D(x, y, z);
        double x1 = nextRandomDouble();
        double y1 = nextRandomDouble();
        double z1 = nextRandomDouble();
        CVector3D cVector3D1(x1, y1, z1);
        EXPECT_DOUBLE_EQ(x - cVector3D1.getX(), cVector3D.operator-=(cVector3D1).getX());
        EXPECT_DOUBLE_EQ(y - cVector3D1.getY() - cVector3D1.getY(),
                         cVector3D.operator-=(cVector3D1).getY());
        EXPECT_DOUBLE_EQ(z - cVector3D1.getZ() - cVector3D1.getZ() - cVector3D1.getZ(),
                         cVector3D.operator-=(cVector3D1).getZ());
    }

    TEST_F(CVector3DFixture, CVector3D_isCollinear_zero_vectors_Test) {
        CVector3D vector_first(0.0, 0.0, 0.0);
        CVector3D vector_second(0.0, 0.0, 0.0);

        EXPECT_EQ(true, vector_first.isCollinear(vector_second));
    }

    TEST_F(CVector3DFixture, CVector3D_isCollinear_two_zero_vectors_Test) {
        CVector3D vector_first(0.0, 0.0, 3.1);
        CVector3D vector_second(0.0, 0.0, 3.1);

        EXPECT_EQ(true, vector_first.isCollinear(vector_second));
    }

    TEST_F(CVector3DFixture, CVector3D_isCollinear_one_zero_vectors_Test) {
        CVector3D vector_first(0.0, 4.2, 6.2);
        CVector3D vector_second(0.0, 2.1, 3.1);

        EXPECT_EQ(true, vector_first.isCollinear(vector_second));
    }

    TEST_F(CVector3DFixture, CVector3D_isCollinear_non_zero_vectors_Test) {
        CVector3D vector_first(99.2, 600.1, 3.6);
        CVector3D vector_second(49.6, 300.05, 1.8);

        EXPECT_EQ(true, vector_first.isCollinear(vector_second));
    }

    TEST_F(CVector3DFixture, CVector3D_getAngleCos_zero_vectors_Test) {
        CVector3D vector_first(0.0, 0.0, 0.0);
        CVector3D vector_second(0.0, 0.0, 0.0);
        double expected_cos_value = 1;
        EXPECT_DOUBLE_EQ(expected_cos_value, vector_first.getAngleCos(vector_second));
    }

    TEST_F(CVector3DFixture, CVector3D_getAngleCos_two_zero_vectors_Test) {
        CVector3D vector_first(11.1, 0.0, 0.0);
        CVector3D vector_second(6.11, 0.0, 0.0);
        double expected_cos_value = 1;
        EXPECT_DOUBLE_EQ(expected_cos_value, vector_first.getAngleCos(vector_second));
    }

    TEST_F(CVector3DFixture, CVector3D_getAngleCos_one_zero_vectors_Test) {
        CVector3D vector_first(11.4, 6.3, 0.0);
        CVector3D vector_second(4.12, 2.6, 0.0);
        double expected_cos_value = 0.99831327785173063;
        EXPECT_DOUBLE_EQ(expected_cos_value, vector_first.getAngleCos(vector_second));
    }

    TEST_F(CVector3DFixture, CVector3D_getAngleCos_non_zero_vectors_Test) {
        CVector3D vector_first(11.4, 6.3, 9.5);
        CVector3D vector_second(4.12, 2.6, 80.2);
        double expected_cos_value = 0.63709935889147207;
        EXPECT_DOUBLE_EQ(expected_cos_value, vector_first.getAngleCos(vector_second));
    }
}
