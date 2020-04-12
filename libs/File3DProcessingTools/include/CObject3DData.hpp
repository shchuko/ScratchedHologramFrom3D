#pragma once


#include <vector>
#include <unordered_map>
#include <limits>
#include <functional>
#include <algorithm>
#include <CPoint3D.hpp>
#include <CVector3D.hpp>


#include "CPolygon.hpp"
#include "TFile3DProcessingToolsTypes.hpp"
#include "CLinkedEdge.hpp"
#include "FOperators.hpp"


namespace File3DProcessingTools {
    /**
     * Storage for 3D objects, similar to *.obj file format structure
     * @author Vladislav Yaroshchuk, github.com/shchuko
     */
    class CObject3DData {
    protected:
        std::vector<Geometry3D::CPoint3D> vertexes;
        std::unordered_map<edge_map_key_t, CLinkedEdge, FHashPair> edges;
        std::vector<Geometry3D::CVector3D> polygons_normals;
        std::vector<CPolygon> polygons;

    public:
        CObject3DData() noexcept = default;

        CObject3DData(const CObject3DData& object3d_data) noexcept;

        /**
         * Add vertex to vertex storage
         * @param vertex Vertex to add
         */
        void addVertex(Geometry3D::CPoint3D vertex) noexcept;

        /**
         * Add normal vector to polygon normals storage
         * @param normal_vector Normal vector to add
         */
        void addPolygonNormal(Geometry3D::CVector3D normal_vector) noexcept;

        /**
         * Add polygon to polygons storage
         * @param polygon Polygon to add
         */
        void addPolygon(CPolygon polygon) noexcept;

        /**
         * Get array of vertexes
         * @return Array of stored vertexes
         */
        const std::vector<Geometry3D::CPoint3D> &getVertexes() const noexcept;

        /**
         * Get array of polygons
         * @return Array of stored polygons
         */
        const std::vector<CPolygon> &getPolygons() const noexcept;

        /**
         * Get edge by its key
         * @param edge_key Edge key stored in CPolygon object
         * @return Reference to Edge object
         */
        const CLinkedEdge &getEdge(edge_map_key_t edge_key);

        /**
         * Get array of polygons' normal vectors
         * @return Array of polygons' normal vectors
         */
        const std::vector<Geometry3D::CVector3D> &getPolygonNormals() const noexcept;

        /**
         * Apply function onto all vertexes (points)
         * @param func Transformation function
         */
        void forEachVertex(const std::function<void(Geometry3D::CPoint3D &point)> &func) noexcept;

        /**
         * Apply function onto all polygons' normal vectors
         * @param func Transformation function
         */
        void forEachNormalVector(const std::function<void(Geometry3D::CVector3D &vec)> &func) noexcept;

    private:
        void addEdge(edge_map_key_t points_pair);
    };
}
