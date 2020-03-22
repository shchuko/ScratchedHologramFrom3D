#pragma once

#include <exception>
#include <string>

namespace CliTools {
    namespace Exceptions {

        class EOptionNotPresentInDictionary : public std::exception {

        private:
            std::string m_error;

        public:

            /**
             * default constructor, which do not accept error message
             */
            explicit EOptionNotPresentInDictionary();

            /**
             * the constructor serves to create an exception and get the cause of the error
             * @param error - message of error
             */
            explicit EOptionNotPresentInDictionary(std::string error);

            /**
            * Method for getting error description
            * @return text of error
            */
            const char *what() const noexcept override;

        };

    }
}