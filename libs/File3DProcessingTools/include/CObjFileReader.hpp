#pragma once

#include <iostream>
#include <fstream>
#include <sstream>

#include "EFile3DReadError.hpp"
#include "IFile3DReader.hpp"


namespace File3DProcessingTools {
    /**
     * @author Vladislav Yaroshchuk, github.com/shchuko
     */
    class CObjFileReader : public IFile3DReader {
    public:
        /**
         * Read file into CObject3DData
         * @param filepath Path to file
         * @param output_data CObject3DData object to read into
         * @throw File3DProcessingTools::EFile3DReadError if file can't be read
         */
        void readFile(const std::string &filepath, CObject3DData &output_data) override;

    private:
        std::ifstream fin;
        CObject3DData *p_data = nullptr;
        std::string next_line;

        bool parseNextLine() noexcept;

        void parseVertexData() noexcept;

        void parseNormalVectorData() noexcept;

        bool parsePolygonData() noexcept;
    };
}
