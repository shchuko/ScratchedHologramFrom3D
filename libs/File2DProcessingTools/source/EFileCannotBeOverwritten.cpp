#include "EFileCannotBeOverwritten.hpp"


namespace File2DProcessingTools {
    namespace Exceptions {

        EFileCannotBeOverwritten::EFileCannotBeOverwritten() noexcept = default;

        EFileCannotBeOverwritten::EFileCannotBeOverwritten(std::string error) noexcept : m_error(std::move(error)) {}

        const char *EFileCannotBeOverwritten::what() const noexcept {
            return m_error.c_str();
        }
    }

}