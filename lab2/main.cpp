#include <iostream>
#include "TVector.h"



int main()
{   

    TVector list;
/*-----Test push_front---*/
    list.push_front(Rhombus());
    list.push_front(Rhombus(Point(1,2), Point(3,4), Point(5,6), Point(7,8)));
    list.push_front(Rhombus(Point(1,2), Point(3,4), Point(5,6), Point(7,8)));
    list.push_front(Rhombus());
    std::cout << list << std::endl;
/*-----Test pop_front---*/
    list.pop_front();
    std::cout << list << std::endl;

    list.pop_front();
    std::cout << list << std::endl;
/*-----Test push_back---*/
    list.push_back(Rhombus(Point(2,3), Point(2,3), Point(2,3), Point(2,3)));
    std::cout << list << std::endl;
/*-----Test pop_back---*/
    list.pop_back();
    std::cout << list << std::endl;  
/*-----Test clear---*/
    list.clear();
    std::cout << list << std::endl; 

    list.push_back(Rhombus(Point(2,3), Point(2,3), Point(2,3), Point(2,3)));
    std::cout << list << std::endl;
/*-----Test insert---*/
    list.insert(Rhombus(Point(0,1), Point(2,3), Point(4,5), Point(6,7)), 1);
    std::cout << list << std::endl;
    list.insert(Rhombus(Point(0,1), Point(2,3), Point(4,5), Point(6,7)), 3);
    std::cout << list << std::endl;
    list.insert(Rhombus(Point(0,1), Point(2,3), Point(4,5), Point(6,7)), 2);
    std::cout << list << std::endl;
/*-----Test erase---*/
    list.erase(1);
    std::cout << list << std::endl;
    
    return 0;
}