#include <string>
#include "COption.hpp"

std::string CliTools::COption::getShortName() {
    return shortName;
}

std::string CliTools::COption::getLongName() {
    return longName;
}

std::string CliTools::COption::getDescription() {
    return description;
}

bool CliTools::COption::isHasArgument() {
    return !argument.empty();
}

std::string CliTools::COption::getOptionData() {
    return argument;
}

bool CliTools::COption::isRequired() {
    return isRequiredArgument;
}
