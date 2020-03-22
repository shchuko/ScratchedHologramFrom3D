#include <EOptionBuildError.hpp>
#include <COptionBuilder.hpp>
#include "gtest/gtest.h"

namespace CliTools {

    TEST(EOptionBuildError, what) {
        COptionBuilder cOptionBuilder;

        // Test: lack of parameters, but the required input - true
        cOptionBuilder.addLongName("test");
        cOptionBuilder.setValue(false, true);
        const char* expectedTest1 = "Could not build instance of COption class : \nNo arguments, but it's required\n";
        try {
            cOptionBuilder.build();
        } catch (EOptionBuildError& error) {
            ASSERT_STREQ(expectedTest1, error.what());
        }

        cOptionBuilder.reset();
        // Test: lack of options
        const char* expectedTest2 = "Could not build instance of COption class : \nNot enough arguments: full name option, short name option\n";
        try {
            cOptionBuilder.build();
        } catch (EOptionBuildError& error) {
            ASSERT_STREQ(expectedTest2, error.what());
        }

        cOptionBuilder.reset();
        // Test: lack of parameters, but the required input - true and Test: lack of options
        cOptionBuilder.setValue(false, true);
        const char* expectedTest3 = "Could not build instance of COption class : \nNot enough arguments: full name option, short name option\nNo arguments, but it's required\n";
        try {
            cOptionBuilder.build();
        } catch (EOptionBuildError& error) {
            ASSERT_STREQ(expectedTest3, error.what());
        }


    }
}
