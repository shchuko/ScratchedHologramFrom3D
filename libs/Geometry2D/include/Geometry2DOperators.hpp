#pragma once

#include <AVector2D.hpp>
#include <CVector2D.hpp>

namespace Geometry2D {
    /**
     * Overloaded operator + which addition two vectors
     * @param left Vector in 2D
     * @param right Vector in 2D
     * @return new CVector2D
     */
    CVector2D operator +(const AVector2D &left, const AVector2D &right);

    /**
     * Overloaded operator - which addition two vectors
     * @param left Vector in 2D
     * @param right Vector in 2D
     * @return new CVector2D
     */
    CVector2D operator -(const AVector2D &left, const AVector2D &right);
}