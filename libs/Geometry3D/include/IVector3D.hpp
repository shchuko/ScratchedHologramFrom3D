#pragma once

namespace Geometry3D {
    /**
     * @author github.com/Tulesha
     */
    class IVector3D {
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
        virtual bool isCollinear(const IVector3D &vector3D) const noexcept = 0;

        /**
         * Get cos of angel between two vectors
         * @param vector3D Vector in 3D
         * @return Cos of angel between two vectors
         */
        virtual double getAngleCos(const IVector3D &vector3D) const noexcept = 0;

        virtual ~IVector3D() = 0;

    };

    inline IVector3D::~IVector3D() = default;
}
