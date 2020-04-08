#pragma once

#include <exception>
#include <string>

namespace ScratchProjectionMaths {
    namespace Exceptions {
        /**
         * @author Vladislav Yaroshchuk, github.com/shchuko
         */
        class EWrongObjectsPosition : public std::exception {
        public:
            EWrongObjectsPosition() = default;

            explicit EWrongObjectsPosition(std::string _cause) noexcept;

            const char *what() const noexcept override;

        private:
            std::string cause;
        };
    }
}

