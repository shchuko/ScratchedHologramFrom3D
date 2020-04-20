#include "CArgsParser.hpp"


namespace CliTools {

    void CArgsParser::addOption(const COption &option) noexcept {
        char short_name = option.getShortName();
        std::string long_name = option.getLongName();

        if (short_name != '\0') {
            options_short_names.insert(std::make_pair(short_name, options.size()));
        }

        if (!long_name.empty()) {
            options_long_names.insert(std::make_pair(long_name, options.size()));
        }

        option_parsed_flags.push_back(false);
        options.emplace_back(option);
    }

    bool CArgsParser::isOptionPresent(char short_name_option) const {
        auto it_short_name = options_short_names.find(short_name_option);

        if (it_short_name == options_short_names.end()) {
            std::string error = std::string("Option name not found: ") + short_name_option;
            throw Exceptions::EOptionNotPresentInDictionary(error);
        }
        return option_parsed_flags[it_short_name->second];
    }


    bool CArgsParser::isOptionPresent(const std::string &long_name_option) const {
        auto it_long_name = options_long_names.find(long_name_option);
        if (it_long_name == options_long_names.end()) {
            std::string error = std::string("Option name not found: ") + long_name_option;
            throw Exceptions::EOptionNotPresentInDictionary(error);
        }
        return option_parsed_flags[it_long_name->second];
    }

    std::string CArgsParser::getOptionValue(const char short_name_option) const {
        auto it_short_name = options_short_names.find(short_name_option);
        if (it_short_name == options_short_names.end()) {
            std::string error = std::string("Option name not found: ") + short_name_option;
            throw Exceptions::EOptionNotPresentInDictionary(error);
        }

        if (!options[it_short_name->second].isHasArgument()) {
            return "";
        }

        return options_values.find(it_short_name->second)->second;
    }

    std::string CArgsParser::getOptionValue(const std::string &long_name_option) const {
        auto it_long_name = options_long_names.find(long_name_option);
        if (it_long_name == options_long_names.end()) {
            std::string error = "Option name not found: " + long_name_option;
            throw Exceptions::EOptionNotPresentInDictionary(error);
        }

        if (!options[it_long_name->second].isHasArgument()) {
            return "";
        }

        return options_values.find(it_long_name->second)->second;
    }

    unsigned long CArgsParser::getPureArgsCount() const noexcept {
        return not_optioned_values.size();
    }

    std::string CArgsParser::getPureArg(unsigned long arg_index) const noexcept {
        if (not_optioned_values.size() <= arg_index) {
            return "";
        }
        return not_optioned_values[arg_index];
    }

    void CArgsParser::parse(int argc, const char *const *args) {
        std::stack<unsigned long> sequence;
        for (int i = 1; i < argc; ++i) {
            if (args[i][0] == '-' && args[i][1] != '-') {
                std::string short_option = std::string(args[i]);
                tryParseShortOption(short_option, sequence);
            }

            if (args[i][0] == '-' && args[i][1] == '-') {
                std::string long_name = std::string(args[i]).substr(2);
                tryParseLongOption(long_name, sequence);
            }

            if (args[i][0] != '-') {
                if (sequence.empty()) {
                    not_optioned_values.emplace_back(args[i]);
                } else {
                    while (!sequence.empty()) {
                        unsigned int option_index = sequence.top();
                        if (options[option_index].isHasArgument()) {
                            std::string value = args[i];
                            options_values[option_index] = value;
                            sequence.pop();
                        }
                    }
                }
            }

        }

        checkRequiredOptionsPresent();
        checkOptionsWithArgHaveArg();
    }

    void CArgsParser::checkRequiredOptionsPresent() {
        for (unsigned long i = 0; i < options.size(); ++i) {
            if (options[i].isRequired() && !option_parsed_flags[i]) {
                if (!options[i].getLongName().empty()) {
                    std::string error = std::string("Required option not entered: --") + options[i].getLongName();
                    throw Exceptions::ERequiredOptionNotPresent(error);
                } else if (options[i].getShortName() != '\0') {
                    std::string error = std::string("Required option not entered: -") + options[i].getShortName();
                    throw Exceptions::ERequiredOptionNotPresent(error);
                }
            }
        }
    }

    void CArgsParser::checkOptionsWithArgHaveArg() {
        for (unsigned long i = 0; i < options.size(); ++i) {
            auto it_option_value = options_values.find(i);
            if (options[i].isHasArgument() && it_option_value == options_values.end()) {
                if (!options[i].getLongName().empty()) {
                    std::string error = "Option without value: --" + options[i].getLongName();
                    throw Exceptions::EValuedOptionWithoutValue(error);
                } else if (options[i].getShortName() != '\0') {
                    std::string error = std::string("Option without value: -") + options[i].getShortName();
                    throw Exceptions::EValuedOptionWithoutValue(error);
                }
            }
        }
    }


    void CArgsParser::tryParseShortOption(const std::string &short_options, std::stack<unsigned long> &sequence) {
        for (unsigned long j = 1; j < short_options.size(); ++j) {
            auto it_short_name = options_short_names.find(short_options[j]);
            if (it_short_name != options_short_names.end()) {
                option_parsed_flags[it_short_name->second] = true;
                sequence.push(it_short_name->second);
            } else {
                std::string error = std::string("No options in the dictionary: -") + short_options[j];
                throw Exceptions::EUnrecognizedOptionParsed(error);
            }
        }
    }

    void CArgsParser::tryParseLongOption(const std::string &long_name, std::stack<unsigned long> &sequence) {
        auto it_long_name = options_long_names.find(long_name);
        if (it_long_name != options_long_names.end()) {
            option_parsed_flags[it_long_name->second] = true;
            sequence.push(it_long_name->second);
        } else {
            std::string error = std::string("No options in the dictionary: --") + long_name;
            throw Exceptions::EUnrecognizedOptionParsed(error);
        }
    }


}
