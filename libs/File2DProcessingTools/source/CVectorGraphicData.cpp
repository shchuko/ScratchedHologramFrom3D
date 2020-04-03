#include "../../File2DProcessingTools/include/CVectorGraphicsData.hpp"

namespace File2DProcessingTools {

    void CVectorGraphicsData::addLineSegments(Geometry2D::CLineSegment2D line_segment) noexcept {
        checkRange(line_segment);
        _data.emplace_back(line_segment);
    }

    const std::vector<Geometry2D::CLineSegment2D> &CVectorGraphicsData::getLineSegments() const noexcept {
        return _data;
    }

    void CVectorGraphicsData::checkRange(const Geometry2D::CLineSegment2D &line_segment) {
        if (line_segment.getFirstPoint().getX() < min_x) {
            min_x = line_segment.getFirstPoint().getX();
        }
        if (line_segment.getFirstPoint().getY() < min_y) {
            min_y = line_segment.getFirstPoint().getY();
        }
        if (line_segment.getFirstPoint().getX() > max_x) {
            max_x = line_segment.getFirstPoint().getX();
        }
        if (line_segment.getFirstPoint().getY() > max_y) {
            max_y = line_segment.getFirstPoint().getY();
        }
        if (line_segment.getSecondPoint().getX() < min_x) {
            min_x = line_segment.getSecondPoint().getX();
        }
        if (line_segment.getSecondPoint().getY() < min_y) {
            min_y = line_segment.getSecondPoint().getY();
        }
        if (line_segment.getSecondPoint().getX() > max_x) {
            max_x = line_segment.getSecondPoint().getX();
        }
        if (line_segment.getSecondPoint().getY() > max_y) {
            max_y = line_segment.getSecondPoint().getY();
        }

    }

    double CVectorGraphicsData::getMaxX() const {
        return max_x;
    }

    double CVectorGraphicsData::getMaxY() const {
        return max_y;
    }

    double CVectorGraphicsData::getMinX() const {
        return min_x;
    }

    double CVectorGraphicsData::getMinY() const {
        return min_y;
    }

}