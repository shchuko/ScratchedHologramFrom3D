#include <gtest/gtest.h>


#include "TFile3DProcessingToolsTypes.hpp"
#include "CPolygon.hpp"


/**
 * @author Vladislav Yaroshchuk, github.com/shchuko
 */
namespace CPolygonUnitTestsNS {
    using namespace File3DProcessingTools;

    TEST(CPolygon, CPolygon_base_constructor_getNormalVectorIndex_Test) {
        nrml_size_t normal_index = 231;
        CPolygon polygon(normal_index);

        EXPECT_EQ(normal_index, polygon.getNormalVectorIndex());
    }

    class CPolygonNotReadonlyFixture : public ::testing::Test {
    protected:
        void SetUp() override {
            nrml_size_t normal_index = 231;
            p_polygon = new CPolygon(normal_index);
        }

        void TearDown() override {
            delete p_polygon;
        }

        CPolygon *p_polygon = nullptr;
    };

    TEST_F(CPolygonNotReadonlyFixture, CPolygon_addEdge_WRITEABLE_Test) {
        vrtx_size_t v1_first_num = 10;
        vrtx_size_t v2_first_num = 20;
        p_polygon->addEdge(v1_first_num, v2_first_num);

        vrtx_size_t v1_second_num = 100;
        vrtx_size_t v2_second_num = 200;
        p_polygon->addEdge(v1_second_num, v2_second_num);

        std::vector<edge_map_key_t> vec = {std::make_pair(v1_first_num, v2_first_num),
                                           std::make_pair(v1_second_num, v2_second_num)};
        EXPECT_EQ(vec, p_polygon->getEdges());
    }

    TEST_F(CPolygonNotReadonlyFixture, CPolygon_isReadonly_FALSE_Test) {
        EXPECT_FALSE(p_polygon->isReadonly());
    }

    class CPolygonReadonlyFixture : public ::testing::Test {
    protected:
        void SetUp() override {
            nrml_size_t normal_index = 231;
            p_polygon = new CPolygon(normal_index);
            p_polygon->makeReadonly();
        }

        void TearDown() override {
            delete p_polygon;
        }

        CPolygon *p_polygon = nullptr;
    };

    TEST_F(CPolygonReadonlyFixture, CPolygon_addEdge_READONLY_Test) {
        vrtx_size_t v1_first_num = 10;
        vrtx_size_t v2_first_num = 20;
        p_polygon->addEdge(v1_first_num, v2_first_num);

        vrtx_size_t v1_second_num = 100;
        vrtx_size_t v2_second_num = 200;
        p_polygon->addEdge(v1_second_num, v2_second_num);

        // Vector should be empty
        std::vector<edge_map_key_t> vec;
        EXPECT_EQ(vec, p_polygon->getEdges());
    }

    TEST_F(CPolygonReadonlyFixture, CPolygon_isReadonly_TRUE_Test) {
        EXPECT_TRUE(p_polygon->isReadonly());
    }
}
