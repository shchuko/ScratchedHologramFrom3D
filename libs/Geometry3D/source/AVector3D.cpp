#include <AVector3D.hpp>

bool Geometry3D::AVector3D::isCollinear(const Geometry3D::AVector3D &vector) const noexcept {
    double first_vector_x = this->getX();
    double first_vector_y = this->getY();
    double first_vector_z = this->getZ();

    double second_vector_x = vector.getX();
    double second_vector_y = vector.getY();
    double second_vector_z = vector.getZ();

    if (isEqualDouble(first_vector_x, 0.0) && isEqualDouble(second_vector_x, 0.0) &&
        isEqualDouble(first_vector_y, 0.0) && isEqualDouble(second_vector_y, 0.0) &&
        isEqualDouble(first_vector_z, 0.0) && isEqualDouble(second_vector_z, 0.0)) {
        return true;
    } else if (isEqualDouble(first_vector_x, 0.0) && isEqualDouble(second_vector_x, 0.0) &&
               isEqualDouble(first_vector_y, 0.0) && isEqualDouble(second_vector_y, 0.0)) {
        return true;
    } else if (isEqualDouble(first_vector_x, 0.0) && isEqualDouble(second_vector_x, 0.0) &&
               isEqualDouble(first_vector_z, 0.0) && isEqualDouble(second_vector_z, 0.0)) {
        return true;
    } else if (isEqualDouble(first_vector_y, 0.0) && isEqualDouble(second_vector_y, 0.0) &&
               isEqualDouble(first_vector_z, 0.0) && isEqualDouble(second_vector_z, 0.0)) {
        return true;
    } else if (isEqualDouble(first_vector_x, 0.0) && isEqualDouble(second_vector_x, 0.0)) {
        return isEqualDouble(first_vector_y / second_vector_y, first_vector_z / second_vector_z);
    } else if (isEqualDouble(first_vector_y, 0.0) && isEqualDouble(second_vector_y, 0.0)) {
        return isEqualDouble(first_vector_x / second_vector_x, first_vector_z / second_vector_z);
    } else if (isEqualDouble(first_vector_z, 0.0) && isEqualDouble(second_vector_z, 0.0)) {
        return isEqualDouble(first_vector_x / second_vector_x, first_vector_y / second_vector_y);
    } else {
        return isEqualDouble(first_vector_x / second_vector_x, first_vector_y / second_vector_y) &&
               isEqualDouble(first_vector_y / second_vector_y, first_vector_z / second_vector_z);
    }
}

double Geometry3D::AVector3D::getAngleCos(const Geometry3D::AVector3D &vector) const noexcept {
    double first_vector_x = this->getX();
    double first_vector_y = this->getY();
    double first_vector_z = this->getZ();

    double second_vector_x = vector.getX();
    double second_vector_y = vector.getY();
    double second_vector_z = vector.getZ();

    double numerator =
            first_vector_x * second_vector_x + first_vector_y * second_vector_y + first_vector_z * second_vector_z;
    double denominator =
            sqrt(first_vector_x * first_vector_x + first_vector_y * first_vector_y + first_vector_z * first_vector_z) *
            sqrt(second_vector_x * second_vector_x + second_vector_y * second_vector_y +
                 second_vector_z * second_vector_z);

    if (denominator != 0)
        return numerator / denominator;
    return 1;
}

bool Geometry3D::AVector3D::isEqualDouble(double x, double y) noexcept {
    return std::fabs(x - y) < std::numeric_limits<double>::epsilon();
}

double Geometry3D::AVector3D::getNormalizedX() const noexcept {
    return getX() / getLen();
}

double Geometry3D::AVector3D::getNormalizedY() const noexcept {
    return getY() / getLen();
}

double Geometry3D::AVector3D::getNormalizedZ() const noexcept {
    return getZ() / getLen();
}
