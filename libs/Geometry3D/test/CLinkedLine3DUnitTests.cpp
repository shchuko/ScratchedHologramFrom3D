#include <random>
#include <chrono>
#include <cmath>

#include <gtest/gtest.h>
#include <CLinkedLine3D.hpp>
#include <CVector3D.hpp>
#include <CPoint3D.hpp>
#include <CLinkedVector3D.hpp>


namespace Geometry3DCLinkedLine3DTests {
    using Geometry3D::CVector3D;
    using Geometry3D::CPoint3D;
    using Geometry3D::CLinkedLine3D;

    class CLinkedLine3DFixture : public ::testing::Test {
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

        CVector3D nextRandomCVector3D() {
            double x = nextRandomDouble();
            double y = nextRandomDouble();
            double z = nextRandomDouble();
            return {x, y, z};
        }

    };

    TEST_F(CLinkedLine3DFixture, CLinkedLine3D_Constructor_Test) {
        CPoint3D point = nextRandomPoint3D();
        CVector3D vector = nextRandomCVector3D();

        CLinkedLine3D line(vector, point);
        EXPECT_EQ(&point, &line.getLinkedPoint());
        EXPECT_EQ(&vector, &line.getDirectionVector());
    }

    TEST_F(CLinkedLine3DFixture, CLinkedLine3D_getLinkedPoint_Test) {
        CPoint3D point = nextRandomPoint3D();
        CVector3D vector = nextRandomCVector3D();

        CLinkedLine3D line(vector, point);
        EXPECT_EQ(&point, &line.getLinkedPoint());
    }

    TEST_F(CLinkedLine3DFixture, CLinkedLine3D_getDirectionVector_Test) {
        CPoint3D point = nextRandomPoint3D();
        CVector3D vector = nextRandomCVector3D();

        CLinkedLine3D line(vector, point);
        EXPECT_EQ(&vector, &line.getDirectionVector());
    }

    TEST_F(CLinkedLine3DFixture, CLinkedLine3D_setLinkedPoint_Test) {
        CPoint3D point = nextRandomPoint3D();
        CVector3D vector = nextRandomCVector3D();

        CLinkedLine3D line(vector, point);

        CPoint3D new_point = nextRandomPoint3D();
        line.setLinkedPoint(new_point);

        EXPECT_EQ(&new_point, &line.getLinkedPoint());
    }

    TEST_F(CLinkedLine3DFixture, CLinkedLine3D_setDirectionVector_Test) {
        CPoint3D point = nextRandomPoint3D();
        CVector3D vector = nextRandomCVector3D();

        CLinkedLine3D line(vector, point);

        CVector3D new_vector = nextRandomCVector3D();
        line.setDirectionVector(new_vector);

        EXPECT_EQ(&new_vector, &line.getDirectionVector());
    }

    TEST_F(CLinkedLine3DFixture, CLinkedLine3D_getRelationType_PARALLEL_Test) {
        CPoint3D first_point(-4.0, -5.0, 6.0);
        CVector3D first_vector(-2.0, 4.0, 6.0);
        CLinkedLine3D first_line(first_vector, first_point);

        CPoint3D second_point(0.0, 1.0, -3.0);
        CVector3D second_vector(1.0, -2.0, -3.0);
        CLinkedLine3D second_line(second_vector, second_point);

        EXPECT_EQ(CLinkedLine3D::RelationType::PARALLEL, first_line.getRelationType(second_line));
    }

    TEST_F(CLinkedLine3DFixture, CLinkedLine3D_getRelationType_SKEW_Test) {
        CPoint3D first_point(2.0, -1.0, 0.0);
        CVector3D first_vector(2.0, -3.0, -1.0);
        CLinkedLine3D first_line(first_vector, first_point);

        CPoint3D second_point(-1.0, 0.0, 1.0);
        CVector3D second_vector(1.0, -2.0, 0.0);
        CLinkedLine3D second_line(second_vector, second_point);

        EXPECT_EQ(CLinkedLine3D::RelationType::SKEW, first_line.getRelationType(second_line));
    }

    TEST_F(CLinkedLine3DFixture, CLinkedLine3D_getRelationType_CROSSING_Test) {
        CPoint3D first_point(3.0, -3.0, 2.0);
        CVector3D first_vector(-1.0, 1.0, 2.0);
        CLinkedLine3D first_line(first_vector, first_point);

        CPoint3D second_point(-1.0, 4.0, -26.0);
        CVector3D second_vector(3.0, -4.0, 6.0);
        CLinkedLine3D second_line(second_vector, second_point);

        EXPECT_EQ(CLinkedLine3D::RelationType::CROSSING, first_line.getRelationType(second_line));
    }

    TEST_F(CLinkedLine3DFixture, CLinkedLine3D_getRelationType_OVERLAP_Test) {
        CPoint3D first_point(-4.0, -5.0, 6.0);
        CVector3D first_vector(-2.0, 4.0, 6.0);
        CLinkedLine3D first_line(first_vector, first_point);

        CPoint3D second_point(4.0, -21.0, -18.0);
        CVector3D second_vector(-2.0, 4.0, 6.0);
        CLinkedLine3D second_line(second_vector, second_point);

        EXPECT_EQ(CLinkedLine3D::RelationType::OVERLAP, first_line.getRelationType(second_line));
    }

    TEST_F(CLinkedLine3DFixture, CLinkedLine3D_isPointOnLine_Test) {
        CPoint3D first_point(-8.0, -10.0, 12.0);
        CVector3D first_vector(-4.0, 8.0, 12.0);
        CLinkedLine3D first_line(first_vector, first_point);

        CPoint3D second_point(8.0, -42.0, -36.0);
        EXPECT_EQ(true, first_line.isPointOnLine(second_point));
    }

    TEST_F(CLinkedLine3DFixture, CLinkedLine3D_getCrossingPoint_CROSSING_Test) {
        CPoint3D first_point(3.0, -3.0, 2.0);
        CVector3D first_vector(-1.0, 1.0, 2.0);
        CLinkedLine3D first_line(first_vector, first_point);

        CPoint3D second_point(-1.0, 4.0, -26.0);
        CVector3D second_vector(3.0, -4.0, 6.0);
        CLinkedLine3D second_line(second_vector, second_point);

        CPoint3D crossing_point = first_line.getCrossingPoint(second_line);

        EXPECT_DOUBLE_EQ(8.0, crossing_point.getX());
        EXPECT_DOUBLE_EQ(-8.0, crossing_point.getY());
        EXPECT_DOUBLE_EQ(-8.0, crossing_point.getZ());
    }

    TEST_F(CLinkedLine3DFixture, CLinkedLine3D_getCrossingPoint_PARALLEL_Test) {
        CPoint3D first_point(-4.0, -5.0, 6.0);
        CVector3D first_vector(-2.0, 4.0, 6.0);
        CLinkedLine3D first_line(first_vector, first_point);

        CPoint3D second_point(0.0, 1.0, -3.0);
        CVector3D second_vector(1.0, -2.0, -3.0);
        CLinkedLine3D second_line(second_vector, second_point);

        CPoint3D crossing_point = first_line.getCrossingPoint(second_line);

        EXPECT_TRUE(std::isnan(crossing_point.getX()));
        EXPECT_TRUE(std::isnan(crossing_point.getY()));
        EXPECT_TRUE(std::isnan(crossing_point.getZ()));
    }

    TEST_F(CLinkedLine3DFixture, CLinkedLine3D_getCrossingPoint_SKEW_Test) {
        CPoint3D first_point(2.0, -1.0, 0.0);
        CVector3D first_vector(2.0, -3.0, -1.0);
        CLinkedLine3D first_line(first_vector, first_point);

        CPoint3D second_point(-1.0, 0.0, 1.0);
        CVector3D second_vector(1.0, -2.0, 0.0);
        CLinkedLine3D second_line(second_vector, second_point);

        CPoint3D crossing_point = first_line.getCrossingPoint(second_line);

        EXPECT_TRUE(std::isnan(crossing_point.getX()));
        EXPECT_TRUE(std::isnan(crossing_point.getY()));
        EXPECT_TRUE(std::isnan(crossing_point.getZ()));
    }

    TEST_F(CLinkedLine3DFixture, CLinkedLine3D_getCrossinPoint_OVERLAP_Test) {
        CPoint3D first_point(-4.0, -5.0, 6.0);
        CVector3D first_vector(-2.0, 4.0, 6.0);
        CLinkedLine3D first_line(first_vector, first_point);

        CPoint3D second_point(4.0, -21.0, -18.0);
        CVector3D second_vector(-2.0, 4.0, 6.0);
        CLinkedLine3D second_line(second_vector, second_point);

        CPoint3D crossing_point = first_line.getCrossingPoint(second_line);

        EXPECT_TRUE(std::isinf(crossing_point.getX()));
        EXPECT_TRUE(std::isinf(crossing_point.getY()));
        EXPECT_TRUE(std::isinf(crossing_point.getZ()));
    }

    class RandomCLinkedLine3DFixture : public ::testing::Test {
    private:
        static constexpr double MAX_DOUBLE_VALUE = 10000.0;
        static constexpr double MIN_DOUBLE_VALUE = -10000.0;

        std::uniform_real_distribution<double> *distribution = nullptr;
        std::mt19937 *random_engine = nullptr;

    protected:
        void SetUp() override {
            distribution = new std::uniform_real_distribution<double>(MIN_DOUBLE_VALUE, MAX_DOUBLE_VALUE);
            random_engine = new std::mt19937(std::chrono::system_clock::now().time_since_epoch().count());

            p_line_point = nextRandomPoint3D();
            p_second_line_point = nextRandomPoint3D();
            p_line_direction_vec = new Geometry3D::CLinkedVector3D(*p_line_point, *p_second_line_point);
            p_line_fixture = new Geometry3D::CLinkedLine3D(*p_line_direction_vec, *p_line_point);
        }

        void TearDown() override {
            delete random_engine;
            delete distribution;
            delete p_line_fixture;
            delete p_line_direction_vec;
            delete p_line_point;
            delete p_second_line_point;
        }

        double nextRandomDouble() {
            return (*distribution)(*random_engine);
        }

        CPoint3D* nextRandomPoint3D() {
            double x = nextRandomDouble();
            double y = nextRandomDouble();
            double z = nextRandomDouble();
            return new CPoint3D(x, y, z);
        }

        Geometry3D::CPoint3D *p_line_point = nullptr;
        Geometry3D::CPoint3D *p_second_line_point = nullptr;
        Geometry3D::CLinkedVector3D  *p_line_direction_vec = nullptr;
        Geometry3D::CLinkedLine3D *p_line_fixture = nullptr;
    };

    TEST_F(RandomCLinkedLine3DFixture, CLinkedLine3D_getLinePointX_knownCoordinate_X_Test) {
        double known_coordinate = p_second_line_point->getX();
        auto known_coordinate_name = Geometry3D::CLinkedLine3D::CoordinateName::X;
        double expected_x = p_second_line_point->getX();
        EXPECT_DOUBLE_EQ(expected_x, p_line_fixture->getLinePointX(known_coordinate, known_coordinate_name));
    }

    TEST_F(RandomCLinkedLine3DFixture, CLinkedLine3D_getLinePointX_knownCoordinate_Y_Test) {
        double known_coordinate = p_second_line_point->getY();
        auto known_coordinate_name = Geometry3D::CLinkedLine3D::CoordinateName::Y;
        double expected_x = p_second_line_point->getX();
        EXPECT_DOUBLE_EQ(expected_x, p_line_fixture->getLinePointX(known_coordinate, known_coordinate_name));
    }

    TEST_F(RandomCLinkedLine3DFixture, CLinkedLine3D_getLinePointX_knownCoordinate_Z_Test) {
        double known_coordinate = p_second_line_point->getZ();
        auto known_coordinate_name = Geometry3D::CLinkedLine3D::CoordinateName::Z;
        double expected_x = p_second_line_point->getX();
        EXPECT_DOUBLE_EQ(expected_x, p_line_fixture->getLinePointX(known_coordinate, known_coordinate_name));
    }

    TEST_F(RandomCLinkedLine3DFixture, CLinkedLine3D_getLinePointY_knownCoordinate_X_Test) {
        double known_coordinate = p_second_line_point->getX();
        auto known_coordinate_name = Geometry3D::CLinkedLine3D::CoordinateName::X;
        double expected_x = p_second_line_point->getY();
        EXPECT_DOUBLE_EQ(expected_x, p_line_fixture->getLinePointY(known_coordinate, known_coordinate_name));
    }

    TEST_F(RandomCLinkedLine3DFixture, CLinkedLine3D_getLinePointY_knownCoordinate_Y_Test) {
        double known_coordinate = p_second_line_point->getY();
        auto known_coordinate_name = Geometry3D::CLinkedLine3D::CoordinateName::Y;
        double expected_x = p_second_line_point->getY();
        EXPECT_DOUBLE_EQ(expected_x, p_line_fixture->getLinePointY(known_coordinate, known_coordinate_name));
    }

    TEST_F(RandomCLinkedLine3DFixture, CLinkedLine3D_getLinePointY_knownCoordinate_Z_Test) {
        double known_coordinate = p_second_line_point->getZ();
        auto known_coordinate_name = Geometry3D::CLinkedLine3D::CoordinateName::Z;
        double expected_x = p_second_line_point->getY();
        EXPECT_DOUBLE_EQ(expected_x, p_line_fixture->getLinePointY(known_coordinate, known_coordinate_name));
    }

    TEST_F(RandomCLinkedLine3DFixture, CLinkedLine3D_getLinePointZ_knownCoordinate_X_Test) {
        double known_coordinate = p_second_line_point->getX();
        auto known_coordinate_name = Geometry3D::CLinkedLine3D::CoordinateName::X;
        double expected_x = p_second_line_point->getZ();
        EXPECT_DOUBLE_EQ(expected_x, p_line_fixture->getLinePointZ(known_coordinate, known_coordinate_name));
    }

    TEST_F(RandomCLinkedLine3DFixture, CLinkedLine3D_getLinePointZ_knownCoordinate_Y_Test) {
        double known_coordinate = p_second_line_point->getY();
        auto known_coordinate_name = Geometry3D::CLinkedLine3D::CoordinateName::Y;
        double expected_x = p_second_line_point->getZ();
        EXPECT_DOUBLE_EQ(expected_x, p_line_fixture->getLinePointZ(known_coordinate, known_coordinate_name));
    }

    TEST_F(RandomCLinkedLine3DFixture, CLinkedLine3D_getLinePointZ_knownCoordinate_Z_Test) {
        double known_coordinate = p_second_line_point->getZ();
        auto known_coordinate_name = Geometry3D::CLinkedLine3D::CoordinateName::Z;
        double expected_x = p_second_line_point->getZ();
        EXPECT_DOUBLE_EQ(expected_x, p_line_fixture->getLinePointZ(known_coordinate, known_coordinate_name));
    }



}
