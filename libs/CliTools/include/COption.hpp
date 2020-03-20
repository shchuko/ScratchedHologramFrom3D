#pragma once

namespace CliTools {

    class COption {

        // Fields
    private:

        std::string shortName;
        std::string longName;
        std::string description;
        std::string argument;
        bool isRequiredArgument = false;

        // Methods
    public:

        std::string getShortName();
        std::string getLongName();
        std::string getDescription();
        std::string getOptionData();

        bool isRequired();
        bool isHasArgument();

    private:

        // Private constructor
        // Building in COptionBuilder
        COption()= default;


    };

}