
#include <ERequiredOptionNotPresent.hpp>
#include <utility>

namespace CliTools {
    namespace Exceptions {

        Exceptions::ERequiredOptionNotPresent::ERequiredOptionNotPresent() = default;

        ERequiredOptionNotPresent::ERequiredOptionNotPresent(std::string error) : EParserError(std::move(error)) {}

        const char *ERequiredOptionNotPresent::what() const noexcept {
            return EParserError::what();
        }
    }
}