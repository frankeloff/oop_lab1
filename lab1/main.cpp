#include <iostream>
#include "rhombus.h"
#include "pentagon.h"
#include "hexagon.h"

int main()
{
    Rhombus a(std::cin);
    std::cout << "Square = " << a.Area() << std::endl;
    a.Print(std::cout);

    Pentagon b(std::cin);
    std::cout << "Square = " << b.Area() << std::endl;
    b.Print(std::cout);

    Hexagon c(std::cin);
    std::cout << "Square = " << c.Area() << std::endl;
    c.Print(std::cout);

    return 0;
}