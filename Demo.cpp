#include "SVGWriter.h"
#include <iostream>


int main()
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

    // x-y Coordinates can be given in an arbitraty fashin (here: fromX > toX, fromY > toY)
    writer.drawRectangle(1000, 625, 900, 525, 7);

    return 0;
}



