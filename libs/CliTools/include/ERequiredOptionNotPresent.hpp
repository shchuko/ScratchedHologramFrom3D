#pragma once

#include "EParserError.hpp"

namespace CliTools {
    namespace Exceptions {

        /**
         * No required option
         * @author Nikita Novgorodtsev (github https://github.com/paNoNi)
         */
        class ERequiredOptionNotPresent : public EParserError {

        public:

            /**
            * default constructor, which do not accept error message
            */
            explicit ERequiredOptionNotPresent();

            /**
            * the constructor serves to create an exception and get the cause of the error
            * @param error - message of error
            */
            explicit ERequiredOptionNotPresent(std::string &error);

            /**
            * Method for getting error description
            * @return text of error
            */
            const char *what() const noexcept override;

        };

    }
}