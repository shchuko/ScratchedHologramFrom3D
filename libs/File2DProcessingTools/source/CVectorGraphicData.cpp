#include "../../File2DProcessingTools/include/CVectorGraphicsData.hpp"

namespace File2DProcessingTools {

    void CVectorGraphicsData::addLineSegments(Geometry2D::CLineSegment2D line_segment) noexcept {
        _data.emplace_back(line_segment);
    }

    const std::vector<Geometry2D::CLineSegment2D> &CVectorGraphicsData::getLineSegments() const noexcept {
        return _data;
    }

}