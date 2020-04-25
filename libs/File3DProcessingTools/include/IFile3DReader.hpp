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
    public:
        /**
         * Read file into CObject3DData
         * @param filepath Path to file
         * @param output_data CObject3DData object to read into
         * @throw File3DProcessingTools::EFile3DReadError if file can't be read
         */
        virtual void readFile(const std::string &filepath, CObject3DData& output_data) = 0;

        virtual ~IFile3DReader() = 0;
    };

    inline IFile3DReader::~IFile3DReader() = default;
}
