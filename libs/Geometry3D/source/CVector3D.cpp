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

}
