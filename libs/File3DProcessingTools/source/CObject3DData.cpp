#include "CObject3DData.hpp"

/**
 * @author Vladislav Yaroshchuk, github.com/shchuko
 */
namespace File3DProcessingTools {

    void CObject3DData::addVertex(Geometry3D::CPoint3D vertex) noexcept {
        vertexes.emplace_back(std::move(vertex));
    }

    void CObject3DData::addPolygonNormal(Geometry3D::CVector3D normal_vector) noexcept {
        polygons_normals.emplace_back(std::move(normal_vector));
    }

    void CObject3DData::addPolygon(CPolygon polygon) noexcept {
        polygons.emplace_back(std::move(polygon));

        for (const auto &edge : polygons.back().getEdges()) {
            addEdge(edge);
        }
    }

    const std::vector<Geometry3D::CPoint3D> &CObject3DData::getVertexes() const noexcept {
        return vertexes;
    }

    const std::vector<CPolygon> &CObject3DData::getPolygons() const noexcept {
        return polygons;
    }

    const CLinkedEdge &CObject3DData::getEdge(const edge_map_key_t &edge_key) {
        return (edges.find(edge_key))->second;
    }

    const std::vector<Geometry3D::CVector3D> &CObject3DData::getPolygonNormals() const noexcept {
        return polygons_normals;
    }

    void CObject3DData::forEachVertex(const std::function<void(Geometry3D::CPoint3D &point)> &func) noexcept {
        std::for_each(std::begin(vertexes), std::end(vertexes), func);
    }

    void CObject3DData::addEdge(edge_map_key_t points_pair) {
        if (edges.find(points_pair) == edges.end()) {
            edges.emplace(std::move(points_pair),
                          CLinkedEdge(vertexes[points_pair.first], vertexes[points_pair.second]));
        }
    }

    void CObject3DData::forEachNormalVector(const std::function<void(Geometry3D::CVector3D &vec)> &func) noexcept {
        std::for_each(std::begin(polygons_normals), std::end(polygons_normals), func);
    }

    CObject3DData::CObject3DData(const CObject3DData &object3d_data) noexcept {
        this->vertexes = object3d_data.vertexes;
        this->polygons_normals = object3d_data.polygons_normals;
        this->edges = object3d_data.edges;
        this->polygons = object3d_data.polygons;

        for (auto &edge_data : edges) {
            auto &points_pair = edge_data.first;
            edge_data.second.update(vertexes[points_pair.first], vertexes[points_pair.second]);
        }
    }

    void CObject3DData::setAllEdgesMarked(bool marked_flag) noexcept {
        for (auto &edge_pair : edges) {
            edge_pair.second.setMarked(marked_flag);
        }
    }

    void CObject3DData::setEdgeMarked(const edge_map_key_t &edge_key, bool marked_flag) noexcept {
        edges.find(edge_key)->second.setMarked(marked_flag);
    }
}