#include <iostream>
#include "rhombus.h"
#include <math.h>

Rhombus::Rhombus(std::istream &is)
{
    is >> a;
    is >> b;
    is >> c;
    is >> d;
}

void Rhombus::Print(std::ostream &os)
{
    os << "Rhombus" << std::endl;
    os << a << ',' << b << ',' << c << ',' << d << std::endl;
}

double Rhombus::Area()
{
    return 0.5 * fabs(get_x(a)*get_y(b) + get_x(b)*get_y(c) + get_x(c)*get_y(d) + get_x(d)*get_y(a) - get_x(b)*get_y(a) - get_x(c)*get_y(b) - get_x(d)*get_y(c) - get_x(a)*get_y(d));
}

Rhombus::~Rhombus()
{
    std::cout << "Rhombus deleted" << std::endl;
}

size_t Rhombus::VertexesNumber()
{
    return 4;
}