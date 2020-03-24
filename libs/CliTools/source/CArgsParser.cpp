#include <string>
#include <EOptionNotPresentInDictionary.hpp>
#include <iostream>
#include <ERequiredOptionNotPresent.hpp>
#include <EUnrecognizedOptionParsed.hpp>
#include <stack>
#include <EValuedOptionWithoutValue.hpp>
#include "CArgsParser.hpp"

class iterator;
namespace CliTools {

    void CArgsParser::addOption(COption option) {

        char short_name = option.getShortName();
        std::string long_name = option.getLongName();

        if (short_name != '\0') {
            short_name_options.insert(std::pair<char, int>(short_name, options.size()));
        }

        if (!long_name.empty()) {
            long_name_options.insert(std::pair<std::string, int>(long_name, options.size()));
        }

        is_has_option.push_back(false);
        options.push_back(option);

    }

    bool CArgsParser::isOptionPresent(char short_name_option) {
        auto it_short_name = short_name_options.find(short_name_option);

        if (it_short_name == short_name_options.end()) {
            std::string error = std::string("Option name not found: ") + short_name_option;
            throw Exceptions::EOptionNotPresentInDictionary(error);
        }
        return short_name_options.find(short_name_option) != short_name_options.end();
    }


    bool CArgsParser::isOptionPresent(const std::string &long_name_option) {
        auto it_long_name = long_name_options.find(long_name_option);
        if (it_long_name == long_name_options.end()) {
            std::string error = std::string("Option name not found: ") + long_name_option;
            throw Exceptions::EOptionNotPresentInDictionary(error);
        }
        return long_name_options.find(long_name_option) != long_name_options.end();
    }

    std::string CArgsParser::getOptionValue(const char short_name_option) {
        auto it_short_name = short_name_options.find(short_name_option);
        if (it_short_name == short_name_options.end()) {
            std::string error = std::string("Option name not found: ") + short_name_option;
            throw Exceptions::EOptionNotPresentInDictionary(error);
        }

        if (!options[it_short_name->second].isHasArgument()) {
            return "";
        }

        return options_value[short_name_options[short_name_option]];
    }

    std::string CArgsParser::getOptionValue(const std::string &long_name_option) {
        auto it_long_name = long_name_options.find(long_name_option);
        if (it_long_name == long_name_options.end()) {
            std::string error = "Option name not found: " + long_name_option;
            throw Exceptions::EOptionNotPresentInDictionary(error);
        }

        if (!options[it_long_name->second].isHasArgument()) {
            return "";
        }

        return options_value[long_name_options[long_name_option]];
    }

    unsigned int CArgsParser::getPureArgsCount() {
        return independent_variable.size();
    }

    std::string CArgsParser::getPureArg(unsigned int arg_index) {
        if (independent_variable.size() <= arg_index) {
            return "";
        }
        return independent_variable[arg_index];
    }

    void CArgsParser::parse(int argv, char **args) {
        std::stack<int> sequence;
        for (int i = 1; i < argv; ++i) {

            if (args[i][0] == '-' && args[i][1] != '-') {
                std::string short_option = std::string(args[i]);
                parseShortOption(short_option, sequence);
            }

            if (args[i][0] == '-' && args[i][1] == '-') {
                std::string long_name = std::string(args[i]).substr(2);
                checkLongOption(long_name, sequence);
            }

            if (args[i][0] != '-') {
                if (sequence.empty()) {
                    independent_variable.emplace_back(args[i]);
                } else {
                    while (!sequence.empty()) {
                        if (options[sequence.top()].isHasArgument()) {
                            std::string value = args[i];
                            options_value[sequence.top()] = value;
                            sequence.pop();
                        }
                    }
                }
            }

        }

        parseOptionsOnValid();


    }

    void CArgsParser::parseOptionsOnValid() {
        for (int i = 0; i < int(options.size()); ++i) {
            if (options[i].isRequired() && !is_has_option[i]) {
                if (!options[i].getLongName().empty()) {
                    std::string error = std::string("Required option not entered: --") + options[i].getLongName();
                    throw Exceptions::ERequiredOptionNotPresent(error);
                } else if (options[i].getShortName() != '\0') {
                    std::string error = std::string("Required option not entered: -") + options[i].getShortName();
                    throw Exceptions::ERequiredOptionNotPresent(error);
                }

            }
            auto it_option_value = options_value.find(i);
            if (options[i].isHasArgument() && it_option_value == options_value.end()) {
                if (!options[i].getLongName().empty()) {
                    std::string error =
                            "after option --" + options[i].getLongName() + ", which takes a value, there is no value";
                    throw Exceptions::EValuedOptionWithoutValue(error);
                } else if (options[i].getShortName() != '\0') {
                    std::string error = std::string("after option -") + options[i].getShortName() +
                                        std::string(", which takes a value, there is no value");
                    throw Exceptions::EValuedOptionWithoutValue(error);
                }
            }

        }


    }

    void CArgsParser::parseShortOption(std::string short_options, std::stack<int> &sequence) {
        for (int j = 1; j < int(short_options.size()); ++j) {
            auto it_short_name = short_name_options.find(short_options[j]);
            if (it_short_name != short_name_options.end()) {
                is_has_option[it_short_name->second] = true;
                sequence.push(it_short_name->second);
            } else {
                std::string error = std::string("No options in the dictionary: -") + short_options[j];
                throw Exceptions::EUnrecognizedOptionParsed(error);
            }
        }
    }

    void CArgsParser::checkLongOption(const std::string& long_name, std::stack<int> &sequence) {
        auto it_long_name = long_name_options.find(long_name);
        if (it_long_name != long_name_options.end()) {
            is_has_option[it_long_name->second] = true;
            sequence.push(it_long_name->second);
        } else {
            std::string error = std::string("No options in the dictionary: --") + long_name;
            throw Exceptions::EUnrecognizedOptionParsed(error);
        }
    }


}
