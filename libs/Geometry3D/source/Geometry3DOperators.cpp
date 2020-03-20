#include "Geometry3DOperators.hpp"

Geometry3D::CVector3D Geometry3D::operator+(const Geometry3D::IVector3D &left, const Geometry3D::IVector3D &right) {
    double x = left.getX() + right.getX();
    double y = left.getY() + right.getY();
    double z = left.getZ() + right.getZ();
    return CVector3D(x, y, z);
}

Geometry3D::CVector3D Geometry3D::operator-(const Geometry3D::IVector3D &left, const Geometry3D::IVector3D &right) {
    double x = left.getX() - right.getX();
    double y = left.getY() - right.getY();
    double z = left.getZ() - right.getZ();
    return CVector3D(x, y, z);
}
