
#include <EUnrecognizedOptionParsed.hpp>

namespace CliTools {
    namespace Exceptions {

        Exceptions::EUnrecognizedOptionParsed::EUnrecognizedOptionParsed() = default;

        EUnrecognizedOptionParsed::EUnrecognizedOptionParsed(std::string &error) : EOptionNotPresentInDictionary(
                error) {

        }

        const char *EUnrecognizedOptionParsed::what() const noexcept {
            return EOptionNotPresentInDictionary::what();
        }
    }
}