#pragma once

#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <array>

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
        std::string next_line;

        bool parseNextLine(CObject3DData &output_data) noexcept;

        void parseVertexData(CObject3DData &output_data) noexcept;

        void parseNormalVectorData(CObject3DData &output_data) noexcept;

        bool parsePolygonData(CObject3DData &output_data) noexcept;
    };
}
