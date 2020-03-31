#pragma once

#include <limits>
#include <vector>
#include <algorithm>
#include <CPoint3D.hpp>

#include "TFile3DProcessingToolsTypes.hpp"


namespace File3DProcessingTools {
    /**
     * Point array analyzer class (minX, maxX, minY, ...)
     * @author Vladislav Yaroshchuk, github.com/shchuko
     */
    class CPoints3DStatistics {
    private:
        double max_x = -std::numeric_limits<double>::max();
        double max_y = -std::numeric_limits<double>::max();
        double max_z = -std::numeric_limits<double>::max();
        double min_x = std::numeric_limits<double>::max();
        double min_y = std::numeric_limits<double>::max();
        double min_z = std::numeric_limits<double>::max();

    public:
         /**
          * Analyse points array
          * @tparam InputIterator Iterator category at least InputIterator
          * @param begin Begin iterator
          * @param end End iterator
          */
        template<typename InputIterator>
        explicit CPoints3DStatistics(InputIterator begin, InputIterator end) noexcept {
            std::for_each(begin, end,
                          [&](const Geometry3D::CPoint3D &point) { fillMaxMinValues(point); });
        }

        /**
       * Get max x coordinate value
       * @return Max x coordinate value
       */
        double getMaxX() const noexcept;

        /**
         * Get min x coordinate value
         * @return Min x coordinate value
         */
        double getMinX() const noexcept;

        /**
         * Get max y coordinate value
         * @return Max y coordinate value
         */
        double getMaxY() const noexcept;

        /**
         * Get min y coordinate value
         * @return Min y coordinate value
         */
        double getMinY() const noexcept;

        /**
         * Get max z coordinate value
         * @return Max z coordinate value
         */
        double getMaxZ() const noexcept;

        /**
         * Get min z coordinate value
         * @return Min z coordinate value
         */
        double getMinZ() const noexcept;

    private:
        void fillMaxMinValues(const Geometry3D::CPoint3D &point);
    };

}
