#include <CLinkedLine3D.hpp>

Geometry3D::CLinkedLine3D::CLinkedLine3D(const AVector3D &direction_vector, const CPoint3D &linked_point) noexcept {
    this->p_direction_vector = &direction_vector;
    this->p_linked_point = &linked_point;
}

void Geometry3D::CLinkedLine3D::setDirectionVector(const Geometry3D::AVector3D &direction_vector) noexcept {
    this->p_direction_vector = &direction_vector;
}

void Geometry3D::CLinkedLine3D::setLinkedPoint(const Geometry3D::CPoint3D &linked_point) noexcept {
    this->p_linked_point = &linked_point;
}

const Geometry3D::AVector3D &Geometry3D::CLinkedLine3D::getDirectionVector() const noexcept {
    return *p_direction_vector;
}

const Geometry3D::CPoint3D &Geometry3D::CLinkedLine3D::getLinkedPoint() const noexcept {
    return *p_linked_point;
}

Geometry3D::CLinkedLine3D::RelationType
Geometry3D::CLinkedLine3D::getRelationType(const Geometry3D::CLinkedLine3D &line) const noexcept {
    if (getCoplanarCheckDeterminant(line) != 0) {
        return RelationType::SKEW;
    }

    if (this->p_direction_vector->isCollinear(*(line.p_direction_vector))) {
        if (isPointOnLine(*(line.p_linked_point))) {
            return RelationType::OVERLAP;
        }

        return RelationType::PARALLEL;
    }

    return RelationType::CROSSING;
}

Geometry3D::CPoint3D Geometry3D::CLinkedLine3D::getCrossingPoint(const Geometry3D::CLinkedLine3D &line) const noexcept {
    if (getRelationType(line) == RelationType::CROSSING) {
        double v_x = this->p_direction_vector->getX();
        double v_y = this->p_direction_vector->getY();
        double v_z = this->p_direction_vector->getZ();

        double pv_x = this->p_linked_point->getX();
        double pv_y = this->p_linked_point->getY();
        double pv_z = this->p_linked_point->getZ();


        double s_x = line.p_direction_vector->getX();
        double s_y = line.p_direction_vector->getY();
        double s_z = line.p_direction_vector->getZ();

        double ps_x = line.p_linked_point->getX();
        double ps_y = line.p_linked_point->getY();
        double ps_z = line.p_linked_point->getZ();


        double numerator_x = pv_x * v_y * s_x - ps_x * s_y * v_x - pv_y * v_x * s_x + ps_y * v_x * s_x;
        double denominator_x = v_y * s_x - s_y * v_x;

        double numerator_y = pv_y * v_x * s_y - ps_y * s_x * v_y - pv_x * v_y * s_y + ps_x * v_y * s_y;
        double denominator_y = v_x * s_y - s_x * v_y;

        double numerator_z = pv_z * v_y * s_z - ps_z * s_y * v_z - pv_y * v_z * s_z + ps_y * v_z * s_z;
        double denominator_z = v_y * s_z - s_y * v_z;

        double crossing_point_x = numerator_x / denominator_x;
        double crossing_point_y = numerator_y / denominator_y;
        double crossing_point_z = numerator_z / denominator_z;

        return {crossing_point_x, crossing_point_y, crossing_point_z};
    }

    if (getRelationType(line) == RelationType::PARALLEL || getRelationType(line) == RelationType::SKEW) {
        return {std::numeric_limits<double>::quiet_NaN(), std::numeric_limits<double>::quiet_NaN(),
                std::numeric_limits<double>::quiet_NaN()};
    }

    return {std::numeric_limits<double>::infinity(), std::numeric_limits<double>::infinity(),
            std::numeric_limits<double>::infinity()};
}

bool Geometry3D::CLinkedLine3D::isPointOnLine(const Geometry3D::CPoint3D &point) const noexcept {
    double parametric_x =
            (point.getX() - this->p_linked_point->getX()) / this->p_direction_vector->getX();
    double parametric_y =
            (point.getY() - this->p_linked_point->getY()) / this->p_direction_vector->getY();
    double parametric_z =
            (point.getZ() - this->p_linked_point->getZ()) / this->p_direction_vector->getZ();


    return isEqualDouble(parametric_x, parametric_y) && isEqualDouble(parametric_y, parametric_z);
}

double Geometry3D::CLinkedLine3D::getCoplanarCheckDeterminant(const Geometry3D::CLinkedLine3D &line) const noexcept {
    double v_x = this->p_direction_vector->getX();
    double v_y = this->p_direction_vector->getY();
    double v_z = this->p_direction_vector->getZ();

    double s_x = line.p_direction_vector->getX();
    double s_y = line.p_direction_vector->getY();
    double s_z = line.p_direction_vector->getZ();


    double p_x = line.p_linked_point->getX() - this->p_linked_point->getX();
    double p_y = line.p_linked_point->getY() - this->p_linked_point->getY();
    double p_z = line.p_linked_point->getZ() - this->p_linked_point->getZ();

    double first_expr = v_x * (s_y * p_z - p_y * s_z);
    double second_expr = s_x * (p_y * v_z - v_y * p_z);
    double third_expr = p_x * (v_y * s_z - s_y * v_z);

    return first_expr + second_expr + third_expr;
}

double Geometry3D::CLinkedLine3D::getLinePointX(double known_coordinate,
                                                Geometry3D::CLinkedLine3D::CoordinateName known_coordinate_name) const noexcept {
    if (known_coordinate_name == CoordinateName::Y) {
        double v_x = p_direction_vector->getX();
        double v_y = p_direction_vector->getY();

        double p_x = p_linked_point->getX();
        double p_y = p_linked_point->getY();

        return ((known_coordinate - p_y) * v_x / v_y) + p_x;
    }

    double v_x = p_direction_vector->getX();
    double v_z = p_direction_vector->getZ();

    double p_x = p_linked_point->getX();
    double p_z = p_linked_point->getZ();

    return ((known_coordinate - p_z) * v_x / v_z) + p_x;
}

double Geometry3D::CLinkedLine3D::getLinePointY(double known_coordinate,
                                                Geometry3D::CLinkedLine3D::CoordinateName known_coordinate_name) const noexcept {
    if (known_coordinate_name == CoordinateName::X) {
        double v_x = p_direction_vector->getX();
        double v_y = p_direction_vector->getY();

        double p_x = p_linked_point->getX();
        double p_y = p_linked_point->getY();

        return ((known_coordinate - p_x) * v_y / v_x) + p_y;
    }

    double v_y = p_direction_vector->getY();
    double v_z = p_direction_vector->getZ();

    double p_y = p_linked_point->getY();
    double p_z = p_linked_point->getZ();

    return ((known_coordinate - p_z) * v_y / v_z) + p_y;
}

double Geometry3D::CLinkedLine3D::getLinePointZ(double known_coordinate,
                                                Geometry3D::CLinkedLine3D::CoordinateName known_coordinate_name) const noexcept {
    if (known_coordinate_name == CoordinateName::X) {
        double v_x = p_direction_vector->getX();
        double v_z = p_direction_vector->getZ();

        double p_x = p_linked_point->getX();
        double p_z = p_linked_point->getZ();

        return ((known_coordinate - p_x) * v_z / v_x) + p_z;
    }

    double v_y = p_direction_vector->getY();
    double v_z = p_direction_vector->getZ();

    double p_y = p_linked_point->getY();
    double p_z = p_linked_point->getZ();

    return ((known_coordinate - p_y) * v_z / v_y) + p_z;
}

bool Geometry3D::CLinkedLine3D::isEqualDouble(double x, double y) noexcept {
    return std::fabs(x - y) < std::numeric_limits<double>::epsilon();
}
