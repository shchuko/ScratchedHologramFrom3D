#include <string>
#include "COption.hpp"

char CliTools::COption::getShortName() {
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

bool CliTools::COption::isRequired() {
    return isRequiredArgument;
}
