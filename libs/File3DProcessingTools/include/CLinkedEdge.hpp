#pragma once

#include <CPoint3D.hpp>
#include <CLinkedVector3D.hpp>
#include <CLinkedLine3D.hpp>


#include <cmath>
#include <limits>


namespace File3DProcessingTools {
    /**
     * @author Vladislav Yaroshchuk, github.com/shchuko
     */
    class CLinkedEdge {
    private:
        Geometry3D::CLinkedVector3D linked_vector;
        Geometry3D::CLinkedLine3D linked_line;

    public:
        /**
         * Create new CEdge3D object
         * @param _point_begin Edge begin point
         * @param _point_end Edge end point
         */
        CLinkedEdge(const Geometry3D::CPoint3D &_point_begin, const Geometry3D::CPoint3D &_point_end)
                : linked_vector{_point_begin, _point_end}, linked_line{linked_vector, _point_begin} {}

        /**
         * Get linked line
         * @return Linked line the edge is part of
         */
        const Geometry3D::CLinkedLine3D &getLinkedLine() const noexcept;

        /**
         * Get linked to edge's line direction vector
         * @return Linked vector, edge's line direction vector
         */
        const Geometry3D::CLinkedVector3D &getLineLinkedVector() const noexcept;


        /**
         * Check is point lays on edge
         * @param point Point to check
         * @return True if point lays on edge, false if not
         */
        bool isPointOnEdge(const Geometry3D::CPoint3D &point) const noexcept;

        /**
         * Check is point lays on edge
         * @param point Point to check
         * @return True if point lays on edge, false if not
         */
        bool isPointOnEdge(Geometry3D::CPoint3D &&point) const noexcept;

        /**
         * Get point of edge and line crossing
         * @param line Line object
         * @return Point object if crossing exists, {NaN, NaN, NaN} if not, {INF, INF, INF} if there's overlap line&edge
         */
        Geometry3D::CPoint3D getLineCrossingPoint(const Geometry3D::CLinkedLine3D &line) const noexcept;

    private:
        CLinkedEdge(Geometry3D::CPoint3D &&point1, Geometry3D::CPoint3D &&point2);

        static inline bool isEqualDouble(double x, double y) noexcept;

        bool isPointBetweenEdgeEndings(const Geometry3D::CPoint3D &point) const noexcept;


    };
}