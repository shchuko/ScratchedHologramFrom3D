#pragma once


#include "COption.hpp"
#include <vector>
#include <stack>
#include <unordered_map>

namespace CliTools {

    /**
     * Class for parsing and adding options
     * @author Nikita Novgorodtsev (github <https://github.com/paNoNi>)
     */
    class CArgsParser {

    private:

        // Storage : key - short name, value : index of option
        std::unordered_map<char, int> short_name_options;
        // Storage : key - long name, value : index of option
        std::unordered_map<std::string, int> long_name_options;
        // Storage : key - index of option in vector of options, value : value of option
        std::unordered_map<unsigned int, std::string> options_value;
        std::vector<COption> options;
        std::vector<bool> is_has_option;
        // Variables without '-'
        std::vector<std::string> independent_variable;

    public:

        /**
         * Parser of arguments and options
         * @param argv - The number of entered parameters
         * @param args - Parameter List
         */
        void parse(int argc, char **args);

        /**
         * Add options in dictionary
         * @param option - option data object
         */
        void addOption(COption option);

        /**
         * Checking for options in the dictionary
         * @param short_name_option - short name of option
         * @return TRUE if there is an option in the dictionary
         */
        bool isOptionPresent(char short_name_option);

        /**
         * Checking for options in the dictionary
         * @param long_name_option - long name of option
         * @return TRUE if there is an option in the dictionary
         */
        bool isOptionPresent(const std::string& long_name_option);

        /**
         * Getting option value
         * @param short_name_option - short name of option
         * @return option value
         */
        std::string getOptionValue(char short_name_option);


        /**
         * Getting option value
         * @param long_name_option - long name of option
         * @return option value
         */
        std::string getOptionValue(const std::string &long_name_option);

        /**
         * Getting count of arguments without options
         * @return count of arguments without options
         */
        unsigned int getPureArgsCount();

        /**
         * Getting argument without option by index
         * @param arg_index - index of argument without option
         * @return value of argument without option
         */
        std::string getPureArg(unsigned int arg_index);

    private:

        void parseShortOption(std::string short_option, std::stack<int> &sequence);

        void checkLongOption(const std::string& long_option, std::stack<int> &sequence);

        void parseOptionsOnValid();

    };
}
