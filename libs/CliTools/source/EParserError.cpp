
#include <EParserError.hpp>

namespace CliTools {
    namespace Exceptions {

        EParserError::EParserError() = default;

        EParserError::EParserError(std::string &error) : m_error(error) {}

        const char *EParserError::what() const noexcept {
            return m_error.c_str();
        }
    }
}
