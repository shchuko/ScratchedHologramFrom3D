#include "EOptionBuildError.hpp"

CliTools::EOptionBuildError::EOptionBuildError(std::string &error) {
    m_error = error;
}

const char *CliTools::EOptionBuildError::what() const noexcept {
    return m_error.c_str();
}
