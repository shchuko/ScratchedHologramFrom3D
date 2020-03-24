#pragma once

#include "EOptionNotPresentInDictionary.hpp"

namespace CliTools {
    namespace Exceptions {
        class EUnrecognizedOptionParsed : public EOptionNotPresentInDictionary {
        public:

            /**
            * default constructor, which do not accept error message
            */
            explicit EUnrecognizedOptionParsed();

            /**
            * the constructor serves to create an exception and get the cause of the error
            * @param error - message of error
            */
            explicit EUnrecognizedOptionParsed(std::string &error);

            /**
            * Method for getting error description
            * @return text of error
            */
            const char *what() const noexcept override;

        };
    }
}