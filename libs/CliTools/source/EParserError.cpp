
#include <EParserError.hpp>
#include <utility>

namespace CliTools {
    namespace Exceptions {

        EParserError::EParserError() = default;

        EParserError::EParserError(std::string error) : m_error(std::move(error)) {}

        const char *EParserError::what() const noexcept {
            return m_error.c_str();
        }
    }
}
