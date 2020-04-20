#pragma once

#include "EWrongObjectsPosition.hpp"

#include <CObject3DData.hpp>
#include <CPoints3DStatistics.hpp>
#include <CPoint2D.hpp>
#include <CLinkedVector3D.hpp>
#include <CLinkedLine3D.hpp>
#include <Geometry3DOperators.hpp>
#include <cmath>


namespace ScratchProjectionMaths {

    class CScratchProjectionAnalyzer {
    private:
        constexpr static double PI_2 =
                3.14159265358979323846264338327950288419716939937510582097494459230781640628620899 / 2.0;
        double projection_width = 0.0;
        Geometry3D::CVector3D pure_calculation_move_vector{0.0, 0.0, 0.0};
        Geometry3D::CPoint3D viewer_point{0.0, 0.0, 0.0};

    public:
        /**
         * Perform analyses of scratch projection. Uses only vertex information
         * @param object 3D-object to project
         * @param object_viewer_distance Distance between the object center and the viewer
         * @param object_viewer_angle_rad Angle between object-viewer line and 0xy plane
         * @param object_disk_distance Distance between the object center and projection disk
         * @param deep Do deep analysis with rotating object and calculating pretty accurate result. [Not implemented]
         */
        explicit CScratchProjectionAnalyzer(const File3DProcessingTools::CObject3DData &object,
                                            double object_viewer_distance,
                                            double object_viewer_angle_rad,
                                            double object_disk_distance,
                                            bool deep = false);

        /**
         * Get projection width
         * @return Projection width
         */
        double getProjectionWidth() const noexcept;

        /**
         * Get recommended space between projection inner radius and projection disk center
         * @return Recommended space width
         */
        double getRecommendedSpacingWidth() const noexcept;

        /**
         * Get recommended move vector to perform projection calculations with. Used in CProjectionBuilder
         * @return Object move vector
         */
        Geometry3D::CVector3D getCalculationMoveVector() const noexcept;

        /**
         * Get move vector to perform projection calculations with with specified spacing width value. Used in CProjectionBuilder
         * @return Object move vector
         */
        Geometry3D::CVector3D getCalculationMoveVector(double spacing_width) const noexcept;

        Geometry3D::CPoint3D getViewerPoint() const noexcept;

        Geometry3D::CPoint3D getViewerPoint(double spacing_width) const noexcept;
    };
}
