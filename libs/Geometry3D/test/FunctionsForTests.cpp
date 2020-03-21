#include <gtest/gtest.h>
#include <CVector3D.hpp>

namespace Geometry3D {
    /**
     * Equals two doubles
     * @param x first double
     * @param y second double
     * @return result of conditions
     */
    inline bool is_equal_double(double x, double y) noexcept {
        return std::fabs(x - y) < std::numeric_limits<double>::epsilon();
    }

    /**
     * Check is two vectors collinear
     * @param cVector3D First vector
     * @param cVector3D1 Second vector
     * @return
     */
    bool IsCollinear(const AVector3D &cVector3D, const AVector3D &cVector3D1) noexcept {
        if (is_equal_double(cVector3D.getX(), 0.0) && is_equal_double(cVector3D1.getX(), 0.0) &&
            is_equal_double(cVector3D.getY(), 0.0) && is_equal_double(cVector3D1.getY(), 0.0) &&
            is_equal_double(cVector3D.getZ(), 0.0) && is_equal_double(cVector3D1.getZ(), 0.0)) {
            return true;
        } else if (is_equal_double(cVector3D.getX(), 0.0) && is_equal_double(cVector3D1.getX(), 0.0) &&
                   is_equal_double(cVector3D.getY(), 0.0) && is_equal_double(cVector3D1.getY(), 0.0)) {
            return true;
        } else if (is_equal_double(cVector3D.getX(), 0.0) && is_equal_double(cVector3D1.getX(), 0.0) &&
                   is_equal_double(cVector3D.getZ(), 0.0) && is_equal_double(cVector3D1.getZ(), 0.0)) {
            return true;
        } else if (is_equal_double(cVector3D.getY(), 0.0) && is_equal_double(cVector3D1.getY(), 0.0) &&
                   is_equal_double(cVector3D.getZ(), 0.0) && is_equal_double(cVector3D1.getZ(), 0.0)) {
            return true;
        } else if (is_equal_double(cVector3D.getX(), 0.0) && is_equal_double(cVector3D1.getX(), 0.0)) {
            return is_equal_double(cVector3D.getY() / cVector3D1.getY(), cVector3D.getZ() / cVector3D1.getZ());
        } else if (is_equal_double(cVector3D.getY(), 0.0) && is_equal_double(cVector3D1.getY(), 0.0)) {
            return is_equal_double(cVector3D.getX() / cVector3D1.getX(), cVector3D.getZ() / cVector3D1.getZ());
        } else if (is_equal_double(cVector3D.getZ(), 0.0) && is_equal_double(cVector3D1.getZ(), 0.0)) {
            return is_equal_double(cVector3D.getX() / cVector3D1.getX(), cVector3D.getY() / cVector3D1.getY());
        } else {
            return is_equal_double(cVector3D.getX() / cVector3D1.getX(), cVector3D.getY() / cVector3D1.getY()) &&
                   is_equal_double(cVector3D.getY() / cVector3D1.getY(), cVector3D.getZ() / cVector3D1.getZ());
        }
    }

    double getAngleCos(const AVector3D &vector3D, const AVector3D &vector3D1) noexcept {
        double numerator =
                vector3D.getX() * vector3D1.getX() + vector3D.getY() * vector3D1.getY() +
                vector3D.getZ() * vector3D1.getZ();
        double denominator = (sqrt(pow(vector3D.getX(), 2) + pow(vector3D.getY(), 2) + pow(vector3D.getZ(), 2)) +
                              sqrt((pow(vector3D1.getX(), 2) + pow(vector3D1.getY(), 2) + pow(vector3D1.getZ(), 2))));

        if (denominator != 0)
            return numerator / denominator;
        return 1;
    }

}
