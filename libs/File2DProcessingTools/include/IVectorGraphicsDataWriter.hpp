#pragma once

#include <string>
#include "CVectorGraphicsData.hpp"

namespace File2DProcessingTools {

    class IVectorGraphicsDataWriter {
    public:
        // [param] write_force
        // -  if true && file already exists, overwrite file
        // -  if false && file already exists, throw EFileAlreadyExistsException
        // If file can't be overwritten force, throw EFileCannotBeOverwritten
        virtual void write(std::string filepath, const CVectorGraphicsData &data, bool write_force) = 0;
    };
}