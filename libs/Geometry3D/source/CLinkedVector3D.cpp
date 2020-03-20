#include <CLinkedVector3D.hpp>

Geometry3D::CLinkedVector3D::CLinkedVector3D(const Geometry3D::CPoint3D &point_begin,
                                             const Geometry3D::CPoint3D &point_end) noexcept : point_begin(
        const_cast<CPoint3D &>(point_begin)), point_end(const_cast<CPoint3D &>(point_end)) {
    this->point_begin = point_begin;
    this->point_end = point_end;
}

Geometry3D::CLinkedVector3D::CLinkedVector3D(const Geometry3D::CPoint3D &&point_begin,
                                             const Geometry3D::CPoint3D &&point_end) noexcept : point_begin(
        const_cast<CPoint3D &>(point_begin)), point_end(const_cast<CPoint3D &>(point_end)) {
    this->point_begin = point_begin;
    this->point_end = point_end;
}

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

bool Geometry3D::CLinkedVector3D::isCollinear(const Geometry3D::IVector3D &vector3D) const noexcept {
    return this->getX() / vector3D.getX() == this->getY() / vector3D.getY() &&
           this->getY() / vector3D.getY() == this->getZ() / vector3D.getZ();
}

double Geometry3D::CLinkedVector3D::getAngleCos(const Geometry3D::IVector3D &vector3D) const noexcept {
    return (this->getX() * vector3D.getX() + this->getY() * vector3D.getY() + this->getZ() * vector3D.getZ()) /
           (sqrt(pow(this->getX(), 2) + pow(this->getY(), 2) + pow(this->getZ(), 2)) +
            sqrt((pow(vector3D.getX(), 2) + pow(vector3D.getY(), 2) + pow(vector3D.getZ(), 2))));
}

Geometry3D::CLinkedVector3D Geometry3D::CLinkedVector3D::operator+() const {

    return CLinkedVector3D(*this);
}

Geometry3D::CLinkedVector3D Geometry3D::CLinkedVector3D::operator-() const {
    CPoint3D new_point_begin(-this->point_begin.getX(), -this->point_begin.getY(), -this->point_begin.getZ());
    CPoint3D new_point_end(-this->point_end.getX(), -this->point_end.getY(), -this->point_end.getZ());
    return CLinkedVector3D(new_point_begin, new_point_end);
}

Geometry3D::CLinkedVector3D &Geometry3D::CLinkedVector3D::operator+=(const Geometry3D::IVector3D &iVector3D) {
    return <#initializer#>;
}

Geometry3D::CLinkedVector3D &Geometry3D::CLinkedVector3D::operator-=(const Geometry3D::IVector3D &iVector3D) {
    return <#initializer#>;
}
