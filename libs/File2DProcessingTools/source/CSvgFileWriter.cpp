#include "CSvgFileWriter.hpp"
#include <sstream>
#include <iostream>
#include <EFileAlreadyExistsException.hpp>
#include <EFileCannotBeOverwritten.hpp>

namespace File2DProcessingTools {

    void File2DProcessingTools::CSvgFileWriter::write(std::string filepath,
                                                      const File2DProcessingTools::CVectorGraphicsData &data,
                                                      bool write_force) {
        std::ofstream svg_file;
        checkFile(filepath, svg_file, write_force);
        svg_file.open(filepath);

        std::pair<double, double> max(data.getMaxX(), data.getMaxY());
        std::pair<double, double> min(data.getMinX(), data.getMinY());

        updateWidthHeight(max, min);
        writeBeginning(svg_file);
        writePoints(data, svg_file, max, min);
        writeEnding(svg_file);
        svg_file.close();
    }

    void CSvgFileWriter::writeMul(std::string filepath, const std::vector<CVectorGraphicsData> &data,
                                  bool write_force) {

        std::ofstream svg_file;
        checkFile(filepath, svg_file, write_force);
        svg_file.open(filepath);

        std::pair<double, double> max = getMaxXY(data);
        std::pair<double, double> min = getMinXY(data);

        updateWidthHeight(max, min);
        writeBeginning(svg_file);
        for (const auto &item : data) {
            writePoints(item, svg_file, max, min);
        }
        writeEnding(svg_file);
        svg_file.close();
    }

    CSvgFileWriter::CSvgFileWriter(unsigned int height, unsigned int width) noexcept {
        _height = height;
        _width = width;
    }

    bool CSvgFileWriter::isFileExists(const std::string &filepath, bool write_force) {
        std::ifstream check_file(filepath);

        if (check_file.is_open() && !write_force) {
            check_file.close();
            return false;
        }
        check_file.close();
        return true;
    }

    double CSvgFileWriter::scaling(unsigned int height, unsigned int width) {
        return (double) _width / width < (double) _height / height ?
               (double) _width / width : (double) _height / height;
    }

    void CSvgFileWriter::writeBeginning(std::ofstream &svg_file) {

        svg_file << "<?xml version=\"1.0\" encoding=\"utf-8\" standalone=\"yes\"?>\n";
        svg_file << "<svg height = \"" << _height << "px\"  width = \""
                 << _width << "px\">\n";

    }

    void CSvgFileWriter::writePoints(const File2DProcessingTools::CVectorGraphicsData &data,
                                     std::ofstream &svg_file, std::pair<double, double> max,
                                     std::pair<double, double> min) {
        for (const auto &line : data.getLineSegments()) {
            svg_file << "<path d=\"M "
                     << scale * (line.getFirstPoint().getX() - min.first) << " "
                     << scale * (max.second - min.second - (line.getFirstPoint().getY() - min.second))
                     << " L "
                     << scale * (line.getSecondPoint().getX() - min.first) << " "
                     << scale * (max.second - min.second - (line.getSecondPoint().getY() - min.second))
                     << " L\" stroke=\"black\" stroke-width=\"1\"  />\n";
        }
    }

    void CSvgFileWriter::writeEnding(std::ofstream &svg_file) {
        svg_file << "</svg>\n";
    }

    void CSvgFileWriter::checkFile(const std::string &filepath, std::ofstream &svg_file, bool write_force) {

        if (!isFileExists(filepath, write_force))
            throw File2DProcessingTools::Exceptions::EFileAlreadyExistsException(
                    "Pass write_force = true to overwrite the existing file.");


        svg_file.open(filepath);
        if (!svg_file.is_open()) {
            throw File2DProcessingTools::Exceptions::EFileCannotBeOverwritten("Couldn't be opened");
        }

        if (svg_file.bad()) {
            svg_file.close();
            throw File2DProcessingTools::Exceptions::EFileCannotBeOverwritten("File write errored.");
        }
        svg_file.close();
    }

    std::pair<double, double> CSvgFileWriter::getMaxXY(const std::vector<CVectorGraphicsData> &data) {
        std::pair<double, double> max(-std::numeric_limits<double>::max(), -std::numeric_limits<double>::min());
        for (const auto &item : data) {
            if (item.getMaxX() > max.first) {
                max.first = item.getMaxX();
            }
            if (item.getMaxY() > max.second) {
                max.second = item.getMaxY();
            }
        }
        return max;
    }

    std::pair<double, double> CSvgFileWriter::getMinXY(const std::vector<CVectorGraphicsData> &data) {
        std::pair<double, double> min(std::numeric_limits<double>::max(), std::numeric_limits<double>::min());
        for (const auto &item : data) {
            if (item.getMinX() < min.first) {
                min.first = item.getMinX();
            }
            if (item.getMinY() < min.second) {
                min.second = item.getMinY();
            }
        }
        return min;
    }

    void CSvgFileWriter::updateWidthHeight(std::pair<double, double> max, std::pair<double, double> min) {
        int max_x = std::ceil(max.first);
        int min_x = std::ceil(min.first);
        int max_y = std::ceil(max.second);
        int min_y = std::ceil(min.second);
        unsigned int width = max_x - min_x;
        unsigned int height = max_y - min_y;
        if (_height > 0 && _width > 0) {
            scale = scaling(height, width);
        } else {
            _height = height;
            _width = width;
        }
    }


}

