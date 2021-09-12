#include "hexagon.h"
#include <cmath>
#include <iostream>

Hexagon::Hexagon(std::istream &is)
{
    is >> a;
    is >> b;
    is >> c;
    is >> d;
    is >> e;
    is >> f;
}

void Hexagon::Print(std::ostream &os)
{
    os << "Hexagon" << std::endl;
    os << a << "," << b << "," << c << "," << d << "," << e << "," << f << std::endl;
}

size_t Hexagon::VertexesNumber()
{
    return 6;
}

double Hexagon::Area()
{
    return 0.5 * fabs(get_x(a)*get_y(b) + get_x(b)*get_y(c) + get_x(c)*get_y(d) + get_x(d)*get_y(e) + get_x(e)*get_y(f) + get_x(f)*get_y(a) - get_x(b)*get_y(a) - get_x(c)*get_y(b) - get_x(d)*get_y(c) - get_x(e)*get_y(d) - get_x(f)*get_y(e) - get_x(a)*get_y(f));
}

Hexagon::~Hexagon()
{
    std::cout << "Hexagon deleted" << std::endl;
}