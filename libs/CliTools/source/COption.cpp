#include <string>
#include "COption.hpp"

namespace CliTools{

    // Get
    char COption::getShortName() {
        return shortName;
    }

    std::string COption::getLongName() {
        return longName;
    }

    std::string COption::getDescription() {
        return description;
    }

    // Does the option have arguments
    bool COption::isHasArgument() {
        return !argument.empty();
    }

    // Is the argument required
    bool COption::isRequired() {
        return option_required;
    }
}

