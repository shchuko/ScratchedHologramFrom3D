#include "CSvgFileWriter.hpp"
#include <iostream>
#include "EFileAlreadyExistsException.hpp"
#include "EFileCannotBeOverwritten.hpp"

namespace File2DProcessingTools {

    void CSvgFileWriter::write(std::string filepath, const File2DProcessingTools::CVectorGraphicsData &data,
                               bool write_force) {
        std::ofstream svg_file;
        tryOpenFile(filepath, svg_file, write_force);

        max.first = data.getMaxX();
        max.second = data.getMaxY();
        min.first = data.getMinX();
        min.second = data.getMinY();


        updateWidthHeight(max, min);
        updatePaddings();
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

        std::pair<double, double> max_xy = getMaxXY(data);
        std::pair<double, double> min_xy = getMinXY(data);

        max.first = max_xy.first;
        max.second = max_xy.second;
        min.first = min_xy.first;
        min.second = min_xy.second;

        updateWidthHeight(max_xy, min_xy);
        updatePaddings();
        writeBeginning(svg_file);
        for (const auto &item : data) {
            writePoints(item, svg_file, max_xy, min_xy);
        }
        writeEnding(svg_file);
        if (!svg_file.good()) {
            svg_file.close();
            throw File2DProcessingTools::Exceptions::EFileCannotBeOverwritten("File write errored.");
        }
        svg_file.close();
    }

    CSvgFileWriter::CSvgFileWriter(double height, double width) noexcept {
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

    double CSvgFileWriter::scaling(double height, double width) const noexcept {
        return (double) (_width - 2 * padding_horizontal) / width < (double) (_height - 2 * padding_vertical) / height ?
               (double) (_width - 2 * padding_horizontal) / width : (double) (_height - 2 * padding_vertical) / height;
    }

    void CSvgFileWriter::writeBeginning(std::ofstream &svg_file) const noexcept {
        svg_file << "<?xml version=\"1.0\" encoding=\"utf-8\" standalone=\"yes\"?>\n";
        svg_file << "<svg height = \"" << _height << "px\"  width = \""
                 << _width << "px\" " << "xmlns=\"http://www.w3.org/2000/svg\">\n";
    }


    void CSvgFileWriter::writePoints(const File2DProcessingTools::CVectorGraphicsData &data,
                                     std::ofstream &svg_file, std::pair<double, double> max_xy,
                                     std::pair<double, double> min_xy) const noexcept {
        auto colors = data.getLineSegmentsColors();
        auto widths = data.getLineSegmentsWidths();
        auto lines = data.getLineSegments();

        for (long long unsigned int i = 0; i < lines.size(); ++i) {
            svg_file << "<line "
                     << "x1=\""
                     << scale * (lines[i].getFirstPoint().getX() - min_xy.first) + padding_horizontal << "\" "
                     << "y1=\""
                     << scale * (max_xy.second - min_xy.second - (lines[i].getFirstPoint().getY() - min_xy.second)) +
                        padding_vertical << "\" "
                     << "x2=\""
                     << scale * (lines[i].getSecondPoint().getX() - min_xy.first) + padding_horizontal << "\" "
                     << "y2=\""
                     << scale * (max_xy.second - min_xy.second - (lines[i].getSecondPoint().getY() - min_xy.second)) +
                        padding_vertical << "\""
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

    void
    CSvgFileWriter::updateWidthHeight(std::pair<double, double> max_xy, std::pair<double, double> min_xy) noexcept {
        double max_x = max_xy.first;
        double min_x = min_xy.first;
        double max_y = max_xy.second;
        double min_y = min_xy.second;
        double width = max_x - min_x;
        double height = max_y - min_y;
        if (_height > 0 && _width > 0) {
            scale = scaling(height, width);
        } else if (_height > 0) {
            scale = (double) (_height - 2 * padding_vertical) / height;
            _width = width * scale + 2 * padding_horizontal;
        } else if (_width > 0) {
            scale = (double) (_width - 2 * padding_horizontal) / width;
            _height = height * scale + 2 * padding_horizontal;
        } else {
            _height = height;
            _width = width;
        }
    }

    void CSvgFileWriter::setCanvasHeight(double height_px) noexcept {
        _height = height_px;
    }

    void CSvgFileWriter::setCanvasWidth(double width_px) noexcept {
        _width = width_px;
    }

    void CSvgFileWriter::setCanvasSize(double height_px, double width_px) noexcept {
        _height = height_px;
        _width = width_px;
    }

    bool CSvgFileWriter::setAlignmentCenter(std::pair<double, double> padding_px) noexcept {
        if ((padding_px.first * 2 >= _width && _width != 0) || (padding_px.second * 2 >= _height && _height != 0)) {
            is_it_centering = false;
            return is_it_centering;
        }
        padding_horizontal = padding_px.first;
        padding_vertical = padding_px.second;
        is_it_centering = true;
        return is_it_centering;
    }

    void CSvgFileWriter::updatePaddings() noexcept {
        padding_horizontal += (_width - scale * (max.first - min.first)) / 2 - padding_horizontal;
        padding_vertical += (_height - scale * (max.second - min.second)) / 2 - padding_vertical;
    }


}

