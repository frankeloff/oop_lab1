#include <iostream>
#include "TVector.h"



int main()
{
    TVector a;
    a.push(Rhombus(Point(1,2), Point(3,4), Point(5,6), Point(7,8)));
    a.push(Rhombus(Point(1,2), Point(3,4), Point(5,6), Point(7,9)));
    std::cout << a;
    a.pop();
    std::cout << a;
    return 0;
}