
#include <gtest/gtest.h>
#include <CPoint2D.hpp>
#include <random>
#include <CPath.hpp>

namespace File2DProcessingTools {


    class CPathFixture : public ::testing::Test {
    private:
        unsigned int number_of_CPaths = 0;
        std::default_random_engine *random_gen = nullptr;
        std::uniform_real_distribution<double> *distribution = nullptr;
    protected:
        void SetUp() override {
            random_gen = new std::default_random_engine{std::random_device()()};
            distribution = new std::uniform_real_distribution<double>(-std::numeric_limits<double>::max(),
                                                                      std::numeric_limits<double>::max());
        }

        void TearDown() override {
            delete distribution;
            delete random_gen;
        }

        unsigned int getSizesCPaths() const {
            return number_of_CPaths;
        }

        int nextRandomInt() {
            return std::ceil((*distribution)(*random_gen));
        }

        double nextRandomDouble() {
            return (*distribution)(*random_gen);
        }

        Geometry2D::CPoint2D nextRandomCPoint2D() {
            return {nextRandomDouble(), nextRandomDouble()};
        }

        CPath generateCPath(unsigned int size) {
            CPath cPath;
            int type_of_point = nextRandomInt();
            for (unsigned int i = 0; i < size; ++i) {
                switch (type_of_point) {
                    case 0:
                        cPath.appendPoint(Geometry2D::CPoint2D(std::numeric_limits<double>::quiet_NaN(),
                                nextRandomDouble()));
                        if (i > 0 && (cPath.getPoints()[i - 1].getX() != std::numeric_limits<double>::quiet_NaN() &&
                                      cPath.getPoints()[i - 1].getY() != std::numeric_limits<double>::quiet_NaN()))
                            ++number_of_CPaths;
                        break;
                    case 1:
                        cPath.appendPoint(Geometry2D::CPoint2D(nextRandomDouble(),
                                std::numeric_limits<double>::quiet_NaN()));
                        if (i > 0 && (cPath.getPoints()[i - 1].getX() != std::numeric_limits<double>::quiet_NaN() &&
                                      cPath.getPoints()[i - 1].getY() != std::numeric_limits<double>::quiet_NaN()))
                            ++number_of_CPaths;
                        break;
                    case 2:
                        cPath.appendPoint(Geometry2D::CPoint2D(std::numeric_limits<double>::quiet_NaN(),
                                std::numeric_limits<double>::quiet_NaN()));
                        if (i > 0 && (cPath.getPoints()[i - 1].getX() != std::numeric_limits<double>::quiet_NaN() &&
                                      cPath.getPoints()[i - 1].getY() != std::numeric_limits<double>::quiet_NaN()))
                            ++number_of_CPaths;
                        break;
                    default:
                        cPath.appendPoint(Geometry2D::CPoint2D(nextRandomCPoint2D()));
                        break;
                }
            }
            return cPath;
        }

    };

    TEST_F(CPathFixture, CPath_toSeparatedPaths_size_Test) {
        for (int i = 0; i < 100; ++i) {
            CPath cPath = generateCPath(i);
            std::vector<CPath> paths = cPath.toSeparatedPaths();
            EXPECT_EQ(paths.size(), getSizesCPaths()) << "Expected: " + std::to_string(getSizesCPaths()) +
            ", Actual: " + std::to_string(paths.size());
        }
    }

}