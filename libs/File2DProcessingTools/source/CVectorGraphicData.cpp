#include "CVectorGraphicsData.hpp"

namespace File2DProcessingTools {

    void
    CVectorGraphicsData::addLineSegments(Geometry2D::CLineSegment2D line_segment, unsigned int width_pixels) noexcept {
        checkRange(line_segment);
        _line_segments.emplace_back(line_segment);
        _line_segments_widths.emplace_back(width_pixels);
        _colors.emplace_back(_current_color);
    }


    const std::vector<Geometry2D::CLineSegment2D> &CVectorGraphicsData::getLineSegments() const noexcept {
        return _line_segments;
    }


    void CVectorGraphicsData::checkRange(const Geometry2D::CLineSegment2D &line_segment) noexcept {
        if (line_segment.getFirstPoint().getX() < min_x) {
            min_x = line_segment.getFirstPoint().getX();
        }
        if (line_segment.getFirstPoint().getY() < min_y) {
            min_y = line_segment.getFirstPoint().getY();
        }
        if (line_segment.getFirstPoint().getX() > max_x) {
            max_x = line_segment.getFirstPoint().getX();
        }
        if (line_segment.getFirstPoint().getY() > max_y) {
            max_y = line_segment.getFirstPoint().getY();
        }
        if (line_segment.getSecondPoint().getX() < min_x) {
            min_x = line_segment.getSecondPoint().getX();
        }
        if (line_segment.getSecondPoint().getY() < min_y) {
            min_y = line_segment.getSecondPoint().getY();
        }
        if (line_segment.getSecondPoint().getX() > max_x) {
            max_x = line_segment.getSecondPoint().getX();
        }
        if (line_segment.getSecondPoint().getY() > max_y) {
            max_y = line_segment.getSecondPoint().getY();
        }

    }

    double CVectorGraphicsData::getMaxX() const noexcept {
        return max_x;
    }

    double CVectorGraphicsData::getMaxY() const noexcept {
        return max_y;
    }

    double CVectorGraphicsData::getMinX() const noexcept {
        return min_x;
    }

    double CVectorGraphicsData::getMinY() const noexcept {
        return min_y;
    }

    void CVectorGraphicsData::setNextColor(const CVectorGraphicsData::CColor_T &color) noexcept {
        _current_color = color;
    }

    const std::vector<unsigned int> &CVectorGraphicsData::getLineSegmentsWidths() const noexcept {
        return _line_segments_widths;
    }

    const std::vector<CVectorGraphicsData::CColor_T> &CVectorGraphicsData::getLineSegmentsColors() const noexcept {
        return _colors;
    }

    CVectorGraphicsData::CColor_T::CColor_T(uint8_t red, uint8_t green, uint8_t blue) noexcept{
        setColor(red, green, blue);
    }


    CVectorGraphicsData::CColor_T::CColor_T(std::string hex_color) {
        setColor(std::move(hex_color));
    }

    void CVectorGraphicsData::CColor_T::setColor(uint8_t red, uint8_t green, uint8_t blue) noexcept {
        _red = red;
        _green = green;
        _blue = blue;

        unsigned int value = 0;
        value |= (static_cast<unsigned int>(red) << 16U);
        value |= (static_cast<unsigned int>(green) << 8U);
        value |= (static_cast<unsigned int>(blue) << 0U);

        std::stringstream stream;
        stream << '#' << std::uppercase << std::setw(6) << std::setfill('0') << std::left << std::hex << value;
        _hex_color = stream.str();

    }

    void CVectorGraphicsData::CColor_T::setColor(std::string color_hex) {
        if (color_hex[0] == '#') {
            color_hex = color_hex.substr(1);
        }

        std::locale loc;
        for (char c : color_hex) {
            if (!std::isxdigit(c, loc)) {
                throw Exceptions::ENotAColorHex("Wrong format");
            }
        }

        if (color_hex.length() != 3 && color_hex.length() != 6) {
            throw Exceptions::ENotAColorHex("Size expected: 3 or 6, but actual: " + std::to_string(color_hex.size()));
        }

        std::stringstream stream;
        stream << std::hex << color_hex;
        _hex_color = '#' + color_hex;
        unsigned long int hex_value;
        stream >> hex_value;

        bool short_notation = (color_hex.length() == 3);
        unsigned int bits_offset_len = short_notation ? 4 : 8;
        uint8_t bits_fill = short_notation ? 0x0F : 0xFF;

        uint8_t red = (bits_fill & (hex_value >> 2 * bits_offset_len));
        uint8_t green = (bits_fill & (hex_value >> 1 * bits_offset_len));
        uint8_t blue = (bits_fill & (hex_value >> 0 * bits_offset_len));

        if (short_notation) {
            red = (red << 4U) + red;
            green = (green << 4U) + green;
            blue = (blue << 4U) + blue;
        }
        _red = red;
        _green = green;
        _blue = blue;
    }

    std::string CVectorGraphicsData::CColor_T::getHexStr() const noexcept {
        return _hex_color;
    }

    std::string CVectorGraphicsData::CColor_T::getRGBStr() const noexcept {
        return std::to_string(_red) + ", " + std::to_string(_green) + ", " + std::to_string(_blue);
    }

    void CVectorGraphicsData::CColor_T::setColor(CVectorGraphicsData::CColor_T::COLOR color) noexcept {
        switch (color) {
            case CVectorGraphicsData::CColor_T::COLOR::RED :
                setColor(255, 0, 0);
                break;
            case CVectorGraphicsData::CColor_T::COLOR::ORANGE :
                setColor(255, 128, 0);
                break;
            case CVectorGraphicsData::CColor_T::COLOR::YELLOW :
                setColor(255, 255, 0);
                break;
            case CVectorGraphicsData::CColor_T::COLOR::GREEN :
                setColor(51, 255, 51);
                break;
            case CVectorGraphicsData::CColor_T::COLOR::BLUE :
                setColor(51, 51, 255);
                break;
            case CVectorGraphicsData::CColor_T::COLOR::PURPLE :
                setColor(204, 0, 204);
                break;
            case CVectorGraphicsData::CColor_T::COLOR::BLACK :
                setColor(0, 0, 0);
                break;
            case CVectorGraphicsData::CColor_T::COLOR::WHITE :
                setColor(255, 255, 255);
                break;
            case CVectorGraphicsData::CColor_T::COLOR::PINK :
                setColor(255, 20, 147);
                break;
            case CVectorGraphicsData::CColor_T::COLOR::GREY :
                setColor(160, 160, 160);
                break;
        }
    }

    CVectorGraphicsData::CColor_T::CColor_T(CVectorGraphicsData::CColor_T::COLOR color) noexcept {
        setColor(color);
    }


}