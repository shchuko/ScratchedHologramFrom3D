#pragma once

#include "IVector3D.hpp"
#include <cmath>

namespace Geometry3D {
    /**
     * @author github.com/Tulesha
     */
    class CVector3D : public IVector3D {
    private:
        double x = 0.0;
        double y = 0.0;
        double z = 0.0;
    public:
        /**
         * Base constructor
         */
        CVector3D() = default;

        /**
         * Copy constructor Lvalue
         * @param cVector3D Vector in 3D
         */
        CVector3D(const CVector3D &cVector3D) noexcept;

        /**
         * Copy constructor Rvalue
         * @param cVector3D Vector in 3D
         */
        CVector3D(CVector3D &&cVector3D) noexcept;

        /**
         * Constructor with parameters of coordinates
         * @param x Coordinate X
         * @param y Coordinate Y
         * @param z Coordinate Z
         */
        CVector3D(double x, double y, double z);

        double getX() const noexcept override;

        double getY() const noexcept override;

        double getZ() const noexcept override;

        double getLen() const noexcept override;

        bool isCollinear(const IVector3D &vector3D) const noexcept override;

        double getAngleCos(const IVector3D &vector3D) const noexcept override;

        /**
         * Overloaded operator +
         * @return new CVector3D
         */
        CVector3D operator+() const;

        /**
        * Overloaded operator -
        * @return new CVector3D
        */
        CVector3D operator-() const;

        /**
         * Overloaded operator +=
         * @param iVector3D Vector in 3D
         * @return new CVector3D
         */
        CVector3D &operator+=(const IVector3D &iVector3D);

        /**
         * Overloaded operator -=
         * @param iVector3D Vector int 3D
         * @return new CVector3D
         */
        CVector3D &operator-=(const IVector3D &iVector3D);

        ~CVector3D() override = default;
    };
}
