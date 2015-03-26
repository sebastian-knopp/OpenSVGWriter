#include "SVGWriter.h"
#include <iostream>
#include <algorithm>
#include <tuple>


SVGWriter::SVGWriter(const std::string& a_filename,
                     const int a_targetSize,
                     const int a_borderWidth)
: m_targetSize(a_targetSize)
, m_borderWidth(a_borderWidth)
, m_ofs(a_filename)
{
}


SVGWriter::~SVGWriter()
{
    const double dblWidth =  m_max.m_x - m_min.m_x;
    double dblHeight =  m_max.m_y - m_min.m_y;

    double scaleFactor = static_cast<double>(m_targetSize) / std::max(dblWidth, dblHeight);

    auto getScaledValue = [scaleFactor, this] (const double a_value)
    {
        return static_cast<int>(scaleFactor * a_value);
    };

    auto getScaledXValue = [scaleFactor, this] (const double a_value)
    {
        return static_cast<int>(scaleFactor * (a_value - m_min.m_x)) + m_borderWidth;
    };

    auto getScaledYValue = [scaleFactor, this] (const double a_value)
    {
        return static_cast<int>(scaleFactor * (a_value - m_min.m_y)) + m_borderWidth;
    };

    const int width = getScaledXValue(m_max.m_x) + m_borderWidth;
    const int height = getScaledYValue(m_max.m_y) + m_borderWidth;

    m_ofs << "<!DOCTYPE html>\n"
          << "<html>\n"
          << "<body>\n"
          << "<svg height=\"" << height << "\" width=\"" << width << "\">\n";

    for (const DrawCommand& command : m_commands)
    {
        m_ofs << "  ";

        switch (command.m_type)
        {
            case CommandType::Circle:
                m_ofs << "<circle "
                      << "cx=\"" << (getScaledXValue(command.m_fromCoord.m_x)) << "\" "
                      << "cy=\"" << (getScaledYValue(command.m_fromCoord.m_y)) << "\" "
                      << "r=\"" << command.m_size << "\" stroke=\"black\" stroke-width=\"0\" "
                      << "fill=\"" << getColorString(command.m_color) << "\" />\n";
                break;
        case CommandType::Line:
            m_ofs << "<line "
                  << "x1=\"" << getScaledXValue(command.m_fromCoord.m_x) << "\" "
                  << "y1=\"" << getScaledYValue(command.m_fromCoord.m_y) << "\" "
                  << "x2=\"" << getScaledXValue(command.m_toCoord.m_x) << "\" "
                  << "y2=\"" << getScaledYValue(command.m_toCoord.m_y) << "\" "
                  << " style=\"stroke:" << getColorString(command.m_color) << ";stroke-width:2\" />\n";
            break;
        case CommandType::Text:
            m_ofs << "<text "
                  << "x=\"" << getScaledXValue(command.m_fromCoord.m_x) << "\" "
                  << "y=\"" << getScaledYValue(command.m_fromCoord.m_y) << "\" "
                  << "font-size=\"" << command.m_size << "\" "
                  << "font-family=\"arial\">" << command.m_text << "</text>\n";
            break;
        case CommandType::Rectangle:
            m_ofs << "<rect "
                  << "x=\"" << getScaledXValue(command.m_fromCoord.m_x) << "\" "
                  << "y=\"" << getScaledYValue(command.m_fromCoord.m_y) << "\" "
                  << "width=\"" << getScaledValue(command.m_toCoord.m_x - command.m_fromCoord.m_x) << "\" "
                  << "height=\"" << getScaledValue(command.m_toCoord.m_y - command.m_fromCoord.m_y) << "\" "
                  << " style=\"fill:" << getColorString(command.m_color) << "; stroke-width:1\" />\n";
            break;
        }
    }

    //<rect width="300" height="100" style="fill:rgb(0,0,255);stroke-width:3;stroke:rgb(0,0,0)" />
    m_ofs << "</svg>\n"
          << "</body>\n"
          << "</html>\n";
}


void SVGWriter::drawCircle(double a_x, double a_y, int a_colorIndex, int a_diameter)
{
    const Coordinate c {  a_x, a_y };
    updateMinMax(c);

    m_commands.push_back(DrawCommand { CommandType::Circle, c, c, a_colorIndex, a_diameter, "" });
}


void SVGWriter::drawLine(double a_fromX, double a_fromY, double a_toX, double a_toY, int a_colorIndex)
{
    const Coordinate from {  a_fromX, a_fromY };
    updateMinMax(from);

    const Coordinate to {  a_toX, a_toY };
    updateMinMax(to);

    m_commands.push_back(DrawCommand { CommandType::Line, from, to, a_colorIndex, 0, "" });
}


void SVGWriter::drawRectangle(double a_fromX, double a_fromY, double a_toX, double a_toY, int a_colorIndex)
{
    std::tie(a_fromX, a_toX) = std::make_tuple(std::min(a_fromX, a_toX), std::max(a_fromX, a_toX));
    std::tie(a_fromY, a_toY) = std::make_tuple(std::min(a_fromY, a_toY), std::max(a_fromY, a_toY));

    const Coordinate from { a_fromX, a_fromY };
    updateMinMax(from);

    const Coordinate to { a_toX, a_toY };
    updateMinMax(to);

    m_commands.push_back(DrawCommand { CommandType::Rectangle, from, to, a_colorIndex, 0, "" });
}


void SVGWriter::drawText(double a_x, double a_y, const std::string& a_text, int a_fontSize)
{
    const Coordinate c { a_x, a_y };
    updateMinMax(c);

    m_commands.push_back(DrawCommand { CommandType::Text, c, c, 0, a_fontSize, a_text });
}


std::string SVGWriter::getColorString(int a_color)
{
    a_color = a_color % 9;
    switch (a_color)
    {
        case 0:
            return "black";
        case 1:
            return "yellowgreen";
        case 2:
            return "lightskyblue";
        case 3:
            return "hotpink";
        case 4:
            return "mediumpurple";
        case 5:
            return "goldenrod";
        case 6:
            return "slategrey";
        case 7:
            return "gold";
        case 8:
            return "red";
        default:
            return "darkcyan";
    }
}


void SVGWriter::updateMinMax(const SVGWriter::Coordinate& a_coord)
{
    m_min.m_x = std::min(a_coord.m_x, m_min.m_x);
    m_min.m_y = std::min(a_coord.m_y, m_min.m_y);

    m_max.m_x = std::max(a_coord.m_x, m_max.m_x);
    m_max.m_y = std::max(a_coord.m_y, m_max.m_y);
}





