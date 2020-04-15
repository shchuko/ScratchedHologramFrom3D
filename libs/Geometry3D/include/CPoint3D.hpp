#pragma once

#include "Geometry3DBase.hpp"
#include "AVector3D.hpp"

namespace Geometry3D {

    /**
     * @author github.com/Tulesha
     */
    class CPoint3D {
    private:
        double x = 0.0;
        double y = 0.0;
        double z = 0.0;
        bool marked = false;

    public:
        /**
         * Base constructor
         */
        CPoint3D() = default;

        /**
         * Copy constructor Lvalue
         * @param cPoint3D Point in 3D
         */
        CPoint3D(const CPoint3D &point) noexcept = default;

        /**
         * Copy constructor Rvalue
         * @param cPoint3D Point int 3D
         */
        CPoint3D(CPoint3D &&point) noexcept = default;

        /**
         * Constructor with parameters of coordinates
         * @param x Coordinate X
         * @param y Coordinate Y
         * @param z Coordinate Z
         */
        CPoint3D(double x, double y, double z) noexcept;

        /**
         * Get x coordinate
         * @return Coordinate X
         */
        double getX() const noexcept;

        /**
         * Get y coordinate
         * @return Coordinate Y
         */
        double getY() const noexcept;

        /**
         * Get z coordinate
         * @return Coordinate Z
         */
        double getZ() const noexcept;

        /**
         * Move current point by vector
         * @param vector Moving vector
         */
        void move(const AVector3D &vector) noexcept;

        /**
         * Create copy of current point and move it by vector
         * @param vector Moving vector
         * @return New moved point object
         */
        CPoint3D moveCopy(const AVector3D &vector) const noexcept;

        /**
         * Copy assigment operator
         * @param point Point to copy
         * @return Reference to *this object
         */
        CPoint3D &operator=(const CPoint3D &point) noexcept = default;

        /**
         * Copy assigment operator
         * @param point Point to copy
         * @return Reference to *this object
         */
        CPoint3D &operator=(CPoint3D &&point) noexcept = default;

        /**
         * Get distance between two points
         * @param point Point in 3D, LValue reference
         * @return distance between two points
         */
        double getDistance(const CPoint3D &point) const noexcept;

        /**
         * Get distance between two points
         * @param point Point in 3D, RValue reference
         * @return distance between two points
         */
        double getDistance(CPoint3D &&point) const noexcept;

        /**
         * Assign new value to X coordinate
         * @param x New X value
         */
        void setX(double x);

        /**
         * Assign new value to Y coordinate
         * @param y New Y value
         */
        void setY(double y);

        /**
         * Assign new value to Z coordinate
         * @param z New Z value
         */
        void setZ(double z);

        /**
         * Get marked flag
         * @return Marked flag
         */
        bool isMarked() const;

        /**
         * Set marked flag
         * @param marked Marked flag value
         */
        void setMarked(bool marked);
    };
}
