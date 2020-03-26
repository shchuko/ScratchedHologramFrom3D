#include "CLinkedEdge.hpp"

/**
 * @author Vladislav Yaroshchuk, github.com/shchuko
 */
namespace File3DProcessingTools {
    const Geometry3D::CLinkedLine3D &CLinkedEdge::getLinkedLine() const noexcept {
        return linked_line;
    }

    bool CLinkedEdge::isPointOnEdge(const Geometry3D::CPoint3D &point) const noexcept {
        return isPointBetweenEdgeEndings(point) && linked_line.isPointOnLine(point);
    }

    bool CLinkedEdge::isEqualDouble(double x, double y) noexcept {
        return std::fabs(x - y) < std::numeric_limits<double>::epsilon();
    }

    bool CLinkedEdge::isPointOnEdge(Geometry3D::CPoint3D &&point) const noexcept {
        return isPointOnEdge(point);
    }

    Geometry3D::CPoint3D CLinkedEdge::getLineCrossingPoint(const Geometry3D::CLinkedLine3D &line) const noexcept {
        auto crossing_point = linked_line.getCrossingPoint(line);
        double NaN_val = std::numeric_limits<double>::quiet_NaN();
        double INF_val = std::numeric_limits<double>::infinity();

        if (!(std::isnormal(crossing_point.getX())
              && std::isnormal(crossing_point.getY())
              && std::isnormal(crossing_point.getZ()))) {
            if (std::isinf(crossing_point.getX())
                || std::isinf(crossing_point.getY())
                || std::isinf(crossing_point.getZ())) {
                return {INF_val, INF_val, INF_val};
            }
            return {NaN_val, NaN_val, NaN_val};
        }


        if (isPointBetweenEdgeEndings(crossing_point)) {
            return crossing_point;
        }
        return {NaN_val, NaN_val, NaN_val};
    }

    const Geometry3D::CLinkedVector3D &CLinkedEdge::getLineLinkedVector() const noexcept {
        return linked_vector;
    }

    bool CLinkedEdge::isPointBetweenEdgeEndings(const Geometry3D::CPoint3D &point) const noexcept {
        double x_vec_first = linked_vector.getPointBegin().getX() - point.getX();
        double y_vec_first = linked_vector.getPointBegin().getY() - point.getY();
        double z_vec_first = linked_vector.getPointBegin().getZ() - point.getZ();

        double x_vec_second = linked_vector.getPointEnd().getX() - point.getX();
        double y_vec_second = linked_vector.getPointEnd().getY() - point.getY();
        double z_vec_second = linked_vector.getPointEnd().getZ() - point.getZ();

        double mul_x = x_vec_first * x_vec_second;
        double mul_y = y_vec_first * y_vec_second;
        double mul_z = z_vec_first * z_vec_second;

        return mul_x <= 0 && mul_y <= 0 && mul_z <= 0;
    }
}