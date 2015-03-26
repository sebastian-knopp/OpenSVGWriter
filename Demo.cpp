#include "SVGWriter.h"
#include <iostream>


int main()
{
    const std::string filename = "demo.html";

    std::cout << "This is a demonstration of the SVGWriter class." << std::endl;
    std::cout << "The example is written to the file '" << filename << "'" << std::endl;

    SVGWriter writer(filename);

    writer.drawCircle(20, 20, 0, 5);
    writer.drawCircle(30, 30, 1, 8);
    writer.drawCircle(40, 50, 2, 8);

    return 0;
}



