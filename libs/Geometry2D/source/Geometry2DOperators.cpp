#include <Geometry2DOperators.hpp>
#include <Geometry2DBase.hpp>

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

bool Geometry2D::operator==(const Geometry2D::CPoint2D &first, const Geometry2D::CPoint2D &second) {
    return (&first) == (&second) ||
           (isEqualDouble(first.getX(), second.getX()) && isEqualDouble(first.getY(), second.getY()));
}

bool Geometry2D::operator==(const Geometry2D::AVector2D &first, const Geometry2D::AVector2D &second) {
    return (&first) == (&second) ||
           (isEqualDouble(first.getX(), second.getX()) && isEqualDouble(first.getY(), second.getY()));
}
