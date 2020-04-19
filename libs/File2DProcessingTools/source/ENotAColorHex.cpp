#include <ENotAColorHex.hpp>


namespace File2DProcessingTools {
    namespace Exceptions {

        ENotAColorHex::ENotAColorHex() noexcept = default;

        ENotAColorHex::ENotAColorHex(std::string error) noexcept : m_error(std::move(error)) {}

        const char *ENotAColorHex::what() const noexcept {
            return m_error.c_str();
        }
    }

}