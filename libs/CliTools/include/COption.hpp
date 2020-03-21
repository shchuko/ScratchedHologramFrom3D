#pragma once

namespace CliTools {

    // Forward declaring the builder
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
        std::string argument = "";
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
        char getShortName();
        /**
        * Getting long option name
        * @return long option
        */
        std::string getLongName();
        /**
        * Getting description to option for information about it
        * @return description option
        */
        std::string getDescription();
        /**
        * Is the argument required
        * @return true if argument is required and false if argument is not required
        */
        bool isRequired();

        /**
        * Does the option have arguments
        * @return true if option has an argument and false if option hasn't argument
        */
        bool isHasArgument();

    protected:

        // Protected constructor
        // Building in COptionBuilder
        COption()= default;


    };

}