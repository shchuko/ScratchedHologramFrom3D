#include "COptionBuilder.hpp"

#include <utility>

namespace CliTools{

    COptionBuilder& COptionBuilder::addShortName(char shortOption) {
        cOption.shortName = shortOption;
        return *this;
    }

    COptionBuilder& COptionBuilder::addLongName(std::string longOption) {
        cOption.longName = std::move(longOption);
        return *this;
    }

    COptionBuilder& COptionBuilder::setValue(std::string argument, bool option_required) {
        cOption.option_required = option_required;
        cOption.argument = std::move(argument);
        return *this;
    }

    COptionBuilder& COptionBuilder::addDescription(std::string description) {
        cOption.description = std::move(description);
        return *this;
    }


    COption COptionBuilder::build() {
        return cOption;
    }

    void COptionBuilder::reset() {
        cOption.shortName = '\0';
        cOption.longName = "";
        cOption.argument = "";
    }


}
