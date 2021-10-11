#include <iostream>
#include "TVector.h"



int main()
{   

    TVector list;
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
/*-----Test push_back---*/
//     list.push_front(std::shared_ptr<Rhombus>(new Rhombus(Point(2,3), Point(2,3), Point(2,3), Point(2,3))));
//     std::cout << list << std::endl;
// /*-----Test pop_back---*/
//     list.pop_front();
//     std::cout << list << std::endl;  
// /*-----Test clear---*/
//     list.clear();
//     std::cout << list << std::endl; 

//     list.push_front(std::shared_ptr<Rhombus>(new Rhombus(Point(2,3), Point(2,3), Point(2,3), Point(2,3))));
//     std::cout << list << std::endl;
// /*-----Test insert---*/
//     list.insert(std::shared_ptr<Rhombus>(new Rhombus(Point(0,1), Point(2,3), Point(4,5), Point(6,7))), 1);
//     std::cout << list << std::endl;
//     list.insert(std::shared_ptr<Rhombus>(new Rhombus(Point(0,1), Point(2,3), Point(4,5), Point(6,7))), 3);
//     std::cout << list << std::endl;
//     list.insert(std::shared_ptr<Rhombus>(new Rhombus(Point(0,1), Point(2,3), Point(4,5), Point(6,7))), 2);
//     std::cout << list << std::endl;
/*-----Test erase---*/
    list.Resize(1);
    std::cout << list[1] << std::endl;
    std::cout << list << std::endl;
    
    return 0;
}