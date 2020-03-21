#include <AVector3D.hpp>

bool Geometry3D::AVector3D::isCollinear(const Geometry3D::AVector3D &vector3D) const noexcept {
    if (is_equal_double(this->getX(), 0.0) && is_equal_double(vector3D.getX(), 0.0) &&
        is_equal_double(this->getY(), 0.0) && is_equal_double(vector3D.getY(), 0.0) &&
        is_equal_double(this->getZ(), 0.0) && is_equal_double(vector3D.getZ(), 0.0)) {
        return true;
    } else if (is_equal_double(this->getX(), 0.0) && is_equal_double(vector3D.getX(), 0.0) &&
               is_equal_double(this->getY(), 0.0) && is_equal_double(vector3D.getY(), 0.0)) {
        return true;
    } else if (is_equal_double(this->getX(), 0.0) && is_equal_double(vector3D.getX(), 0.0) &&
               is_equal_double(this->getZ(), 0.0) && is_equal_double(vector3D.getZ(), 0.0)) {
        return true;
    } else if (is_equal_double(this->getY(), 0.0) && is_equal_double(vector3D.getY(), 0.0) &&
               is_equal_double(this->getZ(), 0.0) && is_equal_double(vector3D.getZ(), 0.0)) {
        return true;
    } else if (is_equal_double(this->getX(), 0.0) && is_equal_double(vector3D.getX(), 0.0)) {
        return is_equal_double(this->getY() / vector3D.getY(), this->getZ() / vector3D.getZ());
    } else if (is_equal_double(this->getY(), 0.0) && is_equal_double(vector3D.getY(), 0.0)) {
        return is_equal_double(this->getX() / vector3D.getX(), this->getZ() / vector3D.getZ());
    } else if (is_equal_double(this->getZ(), 0.0) && is_equal_double(vector3D.getZ(), 0.0)) {
        return is_equal_double(this->getX() / vector3D.getX(), this->getY() / vector3D.getY());
    } else {
        return is_equal_double(this->getX() / vector3D.getX(), this->getY() / vector3D.getY()) &&
               is_equal_double(this->getY() / vector3D.getY(), this->getZ() / vector3D.getZ());
    }
}

bool Geometry3D::AVector3D::is_equal_double(double x, double y) const noexcept {
    return std::fabs(x - y) < std::numeric_limits<double>::epsilon();
}

double Geometry3D::AVector3D::getAngleCos(const Geometry3D::AVector3D &vector3D) const noexcept {
    double numerator =
            this->getX() * vector3D.getX() + this->getY() * vector3D.getY() + this->getZ() * vector3D.getZ();
    double denominator = (sqrt(pow(this->getX(), 2) + pow(this->getY(), 2) + pow(this->getZ(), 2)) +
                          sqrt((pow(vector3D.getX(), 2) + pow(vector3D.getY(), 2) + pow(vector3D.getZ(), 2))));

    if (denominator != 0)
        return numerator / denominator;
    return 1;
}
