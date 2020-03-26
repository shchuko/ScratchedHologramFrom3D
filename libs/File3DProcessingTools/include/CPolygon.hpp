#pragma once


#include <vector>


#include "TFile3DProcessingToolsTypes.hpp"


namespace File3DProcessingTools {
    /**
     * @author Vladislav Yaroshchuk, github.com/shchuko
     */
    class CPolygon {
    private:
        std::vector<edge_map_key_t> edges_links;
        nrml_size_t normal_vector_index = 0;
        bool readonly = false;


    public:
        /**
         * Create new polygon object
         * @param _normal_vector_index Index of normal vector related to polygon
         */
        explicit CPolygon(nrml_size_t _normal_vector_index) noexcept;

        /**
         * Make polygon readonly, after invoking makeReadonly() method addEdge() does not work
         */
        void makeReadonly() noexcept;

        /**
         * Is polygon object readonly
         * @return True if readonly
         */
        bool isReadonly() const noexcept;

        /**
         * Add edge link to polygon storage as its points' indexes
         * @param first_point_index First point index
         * @param second_point_index Second point index
         * @return True if edge is added, false if not (object readonly)
         */
        bool addEdge(vrtx_size_t first_point_index, vrtx_size_t second_point_index) noexcept;

        /**
         * Get index of normal vector related to polygon
         * @return Index of normal vector related to polygon
         */
        nrml_size_t getNormalVectorIndex();

        /**
         * Get edges links stored into polygon object
         * @return Edges links stored into polygon object
         */
        const std::vector<edge_map_key_t> &getEdges() const noexcept;
    };
}
