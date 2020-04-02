
#include <gtest/gtest.h>
#include <random>
#include <CPoint2D.hpp>
#include <CLineSegment2D.hpp>
#include <CVectorGraphicsData.hpp>
#include <CSvgFileWriter.hpp>
#include <EFileAlreadyExistsException.hpp>

namespace File2DProcessingTools {

    class CSvgFileWriterFixture : public ::testing::Test {
    private:

    protected:
        void SetUp() override {
            data_fixture.addLineSegments(
                    Geometry2D::CLineSegment2D(Geometry2D::CPoint2D(1, 2),
                                               Geometry2D::CPoint2D(3, 4)));

            data_fixture.addLineSegments(
                    Geometry2D::CLineSegment2D(Geometry2D::CPoint2D(5, 6),
                                               Geometry2D::CPoint2D(7, 8)));
        }

        void TearDown() override {}


        CVectorGraphicsData getFixtureCopy() {
            auto copy = data_fixture;
            return copy;
        }

        CVectorGraphicsData data_fixture;


    };


    TEST_F(CSvgFileWriterFixture, CSvgFileWritter_write_Test_EFileAlredyExistsException) {
        const char *nameFile = "testFileExists.svg";
        std::ofstream check_file(nameFile);
        bool isExist = false;
        if (check_file.is_open()) {
            check_file.close();
            isExist = true;
            CSvgFileWriter writer(1024, 1024);
            ASSERT_THROW(writer.write(nameFile, getFixtureCopy(), false),
                         File2DProcessingTools::Exceptions::EFileAlreadyExistsException);
            if (remove(nameFile) == 1) {
                std::cerr << "Failed to delete file.\n";
            }
        }

        ASSERT_TRUE(isExist);

    }

    TEST_F(CSvgFileWriterFixture, CSvgFileWritter_write_Test) {
        const char *nameFile = "testFileExists.svg";
        bool isExist = true;

        try {
            CSvgFileWriter writer;
            writer.write(nameFile, getFixtureCopy(), true);
            if (remove(nameFile) == 1) {
                std::cerr << "Failed to delete file.\n";
            }
        } catch (std::exception &ex) {
            isExist = false;
        }

        ASSERT_TRUE(isExist);

    }
}
