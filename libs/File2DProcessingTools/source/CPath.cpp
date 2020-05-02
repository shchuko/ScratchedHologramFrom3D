
#include <CPath.hpp>

namespace File2DProcessingTools {

    void CPath::setColor(CVectorGraphicsData::CColor_T &color) noexcept {
        _color = color;
    }

    CPath::CPath() noexcept {
        _width = 1;
        _color.setColor(CVectorGraphicsData::CColor_T::COLOR::BLACK);
        _smooth = false;
        _isCycled = false;
    }

    CPath::CPath(unsigned int width_px, CVectorGraphicsData::CColor_T &color, bool smooth) noexcept {
        _width = width_px;
        _color.setColor(color.getRGBStr());
        _smooth = smooth;
        _isCycled = false;
    }

    CVectorGraphicsData::CColor_T CPath::getColor() const noexcept {
        return _color;
    }

    void CPath::setWidth(unsigned int width_px) noexcept {
        _width = width_px;
    }

    unsigned int CPath::getWidth() const noexcept {
        return _width;
    }

    void CPath::setSmooth(bool flag) noexcept {
        _smooth = flag;
    }

    bool CPath::isSmooth() const noexcept {
        return _smooth;
    }

    void CPath::appendPoint(const Geometry2D::CPoint2D &point) noexcept {
        CPoints2D.emplace_back(point);
    }

    std::vector<CPath> CPath::toSeparatedPaths() {
        std::vector<CPath> CPaths;
        unsigned int number_of_paths = 0;
        unsigned int size_of_current_path = 0;
        for (auto path : CPoints2D) {
            if ((path.getX() == std::numeric_limits<double>::quiet_NaN() ||
            path.getY() == std::numeric_limits<double>::quiet_NaN()) && size_of_current_path != 0){
                CPaths.resize(++number_of_paths);
                size_of_current_path = 0;
            } else {
                CPaths[number_of_paths].appendPoint(path);
                ++size_of_current_path;
            }
        }
        return CPaths;
    }

    const std::vector<Geometry2D::CPoint2D> &CPath::getPoints() const noexcept {
        return CPoints2D;
    }

    void CPath::updateCycled() noexcept {
        _isCycled = CPoints2D.size() > 1 && CPoints2D[0].getX() == CPoints2D[CPoints2D.size() - 1].getX() &&
                    CPoints2D[0].getY() == CPoints2D[CPoints2D.size() - 1].getY();
    }

    bool CPath::isCycled() const noexcept {
        return _isCycled;
    }
}