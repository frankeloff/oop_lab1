#ifndef PENTAGON_H
#define PENTAGON_
#include <iostream>
#include "figure.h"

class Pentagon : public Figure

{
public:
Pentagon(std::istream &is);
double Area();
void Print(std::ostream &os);
size_t VertexesNumber();
virtual ~Pentagon();
private:
Point a, b, c, d, e;
};

#endif // PENTAGON_H
