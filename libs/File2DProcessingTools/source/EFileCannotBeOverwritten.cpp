#include "EFileCannotBeOverwritten.hpp"


namespace File2DProcessingTools {
    namespace Exceptions {

        EFileCannotBeOverwritten::EFileCannotBeOverwritten() = default;

        EFileCannotBeOverwritten::EFileCannotBeOverwritten(std::string error) : m_error(std::move(error)) {}

        const char *EFileCannotBeOverwritten::what() const noexcept {
            return m_error.c_str();
        }
    }

}