#pragma once

#include <AVector2D.hpp>
#include <cmath>

namespace Geometry2D {
    /**
     * @author github.com/Tulesha
     */
    class CVector2D : public AVector2D {
    private:
        double x = 0.0;
        double y = 0.0;
    public:
        /**
         * Base constructor
         */
        CVector2D() = default;

        /**
         * Constructor with parameters of coordinates
         * @param x Coordinate X
         * @param y Coordinate Y
         */
        CVector2D(double x, double y);

        /**
         * Copy constructor
         * @param vector Vector in 2D
         */
        CVector2D(const CVector2D &vector) noexcept = default;

        /**
         * Move constructor
         * @param vector Vector in 2D
         */
        CVector2D(CVector2D&& vector) noexcept = default;

        /**
         * Copy assignment operator
         * @param vector Vector in 2D
         */
        CVector2D &operator=(const CVector2D &vector) noexcept = default;

        /**
         * Move assignment operator
         * @param vector Vector in 2D
         */
        CVector2D &operator=(CVector2D&& vector) noexcept = default;


        double getX() const noexcept override;

        double getY() const noexcept override;

        double getLen() const noexcept override;

        /**
         * Overloaded operator +
         * @return new CVector2D
         */
        CVector2D operator+() const;

        /**
         * Overloaded operator -
         * @return new CVector2D
         */
        CVector2D operator-() const;

        /**
         * Overloaded operator +=
         * @param vector Vector in 2D
         * @return new CVector2D
         */
        CVector2D &operator+=(const AVector2D &vector);

        /**
         * Overloaded operator -=
         * @param vector Vector in 2D
         * @return new CVector2D
         */
        CVector2D &operator-=(const AVector2D &vector);

        ~CVector2D() override = default;
    };
}
