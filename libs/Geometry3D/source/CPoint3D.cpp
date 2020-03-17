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
}