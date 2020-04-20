#include "COption.hpp"

namespace CliTools{

    // Get
    char COption::getShortName() const noexcept {
        return shortName;
    }

    std::string COption::getLongName() const noexcept {
        return longName;
    }

    std::string COption::getDescription() const noexcept {
        return description;
    }

    // Does the option have arguments
    bool COption::isHasArgument() const noexcept {
        return has_argument;
    }

    // Is there an argument in the option
    bool COption::isRequired() const noexcept {
        return option_required;
    }
}

