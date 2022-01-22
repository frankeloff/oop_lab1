#ifndef RHOMBUX_H
#define RHOMBUX_H
#include <iostream>
#include "point.h"
#include "figure.h"

class Rhombus : public Figure
{
public:
    Rhombus();
    Rhombus(std::istream &is);
    Rhombus(Point a, Point b, Point c, Point d);
    double Area();
    size_t VertexesNumber();
    Rhombus& operator=(const Rhombus& other);
    friend std::ostream& operator<<(std::ostream& os, Rhombus& p);
    virtual ~Rhombus();
private:
    Point a, b, c, d;
};

#endif //RHOMBUX_H