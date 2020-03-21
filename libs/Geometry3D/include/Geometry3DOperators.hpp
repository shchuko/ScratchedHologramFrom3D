#pragma once

#include "AVector3D.hpp"
#include "CVector3D.hpp"
#include "CLinkedVector3D.hpp"

namespace Geometry3D {
    /**
     * Overloaded operator + which addition two vectors
     * @param left Vector in 3D
     * @param right Vector in 3D
     * @return new CVector3D
     */
    CVector3D operator+(const AVector3D &left, const AVector3D &right);

    /**
     * Overloaded operator - which subtraction two vectors
     * @param left Vector in 3D
     * @param right Vector in 3D
     * @return new CVector3D
     */
    CVector3D operator-(const AVector3D &left, const AVector3D &right);
}
