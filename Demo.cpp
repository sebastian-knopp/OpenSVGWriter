#include "SVGWriter.h"
#include <iostream>


void runSVGWriterDemo()
{
    const std::string filename = "demo.html";

    std::cout << "This is a demonstration of the SVGWriter class." << std::endl;
    std::cout << "The example is written to the file '" << filename << "'" << std::endl;

    SVGWriter writer(filename, 300, 20);

    for (int i = 0; i < 20; ++i)
    {
        writer.drawCircle(50l * i, 100, i, 6);
        writer.drawLine(50l * i, 300, 50l * i, 400, i+3);
        writer.drawRectangle(50l * i - 10l, 450, 50l * i + 10l, 475, i + 5);
    }

    writer.drawText(115, 235, "Welcome to OpenSVGWriter", 18);

    // x-y Coordinates can be given in an arbitraty fashion (here: fromX > toX, fromY > toY)
    writer.drawRectangle(1000, 625, 900, 525, 7);
}


void runMatrixDemo()
{
    SVGWriter writer("matrixdemo.html", 300, 20);
    for (int x = 0; x < 10; ++x)
    {
        for (int y = 0; y < 10; ++y)
        {
            writer.drawRectangle(11*x, 11*y, 11*x+10, 11*y+10, 5 * x + 17 * y);
            writer.drawCircle(11*x + 5, 11*y + 5, 13 * x + 7 * y, 9);
        }
    }

    writer.drawRectangle(11*2+2, 11*3+2, 11*5+8, 11*3+8, 0);
    writer.drawRectangle(11*2+5, 11*3+6, 11*5+16, 11*9+17, 7, 5);
}


int main()
{
    runSVGWriterDemo();
    runMatrixDemo();

    return 0;
}



