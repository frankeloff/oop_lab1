#ifndef HEXAGON_H
#define HEXAGON_H
#include <iostream>
#include "figure.h"

class Hexagon : public Figure
{
public:
    Hexagon(std::istream &is);
    double Area();
    void Print(std::ostream &os);
    size_t VertexesNumber();

    virtual ~Hexagon();
private:
    Point a, b, c, d, e, f;
};

#endif // HEXAGON_H