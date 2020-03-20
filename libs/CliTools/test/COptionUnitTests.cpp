#include <gtest/gtest.h>

#include "COptionBuilder.hpp"

namespace CliTools{


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
        cOptionBuilder.addDescription( "Some description");
        std::string expected = "Some description";
        std::string actual = cOptionBuilder.build().getDescription();
        ASSERT_STREQ(expected.c_str(), actual.c_str()) << "Description received incorrectly";
    }

    TEST(COption, isRequired) {
        COptionBuilder cOptionBuilder{};

        // Option entered
        cOptionBuilder.setValue( "value");
        bool actual = cOptionBuilder.build().isRequired();
        ASSERT_FALSE(actual) << "Argument isn't mandatory";

        // Option entered
        cOptionBuilder.setValue("value", true);
        actual = cOptionBuilder.build().isRequired();
        ASSERT_TRUE(actual) << "Argument is mandatory";
    }

    TEST(COption, isHasArgument){
        COptionBuilder cOptionBuilder{};

        bool actual = cOptionBuilder.build().isHasArgument();
        ASSERT_FALSE(actual) << "Argument wasn't entered and expected FALSE, but actual TRUE";

        cOptionBuilder.setValue("value");
        actual = cOptionBuilder.build().isHasArgument();
        ASSERT_TRUE(actual) << "Argument was entered and expected TRUE, but actual FALSE";
    }

}
