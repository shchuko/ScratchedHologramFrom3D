#include <string>
#include "COption.hpp"

namespace CliTools{

    char COption::getShortName() {
        return shortName;
    }

    std::string COption::getLongName() {
        return longName;
    }

    std::string COption::getDescription() {
        return description;
    }

    bool COption::isHasArgument() {
        return !argument.empty();
    }

    bool COption::isRequired() {
        return option_required;
    }
}

