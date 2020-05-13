
#include <gtest/gtest.h>
#include <CLineSegment2D.hpp>
#include <CVectorGraphicsData.hpp>
#include <vector>
#include <random>
#include <limits>


namespace File2DProcessingTools {

    class CVectorGraphicsDataFixture : public ::testing::Test {
    private:
        static constexpr double DOUBLE_MAX_VALUE = 136152.394;

        std::default_random_engine *random_gen = nullptr;
        std::uniform_real_distribution<double> *distribution = nullptr;

    protected:
        void SetUp() override {
            std::random_device rd;
            random_gen = new std::default_random_engine(rd());
            distribution = new std::uniform_real_distribution<double>(-DOUBLE_MAX_VALUE,DOUBLE_MAX_VALUE);

            line_segments_fixture_sources = nextRandomCLineSegments2DVector(1000);
            data_fixture.addLineSegments(std::begin(line_segments_fixture_sources),
                                         std::end(line_segments_fixture_sources));
        }

        void TearDown() override {
            delete distribution;
            delete random_gen;
        }

        double nextRandomDouble() {
            return (*distribution)(*random_gen);
        }

        Geometry2D::CPoint2D nextRandomCPoint2D() {
            return {nextRandomDouble(), nextRandomDouble()};
        }

        Geometry2D::CLineSegment2D nextRandomCLineSegment2D() {
            return {nextRandomCPoint2D(), nextRandomCPoint2D()};
        }

        std::vector<Geometry2D::CLineSegment2D> nextRandomCLineSegments2DVector(size_t size) {
            std::vector<Geometry2D::CLineSegment2D> data;
            data.resize(size, nextRandomCLineSegment2D());;
            return data;
        }

        CVectorGraphicsData getFixtureCopy() {
            auto copy = data_fixture;
            return copy;
        }

        std::vector<Geometry2D::CLineSegment2D> line_segments_fixture_sources;
        CVectorGraphicsData data_fixture;

        static void expectCLineSegment2DVectorsEqual(const std::vector<Geometry2D::CLineSegment2D> &expected,
                                                     const std::vector<Geometry2D::CLineSegment2D> &actual) {
            if (expected.size() != actual.size()) {
                GTEST_FAIL() << "CLineSegment2D vectors sizes are not equal";
            }

            for (std::vector<Geometry2D::CLineSegment2D>::size_type i = 0; i < expected.size(); ++i) {
                EXPECT_EQ(expected[i].getFirstPoint().getX(), actual[i].getFirstPoint().getX());
                EXPECT_EQ(expected[i].getFirstPoint().getY(), actual[i].getFirstPoint().getY());

                EXPECT_EQ(expected[i].getSecondPoint().getX(), actual[i].getSecondPoint().getX());
                EXPECT_EQ(expected[i].getSecondPoint().getY(), actual[i].getSecondPoint().getY());
            }
        }
    };

    TEST(CVectorGraphicsData, CVectorGraphicsData_base_constructor_Test) {
        EXPECT_TRUE(CVectorGraphicsData().getLineSegments().empty());
    }

    TEST_F(CVectorGraphicsDataFixture, CVectorGraphicsData_addLineSegments_Test) {
        expectCLineSegment2DVectorsEqual(line_segments_fixture_sources, data_fixture.getLineSegments());
    }

    TEST_F(CVectorGraphicsDataFixture, CVectorGraphicsData_addLineSegment_Test) {
        CVectorGraphicsData data;
        for (const auto &line_segment : line_segments_fixture_sources) {
            data.addLineSegments(line_segment);
        }
        expectCLineSegment2DVectorsEqual(line_segments_fixture_sources, data.getLineSegments());
    }

    TEST_F(CVectorGraphicsDataFixture, CVectorGraphicsData_copy_constructor_Test) {
        CVectorGraphicsData data_copy = data_fixture;
        expectCLineSegment2DVectorsEqual(data_fixture.getLineSegments(), data_copy.getLineSegments());
    }

    TEST_F(CVectorGraphicsDataFixture, CVectorGraphicsData_move_constructor_Test) {
        CVectorGraphicsData data_move = getFixtureCopy();
        expectCLineSegment2DVectorsEqual(data_fixture.getLineSegments(), data_move.getLineSegments());
    }

    TEST_F(CVectorGraphicsDataFixture, CVectorGraphicsData_copy_assingnment_Test) {
        CVectorGraphicsData data;
        data.addLineSegments(nextRandomCLineSegment2D()); // Adding random segment to prevent optimization

        data = data_fixture;
        expectCLineSegment2DVectorsEqual(data_fixture.getLineSegments(), data.getLineSegments());
    }

    TEST_F(CVectorGraphicsDataFixture, CVectorGraphicsData_move_assingnment_Test) {
        CVectorGraphicsData data;
        data.addLineSegments(nextRandomCLineSegment2D()); // Adding random segment to prevent optimization

        data = getFixtureCopy(); // Should be rvalue here
        expectCLineSegment2DVectorsEqual(data_fixture.getLineSegments(), data.getLineSegments());
    }

}