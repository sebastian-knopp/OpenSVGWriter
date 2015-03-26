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
 * The given coordinates are automatically scaled to the given target size.
 */
class SVGWriter {

public:

    /**
     * @brief Creates a writer object.
     * @param a_filename Name of the file to be written.
     * @param a_targetSize Defines the maximum width and height of the canvas.
     * @param a_borderWidth Specifies the border size of the canvas.
     */
    explicit SVGWriter(const std::string& a_filename,
                       int a_targetSize = 800,
                       int a_borderWidth = 10);

    //! The results are written on destruction of the writer.
    ~SVGWriter();

    /**
     * @brief Draws a circle with the given coordinates
     * @param a_diameter Is given in absolute pixels (not scaled later).
     */
    void drawCircle(double a_x, double a_y, int a_colorIndex = 0, int a_diameter = 1);

    void drawLine(double a_fromX, double a_fromY, double a_toX, double a_toY, int a_colorIndex = 0);

    void drawRectangle(double a_fromX, double a_fromY, double a_toX, double a_toY, int a_colorIndex = 0);

    void drawText(double a_fromX, double a_fromY, const std::string& a_text, int a_fontSize = 12);


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
        Text,
        Rectangle
    };

    struct DrawCommand
    {
        CommandType m_type;
        Coordinate m_fromCoord;
        Coordinate m_toCoord;
        int m_color;
        int m_size; // can be font size or diameter
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

