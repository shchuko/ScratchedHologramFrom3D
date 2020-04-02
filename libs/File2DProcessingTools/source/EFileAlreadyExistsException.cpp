#include "EFileAlreadyExistsException.hpp"


namespace File2DProcessingTools {
    namespace Exceptions {

        EFileAlreadyExistsException::EFileAlreadyExistsException() = default;

        EFileAlreadyExistsException::EFileAlreadyExistsException(std::string error) noexcept : m_error(std::move(error)) {}

        const char *EFileAlreadyExistsException::what() const noexcept {
            return m_error.c_str();
        }
    }

}