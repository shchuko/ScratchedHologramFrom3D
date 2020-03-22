#include "CPoint2D.hpp"

namespace Geometry2D {

    CPoint2D::CPoint2D(const CPoint2D &point) noexcept {
        this->x = point.getX();
        this->y = point.getY();
    }

    CPoint2D::CPoint2D(CPoint2D &&point) noexcept {
        this->x = point.getX();
        this->y = point.getY();
    }

    CPoint2D::CPoint2D(double x, double y) noexcept {
        this->x = x;
        this->y = y;
    }

    double CPoint2D::getX() const noexcept {
        return x;
    }

    double CPoint2D::getY() const noexcept {
        return y;
    }

    void CPoint2D::move(const AVector2D &vector) noexcept {
        this->x += vector.getX();
        this->y += vector.getY();
    }

    CPoint2D CPoint2D::moveCopy(const AVector2D &vector) const noexcept {
        double new_x = this->getX() + vector.getX();
        double new_y = this->getY() + vector.getY();
        return {new_x, new_y};
    }
}