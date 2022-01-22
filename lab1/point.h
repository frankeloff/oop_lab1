#ifndef POINT_H
#define POINT_H
#include <iostream>

class Point
{
public:
Point();
Point(double x, double y);
Point(std::istream &is);
double dist(Point &other);
friend double get_x(Point &other);
friend double get_y(Point &other);
friend std::istream& operator>>(std::istream& is, Point& p);
friend std::ostream& operator<<(std::ostream& os, Point& p);
private:
double x_, y_;
};
#endif //POINT_H