#pragma once

#include <vector>
#include <cfloat>
#include <limits>
#include <string>
#include <utility>
#include <sstream>
#include <iomanip>

#include "ENotAColorHex.hpp"
#include "CLineSegment2D.hpp"

namespace File2DProcessingTools {
    /**
     * Vector graphics storage
     * @author Nikita Novgorodtsev (github <https://github.com/paNoNi>)
     */
    class CVectorGraphicsData {
    private:

        std::vector<Geometry2D::CLineSegment2D> _line_segments;
        std::vector<unsigned int> _line_segments_widths;

        double min_x = std::numeric_limits<double>::max();
        double min_y = std::numeric_limits<double>::max();
        double max_x = -std::numeric_limits<double>::max();
        double max_y = -std::numeric_limits<double>::max();

    public:

        class CColor_T {
        private:
            uint8_t _red = 0;
            uint8_t _green = 0;
            uint8_t _blue = 0;
            std::string _hex_color = "#000";
        public:

            /**
             * Built-in color set
             */
            enum class COLOR {
                RED, ORANGE, YELLOW, GREEN, BLUE, PURPLE, BLACK, WHITE, PINK, GREY
            };

            CColor_T() = default;

            CColor_T(const CColor_T &color) = default;

            CColor_T(CColor_T &&color) = default;

            CColor_T& operator=(const CColor_T &color) = default;
            CColor_T& operator=(CColor_T &&color) = default;


            /**
            * Set color from RGB palette
            * @param red - red level
            * @param green - green level
            * @param blue - blue level
            */
            CColor_T(uint8_t red, uint8_t green, uint8_t blue) noexcept;

            /**
             * Set color default CVectorGraphicsData::CColor_T::COLOR
             * @param color - color name
             */
            explicit CColor_T(COLOR color) noexcept;

            /**
             * Set color from HEX palette
             * @throws ENotAColorHex - If the color format is incorrect
             * @param color_hex - hex color format (#FFF or #FFFFFF)
             */
            explicit CColor_T(std::string hex_color);

            /**
             * Set color from RGB palette
             * @param red - red level
             * @param green - green level
             * @param blue - blue level
             */
            void setColor(uint8_t red, uint8_t green, uint8_t blue) noexcept;

            /**
             * Set color from HEX palette
             * @throws ENotAColorHex - If the color format is incorrect
             * @param color_hex - hex color format (#FFF or #FFFFFF)
             */
            void setColor(std::string color_hex);

            /**
             * Set color default CVectorGraphicsData::CColor_T::COLOR
             * @param color - color name
             */
            void setColor(COLOR color) noexcept;

            /**
             * Getter HEX color string
             * @return color ("#FFFFFF" format)
             */
            std::string getHexStr() const noexcept;

            /**
             * Getter RGB ccolor string
             * @return color ("255, 255, 255" format)
             */
            std::string getRGBStr() const noexcept;

        };


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
        void addLineSegments(InputIterator begin, InputIterator end, unsigned int width_pixels = 1) noexcept {
            _line_segments.insert(_line_segments.end(), begin, end);
            _line_segments_widths.emplace_back(width_pixels);
            _colors.emplace_back(_current_color);
        }

        /**
         * Get all stored line segments
         * @return list of CLineSegment2D
         */
        const std::vector<Geometry2D::CLineSegment2D> &getLineSegments() const noexcept;

        double getMaxX() const noexcept;

        double getMaxY() const noexcept;

        double getMinX() const noexcept;

        double getMinY() const noexcept;

        // Next color should be used for all next added objects
        // Default is black
        void setNextColor(const CColor_T &color) noexcept;

        const std::vector<unsigned int> &getLineSegmentsWidths() const noexcept;

        const std::vector<CColor_T> &getLineSegmentsColors() const noexcept;

    private:

        void checkRange(const Geometry2D::CLineSegment2D &line_segment) noexcept;

        CColor_T _current_color;
        std::vector<CColor_T> _colors;

    };

}