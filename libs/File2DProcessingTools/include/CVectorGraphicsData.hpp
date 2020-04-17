#pragma once

#include <vector>
#include <cfloat>
#include <limits>
#include "string"
#include "CLineSegment2D.hpp"

namespace File2DProcessingTools {


    /**
     * Vector graphics storage
     * @author Nikita Novgorodtsev (github <https://github.com/paNoNi>)
     */
    class CVectorGraphicsData {

    private:
        std::vector<Geometry2D::CLineSegment2D> _data;
        double min_x = std::numeric_limits<double >::max();
        double min_y = std::numeric_limits<double >::max();
        double max_x = -std::numeric_limits<double >::max();
        double max_y = -std::numeric_limits<double >::max();
        std::vector<unsigned int> width;

        class CColor_T {
        private:
            std::string color_rgb{};
            std::string color_hex{};
        public:
            CColor_T(unsigned int red, unsigned int green, unsigned int blue);
            explicit CColor_T(std::string color_hex);

            std::string getHexStr();
            std::string getRGBStr();

        };

    public:


        CVectorGraphicsData() = default;

        CVectorGraphicsData(const CVectorGraphicsData &data) = default;

        CVectorGraphicsData(CVectorGraphicsData &&data) = default;

        CVectorGraphicsData &operator=(const CVectorGraphicsData &data) = default;

        CVectorGraphicsData &operator=(CVectorGraphicsData &&data) = default;

        /**
         * Store line segment
         * @param line_segment Segment to store
         */
        void addLineSegments(Geometry2D::CLineSegment2D line_segment, unsigned int width_pixels = 1) noexcept;

        /**
         * Add several CLineSegment2D objects
         * @tparam InputIterator Should be InputIterator at least
         * @param begin Begin iterator
         * @param end End iterator
         */
        template<typename InputIterator>
        void addLineSegments(InputIterator begin, InputIterator end, unsigned int width_pixels = 1) noexcept;

        /**
         * Get all stored line segments
         * @return list of CLineSegment2D
         */
        const std::vector<Geometry2D::CLineSegment2D> &getLineSegments() const noexcept;

        double getMaxX() const;

        double getMaxY() const;

        double getMinX() const;

        double getMinY() const;

    private:

        void checkRange(const Geometry2D::CLineSegment2D &line_segment);

    };

}