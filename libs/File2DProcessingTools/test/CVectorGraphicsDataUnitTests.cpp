
#include <gtest/gtest.h>
#include <CLineSegment2D.hpp>
#include <CVectorGraphicsData.hpp>
#include <random>

namespace File2DProcessingTools {

    class CVectorGraphicDataFixture : public ::testing::Test {

    private:

        std::vector<Geometry2D::CLineSegment2D> cline_segments;
        CVectorGraphicsData expected;

    protected:

        void SetUp() override {

            for (int i = 0; i < 1000; ++i) {
                std::random_device rd;
                std::default_random_engine generator(rd());
                std::uniform_real_distribution<double> distribution(std::numeric_limits<double >::min(),
                                                                    std::numeric_limits<double >::max() );

                Geometry2D::CPoint2D first_point2D(distribution(generator), distribution(generator));
                Geometry2D::CPoint2D second_point2D(distribution(generator), distribution(generator));
                cline_segments.emplace_back(first_point2D, second_point2D);
                expected.addLineSegment(cline_segments[i]);
            }

        }

        void TearDown() override {
        }

        CVectorGraphicsData getVectorGraphicsData() {
            return expected;
        }

        Geometry2D::CLineSegment2D getSegment2D(int ind) {
            return cline_segments[ind];
        }

        int size(){
            return cline_segments.size();
        }

    };

    TEST_F(CVectorGraphicDataFixture, CVectorGraphicsData_addLineSegment_getLineSegments_Test) {

        CVectorGraphicsData vector_graphics_data = getVectorGraphicsData();
        for (int i = 0; i < size(); ++i) {
            Geometry2D::CLineSegment2D segment2D = getSegment2D(i);
            EXPECT_DOUBLE_EQ(vector_graphics_data.getLineSegments()[i].getFirstPoint().getX(), segment2D.getFirstPoint().getX());
            EXPECT_DOUBLE_EQ(vector_graphics_data.getLineSegments()[i].getFirstPoint().getY(), segment2D.getFirstPoint().getY());
            EXPECT_DOUBLE_EQ(vector_graphics_data.getLineSegments()[i].getSecondPoint().getX(), segment2D.getSecondPoint().getX());
            EXPECT_DOUBLE_EQ(vector_graphics_data.getLineSegments()[i].getSecondPoint().getY(), segment2D.getSecondPoint().getY());
        }
    }

    TEST_F(CVectorGraphicDataFixture, CVectorGraphicsData_CopyConstructor_Test) {
        CVectorGraphicsData temp = getVectorGraphicsData();
        const CVectorGraphicsData& actual(temp);
        CVectorGraphicsData expected  = getVectorGraphicsData();
        for (int i = 0; i < size(); ++i) {
            EXPECT_DOUBLE_EQ(expected.getLineSegments()[i].getFirstPoint().getX(), actual.getLineSegments()[i].getFirstPoint().getX());
            EXPECT_DOUBLE_EQ(expected.getLineSegments()[i].getFirstPoint().getY(), actual.getLineSegments()[i].getFirstPoint().getY());
            EXPECT_DOUBLE_EQ(expected.getLineSegments()[i].getSecondPoint().getX(), actual.getLineSegments()[i].getSecondPoint().getX());
            EXPECT_DOUBLE_EQ(expected.getLineSegments()[i].getSecondPoint().getY(), actual.getLineSegments()[i].getSecondPoint().getY());
        }
    }

    TEST_F(CVectorGraphicDataFixture, CVectorGraphicsData_MoveConstructor_Test) {
        CVectorGraphicsData actual(getVectorGraphicsData());
        CVectorGraphicsData expected  = getVectorGraphicsData();
        for (int i = 0; i < size(); ++i) {
            EXPECT_DOUBLE_EQ(expected.getLineSegments()[i].getFirstPoint().getX(), actual.getLineSegments()[i].getFirstPoint().getX());
            EXPECT_DOUBLE_EQ(expected.getLineSegments()[i].getFirstPoint().getY(), actual.getLineSegments()[i].getFirstPoint().getY());
            EXPECT_DOUBLE_EQ(expected.getLineSegments()[i].getSecondPoint().getX(), actual.getLineSegments()[i].getSecondPoint().getX());
            EXPECT_DOUBLE_EQ(expected.getLineSegments()[i].getSecondPoint().getY(), actual.getLineSegments()[i].getSecondPoint().getY());
        }
    }


    TEST_F(CVectorGraphicDataFixture, CVectorGraphicsData_CopyOperator_Test) {
        CVectorGraphicsData expected = getVectorGraphicsData();
        const CVectorGraphicsData&  actual = expected;
        for (int i = 0; i < size(); ++i) {
            EXPECT_DOUBLE_EQ(expected.getLineSegments()[i].getFirstPoint().getX(), actual.getLineSegments()[i].getFirstPoint().getX());
            EXPECT_DOUBLE_EQ(expected.getLineSegments()[i].getFirstPoint().getY(), actual.getLineSegments()[i].getFirstPoint().getY());
            EXPECT_DOUBLE_EQ(expected.getLineSegments()[i].getSecondPoint().getX(), actual.getLineSegments()[i].getSecondPoint().getX());
            EXPECT_DOUBLE_EQ(expected.getLineSegments()[i].getSecondPoint().getY(), actual.getLineSegments()[i].getSecondPoint().getY());
        }
    }

    TEST_F(CVectorGraphicDataFixture, CVectorGraphicsData_MoveOperator_Test) {
        CVectorGraphicsData actual = getVectorGraphicsData();
        CVectorGraphicsData expected  = getVectorGraphicsData();
        for (int i = 0; i < size(); ++i) {
            EXPECT_DOUBLE_EQ(expected.getLineSegments()[i].getFirstPoint().getX(), actual.getLineSegments()[i].getFirstPoint().getX());
            EXPECT_DOUBLE_EQ(expected.getLineSegments()[i].getFirstPoint().getY(), actual.getLineSegments()[i].getFirstPoint().getY());
            EXPECT_DOUBLE_EQ(expected.getLineSegments()[i].getSecondPoint().getX(), actual.getLineSegments()[i].getSecondPoint().getX());
            EXPECT_DOUBLE_EQ(expected.getLineSegments()[i].getSecondPoint().getY(), actual.getLineSegments()[i].getSecondPoint().getY());
        }
    }

}