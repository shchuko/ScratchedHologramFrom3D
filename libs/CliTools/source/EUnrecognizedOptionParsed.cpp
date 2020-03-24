
#include <EUnrecognizedOptionParsed.hpp>
#include <utility>

namespace CliTools {
    namespace Exceptions {

        Exceptions::EUnrecognizedOptionParsed::EUnrecognizedOptionParsed() = default;

        EUnrecognizedOptionParsed::EUnrecognizedOptionParsed(std::string error) : EOptionNotPresentInDictionary(
                std::move(error)) {

        }

        const char *EUnrecognizedOptionParsed::what() const noexcept {
            return EOptionNotPresentInDictionary::what();
        }
    }
}