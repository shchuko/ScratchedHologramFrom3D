#include <CVector2D.hpp>

namespace Geometry2D {
    CVector2D::CVector2D(double x, double y) {
        this->x = x;
        this->y = y;
    }

    double CVector2D::getX() const noexcept {
        return x;
    }

    double CVector2D::getY() const noexcept {
        return y;
    }

    double CVector2D::getLen() const noexcept {
        return sqrt(x * x + y * y);
    }

    CVector2D Geometry2D::CVector2D::operator+() const {
        return CVector2D(*this);
    }

    CVector2D Geometry2D::CVector2D::operator-() const {
        double new_x = -x;
        double new_y = -y;

        return CVector2D(new_x, new_y);
    }

    CVector2D &Geometry2D::CVector2D::operator+=(const Geometry2D::AVector2D &vector) {
        x += vector.getX();
        y += vector.getY();

        return *this;
    }

    CVector2D &Geometry2D::CVector2D::operator-=(const Geometry2D::AVector2D &vector) {
        x -= vector.getX();
        y -= vector.getY();

        return *this;
    }
}
