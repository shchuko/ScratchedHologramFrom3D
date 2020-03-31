#pragma once

#include <CPoint2D.hpp>
#include <utility>
#include <cmath>

namespace Geometry2D {
    /**
     * @author github.com/Tulesha
     */
    class CLineSegment2D {
    private:
        const CPoint2D first_point;
        const CPoint2D second_point;
    public:
        /**
         * Copy constructor
         * @param point_begin First point
         * @param point_end Second point
         */
        CLineSegment2D(CPoint2D _first_point, CPoint2D _second_point) noexcept;

        /**
         * Get first point of CLineSegment2D
         * @return reference to the first point
         */
        const CPoint2D &getFirstPoint() const noexcept;

        /**
         * Get second point of CLineSegment2D
         * @return reference to the second point
         */
        const CPoint2D &getSecondPoint() const noexcept;

        /**
         * Get length of CLineSegment2D
         * @return length of CLineSegment2D
         */
        double getLen() const noexcept;
    };
}
