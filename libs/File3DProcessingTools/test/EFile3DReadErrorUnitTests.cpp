/**
 * @author Vladislav Yaroshchuk, github.com/shchuko
 * @year 2020
 */

#include <gtest/gtest.h>

#include "EFile3DReadError.hpp"

namespace EFile3DReadErrorUnitTestsNS {
    using namespace File3DProcessingTools;

    TEST(EFile3DReadError, EFile3DReadError_defaut_constructor_what_Test) {
        EFile3DReadError exception;
        EXPECT_STREQ("", exception.what());
    }

    TEST(EFile3DReadError, EFile3DReadError_is_it_std_exception_subclass_Test) {
        bool is_subclass_flag;

        try {
            throw EFile3DReadError();
        } catch (std::exception &e) {
            is_subclass_flag = true;
        } catch (...) {
            is_subclass_flag = false;
        }

        EXPECT_TRUE(is_subclass_flag);
    }

    TEST(EFile3DReadError, EFile3DReadError_parametrized_constructor_what_Test) {
        std::string cause = "some_cause";
        EFile3DReadError exception(cause);
        EXPECT_STREQ(cause.c_str(), exception.what());
    }

}

