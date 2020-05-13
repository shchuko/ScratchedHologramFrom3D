
#include <CPath.hpp>

namespace File2DProcessingTools {

    void CPath::setColor(CVectorGraphicsData::CColor_T &color) noexcept {
        _color = color;
    }

    CPath::CPath() noexcept {
        _width = 1;;
        _smooth = false;
        _isCycled = false;
    }

    CPath::CPath(unsigned int width_px, CVectorGraphicsData::CColor_T &color, bool smooth) noexcept {
        _width = width_px;
        _color = color;
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
        std::vector<CPath> paths;
        bool createNextPath = true;
        for (auto &point : CPoints2D) {
            if (!std::isnormal(point.getX()) || !std::isnormal(point.getY())) {
                createNextPath = true;
            } else {
                if (createNextPath) {
                    paths.emplace_back(this->_width, this->_color, this->_smooth);
                    createNextPath = false;
                }
                paths.back().appendPoint(point);
            }
        }
        return paths;
    }

    const std::vector<Geometry2D::CPoint2D> &CPath::getPoints() const noexcept {
        return CPoints2D;
    }

    void CPath::updateCycled() noexcept {

        _isCycled = CPoints2D.size() > 1 && CPoints2D[0].getX() == CPoints2D[CPoints2D.size() - 1].getX() &&
                    CPoints2D[0].getY() == CPoints2D[CPoints2D.size() - 1].getY();
        for (auto &point : CPoints2D) {
            if (!std::isnormal(point.getX()) || !std::isnormal(point.getY())) {
                _isCycled = false;
                break;
            }
        }
    }

    bool CPath::isCycled() const noexcept {
        return _isCycled;
    }

    void CPath::appendPath(CPath &cPath) noexcept {
        std::vector<Geometry2D::CPoint2D> points2D = cPath.getPoints();
        for(auto & i : points2D) {
            this->appendPoint(i);
        }
    }
}