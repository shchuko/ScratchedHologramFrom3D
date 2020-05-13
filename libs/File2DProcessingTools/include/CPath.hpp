#pragma once

#include <vector>
#include "CVectorGraphicsData.hpp"

namespace File2DProcessingTools {

    class CPath {
    private:
        unsigned int _width;
        CVectorGraphicsData::CColor_T _color;
        bool _smooth;
        bool _isCycled;
        std::vector<Geometry2D::CPoint2D> CPoints2D;

    public:
        /**
         * Default constructor. Width 1px, default color BLACK, smooth=false
         */
        CPath() noexcept;

        /**
         * Create and setup CPath object
         * @param width_px Width in px
         * @param color Color
         * @param smooth Smooth flag
         */
        CPath(unsigned int width_px, CVectorGraphicsData::CColor_T &color, bool smooth) noexcept;

        /**
         * Set new color
         * @param color New color
         */
        void setColor(CVectorGraphicsData::CColor_T &color) noexcept;

        /**
         * Get color of the CPath object
         * @return Color of the CPath object
         */
        CVectorGraphicsData::CColor_T getColor() const noexcept;

        /**
         * Set width in px
         * @param width_px Width in px
         */
        void setWidth(unsigned int width_px) noexcept;

        /**
         * Get width of the CPath object
         * @return Width of the CPath object in px
         */
        unsigned int getWidth() const noexcept;

        /**
         * Set smoothing flag
         * @param flag True to enable smoothing, false to disable
         */
        void setSmooth(bool flag) noexcept;

        /**
         * Get smoothing flag
         * @return Smoothing flag value
         */
        bool isSmooth() const noexcept;

        /**
         * Add next CPath point. To add split point, pass {NaN, NaN}
         * @param point Next CPath point
         */
        void appendPoint(const Geometry2D::CPoint2D &point) noexcept;

        /**
         * Concatenate CPath object
         * @param cPath CPath object to contatenate with
         */
        void appendPath(CPath &cPath) noexcept;

        /**
         * Get stored points
         * @return Stored points
         */
        const std::vector<Geometry2D::CPoint2D> &getPoints() const noexcept;

        /**
         * Split current path to paths (split criterion - {NaN, NaN} point)
         * @return
         */
        std::vector<CPath> toSeparatedPaths();

        /**
         * Update internal is-current-path-cycled flag (ending == beginning)
         */
        void updateCycled() noexcept;

        /**
         * Get is-current-path-cycled flag (ending == beginning)
         * @return True if current path is cycled
         */
        bool isCycled() const noexcept;

    };

}