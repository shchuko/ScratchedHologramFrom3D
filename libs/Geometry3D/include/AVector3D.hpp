#pragma once

#include <cmath>
#include <limits>

namespace Geometry3D {
    /**
     * @author github.com/Tulesha
     */
    class AVector3D {
    private:
        inline bool is_equal_double(double x, double y) const noexcept;

    public:
        /**
         * Get x coordinate
         * @return Coordinate X
         */
        virtual double getX() const noexcept = 0;

        /**
         * Get y coordinate
         * @return Coordinate Y
         */
        virtual double getY() const noexcept = 0;

        /**
         * Get z coordinate
         * @return Coordinate Z
         */
        virtual double getZ() const noexcept = 0;

        /**
         * Get length
         * @return length
         */
        virtual double getLen() const noexcept = 0;

        /**
         * Check collinear between two vectors
         * @param vector3D Vector in 3D
         * @return Collinear or not
         */
        bool isCollinear(const AVector3D &vector3D) const noexcept;

        /**
         * Get cos of angel between two vectors
         * @param vector3D Vector in 3D
         * @return Cos of angel between two vectors
         */
        double getAngleCos(const AVector3D &vector3D) const noexcept;

        virtual ~AVector3D() = 0;
    };

    inline AVector3D::~AVector3D() = default;
}
