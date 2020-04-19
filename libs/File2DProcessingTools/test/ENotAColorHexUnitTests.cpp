#include <ENotAColorHex.hpp>
#include <gtest/gtest.h>
#include <CVectorGraphicsData.hpp>

namespace File2DProcessingTools {
    namespace Exceptions {

        TEST(ENotAColorHex, EFileCannotBeOverwritten_incorect_hex_format_Test) {
            CVectorGraphicsData::CColor_T color;
            std::vector<std::string> incorrect_colors;
            incorrect_colors.push_back("#A");
            incorrect_colors.push_back("#22");
            incorrect_colors.push_back("#FFFF");
            incorrect_colors.push_back("#1RF");
            incorrect_colors.push_back("#GGG");
            incorrect_colors.push_back("#0E0");
            incorrect_colors.push_back("#AAAFFFF");

            bool isThrown = true;
            try {
                for (long long unsigned int i = 0; i < incorrect_colors.size(); ++i) {
                    color.setColor(incorrect_colors[i]);
                    isThrown = false;
                    break;
                }
            } catch (ENotAColorHex &ex) {}
            EXPECT_TRUE(isThrown);
        }

        TEST(ENotAColorHex, ENotAColorHex_std_exception_inheritance_Test) {
            bool thrown;
            try {
                throw ENotAColorHex();
            } catch (std::exception &e) {
                thrown = true;
            } catch (...) {
                thrown = false;
            }

            EXPECT_TRUE(
                    thrown) << "File2DProcessingTools::Exceptions::ENotAColorHex does not inherit std::exception"
                            << std::endl;
        }

    }
}