
#include <EOptionNotPresentInDictionary.hpp>
#include <utility>

namespace CliTools {
    namespace Exceptions {

        Exceptions::EOptionNotPresentInDictionary::EOptionNotPresentInDictionary() = default;

        EOptionNotPresentInDictionary::EOptionNotPresentInDictionary(std::string error) : m_error(std::move(error)) {}

        const char *EOptionNotPresentInDictionary::what() const noexcept {
            return m_error  .c_str();
        }
    }
}