#pragma once

#include <fstream>
#include <vector>
#include <limits>


/**
 * @brief Provides a simplistic tool to write svg files.
 *        The result is a html file that can be viewed in a browser.
 *
 * The class can be used to quickly create a 2D visualizatio,
 * e.g. for debugging purposes or analysis algorithm behavior.
 *
 */
class SVGWriter {

public:

    explicit SVGWriter(const std::string& a_filename,
                       int a_targetSize = 800,
                       int a_borderWidth = 10);

    ~SVGWriter();

    void drawCircle(double a_x, double a_y, int a_color, int a_radius);

    void drawLine(double a_fromX, double a_fromY, double a_toX, double a_toY, int a_color);

    void drawText(double a_fromX, double a_fromY, const std::string& a_text);


private:

    struct Coordinate
    {
        double m_x ;
        double m_y;
    };

    enum class CommandType
    {
        Circle,
        Line,
        Text
    };

    struct DrawCommand
    {
        CommandType m_type;
        Coordinate m_fromCoord;
        Coordinate m_toCoord;
        int m_color;
        int m_radius;
        std::string m_text;
    };

    void updateMinMax(const Coordinate& a_coord);

    static std::string getColorString(int a_color);


private:

    const int m_targetSize;
    const int m_borderWidth;

    std::vector<DrawCommand> m_commands;

    std::ofstream m_ofs;

    Coordinate m_min = { std::numeric_limits<double>::max(), std::numeric_limits<double>::max() } ;
    Coordinate m_max = { -std::numeric_limits<double>::max(), -std::numeric_limits<double>::max() } ;

};

