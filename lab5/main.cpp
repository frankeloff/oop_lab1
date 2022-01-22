#include <iostream>
#include "TVector.h"

int main()
{   
    TVector<Rhombus> list;
/*-----Test push_front---*/
    list.InsertLast(std::shared_ptr<Rhombus>(new Rhombus(Point(1,2), Point(3,4), Point(5,6), Point(7,8))));
    list.InsertLast(std::shared_ptr<Rhombus>(new Rhombus(Point(1,3), Point(3,4), Point(5,6), Point(7,8))));
    list.InsertLast(std::shared_ptr<Rhombus>(new Rhombus(Point(1,4), Point(3,4), Point(5,6), Point(7,8))));
    list.InsertLast(std::shared_ptr<Rhombus>(new Rhombus(Point(1,5), Point(3,4), Point(5,6), Point(7,8))));
    list.InsertLast(std::shared_ptr<Rhombus>(new Rhombus(Point(1,6), Point(3,4), Point(5,6), Point(7,8))));
    list.InsertLast(std::shared_ptr<Rhombus>(new Rhombus(Point(1,7), Point(3,4), Point(5,6), Point(7,8))));
    std::cout << list << std::endl;
/*-----Test pop_front---*/
    list.RemoveLast();
    std::cout << list << std::endl;

    list.RemoveLast();
    std::cout << list << std::endl;
/*-----Test erase---*/
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
      for (auto i : list) {
    std::cout << *i << std::endl;
    }
    return 0;
}