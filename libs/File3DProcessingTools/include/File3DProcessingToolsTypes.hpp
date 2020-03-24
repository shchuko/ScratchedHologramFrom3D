#pragma once


#include <vector>

#include <CPoint3D.hpp>
#include <CVector3D.hpp>


/**
 * @author Vladislav Yaroshchuk, github.com/shchuko
 */
namespace File3DProcessingTools {
    typedef std::vector<Geometry3D::CPoint3D>::size_type v_size_t;
    typedef std::vector<Geometry3D::CVector3D>::size_type n_size_t;
    typedef std::pair<v_size_t, v_size_t> edge_map_key_t;
}