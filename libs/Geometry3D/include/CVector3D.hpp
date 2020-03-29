#pragma once

#include <AVector3D.hpp>
#include <cmath>

namespace Geometry3D {
    /**
     * @author github.com/Tulesha
     */
    class CVector3D : public AVector3D {
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
         * @param vector Vector in 3D
         */
        CVector3D(const CVector3D &vector) noexcept;

        /**
         * Copy constructor Rvalue
         * @param vector Vector in 3D
         */
        CVector3D(CVector3D &&vector) noexcept;

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

        /**
         * Assign new value to X coordinate
         * @param x New X value
         */
        void setX(double x);

        /**
         * Assign new value to Y coordinate
         * @param y New Y value
         */
        void setY(double y);

        /**
         * Assign new value to Z coordinate
         * @param z New Z value
         */
        void setZ(double z);

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
         * @param vector Vector in 3D
         * @return new CVector3D
         */
        CVector3D &operator+=(const AVector3D &vector);

        /**
         * Overloaded operator -=
         * @param vector Vector int 3D
         * @return new CVector3D
         */
        CVector3D &operator-=(const AVector3D &vector);

        ~CVector3D() override = default;
    };
}
