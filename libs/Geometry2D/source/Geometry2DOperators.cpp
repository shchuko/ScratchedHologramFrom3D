#include <Geometry2DOperators.hpp>

Geometry2D::CVector2D Geometry2D::operator+(const Geometry2D::AVector2D &left, const Geometry2D::AVector2D &right) {
    double x = left.getX() + right.getX();
    double y = left.getY() + right.getY();
    return CVector2D(x, y);
}

Geometry2D::CVector2D Geometry2D::operator-(const Geometry2D::AVector2D &left, const Geometry2D::AVector2D &right) {
    double x = left.getX() - right.getX();
    double y = left.getY() - right.getY();
    return CVector2D(x, y);
}
