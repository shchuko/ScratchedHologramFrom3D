#include "CPoint3D.hpp"

namespace Geometry3D {

    CPoint3D::CPoint3D(const CPoint3D &cPoint3D) noexcept {
        this->x = cPoint3D.getX();
        this->y = cPoint3D.getY();
        this->z = cPoint3D.getZ();
    }

    CPoint3D::CPoint3D(CPoint3D &&cPoint3D) noexcept {
        this->x = cPoint3D.getX();
        this->y = cPoint3D.getY();
        this->z = cPoint3D.getZ();
    }

    CPoint3D::CPoint3D(double x, double y, double z) noexcept {
        this->x = x;
        this->y = y;
        this->z = z;
    }

    double CPoint3D::getX() const noexcept {
        return x;
    }

    double CPoint3D::getY() const noexcept {
        return y;
    }

    double CPoint3D::getZ() const noexcept {
        return z;
    }

    CPoint3D &CPoint3D::operator=(const CPoint3D &cPoint3D) {
        if (this != &cPoint3D) {
            x = cPoint3D.getX();
            y = cPoint3D.getY();
            z = cPoint3D.getZ();
        }
        return *this;
    }

    void CPoint3D::move(const AVector3D &vector3D) noexcept {
        this->x += vector3D.getX();
        this->y += vector3D.getY();
        this->z += vector3D.getZ();
    }

    CPoint3D CPoint3D::moveCopy(const AVector3D &vector3D) const noexcept {
        double new_x = this->getX() + vector3D.getX();
        double new_y = this->getY() + vector3D.getY();
        double new_z = this->getZ() + vector3D.getZ();
        return {new_x, new_y, new_z};
    }
}