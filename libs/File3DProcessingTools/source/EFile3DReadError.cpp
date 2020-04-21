/**
 * @author Vladislav Yaroshchuk, github.com/shchuko
 */

#include "EFile3DReadError.hpp"
namespace File3DProcessingTools {
    namespace Exceptions {
        EFile3DReadError::EFile3DReadError(std::string _cause) : cause{std::move(_cause)} {}

        const char *EFile3DReadError::what() const noexcept {
            return cause.c_str();
        }
    }
}
