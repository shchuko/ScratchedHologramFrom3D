#include <gtest/gtest.h>
#include <EOptionBuildError.hpp>

#include "COptionBuilder.hpp"

namespace CliTools {


    TEST(COption, getShortName) {
        COptionBuilder cOptionBuilder{};
        cOptionBuilder.addShortName('a');
        char expected = 'a';
        char actual = cOptionBuilder.build().getShortName();
        ASSERT_EQ(expected, actual) << "Short name received incorrectly";
    }

    TEST(COption, getLongName) {
        COptionBuilder cOptionBuilder{};
        cOptionBuilder.addLongName("testString");
        std::string expected = "testString";
        std::string actual = cOptionBuilder.build().getLongName();
        ASSERT_STREQ(expected.c_str(), actual.c_str()) << "Long name received incorrectly";
    }

    TEST(COption, getDescription) {
        COptionBuilder cOptionBuilder{};
        cOptionBuilder.addLongName("Test");
        cOptionBuilder.addDescription("Some description");
        std::string expected = "Some description";
        std::string actual = cOptionBuilder.build().getDescription();
        ASSERT_STREQ(expected.c_str(), actual.c_str()) << "Description received incorrectly";
    }

    TEST(COption, isRequired) {
        COptionBuilder cOptionBuilder{};
        cOptionBuilder.addLongName("Test");

        // Option entered
        cOptionBuilder.setValue("value");
        bool actual = cOptionBuilder.build().isRequired();
        ASSERT_FALSE(actual) << "Argument isn't mandatory";

        // Option entered
        cOptionBuilder.setValue("value", true);
        actual = cOptionBuilder.build().isRequired();
        ASSERT_TRUE(actual) << "Argument is mandatory";
    }

    TEST(COption, isHasArgument) {
        COptionBuilder cOptionBuilder{};
        cOptionBuilder.addLongName("Test");

        bool actual = cOptionBuilder.build().isHasArgument();
        ASSERT_FALSE(actual) << "Argument wasn't entered and expected FALSE, but actual TRUE";

        cOptionBuilder.setValue("value");
        actual = cOptionBuilder.build().isHasArgument();
        ASSERT_TRUE(actual) << "Argument was entered and expected TRUE, but actual FALSE";
    }

    // Test: lack of parameters, but the required input - true
    TEST(COptionBuilder, build_no_arguments) {
        COptionBuilder cOptionBuilder;
        bool isException = false;
        cOptionBuilder.addLongName("test");
        cOptionBuilder.setValue(false, true);
        const char *expected = "No arguments, but it's required";
        try {
            cOptionBuilder.build();
        } catch (Exceptions::EOptionBuildError &error) {
            EXPECT_STREQ(expected, error.what()) << "Incorrect the text of error";
            isException = true;
        }

        EXPECT_TRUE(isException) << "Excepted exception, but it wasn't";

    }

    // Test: lack of options
    TEST(COptionBuilder, build_no_option_names) {
        COptionBuilder cOptionBuilder;
        bool isException = false;
        const char *expectedTest2 = "Not enough arguments: full name option, short name option";
        try {
            cOptionBuilder.build();
        } catch (Exceptions::EOptionBuildError &error) {
            EXPECT_STREQ(expectedTest2, error.what()) << "Incorrect the text of error";
            isException = true;
        }
        EXPECT_TRUE(isException) << "Excepted exception, but it wasn't";
    }

}
