#include "CSvgFileWriter.hpp"
#include <sstream>
#include <iostream>
#include <EFileAlreadyExistsException.hpp>
#include <EFileCannotBeOverwritten.hpp>

namespace File2DProcessingTools {

    void File2DProcessingTools::CSvgFileWriter::write(std::string filepath,
                                                      const File2DProcessingTools::CVectorGraphicsData &data,
                                                      bool write_force) {

        try {
            isFileExists(filepath, write_force);
        } catch (File2DProcessingTools::Exceptions::EFileAlreadyExistsException &ex) {
            throw File2DProcessingTools::Exceptions::EFileAlreadyExistsException(ex.what());
        }

        std::ofstream svg_file;

        int max_x = ceil(data.getMaxX());
        int min_x = ceil(data.getMinX());
        int max_y = ceil(data.getMaxY());
        int min_y = ceil(data.getMinY());
        unsigned int width = max_x - min_x;
        unsigned height = max_y - min_y;
        double scale = 1;
        if (_height <= 0 && _width <= 0) {
            scale = scaling(height, width);
            height = _height;
            width = _width;
        }

        svg_file.open(filepath);
        if (svg_file) {
            if (svg_file.bad()) {
                svg_file.close();
                throw File2DProcessingTools::Exceptions::EFileCannotBeOverwritten("File write errored.");
            }

            svg_file << "<?xml version=\"1.0\" encoding=\"utf-8\" standalone=\"yes\"?>\n";
            std::stringstream stream;
            stream << "<svg height = \"" << height << "px\"  width = \""
                   << width << "px\">\n";
            for (const auto &line : data.getLineSegments()) {
                stream << "<path d=\"M "
                       << scale * (line.getFirstPoint().getX() - min_x) << " "
                       << scale * (max_y - min_y - (line.getFirstPoint().getY() - min_y)) << " L "
                       << scale * (line.getSecondPoint().getX() - min_x) << " "
                       << scale * (max_y - min_y - (line.getSecondPoint().getY() - min_y))
                       << " L\" stroke=\"black\" stroke-width=\"1\"  />\n";
            }

            svg_file << stream.str();
            svg_file << "</svg>\n";
            svg_file.close();
        } else {
            throw File2DProcessingTools::Exceptions::EFileCannotBeOverwritten("Couldn't be opened");
        }
    }

    CSvgFileWriter::CSvgFileWriter(unsigned int height, unsigned int width) {
        _height = height;
        _width = width;
    }

    void CSvgFileWriter::isFileExists(const std::string &filepath, bool write_force) {
        std::ifstream check_file(filepath);

        if (check_file.is_open() && !write_force) {
            check_file.close();
            throw File2DProcessingTools::Exceptions::EFileAlreadyExistsException(
                    "Pass write_force = true to overwrite the existing file.");

        }
        check_file.close();
    }

    double CSvgFileWriter::scaling(unsigned int height, unsigned int width) {
        return (double) _width / width < (double) _height / height ?
               (double) _width / width : (double) _height / height;
    }
}

