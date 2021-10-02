#include <iostream>
#include "TVectorItem.h"

TVectorItem::TVectorItem(Rhombus &rhomb)
{   
    this->rhomb = rhomb;
    this->first = this->next = nullptr;
}

std::ostream& operator<<(std::ostream& os, TVectorItem& obj)
{
    os << obj.rhomb << " ";
    return os;
}

TVectorItem::~TVectorItem()
{
    std::cout << "TVectorItem deleted" << std::endl;
}