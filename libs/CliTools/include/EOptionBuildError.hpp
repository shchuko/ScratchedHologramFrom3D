#pragma once

#include <string>
#include <utility>
#include "exception"

/**
 * Exception for {@link COptionBuilder}
 * @author Nikita Novgorodtsev (github https://github.com/paNoNi)
 */
class EOptionBuildError : std::exception {

private:
    std::string m_error;

public:

    /**
     * the constructor serves to create an exception and get the cause of the error
     * @param error - message of error
     */
    explicit EOptionBuildError(std::string error)
        : m_error(std::move(error)){}

    /**
    * Method for getting error description
    * @return text of error
    */
    const char* what() const noexcept override;

};