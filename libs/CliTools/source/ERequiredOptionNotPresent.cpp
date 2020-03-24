
#include <ERequiredOptionNotPresent.hpp>

namespace CliTools {
    namespace Exceptions {

        Exceptions::ERequiredOptionNotPresent::ERequiredOptionNotPresent() = default;

        ERequiredOptionNotPresent::ERequiredOptionNotPresent(std::string &error) : EParserError(error) {}

        const char *ERequiredOptionNotPresent::what() const noexcept {
            return EParserError::what();
        }
    }
}