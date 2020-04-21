/**
 * @author Vladislav Yaroshchuk, github.com/shchuko
 */

#pragma once

#include <TFile3DProcessingToolsTypes.hpp>
#include <CObject3DData.hpp>
#include <CVectorGraphicsData.hpp>
#include <Geometry3DOperators.hpp>
#include <CPoint3D.hpp>
#include <CVector3D.hpp>
#include <CLinkedVector3D.hpp>
#include <AVector3D.hpp>
#include <CPoint2D.hpp>
#include <CVector2D.hpp>
#include <exception>
#include <utility>
#include <cmath>


namespace ScratchProjectionMaths {
    class CScratchProjectionBuilder {
    private:
        constexpr static double PI_VAL =
                3.14159265358979323846264338327950288419716939937510582097494459230781640628620899;

        File3DProcessingTools::CObject3DData &object;
        Geometry3D::CPoint3D viewer;
        Geometry3D::CVector3D object_viewer_vec;

        double step_width;
        bool convex_flag;

        // Temporary build-process objects:
        Geometry3D::CVector3D move_vec{0.0, 0.0, 0.0};
        Geometry3D::CVector3D move_vec_inv{0.0, 0.0, 0.0};

        double current_angle = 0.0;
        double next_angle = 0.0;

        // Scratch len divided by 2
        double scratch_len_2 = 0.0;

        Geometry3D::CLinkedVector3D view_vec;
        Geometry3D::CLinkedLine3D view_line;

        std::vector<bool> polygons_visible_flags;

        unsigned int line_width = 1;
    public:
        /**
         * Setup CScratchProjectionBuilder
         * @param _object Object to build projection of. Will be modified!
         * @param _viewer Viewer point (can be got from CScratchProjectionAnalyzer)
         * @param _step_width Width between two scratches of one projection. Should be > 0
         * @param _object_convex_flag True of object is convex, false if not or if not only one object
         * @throw std::logic_exception is _step_width <= 0
         */
        CScratchProjectionBuilder(File3DProcessingTools::CObject3DData &_object,
                                  Geometry3D::CPoint3D _viewer,
                                  double _step_width,
                                  bool _object_convex_flag = false);

        /**
         * Assign new value fot step width
         * @param _step_width Step width value
         */
        void setStepWidth(double _step_width);

        /**
         * Build projection
         * @param out_data Vector Graphics 2D data object to write results in
         * @param _move_vec Object move vector (can be got from CScratchProjectionAnalyzer)
         * @param angle_begin Angle begin projection building from [0, 2pi)
         * @param angle_end Angle end projection building on [0, 2pi)
         * @param angle_step Angle step [0, 2pi)
         * @param _scratch_len Length of scratch > 0
         * @return CVectorGraphicsData object with projection scratches
         * @throw std::logic_error if parameters are not in permitted range
         */
        void build(File2DProcessingTools::CVectorGraphicsData &out_data,
                   const Geometry3D::AVector3D &_move_vec, double angle_begin, double angle_end, double angle_step,
                   double _scratch_len);

        /**
         * Set scratch line width
         * @param width Line width in pixels
         */
        void setScratchLineWidthPixels(unsigned int width);

    private:
        static inline void rotateOz(double &x, double &y, double rotate_angle) noexcept;

        void updateObjectViewerVec() noexcept;

        void updatePolygonsVisibleFlags() noexcept;

        void doFirstMove() noexcept;

        static void checkAngles(double _angle_begin, double _angle_end, double _d_angle);

        void doRotateStep() noexcept;

        void buildObjectProjection(File2DProcessingTools::CVectorGraphicsData &out_data) noexcept;

        void doPolygonEdgesProjection(const File3DProcessingTools::CPolygon &polygon,
                                      File2DProcessingTools::CVectorGraphicsData &out_data) noexcept;

        Geometry2D::CVector2D getScratchHalfDirectionVector() noexcept;

        bool isPointVisible(const Geometry3D::CPoint3D &point_on_edge,
                            const File3DProcessingTools::CPolygon &polygon_point_from,
                            const File3DProcessingTools::CLinkedEdge &edge_point_from) noexcept;

        Geometry3D::CPoint3D getPolygonPlaneViewLineCrossingPoint(const File3DProcessingTools::CPolygon &p) noexcept;

        void addProjectionCenterScratches(File2DProcessingTools::CVectorGraphicsData &out_data) const noexcept;
    };
}
