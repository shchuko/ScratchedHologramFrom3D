#include "CSvgFileWriter.hpp"
#include <iostream>
#include "EFileAlreadyExistsException.hpp"
#include "EFileCannotBeOverwritten.hpp"

namespace File2DProcessingTools {

    void CSvgFileWriter::write(std::string filepath, const File2DProcessingTools::CVectorGraphicsData &data,
                               bool write_force) {
        std::ofstream svg_file;
        tryOpenFile(filepath, svg_file, write_force);

        std::pair<double, double> max(data.getMaxX(), data.getMaxY());
        std::pair<double, double> min(data.getMinX(), data.getMinY());

        updateWidthHeight(max, min);
        writeBeginning(svg_file);
        writePoints(data, svg_file, max, min);
        writeEnding(svg_file);
        if (!svg_file.good()) {
            svg_file.close();
            throw File2DProcessingTools::Exceptions::EFileCannotBeOverwritten("File write errored.");
        }
        svg_file.close();
    }

    void CSvgFileWriter::writeMul(std::string filepath, const std::vector<CVectorGraphicsData> &data,
                                  bool write_force) {

        std::ofstream svg_file;
        tryOpenFile(filepath, svg_file, write_force);

        std::pair<double, double> max = getMaxXY(data);
        std::pair<double, double> min = getMinXY(data);

        updateWidthHeight(max, min);
        writeBeginning(svg_file);
        for (const auto &item : data) {
            writePoints(item, svg_file, max, min);
        }
        writeEnding(svg_file);
        if (!svg_file.good()) {
            svg_file.close();
            throw File2DProcessingTools::Exceptions::EFileCannotBeOverwritten("File write errored.");
        }
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

    double CSvgFileWriter::scaling(unsigned int height, unsigned int width) const noexcept {
        return (double) (_width - padding_horizontal) / width < (double) (_height - padding_vertical) / height ?
               (double) (_width - padding_horizontal) / width : (double) (_height - padding_vertical) / height;
    }

    void CSvgFileWriter::writeBeginning(std::ofstream &svg_file) const noexcept {
        svg_file << "<?xml version=\"1.0\" encoding=\"utf-8\" standalone=\"yes\"?>\n";
        svg_file << "<svg height = \"" << _height << "px\"  width = \""
                 << _width << "px\" " << "xmlns=\"http://www.w3.org/2000/svg\">\n";
    }


    void CSvgFileWriter::writePoints(const File2DProcessingTools::CVectorGraphicsData &data,
                                     std::ofstream &svg_file, std::pair<double, double> max,
                                     std::pair<double, double> min) const noexcept {
        auto colors = data.getLineSegmentsColors();
        auto widths = data.getLineSegmentsWidths();
        auto lines = data.getLineSegments();
        for (long long unsigned int i = 0; i < lines.size(); ++i) {
            svg_file << "<line "
                     << "x1=\""
                     << scale * (lines[i].getFirstPoint().getX() - min.first) + double(padding_horizontal) / 2 << "\" "
                     << "y1=\""
                     << scale * (max.second - min.second - (lines[i].getFirstPoint().getY() - min.second)) +
                        double(padding_vertical) / 2 << "\" "
                     << "x2=\""
                     << scale * (lines[i].getSecondPoint().getX() - min.first) + double(padding_horizontal) / 2 << "\" "
                     << "y2=\""
                     << scale * (max.second - min.second - (lines[i].getSecondPoint().getY() - min.second)) +
                        double(padding_vertical) / 2 << "\""
                     << R"( fill="none" stroke=")" + colors[i].getHexStr() + "\" stroke-width=\"" +
                        std::to_string(widths[i]) + "\"  />\n";
        }
    }

    void CSvgFileWriter::writeEnding(std::ofstream &svg_file) noexcept {
        svg_file << "</svg>\n";
    }

    void CSvgFileWriter::tryOpenFile(const std::string &filepath, std::ofstream &svg_file, bool write_force) {

        if (!isFileExists(filepath, write_force))
            throw File2DProcessingTools::Exceptions::EFileAlreadyExistsException(
                    "Pass write_force = true to overwrite the existing file.");

        svg_file.open(filepath);
        if (!svg_file.is_open()) {
            throw File2DProcessingTools::Exceptions::EFileCannotBeOverwritten("Couldn't be opened");
        }

    }

    std::pair<double, double> CSvgFileWriter::getMaxXY(const std::vector<CVectorGraphicsData> &data) noexcept {
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

    std::pair<double, double> CSvgFileWriter::getMinXY(const std::vector<CVectorGraphicsData> &data) noexcept {
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

    void CSvgFileWriter::updateWidthHeight(std::pair<double, double> max, std::pair<double, double> min) noexcept {
        int max_x = std::ceil(max.first);
        int min_x = std::ceil(min.first);
        int max_y = std::ceil(max.second);
        int min_y = std::ceil(min.second);
        unsigned int width = max_x - min_x;
        unsigned int height = max_y - min_y;
        if (_height > 0 && _width > 0) {
            scale = scaling(height, width);
        } else if (_height > 0) {
            _width = width;
            scale = scaling(height, width);
        } else if (_width > 0) {
            _height = height;
            scale = scaling(height, width);
        } else {
            _height = height;
            _width = width;
        }
    }

    void CSvgFileWriter::setCanvasHeight(unsigned int height_px) noexcept {
        _height = height_px;
    }

    void CSvgFileWriter::setCanvasWidth(unsigned int width_px) noexcept {
        _width = width_px;
    }

    void CSvgFileWriter::setCanvasSize(unsigned int height_px, unsigned int width_px) noexcept  {
        _height = height_px;
        _width = width_px;
    }

    bool CSvgFileWriter::setAlignmentCenter(std::pair<unsigned int, unsigned int> padding_px) noexcept {
        if (padding_px.first >= _width || padding_px.second >= _height) {
            return false;
        }
        padding_horizontal = padding_px.first;
        padding_vertical = padding_px.second;
        return true;
    }


}

