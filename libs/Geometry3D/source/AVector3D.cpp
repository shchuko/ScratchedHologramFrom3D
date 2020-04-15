#include <AVector3D.hpp>

bool Geometry3D::AVector3D::isCollinear(const Geometry3D::AVector3D &vector) const noexcept {
    double x_first = this->getX();
    double y_first = this->getY();
    double z_first = this->getZ();

    double x_second = vector.getX();
    double y_second = vector.getY();
    double z_second = vector.getZ();

    if (isEqualDouble(x_first, 0.0) && isEqualDouble(y_first, 0.0) && isEqualDouble(z_first, 0.0)) {
        return true;
    }

    if (isEqualDouble(x_second, 0.0) && isEqualDouble(y_second, 0.0) && isEqualDouble(z_second, 0.0)) {
        return true;
    }

    if (isEqualDouble(x_first, 0.0) && isEqualDouble(x_second, 0.0) &&
        isEqualDouble(y_first, 0.0) && isEqualDouble(y_second, 0.0) &&
        isEqualDouble(z_first, 0.0) && isEqualDouble(z_second, 0.0)) {
        return true;
    }

    if (isEqualDouble(x_first, 0.0) && isEqualDouble(x_second, 0.0) &&
        isEqualDouble(y_first, 0.0) && isEqualDouble(y_second, 0.0)) {
        return true;
    }

    if (isEqualDouble(x_first, 0.0) && isEqualDouble(x_second, 0.0) &&
        isEqualDouble(z_first, 0.0) && isEqualDouble(z_second, 0.0)) {
        return true;
    }

    if (isEqualDouble(y_first, 0.0) && isEqualDouble(y_second, 0.0) &&
        isEqualDouble(z_first, 0.0) && isEqualDouble(z_second, 0.0)) {
        return true;
    }

    if (isEqualDouble(x_first, 0.0) && isEqualDouble(x_second, 0.0)) {
        return isEqualDouble(y_first / y_second, z_first / z_second);
    }

    if (isEqualDouble(y_first, 0.0) && isEqualDouble(y_second, 0.0)) {
        return isEqualDouble(x_first / x_second, z_first / z_second);
    }

    if (isEqualDouble(z_first, 0.0) && isEqualDouble(z_second, 0.0)) {
        return isEqualDouble(x_first / x_second, y_first / y_second);
    }

    return isEqualDouble(x_first / x_second, y_first / y_second) &&
           isEqualDouble(y_first / y_second, z_first / z_second);

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
    return std::fabs(x - y) < LIB_GEOMETRY3D_EPSILON;
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
