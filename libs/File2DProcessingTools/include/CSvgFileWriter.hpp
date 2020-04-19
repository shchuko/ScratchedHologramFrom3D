#pragma once

#include <fstream>
#include "IVectorGraphicsDataWriter.hpp"

namespace File2DProcessingTools {

    /**
     * Writes points to svg file
     * @author Nikita Novgorodtsev (github <https://github.com/paNoNi>)
     */
    class CSvgFileWriter : public IVectorGraphicsDataWriter {
    private:
        unsigned int _height = 0;
        unsigned int _width = 0;
        double scale = 1;
        unsigned int padding_horizontal = 0;
        unsigned int padding_vertical = 0;

    public:

        CSvgFileWriter() noexcept = default;

        /**
         * Constructor for adjusting canvas size
         * @param height -canvas height
         * @param width - canvas width
         */
        CSvgFileWriter(unsigned int height, unsigned int width) noexcept;

        /**
         * The main method of writing points to a file
         * @param filepath - File Path (* .svg)
         * @param data - point storage
         * @param write_force - parameter that defines actions when there is a file on a given path (true - overwrite,
         * false - do not overwrite)
         */
        void write(std::string filepath, const CVectorGraphicsData &data, bool write_force) override;

        /**
        * The main method of writing points to a file
        * @param filepath - File Path (* .svg)
        * @param data - vector of point storage
        * @param write_force - parameter that defines actions when there is a file on a given path (true - overwrite,
        * false - do not overwrite)
        */
        void writeMul(std::string filepath, const std::vector<CVectorGraphicsData> &data, bool write_force) override;

        /**
         * set canvas Width
         * @param height_px - canvas height
        */
        void setCanvasHeight(unsigned int height_px) noexcept override;

        /**
         * set canvas Width
         * @param width_px - canvas width
        */
        void setCanvasWidth(unsigned int width_px) noexcept override;

        /**
         * Set canvas size
         * @param height_px - canvas height
         * @param width_px - canvas width
         */
        void setCanvasSize(unsigned int height_px, unsigned int width_px) noexcept override;

        /** Padding.first = vertical  (up-side, down-side) padding width in pixels
        * Padding.second = horizontal (left-side, right-side) padding width in pixels
        * Rescale input data to fit if needed
        */
        bool setAlignmentCenter(std::pair<unsigned int, unsigned int> padding_px) noexcept override;

    private:

        void writeBeginning(std::ofstream &svg_file) const noexcept;

        static void writeEnding(std::ofstream &svg_file) noexcept;

        void writePoints(const File2DProcessingTools::CVectorGraphicsData &data,
                         std::ofstream &svg_file, std::pair<double, double> max,
                         std::pair<double, double> min) const noexcept;

        static bool isFileExists(const std::string &filepath, bool write_force);

        double scaling(unsigned int height, unsigned int width) const noexcept;

        static void tryOpenFile(const std::string &filepath, std::ofstream &svg_file, bool write_force);

        void updateWidthHeight(std::pair<double, double> max, std::pair<double, double> min) noexcept;

        static std::pair<double, double> getMaxXY(const std::vector<CVectorGraphicsData> &data) noexcept;

        static std::pair<double, double> getMinXY(const std::vector<CVectorGraphicsData> &data) noexcept;

    };

}