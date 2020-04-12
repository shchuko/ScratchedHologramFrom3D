#include <gtest/gtest.h>
#include <cmath>
#include <CLinkedEdge.hpp>
#include <CPoint3D.hpp>

/**
 * @author Vladislav Yaroshchuk, github.com/shchuko
 */
namespace CLinkedEdgeUnitTestsNS {
    using namespace Geometry3D;
    using namespace File3DProcessingTools;

    TEST(CLinkedEdge, CLinkedEdge_base_constructor_getLinkedVector_getLinkedLine_Test) {
        CPoint3D point_begin{1.0, 2.0, 3.0};
        CPoint3D point_end{4.0, 5.0, 6.0};

        CLinkedEdge edge{point_begin, point_end};
        EXPECT_EQ(&point_begin, &edge.getLineLinkedVector().getPointBegin()) << "point_begin is not linked to edge";
        EXPECT_EQ(&point_end, &edge.getLineLinkedVector().getPointEnd()) << "point_end is not linked to edge";

        auto line = edge.getLinkedLine();

        CLinkedVector3D direction_vector(point_begin, point_end);
        CLinkedLine3D expected_line(direction_vector, point_begin);

        EXPECT_EQ(CLinkedLine3D::RelationType::OVERLAP, expected_line.getRelationType(line))
                            << "Wrong edge line direction";
    }

    TEST(CLinkedEdge, CLinkedEdge_update_Test) {
        CPoint3D point_begin{1.0, 2.0, 3.0};
        CPoint3D point_end{4.0, 5.0, 6.0};

        CLinkedEdge edge{point_begin, point_end};
        EXPECT_EQ(&point_begin, &edge.getLineLinkedVector().getPointBegin()) << "point_begin is not linked to edge";
        EXPECT_EQ(&point_end, &edge.getLineLinkedVector().getPointEnd()) << "point_end is not linked to edge";

        CPoint3D point_begin_new{2.0, 1.0, 4.0};
        CPoint3D point_end_new{6.0, 4.0, 3.0};
        edge.update(point_begin_new, point_end_new);
        EXPECT_EQ(&point_begin_new, &edge.getLineLinkedVector().getPointBegin())
                            << "point_begin is not linked to edge after update";
        EXPECT_EQ(&point_end_new, &edge.getLineLinkedVector().getPointEnd())
                            << "point_end is not linked to edge after update";

        auto line = edge.getLinkedLine();

        CLinkedVector3D direction_vector_new(point_begin_new, point_end_new);
        CLinkedLine3D expected_line(direction_vector_new, point_begin_new);

        EXPECT_EQ(CLinkedLine3D::RelationType::OVERLAP, expected_line.getRelationType(line))
                            << "Wrong edge line direction after update";
    }

    TEST(CLinkedEdge, CLinkedLine3D_isPointOnEdge_True_Test) {
        CPoint3D point_begin{1.0, 2.0, 3.0};
        CPoint3D point_end{4.0, 5.0, 6.0};

        CLinkedEdge edge{point_begin, point_end};

        double point_x = (point_begin.getX() + point_end.getX()) / 2;
        double point_y = (point_begin.getY() + point_end.getY()) / 2;
        double point_z = (point_begin.getZ() + point_end.getZ()) / 2;

        CPoint3D point_on_line{point_x, point_y, point_z};
        EXPECT_TRUE(edge.isPointOnEdge(point_on_line)) << "Point between line edges is detected 'Not on edge'";
        EXPECT_TRUE(edge.isPointOnEdge(point_begin)) << "point_begin id detected 'Not on edge'";
        EXPECT_TRUE(edge.isPointOnEdge(point_end)) << "point_end id detected 'Not on edge'";
    }

    TEST(CLinkedEdge, CLinkedEdge_isPointOnEdge_False_Test) {
        CPoint3D point_begin{1.0, 2.0, 3.0};
        CPoint3D point_end{4.0, 5.0, 6.0};

        CLinkedEdge edge{point_begin, point_end};

        CLinkedVector3D inverted_move_vector(point_end, point_begin);
        auto point_on_edge_line_before_edge_begin = point_begin.moveCopy(inverted_move_vector);
        EXPECT_FALSE(edge.isPointOnEdge(point_on_edge_line_before_edge_begin))
                            << "Point on edge line before edge begin detected 'On edge'";

        CLinkedVector3D move_vector(point_begin, point_end);
        auto point_on_edge_line_after_edge_end = point_end.moveCopy(move_vector);
        EXPECT_FALSE(edge.isPointOnEdge(point_on_edge_line_after_edge_end))
                            << "Point on edge line after edge end detected 'On edge'";


        CPoint3D point_not_on_edge_line{1.5, 2.1, 2.3};
        EXPECT_FALSE(edge.isPointOnEdge(point_not_on_edge_line)) << "Point not on edge line detected as 'On edge'";
    }

    TEST(CLinkedEdge, CLinkedEdge_getLineCrossingPoint_LINES_CROSSING_NOT_BETWEEN_EDGE_ENDINGS_Test) {
        CPoint3D point_begin{3.0, -3.0, 2.0};
        CPoint3D point_end{2.0, -2.0, 4.0};
        CLinkedEdge edge(point_begin, point_end);

        CPoint3D line_point(-1.0, 4.0, -26.0);
        CVector3D line_vector(3.0, -4.0, 6.0);
        CLinkedLine3D line(line_vector, line_point);

        CPoint3D crossing_point = edge.getLineCrossingPoint(line);
        EXPECT_TRUE(std::isnan(crossing_point.getX())) << "X is not NaN: " << crossing_point.getX();
        EXPECT_TRUE(std::isnan(crossing_point.getY())) << "Y is not NaN: " << crossing_point.getY();
        EXPECT_TRUE(std::isnan(crossing_point.getZ())) << "Z is not NaN: " << crossing_point.getZ();
    }

    TEST(CLinkedEdge, CLinkedEdge_getLineCrossingPoint_LINE_CROSSING_EDGE_Test) {
        CPoint3D point_begin{13.0, -13.0, -18.0};
        CPoint3D point_end{2.0, -2.0, 4.0};
        CLinkedEdge edge(point_begin, point_end);

        CPoint3D line_point(-1.0, 4.0, -26.0);
        CVector3D line_vector(3.0, -4.0, 6.0);
        CLinkedLine3D line(line_vector, line_point);

        CPoint3D crossing_point = edge.getLineCrossingPoint(line);
        EXPECT_DOUBLE_EQ(8.0, crossing_point.getX()) << "Wrong X value";
        EXPECT_DOUBLE_EQ(-8.0, crossing_point.getY()) << "Wrong Y value";
        EXPECT_DOUBLE_EQ(-8.0, crossing_point.getZ()) << "Wrong Z value";
    }

    TEST(CLinkedEdge, CLinkedEdge_getLineCrossingPoint_LINE_EDGE_PARALLEL_Test) {
        CPoint3D point_begin{-4.0, -5.0, 6.0};
        CPoint3D point_end{-6.0, -1.0, 12.0};
        CLinkedEdge edge(point_begin, point_end);

        CPoint3D line_point(0.0, 1.0, -3.0);
        CVector3D line_vector(1.0, -2.0, -3.0);
        CLinkedLine3D line(line_vector, line_point);

        CPoint3D crossing_point = edge.getLineCrossingPoint(line);
        EXPECT_TRUE(std::isnan(crossing_point.getX())) << "X is not NaN: " << crossing_point.getX();
        EXPECT_TRUE(std::isnan(crossing_point.getY())) << "Y is not NaN: " << crossing_point.getY();
        EXPECT_TRUE(std::isnan(crossing_point.getZ())) << "Z is not NaN: " << crossing_point.getZ();
    }

    TEST(CLinkedEdge, CLinkedEdge_getLineCrossingPoint_LINE_EDGE_SKEW_Test) {
        CPoint3D point_begin{2.0, -1.0, 0.0};
        CPoint3D point_end{4.0, -4.0, -1.0};
        CLinkedEdge edge(point_begin, point_end);

        CPoint3D line_point(-1.0, 0.0, 1.0);
        CVector3D line_vector(1.0, -2.0, 0.0);
        CLinkedLine3D line(line_vector, line_point);

        CPoint3D crossing_point = edge.getLineCrossingPoint(line);
        EXPECT_TRUE(std::isnan(crossing_point.getX())) << "X is not NaN: " << crossing_point.getX();
        EXPECT_TRUE(std::isnan(crossing_point.getY())) << "Y is not NaN: " << crossing_point.getY();
        EXPECT_TRUE(std::isnan(crossing_point.getZ())) << "Z is not NaN: " << crossing_point.getZ();
    }

    TEST(CLinkedEdge, CLinkedEdge_getLineCrossingPoint_LINE_EDGE_OVERLAP_Test) {
        CPoint3D point_begin{-4.0, -5.0, 6.0};
        CPoint3D point_end{-6.0, -1.0, 12.0};
        CLinkedEdge edge(point_begin, point_end);

        CPoint3D line_point(4.0, -21.0, -18.0);
        CVector3D line_vector(-2.0, 4.0, 6.0);
        CLinkedLine3D line(line_vector, line_point);

        CPoint3D crossing_point = edge.getLineCrossingPoint(line);
        EXPECT_TRUE(std::isinf(crossing_point.getX())) << "X is not NaN: " << crossing_point.getX();
        EXPECT_TRUE(std::isinf(crossing_point.getY())) << "Y is not NaN: " << crossing_point.getY();
        EXPECT_TRUE(std::isinf(crossing_point.getZ())) << "Z is not NaN: " << crossing_point.getZ();
    }

}