#include "EOptionBuildError.hpp"
#include "COptionBuilder.hpp"
#include "gtest/gtest.h"

namespace CliTools {
    namespace Exceptions {

        TEST(EOptionBuildError, EOptionBuildError_std_exception_inheritance_Test) {
            bool thrown;
            try {
                throw EOptionBuildError();
            } catch (std::exception &e) {
                thrown = true;
            } catch (...) {
                thrown = false;
            }

            EXPECT_TRUE(thrown) << "CliTools::EOptionBuildError does not inherit std::exception" << std::endl;
        }

        TEST(EOptionBuildError, EOptionBuildError_test_message_with_empty_constructor) {
            bool thrown;
            try {
                throw EOptionBuildError();
            } catch (std::exception &error) {
                EXPECT_EQ(std::string(error.what()), "")
                                    << "An empty message was expected, but received: " + std::string(error.what());
                thrown = true;
            }

            EXPECT_TRUE(thrown) << "does not throw an exception when the constructor is empty";

        }

        TEST(EOptionBuildError, EOptionBuildError_test_message) {
            bool thrown;
            std::string expected = "test message";
            try {
                throw EOptionBuildError(expected);
            } catch (std::exception &error) {
                EXPECT_EQ(std::string(error.what()), expected)
                                    << "Expected: test message , but received: " + std::string(error.what());
                thrown = true;
            }

            EXPECT_TRUE(thrown) << "does not throw an exception when an argument is passed to the constructor";

        }

    }

}
