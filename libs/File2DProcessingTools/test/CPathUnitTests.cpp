
#include <gtest/gtest.h>
#include <CPoint2D.hpp>
#include <Geometry2DOperators.hpp>
#include <random>
#include <CPath.hpp>

namespace File2DProcessingTools {


    class CPathFixture : public ::testing::Test {
    private:
        std::default_random_engine *random_gen = nullptr;
        std::uniform_real_distribution<double> *distribution = nullptr;
        bool _isCycled = true;

    protected:
        void SetUp() override {
            const int MAX_RANGE = 10000000;
            random_gen = new std::default_random_engine{std::random_device()()};
            distribution = new std::uniform_real_distribution<double>(-MAX_RANGE, MAX_RANGE);
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


        bool getIsCycle() const {
            return _isCycled;
        }


        CPath generateRandomPath(unsigned int size, unsigned int& path_count) {
            constexpr double bernoulli_distribution_k = 0.8;
            std::bernoulli_distribution bernoulli_distribution(bernoulli_distribution_k);

            CPath path;
            for (unsigned int i = 0; i < size; ++i) {
                if (bernoulli_distribution(*random_gen)) {
                    path.appendPoint(nextRandomCPoint2D());
                } else {
                    constexpr double nan_val = std::numeric_limits<double>::quiet_NaN();
                    path.appendPoint({nan_val, nan_val});
                }
            }

            path_count = 0;
            bool previousWasNaN = true;
            for (const auto &point : path.getPoints()) {
                if (!std::isnormal(point.getX()) || !std::isnormal(point.getY())) {
                    previousWasNaN = true;
                } else if (previousWasNaN) {
                    previousWasNaN = false;
                    ++path_count;
                }
            }
            return path;
        }


        CPath getCycledPath(unsigned int size) {
            CPath path;
            if (size == 1) {
                return path;
            }

            for (unsigned int i = 0; i < size - 1; ++i) {
                path.appendPoint(nextRandomCPoint2D());
            }

            path.appendPoint(path.getPoints()[0]);
            return path;
        }

        CPath getNotCycledPath(unsigned int size) {
            CPath path;
            if (size == 1) {
                path.appendPoint(nextRandomCPoint2D());
                return path;
            }

            for (unsigned int i = 0; i < size - 1; ++i) {
                path.appendPoint(nextRandomCPoint2D());
            }

            const Geometry2D::CPoint2D &first_point = path.getPoints()[0];
            Geometry2D::CPoint2D last_point = nextRandomCPoint2D();
            while (last_point == first_point) {
                last_point = nextRandomCPoint2D();
            }

            path.appendPoint(last_point);
            return path;
        }
    };

    TEST_F(CPathFixture, CPath_toSeparatedPaths_size_Test) {
        for (int i = 1; i < 1000; ++i) {
            unsigned int count_paths = 0;
            CPath cPath = generateRandomPath(i, count_paths);
            std::vector<CPath> paths = cPath.toSeparatedPaths();

            EXPECT_EQ(paths.size(), count_paths) << "Expected: " << count_paths
                                                 << ", Actual: " << paths.size();
        }
    }


    TEST_F(CPathFixture, CPath_toSeparatedPaths_data_Test) {
        for (int i = 1; i < 1000; ++i) {
            unsigned int count_paths = 0;
            CPath cPath = generateRandomPath(i, count_paths);
            std::vector<CPath> separatedPaths = cPath.toSeparatedPaths();

            unsigned int separatedPathNo = 0;
            unsigned int separatedPathPointNo = 0;
            bool splitPointFound = true;
            for (unsigned int pointNo = 0; pointNo < cPath.getPoints().size(); ++pointNo) {
                const auto &point = cPath.getPoints()[pointNo];

                if (std::isnormal(point.getX()) && std::isnormal(point.getY())) {
                    splitPointFound = false;

                    EXPECT_EQ(point, separatedPaths[separatedPathNo].getPoints()[separatedPathPointNo]);
                    ++separatedPathPointNo;
                } else if (!splitPointFound) {
                    splitPointFound = true;

                    ++separatedPathNo;
                    separatedPathPointNo = 0;
                }
            }
        }
    }

    TEST_F(CPathFixture, CPath_updateCycled_isCycled_Test) {
        for (int i = 1; i < 1000; ++i) {
            CPath cPath = getNotCycledPath(i);
            cPath.updateCycled();
            EXPECT_FALSE( cPath.isCycled());
        }

        for (int i = 2; i < 1000; ++i) {
            CPath cPath = getCycledPath(i);
            cPath.updateCycled();
            EXPECT_TRUE( cPath.isCycled());
        }
    }

}