/**
 * @author Vladislav Yaroshchuk, github.com/shchuko
 */

#include <algorithm>
#include <gtest/gtest.h>
#include <CPoint3D.hpp>
#include <random>
#include <chrono>

#include "CPoints3DStatistics.hpp"


namespace CPoints3DStatisticsUnitTestsNS {
    using namespace File3DProcessingTools;
    using namespace Geometry3D;

    class CPoints3DStatisticsFixture : public ::testing::Test {
    private:
        static constexpr double MAX_DOUBLE_VALUE = 10000.0;
        static constexpr double MIN_DOUBLE_VALUE = -10000.0;

        std::uniform_real_distribution<double> *distribution = nullptr;
        std::mt19937 *random_engine = nullptr;

    protected:
        void SetUp() override {
            distribution = new std::uniform_real_distribution<double>(MIN_DOUBLE_VALUE, MAX_DOUBLE_VALUE);
            random_engine = new std::mt19937(std::chrono::system_clock::now().time_since_epoch().count());
        }

        void TearDown() override {
            delete random_engine;
            delete distribution;
            delete p_points_statistics;
        }

        inline double nextRandomDouble() {
            return (*distribution)(*random_engine);
        }

        inline CPoint3D nextRandomPoint() {
            return {nextRandomDouble(), nextRandomDouble(), nextRandomDouble()};
        }

        void fillTestMaxMinData(std::vector<CPoint3D>::size_type test_points_count) {
            points.resize(test_points_count);
            std::fill(std::begin(points), std::end(points), nextRandomPoint());
            p_points_statistics = new CPoints3DStatistics(std::begin(points), std::end(points));

            auto compare_x = [](const CPoint3D &first, const CPoint3D &second) -> bool {
                return first.getX() > second.getX();
            };
            auto compare_y = [](const CPoint3D &first, const CPoint3D &second) -> bool {
                return first.getY() > second.getY();
            };
            auto compare_z = [](const CPoint3D &first, const CPoint3D &second) -> bool {
                return first.getZ() > second.getZ();
            };

            max_x = std::max_element(std::begin(points), std::end(points), compare_x)->getX();
            min_x = std::min_element(std::begin(points), std::end(points), compare_x)->getX();

            max_y = std::max_element(std::begin(points), std::end(points), compare_y)->getY();
            min_y = std::min_element(std::begin(points), std::end(points), compare_y)->getY();

            max_z = std::max_element(std::begin(points), std::end(points), compare_z)->getZ();
            min_z = std::min_element(std::begin(points), std::end(points), compare_z)->getZ();
        }


        CPoints3DStatistics *p_points_statistics = nullptr;
        std::vector<CPoint3D> points;

        double max_x = 0.0;
        double max_y = 0.0;
        double max_z = 0.0;
        double min_x = 0.0;
        double min_y = 0.0;
        double min_z = 0.0;
    };

    TEST_F(CPoints3DStatisticsFixture, CPoints3DStatistics_10_elements_Test) {
        fillTestMaxMinData(10);
        EXPECT_EQ(max_x, p_points_statistics->getMaxX());
        EXPECT_EQ(min_x, p_points_statistics->getMinX());

        EXPECT_EQ(max_y, p_points_statistics->getMaxY());
        EXPECT_EQ(min_y, p_points_statistics->getMinY());

        EXPECT_EQ(max_z, p_points_statistics->getMaxZ());
        EXPECT_EQ(min_z, p_points_statistics->getMinZ());

    }

    TEST_F(CPoints3DStatisticsFixture, CPoints3DStatistics_100_elements_Test) {
        fillTestMaxMinData(100);
        EXPECT_EQ(max_x, p_points_statistics->getMaxX());
        EXPECT_EQ(min_x, p_points_statistics->getMinX());

        EXPECT_EQ(max_y, p_points_statistics->getMaxY());
        EXPECT_EQ(min_y, p_points_statistics->getMinY());

        EXPECT_EQ(max_z, p_points_statistics->getMaxZ());
        EXPECT_EQ(min_z, p_points_statistics->getMinZ());

    }

    TEST_F(CPoints3DStatisticsFixture, CPoints3DStatistics_10000000_elements_Test) {
        fillTestMaxMinData(10000000);
        EXPECT_EQ(max_x, p_points_statistics->getMaxX());
        EXPECT_EQ(min_x, p_points_statistics->getMinX());

        EXPECT_EQ(max_y, p_points_statistics->getMaxY());
        EXPECT_EQ(min_y, p_points_statistics->getMinY());

        EXPECT_EQ(max_z, p_points_statistics->getMaxZ());
        EXPECT_EQ(min_z, p_points_statistics->getMinZ());

    }

}
