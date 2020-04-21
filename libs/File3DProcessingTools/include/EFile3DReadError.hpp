/**
 * @author Vladislav Yaroshchuk, github.com/shchuko
 */

#pragma once


#include <exception>
#include <string>


namespace File3DProcessingTools {
    namespace Exceptions {
        /**
         * 3D-File reading exception
         */
        class EFile3DReadError : public std::exception {
        private:
            std::string cause;

        public:
            /**
             * Default constructor
             */
            EFile3DReadError() = default;

            /**
             * Parametrized constructor with cause message
             * @param _cause Exception throw reason description
             */
            explicit EFile3DReadError(std::string _cause);

            /**
             * Get exception throw reason
             * @return Exception throw reason description
             */
            const char *what() const noexcept override;
        };

    }
}