#include <CLinkedVector3D.hpp>

Geometry3D::CLinkedVector3D::CLinkedVector3D(const Geometry3D::CPoint3D &_point_begin,
                                             const Geometry3D::CPoint3D &_point_end) noexcept
        : point_begin{_point_begin}, point_end{_point_end} {}

double Geometry3D::CLinkedVector3D::getX() const noexcept {
    return point_end.getX() - point_begin.getX();
}

double Geometry3D::CLinkedVector3D::getY() const noexcept {
    return point_end.getY() - point_begin.getY();
}

double Geometry3D::CLinkedVector3D::getZ() const noexcept {
    return point_end.getZ() - point_begin.getZ();
}

double Geometry3D::CLinkedVector3D::getLen() const noexcept {
    return sqrt(pow(point_end.getX() - point_begin.getX(), 2) + pow(point_end.getY() - point_begin.getY(), 2) +
                pow(point_end.getZ() - point_begin.getZ(), 2));
}
