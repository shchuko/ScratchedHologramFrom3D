#pragma once

#include <vector>
#include "CVectorGraphicsData.hpp"

namespace File2DProcessingTools {

    class CPath {
    private:
        unsigned int _width;
        CVectorGraphicsData::CColor_T _color;
        bool _smooth;
        bool _isCycled;
        std::vector<Geometry2D::CPoint2D> CPoints2D;
    public:
        CPath() noexcept; // Default width 1px, default color BLACK, smoth=false
        CPath(unsigned int width_px, CVectorGraphicsData::CColor_T &color, bool smooth) noexcept;
        void setColor(CVectorGraphicsData::CColor_T &color)  noexcept; // цвет
        CVectorGraphicsData::CColor_T getColor() const noexcept;
        void setWidth(unsigned int width_px) noexcept; // толщина в пикселях
        unsigned int getWidth() const noexcept;
        void setSmooth(bool flag) noexcept; // сглаживание, атрибут для обработки в дальнейшем
        bool isSmooth() const noexcept;

        // Добавляет следующую точку к линии
        // Если линия имеет одну из координат NaN - разрыв в линии, распознается методом toSeparatedPaths()
        void appendPoint(const Geometry2D::CPoint2D& point) noexcept;
        const std::vector<Geometry2D::CPoint2D>& getPoints() const noexcept;

        // Разбивает линию на несколько линий, разрыв определяется точкой с NaN-координатой или циклом
        std::vector<CPath> toSeparatedPaths();

        // Проверяет, зациклена ли кривая. Если да - отмечает, что есть цикл, чтоб не дублировать точку начала/конца при записи в файл
        void updateCycled() noexcept;
        bool isCycled() const noexcept;

    };

}