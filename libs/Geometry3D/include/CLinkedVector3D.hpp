#pragma once

#include <CPoint3D.hpp>
#include "IVector3D.hpp"
#include <cmath>

namespace Geometry3D {
    /**
     * @author github.com/Tulesha
     */
    class CLinkedVector3D : public IVector3D {
    private:
        CPoint3D &point_begin;
        CPoint3D &point_end;
    public:
        /**
         * Copy constructor Lvalue
         * @param point_begin First point
         * @param point_end Second point
         */
        CLinkedVector3D(const CPoint3D& point_begin, const CPoint3D& point_end) noexcept;

        /**
         * Copy constructor Rvalue
         * @param point_begin First point
         * @param point_end Second point
         */
        CLinkedVector3D(const CPoint3D&& point_begin, const CPoint3D&& point_end) noexcept;

        double getX() const noexcept override;

        double getY() const noexcept override;

        double getZ() const noexcept override;

        double getLen() const noexcept override;

        bool isCollinear(const IVector3D &vector3D) const noexcept override;

        double getAngleCos(const IVector3D &vector3D) const noexcept override;

        CLinkedVector3D operator+()const;

        CLinkedVector3D operator-()const;

        CLinkedVector3D&operator+=(const IVector3D& iVector3D);

        CLinkedVector3D&operator-=(const IVector3D& iVector3D);
        ~CLinkedVector3D() override = default;
    };
}