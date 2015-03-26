#pragma once

////////////////////////////////////////////////////////////////////////////////
// OpenSVGWriter
// https://github.com/sebastian-knopp/OpenSVGWriter
////////////////////////////////////////////////////////////////////////////////
//
// MIT LICENSE
// Copyright (c) 2015 Sebastian Knopp
//
// Permission is hereby granted, free of charge, to any person obtaining
// a copy of this software and associated documentation files (the "Software"),
// to deal in the Software without restriction, including without limitation
// the rights to use, copy, modify, merge, publish, distribute, sublicense,
// and/or sell copies of the Software, and to permit persons to whom the
// Software is furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included
// in all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
// EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
// MERCHANTABILITY,FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
// IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM,
// DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR
// OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE
// USE OR OTHER DEALINGS IN THE SOFTWARE.
////////////////////////////////////////////////////////////////////////////////


#include <fstream>
#include <vector>
#include <limits>


/**
 * @brief Provides a simplistic tool to write svg files.
 *        The result is a html file that can be viewed in a browser.
 *
 * The class can be used to quickly create a 2D visualizatio,
 * e.g. for debugging purposes or analysis of algorithm behavior.
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

