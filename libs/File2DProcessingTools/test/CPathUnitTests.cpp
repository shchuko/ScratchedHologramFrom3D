
#include <gtest/gtest.h>
#include <CPoint2D.hpp>
#include <random>
#include <CPath.hpp>

namespace File2DProcessingTools {


    class CPathFixture : public ::testing::Test {
    private:
        std::default_random_engine *random_gen = nullptr;
        std::uniform_real_distribution<double> *distribution = nullptr;
        bool _isCycled = true;
        std::vector<CPath> without_nan_CPath;
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

        unsigned int nextRandomInt(unsigned int begin,unsigned int end) {
            auto *int_distribution = new std::uniform_int_distribution<unsigned int>(begin, end);
            return std::ceil((*int_distribution)(*random_gen));
        }

        double nextRandomDouble() {
            return (*distribution)(*random_gen);
        }

        Geometry2D::CPoint2D nextRandomCPoint2D() {
            return {nextRandomDouble(), nextRandomDouble()};
        }

        CPath getValueCPath(unsigned int size){
            CPath value_CPath;
            for (unsigned int i = 0; i < size; ++i) {
                value_CPath.appendPoint(nextRandomCPoint2D());
            }
            return value_CPath;
        }

        CPath getPartNaNCPath(unsigned int size){
            CPath value_CPath;
            std::random_device rd;
            std::mt19937 gen(rd());
            for (unsigned int i = 0; i < size; ++i) {
                std::bernoulli_distribution distribution_bernoulli(0.5);
                if (distribution_bernoulli(gen)) {
                    value_CPath.appendPoint(Geometry2D::CPoint2D(nextRandomDouble(),
                                                                 std::numeric_limits<double>::quiet_NaN()));
                } else {
                    value_CPath.appendPoint(Geometry2D::CPoint2D(std::numeric_limits<double>::quiet_NaN(),
                                                                 nextRandomDouble()));
                }
            }
            return value_CPath;
        }

        static CPath getFullNaNCPath(unsigned int size){
            CPath value_CPath;
            for (unsigned int i = 0; i < size; ++i) {
                value_CPath.appendPoint(Geometry2D::CPoint2D(std::numeric_limits<double>::quiet_NaN(),
                                                             std::numeric_limits<double>::quiet_NaN()));
            }
            return value_CPath;
        }

        bool getIsCycle() const {
            return _isCycled;
        }

        std::vector<CPath> getPathsWithoutNaN() {
            return without_nan_CPath;
        }


        CPath generateCPath(unsigned int size, unsigned int &count_paths) {
            CPath cPath;
            without_nan_CPath.clear();
            unsigned int type_of_point = nextRandomInt(0, 20);
            unsigned int size_of_parts = nextRandomInt(1, size);
            CPath part_cPath;
            bool isPrevNaN = true;
            while (size > 0) {
                size -= size_of_parts;
                switch (type_of_point) {
                    case 0:
                        part_cPath = getPartNaNCPath(size_of_parts);
                        cPath.appendPath(part_cPath);
                        isPrevNaN = true;
                        _isCycled = false;
                        break;
                    case 1:
                        part_cPath = getFullNaNCPath(size_of_parts);
                        cPath.appendPath(part_cPath);
                        isPrevNaN = true;
                        _isCycled = false;
                        break;
                    default:
                        part_cPath = getValueCPath(size_of_parts);
                        cPath.appendPath(part_cPath);
                        if (isPrevNaN) {
                            without_nan_CPath.emplace_back(part_cPath);
                            ++count_paths;
                        } else {
                            without_nan_CPath[without_nan_CPath.size() - 1].appendPath(part_cPath);
                        }
                        isPrevNaN = false;
                        break;
                }
                size_of_parts = nextRandomInt(0, size);
            }
            _isCycled = _isCycled && cPath.getPoints().size() > 1;
            if (cPath.getPoints().size() > 1) {
                _isCycled = _isCycled &&
                        cPath.getPoints()[0].getX() == cPath.getPoints()[cPath.getPoints().size() - 1].getX() &&
                        cPath.getPoints()[0].getY() == cPath.getPoints()[cPath.getPoints().size() - 1].getY();
            }
            return cPath;
        }

    };

    TEST_F(CPathFixture, CPath_toSeparatedPaths_size_Test) {
        for (int i = 1; i < 1000; ++i) {
            unsigned int count_paths = 0;
            CPath cPath = generateCPath(i, count_paths);
            std::vector<CPath> paths = cPath.toSeparatedPaths();
            EXPECT_EQ(paths.size(), count_paths) << "Expected: " + std::to_string(count_paths) +
                                                    ", Actual: " + std::to_string(paths.size());
        }
    }


    TEST_F(CPathFixture, CPath_toSeparatedPaths_data_Test) {
        for (int i = 1; i < 1000; ++i) {
            unsigned int count_paths = 0;
            CPath cPath = generateCPath(i, count_paths);
            std::vector<CPath> paths = cPath.toSeparatedPaths();
            for ( unsigned int j = 0; j < count_paths; ++j) {
                bool isEqually;
                std::vector<Geometry2D::CPoint2D> actual_points = paths[j].getPoints();
                std::vector<Geometry2D::CPoint2D> expected_points = getPathsWithoutNaN()[j].getPoints();
                if (actual_points.size() != expected_points.size()) {
                    isEqually = false;
                    EXPECT_TRUE(isEqually) << "Actual size: " + std::to_string(actual_points.size()) + ", Expected size: "
                                        + std::to_string(expected_points.size());
                    break;
                }
                for (unsigned int k = 0; k < actual_points.size(); ++k) {
                    isEqually = actual_points[k].getX() == expected_points[k].getX() &&
                            actual_points[k].getY() == expected_points[k].getY();
                    EXPECT_TRUE(isEqually);
                }
            }
        }
    }

    TEST_F(CPathFixture, CPath_updateCicled_Test) {
        for (int i = 1; i < 1000; ++i) {
            unsigned int count_paths = 0;
            CPath cPath = generateCPath(i, count_paths);
            cPath.updateCycled();
            EXPECT_EQ(getIsCycle(), cPath.isCycled());
        }
    }

}