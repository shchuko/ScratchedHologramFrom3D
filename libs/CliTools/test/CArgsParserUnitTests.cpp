#include <gtest/gtest.h>
#include <COptionBuilder.hpp>
#include <EOptionNotPresentInDictionary.hpp>
#include <EUnrecognizedOptionParsed.hpp>
#include <ERequiredOptionNotPresent.hpp>
#include <EValuedOptionWithoutValue.hpp>

#include "CArgsParser.hpp"

namespace CliTools {

    class CArgsParserFixture : public ::testing::Test {

    protected:

        void SetUp() override {

            //  test parse string
            char file_name[] = "test_file.txt";
            char shorts_name_first[] = "-tr";
            char value_first[] = "text_first";
            char long_name_first[] = "--test_long_name_t";
            char value_second[] = "text_second";
            char independent_variable[] = "independent_variable";
            test_args[0] = file_name;
            test_args[1] = shorts_name_first;
            test_args[2] = value_first;
            test_args[3] = long_name_first;
            test_args[4] = value_second;
            test_args[5] = independent_variable;
            // first option
            COptionBuilder cOptionBuilder;
            cOptionBuilder.addLongName("test_long_name_t");
            cOptionBuilder.addShortName('t');
            cOptionBuilder.setValue(true);
            cArgsParser.addOption(cOptionBuilder.build());
            cOptionBuilder.reset();
            // second option
            cOptionBuilder.addShortName('r');
            cOptionBuilder.setValue(true, true);
            cOptionBuilder.addLongName("test_long_name_r");
            cArgsParser.addOption(cOptionBuilder.build());
            cOptionBuilder.reset();
            // third option
            cOptionBuilder.addShortName('u');
            cOptionBuilder.addLongName("test_long_name_u");
            cArgsParser.addOption(cOptionBuilder.build());
            cOptionBuilder.reset();


            cArgsParser.parse(6, test_args);

        }

        void TearDown() override {
            delete[] test_args;
        }

        char **test_args = new char *[6];
        CArgsParser cArgsParser;

    };

    TEST(CArgsParser, CArgsParser_parse_Test_ERequiredOptionNotPresent_exception) {
        COptionBuilder cOptionBuilder;
        cOptionBuilder.addShortName('a');
        cOptionBuilder.setValue(false, true);
        CArgsParser cArgsParser;
        cArgsParser.addOption(cOptionBuilder.build());
        cOptionBuilder.reset();
        cOptionBuilder.addShortName('y');
        cArgsParser.addOption(cOptionBuilder.build());
        char name_option[] = "-y";
        char **test_parse = new char *[2];
        test_parse[1] = name_option;
        bool isExpected = false;
        try {
            cArgsParser.parse(2, test_parse);
        } catch (Exceptions::ERequiredOptionNotPresent &ex) {
            isExpected = true;
        } catch (...) {
            isExpected = false;
        }
        EXPECT_TRUE(isExpected);
    }

    TEST(CArgsParser, CArgsParser_parse_EValuedOptionWithoutValue_exception) {
        COptionBuilder cOptionBuilder;
        cOptionBuilder.addShortName('t');
        cOptionBuilder.setValue(true, false);
        CArgsParser cArgsParser;
        cArgsParser.addOption(cOptionBuilder.build());
        char name_option[] = "-t";
        char **test_parse = new char *[2];
        test_parse[1] = name_option;
        bool isExpected = false;
        try {
            cArgsParser.parse(2, test_parse);
        } catch (Exceptions::EValuedOptionWithoutValue &ex) {
            isExpected = true;
        } catch (...) {
            isExpected = false;
        }
        EXPECT_TRUE(isExpected);
    }

    TEST(CArgsParser, CArgsParser_parse_EOptionNotPresentInDictionary_exception) {
        COptionBuilder cOptionBuilder;
        cOptionBuilder.addShortName('t');
        cOptionBuilder.setValue(true, false);
        CArgsParser cArgsParser;
        cArgsParser.addOption(cOptionBuilder.build());
        char name_option[] = "-e";
        char **test_parse = new char *[2];
        test_parse[1] = name_option;
        bool isExpected = false;
        try {
            cArgsParser.parse(2, test_parse);
        } catch (Exceptions::EOptionNotPresentInDictionary &ex) {
            isExpected = true;
        } catch (...) {
            isExpected = false;
        }
        EXPECT_TRUE(isExpected);
    }

    TEST_F(CArgsParserFixture, CArgsParser_addOption_isOptionPresent_with_short_name_Test) {
        EXPECT_TRUE(cArgsParser.isOptionPresent('t'));
    }


    TEST_F(CArgsParserFixture, CArgsParser_addOption_isOptionPresent_with_long_name_Test) {
        EXPECT_TRUE(cArgsParser.isOptionPresent("test_long_name_t"));
    }

    TEST_F(CArgsParserFixture, CArgsParser_getOptionValue_with_short_name_Test) {
        const char *expected = "text_second";
        const char *actual = cArgsParser.getOptionValue('t').c_str();
        EXPECT_STREQ(expected, actual);
    }


    TEST_F(CArgsParserFixture, CArgsParser_getOptionValue_with_long_name_Test) {
        const char *expected = "";
        const char *actual = cArgsParser.getOptionValue("test_long_name_u").c_str();
        EXPECT_STREQ(expected, actual);
    }

    TEST_F(CArgsParserFixture, CArgsParser_getOptionValue_Test_with_long_name_Test_exception_checking) {
        bool isExpected = false;
        try {
            cArgsParser.getOptionValue("nonexistent_option");
        } catch (Exceptions::EOptionNotPresentInDictionary &ex) {
            isExpected = true;
        }

        EXPECT_TRUE(isExpected);

    }

    TEST_F(CArgsParserFixture, CArgsParser_getOptionValue_Test_with_short_name_Test_exception_checking) {
        bool isExpected = false;
        try {
            cArgsParser.getOptionValue('y');
        } catch (Exceptions::EOptionNotPresentInDictionary &ex) {
            isExpected = true;
        }

        EXPECT_TRUE(isExpected);

    }

    TEST_F(CArgsParserFixture, CArgsParser_isOptionPresent_with_short_name_Test) {
        bool actual = cArgsParser.isOptionPresent('r');
        EXPECT_TRUE(actual);
    }

    TEST_F(CArgsParserFixture, CArgsParser_isOptionPresent_with_long_name_Test) {
        bool actual = cArgsParser.isOptionPresent("test_long_name_r");
        EXPECT_TRUE(actual);
    }


    TEST_F(CArgsParserFixture, CArgsParser_isOptionPresent_with_short_name_Test_exception_checking) {
        bool isExpected = false;
        try {
            cArgsParser.isOptionPresent('y');
        } catch (Exceptions::EOptionNotPresentInDictionary &ex) {
            isExpected = true;
        }
        EXPECT_TRUE(isExpected);
    }

    TEST_F(CArgsParserFixture, CArgsParser_isOptionPresent_with_long_name_Test_exception_checking) {
        bool isExpected = false;
        try {
            cArgsParser.isOptionPresent("nonexistent_option");
        } catch (Exceptions::EOptionNotPresentInDictionary &ex) {
            isExpected = true;
        }
        EXPECT_TRUE(isExpected);
    }

    TEST_F(CArgsParserFixture, CArgsParser_getPureArgsCount_Test) {
        int expected = 1;
        EXPECT_EQ(expected, cArgsParser.getPureArgsCount());
    }

    TEST_F(CArgsParserFixture, CArgsParser_getPureArg_Test_with_existing_option) {
        const char *expected = "independent_variable";
        EXPECT_STREQ(expected, cArgsParser.getPureArg(0).c_str());
    }

    TEST_F(CArgsParserFixture, CArgsParser_getPureArg_Test_with_nonexisting_option) {
        const char *expected = "";
        EXPECT_STREQ(expected, cArgsParser.getPureArg(1).c_str());
    }

}
