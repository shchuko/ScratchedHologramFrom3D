#pragma once


#include <string>
#include <stack>
#include <vector>
#include <unordered_map>


#include "EOptionNotPresentInDictionary.hpp"
#include "ERequiredOptionNotPresent.hpp"
#include "EUnrecognizedOptionParsed.hpp"
#include "EValuedOptionWithoutValue.hpp"
#include "COption.hpp"

namespace CliTools {

    /**
     * Class for parsing and adding options
     * @author Nikita Novgorodtsev (github <https://github.com/paNoNi>)
     */
    class CArgsParser {

    private:

        // Storage : key - short name, value : index of option
        std::unordered_map<char, unsigned long> options_short_names;
        // Storage : key - long name, value : index of option
        std::unordered_map<std::string, unsigned long> options_long_names;
        // Storage : key - index of option in vector of options, value : value of option
        std::unordered_map<unsigned long, std::string> options_values;

        std::vector<COption> options;
        std::vector<bool> option_parsed_flags;

        // Passed values without '-'
        std::vector<std::string> not_optioned_values;

    public:

        /**
         * Parser of arguments and options
         * @param argv - The number of entered parameters
         * @param args - Parameter List
         */
        void parse(int argc, const char *const *args);

        /**
         * Add options in dictionary
         * @param option - option data object
         */
        void addOption(const COption &option) noexcept;

        /**
         * Checking for options in the dictionary
         * @param short_name_option - short name of option
         * @return TRUE if there is an option in the dictionary
         */
        bool isOptionPresent(char short_name_option) const;

        /**
         * Checking for options in the dictionary
         * @param long_name_option - long name of option
         * @return TRUE if there is an option in the dictionary
         */
        bool isOptionPresent(const std::string &long_name_option) const;

        /**
         * Getting option value
         * @param short_name_option - short name of option
         * @return option value
         */
        std::string getOptionValue(char short_name_option) const;


        /**
         * Getting option value
         * @param long_name_option - long name of option
         * @return option value
         */
        std::string getOptionValue(const std::string &long_name_option) const;

        /**
         * Getting count of arguments without options
         * @return count of arguments without options
         */
        unsigned long getPureArgsCount() const noexcept;

        /**
         * Getting argument without option by index
         * @param arg_index - index of argument without option
         * @return value of argument without option
         */
        std::string getPureArg(unsigned long arg_index) const noexcept;

        void reset() noexcept;

        std::string getHelpMessage() const noexcept;

    private:

        void tryParseShortOption(const std::string &short_options, std::stack<unsigned long> &sequence);

        void tryParseLongOption(const std::string &long_name, std::stack<unsigned long> &sequence);

        void checkRequiredOptionsPresent();

        void checkOptionsWithArgHaveArg();

    };
}
