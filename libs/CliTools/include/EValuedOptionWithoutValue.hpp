#pragma once

#include "EParserError.hpp"

namespace CliTools {
    namespace Exceptions {

        /**
         * There is no value for the option, which must have a value
         * @author Nikita Novgorodtsev (github https://github.com/paNoNi)
         */
        class EValuedOptionWithoutValue : public EParserError {

        public:


            /**
            * default constructor, which do not accept error message
            */
            explicit EValuedOptionWithoutValue();

            /**
           * the constructor serves to create an exception and get the cause of the error
           * @param error - message of error
           */
            explicit EValuedOptionWithoutValue(std::string error);


            /**
            * Method for getting error description
            * @return text of error
            */
            const char *what() const noexcept override;

        };

    }
}