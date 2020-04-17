/**
 * @author Vladislav Yaroshchuk, github.com/shchuko
 */


#include <algorithm>
#include <gtest/gtest.h>
#include <CPoint3D.hpp>
#include <CVector3D.hpp>
#include <Geometry3DOperators.hpp>

#include "CObject3DData.hpp"


namespace CObject3DDataUnitTestsNS {
    using namespace File3DProcessingTools;
    using namespace Geometry3D;

    class CObject3DDataFixture : public ::testing::Test {
    protected:
        void SetUp() override {
            polygons.emplace_back(0);
            polygons.emplace_back(1);
            polygons.emplace_back(2);

            polygons[0].addEdge(0, 1);
            polygons[0].addEdge(1, 2);
            polygons[0].addEdge(2, 0);

            polygons[1].addEdge(0, 1);
            polygons[1].addEdge(1, 3);
            polygons[1].addEdge(3, 0);

            polygons[2].addEdge(1, 2);
            polygons[2].addEdge(2, 3);
            polygons[2].addEdge(3, 1);

            for (const auto &v : vertexes)
                data.addVertex(v);

            for (const auto &n : normal_vectors)
                data.addPolygonNormal(n);

            for (const auto &poly : polygons)
                data.addPolygon(poly);
        }

        void TearDown() override {
        }

        CObject3DData data;

        std::vector<CPoint3D> vertexes = {
                {1.0,  1.0,  1.0},
                {-1.0, -1.0, 1.0},
                {-1.0, 1.0,  -1.0},
                {1.0,  -1.0, -1.0}
        };

        std::vector<CVector3D> normal_vectors = {
                {1.1,    4.3,   -2.3},
                {-32.42, -24.0, 23.5},
                {14.28,  296.0, 238972.1}
        };

        std::vector<CPolygon> polygons;
    };

    TEST_F(CObject3DDataFixture, CObject3DData_addVertex_getVertexes_Test) {
        EXPECT_EQ(vertexes, data.getVertexes());
    }

    TEST_F(CObject3DDataFixture, CObject3DData_addPolygonNormal_getPolygonNormal_Test) {
        EXPECT_EQ(normal_vectors, data.getPolygonNormals());
    }

    TEST_F(CObject3DDataFixture, CObject3DData_addPolygon_getPolygons_Test) {
        for (std::vector<CPolygon>::size_type i = 0; i < polygons.size(); ++i) {
            const auto &stored_poly = data.getPolygons()[i];
            const auto &expected_poly = polygons[i];

            EXPECT_FALSE(&expected_poly == &stored_poly) << "Stored in CObject3DData polygon is not a copy";
            EXPECT_EQ(expected_poly.getNormalVectorIndex(), stored_poly.getNormalVectorIndex());
            EXPECT_EQ(expected_poly.getEdges(), stored_poly.getEdges());
        }
    }

    TEST_F(CObject3DDataFixture, CObject3DData_getEdges_Test) {
        for (const auto &polygon : data.getPolygons()) {
            for (const auto &edge_key : polygon.getEdges()) {
                const auto &edge = data.getEdge(edge_key);

                const auto &edge_begin_point = data.getVertexes()[edge_key.first];
                const auto &edge_end_point = data.getVertexes()[edge_key.second];
                CLinkedEdge expected_edge(edge_begin_point, edge_end_point);

                EXPECT_EQ(expected_edge.getLineLinkedVector(), edge.getLineLinkedVector());
                EXPECT_EQ(expected_edge.getLinkedLine(), edge.getLinkedLine());
                EXPECT_EQ(edge_begin_point, edge.getLineLinkedVector().getPointBegin());
                EXPECT_EQ(edge_end_point, edge.getLineLinkedVector().getPointEnd());
            }
        }
    }

    TEST_F(CObject3DDataFixture, CObject3DData_forEachVertex_Test) {
        auto f_multiply_five = [](CPoint3D &vertex) {
            vertex.setX(vertex.getX() * 5);
            vertex.setY(vertex.getY() * 5);
            vertex.setZ(vertex.getZ() * 5);
        };

        data.forEachVertex(f_multiply_five);
        std::for_each(std::begin(vertexes), std::end(vertexes), f_multiply_five);

        EXPECT_EQ(vertexes, data.getVertexes());
    }

    TEST_F(CObject3DDataFixture, CObject3DData_forEachNormalVector_Test) {
        auto f_multiply_five = [](CVector3D &vector) {
            vector.setX(vector.getX() * 5);
            vector.setY(vector.getY() * 5);
            vector.setZ(vector.getZ() * 5);
        };

        data.forEachNormalVector(f_multiply_five);
        std::for_each(std::begin(normal_vectors), std::end(normal_vectors), f_multiply_five);

        EXPECT_EQ(normal_vectors, data.getPolygonNormals());
    }

    TEST_F(CObject3DDataFixture, CObject3DData_setAllEdgesMarked_setEdgeMarked_Test) {
        auto edge_key = *(data.getPolygons().begin()->getEdges().begin());
        EXPECT_FALSE(data.getEdge(edge_key).isMarked());
        data.setEdgeMarked(edge_key, true);
        EXPECT_TRUE(data.getEdge(edge_key).isMarked());
        data.setAllEdgesMarked(false);
        EXPECT_FALSE(data.getEdge(edge_key).isMarked());
    }
}
