
#include <gtest/gtest.h>
#include <CPoint2D.hpp>
#include <random>
#include <CPath.hpp>

namespace File2DProcessingTools {

    class CPathFixture : public ::testing::Test {
    private:
        static constexpr double DOUBLE_MAX_VALUE = 127152.394;
        static constexpr int INT_MAX_VALUE = 12821734;

        unsigned int number_of_CPaths = 0;
        std::default_random_engine *random_gen = nullptr;
        std::uniform_real_distribution<double> *double_distribution = nullptr;
        std::uniform_int_distribution<int> *int_distribution = nullptr;

    protected:
        void SetUp() override {
            random_gen = new std::default_random_engine{std::random_device()()};
            double_distribution = new std::uniform_real_distribution<double>(-DOUBLE_MAX_VALUE, DOUBLE_MAX_VALUE);
            int_distribution = new std::uniform_int_distribution<int>(-INT_MAX_VALUE, INT_MAX_VALUE);
        }

        void TearDown() override {
            delete double_distribution;
            delete int_distribution;
            delete random_gen;
        }

        unsigned int getSizesCPaths() const {
            return number_of_CPaths;
        }

        int nextRandomInt() {
            return (*int_distribution)(*random_gen);
        }

        double nextRandomDouble() {
            return (*double_distribution)(*random_gen);
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