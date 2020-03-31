
#include <gtest/gtest.h>
#include <CLineSegment2D.hpp>
#include <CVectorGraphicsData.hpp>
#include <random>

namespace File2DProcessingTools {

    class CVectorGraphicDataFixture : public ::testing::Test {

    private:

        std::vector<Geometry2D::CLineSegment2D> cline_segments;
        CVectorGraphicsData vector_graphics_data;

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
                vector_graphics_data.addLineSegment(cline_segments[i]);
            }

        }

        void TearDown() override {
        }

        CVectorGraphicsData getVectorGraphicsData() {
            return vector_graphics_data;
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

}