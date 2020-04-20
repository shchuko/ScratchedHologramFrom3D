/**
 * @author Vladislav Yaroshchuk, github.com/shchuko
 */

#include <gtest/gtest.h>
#include <EWrongObjectsPosition.hpp>
#include <exception>

namespace EWrongObjectPositionUnitTestsNS {
    using namespace ScratchProjectionMaths::Exceptions;

    TEST(EWrongObjectsPosition, EWrongObjectsPosition_inherits_std_exception_Test) {
        try {
            throw EWrongObjectsPosition();
        } catch (std::exception &e) {
            GTEST_SUCCEED();
        } catch (...) {
            GTEST_FAIL();
        }
    }

    TEST(EWrongObjectsPosition, EWrongObjectsPosition_base_constructor_Test) {
        try {
            throw EWrongObjectsPosition();
        } catch (EWrongObjectsPosition &e) {
            EXPECT_STREQ("", e.what());
        } catch (...) {
            GTEST_FAIL();
        }
    }

    TEST(EWrongObjectsPosition, EWrongObjectsPosition_cause_constructor_Test) {
        std::string message = "SomeMessage";

        try {
            throw EWrongObjectsPosition(message);
        } catch (EWrongObjectsPosition &e) {
            EXPECT_STREQ(message.c_str(), e.what());
        } catch (...) {
            GTEST_FAIL();
        }
    }
}
