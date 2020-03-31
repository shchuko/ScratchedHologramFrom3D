#include <CVector3D.hpp>

namespace Geometry3D {
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
        return sqrt(x * x + y * y + z * z);
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

    CVector3D &CVector3D::operator+=(const AVector3D &vector) {
        x += vector.getX();
        y += vector.getY();
        z += vector.getZ();

        return *this;
    }

    CVector3D &CVector3D::operator-=(const AVector3D &vector) {
        x -= vector.getX();
        y -= vector.getY();
        z -= vector.getZ();

        return *this;
    }

    void CVector3D::setX(double _x) {
        CVector3D::x = _x;
    }

    void CVector3D::setY(double _y) {
        CVector3D::y = _y;
    }

    void CVector3D::setZ(double _z) {
        CVector3D::z = _z;
    }

    CVector3D &CVector3D::operator=(const AVector3D &vec) noexcept {
        x = vec.getX();
        y = vec.getY();
        z = vec.getZ();
        return *this;
    }

    CVector3D &CVector3D::operator=(AVector3D &&vec) noexcept {
        operator=(vec);
        return *this;
    }
}
