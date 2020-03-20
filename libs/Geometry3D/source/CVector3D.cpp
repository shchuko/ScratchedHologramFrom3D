#include "CVector3D.hpp"

namespace Geometry3D {

    CVector3D::CVector3D(const CVector3D &cVector3D) noexcept {
        this->x = cVector3D.getX();
        this->y = cVector3D.getY();
        this->z = cVector3D.getZ();
    }

    CVector3D::CVector3D(CVector3D &&cVector3D) noexcept {
        this->x = cVector3D.getX();
        this->y = cVector3D.getY();
        this->z = cVector3D.getZ();
    }

    CVector3D::CVector3D(double x, double y, double z) {
        this->x = x;
        this->y = y;
        this->z = z;
    }

    double CVector3D::getX() const noexcept {
        return x;
    }

    double CVector3D::getY() const noexcept {
        return y;
    }

    double CVector3D::getZ() const noexcept {
        return z;
    }

    double CVector3D::getLen() const noexcept {
        return 0;
    }

    bool CVector3D::isCollinear(const IVector3D &vector3D) const noexcept {
        return this->x / vector3D.getX() == this->y / vector3D.getY() && this->y / vector3D.getY() == this->z / vector3D.getZ();
    }

    double CVector3D::getAngleCos(const IVector3D &vector3D) const noexcept {
        return (this->x * vector3D.getX() + this->y * vector3D.getY() + this->z * vector3D.getZ())/(sqrt(pow(this->x,2) + pow(this->y,2) + pow(this->z,2)) + sqrt((pow(vector3D.getX(),2) + pow(vector3D.getY(),2) + pow(vector3D.getZ(),2))));
    }

}
