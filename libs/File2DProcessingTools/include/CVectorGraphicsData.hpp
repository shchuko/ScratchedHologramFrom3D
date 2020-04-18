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
        double min_x = std::numeric_limits<double>::max();
        double min_y = std::numeric_limits<double>::max();
        double max_x = -std::numeric_limits<double>::max();
        double max_y = -std::numeric_limits<double>::max();
        std::vector<unsigned int> width;

        class CColor_T {
        private:
            uint8_t _red{};
            uint8_t _green{};
            uint8_t _blue{};
            std::string _hex_color;
        public:

            /**
             * Built-in color set
             */
            enum COLOR {
                RED, ORANGE, YELLOW, GREEN, BLUE, PURPLE, BLACK, WHITE, PINK, GREY
            };

            /**
            * Set color from RGB palette
            * @param red - red level
            * @param green - green level
            * @param blue - blue level
            */
            CColor_T(uint8_t red, uint8_t green, uint8_t blue);

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
            void setColor(uint8_t red, uint8_t green, uint8_t blue);

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
            void setColor(COLOR color);

            /**
             * Getter HEX color string
             * @return color ("#FFFFFF" format)
             */
            std::string getHexStr();

            /**
             * Getter RGB ccolor string
             * @return color ("255, 255, 255" format)
             */
            std::string getRGBStr() const;

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