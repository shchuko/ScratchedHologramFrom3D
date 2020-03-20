#pragma once

namespace CliTools {

    // Forward declaring the builder
    class COptionBuilder;

    //Helper class for ease of use and storage of options
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

        // Builder to access the fields
        friend COptionBuilder;

        // Getting short option name
        char getShortName();
        // Getting long option name
        std::string getLongName();
        // Getting description to option for information about it
        std::string getDescription();

        // Is the argument required
        bool isRequired();

        // Does the option have arguments
        bool isHasArgument();

    protected:

        // Protected constructor
        // Building in COptionBuilder
        COption()= default;


    };

}