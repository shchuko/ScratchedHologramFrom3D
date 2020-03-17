#pragma once


namespace Geometry3D {

    class CVector3D {
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
        CVector3D(const CVector3D& cVector3D) noexcept;

        /**
         * Copy constructor Rvalue
         * @param cVector3D Vector in 3D
         */
        CVector3D(CVector3D&& cVector3D) noexcept;

        /**
         * Constructor with parameters of coordinates
         * @param x Coordinate X
         * @param y Coordinate Y
         * @param z Coordinate Z
         */
        CVector3D(double x, double y, double z);

        /**
         * Get x coordinate
         * @return Coordinate X
         */
        double getX() const noexcept;

        /**
         * Get y coordinate
         * @return Coordinate Y
         */
        double getY() const noexcept;

        /**
         * Get z coordinate
         * @return Coordinte Z
         */
        double getZ() const noexcept;

        /**
         * Get length of 3D vector
         * @return length of 3D vector
         */
        double getLen() const noexcept;


    };

}
