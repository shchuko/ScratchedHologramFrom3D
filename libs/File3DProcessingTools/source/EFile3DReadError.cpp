/**
 * @author Vladislav Yaroshchuk, github.com/shchuko
 */

#include "EFile3DReadError.hpp"

File3DProcessingTools::EFile3DReadError::EFile3DReadError(std::string _cause) : cause{std::move(_cause)}{}

const char *File3DProcessingTools::EFile3DReadError::what() const noexcept {
    return cause.c_str();
}
