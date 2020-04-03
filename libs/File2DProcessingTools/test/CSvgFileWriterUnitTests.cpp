#include <gtest/gtest.h>
#include <cstdio>
#include <CPoint2D.hpp>
#include <CLineSegment2D.hpp>
#include <CVectorGraphicsData.hpp>
#include <CSvgFileWriter.hpp>
#include <EFileAlreadyExistsException.hpp>
#include <algorithm>
#include <EFileCannotBeOverwritten.hpp>

namespace File2DProcessingTools {

    class CSvgFileWriterFixture : public ::testing::Test {
    private:
        std::string PROJECT_ROOT;

    protected:
        void SetUp() override {
            data_fixture.addLineSegments(
                    Geometry2D::CLineSegment2D(Geometry2D::CPoint2D(1, 2),
                                               Geometry2D::CPoint2D(3, 4)));

            data_fixture.addLineSegments(
                    Geometry2D::CLineSegment2D(Geometry2D::CPoint2D(5, 6),
                                               Geometry2D::CPoint2D(7, 8)));

            DIR_SEPARATOR = getDirectorySeparator();
            PROJECT_ROOT = PROJECT_SOURCE_DIR;
            std::replace(PROJECT_ROOT.begin(), PROJECT_ROOT.end(), '/', DIR_SEPARATOR[0]);
            TEST_RESOURCES_DIR = PROJECT_ROOT + DIR_SEPARATOR + "test_resources";

            SVG_PATH = TEST_RESOURCES_DIR + DIR_SEPARATOR + "test.svg";
        }

        void TearDown() override {}


        CVectorGraphicsData getFixtureCopy() {
            return data_fixture;
        }

        static CVectorGraphicsData getSquareData() {
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

        std::string TEST_RESOURCES_DIR;
        std::string SVG_PATH;
        std::string DIR_SEPARATOR;
        CVectorGraphicsData data_fixture;


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
            ASSERT_THROW(writer.write(SVG_PATH, getFixtureCopy(), false),
                         File2DProcessingTools::Exceptions::EFileAlreadyExistsException);
            EXPECT_TRUE(std::remove(SVG_PATH.c_str()) == 0) << "Failed to delete file.\n";

        }

        ASSERT_TRUE(isExist) << "Test resources are not available\n";

    }

    TEST_F(CSvgFileWriterFixture, CSvgFileWritter_write_Test) {
        bool isExist = true;

        try {
            CSvgFileWriter writer;
            writer.write(SVG_PATH, getFixtureCopy(), true);
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

            writer.write(SVG_PATH, getSquareData(), false);
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
            if (!line_standard_file.empty() || !line_test_file.empty()){
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
