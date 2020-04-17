#pragma once

#include <limits>
#include <algorithm>

namespace Geometry3D {

#define LIB_GEOMETRY3D_EPSILON 0.0000001

    template<typename FLOATING_POINT_T>
    bool
    isEqualDouble(FLOATING_POINT_T a, FLOATING_POINT_T b, FLOATING_POINT_T epsilon = LIB_GEOMETRY3D_EPSILON) noexcept {
        return std::abs(a - b) < epsilon;
    }

}
