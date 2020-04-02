#include "EFileAlreadyExistsException.hpp"
#include <gtest/gtest.h>

namespace File2DProcessingTools {
    namespace Exceptions {

        TEST(EFileAlreadyExistsException, EFileAlreadyExistsException_std_exception_inheritance_Test) {
            bool thrown;
            try {
                throw EFileAlreadyExistsException();
            } catch (std::exception &e) {
                thrown = true;
            } catch (...) {
                thrown = false;
            }

            EXPECT_TRUE(
                    thrown) << "File2DProcessingTools::Exceptions::EFileAlreadyExistsException does not inherit std::exception"
                            << std::endl;
        }


        TEST(EFileAlreadyExistsException, EFileAlreadyExistsException_test_message_with_empty_constructor) {
            bool thrown;
            try {
                throw EFileAlreadyExistsException();
            } catch (std::exception &error) {
                EXPECT_EQ(std::string(error.what()), "")
                                    << "An empty message was expected, but received: " + std::string(error.what());
                thrown = true;
            }

            EXPECT_TRUE(thrown) << "does not throw an exception when the constructor is empty";

        }

        TEST(EFileAlreadyExistsException, EFileAlreadyExistsException_test_message) {
            bool thrown;
            std::string expected = "test message";
            try {
                throw EFileAlreadyExistsException(expected);
            } catch (std::exception &error) {
                EXPECT_EQ(std::string(error.what()), expected)
                                    << "Expected: test message , but received: " + std::string(error.what());
                thrown = true;
            }

            EXPECT_TRUE(thrown) << "does not throw an exception when an argument is passed to the constructor";

        }


    }

}