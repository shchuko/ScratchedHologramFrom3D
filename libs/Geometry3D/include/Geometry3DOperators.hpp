#pragma once

#include <cmath>
#include <limits>

#include "Geometry3DBase.hpp"
#include "AVector3D.hpp"
#include "CVector3D.hpp"
#include "CLinkedVector3D.hpp"
#include "CLinkedLine3D.hpp"


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

    /**
     * Geometry3D::CPoint3D equals operator
     * @param first First object
     * @param second Second object
     * @return True if object are equal, else if not
     */
    bool operator==(const CPoint3D &first, const CPoint3D &second);

    /**
     * Geometry3D::AVector3D equals operator
     * @param first First object
     * @param second Second object
     * @return True if object are equal, else if not
     */
    bool operator==(const AVector3D &first, const AVector3D &second);

    /**
     * Geometry3D::CLinkedLine3D equals operator
     * @param first First line
     * @param second Second line
     * @return True if lines are OVERLAP
     */
    bool operator==(const CLinkedLine3D &first, const CLinkedLine3D &second);
}
