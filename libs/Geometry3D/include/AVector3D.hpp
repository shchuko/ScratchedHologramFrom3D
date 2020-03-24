#pragma once

#include <cmath>
#include <limits>

namespace Geometry3D {
    /**
     * @author github.com/Tulesha
     */
    class AVector3D {
    private:
        static inline bool isEqualDouble(double x, double y) noexcept;

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
         * Get normalized coordinate X
         * @return Normalized coordinate X
         */
        virtual double getNormalizedX() const noexcept;

        /**
         * Get normalized coordinate Y
         * @return Normalized coordinate Y
         */
        virtual double getNormalizedY() const noexcept;

        /**
         * Get normalized coordinate Z
         * @return Normalized coordinate Z
         */
        virtual double getNormalizedZ() const noexcept;

        /**
         * Check collinear between two vectors
         * @param vector Vector in 3D
         * @return Collinear or not
         */
        bool isCollinear(const AVector3D &vector) const noexcept;

        /**
         * Get cos of angel between two vectors
         * @param vector Vector in 3D
         * @return Cos of angel between two vectors
         */
        double getAngleCos(const AVector3D &vector) const noexcept;

        virtual ~AVector3D() = 0;
    };

    inline AVector3D::~AVector3D() = default;
}
