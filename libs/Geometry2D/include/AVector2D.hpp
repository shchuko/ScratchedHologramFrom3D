#pragma once

#include <Geometry2DBase.hpp>
#include <cmath>
#include <limits>

namespace Geometry2D {
    /**
     * @author github.com/Tulesha
     */
    class AVector2D {
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
         * Get length
         * @return length
         */
        virtual double getLen() const noexcept = 0;

        /**
         * Check collinear between two vectors
         * @param vector Vector in 2D
         * @return Collinear or not
         */
        bool isCollinear(const AVector2D &vector) const noexcept;

        /**
         * Get cos of angel between two vectors
         * @param vector Vector in 2D
         * @return Cos of angel between two vectors
         */
        double getAngleCos(const AVector2D &vector) const noexcept;

        virtual ~AVector2D() = 0;

        AVector2D() noexcept = default;

        AVector2D(const AVector2D &vec) = default;

        AVector2D(AVector2D &&vec) = default;

        AVector2D &operator=(const AVector2D &vec) = default;

        AVector2D &operator=(AVector2D &&vec) = default;

    };

    inline AVector2D::~AVector2D() = default;
}