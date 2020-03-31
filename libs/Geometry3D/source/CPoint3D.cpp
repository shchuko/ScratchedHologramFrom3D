#include <CPoint3D.hpp>

namespace Geometry3D {

    CPoint3D::CPoint3D(const CPoint3D &point) noexcept {
        this->x = point.getX();
        this->y = point.getY();
        this->z = point.getZ();
    }

    CPoint3D::CPoint3D(CPoint3D &&point) noexcept {
        this->x = point.getX();
        this->y = point.getY();
        this->z = point.getZ();
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

    CPoint3D &CPoint3D::operator=(const CPoint3D &point) noexcept {
        if (this != &point) {
            x = point.getX();
            y = point.getY();
            z = point.getZ();
        }
        return *this;
    }

    void CPoint3D::move(const AVector3D &vector) noexcept {
        this->x += vector.getX();
        this->y += vector.getY();
        this->z += vector.getZ();
    }

    CPoint3D CPoint3D::moveCopy(const AVector3D &vector) const noexcept {
        double new_x = this->getX() + vector.getX();
        double new_y = this->getY() + vector.getY();
        double new_z = this->getZ() + vector.getZ();
        return {new_x, new_y, new_z};
    }

    double CPoint3D::getDistance(const CPoint3D &point) const noexcept {
        double difference_between_x = point.x - this->x;
        double difference_between_y = point.y - this->y;
        double difference_between_z = point.z - this->z;

        return std::sqrt(difference_between_x * difference_between_x + difference_between_y * difference_between_y +
                         difference_between_z * difference_between_z);
    }

    double CPoint3D::getDistance(CPoint3D &&point) const noexcept {
        double difference_between_x = point.x - this->x;
        double difference_between_y = point.y - this->y;
        double difference_between_z = point.z - this->z;

        return std::sqrt(difference_between_x * difference_between_x + difference_between_y * difference_between_y +
                         difference_between_z * difference_between_z);
    }

    void CPoint3D::setX(double _x) {
        CPoint3D::x = _x;
    }

    void CPoint3D::setY(double _y) {
        CPoint3D::y = _y;
    }

    void CPoint3D::setZ(double _z) {
        CPoint3D::z = _z;
    }
}