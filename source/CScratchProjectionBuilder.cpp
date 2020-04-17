/**
 * @author Vladislav Yaroshchuk, github.com/shchuko
 */

#include "CScratchProjectionBuilder.hpp"

ScratchProjectionMaths::CScratchProjectionBuilder::CScratchProjectionBuilder(
        const File3DProcessingTools::CObject3DData &_object, Geometry3D::CPoint3D _viewer, double _step_width,
        bool _object_convex_flag)
        : object{_object}, viewer{_viewer},
          convex_flag{_object_convex_flag}, view_vec{viewer, viewer}, view_line{view_vec, viewer} {
    if (_step_width <= 0.0) {
        throw std::logic_error("Edge step should be above zero");
    }

    step_width = _step_width;
    polygons_visible_flags.resize(object.getPolygons().size());
}

void ScratchProjectionMaths::CScratchProjectionBuilder::setStepWidth(double _step_width) {
    if (_step_width <= 0.0) {
        throw std::logic_error("Edge step should be above zero");
    }

    step_width = _step_width;
}

File2DProcessingTools::CVectorGraphicsData
ScratchProjectionMaths::CScratchProjectionBuilder::build(const Geometry3D::AVector3D &_move_vec, double angle_begin,
                                                         double angle_end, double angle_step, double _scratch_len) {
    // Throws exceptions
    checkAngles(angle_begin, angle_end, angle_step);

    if (_scratch_len <= 0) {
        throw std::logic_error("_scratch_len should be above zero 0.0");
    }

    move_vec = _move_vec;
    move_vec_inv = -move_vec;
    scratch_len_2 = _scratch_len / 2.0;

    updateObjectViewerVec();

    File2DProcessingTools::CVectorGraphicsData out_data;

    current_angle = 0.0;
    next_angle = angle_begin;
    doFirstMove();
    doRotateStep();
    updatePolygonsVisibleFlags();

    while (current_angle < angle_end) {
        updatePolygonsVisibleFlags();

        buildObjectProjection(out_data);

        next_angle += angle_step;
        object.setAllEdgesMarked(false);
        object.forEachVertex([](Geometry3D::CPoint3D &p) { p.setMarked(false); });
        doRotateStep();
    }

    move_vec = move_vec_inv = {0.0, 0.0, 0.0};
    scratch_len_2 = 0.0;
    view_vec.setPointEnd(viewer);

    addProjectionCenterScratches(out_data);

    return out_data;
}

void ScratchProjectionMaths::CScratchProjectionBuilder::rotateOz(double &x, double &y, double rotate_angle) noexcept {
    double x_prev = x;
    x = x_prev * std::cos(rotate_angle) + y * sin(rotate_angle);
    y = -x_prev * std::sin(rotate_angle) + y * cos(rotate_angle);
}

void ScratchProjectionMaths::CScratchProjectionBuilder::updateObjectViewerVec() noexcept {
    object_viewer_vec.setX(-viewer.getX() + move_vec.getX());
    object_viewer_vec.setY(-viewer.getY() + move_vec.getY());
    object_viewer_vec.setZ(-viewer.getZ() + move_vec.getZ());
}

void ScratchProjectionMaths::CScratchProjectionBuilder::updatePolygonsVisibleFlags() noexcept {
    // If polygon is visible
    // Angle between viewer-object vector and polygon normal vector should be in (pi/2, pi]
    // Which cos is in [-1, 0)

    const auto &polygons = object.getPolygons();
    const auto &polygons_normals = object.getPolygonNormals();

    for (std::vector<bool>::size_type i = 0; i < polygons_visible_flags.size(); ++i) {
        const auto &normal_vector = polygons_normals[polygons[i].getNormalVectorIndex()];
        const double angle_cos = normal_vector.getAngleCos(object_viewer_vec);
        if (Geometry3D::isEqualDouble(angle_cos, 0.0, 0.01)) {
            polygons_visible_flags[i] = false;
        } else {
            polygons_visible_flags[i] = normal_vector.getAngleCos(object_viewer_vec) < 0.0;
        }
    }
}

void ScratchProjectionMaths::CScratchProjectionBuilder::doFirstMove() noexcept {
    object.forEachVertex([&](Geometry3D::CPoint3D &p) { p.move(move_vec); });
}

void
ScratchProjectionMaths::CScratchProjectionBuilder::checkAngles(double _angle_begin, double _angle_end, double _d_angle) {
    if (_angle_begin >= PI_VAL * 2 || _angle_begin < 0.0) {
        throw std::logic_error("angle_begin should be in [0, 2Pi)");
    }

    if (_angle_end >= PI_VAL * 2 || _angle_end < 0.0) {
        throw std::logic_error("angle_end should be in [0, 2Pi)");
    }

    if (_d_angle >= PI_VAL * 2 || _d_angle < 0.0) {
        throw std::logic_error("d_angle should be in [0, 2Pi)");
    }

    if (_angle_end < _angle_begin) {
        throw std::logic_error("angle_begin should be lower than angle_end");
    }
}

void ScratchProjectionMaths::CScratchProjectionBuilder::doRotateStep() noexcept {
    object.forEachVertex([&](Geometry3D::CPoint3D &p) {
        p.move(move_vec_inv);
        double x = p.getX();
        double y = p.getY();

        rotateOz(x, y, next_angle - current_angle);

        p.setX(x);
        p.setY(y);

        p.move(move_vec);
    });

    object.forEachNormalVector([&](Geometry3D::CVector3D &v) {
        double x = v.getX();
        double y = v.getY();

        rotateOz(x, y, next_angle - current_angle);

        v.setX(x);
        v.setY(y);
    });

    current_angle = next_angle;
}

void ScratchProjectionMaths::CScratchProjectionBuilder::buildObjectProjection(
        File2DProcessingTools::CVectorGraphicsData &out_data) noexcept {
    const auto &polygons = object.getPolygons();
    for (std::vector<bool>::size_type i = 0; i < polygons_visible_flags.size(); ++i) {
        if (!polygons_visible_flags[i]) {
            continue;
        }
        doPolygonEdgesProjection(polygons[i], out_data);
    }
}

void ScratchProjectionMaths::CScratchProjectionBuilder::doPolygonEdgesProjection(
        const File3DProcessingTools::CPolygon &polygon, File2DProcessingTools::CVectorGraphicsData &out_data) noexcept {
    for (const auto &edge_key : polygon.getEdges()) {
        const auto &edge = object.getEdge(edge_key);

        // Do not process edge twice
        if (edge.isMarked()) {
            continue;
        }

        using COORD_T = Geometry3D::CLinkedLine3D::CoordinateName;

        // Finding edge endings projections on scratch disc
        const Geometry3D::CPoint3D &edge_begin_p = edge.getLineLinkedVector().getPointBegin();
        view_vec.setPointEnd(edge_begin_p);

        bool edge_begin_projection_made = edge_begin_p.isMarked();

        double edge_proj_begin_x = view_line.getLinePointX(0.0, COORD_T::Z);
        double edge_proj_begin_y = view_line.getLinePointY(0.0, COORD_T::Z);

        // Rotating == rotating scratch disc
        rotateOz(edge_proj_begin_x, edge_proj_begin_y, -current_angle);


        const Geometry3D::CPoint3D &edge_end_p = edge.getLineLinkedVector().getPointEnd();
        view_vec.setPointEnd(edge_end_p);
        bool edge_end_projection_made = edge_end_p.isMarked();

        double edge_proj_end_x = view_line.getLinePointX(0.0, COORD_T::Z);
        double edge_proj_end_y = view_line.getLinePointY(0.0, COORD_T::Z);

        // Rotating == rotating scratch disc
        rotateOz(edge_proj_end_x, edge_proj_end_y, -current_angle);


        Geometry3D::CPoint3D edge_proj_begin{edge_proj_begin_x, edge_proj_begin_y, 0.0};
        Geometry3D::CPoint3D edge_proj_end{edge_proj_end_x, edge_proj_end_y, 0.0};

        Geometry3D::CLinkedVector3D edge_proj_vec(edge_proj_begin, edge_proj_end);
        Geometry3D::CVector3D edge_proj_step_vec{edge_proj_vec.getNormalizedX() * step_width,
                                                 edge_proj_vec.getNormalizedY() * step_width,
                                                 0.0};

//                Print edge projection - used for debug
//                out_data.addLineSegments({{edge_proj_begin_x, edge_proj_begin_y},
//                                          {edge_proj_end_x,   edge_proj_end_y}});

        if (edge_begin_projection_made) {
            edge_proj_begin.move(edge_proj_step_vec);
        } else {
            // Bad practice, but I know what I'm doing!
            const_cast<Geometry3D::CPoint3D &>(edge_begin_p).setMarked(true);
        }

        auto scratch_vec_half = getScratchHalfDirectionVector();
        // Doing steps, adding edge projection scratches onto disc
        while (edge_proj_vec.getAngleCos(edge_proj_step_vec) > 0) {
            if (convex_flag) {
                Geometry2D::CPoint2D scratch_begin_point = {
                        edge_proj_begin.getX() + scratch_vec_half.getX(),
                        edge_proj_begin.getY() + scratch_vec_half.getY()};
                Geometry2D::CPoint2D scratch_end_point = {edge_proj_begin.getX() - scratch_vec_half.getX(),
                                                          edge_proj_begin.getY() - scratch_vec_half.getY()};
                out_data.addLineSegments({scratch_begin_point, scratch_end_point});
            } else {
                double rotated_proj_x = edge_proj_begin.getX();
                double rotated_proj_y = edge_proj_begin.getY();
                rotateOz(rotated_proj_x, rotated_proj_y, current_angle);

                Geometry3D::CPoint3D temp_point{rotated_proj_x, rotated_proj_y, 0.0};

                view_vec.setPointEnd(temp_point);
                const auto edge_point = edge.getLineCrossingPoint(view_line);

                if (isPointVisible(edge_point, polygon, edge)) {
                    Geometry2D::CPoint2D scratch_begin_point = {
                            edge_proj_begin.getX() + scratch_vec_half.getX(),
                            edge_proj_begin.getY() + scratch_vec_half.getY()};
                    Geometry2D::CPoint2D scratch_end_point = {
                            edge_proj_begin.getX() - scratch_vec_half.getX(),
                            edge_proj_begin.getY() - scratch_vec_half.getY()};

                    out_data.addLineSegments({scratch_begin_point, scratch_end_point});
                }
            }

            edge_proj_begin.move(edge_proj_step_vec);

            if (edge_proj_begin == edge_proj_end) {
                if (edge_end_projection_made) {
                    break;
                } else {
                    // Bad practice, but I know what I'm doing!
                    const_cast<Geometry3D::CPoint3D &>(edge_end_p).setMarked(true);
                }
            }
        }
    }
}

Geometry2D::CVector2D ScratchProjectionMaths::CScratchProjectionBuilder::getScratchHalfDirectionVector() noexcept {
    // Finding view vector projection coordinates
    double view_vec_proj_x = view_vec.getX();
    double view_vec_proj_y = view_vec.getY();

    // Rotating it == rotating scratch disc
    rotateOz(view_vec_proj_x, view_vec_proj_y, -current_angle);

    if (view_vec_proj_x == 0.0 && view_vec_proj_y == 0.0) {
        return {0.0, 0.0};
    }

    // Finding scratch direction vector - it's perpendicular to view projection vector
    double x_scratch_vec = 0.0;
    double y_scratch_vec = 0.0;

    if (view_vec_proj_x == 0.0) {
        x_scratch_vec = scratch_len_2;
    } else if (view_vec_proj_y == 0.0) {
        y_scratch_vec = scratch_len_2;
    } else {
        x_scratch_vec = 1.0; // Random non-zero X value
        y_scratch_vec =
                -(x_scratch_vec * view_vec_proj_x) / view_vec_proj_y; // Finding related Y value

        // Normalizing scratch vector len and making its len = scratch_len / 2
        double temp_len = std::sqrt(x_scratch_vec * x_scratch_vec +
                                    y_scratch_vec * y_scratch_vec);

        x_scratch_vec = x_scratch_vec / temp_len * scratch_len_2;
        y_scratch_vec = y_scratch_vec / temp_len * scratch_len_2;

    }
    return {x_scratch_vec, y_scratch_vec};
}

bool ScratchProjectionMaths::CScratchProjectionBuilder::isPointVisible(const Geometry3D::CPoint3D &point_on_edge,
                                                                       const File3DProcessingTools::CPolygon &polygon_point_from,
                                                                       const File3DProcessingTools::CLinkedEdge &edge_point_from) noexcept {
    // Set up view line
    view_vec.setPointEnd(point_on_edge);
    for (std::vector<bool>::size_type i = 0; i < polygons_visible_flags.size(); ++i) {
        // Skipping invisible polygons
        if (!polygons_visible_flags[i]) {
            continue;
        }

        // Skipping poly-itself check
        const auto &polygon = object.getPolygons()[i];
        if (&polygon == &polygon_point_from) {
            continue;
        }

        // Finding crossing point of the polygon plane and the view line
        auto plane_crossing_point = getPolygonPlaneViewLineCrossingPoint(polygon);
        // If crossing is NOT between the viewer and the edge-point-to-check
        // Skipping checking, going to next polygon
        Geometry3D::CLinkedVector3D check_vec{plane_crossing_point, point_on_edge};
        if (!Geometry3D::isEqualDouble(check_vec.getAngleCos(view_vec), 1.0, 0.01)) {
            continue;
        }

        // If view line crossed the border (== the edge) of some polygon, edge-point-to-check is invisible
        for (const auto &e_key : polygon.getEdges()) {
            const auto &edge = object.getEdge(e_key);
            if (&edge != &edge_point_from && edge.isPointOnEdge(plane_crossing_point)) {
                return false;
            }
        }

        // Checking is edge-point-to-check is covered by polygon from the viewer point view
        // If yes, plane crossing point takes place somewhere onto polygon
        double angle_sum{0.0};
        for (const auto &edge_key : polygon.getEdges()) {
            const auto &edge = object.getEdge(edge_key);
            if (&edge == &edge_point_from) {
                angle_sum = 0.0;
                break;
            }

            const auto &edge_vec = edge.getLineLinkedVector();
            const Geometry3D::CLinkedVector3D first_vec{plane_crossing_point, edge_vec.getPointBegin()};
            const Geometry3D::CLinkedVector3D second_vec{plane_crossing_point, edge_vec.getPointEnd()};

            const double vec_angle_cos = first_vec.getAngleCos(second_vec);
            double angle;
            // Prevent NaN producing
            if (vec_angle_cos > 1.0) {
                angle = std::acos(1.0);
            } else if (vec_angle_cos < -1.0) {
                angle = std::acos(-1.0);
            } else {
                angle = std::acos(vec_angle_cos);
            }
            angle_sum += angle;
        }

        // If point lays onto the polygon, angle_sum should be pi * 2
        // If yes, the point is invisible
        if (Geometry3D::isEqualDouble(angle_sum, PI_VAL * 2, 0.01)) {
            return false;
        }

    }
    // No polygons were crossed by the view_line, the point is visible
    return true;
}

Geometry3D::CPoint3D ScratchProjectionMaths::CScratchProjectionBuilder::getPolygonPlaneViewLineCrossingPoint(
        const File3DProcessingTools::CPolygon &p) noexcept {
    const auto &polygon_normal = object.getPolygonNormals()[p.getNormalVectorIndex()];
    const auto &some_polygon_edge = object.getEdge(p.getEdges().front());
    const auto &some_polygon_vertex = some_polygon_edge.getLineLinkedVector().getPointBegin();

    // Polygon plane equation coefficients
    const double a_plane_eqt = polygon_normal.getX();
    const double b_plane_eqt = polygon_normal.getY();
    const double c_plane_eqt = polygon_normal.getZ();
    const double d_plane_eqt = -(polygon_normal.getX() * some_polygon_vertex.getX() +
                                 polygon_normal.getY() * some_polygon_vertex.getY() +
                                 polygon_normal.getZ() * some_polygon_vertex.getZ());
    // Parameter for finding polygon plane and view line crossing point
    const double t_param =
            -(a_plane_eqt * viewer.getX() + b_plane_eqt * viewer.getY() + c_plane_eqt * viewer.getZ() +
              d_plane_eqt) /
            (a_plane_eqt * view_vec.getX() + b_plane_eqt * view_vec.getY() + c_plane_eqt * view_vec.getZ());

    const double plane_point_x = viewer.getX() + t_param * view_vec.getX();
    const double plane_point_y = viewer.getY() + t_param * view_vec.getY();
    const double plane_point_z = viewer.getZ() + t_param * view_vec.getZ();

    return {plane_point_x, plane_point_y, plane_point_z};
}

void ScratchProjectionMaths::CScratchProjectionBuilder::addProjectionCenterScratches(
        File2DProcessingTools::CVectorGraphicsData &out_data) noexcept {
    out_data.addLineSegments({{-0.5, 0},
                              {0.5,  0}});
    out_data.addLineSegments({{0, -0.5},
                              {0, 0.5}});
    out_data.addLineSegments({{-0.5, -0.1},
                              {-0.5, 0.1}});
    out_data.addLineSegments({{0.5, -0.1},
                              {0.5, 0.1}});
    out_data.addLineSegments({{-0.1, -0.5},
                              {0.1,  -0.5}});
    out_data.addLineSegments({{-0.1, 0.5},
                              {0.1,  0.5}});
}
