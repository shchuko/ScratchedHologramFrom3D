#pragma once

namespace Geometry3D {

    /**
     * @author Tulesha 2020
     */
    class CPoint3D {
    private:
        double x = 0.0;
        double y = 0.0;
        double z = 0.0;

    public:
        /**
         * Base constructor
         */
        CPoint3D() = default;

        /**
         * Copy constructor Lvalue
         * @param cPoint3D Point in 3D
         */
        CPoint3D(const CPoint3D& cPoint3D) noexcept;

        /**
         * Copy constructor Rvalue
         * @param cPoint3D Point int 3D
         */
        CPoint3D(CPoint3D&& cPoint3D) noexcept;

        /**
         * Constructor with parameters of coordinates
         * @param x Coordinate X
         * @param y Coordinate Y
         * @param z Coordinate Z
         */
        CPoint3D(double x, double y, double z) noexcept;

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
         * @return Coordinate Z
         */
        double getZ() const noexcept;
    };
}
