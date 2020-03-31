#include <ERequiredOptionNotPresent.hpp>
#include "gtest/gtest.h"

namespace CliTools {
    namespace Exceptions {

        TEST(ERequiredOptionNotPresent, ERequiredOptionNotPresent_std_exception_inheritance_Test) {
            bool thrown;
            try {
                throw ERequiredOptionNotPresent();
            } catch (std::exception &e) {
                thrown = true;
            } catch (...) {
                thrown = false;
            }

            EXPECT_TRUE(thrown) << "CliTools::EOptionBuildError does not inherit std::exception" << std::endl;
        }


        TEST(ERequiredOptionNotPresent, ERequiredOptionNotPresent_test_message_with_empty_constructor) {
            bool thrown;
            try {
                throw ERequiredOptionNotPresent();
            } catch (std::exception &error) {
                EXPECT_EQ(std::string(error.what()), "")
                                    << "An empty message was expected, but received: " + std::string(error.what());
                thrown = true;
            }

            EXPECT_TRUE(thrown) << "does not throw an exception when the constructor is empty";

        }

        TEST(ERequiredOptionNotPresent, ERequiredOptionNotPresent_test_message) {
            bool thrown;
            std::string expected = "test message";
            try {
                throw ERequiredOptionNotPresent(expected);
            } catch (std::exception &error) {
                EXPECT_EQ(std::string(error.what()), expected)
                                    << "Expected: test message , but received: " + std::string(error.what());
                thrown = true;
            }

            EXPECT_TRUE(thrown) << "does not throw an exception when an argument is passed to the constructor";

        }

    }
}