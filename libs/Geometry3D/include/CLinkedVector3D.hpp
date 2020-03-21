#pragma once

#include <CPoint3D.hpp>
#include "AVector3D.hpp"
#include <cmath>

namespace Geometry3D {
    /**
     * @author github.com/Tulesha
     */
    class CLinkedVector3D : public AVector3D {
    private:
        const CPoint3D &point_begin;
        const CPoint3D &point_end;
    public:
        /**
         * Copy constructor Lvalue
         * @param point_begin First point
         * @param point_end Second point
         */
        CLinkedVector3D(const CPoint3D &_point_begin, const CPoint3D &_point_end) noexcept;

        double getX() const noexcept override;

        double getY() const noexcept override;

        double getZ() const noexcept override;

        double getLen() const noexcept override;

        ~CLinkedVector3D() override = default;
    };
}