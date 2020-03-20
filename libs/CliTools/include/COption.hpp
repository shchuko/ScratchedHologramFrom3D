#pragma once

namespace CliTools {

    class COption {

        // Fields
    private:

        char shortName;
        std::string longName;
        std::string description;
        std::string argument;
        bool isRequiredArgument = false;

        // Methods
    public:

        char getShortName();
        std::string getLongName();
        std::string getDescription();

        bool isRequired();
        bool isHasArgument();

    private:

        // Private constructor
        // Building in COptionBuilder
        COption()= default;


    };

}