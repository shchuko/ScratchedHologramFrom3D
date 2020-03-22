#include "EOptionBuildError.hpp"

CliTools::Exceptions::EOptionBuildError::EOptionBuildError(std::string error):m_error(std::move(error)){};

const char *CliTools::Exceptions::EOptionBuildError::what() const noexcept {
    return m_error.c_str();
}

CliTools::Exceptions::EOptionBuildError::EOptionBuildError() = default;
