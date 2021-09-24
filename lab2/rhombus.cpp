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

Rhombus::Rhombus(Point pa, Point pb, Point pc, Point pd): a(pa), b(pb), c(pc), d(pd)
{
    std::cout << "Rhombus created" << std::endl;
}

// void Rhombus::Print(std::ostream &os)
// {
//     os << "Rhombus" << std::endl;
//     os << a << ',' << b << ',' << c << ',' << d << std::endl;
// }

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

std::ostream& operator<<(std::ostream& os, Rhombus& p) {
  os << p.a << p.b << p.c << p.d;
  return os;
}


// Point get_a(const Rhombus& other)
// {
//     return other.a;
// }

// Point get_b(Rhombus& other)
// {
//     return other.b;
// }

// Point get_c(Rhombus& other)
// {
//     return other.c;
// }

// Point get_d(Rhombus& other)
// {
//     return other.d;
// }