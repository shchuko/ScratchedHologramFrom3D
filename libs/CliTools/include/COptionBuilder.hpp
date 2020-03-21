#pragma once

#include <string>
#include "COption.hpp"

namespace CliTools {

    /**
     * Builder for class COption
     * @author Nikita Novgorodtsev (github <https://github.com/paNoNi>)
     */
    class COptionBuilder {

    private:
        // The object to be built
        COption cOption;

    public:

        /**
        * Getting short option name
        * @param shortOption - short name for easy to use and combination options
        * @return instance of COptionBuilder for further construction
        */
        COptionBuilder& addShortName(char shortOption);

        /**
         * Getting long option name
         * @param longOption - full name of option
         * @return instance of COptionBuilder for further construction
         */
        COptionBuilder& addLongName(const std::string &longOption);

        /**
         * Set argument to option
         * @param has_argument - Is there an argument to the option
         * @param option_required - is the argument required
         * @return instance of COptionBuilder for further construction
         */
        COptionBuilder& setValue(bool has_argument, bool option_required = false);

        /**
         * Add description to option for information about it
         * @param description - description of option to get information about it
         * @return instance of COptionBuilder for further construction
         */
        COptionBuilder& addDescription(const std::string &description);

        /**
         * Form and get a customized object
         * @return finished instance of COption
         */
        COption build();

        /**
         * Reset all object settings
         */
        void reset();

    };

}