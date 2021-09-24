#ifndef RHOMBUX_H
#define RHOMBUX_H
#include <iostream>
#include "point.h"
#include "figure.h"

class Rhombus : public Figure
{
public:
    Rhombus(std::istream &is);
    Rhombus(Point a, Point b, Point c, Point d);
    double Area();
    // void Print(std::ostream &os);
    size_t VertexesNumber();
    // friend Point get_a(Rhombus& other);
    // friend Point get_b(Rhombus& other);
    // friend Point get_c(Rhombus& other);
    // friend Point get_d(Rhombus& other);
    virtual ~Rhombus();
    friend std::ostream& operator<<(std::ostream& os, Rhombus& p);

private:
    Point a, b, c, d;
};

#endif //RHOMBUX_H