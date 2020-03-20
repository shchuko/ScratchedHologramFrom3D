#pragma once

#include <string>
#include "COption.hpp"

namespace CliTools {

    //Builder for class COption
    class COptionBuilder {

    private:
        // The object to be built
        COption cOption;

    public:

        COptionBuilder()= default;

        // Getting short option name
        COptionBuilder& addShortName(char shortOption);

        //Getting long option name
        COptionBuilder& addLongName(const std::string &longOption);

        // Set argument to option
        // argument - argument to option
        // option_required - Is the argument required
        COptionBuilder& setValue(const std::string &argument, bool option_required = false);

        // Add description to option for information about it
        COptionBuilder& addDescription(const std::string &description);

        // Form and get a customized object
        COption build();

        // Reset all object settings
        void reset();

    };

}