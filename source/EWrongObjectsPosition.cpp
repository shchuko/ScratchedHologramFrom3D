/**
 * @author Vladislav Yaroshchuk, github.com/shchuko
 */

#include "EWrongObjectsPosition.hpp"

ScratchProjectionMaths::Exceptions::EWrongObjectsPosition::EWrongObjectsPosition(std::string _cause) noexcept
        : cause{std::move(_cause)} {}

const char *ScratchProjectionMaths::Exceptions::EWrongObjectsPosition::what() const noexcept {
    return cause.c_str();
}
