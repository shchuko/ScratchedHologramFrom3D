#include "../../File2DProcessingTools/include/CVectorGraphicsData.hpp"

namespace File2DProcessingTools {

    void CVectorGraphicsData::addLineSegment(Geometry2D::CLineSegment2D data) noexcept {
        _data.emplace_back(std::move(data));
    }

    const std::vector<Geometry2D::CLineSegment2D> &CVectorGraphicsData::getLineSegments() const noexcept {
        return _data;
    }

}