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
        return sqrt(pow(this->x, 2) + pow(this->y, 2) + pow(this->z, 2));
    }

    bool CVector3D::isCollinear(const IVector3D &vector3D) const noexcept {
        return this->x / vector3D.getX() == this->y / vector3D.getY() &&
               this->y / vector3D.getY() == this->z / vector3D.getZ();
    }

    double CVector3D::getAngleCos(const IVector3D &vector3D) const noexcept {
        return (this->x * vector3D.getX() + this->y * vector3D.getY() + this->z * vector3D.getZ()) /
               (sqrt(pow(this->x, 2) + pow(this->y, 2) + pow(this->z, 2)) +
                sqrt((pow(vector3D.getX(), 2) + pow(vector3D.getY(), 2) + pow(vector3D.getZ(), 2))));
    }

    CVector3D CVector3D::operator+() const {
        return CVector3D(*this);
    }

    CVector3D CVector3D::operator-() const {
        double new_x = -x;
        double new_y = -y;
        double new_z = -z;

        return CVector3D(new_x, new_y, new_z);
    }

    CVector3D &CVector3D::operator+=(const IVector3D &iVector3D) {
        x += iVector3D.getX();
        y += iVector3D.getY();
        z += iVector3D.getZ();

        return *this;
    }

    CVector3D &CVector3D::operator-=(const IVector3D &iVector3D) {
        x -= iVector3D.getX();
        y -= iVector3D.getY();
        z -= iVector3D.getZ();

        return *this;
    }
}
