#pragma once

#include <vector>
#include "../../Geometry2D/include/CLineSegment2D.hpp"

namespace File2DProcessingTools {


    /**
     * Vector graphics storage
     * @author Nikita Novgorodtsev (github <https://github.com/paNoNi>)
     */
    class CVectorGraphicsData {

    private:
        std::vector<Geometry2D::CLineSegment2D> _data;

    public:


        /**
         * Store line segment
         */
        void addLineSegment(Geometry2D::CLineSegment2D) noexcept;

        /**
         * Get all stored line segments
         * @return list of CLineSegment2D
         */
        const std::vector<Geometry2D::CLineSegment2D> &getLineSegments() const noexcept;
    };

}