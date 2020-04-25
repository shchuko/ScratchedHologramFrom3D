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

        virtual void writeMul(std::string filepath, const std::vector<CVectorGraphicsData> &data, bool write_force) = 0;

        // Input data should be scaled to height
        // Width should be recalculated by input data aspect ratio
        virtual void setCanvasHeight(double height_px) = 0;

        // Input data should be scaled to width
        // Height should be recalculated by input data aspect ratio
        virtual void setCanvasWidth(double width_px)  = 0;

        // Input data should be scaled to fit height and width
        virtual void setCanvasSize(double height_px, double width_px)  = 0;

        // Padding.first = vertical  (up-side, down-side) padding width in pixels
        // Padding.second = horizontal (left-side, right-side) padding width in pixels
        // Rescale input data to fit if needed
        virtual bool setAlignmentCenter(std::pair<double, double> padding_px)  = 0;

        virtual ~IVectorGraphicsDataWriter() = 0;
    };

    inline IVectorGraphicsDataWriter::~IVectorGraphicsDataWriter() = default;
}
