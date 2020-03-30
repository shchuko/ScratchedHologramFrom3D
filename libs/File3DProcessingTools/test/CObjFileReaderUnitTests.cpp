#include <gtest/gtest.h>
#include <regex>

#include "Geometry3DOperators.hpp"
#include "CObject3DData.hpp"
#include "CObjFileReader.hpp"
#include "EFile3DReadError.hpp"


namespace CObjFileReaderUnitTestsNS {
    using namespace File3DProcessingTools;

    class CObjFileReaderFixture : public ::testing::Test {
    private:
        std::string DIR_SEPARATOR;
        std::string PROJECT_ROOT;
        std::string TEST_RESOURCES_DIR;

    protected:
        void SetUp() override {
            DIR_SEPARATOR = getDirectorySeparator();
            PROJECT_ROOT = std::regex_replace(PROJECT_SOURCE_DIR, std::regex("/"), DIR_SEPARATOR);
            TEST_RESOURCES_DIR = PROJECT_ROOT + DIR_SEPARATOR + "test_resources";

            CUBE_PATH = TEST_RESOURCES_DIR + DIR_SEPARATOR + "cube.obj";
            NOT_EXISTING_FILE_PATH = TEST_RESOURCES_DIR + DIR_SEPARATOR + "file_not_exists.obj";
            UNSUPPORTED_OBJ_FILE_PATH = TEST_RESOURCES_DIR + DIR_SEPARATOR + "unsupported.obj";
        }

        void TearDown() override {
        }

        void parsedExpectedEqualsCheck() noexcept {
            EXPECT_EQ(expected_data.getVertexes(), parsed_data.getVertexes()) << "Vertexes information is wrong";
            EXPECT_EQ(expected_data.getPolygonNormals(), parsed_data.getPolygonNormals())
                                << "Normal vectors information is wrong";
            EXPECT_EQ(expected_data.getPolygons().size(), parsed_data.getPolygons().size())
                                << "Polygons information is wrong";

            for (std::vector<CPolygon>::size_type i = 0; i < expected_data.getPolygons().size(); ++i) {
                const auto &expected_poly = expected_data.getPolygons()[i];
                const auto &parsed_poly = parsed_data.getPolygons()[i];

                EXPECT_TRUE(parsed_poly.isReadonly()) << "Polygon is not readonly";
                EXPECT_EQ(expected_poly.getEdges(), parsed_poly.getEdges()) << "Polygon edges information is wrong";
                EXPECT_EQ(expected_poly.getNormalVectorIndex(), parsed_poly.getNormalVectorIndex())
                                    << "Polygon normal vector information is wrong";

            }
        }

        std::string CUBE_PATH;
        std::string NOT_EXISTING_FILE_PATH;
        std::string UNSUPPORTED_OBJ_FILE_PATH;

        CObject3DData parsed_data;
        CObject3DData expected_data;

    private:
        static inline std::string getDirectorySeparator() {
#if defined(_WIN32) || defined(WIN32)
            return "\\";
#else
            return "/";
#endif
        }
    };

    TEST_F(CObjFileReaderFixture, CObjFileReader_no_file_throw_exception_Test) {
        CObjFileReader reader;
        EXPECT_THROW(reader.readFile(NOT_EXISTING_FILE_PATH, parsed_data), EFile3DReadError);
    }

    TEST_F(CObjFileReaderFixture, CObjFileReader_unsopported_obj_file_throw_exception_Test) {
        CObjFileReader reader;
        EXPECT_THROW(reader.readFile(UNSUPPORTED_OBJ_FILE_PATH, parsed_data), EFile3DReadError);
    }

    TEST_F(CObjFileReaderFixture, CObjFileReader_read_cube_Test) {
        CObjFileReader().readFile(CUBE_PATH, parsed_data);

        expected_data.addVertex({-1.000000, -1.000000, 1.000000});
        expected_data.addVertex({-1.000000, 1.000000, 1.000000});
        expected_data.addVertex({-1.000000, -1.000000, -1.000000});
        expected_data.addVertex({-1.000000, 1.000000, -1.000000});
        expected_data.addVertex({1.000000, -1.000000, 1.000000});
        expected_data.addVertex({1.000000, 1.000000, 1.000000});
        expected_data.addVertex({1.000000, -1.000000, -1.000000});
        expected_data.addVertex({1.000000, 1.000000, -1.000000});

        expected_data.addPolygonNormal({-1.0000, 0.0000, 0.0000});
        expected_data.addPolygonNormal({0.0000, 0.0000, -1.0000});
        expected_data.addPolygonNormal({1.0000, 0.0000, 0.0000});
        expected_data.addPolygonNormal({0.0000, 0.0000, 1.0000});
        expected_data.addPolygonNormal({0.0000, -1.0000, 0.0000});
        expected_data.addPolygonNormal({0.0000, 1.0000, 0.0000});

        CPolygon p1(0);
        p1.addEdge(0, 1);
        p1.addEdge(1, 3);
        p1.addEdge(3, 2);
        p1.addEdge(2, 0);
        p1.makeReadonly();
        expected_data.addPolygon(p1);

        CPolygon p2(1);
        p2.addEdge(2, 3);
        p2.addEdge(3, 7);
        p2.addEdge(7, 6);
        p2.addEdge(6, 2);
        p2.makeReadonly();
        expected_data.addPolygon(p2);

        CPolygon p3(2);
        p3.addEdge(6, 7);
        p3.addEdge(7, 5);
        p3.addEdge(5, 4);
        p3.addEdge(4, 6);
        p3.makeReadonly();
        expected_data.addPolygon(p3);

        CPolygon p4(3);
        p4.addEdge(4, 5);
        p4.addEdge(5, 1);
        p4.addEdge(1, 0);
        p4.addEdge(0, 4);
        p4.makeReadonly();
        expected_data.addPolygon(p4);

        CPolygon p5(4);
        p5.addEdge(2, 6);
        p5.addEdge(6, 4);
        p5.addEdge(4, 0);
        p5.addEdge(0, 2);
        p5.makeReadonly();
        expected_data.addPolygon(p5);

        CPolygon p6(5);
        p6.addEdge(7, 3);
        p6.addEdge(3, 1);
        p6.addEdge(1, 5);
        p6.addEdge(5, 7);
        p6.makeReadonly();
        expected_data.addPolygon(p6);

        parsedExpectedEqualsCheck();
    }
}
