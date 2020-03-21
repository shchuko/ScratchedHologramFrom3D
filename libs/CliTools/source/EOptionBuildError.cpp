#include <EOptionBuildError.hpp>

const char *EOptionBuildError::what() const noexcept {
    return m_error.c_str();
}
