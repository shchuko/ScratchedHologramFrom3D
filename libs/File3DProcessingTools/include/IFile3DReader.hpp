/**
 * @author Vladislav Yaroshchuk, github.com/shchuko
 */
#pragma once


#include "CObject3DData.hpp"


namespace File3DProcessingTools {
    /**
     * @author Vladislav Yaroshchuk, github.com/shchuko
     */
    class IFile3DReader {
        /**
         * Read file into CObject3DData
         * @param filepath Path to file
         * @return CObject3DData object
         * @throw File3DProcessingTools::EFile3DReadError if file can't be read
         */
        virtual CObject3DData readFile(std::string filepath) = 0;
    };
}
