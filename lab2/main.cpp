#include <iostream>
#include "TVector.h"

int main()
{   

    TVector list;
/*-----Test InsertLast---*/
    list.InsertLast(Rhombus());
    list.InsertLast(Rhombus(Point(1,2), Point(3,4), Point(5,6), Point(7,8)));
    list.InsertLast(Rhombus(Point(1,2), Point(3,4), Point(5,4), Point(7,8)));
    list.InsertLast(Rhombus(Point(1,0), Point(3,2), Point(4,5), Point(9,9)));
    list.InsertLast(Rhombus(Point(1,0), Point(3,2), Point(4,5), Point(9,9)));
    list.InsertLast(Rhombus(Point(1,0), Point(3,2), Point(4,5), Point(9,9)));
    list.InsertLast(Rhombus());
    std::cout << list << std::endl;
/*-----Test RemoveLast---*/
    list.RemoveLast();
    std::cout << list << std::endl;

    list.RemoveLast();
    std::cout << list << std::endl;
/*-----Test Remove---*/
    std::cout << "--------------" << std::endl;
    list.Remove(1);
    std::cout << list << std::endl;
    std::cout << list.Length() << std::endl;
    std::cout << "--------------" << std::endl;
    list.Resize(2);
    std::cout << list << std::endl;
    std::cout << "--------------" << std::endl;
    std::cout << list.Length() << std::endl;
    std::cout << list << std::endl;
    std::cout << list[2] << std::endl;
    list.Resize(4);
    std::cout << list << std::endl;
    list.Resize(4);
    std::cout << list << std::endl;
    return 0;
}