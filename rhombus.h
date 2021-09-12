#ifndef RHOMBUX_H
#define RHOMBUX_H
#include <iostream>
#include "point.h"
#include "figure.h"

class Rhombus : public Figure
{
public:
    Rhombus(std::istream &is);
    double Area();
    void Print(std::ostream &os);
    size_t VertexesNumber();

    virtual ~Rhombus();


private:
    Point a, b, c, d;
};

#endif //RHOMBUX_H