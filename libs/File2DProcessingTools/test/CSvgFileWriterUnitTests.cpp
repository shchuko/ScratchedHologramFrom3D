#include <gtest/gtest.h>
#include <cstdio>
#include <CPoint2D.hpp>
#include <CLineSegment2D.hpp>
#include <CVectorGraphicsData.hpp>
#include <CSvgFileWriter.hpp>
#include <EFileAlreadyExistsException.hpp>
#include <algorithm>

namespace File2DProcessingTools {

    class CSvgFileWriterFixture : public ::testing::Test {
    private:
        std::string PROJECT_ROOT;

    protected:
        void SetUp() override {
            DIR_SEPARATOR = getDirectorySeparator();
            PROJECT_ROOT = PROJECT_SOURCE_DIR;
            std::replace(PROJECT_ROOT.begin(), PROJECT_ROOT.end(), '/', DIR_SEPARATOR[0]);
            TEST_RESOURCES_DIR = PROJECT_ROOT + DIR_SEPARATOR + "test_resources";

            SVG_PATH = TEST_RESOURCES_DIR + DIR_SEPARATOR + "test.svg";
        }

        void TearDown() override {}

        static CVectorGraphicsData getDanyaData() {
            File2DProcessingTools::CVectorGraphicsData cVectorGraphicsData;

            File2DProcessingTools::CVectorGraphicsData::CColor_T color(
                    File2DProcessingTools::CVectorGraphicsData::CColor_T::COLOR::GREEN);


            //Д
            cVectorGraphicsData.addLineSegments(
                    Geometry2D::CLineSegment2D(Geometry2D::CPoint2D(-1150, 200), Geometry2D::CPoint2D(-1150, 250)), 2);
            cVectorGraphicsData.addLineSegments(
                    Geometry2D::CLineSegment2D(Geometry2D::CPoint2D(-1150, 250), Geometry2D::CPoint2D(-1000, 250)), 2);
            cVectorGraphicsData.addLineSegments(
                    Geometry2D::CLineSegment2D(Geometry2D::CPoint2D(-1100, 100), Geometry2D::CPoint2D(-1150, 200)), 2);
            cVectorGraphicsData.addLineSegments(
                    Geometry2D::CLineSegment2D(Geometry2D::CPoint2D(-1000, 250), Geometry2D::CPoint2D(-950, 500)), 2);
            cVectorGraphicsData.addLineSegments(
                    Geometry2D::CLineSegment2D(Geometry2D::CPoint2D(-950, 500), Geometry2D::CPoint2D(-850, 500)), 2);
            cVectorGraphicsData.addLineSegments(
                    Geometry2D::CLineSegment2D(Geometry2D::CPoint2D(-850, 500), Geometry2D::CPoint2D(-800, 250)), 2);
            cVectorGraphicsData.addLineSegments(
                    Geometry2D::CLineSegment2D(Geometry2D::CPoint2D(-800, 250), Geometry2D::CPoint2D(-650, 250)), 2);
            cVectorGraphicsData.addLineSegments(
                    Geometry2D::CLineSegment2D(Geometry2D::CPoint2D(-650, 250), Geometry2D::CPoint2D(-650, 200)), 2);
            cVectorGraphicsData.addLineSegments(
                    Geometry2D::CLineSegment2D(Geometry2D::CPoint2D(-650, 200), Geometry2D::CPoint2D(-700, 100)), 2);
            cVectorGraphicsData.addLineSegments(
                    Geometry2D::CLineSegment2D(Geometry2D::CPoint2D(-700, 100), Geometry2D::CPoint2D(-800, 100)), 2);
            cVectorGraphicsData.addLineSegments(
                    Geometry2D::CLineSegment2D(Geometry2D::CPoint2D(-800, 100), Geometry2D::CPoint2D(-750, 200)), 2);
            cVectorGraphicsData.addLineSegments(
                    Geometry2D::CLineSegment2D(Geometry2D::CPoint2D(-750, 200), Geometry2D::CPoint2D(-1050, 200)), 2);
            cVectorGraphicsData.addLineSegments(
                    Geometry2D::CLineSegment2D(Geometry2D::CPoint2D(-1050, 200), Geometry2D::CPoint2D(-1000, 100)), 2);
            cVectorGraphicsData.addLineSegments(
                    Geometry2D::CLineSegment2D(Geometry2D::CPoint2D(-1000, 100), Geometry2D::CPoint2D(-1100, 100)), 2);
            cVectorGraphicsData.addLineSegments(
                    Geometry2D::CLineSegment2D(Geometry2D::CPoint2D(-850, 250), Geometry2D::CPoint2D(-950, 250)), 2);
            cVectorGraphicsData.addLineSegments(
                    Geometry2D::CLineSegment2D(Geometry2D::CPoint2D(-950, 250), Geometry2D::CPoint2D(-920, 450)), 2);
            cVectorGraphicsData.addLineSegments(
                    Geometry2D::CLineSegment2D(Geometry2D::CPoint2D(-920, 450), Geometry2D::CPoint2D(-880, 450)), 2);
            cVectorGraphicsData.addLineSegments(
                    Geometry2D::CLineSegment2D(Geometry2D::CPoint2D(-880, 450), Geometry2D::CPoint2D(-850, 250)), 2);
            cVectorGraphicsData.setNextColor(color);
            //А
            cVectorGraphicsData.addLineSegments(
                    Geometry2D::CLineSegment2D(Geometry2D::CPoint2D(-500, 100), Geometry2D::CPoint2D(-350, 500)), 2);
            cVectorGraphicsData.addLineSegments(
                    Geometry2D::CLineSegment2D(Geometry2D::CPoint2D(-350, 500), Geometry2D::CPoint2D(-250, 500)), 2);
            cVectorGraphicsData.addLineSegments(
                    Geometry2D::CLineSegment2D(Geometry2D::CPoint2D(-250, 500), Geometry2D::CPoint2D(-100, 100)), 2);
            cVectorGraphicsData.addLineSegments(
                    Geometry2D::CLineSegment2D(Geometry2D::CPoint2D(-100, 100), Geometry2D::CPoint2D(-200, 100)), 2);
            cVectorGraphicsData.addLineSegments(
                    Geometry2D::CLineSegment2D(Geometry2D::CPoint2D(-200, 100), Geometry2D::CPoint2D(-250, 200)), 2);
            cVectorGraphicsData.addLineSegments(
                    Geometry2D::CLineSegment2D(Geometry2D::CPoint2D(-250, 200), Geometry2D::CPoint2D(-350, 200)), 2);
            cVectorGraphicsData.addLineSegments(
                    Geometry2D::CLineSegment2D(Geometry2D::CPoint2D(-350, 200), Geometry2D::CPoint2D(-400, 100)), 2);
            cVectorGraphicsData.addLineSegments(
                    Geometry2D::CLineSegment2D(Geometry2D::CPoint2D(-400, 100), Geometry2D::CPoint2D(-500, 100)), 2);
            cVectorGraphicsData.addLineSegments(
                    Geometry2D::CLineSegment2D(Geometry2D::CPoint2D(-250, 250), Geometry2D::CPoint2D(-350, 250)), 2);
            cVectorGraphicsData.addLineSegments(
                    Geometry2D::CLineSegment2D(Geometry2D::CPoint2D(-350, 250), Geometry2D::CPoint2D(-320, 350)), 2);
            cVectorGraphicsData.addLineSegments(
                    Geometry2D::CLineSegment2D(Geometry2D::CPoint2D(-320, 350), Geometry2D::CPoint2D(-280, 350)), 2);
            cVectorGraphicsData.addLineSegments(
                    Geometry2D::CLineSegment2D(Geometry2D::CPoint2D(-280, 350), Geometry2D::CPoint2D(-250, 250)), 2);
            color.setColor(File2DProcessingTools::CVectorGraphicsData::CColor_T::COLOR::RED);
            cVectorGraphicsData.setNextColor(color);
            //Н
            cVectorGraphicsData.addLineSegments(
                    Geometry2D::CLineSegment2D(Geometry2D::CPoint2D(100, 500), Geometry2D::CPoint2D(200, 500)), 2);
            cVectorGraphicsData.addLineSegments(
                    Geometry2D::CLineSegment2D(Geometry2D::CPoint2D(200, 500), Geometry2D::CPoint2D(200, 300)), 2);
            cVectorGraphicsData.addLineSegments(
                    Geometry2D::CLineSegment2D(Geometry2D::CPoint2D(200, 300), Geometry2D::CPoint2D(400, 300)), 2);
            cVectorGraphicsData.addLineSegments(
                    Geometry2D::CLineSegment2D(Geometry2D::CPoint2D(400, 300), Geometry2D::CPoint2D(400, 500)), 2);
            cVectorGraphicsData.addLineSegments(
                    Geometry2D::CLineSegment2D(Geometry2D::CPoint2D(400, 500), Geometry2D::CPoint2D(500, 500)), 2);
            cVectorGraphicsData.addLineSegments(
                    Geometry2D::CLineSegment2D(Geometry2D::CPoint2D(500, 500), Geometry2D::CPoint2D(500, 100)), 2);
            cVectorGraphicsData.addLineSegments(
                    Geometry2D::CLineSegment2D(Geometry2D::CPoint2D(500, 100), Geometry2D::CPoint2D(400, 100)), 2);
            cVectorGraphicsData.addLineSegments(
                    Geometry2D::CLineSegment2D(Geometry2D::CPoint2D(400, 100), Geometry2D::CPoint2D(400, 200)), 2);
            cVectorGraphicsData.addLineSegments(
                    Geometry2D::CLineSegment2D(Geometry2D::CPoint2D(400, 200), Geometry2D::CPoint2D(200, 200)), 2);
            cVectorGraphicsData.addLineSegments(
                    Geometry2D::CLineSegment2D(Geometry2D::CPoint2D(200, 200), Geometry2D::CPoint2D(200, 100)), 2);
            cVectorGraphicsData.addLineSegments(
                    Geometry2D::CLineSegment2D(Geometry2D::CPoint2D(200, 100), Geometry2D::CPoint2D(100, 100)), 2);
            cVectorGraphicsData.addLineSegments(
                    Geometry2D::CLineSegment2D(Geometry2D::CPoint2D(100, 100), Geometry2D::CPoint2D(100, 500)), 2);
            color.setColor(File2DProcessingTools::CVectorGraphicsData::CColor_T::COLOR::ORANGE);
            cVectorGraphicsData.setNextColor(color);
            //Я
            cVectorGraphicsData.addLineSegments(
                    Geometry2D::CLineSegment2D(Geometry2D::CPoint2D(700, 100), Geometry2D::CPoint2D(700, 200)), 3);
            cVectorGraphicsData.addLineSegments(
                    Geometry2D::CLineSegment2D(Geometry2D::CPoint2D(700, 200), Geometry2D::CPoint2D(800, 300)), 3);
            cVectorGraphicsData.addLineSegments(
                    Geometry2D::CLineSegment2D(Geometry2D::CPoint2D(800, 300), Geometry2D::CPoint2D(700, 350)), 3);
            cVectorGraphicsData.addLineSegments(
                    Geometry2D::CLineSegment2D(Geometry2D::CPoint2D(700, 350), Geometry2D::CPoint2D(700, 450)), 3);
            cVectorGraphicsData.addLineSegments(
                    Geometry2D::CLineSegment2D(Geometry2D::CPoint2D(700, 450), Geometry2D::CPoint2D(800, 500)), 3);
            cVectorGraphicsData.addLineSegments(
                    Geometry2D::CLineSegment2D(Geometry2D::CPoint2D(800, 500), Geometry2D::CPoint2D(1100, 500)), 3);
            cVectorGraphicsData.addLineSegments(
                    Geometry2D::CLineSegment2D(Geometry2D::CPoint2D(1100, 500), Geometry2D::CPoint2D(1100, 100)), 3);
            cVectorGraphicsData.addLineSegments(
                    Geometry2D::CLineSegment2D(Geometry2D::CPoint2D(1100, 100), Geometry2D::CPoint2D(1000, 100)), 3);
            cVectorGraphicsData.addLineSegments(
                    Geometry2D::CLineSegment2D(Geometry2D::CPoint2D(1000, 100), Geometry2D::CPoint2D(1000, 200)), 3);
            cVectorGraphicsData.addLineSegments(
                    Geometry2D::CLineSegment2D(Geometry2D::CPoint2D(1000, 200), Geometry2D::CPoint2D(850, 200)), 3);
            cVectorGraphicsData.addLineSegments(
                    Geometry2D::CLineSegment2D(Geometry2D::CPoint2D(850, 200), Geometry2D::CPoint2D(800, 150)), 3);
            cVectorGraphicsData.addLineSegments(
                    Geometry2D::CLineSegment2D(Geometry2D::CPoint2D(800, 150), Geometry2D::CPoint2D(800, 100)), 3);
            cVectorGraphicsData.addLineSegments(
                    Geometry2D::CLineSegment2D(Geometry2D::CPoint2D(800, 100), Geometry2D::CPoint2D(700, 100)), 3);
            cVectorGraphicsData.addLineSegments(
                    Geometry2D::CLineSegment2D(Geometry2D::CPoint2D(850, 350), Geometry2D::CPoint2D(850, 450)), 3);
            cVectorGraphicsData.addLineSegments(
                    Geometry2D::CLineSegment2D(Geometry2D::CPoint2D(850, 450), Geometry2D::CPoint2D(950, 450)), 3);
            cVectorGraphicsData.addLineSegments(
                    Geometry2D::CLineSegment2D(Geometry2D::CPoint2D(950, 450), Geometry2D::CPoint2D(950, 350)), 3);
            cVectorGraphicsData.addLineSegments(
                    Geometry2D::CLineSegment2D(Geometry2D::CPoint2D(950, 350), Geometry2D::CPoint2D(850, 350)), 3);
            color.setColor(File2DProcessingTools::CVectorGraphicsData::CColor_T::COLOR::BLUE);
            cVectorGraphicsData.setNextColor(color);
            //П
            cVectorGraphicsData.addLineSegments(
                    Geometry2D::CLineSegment2D(Geometry2D::CPoint2D(-1100, -700), Geometry2D::CPoint2D(-1100, -300)), 4);
            cVectorGraphicsData.addLineSegments(
                    Geometry2D::CLineSegment2D(Geometry2D::CPoint2D(-1100, -300), Geometry2D::CPoint2D(-700, -300)), 4);
            cVectorGraphicsData.addLineSegments(
                    Geometry2D::CLineSegment2D(Geometry2D::CPoint2D(-700, -300), Geometry2D::CPoint2D(-700, -700)), 4);
            cVectorGraphicsData.addLineSegments(
                    Geometry2D::CLineSegment2D(Geometry2D::CPoint2D(-700, -700), Geometry2D::CPoint2D(-800, -700)), 4);
            cVectorGraphicsData.addLineSegments(
                    Geometry2D::CLineSegment2D(Geometry2D::CPoint2D(-800, -700), Geometry2D::CPoint2D(-800, -400)), 4);
            cVectorGraphicsData.addLineSegments(
                    Geometry2D::CLineSegment2D(Geometry2D::CPoint2D(-800, -400), Geometry2D::CPoint2D(-1000, -400)), 4);
            cVectorGraphicsData.addLineSegments(
                    Geometry2D::CLineSegment2D(Geometry2D::CPoint2D(-1000, -400), Geometry2D::CPoint2D(-1000, -700)), 4);
            cVectorGraphicsData.addLineSegments(
                    Geometry2D::CLineSegment2D(Geometry2D::CPoint2D(-1000, -700), Geometry2D::CPoint2D(-1100, -700)), 4);
            color.setColor("#FFA5D1");
            cVectorGraphicsData.setNextColor(color);
            //И
            cVectorGraphicsData.addLineSegments(
                    Geometry2D::CLineSegment2D(Geometry2D::CPoint2D(-500, -700), Geometry2D::CPoint2D(-500, -300)), 4);
            cVectorGraphicsData.addLineSegments(
                    Geometry2D::CLineSegment2D(Geometry2D::CPoint2D(-500, -300), Geometry2D::CPoint2D(-400, -300)), 4);
            cVectorGraphicsData.addLineSegments(
                    Geometry2D::CLineSegment2D(Geometry2D::CPoint2D(-400, -300), Geometry2D::CPoint2D(-400, -600)), 4);
            cVectorGraphicsData.addLineSegments(
                    Geometry2D::CLineSegment2D(Geometry2D::CPoint2D(-400, -600), Geometry2D::CPoint2D(-200, -450)), 4);
            cVectorGraphicsData.addLineSegments(
                    Geometry2D::CLineSegment2D(Geometry2D::CPoint2D(-200, -450), Geometry2D::CPoint2D(-200, -300)), 4);
            cVectorGraphicsData.addLineSegments(
                    Geometry2D::CLineSegment2D(Geometry2D::CPoint2D(-200, -300), Geometry2D::CPoint2D(-100, -300)), 4);
            cVectorGraphicsData.addLineSegments(
                    Geometry2D::CLineSegment2D(Geometry2D::CPoint2D(-100, -300), Geometry2D::CPoint2D(-100, -700)), 4);
            cVectorGraphicsData.addLineSegments(
                    Geometry2D::CLineSegment2D(Geometry2D::CPoint2D(-100, -700), Geometry2D::CPoint2D(-200, -700)), 4);
            cVectorGraphicsData.addLineSegments(
                    Geometry2D::CLineSegment2D(Geometry2D::CPoint2D(-200, -700), Geometry2D::CPoint2D(-200, -550)), 4);
            cVectorGraphicsData.addLineSegments(
                    Geometry2D::CLineSegment2D(Geometry2D::CPoint2D(-200, -550), Geometry2D::CPoint2D(-400, -700)), 4);
            cVectorGraphicsData.addLineSegments(
                    Geometry2D::CLineSegment2D(Geometry2D::CPoint2D(-400, -700), Geometry2D::CPoint2D(-500, -700)), 4);
            color.setColor(255, 0, 255);
            cVectorGraphicsData.setNextColor(color);
            //Д
            cVectorGraphicsData.addLineSegments(
                    Geometry2D::CLineSegment2D(Geometry2D::CPoint2D(100, -700), Geometry2D::CPoint2D(50, -600)), 4);
            cVectorGraphicsData.addLineSegments(
                    Geometry2D::CLineSegment2D(Geometry2D::CPoint2D(50, -600), Geometry2D::CPoint2D(200, -600)), 4);
            cVectorGraphicsData.addLineSegments(
                    Geometry2D::CLineSegment2D(Geometry2D::CPoint2D(200, -600), Geometry2D::CPoint2D(250, -300)), 4);
            cVectorGraphicsData.addLineSegments(
                    Geometry2D::CLineSegment2D(Geometry2D::CPoint2D(250, -300), Geometry2D::CPoint2D(350, -300)), 4);
            cVectorGraphicsData.addLineSegments(
                    Geometry2D::CLineSegment2D(Geometry2D::CPoint2D(350, -300), Geometry2D::CPoint2D(400, -600)), 4);
            cVectorGraphicsData.addLineSegments(
                    Geometry2D::CLineSegment2D(Geometry2D::CPoint2D(400, -600), Geometry2D::CPoint2D(550, -600)), 4);
            cVectorGraphicsData.addLineSegments(
                    Geometry2D::CLineSegment2D(Geometry2D::CPoint2D(550, -600), Geometry2D::CPoint2D(500, -700)), 4);
            cVectorGraphicsData.addLineSegments(
                    Geometry2D::CLineSegment2D(Geometry2D::CPoint2D(500, -700), Geometry2D::CPoint2D(400, -700)), 4);
            cVectorGraphicsData.addLineSegments(
                    Geometry2D::CLineSegment2D(Geometry2D::CPoint2D(400, -700), Geometry2D::CPoint2D(450, -650)), 4);
            cVectorGraphicsData.addLineSegments(
                    Geometry2D::CLineSegment2D(Geometry2D::CPoint2D(450, -650), Geometry2D::CPoint2D(150, -650)), 4);
            cVectorGraphicsData.addLineSegments(
                    Geometry2D::CLineSegment2D(Geometry2D::CPoint2D(150, -650), Geometry2D::CPoint2D(200, -700)), 4);
            cVectorGraphicsData.addLineSegments(
                    Geometry2D::CLineSegment2D(Geometry2D::CPoint2D(200, -700), Geometry2D::CPoint2D(100, -700)), 4);
            cVectorGraphicsData.addLineSegments(
                    Geometry2D::CLineSegment2D(Geometry2D::CPoint2D(250, -600), Geometry2D::CPoint2D(280, -350)), 4);
            cVectorGraphicsData.addLineSegments(
                    Geometry2D::CLineSegment2D(Geometry2D::CPoint2D(280, -350), Geometry2D::CPoint2D(320, -350)), 4);
            cVectorGraphicsData.addLineSegments(
                    Geometry2D::CLineSegment2D(Geometry2D::CPoint2D(320, -350), Geometry2D::CPoint2D(350, -600)), 4);
            cVectorGraphicsData.addLineSegments(
                    Geometry2D::CLineSegment2D(Geometry2D::CPoint2D(350, -600), Geometry2D::CPoint2D(250, -600)), 4);
            color.setColor("#ABC");
            cVectorGraphicsData.setNextColor(color);
            //Р
            cVectorGraphicsData.addLineSegments(
                    Geometry2D::CLineSegment2D(Geometry2D::CPoint2D(700, -700), Geometry2D::CPoint2D(700, -300)), 5);
            cVectorGraphicsData.addLineSegments(
                    Geometry2D::CLineSegment2D(Geometry2D::CPoint2D(700, -300), Geometry2D::CPoint2D(1000, -300)), 5);
            cVectorGraphicsData.addLineSegments(
                    Geometry2D::CLineSegment2D(Geometry2D::CPoint2D(1000, -300), Geometry2D::CPoint2D(1050, -350)), 5);
            cVectorGraphicsData.addLineSegments(
                    Geometry2D::CLineSegment2D(Geometry2D::CPoint2D(1050, -350), Geometry2D::CPoint2D(1050, -450)), 5);
            cVectorGraphicsData.addLineSegments(
                    Geometry2D::CLineSegment2D(Geometry2D::CPoint2D(1050, -450), Geometry2D::CPoint2D(1000, -500)), 5);
            cVectorGraphicsData.addLineSegments(
                    Geometry2D::CLineSegment2D(Geometry2D::CPoint2D(1000, -500), Geometry2D::CPoint2D(800, -500)), 5);
            cVectorGraphicsData.addLineSegments(
                    Geometry2D::CLineSegment2D(Geometry2D::CPoint2D(800, -500), Geometry2D::CPoint2D(800, -700)), 5);
            cVectorGraphicsData.addLineSegments(
                    Geometry2D::CLineSegment2D(Geometry2D::CPoint2D(800, -700), Geometry2D::CPoint2D(700, -700)), 5);
            cVectorGraphicsData.addLineSegments(
                    Geometry2D::CLineSegment2D(Geometry2D::CPoint2D(850, -350), Geometry2D::CPoint2D(950, -350)), 5);
            cVectorGraphicsData.addLineSegments(
                    Geometry2D::CLineSegment2D(Geometry2D::CPoint2D(950, -350), Geometry2D::CPoint2D(950, -450)), 5);
            cVectorGraphicsData.addLineSegments(
                    Geometry2D::CLineSegment2D(Geometry2D::CPoint2D(950, -450), Geometry2D::CPoint2D(850, -450)), 5);
            cVectorGraphicsData.addLineSegments(
                    Geometry2D::CLineSegment2D(Geometry2D::CPoint2D(850, -450), Geometry2D::CPoint2D(850, -350)), 5);

            return cVectorGraphicsData;

        }

        static CVectorGraphicsData getRhombusData() {
            File2DProcessingTools::CVectorGraphicsData cVectorGraphicsData;

            cVectorGraphicsData.addLineSegments(
                    Geometry2D::CLineSegment2D(Geometry2D::CPoint2D(512, 0), Geometry2D::CPoint2D(1024, 512)));
            cVectorGraphicsData.addLineSegments(
                    Geometry2D::CLineSegment2D(Geometry2D::CPoint2D(1024, 512), Geometry2D::CPoint2D(512, 1024)));
            cVectorGraphicsData.addLineSegments(
                    Geometry2D::CLineSegment2D(Geometry2D::CPoint2D(512, 1024), Geometry2D::CPoint2D(0, 512)));
            cVectorGraphicsData.addLineSegments(
                    Geometry2D::CLineSegment2D(Geometry2D::CPoint2D(0, 512), Geometry2D::CPoint2D(512, 0)));
            return cVectorGraphicsData;
        }

        static CVectorGraphicsData getSquareData() {
            File2DProcessingTools::CVectorGraphicsData cVectorGraphicsData;

            cVectorGraphicsData.addLineSegments(
                    Geometry2D::CLineSegment2D(Geometry2D::CPoint2D(1024, 0), Geometry2D::CPoint2D(2048, 0)));
            cVectorGraphicsData.addLineSegments(
                    Geometry2D::CLineSegment2D(Geometry2D::CPoint2D(2048, 0), Geometry2D::CPoint2D(2048, 1024)));
            cVectorGraphicsData.addLineSegments(
                    Geometry2D::CLineSegment2D(Geometry2D::CPoint2D(2048, 1024), Geometry2D::CPoint2D(1024, 1024)));
            cVectorGraphicsData.addLineSegments(
                    Geometry2D::CLineSegment2D(Geometry2D::CPoint2D(1024, 1024), Geometry2D::CPoint2D(1024, 0)));
            return cVectorGraphicsData;
        }

        std::string TEST_RESOURCES_DIR;
        std::string SVG_PATH;
        std::string DIR_SEPARATOR;


    private:
        constexpr static char getDirectorySeparator() noexcept {
#if defined(_WIN32) || defined(WIN32)
            return '\\';
#else
            return '/';
#endif
        }

    };


    TEST_F(CSvgFileWriterFixture, CSvgFileWritter_write_Test_EFileAlredyExistsException) {
        std::ofstream check_file(SVG_PATH);
        bool isExist = false;
        if (check_file.is_open()) {
            check_file.close();
            isExist = true;
            CSvgFileWriter writer(1024, 1024);
            ASSERT_THROW(writer.write(SVG_PATH, getRhombusData(), false),
                         File2DProcessingTools::Exceptions::EFileAlreadyExistsException);
            EXPECT_TRUE(std::remove(SVG_PATH.c_str()) == 0) << "Failed to delete file.\n";

        }

        ASSERT_TRUE(isExist) << "Test resources are not available\n";

    }

    TEST_F(CSvgFileWriterFixture, CSvgFileWritter_write_Test) {
        bool isExist = true;

        try {
            CSvgFileWriter writer;
            writer.write(SVG_PATH, getRhombusData(), true);
            EXPECT_TRUE(std::remove(SVG_PATH.c_str()) == 0) << "Failed to delete file.\n";
        } catch (std::exception &ex) {
            isExist = false;
        }

        ASSERT_TRUE(isExist);
    }

    TEST_F(CSvgFileWriterFixture, CSvgFileWriter_write_syntax_Test) {
        bool isStandard = true;
        std::string m_error;
        try {
            CSvgFileWriter writer(1024, 1024);;

            writer.write(SVG_PATH, getRhombusData(), false);
            std::ifstream standard_file(TEST_RESOURCES_DIR + DIR_SEPARATOR + "rhombus.svg");
            EXPECT_TRUE(standard_file.is_open()) << "Failed to open standard file.\n";

            std::ifstream test_file(SVG_PATH);
            EXPECT_TRUE(test_file.is_open()) << "Failed to open test file.\n";

            std::string line_standard_file;
            std::string line_test_file;
            while ((std::getline(standard_file, line_standard_file)) && (std::getline(test_file, line_test_file))) {
                if (line_standard_file != line_test_file) {
                    m_error.append("actual: ").append(line_test_file).append(
                            ", but expected: ").append(line_standard_file);
                    isStandard = false;
                    break;
                }
            }
            std::getline(test_file, line_test_file);
            if (!line_standard_file.empty() || !line_test_file.empty()) {
                isStandard = false;
                m_error = "File sizes differ.\n";
            }
            standard_file.close();
            test_file.close();
            EXPECT_TRUE(std::remove(SVG_PATH.c_str()) == 0) << "Failed to delete file.\n";
        } catch (std::exception &ex) {
            m_error = ex.what();
            isStandard = false;
        }


        EXPECT_TRUE(isStandard) << m_error;

    }

    TEST_F(CSvgFileWriterFixture, CSvgFileWriter_writeMul_syntax_Test) {
        std::vector<CVectorGraphicsData> data;
        data.push_back(getRhombusData());
        data.push_back(getSquareData());

        bool isStandard = true;
        std::string m_error;
        try {
            CSvgFileWriter writer(1024, 1024);;

            writer.writeMul(SVG_PATH, data, true);
            std::ifstream standard_file(TEST_RESOURCES_DIR + DIR_SEPARATOR + "rhombus-cube.svg");
            EXPECT_TRUE(standard_file.is_open()) << "Failed to open standard file.\n";

            std::ifstream test_file(SVG_PATH);
            EXPECT_TRUE(test_file.is_open()) << "Failed to open test file.\n";

            std::string line_standard_file;
            std::string line_test_file;
            while ((std::getline(standard_file, line_standard_file)) && (std::getline(test_file, line_test_file))) {
                if (line_standard_file != line_test_file) {
                    m_error.append("actual: ").append(line_test_file).append(
                            ", but expected: ").append(line_standard_file);
                    isStandard = false;
                    break;
                }
            }
            std::getline(test_file, line_test_file);
            if (!line_standard_file.empty() || !line_test_file.empty()) {
                isStandard = false;
                m_error = "File sizes differ.\n";
            }
            standard_file.close();
            test_file.close();
            EXPECT_TRUE(std::remove(SVG_PATH.c_str()) == 0) << "Failed to delete file.\n";
        } catch (std::exception &ex) {
            m_error = ex.what();
            isStandard = false;
        }


        EXPECT_TRUE(isStandard) << m_error;

    }

    TEST_F(CSvgFileWriterFixture, CSvgFileWriter_setCanvasHeight_with_height_default_Test) {
        CSvgFileWriter cSvgFileWriter(100, 100);
        cSvgFileWriter.setCanvasHeight(200);
        cSvgFileWriter.write(SVG_PATH, getRhombusData(), true);
        std::ifstream reader(SVG_PATH);
        EXPECT_TRUE(reader.is_open()) << "Failed to open test file.\n";
        std::string line_file;
        bool checker = false;
        const std::string template_line = R"(<svg height = "200px"  width = "100px" xmlns="http://www.w3.org/2000/svg">)";
        while (std::getline(reader, line_file)) {
            if (line_file == template_line) {
                checker = true;
                break;
            }
        }
        EXPECT_TRUE(checker);
        reader.close();
        EXPECT_TRUE(std::remove(SVG_PATH.c_str()) == 0) << "Failed to delete file.\n";
    }


    TEST_F(CSvgFileWriterFixture, CSvgFileWriter_setCanvasHeight_with_width_default_Test) {
        CSvgFileWriter cSvgFileWriter(100, 100);
        cSvgFileWriter.setCanvasWidth(200);
        cSvgFileWriter.write(SVG_PATH, getRhombusData(), true);
        std::ifstream reader(SVG_PATH);
        EXPECT_TRUE(reader.is_open()) << "Failed to open test file.\n";
        std::string line_file;
        bool checker = false;
        const std::string template_line = R"(<svg height = "100px"  width = "200px" xmlns="http://www.w3.org/2000/svg">)";
        while (std::getline(reader, line_file)) {
            if (line_file == template_line) {
                checker = true;
                break;
            }
        }
        EXPECT_TRUE(checker);
        reader.close();
        EXPECT_TRUE(std::remove(SVG_PATH.c_str()) == 0) << "Failed to delete file.\n";
    }


    TEST_F(CSvgFileWriterFixture, CSvgFileWriter_setCanvasHeight_with_width_and_height_default_Test) {
        CSvgFileWriter cSvgFileWriter(100, 100);
        cSvgFileWriter.setCanvasSize(200, 200);
        cSvgFileWriter.write(SVG_PATH, getRhombusData(), true);
        std::ifstream reader(SVG_PATH);
        EXPECT_TRUE(reader.is_open()) << "Failed to open test file.\n";
        std::string line_file;
        bool checker = false;
        const std::string template_line = R"(<svg height = "200px"  width = "200px" xmlns="http://www.w3.org/2000/svg">)";
        while (std::getline(reader, line_file)) {
            if (line_file == template_line) {
                checker = true;
                break;
            }
        }
        EXPECT_TRUE(checker);
        reader.close();
        EXPECT_TRUE(std::remove(SVG_PATH.c_str()) == 0) << "Failed to delete file.\n";
    }

    TEST_F(CSvgFileWriterFixture, CSvgFileWriter_setAligmentCenter_Test) {
        std::string m_error;
        bool isStandard = true;
        try {
            CSvgFileWriter cSvgFileWriter(1024, 1024);
            cSvgFileWriter.setAlignmentCenter(std::pair<unsigned int, unsigned int>(200, 200));
            cSvgFileWriter.write(SVG_PATH, getRhombusData(), true);
            std::ifstream standard_file(TEST_RESOURCES_DIR + DIR_SEPARATOR + "rhombus_template_center.svg");
            EXPECT_TRUE(standard_file.is_open()) << "Failed to open standard file.\n";

            std::ifstream test_file(SVG_PATH);
            EXPECT_TRUE(test_file.is_open()) << "Failed to open test file.\n";

            std::string line_standard_file;
            std::string line_test_file;
            while ((std::getline(standard_file, line_standard_file)) && (std::getline(test_file, line_test_file))) {
                if (line_standard_file != line_test_file) {
                    m_error.append("actual: ").append(line_test_file).append(
                            ", but expected: ").append(line_standard_file);
                    isStandard = false;
                    break;
                }
            }
            std::getline(test_file, line_test_file);
            if (!line_standard_file.empty() || !line_test_file.empty()) {
                isStandard = false;
                m_error = "File sizes differ.\n";
            }
            standard_file.close();
            test_file.close();
            EXPECT_TRUE(std::remove(SVG_PATH.c_str()) == 0) << "Failed to delete file.\n";
        } catch (std::exception &ex) {
            m_error = ex.what();
            isStandard = false;
        }
        EXPECT_TRUE(isStandard) << m_error;
    }

    TEST_F(CSvgFileWriterFixture, CSvgFileWriter_color_width_Test) {
        std::string m_error;
        bool isStandard = true;
        try {
            CSvgFileWriter cSvgFileWriter(1000, 1000);

            cSvgFileWriter.write(SVG_PATH, getDanyaData(), true);
            std::ifstream standard_file(TEST_RESOURCES_DIR + DIR_SEPARATOR + "test_color_width.svg");
            EXPECT_TRUE(standard_file.is_open()) << "Failed to open standard file.\n";

            std::ifstream test_file(SVG_PATH);
            EXPECT_TRUE(test_file.is_open()) << "Failed to open test file.\n";

            std::string line_standard_file;
            std::string line_test_file;
            while ((std::getline(standard_file, line_standard_file)) && (std::getline(test_file, line_test_file))) {
                if (line_standard_file != line_test_file) {
                    m_error.append("actual: ").append(line_test_file).append(
                            ", but expected: ").append(line_standard_file);
                    isStandard = false;
                    break;
                }
            }
            std::getline(test_file, line_test_file);
            if (!line_standard_file.empty() || !line_test_file.empty()) {
                isStandard = false;
                m_error = "File sizes differ.\n";
            }
            standard_file.close();
            test_file.close();
            EXPECT_TRUE(std::remove(SVG_PATH.c_str()) == 0) << "Failed to delete file.\n";
        } catch (std::exception &ex) {
            m_error = ex.what();
            isStandard = false;
        }
        EXPECT_TRUE(isStandard) << m_error;
    }



}
