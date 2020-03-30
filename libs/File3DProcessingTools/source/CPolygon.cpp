#include "CPolygon.hpp"


/**
 * @author Vladislav Yaroshchuk, github.com/shchuko
 */
namespace File3DProcessingTools {
    CPolygon::CPolygon(nrml_size_t _normal_vector_index) noexcept
            : normal_vector_index{_normal_vector_index} {

    }

    void CPolygon::makeReadonly() noexcept {
        readonly = true;
    }

    bool CPolygon::isReadonly() const noexcept {
        return readonly;
    }

    bool CPolygon::addEdge(vrtx_size_t first_point_index, vrtx_size_t second_point_index) noexcept {
        if (readonly) {
            return false;
        }

        if (first_point_index > second_point_index) {
            std::swap(first_point_index, second_point_index);
        }
        edges_links.emplace_back(std::make_pair(first_point_index, second_point_index));
        return true;
    }

    nrml_size_t CPolygon::getNormalVectorIndex() const noexcept {
        return normal_vector_index;
    }

    const std::vector<edge_map_key_t> &CPolygon::getEdges() const noexcept {
        return edges_links;
    }
}
