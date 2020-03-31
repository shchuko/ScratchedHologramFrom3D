#pragma once

#include <AVector3D.hpp>
#include <CPoint3D.hpp>
#include <CVector3D.hpp>

namespace Geometry3D {
    /**
     * @author github.com/Tulesha
     */
    class CLinkedLine3D {
    private:
        const AVector3D *p_direction_vector = nullptr;
        const CPoint3D *p_linked_point = nullptr;

    public:
        /**
         * This class describes all types of straight lines.
         * @author @author github.com/Tulesha
         */
        enum class RelationType {
            SKEW, CROSSING, PARALLEL, OVERLAP
        };

        /**
         * Name of coordinates in 3D.
         */
        enum class CoordinateName {
            X, Y, Z
        };

        /**
         * Constructor Lvalue
         * @param direction_vector Input direction vector.
         * @param linked_point Input linked point.
         */
        CLinkedLine3D(const AVector3D &direction_vector, const CPoint3D &linked_point) noexcept;

        /**
         * Copy constructor
         * @param line Line to copy
         */
        CLinkedLine3D(const CLinkedLine3D &line) noexcept = default;

        /**
         * Move constructor
         * @param line Line to move
         */
        CLinkedLine3D(CLinkedLine3D &&line) noexcept = default;

        /**
         * Copy assignment operator
         * @param line to assign
         * @return Ref to *this
         */
        CLinkedLine3D &operator=(const CLinkedLine3D &line) noexcept = default;

        /**
         * Move assignment operator
         * @param line to assign
         * @return Ref to *this
         */
        CLinkedLine3D &operator=(CLinkedLine3D &&line) noexcept = default;

        /**
         * Set direction vector.
         * @param direction_vector Input direction vector.
         */
        void setDirectionVector(const AVector3D &direction_vector) noexcept;

        /**
         * Set linked point.
         * @param linked_point Input linked point.
         */
        void setLinkedPoint(const CPoint3D &linked_point) noexcept;

        /**
         * Get direction vector.
         * @return Direction vector.
         */
        const AVector3D &getDirectionVector() const noexcept;

        /**
         * Get linked point.
         * @return Linked point.
         */
        const CPoint3D &getLinkedPoint() const noexcept;

        /**
         * Get relation type between two lines. Possible variants (SKEW, CROSSING, PARALLEL, OVERLAP).
         * @param line Input line.
         * @return Relation between two lines.
         */
        RelationType getRelationType(const CLinkedLine3D &line) const noexcept;

        /**
         * Get crossing point between two lines. If lines is CROSSING (double double double), if lines is PARALLEL or SKEW (nan, nan, nan), if lines is OVERLAP (inf, inf, inf)
         * @param line Input line.
         * @return Crossing point.
         */
        CPoint3D getCrossingPoint(const CLinkedLine3D &line) const noexcept;

        /**
         * Check is point on Line.
         * @param point Input line.
         * @return True of false.
         */
        bool isPointOnLine(const CPoint3D &point) const noexcept;

        /**
         * Get line point coordinate X, knowing only one of the coordinates.
         * @param known_coordinate Known coordinate.
         * @param known_coordinate_name Name of coordinate(Y or Z).
         * @return Coordinate X of point.
         */
        double getLinePointX(double known_coordinate, CoordinateName known_coordinate_name) const noexcept;

        /**
         * Get line point coordinate Y, knowing only one of the coordinates.
         * @param known_coordinate Known coordinate.
         * @param known_coordinate_name Name of coordinate(X or Z).
         * @return Coordinate Y of point.
         */
        double getLinePointY(double known_coordinate, CoordinateName known_coordinate_name) const noexcept;

        /**
         * Get line point coordinate Z, knowing only one of the coordinates.
         * @param known_coordinate Known coordinate.
         * @param known_coordinate_name Name of coordinate(X or Y).
         * @return Coordinate Z of point.
         */
        double getLinePointZ(double known_coordinate, CoordinateName known_coordinate_name) const noexcept;

    private:
        /**
         * Constructor RValue. Cannot be used.
         * @param direction_vector Input direction vector.
         * @param linked_point Input linked point.
         */
        CLinkedLine3D(AVector3D &&direction_vector, CPoint3D &&linked_point) noexcept;

        /**
         * Set direction vector RValue. Cannot be used.
         * @param direction_vector Input direction vector.
         */
        void setDirectionVector(AVector3D &&direction_vector) noexcept;

        /**
         * Set linked point RValue. Cannot be used.
         * @param linked_point Input linked point.
         */
        void setLinkedPoint(CPoint3D &&linked_point) noexcept;

        /**
         * Get determinant for check coplanar of two lines.
         * @param line Input line.
         * @return Determinant.
         */
        double getCoplanarCheckDeterminant(const CLinkedLine3D &line) const noexcept;

        /**
         * Check equals of two doubles.
         * @param x Input X.
         * @param y Input Y.
         * @return True of false.
         */
        static inline bool isEqualDouble(double x, double y) noexcept;
    };
}
