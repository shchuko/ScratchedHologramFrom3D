#pragma once

#include <CPoint2D.hpp>
#include <Geometry2DBase.hpp>
#include <utility>
#include <cmath>

namespace Geometry2D {
    /**
     * @author github.com/Tulesha
     */
    class CLineSegment2D {
    private:
        CPoint2D first_point;
        CPoint2D second_point;

    public:
        /**
         * Copy constructor
         * @param point_begin First point
         * @param point_end Second point
         */
        CLineSegment2D(CPoint2D _first_point, CPoint2D _second_point) noexcept;
        
        /**
        * Copy constructor
        * @param lineSegment2D Object to copy
        */
        CLineSegment2D(const CLineSegment2D &lineSegment2D) noexcept = default;

        /**
         * Move constructor
         * @param lineSegment2D Object to move
         */
        CLineSegment2D(CLineSegment2D &&lineSegment2D) noexcept = default;

        /**
         * Copy assignment operator
         * @param lineSegment2D Object to assing
         */
        CLineSegment2D &operator=(const CLineSegment2D &lineSegment2D) noexcept = default;

        /**
         * Move assignment operator
         * @param lineSegment2D Object to assign
         */
        CLineSegment2D &operator=(CLineSegment2D &&lineSegment2D) noexcept = default;

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
