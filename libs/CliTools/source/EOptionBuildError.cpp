#include "EOptionBuildError.hpp"

EOptionBuildError::EOptionBuildError(std::string &error) {
    m_error = error;
}

const char *EOptionBuildError::what() const noexcept {
    return m_error.c_str();
}
