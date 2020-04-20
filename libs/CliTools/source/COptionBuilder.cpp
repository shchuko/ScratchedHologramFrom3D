#include "COptionBuilder.hpp"

namespace CliTools{

    // Add short option name
    COptionBuilder& COptionBuilder::addShortName(char shortOption) noexcept {
        cOption.shortName = shortOption;
        return *this;
    }

    //Add long option name
    COptionBuilder& COptionBuilder::addLongName(const std::string& longOption) noexcept {
        cOption.longName = longOption;
        return *this;
    }

    // Set argument to option
    // argument - argument to option
    // option_required - Is the argument required
    COptionBuilder& COptionBuilder::setValue(bool has_argument, bool option_required) noexcept {
        cOption.option_required = option_required;
        cOption.has_argument = has_argument;
        return *this;
    }

    // Add description to option for information about it
    COptionBuilder& COptionBuilder::addDescription(const std::string& description) noexcept {
        cOption.description = description;
        return *this;
    }

    // Form and get a customized object
    COption COptionBuilder::build() {

        if (cOption.longName.empty() and cOption.shortName == '\0') {
            throw Exceptions::EOptionBuildError("Not enough arguments: full name option, short name option");
        }

        return COption(cOption);
    }

    // Clear builder data
    void COptionBuilder::reset() noexcept {
        cOption.shortName = '\0';
        cOption.longName = "";
        cOption.description = "";
        cOption.has_argument = false;
        cOption.option_required = false;
    }


}
