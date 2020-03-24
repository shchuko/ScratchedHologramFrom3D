#include <gtest/gtest.h>
#include <EOptionBuildError.hpp>

#include "COptionBuilder.hpp"

namespace CliTools {


    TEST(COption, COption_getShortName_Test) {
        COptionBuilder cOptionBuilder{};
        char expected = 'a';
        cOptionBuilder.addShortName(expected);
        char actual = cOptionBuilder.build().getShortName();
        EXPECT_EQ(expected, actual) << "Short name received incorrectly";
    }

    TEST(COption, COption_getLongName_Test) {
        COptionBuilder cOptionBuilder{};
        std::string expected = "testString";
        cOptionBuilder.addLongName(expected);
        std::string actual = cOptionBuilder.build().getLongName();
        EXPECT_STREQ(expected.c_str(), actual.c_str()) << "Long name received incorrectly";
    }

    TEST(COption, COption_getDescription_Test) {
        COptionBuilder cOptionBuilder{};
        std::string expected = "Some description";
        cOptionBuilder.addLongName("Test");
        cOptionBuilder.addDescription(expected);
        std::string actual = cOptionBuilder.build().getDescription();
        EXPECT_STREQ(expected.c_str(), actual.c_str()) << "Description received incorrectly";
    }

    TEST(COption, COption_isRequired_Test) {
        COptionBuilder cOptionBuilder{};
        cOptionBuilder.addLongName("Test");

        // Option entered
        cOptionBuilder.setValue(true, false);
        bool actual = cOptionBuilder.build().isRequired();
        EXPECT_FALSE(actual) << "Argument isn't mandatory";

        // Option entered
        cOptionBuilder.setValue(true, true);
        actual = cOptionBuilder.build().isRequired();
        EXPECT_TRUE(actual) << "Argument is mandatory";
    }

    TEST(COption, COption_isHasArgument_Test_without_argument) {
        COptionBuilder cOptionBuilder{};
        cOptionBuilder.addLongName("Test");

        bool actual = cOptionBuilder.build().isHasArgument();
        EXPECT_FALSE(actual) << "Argument wasn't entered and expected FALSE, but actual TRUE";
    }

    TEST(COption, COption_isHasArgument_Test_with_has_argument_true) {
        COptionBuilder cOptionBuilder;
        cOptionBuilder.addLongName("Test");
        cOptionBuilder.setValue(true);
        bool actual = cOptionBuilder.build().isHasArgument();
        EXPECT_TRUE(actual) << "Argument was entered and expected TRUE, but actual FALSE";
    }

    TEST(COption, COption_isHasArgument_Test_with_both_arguments_true) {
        COptionBuilder cOptionBuilder;
        cOptionBuilder.addLongName("Test");
        cOptionBuilder.setValue(true, true);
        bool actual = cOptionBuilder.build().isHasArgument();
        EXPECT_TRUE(actual) << "Arguments was entered and expected TRUE, but actual FALSE";
    }

    // Test: lack of options
    TEST(COptionBuilder, COptionBuilder_not_initialized_exception_Test) {
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
