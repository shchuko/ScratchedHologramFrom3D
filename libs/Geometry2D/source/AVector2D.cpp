#include <AVector2D.hpp>

bool Geometry2D::AVector2D::isCollinear(const Geometry2D::AVector2D &vector) const noexcept {
    double first_vector_x = this->getX();
    double first_vector_y = this->getY();

    double second_vector_x = vector.getX();
    double second_vector_y = vector.getY();

    if (isEqualDouble(first_vector_x, 0.0) && isEqualDouble(second_vector_x, 0.0) &&
        isEqualDouble(first_vector_y, 0.0) && isEqualDouble(second_vector_y, 0.0)) {
        return true;
    } else if (isEqualDouble(first_vector_x, 0.0) && isEqualDouble(second_vector_x, 0.0)) {
        return true;
    } else if (isEqualDouble(first_vector_y, 0.0) && isEqualDouble(second_vector_y, 0.0)) {
        return true;
    } else {
        return isEqualDouble(first_vector_x / second_vector_x, first_vector_y / second_vector_y);
    }
}

double Geometry2D::AVector2D::getAngleCos(const Geometry2D::AVector2D &vector) const noexcept {
    double first_vector_x = this->getX();
    double first_vector_y = this->getY();

    double second_vector_x = vector.getX();
    double second_vector_y = vector.getY();

    double numerator = first_vector_x * second_vector_x + first_vector_y * second_vector_y;
    double denominator = sqrt(first_vector_x * first_vector_x + first_vector_y * first_vector_y) *
                         sqrt(second_vector_x * second_vector_x + second_vector_y * second_vector_y);

    if (denominator != 0)
        return numerator / denominator;
    return 1;
}
