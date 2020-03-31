#include "../../File2DProcessingTools/include/CVectorGraphicsData.hpp"

namespace File2DProcessingTools {

    void CVectorGraphicsData::addLineSegment(Geometry2D::CLineSegment2D cLineSegment2D) noexcept {
        line_segments2D.emplace_back(std::move(cLineSegment2D));
    }

    const std::vector<Geometry2D::CLineSegment2D> &CVectorGraphicsData::getLineSegments() const noexcept {
        return line_segments2D;
    }

}