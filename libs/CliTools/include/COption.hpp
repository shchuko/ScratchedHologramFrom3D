#pragma once

#include <string>
#include "EOptionBuildError.hpp"

namespace CliTools {
    /**
    * Prototype of builder to access the fields
    */
    class COptionBuilder;

    /**
    * Helper class for ease of use and storage of options
    * @author Nikita Novgorodtsev (github <https://github.com/paNoNi>)
    */
    class COption {
    private:
        // Short name of option
        char shortName = '\0';
        // Long name of option
        std::string longName = "";
        // Description of option
        std::string description = "";
        // Argument for option (if needed)
        bool has_argument = false;
        // Is the argument required
        bool option_required = false;

    public:

        /**
        * Prototype of builder to access the fields
        */
        friend COptionBuilder;

        /**
        * Getting short option name
        * @return short option
        */
        char getShortName() const noexcept;

        /**
        * Getting long option name
        * @return long option
        */
        std::string getLongName() const noexcept;

        /**
        * Getting description to option for information about it
        * @return description option
        */
        std::string getDescription() const noexcept;

        /**
        * Is the argument required
        * @return true if argument is required and false if argument is not required
        */
        bool isRequired() const noexcept;

        /**
        * Is there an argument in the option
        * @return true if option has an argument and false if option hasn't argument
        */
        bool isHasArgument() const noexcept;

        COption(const COption &option) = default;

        COption(COption &&) = default;

        COption &operator=(const COption &option) = default;

        COption &operator=(COption &&option) = default;

    protected:

        // Protected constructor
        // Building in COptionBuilder
        COption() = default;
    };

}