#include <iostream>
#include "TVector.h"
#include <vector>
#include "tallocation_block.h"

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
    TAllocationBlock allocator(sizeof(int), 10);
    int *a1 = nullptr;
    int *a2 = nullptr;
    int *a3 = nullptr;
    int *a4 = nullptr;
    int *a5 = nullptr;

    a1 = (int *) allocator.allocate();
    *a1 = 1;
    std::cout << "a1 pointer value:" << *a1 << std::endl;

    a2 = (int *) allocator.allocate();
    *a2 = 2;
    std::cout << "a2 pointer value:" << *a2 << std::endl;

    a3 = (int *) allocator.allocate();
    *a3 = 3;
    std::cout << "a3 pointer value:" << *a3 << std::endl;

    allocator.deallocate(a1);
    allocator.deallocate(a3);

    a4 = (int *) allocator.allocate();
    *a4 = 4;
    std::cout << "a4 pointer value:" << *a4 << std::endl;

    a5 = (int *) allocator.allocate();
    *a5 = 5;
    std::cout << "a5 pointer value:" << *a5 << std::endl;

    std::cout << "a1 pointer value:" << *a1 << std::endl;
    std::cout << "a2 pointer value:" << *a2 << std::endl;
    std::cout << "a3 pointer value:" << *a3 << std::endl;

    allocator.deallocate(a2);
    allocator.deallocate(a4);
    allocator.deallocate(a5);
    return 0;
}