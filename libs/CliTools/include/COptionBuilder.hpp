#pragma once

#include <string>
#include "COption.hpp"

namespace CliTools {

    class COptionBuilder {

    private:
        COption cOption;

    public:

        COptionBuilder()= default;

        COptionBuilder& addShortName(char shortOption);
        COptionBuilder& addLongName(std::string longOption);
        COptionBuilder& setValue(std::string argument, bool option_required = false);
        COptionBuilder& addDescription(std::string description);
        COption build();
        void reset();

    };

}