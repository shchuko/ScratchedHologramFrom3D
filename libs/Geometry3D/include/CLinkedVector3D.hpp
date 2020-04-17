#pragma once

#include "CPoint3D.hpp"
#include "AVector3D.hpp"
#include "Geometry3DBase.hpp"
#include <cmath>

namespace Geometry3D {
    /**
     * @author github.com/Tulesha
     */
    class CLinkedVector3D : public AVector3D {
    private:
        const CPoint3D *point_begin = nullptr;
        const CPoint3D *point_end = nullptr;

    public:
        /**
         * Base constructor
         * @param point_begin Vector begin point
         * @param point_end Vector end point
         */
        CLinkedVector3D(const CPoint3D &_point_begin, const CPoint3D &_point_end) noexcept;

        /**
         * Copy constructor
         * @param vec vector to copy
         */
        CLinkedVector3D(const CLinkedVector3D &vec) noexcept = default;

        /**
         * Move constructor
         * @param vec vector to move
         */
        CLinkedVector3D(CLinkedVector3D &&vec) noexcept = default;


        /**
         * Copy assignment operator
         * @param vec vector to assign
         */
        CLinkedVector3D &operator=(const CLinkedVector3D &vec) noexcept = default;

        /**
         * Move assignment operator
         * @param vec vector to assing
         */
        CLinkedVector3D &operator=(CLinkedVector3D &&vec) noexcept = default;

        double getX() const noexcept override;

        double getY() const noexcept override;

        double getZ() const noexcept override;

        double getLen() const noexcept override;

        /**
         * Set new begin point
         * @param new_point_begin Lvalue reference to begin point
         */
        void setPointBegin(const CPoint3D &new_point_begin) noexcept;

        /**
         * Set new end point
         * @param new_point_end Reference to end point
         */
        void setPointEnd(const CPoint3D &new_point_end) noexcept;

        const CPoint3D& getPointBegin() const noexcept;

        const CPoint3D& getPointEnd() const  noexcept;

        ~CLinkedVector3D() override = default;

    private:
        /**
        * Set new begin point Rvalue. Cannot be used.
        * @param new_point_begin Rvalue reference to begin point
        */
        void setPointBegin(CPoint3D&& new_point_begin) const noexcept;

        /**
         * Set new end point. Cannot be used.
         * @param new_point_end Rvalue reference to end point
         */
        void setPointEnd(CPoint3D&& new_point_end) const noexcept;

        /**
         * Copy constructor RValue. Cannot be used.
         * @param _point_begin Rvalue reference to begin point
         * @param _point_end Rvalue reference to end point
         */
        CLinkedVector3D(CPoint3D &&_point_begin, CPoint3D &&_point_end);
    };
}
