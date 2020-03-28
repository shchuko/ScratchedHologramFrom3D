#include <Geometry3DOperators.hpp>

Geometry3D::CVector3D Geometry3D::operator+(const Geometry3D::AVector3D &left, const Geometry3D::AVector3D &right) {
    double x = left.getX() + right.getX();
    double y = left.getY() + right.getY();
    double z = left.getZ() + right.getZ();
    return CVector3D(x, y, z);
}

Geometry3D::CVector3D Geometry3D::operator-(const Geometry3D::AVector3D &left, const Geometry3D::AVector3D &right) {
    double x = left.getX() - right.getX();
    double y = left.getY() - right.getY();
    double z = left.getZ() - right.getZ();
    return CVector3D(x, y, z);
}

bool Geometry3D::operator==(const Geometry3D::CPoint3D &first, const Geometry3D::CPoint3D &second) {
    return (&first) == (&second) ||
           (std::fabs(first.getX() - second.getX()) <= std::numeric_limits<double>::epsilon() &&
            std::fabs(first.getY() - second.getY()) <= std::numeric_limits<double>::epsilon() &&
            std::fabs(first.getZ() - second.getZ()) <= std::numeric_limits<double>::epsilon());
}
