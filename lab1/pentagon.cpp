#include "pentagon.h"
#include <cmath>
#include <iostream>
Pentagon::Pentagon(std::istream &is)

{
is >> a;
is >> b;
is >> c;
is >> d;
is >> e;
}
void Pentagon::Print(std::ostream &os)
{
os << "Pentagon" << std::endl;
os << a << "," << b << "," << c << "," << d << "," << e << std::endl;
}
double Pentagon::Area()
{
return 0.5 * fabs(get_x(a)*get_y(b) + get_x(b)*get_y(c) + get_x(c)*get_y(d) + get_x(d)*get_y(e) + get_x(e)*get_y(a) - get_x(b)*get_y(a) - get_x(c)*get_y(b) - get_x(d)*get_y(c) - get_x(e)*get_y(d) - get_x(a)*get_y(e));
}
size_t Pentagon::VertexesNumber()
{
return 5;
}
Pentagon::~Pentagon()
{
std::cout << "Pentagon deleted" << std::endl;
}
