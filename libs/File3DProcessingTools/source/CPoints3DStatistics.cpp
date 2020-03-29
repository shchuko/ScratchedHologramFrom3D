#include "CPoints3DStatistics.hpp"

namespace File3DProcessingTools {
    double CPoints3DStatistics::getMaxX() const noexcept {
        return max_x;
    }

    double CPoints3DStatistics::getMinX() const noexcept {
        return min_x;
    }

    double CPoints3DStatistics::getMaxY() const noexcept {
        return max_y;
    }

    double CPoints3DStatistics::getMinY() const noexcept {
        return min_y;
    }

    double CPoints3DStatistics::getMaxZ() const noexcept {
        return max_z;
    }

    double CPoints3DStatistics::getMinZ() const noexcept {
        return min_z;
    }

    void CPoints3DStatistics::fillMaxMinValues(const Geometry3D::CPoint3D &point) {
        double x = point.getX();
        double y = point.getY();
        double z = point.getZ();

        if (x < min_x)
            min_x = x;
        if (x >= max_x)
            max_x = x;

        if (y < min_y)
            min_y = y;
        if (y >= max_y)
            max_y = y;

        if (z < min_z)
            min_z = z;
        if (z >= max_z)
            max_z = z;
    }
}
