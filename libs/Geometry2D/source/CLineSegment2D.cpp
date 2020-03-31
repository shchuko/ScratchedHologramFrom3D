#include "CLineSegment2D.hpp"

#include <utility>

namespace Geometry2D {


    CLineSegment2D::CLineSegment2D(CPoint2D _first_point, CPoint2D _second_point) noexcept
            : first_point{_first_point}
            , second_point{_second_point} {
    }

    const CPoint2D &CLineSegment2D::getFirstPoint() const noexcept {
        return first_point;
    }

    const CPoint2D &CLineSegment2D::getSecondPoint() const noexcept {
        return second_point;
    }

    double CLineSegment2D::getLen() const noexcept {
        double difference_between_x = second_point.getX() - first_point.getX();
        double difference_between_y = second_point.getY() - first_point.getY();

        return sqrt(difference_between_x * difference_between_x + difference_between_y * difference_between_y);
    }
}
