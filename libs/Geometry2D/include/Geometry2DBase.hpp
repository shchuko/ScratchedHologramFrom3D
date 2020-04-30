#pragma once

#include <cmath>

namespace Geometry2D {

#define LIB_GEOMETRY2D_EPSILON 0.0000001

    template<typename FLOATING_POINT_T>
    bool
    isEqualDouble(FLOATING_POINT_T a, FLOATING_POINT_T b, FLOATING_POINT_T epsilon = LIB_GEOMETRY2D_EPSILON) noexcept {
        return std::fabs(a - b) < epsilon;
    }

}
