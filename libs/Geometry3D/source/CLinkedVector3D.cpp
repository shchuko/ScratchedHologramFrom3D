#include <CLinkedVector3D.hpp>


double Geometry3D::CLinkedVector3D::getX() const noexcept {
    return point_end->getX() - point_begin->getX();
}

double Geometry3D::CLinkedVector3D::getY() const noexcept {
    return point_end->getY() - point_begin->getY();
}

double Geometry3D::CLinkedVector3D::getZ() const noexcept {
    return point_end->getZ() - point_begin->getZ();
}

double Geometry3D::CLinkedVector3D::getLen() const noexcept {
    double point_end_x = point_end->getX();
    double point_end_y = point_end->getY();
    double point_end_z = point_end->getZ();

    double point_begin_x = point_begin->getX();
    double point_begin_y = point_begin->getY();
    double point_begin_z = point_begin->getZ();

    return sqrt(((point_end_x - point_begin_x) * (point_end_x - point_begin_x)) +
                ((point_end_y - point_begin_y) * (point_end_y - point_begin_y)) +
                ((point_end_z - point_begin_z) * (point_end_z - point_begin_z)));
}

Geometry3D::CLinkedVector3D::CLinkedVector3D(const Geometry3D::CPoint3D &_point_begin,
                                             const Geometry3D::CPoint3D &_point_end) noexcept {
    this->point_begin = &_point_begin;
    this->point_end = &_point_end;
}

void Geometry3D::CLinkedVector3D::setPointBegin(const Geometry3D::CPoint3D &new_point_begin) noexcept {
    point_begin = &new_point_begin;
}

void Geometry3D::CLinkedVector3D::setPointEnd(const Geometry3D::CPoint3D &new_point_end) noexcept {
    point_end = &new_point_end;
}

const Geometry3D::CPoint3D &Geometry3D::CLinkedVector3D::getPointBegin() const noexcept {
    return *point_begin;
}

const Geometry3D::CPoint3D &Geometry3D::CLinkedVector3D::getPointEnd() const noexcept {
    return *point_end;
}
