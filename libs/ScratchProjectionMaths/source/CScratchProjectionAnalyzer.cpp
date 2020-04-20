#include "CScratchProjectionAnalyzer.hpp"

ScratchProjectionMaths::CScratchProjectionAnalyzer::CScratchProjectionAnalyzer(const File3DProcessingTools::CObject3DData &object,
                                                                               double object_viewer_distance,
                                                                               double object_viewer_angle_rad,
                                                                               double object_disk_distance,
                                                                               bool deep) {

    if (object_viewer_distance <= 0.0) {
        throw Exceptions::EWrongObjectsPosition("Zero distance between the object and the viewer");
    }

    if (object_disk_distance <= 0.0) {
        throw Exceptions::EWrongObjectsPosition("Zero distance between the object and the dist");
    }

    if (object_viewer_angle_rad >= CScratchProjectionAnalyzer::PI_2 || object_viewer_angle_rad <= 0.0) {
        throw Exceptions::EWrongObjectsPosition("Angle between object and viewer should be in (0, pi/2)");
    }

    // All calculations are performed in 0xz plane
    using namespace Geometry3D;

    // Fixing object and viewer points in special places for the easiest calculations case
    CPoint3D object_center{0.0, 0.0, object_disk_distance};
    CPoint3D viewer{object_viewer_distance * std::cos(object_viewer_angle_rad),
                    0.0,
                    object_viewer_distance * std::sin(object_viewer_angle_rad) + object_disk_distance};

    // Inscribing the object with an imaginary cylinder, finding its radius
    File3DProcessingTools::CPoints3DStatistics vertexes_statistics(std::begin(object.getVertexes()),
                                                                   std::end(object.getVertexes()));
    double x_abs_max = std::max(std::abs(vertexes_statistics.getMaxX()),
                                std::abs(vertexes_statistics.getMinX()));
    double y_abs_max = std::max(std::abs(vertexes_statistics.getMaxY()),
                                std::abs(vertexes_statistics.getMinY()));
    double circumscribed_cylinder_radius = std::sqrt(x_abs_max * x_abs_max + y_abs_max * y_abs_max);

    // Fixing up left and down right object points
    CPoint3D object_up_left{-circumscribed_cylinder_radius,
                            0.0,
                            object_disk_distance + vertexes_statistics.getMaxZ()};

    CPoint3D object_down_right{circumscribed_cylinder_radius,
                               0.0,
                               object_disk_distance + vertexes_statistics.getMinZ()};

    // Ray-tracing lines from viewer to object critical [border] points
    CLinkedVector3D vec_left_proj_border(viewer, object_up_left);
    CLinkedLine3D left_proj_border_ray(vec_left_proj_border, viewer);

    CLinkedVector3D vec_right_proj_ray(viewer, object_down_right);
    CLinkedLine3D right_proj_border_ray(vec_right_proj_ray, viewer);

    // Finding projection borders 0xy crossing points
    CPoint3D left_proj_border_point{
            left_proj_border_ray.getLinePointX(0.0, CLinkedLine3D::CoordinateName::Z),
            0.0, 0.0};
    CPoint3D right_proj_border_point{
            right_proj_border_ray.getLinePointX(0.0, CLinkedLine3D::CoordinateName::Z),
            0.0, 0.0};

    // Distance between points is projection width
    projection_width = std::abs(right_proj_border_point.getX() - left_proj_border_point.getX());

    // And for further projection calculations finding move vector coordinates
    pure_calculation_move_vector.setX(- left_proj_border_point.getX());
    pure_calculation_move_vector.setY(0.0);
    pure_calculation_move_vector.setZ(object_center.getZ());

    viewer_point = viewer.moveCopy(CVector3D(-left_proj_border_point.getX(), 0.0, 0.0));
}

double ScratchProjectionMaths::CScratchProjectionAnalyzer::getProjectionWidth() const noexcept {
    return projection_width;
}

double ScratchProjectionMaths::CScratchProjectionAnalyzer::getRecommendedSpacingWidth() const noexcept {
    return projection_width / 2.0;
}

Geometry3D::CVector3D
ScratchProjectionMaths::CScratchProjectionAnalyzer::getCalculationMoveVector(double spacing_width) const noexcept {
    return pure_calculation_move_vector + Geometry3D::CVector3D{spacing_width, 0.0, 0.0};
}

Geometry3D::CVector3D ScratchProjectionMaths::CScratchProjectionAnalyzer::getCalculationMoveVector() const noexcept {
    return getCalculationMoveVector(0.0);
}

Geometry3D::CPoint3D
ScratchProjectionMaths::CScratchProjectionAnalyzer::getViewerPoint(double spacing_width) const noexcept {
    return viewer_point.moveCopy(Geometry3D::CVector3D{spacing_width, 0.0, 0.0});
}

Geometry3D::CPoint3D ScratchProjectionMaths::CScratchProjectionAnalyzer::getViewerPoint() const noexcept {
    return getViewerPoint(0.0);
}


