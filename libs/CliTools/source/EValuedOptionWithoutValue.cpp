#include <EValuedOptionWithoutValue.hpp>

namespace CliTools {
    namespace Exceptions {

        Exceptions::EValuedOptionWithoutValue::EValuedOptionWithoutValue() = default;

        EValuedOptionWithoutValue::EValuedOptionWithoutValue(std::string error) : EParserError(error) {}

        const char *EValuedOptionWithoutValue::what() const noexcept {
            return EParserError::what();
        }
    }
}