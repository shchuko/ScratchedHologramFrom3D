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
}
