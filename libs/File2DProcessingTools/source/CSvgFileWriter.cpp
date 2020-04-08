#include "CSvgFileWriter.hpp"
#include <sstream>
#include <iostream>
#include <EFileAlreadyExistsException.hpp>
#include <EFileCannotBeOverwritten.hpp>

namespace File2DProcessingTools {

    void File2DProcessingTools::CSvgFileWriter::write(std::string filepath,
                                                      const File2DProcessingTools::CVectorGraphicsData &data,
                                                      bool write_force) {
        checkFile(filepath, write_force);
        std::ofstream svg_file(filepath);
        std::stringstream stream;

        std::pair<double, double> max(data.getMaxX(), data.getMaxY());
        std::pair<double, double> min(data.getMinX(), data.getMinY());

        doAnalysis(max, min);
        writeBeginning(stream);
        writePoints(data, stream, max, min);
        writeEnd(stream);
        svg_file << stream.str();
        svg_file.close();
    }

    void CSvgFileWriter::writeMul(std::string filepath, const std::vector<CVectorGraphicsData> &data,
                                  bool write_force) {

        checkFile(filepath, write_force);
        std::ofstream svg_file(filepath);
        std::stringstream stream;


        std::pair<double, double> max = getMax(data);
        std::pair<double, double> min = getMin(data);

        doAnalysis(max, min);
        writeBeginning(stream);
        for (const auto &item : data) {
            writePoints(item, stream, max, min);
        }
        writeEnd(stream);
        svg_file << stream.str();
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

    void CSvgFileWriter::writeBeginning(std::stringstream &stream) {

        stream << "<?xml version=\"1.0\" encoding=\"utf-8\" standalone=\"yes\"?>\n";
        stream << "<svg height = \"" << _height << "px\"  width = \""
               << _width << "px\">\n";

    }

    void CSvgFileWriter::writePoints(const File2DProcessingTools::CVectorGraphicsData &data,
                                     std::stringstream &stream, std::pair<double, double> max,
                                     std::pair<double, double> min) {
        for (const auto &line : data.getLineSegments()) {
            stream << "<path d=\"M "
                   << scale * (line.getFirstPoint().getX() - min.first) << " "
                   << scale * (max.second - min.second - (line.getFirstPoint().getY() - min.second))
                   << " L "
                   << scale * (line.getSecondPoint().getX() - min.first) << " "
                   << scale * (max.second - min.second - (line.getSecondPoint().getY() - min.second))
                   << " L\" stroke=\"black\" stroke-width=\"1\"  />\n";
        }
    }

    void CSvgFileWriter::writeEnd(std::stringstream &stream) {
        stream << "</svg>\n";
    }

    void CSvgFileWriter::checkFile(const std::string &filepath, bool write_force) {

        if (!isFileExists(filepath, write_force))
            throw File2DProcessingTools::Exceptions::EFileAlreadyExistsException(
                    "Pass write_force = true to overwrite the existing file.");


        std::ofstream svg_file(filepath);

        if (!svg_file.is_open()) {
            throw File2DProcessingTools::Exceptions::EFileCannotBeOverwritten("Couldn't be opened");
        }

        if (svg_file.bad()) {
            svg_file.close();
            throw File2DProcessingTools::Exceptions::EFileCannotBeOverwritten("File write errored.");
        }
        svg_file.close();
    }

    std::pair<double, double> CSvgFileWriter::getMax(const std::vector<CVectorGraphicsData> &data) {
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

    std::pair<double, double> CSvgFileWriter::getMin(const std::vector<CVectorGraphicsData> &data) {
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

    void CSvgFileWriter::doAnalysis(std::pair<double, double> max, std::pair<double, double> min) {
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

