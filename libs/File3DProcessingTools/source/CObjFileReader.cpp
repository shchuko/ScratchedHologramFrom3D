#include "CObjFileReader.hpp"

/**
 * @author Vladislav Yaroshchuk, github.com/shchuko
 */
namespace File3DProcessingTools {
    void CObjFileReader::readFile(const std::string &filepath, CObject3DData &output_data) {
        fin.open(filepath);
        if (!fin.is_open()) {
            throw Exceptions::EFile3DReadError("File_open_error");
        }

        while (!fin.eof()) {
            std::getline(fin, next_line);
            bool parse_line_success = false;
            try {
                parse_line_success = parseNextLine(output_data);
            } catch (...) {
                fin.close();
                throw Exceptions::EFile3DReadError("File content parsing error");
            }
            if (!parse_line_success) {
                fin.close();
                throw Exceptions::EFile3DReadError("No_normals_data_in_obj_file");
            }
        }
        fin.close();
    }

    bool CObjFileReader::parseNextLine(CObject3DData &output_data) {
        if (next_line.size() < 2)
            return true;

        if (next_line[0] == 'v' && next_line[1] == ' ') {
            parseVertexData(output_data);
            return true;
        }

        if (next_line[0] == 'v' && next_line[1] == 'n' && next_line[2] == ' ') {
            parseNormalVectorData(output_data);
            return true;
        }

        if (next_line[0] == 'f' && next_line[1] == ' ') {
            return parsePolygonData(output_data);
        }

        return true;
    }

    void CObjFileReader::parseVertexData(CObject3DData &output_data) {
        std::array<double, 3> coordinates{};
        int fill_index = 0;


        // Starting from 2nd symbol
        std::string::size_type i = 2;
        int parse_double_begin_index = -1;
        while (fill_index < 3) {
            if (i == next_line.length()) {
                coordinates[fill_index] = std::stod(next_line.substr(parse_double_begin_index));
                break;
            }

            if (next_line[i] != ' ') {
                if (parse_double_begin_index == -1) {
                    parse_double_begin_index = i;
                }
            } else if (parse_double_begin_index != -1) {
                coordinates[fill_index] = std::stod(
                        next_line.substr(parse_double_begin_index, i - parse_double_begin_index));
                parse_double_begin_index = -1;
                ++fill_index;
            }
            ++i;
        }

        output_data.addVertex({coordinates[0], coordinates[1], coordinates[2]});
    }

    void CObjFileReader::parseNormalVectorData(CObject3DData &output_data) {
        std::array<double, 3> coordinates{};
        int fill_index = 0;

        // Starting from 3rd symbol
        std::string::size_type i = 3;
        int parse_double_begin_index = -1;
        while (fill_index < 3) {
            if (i == next_line.length()) {
                coordinates[fill_index] = std::stod(next_line.substr(parse_double_begin_index));
                break;
            }

            if (next_line[i] != ' ') {
                if (parse_double_begin_index == -1) {
                    parse_double_begin_index = i;
                }
            } else if (parse_double_begin_index != -1) {
                coordinates[fill_index] = std::stod(
                        next_line.substr(parse_double_begin_index, i - parse_double_begin_index));
                parse_double_begin_index = -1;
                ++fill_index;
            }
            ++i;
        }

        output_data.addPolygonNormal({coordinates[0], coordinates[1], coordinates[2]});
    }

    bool CObjFileReader::parsePolygonData(CObject3DData &output_data) {
        std::vector<vrtx_size_t> polygon_vertexes{};
        nrml_size_t polygon_normal_index;
        long int vertex_number;

        long int parse_long_begin_index = -1;
        // 0 - vertex num, 1 - texture vertex num, 2 - normal vector num
        long int number_type_counter = 0;

        // Starting from 2nd symbol
        for (std::string::size_type i = 2; i < next_line.length(); ++i) {
            if (next_line[i] == ' ' || next_line[i] == '/') {
                if (parse_long_begin_index == -1) {
                    continue;
                }

                if (number_type_counter == 0) {
                    vertex_number = std::stol(next_line.substr(parse_long_begin_index, i - parse_long_begin_index)) - 1;
                }

                if (next_line[i] == ' ') {
                    if (number_type_counter == 0) {
                        return false;
                    }
                    polygon_vertexes.emplace_back(vertex_number);
                } else if (next_line[i] == '/' && next_line[i + 1] == '/') {
                    ++number_type_counter;
                }

                ++number_type_counter;
                parse_long_begin_index = -1;

                if (number_type_counter == 3) {
                    number_type_counter = 0;
                }
            } else if (parse_long_begin_index == -1) {
                parse_long_begin_index = i;
            }
        }

        polygon_vertexes.emplace_back(vertex_number);
        polygon_normal_index = std::stol(next_line.substr(parse_long_begin_index)) - 1;

        CPolygon polygon(polygon_normal_index);
        for (auto it = std::begin(polygon_vertexes); it != std::end(polygon_vertexes); ++it) {
            if (it + 1 != std::end(polygon_vertexes)) {
                polygon.addEdge(*it, *(it + 1));
            }
        }
        polygon.addEdge(polygon_vertexes.back(), polygon_vertexes.front());
        polygon.makeReadonly();
        output_data.addPolygon(std::move(polygon));
        return true;
    }
}
