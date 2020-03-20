#pragma once

#include "IVector3D.hpp"

namespace Geometry3D {
    /**
     * @author Tulesha
     */
    class CVector3D : public IVector3D{
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

    };

}
