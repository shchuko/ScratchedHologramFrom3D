#include "COptionBuilder.hpp"

#include <utility>
#include <EOptionBuildError.hpp>

namespace CliTools{

    // Add short option name
    COptionBuilder& COptionBuilder::addShortName(char shortOption) {
        cOption.shortName = shortOption;
        return *this;
    }

    //Add long option name
    COptionBuilder& COptionBuilder::addLongName(const std::string &longOption) {
        cOption.longName = longOption;
        return *this;
    }

    // Set argument to option
    // argument - argument to option
    // option_required - Is the argument required
    COptionBuilder& COptionBuilder::setValue(bool has_argument, bool option_required) {
        cOption.option_required = option_required;
        cOption.has_argument = has_argument;
        return *this;
    }

    // Add description to option for information about it
    COptionBuilder& COptionBuilder::addDescription(const std::string &description) {
        cOption.description = description;
        return *this;
    }

    // Form and get a customized object
    COption COptionBuilder::build() {

        if (cOption.longName.empty() and cOption.shortName == '\0') {
            throw EOptionBuildError( "Not enough arguments: full name option, short name option");
        }

        if (!cOption.has_argument && cOption.option_required) {
            throw EOptionBuildError("No arguments, but it's required");
        }

        return cOption;
    }

    // Reset all object settings
    void COptionBuilder::reset() {
        cOption.shortName = '\0';
        cOption.longName = "";
        cOption.description = "";
        cOption.has_argument = false;
        cOption.option_required = false;
    }


}
