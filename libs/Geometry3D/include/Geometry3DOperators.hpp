#pragma once

#include "IVector3D.hpp"
#include "CVector3D.hpp"
//#include "CLinkedVector3D.hpp"

namespace Geometry3D {
    /**
     * Overloaded operator + which addition two vectors
     * @param left Vector in 3D
     * @param right Vector in 3D
     * @return new CVector3D
     */
    CVector3D operator+(const IVector3D& left, const IVector3D& right);

    /**
     * Overloaded operator - which subtraction two vectors
     * @param left Vector in 3D
     * @param right Vector in 3D
     * @return new CVector3D
     */
    CVector3D operator-(const IVector3D& left, const IVector3D& right);
}
