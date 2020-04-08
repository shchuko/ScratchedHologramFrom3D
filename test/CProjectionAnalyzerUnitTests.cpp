#include <gtest/gtest.h>

#include <CProjectionAnalyzer.hpp>
#include <CObject3DData.hpp>

#include <tuple>
#include <cmath>
#include <CVector3D.hpp>
#include <CPoint3D.hpp>
#include <CPolygon.hpp>

namespace CProjectionAnalyzerUnitTestsNS {
    using namespace ScratchProjectionMaths;
    using namespace File3DProcessingTools;

    class CObject3DDataCubeFixture : public ::testing::Test {
    protected:
        static constexpr double PI_VAL = 3.14159265358979323846264338327950288419716939937510582097494459230781640628620899;

        void SetUp() override {
            p_object_3d = new CObject3DData();

            p_object_3d->addVertex({-1.000000, -1.000000, 1.000000});
            p_object_3d->addVertex({-1.000000, 1.000000, 1.000000});
            p_object_3d->addVertex({-1.000000, -1.000000, -1.000000});
            p_object_3d->addVertex({-1.000000, 1.000000, -1.000000});
            p_object_3d->addVertex({1.000000, -1.000000, 1.000000});
            p_object_3d->addVertex({1.000000, 1.000000, 1.000000});
            p_object_3d->addVertex({1.000000, -1.000000, -1.000000});
            p_object_3d->addVertex({1.000000, 1.000000, -1.000000});

            p_object_3d->addPolygonNormal({-1.0000, 0.0000, 0.0000});
            p_object_3d->addPolygonNormal({0.0000, 0.0000, -1.0000});
            p_object_3d->addPolygonNormal({1.0000, 0.0000, 0.0000});
            p_object_3d->addPolygonNormal({0.0000, 0.0000, 1.0000});
            p_object_3d->addPolygonNormal({0.0000, -1.0000, 0.0000});
            p_object_3d->addPolygonNormal({0.0000, 1.0000, 0.0000});

            CPolygon p1(0);
            p1.addEdge(0, 1);
            p1.addEdge(1, 3);
            p1.addEdge(3, 2);
            p1.addEdge(2, 0);
            p1.makeReadonly();
            p_object_3d->addPolygon(p1);

            CPolygon p2(1);
            p2.addEdge(2, 3);
            p2.addEdge(3, 7);
            p2.addEdge(7, 6);
            p2.addEdge(6, 2);
            p2.makeReadonly();
            p_object_3d->addPolygon(p2);

            CPolygon p3(2);
            p3.addEdge(6, 7);
            p3.addEdge(7, 5);
            p3.addEdge(5, 4);
            p3.addEdge(4, 6);
            p3.makeReadonly();
            p_object_3d->addPolygon(p3);

            CPolygon p4(3);
            p4.addEdge(4, 5);
            p4.addEdge(5, 1);
            p4.addEdge(1, 0);
            p4.addEdge(0, 4);
            p4.makeReadonly();
            p_object_3d->addPolygon(p4);

            CPolygon p5(4);
            p5.addEdge(2, 6);
            p5.addEdge(6, 4);
            p5.addEdge(4, 0);
            p5.addEdge(0, 2);
            p5.makeReadonly();
            p_object_3d->addPolygon(p5);

            CPolygon p6(5);
            p6.addEdge(7, 3);
            p6.addEdge(3, 1);
            p6.addEdge(1, 5);
            p6.addEdge(5, 7);
            p6.makeReadonly();
            p_object_3d->addPolygon(p6);


            auto transform_f = [](double x, double y, double z) -> std::tuple<double, double, double> {
                double rotate_angle = PI_VAL / 6;

                double x_new = x * std::cos(rotate_angle) + y * sin(rotate_angle) + 0.3;
                double y_new = -x * std::sin(rotate_angle) + y * cos(rotate_angle) - 0.4;
                double z_new = z + 0.35;
                return std::make_tuple(x_new, y_new, z_new);
            };

            p_object_3d->forEachVertex([&](Geometry3D::CPoint3D &p) {
                auto tpl = transform_f(p.getX(), p.getY(), p.getZ());
                p.setX(std::get<0>(tpl));
                p.setY(std::get<1>(tpl));
                p.setZ(std::get<2>(tpl));
            });

            p_object_3d->forEachNormalVector([&](Geometry3D::CVector3D &v) {
                auto tpl = transform_f(v.getX(), v.getY(), v.getZ());
                v.setX(std::get<0>(tpl));
                v.setY(std::get<1>(tpl));
                v.setZ(std::get<2>(tpl));

            });
        }

        void TearDown() override {
            delete p_object_3d;
        }

        CObject3DData *p_object_3d = nullptr;
    };

    TEST_F(CObject3DDataCubeFixture, CProjectionAnalyzer_1m_pi_5_10cm_get_width_Test) {
        // Let it be 1 [unit] == 1 [cm]
        double obj_view_distance = 100.0;
        double view_angle = PI_VAL / 5;
        double obj_disk_distance = 10.0;

        CProjectionAnalyzer analyzer(*p_object_3d, obj_view_distance, view_angle, obj_disk_distance);

        double expected_width = 8.978278835123632;
        EXPECT_DOUBLE_EQ(expected_width, analyzer.getProjectionWidth());
    }

    TEST_F(CObject3DDataCubeFixture, CProjectionAnalyzer_1m_pi_5_10cm_get_recom_spacing_Test) {
        // Let it be 1 [unit] == 1 [cm]
        double obj_view_distance = 100.0;
        double view_angle = PI_VAL / 5;
        double obj_disk_distance = 10.0;

        CProjectionAnalyzer analyzer(*p_object_3d, obj_view_distance, view_angle, obj_disk_distance);

        double expected_width = 8.978278835123632;
        double expected_recommended_spacing = expected_width / 2;
        EXPECT_DOUBLE_EQ(expected_recommended_spacing, analyzer.getRecommendedSpacingWidth());
    }

    TEST_F(CObject3DDataCubeFixture, CProjectionAnalyzer_1m_pi_5_10cm_get_recom_move_vec_Test) {
        // Let it be 1 [unit] == 1 [cm]
        double obj_view_distance = 100.0;
        double view_angle = PI_VAL / 5;
        double obj_disk_distance = 10.0;

        CProjectionAnalyzer analyzer(*p_object_3d, obj_view_distance, view_angle, obj_disk_distance);

        double expected_width = 8.978278835123632;
        double expected_recommended_spacing = expected_width / 2;

        Geometry3D::CVector3D pure_move_vec{18.896857656088315, 0.0, obj_disk_distance};

        Geometry3D::CVector3D expected_recommended_move_vector = pure_move_vec;
        expected_recommended_move_vector.setX(expected_recommended_move_vector.getX() + expected_recommended_spacing);

        EXPECT_EQ(expected_recommended_move_vector, analyzer.getCalculationMoveVector());
    }

    TEST_F(CObject3DDataCubeFixture, CProjectionAnalyzer_1m_pi_5_10cm_get_manual_move_vec_Test) {
        // Let it be 1 [unit] == 1 [cm]
        double obj_view_distance = 100.0;
        double view_angle = PI_VAL / 5;
        double obj_disk_distance = 10.0;

        CProjectionAnalyzer analyzer(*p_object_3d, obj_view_distance, view_angle, obj_disk_distance);

        Geometry3D::CVector3D pure_move_vec{18.896857656088315, 0.0, obj_disk_distance};
        Geometry3D::CVector3D expected_manual_move_vec = pure_move_vec;
        double manual_spacing_width = 13.1342425;
        expected_manual_move_vec.setX(expected_manual_move_vec.getX() + manual_spacing_width);

        EXPECT_EQ(expected_manual_move_vec, analyzer.getCalculationMoveVector(manual_spacing_width));
    }

    TEST_F(CObject3DDataCubeFixture, CProjectionAnalyzer_0m_pi_5_10cm_Test) {
        // Let it be 1 [unit] == 1 [cm]
        double obj_view_distance = 0.0;
        double view_angle = PI_VAL / 5;
        double obj_disk_distance = 10.0;

        EXPECT_THROW(CProjectionAnalyzer(*p_object_3d, obj_view_distance, view_angle, obj_disk_distance),
                     Exceptions::EWrongObjectsPosition);
    }

    TEST_F(CObject3DDataCubeFixture, CProjectionAnalyzer_1m_pi_10cm_Test) {
        // Let it be 1 [unit] == 1 [cm]
        double obj_view_distance = 100.0;
        double view_angle = PI_VAL;
        double obj_disk_distance = 10.0;

        EXPECT_THROW(CProjectionAnalyzer(*p_object_3d, obj_view_distance, view_angle, obj_disk_distance),
                     Exceptions::EWrongObjectsPosition);
    }

    TEST_F(CObject3DDataCubeFixture, CProjectionAnalyzer_1m_pi_5_0cm_Test) {
        // Let it be 1 [unit] == 1 [cm]
        double obj_view_distance = 100.0;
        double view_angle = PI_VAL / 5;
        double obj_disk_distance = 0;

        EXPECT_THROW(CProjectionAnalyzer(*p_object_3d, obj_view_distance, view_angle, obj_disk_distance),
                     Exceptions::EWrongObjectsPosition);
    }
}