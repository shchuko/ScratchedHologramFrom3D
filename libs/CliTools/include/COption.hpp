#pragma once

namespace CliTools {

    // Forward declaring the builder
    class COptionBuilder;

    class COption {

    // Fields
    private:

        char shortName = '\0';
        std::string longName = "";
        std::string description = "";
        std::string argument = "";
        bool option_required = false;

    // Methods
    public:

        friend COptionBuilder;

        char getShortName();
        std::string getLongName();
        std::string getDescription();
        bool isRequired();
        bool isHasArgument();

    protected:

        // Protected constructor
        // Building in COptionBuilder
        COption()= default;


    };

}