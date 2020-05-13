#pragma once

#include <AVector2D.hpp>
#include <CVector2D.hpp>
#include <CPoint2D.hpp>

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


    /**
     * Geometry3D::CPoint2D equals operator
     * @param first First object
     * @param second Second object
     * @return True if object are equal, else if not
     */
    bool operator==(const CPoint2D &first, const CPoint2D &second);

    /**
     * Geometry3D::AVector2D equals operator
     * @param first First object
     * @param second Second object
     * @return True if object are equal, else if not
     */
    bool operator==(const AVector2D &first, const AVector2D &second);
}